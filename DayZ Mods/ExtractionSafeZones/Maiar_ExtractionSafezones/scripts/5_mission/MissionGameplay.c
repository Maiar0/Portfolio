modded class MissionGameplay extends MissionBase
{
	protected bool m_isModdedMissionInitialized = false;
	
	override void OnInit()
	{
		super.OnInit();
			
			GetRPCManager().AddRPC( "ESZ_Scripts", "CONFIGREQUEST", this, SingeplayerExecutionType.Both );
			
	}

	override void OnMissionStart()
	{
		super.OnMissionStart();
		
		Print("[MaiarsExtractionSafezones] Sucessfully Sent config request to server!");
		GetRPCManager().SendRPC("ESZ_Scripts", "CONFIGREQUEST",new Param1< Maiar_ExtractionSafezoneConfigManager >( NULL ), true, NULL);
		//Sends the server a request to get the config.
	}

	/* RPC HANDLING OF CLIENT */ 
	void CONFIGREQUEST(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target) {

			Param1 < Maiar_ExtractionSafezoneConfigManager > data;
        	if ( !ctx.Read( data ) ) return;
			g_ClientMaiarsExtractionSafezonesConfig = data.param1; //Update our reference in Gamemodule.
			Print("[MaiarsExtractionSafezones] Sucessfully recieved config from server!");
			
	}
}