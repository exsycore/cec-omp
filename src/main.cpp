#include "sdk.hpp"

#include "Server/Components/Pawn/pawn.hpp"

#include "natives.h"

AMX_NATIVE_INFO natives[] =
{
	{ "CE_Convert", Natives::CE_Convert },
	{ "CE_Convert_Dialog", Natives::CE_Convert_Dialog },
	{ "CE_CountTag", Natives::CE_CountTag },
	{ "CE_CountVowel", Natives::CE_CountVowel },
	{ 0, 0 }
};

class ColourFix final : public IComponent, public CoreEventHandler, public PawnEventHandler
{
private:
	ICore *core_ = nullptr;

	IPawnComponent *pawn_ = nullptr;

public:
	PROVIDE_UID(0x55D38CB65D394195);

	StringView componentName() const override
	{
		return "open.mp colourfix";
	}

	SemanticVersion componentVersion() const override
	{
		return SemanticVersion(2, 6, 0, 2);
	}

	void onLoad(ICore* c) override
	{
		core_ = c;
		core_->printLn("      --------------------------------");
		core_->printLn(" ");
		core_->printLn("    < cec 2.6 (open.mp) | Copyright 2020-2025 > ");
		core_->printLn("     Author: Ak-kawit \"B-Less\" Tahae");
		core_->printLn("     Editor: EasyCore \"E-Core\" .....");
		core_->printLn("   Repository: https://github.com/Brian-Less/cec");
		core_->printLn("   Repository: https://github.com/exsycore/cec-omp");
		core_->printLn(" ");
		core_->printLn("      --------------------------------");
	}

	void onInit(IComponentList *components) override
	{
		pawn_ = components->queryComponent<IPawnComponent>();

		if (pawn_ == nullptr)
		{
			StringView name = componentName();
			core_->logLn(
				LogLevel::Error,
				"Error loading component %.*s: Pawn component not loaded",
				name.length(),
				name.data()
			);

			return;
		}

		pawn_->getEventDispatcher().addEventHandler(this);
		core_->getEventDispatcher().addEventHandler(this);
		pAMXFunctions = (void*)&pawn_->getAmxFunctions();
	}

	void onReady() override
	{
	}

	void onTick(Microseconds elapsed, TimePoint now) override
	{
	}

	void onAmxLoad(IPawnScript &script) override
	{	
		AMX* amx = script.GetAMX();
		
		amx_Register(amx, natives, -1);
	}

	void onAmxUnload(IPawnScript &script) override
	{
	}

	void onFree(IComponent *component) override
	{
		if (component == pawn_)
		{

			pawn_ = nullptr;
			pAMXFunctions = nullptr;
			core_->printLn("\n\n*** ColourFix Plugin v2.6 unloaded ***\n\n");
		}
	}

	void free() override
	{
		if (pawn_ != nullptr)
		{
			pawn_->getEventDispatcher().removeEventHandler(this);
			core_->getEventDispatcher().removeEventHandler(this);
		}

		delete this;
	}

	void reset() override
	{
	}

	~ColourFix()
	{
	}
};

COMPONENT_ENTRY_POINT()
{
	return new ColourFix();
}
