modded class ActionOpenDoors: ActionInteractBase
{
	land_Vaultdoor VD;
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if ( !target ) 
			return false;
		
		if ( Class.CastTo(VD, target.GetObject()) ) return false;
		
		return super.ActionCondition( player, target, item );
	}
	
};