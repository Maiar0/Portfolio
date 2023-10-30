class CfgPatches
{
	class Maiars_Kits
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
	class Maiars_Kits
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
				files[]= {"Maiars_Kits/scripts/3_Game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"Maiars_Kits/Scripts/4_World"};
			};
			class missionScriptModule
			{
				value="";
				files[]= {"Maiars_Kits/scripts/5_Mission"};
			};
        };
    };
};
class cfgvehicles
{
	class Inventory_Base;
	
};