modded class MissionGameplay extends MissionBase
{
	protected bool m_isModdedMissionInitialized = false;
	
	override void OnInit()
	{
		super.OnInit();
		if(!m_isModdedMissionInitialized) 
		{
			GetRPCManager().AddRPC( "TT_Scripts", "CONFIGRESPONSE", this, SingeplayerExecutionType.Client );
			m_isModdedMissionInitialized = true;
		}
	}

	override void OnMissionStart()
	{
		super.OnMissionStart();
		GetRPCManager().SendRPC("TT_Scripts", "CLIENTCONFIGREQUEST", null, true);//Sends the remote a request to get the config.
	}

	/* RPC HANDLING OF CLIENT */ 
	void CONFIGRESPONSE(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target) {

		if(type == CallType.Client) 
		{
			Param1 <ref Maiar_TeleportTerminalsConfigManager> data;
        	if ( !ctx.Read( data ) ) return;
			g_ClientTeleportTerminalConfig = data.param1; //Update our reference in Gamemodule.
			Print("[TeleportTerminal] Sucessfully recieved config from remote!");
		}
	}
}