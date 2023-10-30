modded class MissionServer
{
	protected ref Maiar_TeleportTerminalsConfigManager m_Currentsettings;
	
	override void OnInit()
	{
		super.OnInit();
		if(!m_Currentsettings)
			m_Currentsettings = GetTeleportTerminalConfig();//Server creates default config for the mod on the startup!
		if(m_Currentsettings)
			Print("[TeleportTerminal] Config Sucessfully loaded!");
		else
			Print("[TeleportTerminal] Internal Serverconfig Load failed!");
		
		GetRPCManager().AddRPC( "TT_Scripts", "CLIENTCONFIGREQUEST", this, SingeplayerExecutionType.Both );
		
		Maiar_SpawnTerminals.SpawnTerminals();
	}
		
		/* RPC HANDLING SERVERSIDE */
	void CLIENTCONFIGREQUEST(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target) 
	{

		if(type == CallType.Server) {
			GetRPCManager().SendRPC("TT_Scripts", "CONFIGRESPONSE", new Param1< ref Maiar_TeleportTerminalsConfigManager >( m_Currentsettings ), true, sender);
			Print("[TeleportTerminal] -> Sucessfully sent: " + sender.GetName() + " [TeleportTerminal] Config!");
		}
	}
}
