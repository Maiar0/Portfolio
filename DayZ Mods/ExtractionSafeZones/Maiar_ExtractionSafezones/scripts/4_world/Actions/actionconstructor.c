modded class PlayerBase
{
   
    override void SetActions(out TInputActionMap InputActionMap)
	{
		super.SetActions(InputActionMap);

        AddAction(Maiar_ActionExtract, InputActionMap);
        AddAction(Maiar_ActionExtractSafezone_One, InputActionMap);
        AddAction(Maiar_ActionExtractSafezone_Two, InputActionMap);
        AddAction(Maiar_ActionExtractSafezone_Three, InputActionMap);
        AddAction(Maiar_ActionExtractSafezone_Four, InputActionMap);
        AddAction(Maiar_ActionExtractSafezone_Five, InputActionMap);
        AddAction(Maiar_ActionExtractSafezone_Six, InputActionMap);
        AddAction(Maiar_ActionExtractSafezone_Seven, InputActionMap);
        AddAction(Maiar_ActionExtractSafezone_Eight, InputActionMap);
        AddAction(Maiar_ActionExtractSafezone_Nine, InputActionMap);
	}
}
modded class ActionConstructor
{
    override void RegisterActions(TTypenameArray actions)
    {
        super.RegisterActions(actions);
        
        actions.Insert(Maiar_ActionExtract);
        actions.Insert(Maiar_ActionExtractSafezone_One);
        actions.Insert(Maiar_ActionExtractSafezone_Two);
        actions.Insert(Maiar_ActionExtractSafezone_Three);
        actions.Insert(Maiar_ActionExtractSafezone_Four);
        actions.Insert(Maiar_ActionExtractSafezone_Five);
        actions.Insert(Maiar_ActionExtractSafezone_Six);
        actions.Insert(Maiar_ActionExtractSafezone_Seven);
        actions.Insert(Maiar_ActionExtractSafezone_Eight);
        actions.Insert(Maiar_ActionExtractSafezone_Nine);
    }
}