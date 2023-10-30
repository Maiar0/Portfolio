class ActionKit01 : ActionSingleUseBase
{
	string kitname;
	ItemBase old_item;
	protected ref array<string> m_KitItems = {};
	
	void ActionKit01 ()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_PICKUP_HANDS;
	}

	override void CreateConditionComponents ()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNone;
	}

	

	override bool HasTarget () { return false; }

	override bool ActionCondition ( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if (item)
			return true;
		return false;
	}
	
	override string GetText()
	{
		return "Unpack";
	}

	override bool ActionConditionContinue ( ActionData action_data ) { return true; }

	override void OnExecuteClient ( ActionData action_data )
    {
        #ifdef DAYZ_1_11
            ClearInventoryReservation(action_data);
        #else
            ClearInventoryReservationEx(action_data);
        #endif
    }
	
	
	
	override void OnExecuteServer ( ActionData action_data )
	{
		if ( !GetGame().IsMultiplayer() )
		{
			#ifdef DAYZ_1_11
				ClearInventoryReservation(action_data);
			#else
				ClearInventoryReservationEx(action_data);
			#endif
		}
		old_item = action_data.m_MainItem;
		if (old_item.ConfigIsExisting("KitItems"))
		{
			old_item.ConfigGetTextArray("KitItems", m_KitItems);
			foreach (string kt: m_KitItems) 
			{
				Print(kt)
				vector pos = action_data.m_Player.GetPosition();
				Print( pos );
				ItemBase item = ItemBase.Cast( GetGame().CreateObjectEx(kt , pos , ECE_PLACE_ON_SURFACE) );
				if (!item) 
				{
					continue;
				}
			}
			old_item.Delete()
		}
	}
};
