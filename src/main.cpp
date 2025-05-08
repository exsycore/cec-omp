#include "main.hpp"

#include "Server/Components/Pawn/pawn.hpp"

#include "common.hpp"
#include "natives.hpp"

class ColourFix final : public IComponent, public CoreEventHandler, public PawnEventHandler
{
        PROVIDE_UID(/*UID*/);

        StringView componentName() const override
        {
            return "open.mp colourfix";
        }

        SemanticVersion componentVersion() const override
        {
            return SemanticVersion(2, 6, 0, 2);
        }

        void onLoad(ICore *c) override
        {
            core_ = c;
            c->printLn("      --------------------------------");
            c->printLn(" ");
            c->printLn("    < cec 2.6 (open.mp) | Copyright 2020-2025 > ");
            c->printLn("     Author: Ak-kawit \"B-Less\" Tahae");
            c->printLn("     Editor: EasyCore \"E-Core\" .....");
            c->printLn("   Repository: https://github.com/Brian-Less/cec");
            c->printLn("   Repository: https://github.com/exsycore/cec-omp");
            c->printLn(" ");
            c->printLn("      --------------------------------");
        }

        void onInit(IComponentList *components) override
        {
            ompgdk::GDKManager::Get()->Init(core_, components);
            pawn_ = components->queryComponent<IPawnComponent>();

            if (pawn_ == nullptr)
            {
                StringView name = componentName();
                core_->logLn(
                    LogLevel::Error,
                    "Error loading component %.*s: Pawn component not loaded",
                    name.length(),
                    name.data());

                return;
            }

            pawn_->getEventDispatcher().addEventHandler(this);
            core_->getEventDispatcher().addEventHandler(this);
            pAMXFunctions = (void*)&pawn_->getAmxFunctions();
        }

        void onReady() override {}

        void onTick(Microseconds elapsed, TimePoint now) override {}

        void onAmxLoad(IPawnScript &script) override
        {
            script.Register("CE_Convert", Natives::CE_Convert);
            script.Register("CE_Convert_Dialog", Natives::CE_Convert_Dialog);
            script.Register("CE_CountTag", Natives::CE_CountTag);
            script.Register("CE_CountVowel", Natives::CE_CountVowel);
            // amx_Register(script.GetAMX(), native_list, -1);
        }

        void onAmxUnload(IPawnScript &script) override {}

        void onFree(IComponent *component) override
        {
            if (component == pawn_ || component == this)
            {
                if (pawn_)
                {
                    core_->printLn("\n\n*** ColourFix Plugin v2.6 unloaded ***\n\n");

                    core_->getEventDispatcher().removeEventHandler(this);
                    pawn_->getEventDispatcher().removeEventHandler(this);
                    pAMXFunctions = nullptr;
                }

                pawn_ = nullptr;
            }
        }

        void free() override
        {
            delete this;
        }

        void reset() override {}

        ~ColourFix() {}

    private:
        ICore *core_ = nullptr;

        IPawnComponent *pawn_ = nullptr;
};

COMPONENT_ENTRY_POINT()
{
	return new ColourFix();
}
