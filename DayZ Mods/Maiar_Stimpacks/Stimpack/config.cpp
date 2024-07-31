class CfgPatches
{
	class Mar_Stimpack
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
	class Mar_Stimpack: Inventory_Base
	{
		scope=0;
		displayName="Stimpack";
		descriptionShort="Heals a small amount of health rapidly.";
		model="Maiar_Stimpacks\Stimpack\BloodStim.p3d";
		rotationFlags=17;
		itemSize[]={1,2};
		weight=200;
		isMeleeWeapon=1;
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = 
        {
            "Maiar_Stimpacks\Stimpack\Data\Blue_co.paa"
        };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=20;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\medical\data\transfusion_kit.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\medical\data\transfusion_kit.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\medical\data\transfusion_kit_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\medical\data\transfusion_kit_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\medical\data\transfusion_kit_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class Syringe_out
				{
					soundSet="Syringe_out_SoundSet";
					id=201;
				};
				class Syringe_spear
				{
					soundSet="Syringe_spear_SoundSet";
					id=202;
				};
				class Syringe_splash
				{
					soundSet="Syringe_splash_SoundSet";
					id=203;
				};
			};
		};
	};
	class Mar_SuperStimpack: Inventory_Base
	{
		scope=0;
		displayName="Super Stimpack";
		descriptionShort="Heals a Large amount of health rapidly.";
		model="Maiar_Stimpacks\Stimpack\BloodStim.p3d";
		rotationFlags=17;
		itemSize[]={1,2};
		weight=200;
		isMeleeWeapon=1;
		hiddenSelections[] = {"Camo"};
		 hiddenSelectionsTextures[] = 
        {
            "Maiar_Stimpacks\Stimpack\Data\Green_Co.paa"
        };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=20;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\medical\data\transfusion_kit.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\medical\data\transfusion_kit.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\medical\data\transfusion_kit_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\medical\data\transfusion_kit_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\medical\data\transfusion_kit_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class Syringe_out
				{
					soundSet="Syringe_out_SoundSet";
					id=201;
				};
				class Syringe_spear
				{
					soundSet="Syringe_spear_SoundSet";
					id=202;
				};
				class Syringe_splash
				{
					soundSet="Syringe_splash_SoundSet";
					id=203;
				};
			};
		};
	};
	class Mar_BloodStimpack: Inventory_Base
	{
		scope=0;
		displayName="Blood Stimpack";
		descriptionShort="Heals a Large amount of Blood rapidly.";
		model="Maiar_Stimpacks\Stimpack\BloodStim.p3d";
		rotationFlags=17;
		itemSize[]={1,2};
		weight=200;
		isMeleeWeapon=1;
		hiddenSelections[] = {"Camo"};
        hiddenSelectionsTextures[] = 
        {
            "Maiar_Stimpacks\Stimpack\Data\Blood_Co.paa"
        };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=20;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\medical\data\transfusion_kit.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\medical\data\transfusion_kit.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\medical\data\transfusion_kit_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\medical\data\transfusion_kit_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\medical\data\transfusion_kit_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class Syringe_out
				{
					soundSet="Syringe_out_SoundSet";
					id=201;
				};
				class Syringe_spear
				{
					soundSet="Syringe_spear_SoundSet";
					id=202;
				};
				class Syringe_splash
				{
					soundSet="Syringe_splash_SoundSet";
					id=203;
				};
			};
		};
	};
	class Kryptic_Stimpack: Mar_Stimpack
	{
		scope=2;
		displayName="Kryptic Stimpack";
		descriptionShort="Heals a small amount of health rapidly.(25 instantly and 25 over time)";
		hiddenSelections[] = {"Camo"};
        hiddenSelectionsTextures[] = 
        {
            "Maiar_Stimpacks\Stimpack\Data\Blue_co.paa"
        };
	};
	class Kryptic_Super_Stimpack: Mar_SuperStimpack
	{
		scope=2;
		displayName="Kryptic Super Stimpack";
		descriptionShort="Heals a Large amount of health rapidly.(50 instantly and 50 over time)";
		hiddenSelections[] = {"Camo"};
        hiddenSelectionsTextures[] = 
        {
            "Maiar_Stimpacks\Stimpack\Data\Green_Co.paa"
        };
	};
	class Kryptic_Blood_Stimpack: Mar_BloodStimpack
	{
		scope=2;
		displayName="Kryptic Blood Infusion";
		descriptionShort="Heals a Large amount of Blood rapidly.(1000 instantly and 3500 over time)";
		hiddenSelections[] = {"Camo"};
        hiddenSelectionsTextures[] = 
        {
            "Maiar_Stimpacks\Stimpack\Data\Blood_Co.paa"
        };
	};
	
};