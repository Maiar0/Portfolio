class CfgPatches
{
	class Maiar_ExtractionSafezones
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.0;
		requiredAddons[] = 
		{
		"DZ_Data",
		"DZ_Scripts",
		"Maiar_ExtractionSafezoneAssets",
		"JM_CF_Scripts"
		};
	};
};
class CfgMods
{
	class Maiar_ExtractionSafezones
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
				files[]= {"Maiar_ExtractionSafezones/scripts/3_Game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"Maiar_ExtractionSafezones/Scripts/4_World"};
			};
			class missionScriptModule
			{
				value="";
				files[]= {"Maiar_ExtractionSafezones/scripts/5_Mission"};
			};
        };
    };
};
class cfgvehicles
{
};