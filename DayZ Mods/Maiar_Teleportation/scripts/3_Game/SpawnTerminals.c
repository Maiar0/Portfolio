class Maiar_SpawnTerminals
{
	static void SpawnTerminals()
	{
		SpawnObject( "Maiar_Teleportation_Static_base" ,  GetTeleportTerminalConfig().Terminal01_Position , GetTeleportTerminalConfig().Terminal01_Orientation );
		SpawnObject( "Maiar_Teleportation_Static_base" ,  GetTeleportTerminalConfig().Terminal02_Position , GetTeleportTerminalConfig().Terminal02_Orientation );
	}
	static void SpawnObject(string type, vector position, vector orientation)
	{
		
		Object obj = GetGame().CreateObjectEx(type, position, ECE_SETUP | ECE_UPDATEPATHGRAPH | ECE_CREATEPHYSICS);
		obj.SetPosition(position);
		obj.SetOrientation(orientation);
		obj.SetOrientation(obj.GetOrientation());
		obj.SetFlags(EntityFlags.STATIC, false);
		obj.Update();
		obj.SetAffectPathgraph(true, false);
		if (obj.CanAffectPathgraph()) GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(GetGame().UpdatePathgraphRegionByObject, 100, false, obj);
	}
}