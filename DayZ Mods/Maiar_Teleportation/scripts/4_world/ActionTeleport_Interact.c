class Maiar_ActionTeleport_interact: ActionSingleUseBase
{
	Maiar_Teleportation_Static_base ttp;
	ItemBase old_item;
	int m_Teleport;
	string Location;
	
	void Maiar_ActionTeleport_interact ()
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
		if ( !CastTo( ttp , target.GetObject() ) )	return false;
		
		return true;
	}
	
	override string GetText()
	{
		if(m_Teleport ==  0)
		{
			Location = old_item.ConfigGetString("displayName");
		}
		if( m_Teleport == 1)
		{ 
			Location = GetTeleportTerminalConfig().g_ticket01_name;
		}
		if( m_Teleport == 2)
		{ 
			Location = GetTeleportTerminalConfig().g_ticket02_name;
		}
		if( m_Teleport == 3)
		{ 
			Location = GetTeleportTerminalConfig().g_ticket03_name;
		}
		if( m_Teleport == 4)
		{ 
			Location = GetTeleportTerminalConfig().g_ticket04_name;
		}
		if( m_Teleport == 5)
		{ 
			Location = GetTeleportTerminalConfig().g_ticket05_name;
		}
		if(Location == string.Empty)
		{
			Print("[TeleportTerminal] GetText String Empty" + Location);
		}
		//Print("[TeleportTerminal] GetText " + Location);
		
		return "Teleport to " + Location ;
	}
	
	override void OnEndServer( ActionData action_data )
	{
		vector pos;
		if(m_Teleport ==  0)
		{
			pos = old_item.ConfigGetVector("TeleportLocationStatic");
		}
		if( m_Teleport == 1)
		{ 
			pos = GetTeleportTerminalConfig().g_ticket01;
		}
		if( m_Teleport == 2)
		{ 
			pos = GetTeleportTerminalConfig().g_ticket02;
		}
		if( m_Teleport == 3)
		{ 
			pos = GetTeleportTerminalConfig().g_ticket03;
		}
		if( m_Teleport == 4)
		{ 
			pos = GetTeleportTerminalConfig().g_ticket04;
		}
		if( m_Teleport == 5)
		{ 
			pos = GetTeleportTerminalConfig().g_ticket05;
		}
		
		if ( !pos )
			Print( "!!! \"TeleportLocationStatic\" has invalid format" );
		Print("[TeleportTerminal] EndServer Ticket Number " + m_Teleport);
		Print("Teleported With Ticket to " + pos);
		action_data.m_Player.SetPosition( pos );
		GetGame().ObjectDelete( old_item );
	}
}