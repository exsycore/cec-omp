#include <sdk.hpp>

#include "Server/Components/Pawn/pawn.hpp"
#include <Server/Components/Pawn/Impl/pawn_natives.hpp>
#include <Server/Components/Pawn/Impl/pawn_impl.hpp>

#include "natives.h"

AMX_NATIVE_INFO natives[] =
{
	{ "CE_Convert", Natives::CE_Convert },
	{ "CE_Convert_Dialog", Natives::CE_Convert_Dialog },
	{ "CE_CountTag", Natives::CE_CountTag },
	{ "CE_CountVowel", Natives::CE_CountVowel },
	{ 0, 0 }
};

class ColourFix final : public IComponent, public PawnEventHandler
{
private:
	ICore *core_ = nullptr;

	IPawnComponent *pawn_;

public:
	PROVIDE_UID(0xE6F68FA408610254);

	StringView componentName() const override
	{
		return "Colour Fix";
	}

	SemanticVersion componentVersion() const override
	{
		return SemanticVersion(0, 0, 1, 0);
	}

	void onLoad(ICore* c) override
	{
		core_ = c;
		core_->printLn("ColourFix loaded.");
	}

	void onInit(IComponentList *components) override
	{
		pawn_ = components->queryComponent<IPawnComponent>();

		if (pawn_)
		{
			setAmxFunctions(pawn_->getAmxFunctions());

			setAmxLookups(components);

			pawn_->getEventDispatcher().addEventHandler(this);
		}
	}

	void onReady() override
	{
	}

	void onFree(IComponent *component) override
	{
		if (component == pawn_)
		{

			pawn_ = nullptr;

			setAmxFunctions();

			setAmxLookups();
		}
	}

	void free() override
	{
		delete this;
	}

	void reset() override
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

	~ColourFix()
	{
	}
};

COMPONENT_ENTRY_POINT()
{
	return new ColourFix();
}
