class Maiar_ActionTeleport_item : ActionSingleUseBase
{
	ItemBase old_item;
	int m_Teleport;
	string Location;
	
	void Maiar_ActionTeleport_item ()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_PICKUP_HANDS;
	}

	override void CreateConditionComponents ()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNone;
	}
	
	override bool ActionCondition ( PlayerBase player, ActionTarget target, ItemBase item )
	{
		
		if ( !CastTo( old_item , item )	)			return false;
			m_Teleport = old_item.ConfigGetInt("TeleportConfig");
		if(item) return true;
		return false;
	}
	
	override string GetText()
	{
		if(m_Teleport ==  0)
		{
			Location = old_item.ConfigGetString("displayName");
		}
		if( m_Teleport == 1)
		{ 
			Location = GetTeleportTerminalConfig().g_token01_name;
		}
		if( m_Teleport == 2)
		{ 
			Location = GetTeleportTerminalConfig().g_token02_name;
		}
		if( m_Teleport == 3)
		{ 
			Location = GetTeleportTerminalConfig().g_token03_name;
		}
		if( m_Teleport == 4)
		{ 
			Location = GetTeleportTerminalConfig().g_token04_name;
		}
		if( m_Teleport == 5)
		{ 
			Location = GetTeleportTerminalConfig().g_token05_name;
		}
		if(Location == string.Empty)
		{
			Print("[TeleportTerminal] GetText String Empty" + Location);
		}
		//Print("[TeleportTerminal] GetText " + Location);
		
		return "Teleport to " + Location ;
	}
	
	override bool ActionConditionContinue ( ActionData action_data ) { return true; }
	
	override void OnEndServer( ActionData action_data )
	{
		vector pos;
		m_Teleport = old_item.ConfigGetInt("TeleportConfig");
		if(m_Teleport ==  0)
		{
			pos = old_item.ConfigGetVector("TeleportLocation");
		}
		if( m_Teleport == 1)
		{ 
			pos = GetTeleportTerminalConfig().g_token01;
		}
		if( m_Teleport == 2)
		{ 
			pos = GetTeleportTerminalConfig().g_token02;
		}
		if( m_Teleport == 3) 
		{ 
			pos = GetTeleportTerminalConfig().g_token03;
		}
		if( m_Teleport == 4)
		{ 
			pos = GetTeleportTerminalConfig().g_token04;
		}
		if( m_Teleport == 5)
		{ 
			pos = GetTeleportTerminalConfig().g_token05;
		}
		if ( !pos )
			Print( "!!! \"TeleportLocation\" has invalid format" );
		Print("[TeleportTerminal] EndServer Token Number " + m_Teleport);
		Print("Teleported With Token to " + pos);
		action_data.m_Player.SetPosition( pos );
		GetGame().ObjectDelete( old_item );
	}
	
}
