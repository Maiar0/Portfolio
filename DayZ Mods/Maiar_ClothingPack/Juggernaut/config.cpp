class CfgPatches
{
	class Maiar_JuggernautVest
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Characters"};
	};
};
class cfgVehicles
{
	class Clothing_Base;
	class Clothing: Clothing_Base{};
	class Maiar_JuggernautVest: Clothing
	{
		scope = 0;
		displayName = "Juggernaut Vest";
		descriptionShort = "Vest for advanced Balistic Protection.";
		model = "Maiar_ClothingPack\Juggernaut\HeavyVest_g.p3d";
		attachments[] = {"JuggernautBackPouch"};
		inventorySlot[] = {"Vest"};
		itemSize[] = {6,6};
		varWetMax = 0.49;
		heatIsolation = 0.81;
		repairableWithKits[]={3,8};
		repairCosts[]={75,50};
		quickBarBonus = 3;
		class ClothingTypes
		{
			male = "Maiar_ClothingPack\Juggernaut\HeavyVest_m.p3d";
			female = "Maiar_ClothingPack\Juggernaut\HeavyVest_f.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 350;
					healthLevels[] = 
					{
						{1.0,{	}},
						{0.7,{	}},
						{0.5,{	}},
						{0.3,{	}},
						{0.0,{	}},
					};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health 	{ damage=0.1; };
					class Blood 	{ damage=0; };
					class Shock 	{ damage=0.1; };
				};
				class Melee
				{
					class Health 	{ damage=0.1; };
					class Blood 	{ damage=0; };
					class Shock 	{ damage=0.1; };
				};
				class Infected
				{
					class Health 	{ damage=0.1; };
					class Blood 	{ damage=0; };
					class Shock 	{ damage=0.1; };
				};
				class FragGrenade
				{
					class Health 	{ damage=0.1; };
					class Blood 	{ damage=0; };
					class Shock 	{ damage=0.1; };
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "SmershVest_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "SmershVest_drop_SoundSet";
					id = 898;
				};
			};
		};		
	};
	class Maiar_Juggernaut_DigDesert: Maiar_JuggernautVest
	{
		scope = 2;
		displayName = "Juggernaught Vest - Digital Desert";
		hiddenSelections[] = {"Camoground","Camofemale","camomale"};
        hiddenSelectionsTextures[] = 
        {
            "Maiar_ClothingPack\Juggernaut\Vest\JugVest_DigDesert_co.paa",
            "Maiar_ClothingPack\Juggernaut\Vest\JugVest_DigDesert_co.paa",
            "Maiar_ClothingPack\Juggernaut\Vest\JugVest_DigDesert_co.paa"
        };
	};
	class Maiar_Juggernaut_DigFlora: Maiar_JuggernautVest
	{
		scope = 2;
		displayName = "Juggernaught Vest - Digital Flora";
		hiddenSelections[] = {"Camoground","Camofemale","camomale"};
        hiddenSelectionsTextures[] = 
        {
            "Maiar_ClothingPack\Juggernaut\Vest\JugVest_DigFlora_co.paa",
            "Maiar_ClothingPack\Juggernaut\Vest\JugVest_DigFlora_co.paa",
            "Maiar_ClothingPack\Juggernaut\Vest\JugVest_DigFlora_co.paa"
        };
	};
	class Maiar_Juggernaut_Flora: Maiar_JuggernautVest
	{
		scope = 2;
		displayName = "Juggernaught Vest - Flora";
		hiddenSelections[] = {"Camoground","Camofemale","camomale"};
        hiddenSelectionsTextures[] = 
        {
            "Maiar_ClothingPack\Juggernaut\Vest\JugVest_Flora_co.paa",
            "Maiar_ClothingPack\Juggernaut\Vest\JugVest_Flora_co.paa",
            "Maiar_ClothingPack\Juggernaut\Vest\JugVest_Flora_co.paa"
        };
	};
	class Maiar_Juggernaut_Black: Maiar_JuggernautVest
	{
		scope = 2;
		displayName = "Juggernaught Vest - Black";
		hiddenSelections[] = {"Camoground","Camofemale","camomale"};
        hiddenSelectionsTextures[] = 
        {
            "Maiar_ClothingPack\Juggernaut\Vest\JugVest_Black_co.paa",
            "Maiar_ClothingPack\Juggernaut\Vest\JugVest_Black_co.paa",
            "Maiar_ClothingPack\Juggernaut\Vest\JugVest_Black_co.paa"
        };
	};
	class Maiar_Jug_BckPouch: Clothing
	{
		scope=0;
		displayName="Juggernaut Back Pouch";
		descriptionShort="48 slot pouch for Juggernaut Vest.";
		model="Maiar_ClothingPack\Juggernaut\HeavyVestBackPouch.p3d";
		inventorySlot[]=
		{
			"JuggernautBackPouch"
		};
		itemsCargoSize[]={8,6};
		weight=110;
		itemSize[]={5,6};
		varWetMax=0.79000002;
		heatIsolation=0;
		repairableWithKits[]={3};
		repairCosts[]={25};
		hiddenSelections[] = {"Camo"};
        hiddenSelectionsTextures[] = 
        {
            "Maiar_ClothingPack\Juggernaut\Pouches\Pouches_DigDesert.paa"
        };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = 
					{
						{1.0,{	}},
						{0.7,{	}},
						{0.5,{	}},
						{0.3,{	}},
						{0.0,{	}},
					};
				};
			};
		};
		
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet="Shirt_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="Shirt_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class Maiar_Jug_BckPouch_DigDesert: Maiar_Jug_BckPouch
	{
		scope = 2;
		displayName="Juggernaut Back Pouch - Digital Desert";
		hiddenSelections[] = {"Camo"};
        hiddenSelectionsTextures[] = 
        {
            "Maiar_ClothingPack\Juggernaut\Pouches\Pouches_DigDesert.paa"
        };
	};
	class Maiar_Jug_BckPouch_DigFlora: Maiar_Jug_BckPouch
	{
		scope = 2;
		displayName="Juggernaut Back Pouch - Digital Flora";
		hiddenSelections[] = {"Camo"};
        hiddenSelectionsTextures[] = 
        {
            "Maiar_ClothingPack\Juggernaut\Pouches\Pouches_DigFlora.paa"
        };
	};
	class Maiar_Jug_BckPouch_Flora: Maiar_Jug_BckPouch
	{
		scope = 2;
		displayName="Juggernaut Back Pouch - Flora";
		hiddenSelections[] = {"Camo"};
        hiddenSelectionsTextures[] = 
        {
            "Maiar_ClothingPack\Juggernaut\Pouches\Pouches_Flora.paa"
        };
	};
	class Maiar_Jug_BckPouch_Black: Maiar_Jug_BckPouch
	{
		scope = 2;
		displayName="Juggernaut Back Pouch - Black";
		hiddenSelections[] = {"Camo"};
        hiddenSelectionsTextures[] = 
        {
            "Maiar_ClothingPack\Juggernaut\Vest\JugVest_Black_co.paa"
        };
	};
	
	class Maiar_JugFrnt_Pouch: Clothing
	{
		scope=0;
		displayName="Juggernaut Front Pouch";
		descriptionShort="30 slot pouch for  Juggernaut Vest.";
		model="Maiar_ClothingPack\Juggernaut\HeavyVestFrontPouch.p3d";
		inventorySlot[]=
		{
			"JuggernautFrontPouch"
		};
		itemsCargoSize[]={5,6};
		weight=110;
		rotationFlags=16;
		itemSize[]={5,6};
		varWetMax=0.79000002;
		heatIsolation=0;
		repairableWithKits[]={3};
		repairCosts[]={25};
		hiddenSelections[] = {"Camo"};
        hiddenSelectionsTextures[] = 
        {
            "Maiar_ClothingPack\Juggernaut\Pouches\Pouches_DigDesert.paa"
        };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = 
					{
						{1.0,{	}},
						{0.7,{	}},
						{0.5,{	}},
						{0.3,{	}},
						{0.0,{	}},
					};
				};
			};
		};
		
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet="Shirt_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="Shirt_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class Maiar_JugFrnt_Pouch_DigDesert: Maiar_JugFrnt_Pouch
	{
		scope = 2;
		hiddenSelections[] = {"Camo"};
        hiddenSelectionsTextures[] = 
        {
            "Maiar_ClothingPack\Juggernaut\Pouches\Pouches_DigDesert.paa"
        };
	};
	class Maiar_JugFrnt_Pouch_DigFlora: Maiar_JugFrnt_Pouch
	{
		scope = 2;
		hiddenSelections[] = {"Camo"};
        hiddenSelectionsTextures[] = 
        {
            "Maiar_ClothingPack\Juggernaut\Pouches\Pouches_DigFlora.paa"
        };
	};
	class Maiar_JugFrnt_Pouch_Flora: Maiar_JugFrnt_Pouch
	{
		scope = 2;
		hiddenSelections[] = {"Camo"};
        hiddenSelectionsTextures[] = 
        {
            "Maiar_ClothingPack\Juggernaut\Pouches\Pouches_Flora.paa"
        };
	};
	
	
	
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
    class ProxyHeavyVestBackPouch: ProxyAttachment
    {
        scope=2;
        inventorySlot="JuggernautBackPouch";
        model="Maiar_ClothingPack\proxies\HeavyVestBackPouch.p3d";
    };
	class ProxyHeavyVestFrontPouch: ProxyAttachment
    {
        scope=2;
        inventorySlot="JuggernautFrontPouch";
        model="Maiar_ClothingPack\proxies\HeavyVestFrontPouch.p3d";
    };
	
};
class CfgSlots
{
    class Maiar_JuggernautBackPouch
    {
        name = "JuggernautBackPouch";
        displayName = "Juggernaut Back Pouch";
        ghostIcon = "set:dayz_inventory image:magazine";
    };
	class Maiar_JuggernautFrontPouch
    {
        name = "JuggernautFrontPouch";
        displayName = "Juggernaut Front Pouch";
        ghostIcon = "set:dayz_inventory image:magazine";
    };
};



