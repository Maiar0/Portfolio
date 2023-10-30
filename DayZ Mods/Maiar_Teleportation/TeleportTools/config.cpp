class CfgPatches
{
	class maiar_TeleportationTools
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
	
	
	class HouseNoDestruct;
	class Maiar_Teleportation_Static_base: HouseNoDestruct
	{
		scope=2;
		model="Maiar_Teleportation\TeleportTools\TeleportationTerminal.p3d";
		
	};
	
	class Maiar_Teleportation_ticket_base: Inventory_Base
	{
		scope=0;
		displayName="Teleportation Ticket";
		descriptionShort="This ticket is used to teleport you to various locations, procceed to a teleportation terminal to find out where this one goes!";
		model="Maiar_Teleportation\TeleportTools\TeleportTicket.p3d";
		TeleportConfig = 0;
		TeleportLocationStatic[]= 
		{
			4588.069824, 340.575836, 10161.299805
		};
	};
	class Maiar_Teleportation_ticket01: Maiar_Teleportation_ticket_base
	{
		scope=2;
		displayName="Teleportation Ticket - South Safezone";
		TeleportConfig = 1;
	};
	class Maiar_Teleportation_ticket02: Maiar_Teleportation_ticket_base
	{
		scope=2;
		displayName="Teleportation Ticket - North Safezone";
		TeleportConfig = 2;
	};
	class Maiar_Teleportation_ticket03: Maiar_Teleportation_ticket_base
	{
		scope=2;
		TeleportConfig = 3;
	};
	class Maiar_Teleportation_ticket04: Maiar_Teleportation_ticket_base
	{
		scope=2;
		TeleportConfig = 4;
	};
	class Maiar_Teleportation_ticket05: Maiar_Teleportation_ticket_base
	{
		scope=2;
		TeleportConfig = 5;
	};
	
	class Maiar_Teleportation_token_base: Inventory_Base
	{
		scope=0;
		displayName="Teleportation Token";
		descriptionShort="This is a teleportation token, put it in your hand to find out where it takes your!";
		model="Maiar_Teleportation\TeleportTools\TeleportToken.p3d";
		TeleportConfig = 0;
		TeleportLocation[]= 
		{
			4588.069824, 340.575836, 10161.299805
		};
	};
	class Maiar_Teleportation_token01: Maiar_Teleportation_token_base
	{
		scope=2;
		displayName="Teleportation Token - South SafeZone";
		TeleportConfig = 1;
	};
	class Maiar_Teleportation_token02: Maiar_Teleportation_token_base
	{
		scope=2;
		displayName="Teleportation Token - North SafeZone";
		TeleportConfig = 2;
	};
	class Maiar_Teleportation_token03: Maiar_Teleportation_token_base
	{
		scope=2;
		TeleportConfig = 3;
	};
	class Maiar_Teleportation_token04: Maiar_Teleportation_token_base
	{
		scope=2;
		TeleportConfig = 4;
	};
	class Maiar_Teleportation_token05: Maiar_Teleportation_token_base
	{
		scope=2;
		TeleportConfig = 5;
	};
	
};