class CfgPatches
{
	class MaiarsKits01
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = 
		{
		"DZ_Data",
		"DZ_Scripts",
		"ModularVestSystem",
		"pitstop_stuff",
		"Mass_Textures"
		};
	};
};

class cfgvehicles
{
	class Inventory_Base;
	class Maiar_Kit_base: Inventory_Base
	{
		scope=0;
		displayName="Kit";
		descriptionShort="This item has blah blah blah. Opening this item places all items at your feet.";
		model="\Maiars_Kits\kits\kit.p3d";
		KitItems[]= 
		{
			"M65Jacket_Black",
			"CargoPants_Black",
			"CombatKnife"
		};
	};
	class Maiar_MaiarSpecial_Black_SafeZone: Maiar_Kit_base
	{
		scope=2;
		displayName="Maiar's Loadout - Black";
		descriptionShort="This has MVS Vest, SOCOM Pants, Pilots Jacket, Battle Belt, Warrior Helmet, and all attachments for these items(Pouches). Opening this item places all items at your feet.";
		KitItems[]= 
		{
			"MVS_Combat_Vest_Black", //5000
			"PITSTOP_SOCOMPants_Black", //2500
			"PITSTOP_PilotJacket_Black", //2500
			"MassMolleBeltBlack", //2000
			"MVS_Rucksack_Black", //5000
			"MVS_WarriorHelmet_Black", //1750
			"MVS_Taco_Pouch_Black", //750
			"MVS_Admin_Pouch_Black", //750
			"MVS_Utility_Pouch_Black", //300
			"MVS_Medical_Pouch_Black", //750
			"MVS_Canteen_Black", //750
			"MassTacticalBagBlack", //1000
			"MassTacticalBagBlack", //1000
			"MassTacticalBagBlack", //1000
			"MVS_Magazine_Pouch_Black", //750
			"MVS_Sheath_Black" //750
		}; //26500
	};
	class Maiar_MVSKit_ERDL_SafeZone: Maiar_Kit_base
	{
		scope=2;
		displayName="MVS Load Out - ERDL";
		descriptionShort="This has MVS Combat Shirt, Pants, Belt, Raider Backpack, MVS Vest, and all attachments for these items(Pouches). Opening this item places all items at your feet.";
		KitItems[]= 
		{
			"MVS_Combat_Vest_ERDL", //5000
			"MVS_CombatPants_ERDL", //750
			"MVS_CombatShirt_ERDL", //750
			"MVS_Belt_ERDL", //1000
			"MVS_Assault_Pack_ERDL", //1750
			"MVS_Helmet_01_ERDL", //100
			"MVS_Taco_Pouch_ERDL", //750
			"MVS_Admin_Pouch_ERDL", //750
			"MVS_Taco_Pouch_ERDL", //750
			"MVS_Admin_Pouch_ERDL", //750
			"MVS_Taco_Pouch_ERDL", //750
			"MVS_Admin_Pouch_ERDL", //750
			"MVS_Utility_Pouch_ERDL", //300
			"MVS_Medical_Pouch_ERDL", //750
			"MVS_Canteen_ERDL", //750
			"MVS_Sheath_ERDL", //750
			"MVS_Holster_ERDL" //750
		}; //18000
	};
	class Maiar_MVSKit_Black_SafeZone: Maiar_Kit_base
	{
		scope=2;
		displayName="MVS Load Out - Black";
		descriptionShort="This has MVS Combat Shirt, Pants, Belt, Raider Backpack, MVS Vest, and all attachments for these items(Pouches). Opening this item places all items at your feet.";
		KitItems[]= 
		{
			"MVS_Combat_Vest_Black", //5000
			"MVS_CombatPants_Black", //750
			"MVS_CombatShirt_Black", //750
			"MVS_Belt_Black", //1000
			"MVS_Assault_Pack_Black", //1750
			"MVS_Helmet_01_Black", //100
			"MVS_Taco_Pouch_Black", //750
			"MVS_Admin_Pouch_Black", //750
			"MVS_Taco_Pouch_Black", //750
			"MVS_Admin_Pouch_Black", //750
			"MVS_Taco_Pouch_Black", //750
			"MVS_Admin_Pouch_Black", //750
			"MVS_Utility_Pouch_Black", //300
			"MVS_Medical_Pouch_Black", //750
			"MVS_Canteen_Black", //750
			"MVS_Sheath_Black", //750
			"MVS_Holster_Black" //750
		}; //18000
	};
	class Maiar_MVSKit_Tan_SafeZone: Maiar_Kit_base
	{
		scope=2;
		displayName="MVS Load Out - Tan";
		descriptionShort="This has MVS Combat Shirt, Pants, Belt, Raider Backpack, MVS Vest, and all attachments for these items(Pouches). Opening this item places all items at your feet.";
		KitItems[]= 
		{
			"MVS_Combat_Vest_Tan", //5000
			"MVS_CombatPants_Tan", //750
			"MVS_CombatShirt_Tan", //750
			"MVS_Belt_Tan", //1000
			"MVS_Assault_Pack_Tan", //1750
			"MVS_Helmet_01_Tan", //100
			"MVS_Taco_Pouch_Tan", //750
			"MVS_Admin_Pouch_Tan", //750
			"MVS_Taco_Pouch_Tan", //750
			"MVS_Admin_Pouch_Tan", //750
			"MVS_Taco_Pouch_Tan", //750
			"MVS_Admin_Pouch_Tan", //750
			"MVS_Utility_Pouch_Tan", //300
			"MVS_Medical_Pouch_Tan", //750
			"MVS_Canteen_Tan", //750
			"MVS_Sheath_Tan", //750
			"MVS_Holster_Tan" //750
		}; //1800
	};
};