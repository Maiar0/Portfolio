class CfgPatches
{
	class Maiar_JugHelm
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
	class Maiar_JugHelm: Clothing
	{
		scope = 2;
		displayName="Juggernaut Helmet";
		descriptionShort="Advanced Helmet with extreme Balistic Protection.";
		model="Maiar_ClothingPack\Jug_Helm\Jug_Helm_g.p3d";
		repairableWithKits[]={8};
		repairCosts[]={25};
		inventorySlot[]={"Headgear"};
		simulation="clothing";
		vehicleClass="Clothing";
		itemInfo[]={"Clothing","Headgear"};
		weight=1000;
		itemSize[]={4,3};
		varWetMax=0.249;
		heatIsolation=0.30000001;
		noMask=0;
		headSelectionsToHide[]=
		{
			"Clipping_Gasmask"
		};
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 250;
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
					class Health 	{ damage=0.2; };
					class Blood 	{ damage=0; };
					class Shock 	{ damage=0.2; };
				};
				class Melee
				{
					class Health 	{ damage=0.2; };
					class Blood 	{ damage=0; };
					class Shock 	{ damage=0.2; };
				};
				class Infected
				{
					class Health 	{ damage=0.2; };
					class Blood 	{ damage=0; };
					class Shock 	{ damage=0.2; };
				};
				class FragGrenade
				{
					class Health 	{ damage=0.2; };
					class Blood 	{ damage=0; };
					class Shock 	{ damage=0.2; };
				};
			};
		};
		class ClothingTypes
		{
			male="Maiar_ClothingPack\Jug_Helm\Jug_Helm.p3d";
			female="Maiar_ClothingPack\Jug_Helm\Jug_Helm_f.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet="pickUpPot_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="BallisticHelmet_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	
	
	
};



