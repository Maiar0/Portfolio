class CfgPatches
{
	class Maiar_KeycardAssets
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
class CfgMods
{
	class Maiar_KeycardAssets
	{
	    Author = "Maiar";
	    picture = "";
	    action = "";
	    type = "mod";
		dependencies[]={"Mission","Game","World"}; 

	    class defs
	    {	
	    	class gameScriptModule
			{
				value="";
				files[]= {"Maiar_KeycardAssets/scripts/3_Game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"Maiar_KeycardAssets/Scripts/4_World"};
			};
			class missionScriptModule
			{
				value="";
				files[]= {"Maiar_KeycardAssets/scripts/5_Mission"};
			};
        };
    };
};
class cfgvehicles
{
	class HouseNoDestruct;
	class land_Vaultdoor: HouseNoDestruct
	{
		scope=0;
		model="Maiar_KeycardAssets\Doors\Vaultdoor.p3d";
		class Doors
		{
		  class door1
		  {
			displayName = "door 1";
			component = "door1";
			soundPos = "door1_action";
			animPeriod = 1;
			initPhase = 0;
			initOpened = 0;
			soundOpen = "sound open";
			soundClose = "sound close";
			soundLocked = "sound locked";
			soundOpenABit = "sound openabit";
		  };
		};
		class DamageSystem
		{
		  class GlobalHealth
		  {
			class Health
			{
			  hitpoints = 999999999999;
			};
		  };
		  class GlobalArmor
		  {
			class Projectile
			{
			  class Health { damage = 0; };
			  class Blood { damage = 0; };
			  class Shock { damage = 0; };
			};
			class Melee
			{
			  class Health { damage = 0; };
			  class Blood { damage = 0; };
			  class Shock { damage = 0; };
			};
		  };
		  class DamageZones
		  {
			class door
			{
			  class Health
			  {
				hitpoints = 1000;
				transferToGlobalCoef = 0;
			  };
			  componentNames[] = {"door1"};
			  fatalInjuryCoef = -1;
			  class ArmorType
			  {
				class Projectile
				{
				  class Health { damage = 0; };
				  class Blood { damage = 0; };
				  class Shock { damage = 0; };
				};
				class Melee
				{
				  class Health { damage = 0; };
				  class Blood { damage = 0; };
				  class Shock { damage = 0; };
				};
			  };
			};
		  };
		};
	};
	class Inventory_Base;
	class Maiar_keyCard_base: Inventory_Base
	{
		scope=0;
		displayName="Keycard";
		descriptionShort="KeyCard, goes to vaulted doors all around the map.";
		model="Maiar_KeycardAssets\Doors\KeyCard.p3d";
		KeyTier = "land_Vaultdoor";
		rotationFlags=1;
	};
	class SeaChest;
	class Maiar_PlacementTool: SeaChest
	{
		displayName="Placement tool";
		descriptionShort="Helps with placement of keycard doors";
		model="Maiar_KeycardAssets\Doors\VaultDoorPlacement.p3d";
		itemSize[]={1,1};
		rotationFlags=64;
		itemBehaviour=2;
		canBeDigged=0;
		class Cargo
		{
			itemsCargoSize[]={1,1};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
	};
	class Maiar_KeyCardLootBox: Seachest
	{
		scope = 2;
		descriptionShort = "Case containg loot!";
		displayName = "Key Card Loot Box";
		physLayer="item_large";
		itemSize[] = {50,50};
		class Cargo
		{
			itemsCargoSize[] = {10,50};
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
};