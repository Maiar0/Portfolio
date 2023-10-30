class CfgPatches
{
	class Maiar_KeycardScripts
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = 
		{
		"DZ_Data",
		"DZ_Scripts",
		"Maiar_KeycardAssets",
		"JM_CF_Scripts"
		};
	};
};
class CfgMods
{
	class Maiar_KeycardScripts
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
				files[]= {"Maiar_KeycardScripts/scripts/3_Game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"Maiar_KeycardScripts/Scripts/4_World"};
			};
			class missionScriptModule
			{
				value="";
				files[]= {"Maiar_KeycardScripts/scripts/5_Mission"};
			};
        };
    };
};
class cfgvehicles
{
};