class CfgPatches
{
	class Maiar_KeycardDoors
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = 
		{
		"DZ_Data",
		"DZ_Scripts",
		"Maiar_KeycardAssets"
		};
	};
};
class cfgvehicles
{
	class land_Vaultdoor;
	class land_Vaultdoor1: land_Vaultdoor
	{
		scope=2;
		model="Maiar_KeycardAssets\Doors\Vaultdoor1.p3d";
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
	class land_Vaultdoor2: land_Vaultdoor
	{
		scope=2;
		model="Maiar_KeycardAssets\Doors\Vaultdoor2.p3d";
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
	class land_Vaultdoor3: land_Vaultdoor
	{
		scope=2;
		model="Maiar_KeycardAssets\Doors\Vaultdoor3.p3d";
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
	class land_Vaultdoor4: land_Vaultdoor
	{
		scope=2;
		model="Maiar_KeycardAssets\Doors\Vaultdoor4.p3d";
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
	class land_Vaultdoor5: land_Vaultdoor
	{
		scope=2;
		model="Maiar_KeycardAssets\Doors\Vaultdoor5.p3d";
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
	
	class Maiar_keyCard_base;
	class Maiar_keyCard_Tier1: Maiar_keyCard_base
	{
		scope=2;
		displayName="Keycard Tier 1";
		descriptionShort="KeyCard, goes to vaulted doors all around the map.";
		KeyTier = "land_Vaultdoor1";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = 
        {
            "Maiar_KeycardAssets\Doors\Data\KeyCard_blue_co.paa"
        };
	};
	class Maiar_keyCard_Tier2: Maiar_keyCard_base
	{
		scope=2;
		displayName="Keycard Tier 2";
		descriptionShort="KeyCard, goes to vaulted doors all around the map.";
		KeyTier = "land_Vaultdoor2";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = 
        {
            "Maiar_KeycardAssets\Doors\Data\KeyCard_purple_co.paa"
        };
	};
	class Maiar_keyCard_Tier3: Maiar_keyCard_base
	{
		scope=2;
		displayName="Keycard Tier 3";
		descriptionShort="KeyCard, goes to vaulted doors all around the map.";
		KeyTier = "land_Vaultdoor3";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = 
        {
            "Maiar_KeycardAssets\Doors\Data\KeyCard_orange_co.paa"
        };
	};
	class Maiar_keyCard_Tier4: Maiar_keyCard_base
	{
		scope=2;
		displayName="Keycard Tier 4";
		descriptionShort="KeyCard, goes to vaulted doors all around the map.";
		KeyTier = "land_Vaultdoor4";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = 
        {
            "Maiar_KeycardAssets\Doors\Data\KeyCard_red_co.paa"
        };
	};
	class Maiar_keyCard_Tier5: Maiar_keyCard_base
	{
		scope=2;
		displayName="Keycard Tier 5";
		descriptionShort="KeyCard, goes to vaulted doors all around the map.";
		KeyTier = "land_Vaultdoor5";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = 
        {
            "Maiar_KeycardAssets\Doors\Data\KeyCard_black_co.paa"
        };
	};
	
};