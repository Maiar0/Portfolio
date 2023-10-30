class CfgPatches
{
	class Maiar_Stimpacks
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgMods
{
	class Maiar_Stimpacks
	{
		dir = "maiar";
		author = "AUT";
		version = "1.0";
		extra = 0;
		type = "mod";
		dependencies[] = {"Game","World","Mission"};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"Maiar_Stimpacks/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"Maiar_Stimpacks/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"Maiar_Stimpacks/scripts/5_Mission"};
			};
		};
	};
};
