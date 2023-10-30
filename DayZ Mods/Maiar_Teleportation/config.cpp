class CfgPatches
{
	class maiar_Teleportation
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
class CfgMods
{
	class Maiar_Teleportation
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
				files[]= {"Maiar_Teleportation/scripts/3_Game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"Maiar_Teleportation/Scripts/4_World"};
			};
			class missionScriptModule
			{
				value="";
				files[]= {"Maiar_Teleportation/scripts/5_Mission"};
			};
        };
    };
};
class cfgvehicles
{
	class Inventory_Base;
	
};