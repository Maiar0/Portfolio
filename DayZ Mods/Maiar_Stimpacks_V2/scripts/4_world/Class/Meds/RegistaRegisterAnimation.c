 modded class ModItemRegisterCallbacks
{
	override void RegisterOneHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterOneHanded(pType, pBehavior);
        pBehavior.SetToolsOneHanded();
        
        pType.AddItemInHandsProfileIK("Mar_Stimpack", "dz/anims/workspaces/player/player_main/props/player_main_1h_morphine.asi", pBehavior,"dz/anims/anm/player/ik/gear/morphine.anm");
		pType.AddItemInHandsProfileIK("Mar_SuperStimpack", "dz/anims/workspaces/player/player_main/props/player_main_1h_morphine.asi", pBehavior,"dz/anims/anm/player/ik/gear/morphine.anm");
		pType.AddItemInHandsProfileIK("Mar_BloodStimpack", "dz/anims/workspaces/player/player_main/props/player_main_1h_morphine.asi", pBehavior,"dz/anims/anm/player/ik/gear/morphine.anm");
		pType.AddItemInHandsProfileIK("AUT_MedX", "dz/anims/workspaces/player/player_main/props/player_main_1h_morphine.asi", pBehavior,"dz/anims/anm/player/ik/gear/morphine.anm");
		
    }
}