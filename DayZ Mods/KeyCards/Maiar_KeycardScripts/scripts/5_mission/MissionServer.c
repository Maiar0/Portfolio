modded class MissionServer
{
	protected ref Maiar_MaiarsKeyCardsConfigManager m_CurrentsettingsKeyCardDoors;
	
	override void OnInit()
	{
		super.OnInit();
		if(!m_CurrentsettingsKeyCardDoors)
			m_CurrentsettingsKeyCardDoors = GetMaiarsKeyCardConfig();//Server creates default config for the mod on the startup
		if(m_CurrentsettingsKeyCardDoors)
			Print("[MaiarsKeyCard] Config Sucessfully loaded!");
		else
			Print("[MaiarsKeyCard] Internal Serverconfig Load failed!");
		
		GetRPCManager().AddRPC( "KD_Scripts", "CLIENTCONFIGREQUEST", this, SingeplayerExecutionType.Both );
		
		SpawnKeyDoors();
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(DeleteKeyDoorChests,2000,false);
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(SpawnLootChestPlaceholder,5000,false);
	}
		
		/* RPC HANDLING SERVERSIDE */
	void CLIENTCONFIGREQUEST(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target) 
	{

		if(type == CallType.Server) {
			GetRPCManager().SendRPC("KD_Scripts", "CONFIGRESPONSE", new Param1< ref Maiar_MaiarsKeyCardsConfigManager >( m_CurrentsettingsKeyCardDoors ), true, sender);
			Print("[MaiarsKeyCard] -> Sucessfully sent: " + sender.GetName() + " [MaiarsKeyCard] Config!");
		}
	}
	
	protected void SpawnKeyDoors()
	{
		for(int i = 0; i < m_CurrentsettingsKeyCardDoors.Doors.Count(); i++)
        {
            local vector pos = m_CurrentsettingsKeyCardDoors.Doors.Get(i).GetDoorPosition();
            local vector Ori = m_CurrentsettingsKeyCardDoors.Doors.Get(i).GetDoorOrientation();
            string ObjName = m_CurrentsettingsKeyCardDoors.Doors.Get(i).GetDoorsName();
			//Print("[MaiarsKeyCard] -> Trying to spawn KeyDoor: " + ObjName + " on: " + pos + " Ori " + Ori);
            if(!pos || !ObjName)
                continue;
            
            EntityAI Door = EntityAI.Cast(GetGame().CreateObject(ObjName, pos));
			Object Obj = Door;
            Door.SetPosition(pos);
            Door.SetOrientation(Ori);
			Print("[MaiarsKeyCard] -> Sucesfully spawned door: " + ObjName + " on: " + pos);
			

        }
	}
	
	protected void SpawnLootChestPlaceholder()
	{
		for(int i = 0; i < m_CurrentsettingsKeyCardDoors.Doors.Count(); i++)
        {
			
			int Spawnmethod = m_CurrentsettingsKeyCardDoors.LootMethod;
			if(Spawnmethod != 0 && m_CurrentsettingsKeyCardDoors.ActivateLootCrates )
			{
				vector LootChestPosition = m_CurrentsettingsKeyCardDoors.Doors.Get(i).GetLootSpawnLocation();
				
				EntityAI LootContainer = ItemBase.Cast( GetGame().CreateObject("Maiar_KeyCardLootBox" , LootChestPosition));				
					
				Print("[MaiarsKeyCard] -> Sucesfully spawned Loot Chest: " + LootChestPosition);
			
			}
        }
	}
	
	//Must Run before Loot placeholder spawns
	protected void DeleteKeyDoorChests()
	{
		for(int i = 0; i < m_CurrentsettingsKeyCardDoors.Doors.Count(); i++)
        {
            local vector pos = m_CurrentsettingsKeyCardDoors.Doors.Get(i).GetDoorPosition();
			
			array<Object> objects = new array<Object>;
			array<CargoBase> proxyCargos = new array<CargoBase> ;
			GetGame().GetObjectsAtPosition( pos, 20, objects, proxyCargos );
			for ( int c = 0; c < objects.Count(); ++c )
			{
				//Print( "[Maiars Keycards] " + objects[c] + "Result " + objects[c].IsInherited( Maiar_KeyCardLootBox ) );
				if ( objects[c].IsInherited( Maiar_KeyCardLootBox ) )
				{
					string type = objects[c].GetType();
					vector posoldchest = objects[c].GetPosition();
					//Print("[Maiars Keycards] Found Loot Chest" + posoldchest + "typ = " + type );
					GetGame().ObjectDelete(objects[c]);
				}
			}
			
		}
	}
	
	
}
