class Mar_BloodStimpack: Inventory_Base
{
	override void SetActions()
	{
		super.SetActions();
		
		//AddAction(ActionGiveSalineTarget);
		AddAction(ActionGiveBloodStim);
	}
};

class BloodStimMdfr: ModifierBase
{
	float m_RegenTime;
	override void Init()
	{
		m_TrackActivatedTime = true;
		m_IsPersistent = true;
		m_ID = StimModifiers.MDF_BLOODSTIM
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= DEFAULT_TICK_TIME_ACTIVE;
		m_RegenTime = CalculateRegenTime();
	}

	override bool ActivateCondition(PlayerBase player)
	{
		return false;
	}

	override bool DeactivateCondition(PlayerBase player)
	{
		float attached_time = GetAttachedTime();

		if ( attached_time > m_RegenTime )
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	override void OnReconnect(PlayerBase player)
	{
		OnActivate(player);
	}
	
	override void OnActivate(PlayerBase player)
	{
		Print(player.GetHealth("GlobalHealth", "Blood"))
		if( player.GetNotifiersManager() )
			player.GetNotifiersManager().ActivateByType(eNotifiers.NTF_PILLS);
		if(player.GetHealth("GlobalHealth", "Blood") > 4500)
			player.SetHealth("GlobalHealth","Blood", 5000);
		
		if(player.GetHealth("GlobalHealth", "Blood") < 4500)
			player.AddHealth("GlobalHealth", "Blood", 500);
	}
	
	override void OnDeactivate(PlayerBase player)
	{
		if( player.GetNotifiersManager() )
			player.GetNotifiersManager().DeactivateByType(eNotifiers.NTF_PILLS);
	}

	override void OnTick(PlayerBase player, float deltaT)
	{
		float blood =  player.GetHealth("GlobalHealth", "Blood");

		float regen_speed = 10;
		regen_speed = regen_speed * deltaT;
		if( player.GetHealth("GlobalHealth", "Blood") > 0.001 )
		{
			player.AddHealth("GlobalHealth", "Blood" ,  regen_speed * 5.5 );
			Print(regen_speed * 5.5)
		}
		player.AddHealth("GlobalHealth","Blood",regen_speed );
		
	}
	
	float CalculateRegenTime()
	{
		float regen_time = 20
         return regen_time;
	}
};