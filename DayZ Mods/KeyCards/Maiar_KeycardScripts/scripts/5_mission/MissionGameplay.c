modded class MissionGameplay extends MissionBase
{
	protected bool m_isModdedMissionInitialized = false;
	
	override void OnInit()
	{
		super.OnInit();
		if(!m_isModdedMissionInitialized) 
		{
			GetRPCManager().AddRPC( "KD_Scripts", "CONFIGRESPONSE", this, SingeplayerExecutionType.Client );
			m_isModdedMissionInitialized = true;
		}
	}

	override void OnMissionStart()
	{
		super.OnMissionStart();
		GetRPCManager().SendRPC("KD_Scripts", "CLIENTCONFIGREQUEST", null, true);//Sends the server a request to get the config.
	}

	/* RPC HANDLING OF CLIENT */ 
	void CONFIGRESPONSE(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target) {

		if(type == CallType.Client) 
		{
			Param1 <ref Maiar_MaiarsKeyCardsConfigManager> data;
        	if ( !ctx.Read( data ) ) return;
			g_ClientMaiarsKeyCardConfig = data.param1; //Update our reference in Gamemodule.
			Print("[MaiarsKeyCard] Sucessfully recieved config from server!");
		}
	}
}