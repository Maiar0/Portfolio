modded class HDSN_ActionArmBreachingCharge : ActionInteractBase
{
	
	
	override void OnEndServer( ActionData action_data )
	{
		PlayerBase player = action_data.m_Player;
		
		if ( HasRaidAlarmPanel( action_data ) )
		{
			Print("[[RAIDALARM]] Found Alarm Panel");
			string Owner = Maiar_TerritoryFlagOwner( action_data );
			if ( Owner != string.Empty )
			{
				string RaidMessage = Owner +" is being RAIDED!!";
				NotificationSystem.SimpleNoticiation( RaidMessage );
				Print("[[RAIDALARM]] Found Flag Pole");
			}
			
		}
		
		
		super.OnEndServer(action_data);
	}
	
	bool HasRaidAlarmPanel( ActionData action_data )
	{
		array<Object> objects = new array<Object>;
		array<CargoBase> proxyCargos = new array<CargoBase> ;
		GetGame().GetObjectsAtPosition( action_data.m_Player.GetPosition(), 75, objects, proxyCargos );
		
		for ( int i = 0; i < objects.Count(); ++i )
		{
			//Print( objects[i] );
			if ( objects[i].IsInherited( Maiar_RaidAlarmPanel ) )//&& objects[i].IsInherited( TerritoryFlag ))
			{
				
				vector pos = objects[i].GetPosition();
				Print("[[RAIDALARM]] Found Alarm Panel" + pos + objects[i] );
				return true;
			}
		}
		return false;
	}
	
	string Maiar_TerritoryFlagOwner( ActionData action_data )
	{
		string Owner;
		array<Object> objects = new array<Object>;
		array<CargoBase> proxyCargos = new array<CargoBase> ;
		GetGame().GetObjectsAtPosition( action_data.m_Player.GetPosition(), 75, objects, proxyCargos );
		
		for ( int i = 0; i < objects.Count(); ++i )
		{
			if ( objects[i].IsInherited( TerritoryFlag ) )//&& objects[i].IsInherited( TerritoryFlag ))
			{
				
				vector pos = objects[i].GetPosition();
				TerritoryFlag nearest = TerritoryFlag.FindNearestFlag(pos);
				Owner = nearest.ownerGroupTag;
				SendMessagetoDiscord( Owner );
				Print(" [[RaidAlarm]] Owner of flag Pole: " + Owner);
			}
			
		}
		return Owner;
	}
	
	
}