#include "Papyrus.h"

#include "Settings.h"
#include "AdjustmentHandler.h"

namespace Papyrus
{
	void DynamicCollisionAdjustment_MCM::OnConfigClose(RE::TESQuest*)
	{
		Settings::ReadSettings();
	}

	bool DynamicCollisionAdjustment_MCM::Register(RE::BSScript::IVirtualMachine* a_vm)
	{
		a_vm->RegisterFunction("OnConfigClose", "DynamicCollisionAdjustment_MCM", OnConfigClose);

		logger::info("Registered DynamicCollisionAdjustment_MCM class");
		return true;
	}

	void DynamicCollisionAdjustment_Prone::SetProneState(RE::StaticFunctionTag*, bool proneState, bool sneakState)
	{	
		logger::debug("Function call was sent! {}", proneState);
		AdjustmentHandler* AdjustmentHandlerSingleton = AdjustmentHandler::GetSingleton();
		AdjustmentHandlerSingleton->ActorSneakStateChanged(RE::PlayerCharacter::GetSingleton()->GetHandle(), sneakState);
	}

	bool DynamicCollisionAdjustment_Prone::CanPlayerGetUp(RE::StaticFunctionTag*)
	{	
		AdjustmentHandler* AdjustmentHandlerSingleton = AdjustmentHandler::GetSingleton();
		return AdjustmentHandlerSingleton->CheckEnoughSpaceToStand(RE::PlayerCharacter::GetSingleton()->GetHandle());
	}

	bool DynamicCollisionAdjustment_Prone::Register(RE::BSScript::IVirtualMachine* a_vm)
	{
		a_vm->RegisterFunction("SetProneState", "DynamicCollisionAdjustment_Prone", SetProneState);
		a_vm->RegisterFunction("CanPlayerGetUp", "DynamicCollisionAdjustment_Prone", CanPlayerGetUp);

		logger::info("Registered DynamicCollisionAdjustment_Prone class");
		return true;
	}

	void Register()
	{
		auto papyrus = SKSE::GetPapyrusInterface();
		papyrus->Register(DynamicCollisionAdjustment_MCM::Register);
		papyrus->Register(DynamicCollisionAdjustment_Prone::Register);
		logger::info("Registered papyrus functions");
	}
}
