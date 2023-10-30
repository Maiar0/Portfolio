class Maiar_ActionOpenKeyDoor : ActionSingleUseBase
{
	
	land_Vaultdoor VD;
	
	protected SoundOnVehicle sound;
	
	void Maiar_ActionOpenKeyDoor ()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		
	}

	override void CreateConditionComponents ()
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTCursor;
	}
	
	override bool ActionCondition ( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if ( !target ) 
			return false;
		
		if (!CheckAccess( player, target, item ) ) return false;
		
		if ( Class.CastTo(VD, target.GetObject()) )
		{
			int doorIndex = VD.GetDoorIndex(target.GetComponentIndex());
			if ( doorIndex != -1 )
			{
				if ( !IsInReach(player, target, UAMaxDistances.DEFAULT) ) 
					return false;
				if ( !VD.IsDoorOpen(doorIndex) ) return true;
			}
		}
		
		return false;
	}
	
	override string GetText()
	{
		return " Unlock ";
	}
	
	override bool ActionConditionContinue ( ActionData action_data ) { return true; }
	
	
	override void OnStartServer( ActionData action_data )
	{
		
		Building building;
		Object obj = action_data.m_Target.GetObject();
		
		if ( Class.CastTo(VD, action_data.m_Target.GetObject()) )
		{
			int doorIndex = VD.GetDoorIndex(action_data.m_Target.GetComponentIndex());
			if ( doorIndex != -1 )
			{
				VD.OpenDoor(doorIndex);
				//Print("[Maiars Keycards]" + " Succesfully opened doorindex = " + doorIndex  )
				if( GetMaiarsKeyCardConfig().ShouldDoorAutoClose ) 
				{
					VD.AutoCloseDoor( obj , doorIndex);
				}
				if( GetMaiarsKeyCardConfig().ActivateLootCrates ) 
				{
					VD.PrepareLoot(obj);
				}
				
			}
			
			action_data.m_MainItem.Delete();
			
		}  
		
	}
	
	override void OnEndServer( ActionData action_data )
	{
		if ( Class.CastTo(VD, action_data.m_Target.GetObject()) )
		{
			SoundPlay(VD);
		}
	}
	
	bool CheckAccess(PlayerBase player, ActionTarget target, ItemBase item)
	{
		string m_ItemInHands = item.ConfigGetString("KeyTier");
		string m_Target = target.GetObject().GetType();
		if(m_Target == m_ItemInHands)
			return true;
		return false; 
	}
	
	void SoundPlay(Object obj)
    {
		bool isActive = GetMaiarsKeyCardConfig().ShouldAlarmPlay;
		if( isActive )
		{
			sound = GetGame().CreateSoundOnObject(obj, "Maiar_DoorAlarm1", 1000, false);
		}
		//Dirty needs work
    }
	
	
}