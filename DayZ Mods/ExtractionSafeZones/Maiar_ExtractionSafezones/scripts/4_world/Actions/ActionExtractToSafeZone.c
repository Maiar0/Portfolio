class Maiar_ActionExtract: ActionInteractBase
{
	Maiar_ExtractionPoint_base EP;
	
	void Maiar_ActionExtract()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_HUDCursorIcon = CursorIcons.CloseHood;
	}

    override void CreateConditionComponents()  
	{
		m_ConditionTarget = new CCTObject(10);//CCTMan(10);
		m_ConditionItem = new CCINone;
	}

	override string GetText()
	{
		return "Extract";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
    {
        /*if ( GetGame().IsServer() )
            return true;*/
		if ( !target ) 
			return false;
		
		if ( !Class.CastTo(EP, target.GetObject()) ) return false;
		
        return true;
    }
    
	override void OnEndServer( ActionData action_data )
	{
		int i = Math.RandomInt(0, GetMaiarsExtractionSafezonesConfig().SafezonePosition.Count() );
		vector pos = GetMaiarsExtractionSafezonesConfig().SafezonePosition.Get(i).GetPosition();
		if ( !pos )
			Print( "!!! \"TeleportLocation\" has invalid format" );
		action_data.m_Player.SetPosition( pos );
	}
}