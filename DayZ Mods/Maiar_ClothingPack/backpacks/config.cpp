class CfgPatches
{
	class Maiar_ClothingPack
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
	class Clothing_Base;
	class Clothing: Clothing_Base{};
	class Maiar_Civilian_Backpack_Base: Clothing
	{
		scope = 0;
		displayName = "Civillian Backpack";
		descriptionShort = "A backpack that holds 2 rifles and 150 slots!";
		model = "Maiar_ClothingPack\backpacks\Backpack1_g.p3d";
		inventorySlot[] = {"Back"};
		attachments[] = {"Shoulder","Melee","Belt_Left"};
		itemInfo[]= {"Clothing","Back"};
		itemSize[] = {5,7};
		itemsCargoSize[] = {10,15};
		rotationFlags=2;
		quickBarBonus = 2;
		weight=2300;
		varWetMax=0.79000002;
		heatIsolation=1;
		repairableWithKits[]={5,2};
		repairCosts[]={30,25};
		soundAttType="Outdoor";
		randomQuantity=4;
		hiddenSelections[] = {"Camoground","Camofemale","camomale"};
        hiddenSelectionsTextures[] = 
        {
            "\Maiar_ClothingPack\backpacks\Backpack1\Camel_BLK_Co.paa",
            "\Maiar_ClothingPack\backpacks\Backpack1\Camel_BLK_Co.paa",
            "\Maiar_ClothingPack\backpacks\Backpack1\Camel_BLK_Co.paa"
        };
		class ClothingTypes
		{
			male = "\Maiar_ClothingPack\backpacks\Backpack1.p3d";
			female = "\Maiar_ClothingPack\backpacks\Backpack1.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 800;
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
				class pickUpItem_Light
				{
					soundSet="pickUpBackPack_Plastic_Light_SoundSet";
					id=796;
				};
				class pickUpItem
				{
					soundSet="pickUpBackPack_Plastic_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="taloonbag_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class Maiar_Civilian_Backpack_Black: Maiar_Civilian_Backpack_Base
	{
		scope = 2;
		displayName = "Civillian Backpack";
		
		hiddenSelections[] = {"Camoground","Camofemale","camomale"};
        hiddenSelectionsTextures[] = 
        {
			"\Maiar_ClothingPack\backpacks\Backpack1\Camel_BLK_Co.paa",
            "\Maiar_ClothingPack\backpacks\Backpack1\Camel_BLK_Co.paa",
            "\Maiar_ClothingPack\backpacks\Backpack1\Camel_BLK_Co.paa"
        };
	};
	class Maiar_Civilian_Backpack_Green: Maiar_Civilian_Backpack_Base
	{
		scope = 2;
		displayName = "Civillian Backpack";
		
		hiddenSelections[] = {"Camoground","Camofemale","camomale"};
        hiddenSelectionsTextures[] = 
        {
			"\Maiar_ClothingPack\backpacks\Backpack1\Camel_Green_co.paa",
            "\Maiar_ClothingPack\backpacks\Backpack1\Camel_Green_co.paa",
            "\Maiar_ClothingPack\backpacks\Backpack1\Camel_Green_co.paa"
        };
	};
	class Maiar_Civilian_Backpack_MultiCam: Maiar_Civilian_Backpack_Base
	{
		scope = 2;
		displayName = "Civillian Backpack";
		
		hiddenSelections[] = {"Camoground","Camofemale","camomale"};
        hiddenSelectionsTextures[] = 
        {
			"\Maiar_ClothingPack\backpacks\Backpack1\Camel_Multicam_co.paa",
            "\Maiar_ClothingPack\backpacks\Backpack1\Camel_Multicam_co.paa",
            "\Maiar_ClothingPack\backpacks\Backpack1\Camel_Multicam_co.paa"
        };
	};
	class Maiar_Civilian_Backpack_Tan: Maiar_Civilian_Backpack_Base
	{
		scope = 2;
		displayName = "Civillian Backpack";
		
		hiddenSelections[] = {"Camoground","Camofemale","camomale"};
        hiddenSelectionsTextures[] = 
        {
			"\Maiar_ClothingPack\backpacks\Backpack1\Camel_Tan_Co.paa",
            "\Maiar_ClothingPack\backpacks\Backpack1\Camel_Tan_Co.paa",
            "\Maiar_ClothingPack\backpacks\Backpack1\Camel_Tan_Co.paa"
        };
	};
	class Maiar_Civilian_Backpack_Woods: Maiar_Civilian_Backpack_Base
	{
		scope = 2;
		displayName = "Civillian Backpack";
		
		hiddenSelections[] = {"Camoground","Camofemale","camomale"};
        hiddenSelectionsTextures[] = 
        {
			"\Maiar_ClothingPack\backpacks\Backpack1\Camel_Woods_Co.paa",
            "\Maiar_ClothingPack\backpacks\Backpack1\Camel_Woods_Co.paa",
            "\Maiar_ClothingPack\backpacks\Backpack1\Camel_Woods_Co.paa"
        };
	};
	class Maiar_Military_Backpack_Base: Clothing
	{
		scope = 0;
		displayName = "Military Backpack";
		descriptionShort = "A backpack that holds 2 rifles and 150 slots!";
		model = "Maiar_ClothingPack\backpacks\MilitaryBackpack_g.p3d";
		inventorySlot[] = {"Back"};
		attachments[] = {"Shoulder","Melee","Belt_Left"};
		itemInfo[]= {"Clothing","Back"};
		itemSize[] = {5,7};
		itemsCargoSize[] = {10,15};
		rotationFlags=2;
		quickBarBonus = 2;
		weight=2300;
		varWetMax=0.79000002;
		heatIsolation=1;
		repairableWithKits[]={5,2};
		repairCosts[]={30,25};
		soundAttType="Outdoor";
		randomQuantity=4;
		hiddenSelections[] = {"CamoB","CamoD"};
        hiddenSelectionsTextures[] = 
        {
            "\Maiar_ClothingPack\backpacks\MIlitaryBackpack\Backpack_A_Co.paa",
            "\Maiar_ClothingPack\backpacks\MIlitaryBackpack\Details_A_Co.paa"
        };
		class ClothingTypes
		{
			male = "\Maiar_ClothingPack\backpacks\MilitaryBackpack_m.p3d";
			female = "\Maiar_ClothingPack\backpacks\MilitaryBackpack_m.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 800;
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
				class pickUpItem_Light
				{
					soundSet="pickUpBackPack_Plastic_Light_SoundSet";
					id=796;
				};
				class pickUpItem
				{
					soundSet="pickUpBackPack_Plastic_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="taloonbag_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class Maiar_Military_Backpack_Green: Maiar_Military_Backpack_Base
	{
		scope = 2;
		displayName = "Military Backpack - Green";
		descriptionShort = "A backpack that holds 2 rifles and 150 slots!";
		hiddenSelections[] = {"CamoB","CamoD"};
        hiddenSelectionsTextures[] = 
        {
            "\Maiar_ClothingPack\backpacks\MIlitaryBackpack\Backpack_A_Co.paa",
            "\Maiar_ClothingPack\backpacks\MIlitaryBackpack\Details_A_Co.paa"
        };
	};
	class Maiar_Military_Backpack_Tan: Maiar_Military_Backpack_Base
	{
		scope = 2;
		displayName = "Military Backpack - Tan";
		descriptionShort = "A backpack that holds 2 rifles and 150 slots!";
		hiddenSelections[] = {"CamoB","CamoD"};
        hiddenSelectionsTextures[] = 
        {
            "\Maiar_ClothingPack\backpacks\MIlitaryBackpack\Backpack_Tan.paa",
            "\Maiar_ClothingPack\backpacks\MIlitaryBackpack\DEtails_Tan.paa"
        };
	};
	class Maiar_Military_Backpack_GreenCamo: Maiar_Military_Backpack_Base
	{
		scope = 2;
		displayName = "Military Backpack - Digital Camo ";
		descriptionShort = "A backpack that holds 2 rifles and 150 slots!";
		hiddenSelections[] = {"CamoB","CamoD"};
        hiddenSelectionsTextures[] = 
        {
            "\Maiar_ClothingPack\backpacks\MIlitaryBackpack\Backpack_GreenCamo.paa",
            "\Maiar_ClothingPack\backpacks\MIlitaryBackpack\Details_GreenCamo.paa"
        };
	};
	class Maiar_Military_Backpack_Black: Maiar_Military_Backpack_Base
	{
		scope = 2;
		displayName = "Military Backpack - Black ";
		descriptionShort = "A backpack that holds 2 rifles and 150 slots!";
		hiddenSelections[] = {"CamoB","CamoD"};
        hiddenSelectionsTextures[] = 
        {
            "\Maiar_ClothingPack\backpacks\MIlitaryBackpack\Backpack_Black_co.paa",
            "\Maiar_ClothingPack\backpacks\MIlitaryBackpack\Details_Black_co.paa"
        };
	};
};
class CfgNonAIVehicles
{
    class ProxyAttachment;
    class ProxyMaiar_Weapon: ProxyAttachment
    {
        scope=2;
        inventorySlot="Shoulder";
        model="Maiar_ClothingPack\proxies\maiar_weapon.p3d";
    };
	class ProxyMaiar_Weapon2: ProxyAttachment
    {
        scope=2;
        inventorySlot="Melee";
        model="Maiar_ClothingPack\proxies\maiar_weapon2.p3d";
    };
};
/*class CfgSlots
{
    class Maiar_Weapon
    {
        name = "Shoulder";
        displayName = "Weapon";
        ghostIcon = "iconName";
    };
	class Maiar_Weapon2
    {
        name = "Melee";
        displayName = "Weapon";
        ghostIcon = "iconName";
    };
};*/