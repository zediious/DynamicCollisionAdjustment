#pragma once

namespace Papyrus
{
	class DynamicCollisionAdjustment_MCM
	{
	public:
		static void OnConfigClose(RE::TESQuest*);

		static bool Register(RE::BSScript::IVirtualMachine* a_vm);
	};

	class DynamicCollisionAdjustment_Prone
	{
	public:
		static void SetProneState(RE::StaticFunctionTag*, bool, bool);

		static bool CanPlayerGetUp(RE::StaticFunctionTag*);

		static bool Register(RE::BSScript::IVirtualMachine* a_vm);
	};

	void Register();
}
