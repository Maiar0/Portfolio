class CfgPatches
{
	class Maiar_RaidAlarmItem
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
	class Maiar_RaidAlarmPanel: Inventory_Base
	{
		scope=2;
		displayName="Raid Alarm Panel";
		physLayer="item_large";
		model="Maiar_Teleportation\TeleportTools\TeleportationTerminal.p3d";
		class Cargo
		{
			itemsCargoSize[]={0,0};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
	};
};