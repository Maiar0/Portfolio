 modded class ModItemRegisterCallbacks
{
	override void RegisterOneHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterOneHanded(pType, pBehavior);
        pBehavior.SetToolsOneHanded();
        
        pType.AddItemInHandsProfileIK("Maiar_keyCard_base", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior,"dz/anims/anm/player/ik/gear/zucchini_seeds_pack.anm");
		
    }
}