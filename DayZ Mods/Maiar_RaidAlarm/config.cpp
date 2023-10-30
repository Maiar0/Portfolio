class CfgPatches
{
	class Maiar_RaidAlarm
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = 
		{
		"DZ_Data",
		"DZ_Scripts",
		"HDSN_BreachingCharge"
		};
	};
};
class CfgMods
{
	class Maiar_RaidAlarm
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
				files[]= {"Maiar_RaidAlarm/scripts/3_Game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"Maiar_RaidAlarm/Scripts/4_World"};
			};
			class missionScriptModule
			{
				value="";
				files[]= {"Maiar_RaidAlarm/scripts/5_Mission"};
			};
        };
    };
};
class cfgvehicles
{
	class Inventory_Base;
	
};