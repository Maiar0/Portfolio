
modded class MissionServer
{
	protected ref Maiar_ExtractionSafezoneConfigManager m_CurrentsettingsExtractionSafeZone;
	
	override void OnInit()
	{
		super.OnInit();
		if(!m_CurrentsettingsExtractionSafeZone)
			m_CurrentsettingsExtractionSafeZone = GetMaiarsExtractionSafezonesConfig();//Server creates default config for the mod on the startup
		if(m_CurrentsettingsExtractionSafeZone)
			Print("[MaiarsExtractionSafezones] Config Sucessfully loaded!");
		else
			Print("[MaiarsExtractionSafezones] Internal Serverconfig Load failed!");
		
		GetRPCManager().AddRPC( "ESZ_Scripts", "CONFIGREQUEST", this, SingeplayerExecutionType.Both );
		
		SpawnExtractionMachines();
		SpawnSafezoneMachines();
	}
		
		/* RPC HANDLING SERVERSIDE */
	void CONFIGREQUEST(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target) 
	{

		PlayerIdentity RequestedBy = PlayerIdentity.Cast(sender);
		if (RequestedBy)
		{
			GetRPCManager().SendRPC("ESZ_Scripts", "CONFIGREQUEST", new Param1< ref Maiar_ExtractionSafezoneConfigManager >( GetMaiarsExtractionSafezonesConfig() ), true, RequestedBy);
			
			Print("[MaiarsExtractionSafezones] -> Sucessfully sent: " + sender.GetName() + " [MaiarsExtractionSafezones] Config!");
		}
	}
	
	protected void SpawnExtractionMachines()
	{
		for(int i = 0; i < m_CurrentsettingsExtractionSafeZone.ExtractionMachine.Count(); i++)
        {
            local vector pos = m_CurrentsettingsExtractionSafeZone.ExtractionMachine.Get(i).GetPositions();
            local vector Ori = m_CurrentsettingsExtractionSafeZone.ExtractionMachine.Get(i).GetOrientation();
            string ObjName = m_CurrentsettingsExtractionSafeZone.ExtractionMachine.Get(i).GetName();
			//Print("[MaiarsExtractionSafezones] -> 
            if(!pos || !ObjName)
                continue;
            
            EntityAI Door = EntityAI.Cast(GetGame().CreateObject(ObjName, pos));
			Object Obj = Door;
            Door.SetPosition(pos);
            Door.SetOrientation(Ori);
			Print("[MaiarsExtractionSafezones] -> Sucesfully spawned ExtractionMachine: " + ObjName + " on: " + pos);
			

        }
	}
	
	protected void SpawnSafezoneMachines()
	{
		for(int i = 0; i < m_CurrentsettingsExtractionSafeZone.SafezoneMachine.Count(); i++)
        {
            local vector pos = m_CurrentsettingsExtractionSafeZone.SafezoneMachine.Get(i).GetPositions();
            local vector Ori = m_CurrentsettingsExtractionSafeZone.SafezoneMachine.Get(i).GetOrientation();
            string ObjName = "Maiar_SafezoneExtraction";//m_CurrentsettingsExtractionSafeZone.SafezoneExtractors.Get(i).GetExtractionsName();
			//Print("[MaiarsExtractionSafezones] -> 
            if(!pos || !ObjName)
                continue;
            
            EntityAI Door = EntityAI.Cast(GetGame().CreateObject(ObjName, pos));
			Object Obj = Door;
            Door.SetPosition(pos);
            Door.SetOrientation(Ori);
			Print("[MaiarsExtractionSafezones] -> Sucesfully spawned SafezoneMachine: " + ObjName + " on: " + pos);
			

        }
	}
	
}
