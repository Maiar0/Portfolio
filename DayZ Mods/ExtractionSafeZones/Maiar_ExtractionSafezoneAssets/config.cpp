class CfgPatches
{
	class Maiar_ExtractionSafezoneAssets
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = 
		{
		"DZ_Data",
		"DZ_Scripts"
		};
	};
};

class cfgvehicles
{
	class Inventory_Base;
	
	
	class HouseNoDestruct;
	class Maiar_ExtractionPoint_base: HouseNoDestruct
	{
		model="Maiar_ExtractionSafezoneAssets\TeleportationTerminalBlack.p3d";
		
	};
	class Maiar_ExtractionPoint: Maiar_ExtractionPoint_base
	{
		scope=2;
		
	};
	class Maiar_SafezoneExtraction_base: HouseNoDestruct
	{
		model="Maiar_ExtractionSafezoneAssets\TeleportationTerminal.p3d";
		
	};
	class Maiar_SafezoneExtraction: Maiar_SafezoneExtraction_base
	{
		scope=2;
		
	};
};