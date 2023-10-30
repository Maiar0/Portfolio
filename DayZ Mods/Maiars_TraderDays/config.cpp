class CfgPatches
{
	class Maiars_TraderDays
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = 
		{
		"DZ_Data",
		"DZ_Scripts",
		"Trader"
		};
	};
};
class CfgMods
{
	class Maiars_TraderDays
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
				files[]= {"Maiars_TraderDays/scripts/3_Game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"Maiars_TraderDays/Scripts/4_World"};
			};
			class missionScriptModule
			{
				value="";
				files[]= {"Maiars_TraderDays/scripts/5_Mission"};
			};
        };
    };
};
class cfgvehicles
{
	class Inventory_Base;
	
};