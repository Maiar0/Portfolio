class Mar_SuperStimpack: Inventory_Base
{
	override void SetActions()
	{
		super.SetActions();
		
		//AddAction(ActionGiveSalineTarget);
		AddAction(ActionGiveSupperStimpackSelf);
	}
};

class SupperStimpackMdfr: ModifierBase
{
	float m_RegenTime;
	override void Init()
	{
		m_TrackActivatedTime = true;
		m_IsPersistent = true;
		m_ID = StimModifiers.MDF_SUPPERSTIMPACK
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
		if( player.GetNotifiersManager() )
			player.GetNotifiersManager().ActivateByType(eNotifiers.NTF_PILLS);
		if(player.GetHealth("GlobalHealth", "Health") > 50)
			
			player.SetHealth("GlobalHealth","Health", 100);
		if(player.GetHealth("GlobalHealth", "Health") < 50)
			
			player.AddHealth("GlobalHealth", "Health", 50);
	}
	
	override void OnDeactivate(PlayerBase player)
	{
		if( player.GetNotifiersManager() )
			player.GetNotifiersManager().DeactivateByType(eNotifiers.NTF_PILLS);
	}

	override void OnTick(PlayerBase player, float deltaT)
	{
		float blood =  player.GetHealth("GlobalHealth", "Blood");

		float regen_speed = 0.4;
		regen_speed = regen_speed * deltaT;
		if( player.GetHealth("GlobalHealth", "Health") > 0.001 )
		{
			player.AddHealth("GlobalHealth", "Health" ,  regen_speed * 5.5 );
		}
		player.AddHealth("GlobalHealth","Health",regen_speed );
		
	}
	
	float CalculateRegenTime()
	{
		float regen_time = 20
         return regen_time;
	}
};