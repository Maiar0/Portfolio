modded class ActionConstructor
{
	override void RegisterActions(TTypenameArray actions)
	{
		 super.RegisterActions(actions);
		actions.Insert(ActionGiveStimpackSelf);
		actions.Insert(ActionGiveSupperStimpackSelf);
		actions.Insert(ActionGiveBloodStim);
	}
};



class ActionGiveStimpackSelf: ActionInjectSelf
{	
	override void ApplyModifiers( ActionData action_data )
	{
		action_data.m_MainItem.OnApply(action_data.m_Player);
		action_data.m_Player.GetModifiersManager().ActivateModifier(StimModifiers.MDF_STIMPACK);
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
	}
	
};

class ActionGiveSupperStimpackSelf: ActionInjectSelf
{	
	override void ApplyModifiers( ActionData action_data )
	{
		action_data.m_MainItem.OnApply(action_data.m_Player);
		action_data.m_Player.GetModifiersManager().ActivateModifier(StimModifiers.MDF_SUPPERSTIMPACK);
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
	}
};

class ActionGiveBloodStim: ActionInjectSelf
{	
	override void ApplyModifiers( ActionData action_data )
	{
		action_data.m_MainItem.OnApply(action_data.m_Player);
		action_data.m_Player.GetModifiersManager().ActivateModifier(StimModifiers.MDF_BLOODSTIM);
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
	}
};