class Maiar_Teleportation_Static_base extends BuildingSuper
{
	
};

class Maiar_Teleportation_token_base extends ItemBase
{
	override void SetActions()
	{
		super.SetActions();		
		AddAction(Maiar_ActionTeleport_item);
	}
};

class Maiar_Teleportation_ticket_base extends ItemBase
{
	override void SetActions()
	{
		super.SetActions();		
		AddAction(Maiar_ActionTeleport_interact);
	}
};

/*class Maiar_Teleportation_ticket01: Maiar_Teleportation_ticket_base
{
	override bool OnStoreLoad( ParamsReadContext ctx, int version )
	{
		if ( !super.OnStoreLoad(ctx, version) )
			return false;
		
		SetName(MaiarTeleportGlobals.Get().g_ticket01_name);
			return true;
	}
};
class Maiar_Teleportation_ticket02: Maiar_Teleportation_ticket_base
{
	override bool OnStoreLoad( ParamsReadContext ctx, int version )
	{
		if ( !super.OnStoreLoad(ctx, version) )
			return false;
		
		SetName(MaiarTeleportGlobals.Get().g_ticket02_name);
			return true;
	}
};
class Maiar_Teleportation_ticket03: Maiar_Teleportation_ticket_base
{
	override bool OnStoreLoad( ParamsReadContext ctx, int version )
	{
		if ( !super.OnStoreLoad(ctx, version) )
			return false;
		
		SetName(MaiarTeleportGlobals.Get().g_ticket03_name);
			return true;
	}
};
class Maiar_Teleportation_ticket04: Maiar_Teleportation_ticket_base
{
	override bool OnStoreLoad( ParamsReadContext ctx, int version )
	{
		if ( !super.OnStoreLoad(ctx, version) )
			return false;
		
		SetName(MaiarTeleportGlobals.Get().g_ticket04_name);
			return true;
	}
};
class Maiar_Teleportation_ticket05: Maiar_Teleportation_ticket_base
{
	override bool OnStoreLoad( ParamsReadContext ctx, int version )
	{
		if ( !super.OnStoreLoad(ctx, version) )
			return false;
		
		SetName(MaiarTeleportGlobals.Get().g_ticket05_name);
		return true;
	}
};*/


