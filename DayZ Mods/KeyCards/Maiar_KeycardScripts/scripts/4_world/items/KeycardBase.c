class land_Vaultdoor extends BuildingSuper
{
	
	protected ref Timer m_CloseTimer;
	protected ref Timer m_DeleteTimer;
	protected ref Maiar_MaiarsKeyCardsConfigManager m_CurrentsettingsKeyCardDoors;
	
	int AutoCloseTime = GetMaiarsKeyCardConfig().TimeToAutoClose *60;
	
	
	void Land_Vaultdoor()
	{
		
	}
	
	void AutoCloseDoor(Object obj ,int index)
    {
		m_CloseTimer = new Timer(CALL_CATEGORY_SYSTEM);
		//Print(" Attempting to close doorindex = " + index  + " Object " + obj)
        m_CloseTimer.Run(AutoCloseTime, obj, "CloseDoor", new Param1<int>(index));
    }
	
	//Not used needs work
	void DeleteLootchest(EntityAI LootChest)
	{
		m_DeleteTimer = new Timer(CALL_CATEGORY_SYSTEM);
		Print(" Attempting to DeleteLoot = " + LootChest + " AutoCloseTime " +AutoCloseTime	);
       m_DeleteTimer.Run(AutoCloseTime, LootChest, "Delete"/*, new Param1<EntityAI>(LootChest)*/);
		
		//GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(GetGame().ObjectDelete,AutoCloseTime,false, new Param1<EntityAI>(LootChest))
	}
	
	bool CheckAccess(Object obj, ItemBase item)
	{
		string m_ItemInHands = item.ConfigGetString("KeyTier");
		string m_Target = obj.GetType();
		if(m_Target == m_ItemInHands)
			return true;
		return false; 
	}
	
	void PrepareLoot(Object obj)
	{
		land_Vaultdoor VD;
		EntityAI LootContainer;
		m_CurrentsettingsKeyCardDoors = GetMaiarsKeyCardConfig();
		
		Class.CastTo(VD, obj);
		string LootTier = VD.GetTier();
		vector location;
		int Spawnmethod = m_CurrentsettingsKeyCardDoors.LootMethod;
		if(Spawnmethod == 0)
		{
			location = DoorLocation(obj);
		}
		if(Spawnmethod == 1)
		{
			location = FindPreviousLootChest(obj);
		}
		LootContainer = ItemBase.Cast( GetGame().CreateObject("Maiar_KeyCardLootBox" , location));
		
		//Work on loot spawning
		SpawnLootinChest(LootTier, LootContainer);
		
	}
	
	vector DoorLocation(Object obj)
	{
		
		vector location;
		location = obj.GetPosition();
		
		return location;
	}
	
	vector FindPreviousLootChest(Object obj)
	{
		array<Object> objects = new array<Object>;
		array<CargoBase> proxyCargos = new array<CargoBase> ;
		GetGame().GetObjectsAtPosition( obj.GetPosition(), 15, objects, proxyCargos );
		
		for ( int i = 0; i < objects.Count(); ++i )
		{
			//Print( "[Maiars Keycards] " + objects[i] );
			if ( objects[i].IsInherited( Maiar_KeyCardLootBox ) )
			{
				
				vector pos = objects[i].GetPosition();
				Print("[Maiars Keycards] Found Loot Chest" + pos + objects[i] );
				GetGame().ObjectDelete(objects[i]);
				return pos;
			}
		}
		return DoorLocation(obj);
	}
	string GetTier()
	{
		return "";
	}
	
	//Spawning loot needs alot of work
	void SpawnLootinChest(string LootTier, EntityAI Container)
	{
		int i;
		EntityAI Loot;
		if(LootTier == "Tier1_Loot") 
		{ 
			for(i = 0; i < m_CurrentsettingsKeyCardDoors.Tier1_Loot.Count(); i++)
			{
			Loot = Container.GetInventory().CreateInInventory(m_CurrentsettingsKeyCardDoors.Tier1_Loot.Get(i).GetLootItem());
			}
		}
		if(LootTier == "Tier2_Loot") 
		{ 
			for(i = 0; i < m_CurrentsettingsKeyCardDoors.Tier2_Loot.Count(); i++)
			{
			Loot = Container.GetInventory().CreateInInventory(m_CurrentsettingsKeyCardDoors.Tier2_Loot.Get(i).GetLootItem());
			}
		}
		if(LootTier == "Tier3_Loot") 
		{ 
			for(i = 0; i < m_CurrentsettingsKeyCardDoors.Tier3_Loot.Count(); i++)
			{
			Loot = Container.GetInventory().CreateInInventory(m_CurrentsettingsKeyCardDoors.Tier3_Loot.Get(i).GetLootItem());
			}
		}
		if(LootTier == "Tier4_Loot") 
		{ 
			for(i = 0; i < m_CurrentsettingsKeyCardDoors.Tier4_Loot.Count(); i++)
			{
			Loot = Container.GetInventory().CreateInInventory(m_CurrentsettingsKeyCardDoors.Tier4_Loot.Get(i).GetLootItem());
			}
		}
		if(LootTier == "Tier5_Loot") 
		{ 
			for(i = 0; i < m_CurrentsettingsKeyCardDoors.Tier5_Loot.Count(); i++)
			{
			Loot = Container.GetInventory().CreateInInventory(m_CurrentsettingsKeyCardDoors.Tier5_Loot.Get(i).GetLootItem());
			}
		}
	}
	
};
class land_Vaultdoor1 extends land_Vaultdoor
{
	override string GetTier()
	{
		return "Tier1_Loot";
	}
};
class land_Vaultdoor2 extends land_Vaultdoor
{
	override string GetTier()
	{
		return "Tier2_Loot";
	}
};
class land_Vaultdoor3 extends land_Vaultdoor
{
	override string GetTier()
	{
		return "Tier3_Loot";
	}
};
class land_Vaultdoor4 extends land_Vaultdoor
{
	override string GetTier()
	{
		return "Tier4_Loot";
	}
};
class land_Vaultdoor5 extends land_Vaultdoor
{
	override string GetTier()
	{
		return "Tier5_Loot";
	}
};
class Maiar_keyCard_base extends ItemBase
{
	override void SetActions()
	{
		super.SetActions();		
		AddAction(Maiar_ActionOpenKeyDoor);
	}
};
class Maiar_KeyCardLootBox extends Container_Base
{
	
	
	void Maiar_KeyCardLootBox()
	{
		
	}
	
	override bool CanPutIntoHands( EntityAI parent )
	{
		return false;
	}

	override bool CanPutInCargo( EntityAI parent )
	{
		return false;
	}
	
	
}