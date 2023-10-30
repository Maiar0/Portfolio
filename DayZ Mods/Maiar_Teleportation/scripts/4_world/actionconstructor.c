modded class ActionConstructor
{
	override void RegisterActions (TTypenameArray actions)
	{
		super.RegisterActions(actions);
		
		actions.Insert( Maiar_ActionTeleport_item );
		actions.Insert( Maiar_ActionTeleport_interact );
		
	}
};	