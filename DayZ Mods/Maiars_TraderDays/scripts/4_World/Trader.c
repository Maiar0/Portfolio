modded class ActionTrade: ActionInteractBase
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
    {
		int TraderDays = TraderAvailble.IsTraderAvailble()
		Print(TraderDays); 
		if (TraderDays == 0)
		{
			Print("Trader is Off")
			//player.MessageStatus("Trader is Unavailble During this time");                
			return false;
		}
		
        if ( GetGame().IsServer() )
            return true;

		if ( player.m_Trader_RecievedAllData == false )
        {            
            //player.MessageStatus("[Trader] MISSING TRADER DATA FROM SERVER!");                
            return false;
        }
        
        bool isTraderNPCCharacter = false;

        PlayerBase ntarget = PlayerBase.Cast( target.GetObject() );
        
        if ( ntarget )
            isTraderNPCCharacter = ntarget.m_Trader_IsTrader;

        bool isTraderNPCObject = false;
        for ( int i = 0; i < player.m_Trader_NPCDummyClasses.Count(); i++ )
        {
            if ( target.GetObject().GetType() == player.m_Trader_NPCDummyClasses.Get(i) )
                isTraderNPCObject = true;
        }

        if ( !isTraderNPCCharacter && !isTraderNPCObject )
            return false;

        vector playerPosition = player.GetPosition();

        // only call these after we made sure the client has all trader data loaded!
        int traderUID = getNearbyTraderUID(playerPosition);
        bool canOpenTraderMenu = getCanOpenTraderMenu( playerPosition, traderUID );

        if ( !canOpenTraderMenu )
            return false;

        return true;
    }
}