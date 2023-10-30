class Maiar_MaiarsKeyCardsConfigManager
{
	private static const string configPath = "$profile:\\MaiarsKeyCards\\MaiarsKeyCards.json";
	private static const string configRoot = "$profile:\\MaiarsKeyCards\\";
	
	bool ShouldAlarmPlay;
	bool ShouldDoorAutoClose;
	int TimeToAutoClose = 45;
	bool ActivateLootCrates;
	int LootMethod;
	ref array<ref DoorPosition> Doors;
	ref array<ref KeyCardDoorLoot> Tier1_Loot;
	ref array<ref KeyCardDoorLoot> Tier2_Loot;
	ref array<ref KeyCardDoorLoot> Tier3_Loot;
	ref array<ref KeyCardDoorLoot> Tier4_Loot;
	ref array<ref KeyCardDoorLoot> Tier5_Loot;
	
	void Maiar_MaiarsKeyCardsConfigManager() 
	{
		Doors = new ref array<ref DoorPosition>();
		Tier1_Loot = new ref array<ref KeyCardDoorLoot>();
		Tier2_Loot = new ref array<ref KeyCardDoorLoot>();
		Tier3_Loot = new ref array<ref KeyCardDoorLoot>();
		Tier4_Loot = new ref array<ref KeyCardDoorLoot>();
		Tier5_Loot = new ref array<ref KeyCardDoorLoot>();
	};
	
	void LoadDefaultSettings() 
	{
		ShouldAlarmPlay = true;
		ShouldDoorAutoClose = false;
		TimeToAutoClose = 45;
		ActivateLootCrates = false;
		LootMethod = 0;
		Doors.Insert(new ref DoorPosition("land_Vaultdoor1", "4801.003906 339.174927 10369.405273", "150 0 0", "4801.003906 339.174927 10369.405273", "150 0 0"));
		Doors.Insert(new ref DoorPosition("land_Vaultdoor2", "4799.757813 339.174927 10371.808594", "150 0 0", "4799.757813 339.174927 10371.808594", "150 0 0"));
		Doors.Insert(new ref DoorPosition("land_Vaultdoor3", "4798.347656 339.174927 10374.032227", "150 0 0", "4798.347656 339.174927 10374.032227", "150 0 0"));
		Doors.Insert(new ref DoorPosition("land_Vaultdoor4", "4796.722656 339.174927 10376.812500", "150 0 0", "4796.722656 339.174927 10376.812500", "150 0 0"));
		Doors.Insert(new ref DoorPosition("land_Vaultdoor5", "4795.405762 339.174927 10379.481445", "150 0 0", "4795.405762 339.174927 10379.481445", "150 0 0"));
		Tier1_Loot.Insert(new ref KeyCardDoorLoot("Apple"));
		Tier2_Loot.Insert(new ref KeyCardDoorLoot("Apple"));
		Tier3_Loot.Insert(new ref KeyCardDoorLoot("Apple"));
		Tier4_Loot.Insert(new ref KeyCardDoorLoot("Apple"));
		Tier5_Loot.Insert(new ref KeyCardDoorLoot("Apple"));
		
		SaveConfig();
	};
	
	protected void SaveConfig()
	{
		if (!FileExist(configRoot))
			MakeDirectory(configRoot);
		JsonFileLoader<Maiar_MaiarsKeyCardsConfigManager>.JsonSaveFile(configPath, this);
	};
	
	static ref Maiar_MaiarsKeyCardsConfigManager LoadConfig() 
	{
        ref Maiar_MaiarsKeyCardsConfigManager settings = new Maiar_MaiarsKeyCardsConfigManager();
		
        if(!FileExist(configRoot))
            MakeDirectory(configRoot);
		
        if(FileExist(configPath))
        {
            JsonFileLoader<Maiar_MaiarsKeyCardsConfigManager>.JsonLoadFile(configPath, settings);
        }
        else
        {
            settings.LoadDefaultSettings();
        }
        return settings;
    }
}

// Global Getter for config
static ref Maiar_MaiarsKeyCardsConfigManager g_MaiarsKeyCardConfig;
static ref Maiar_MaiarsKeyCardsConfigManager g_ClientMaiarsKeyCardConfig;
static ref Maiar_MaiarsKeyCardsConfigManager GetMaiarsKeyCardConfig()
{
    if (g_Game.IsServer() && !g_MaiarsKeyCardConfig) 
    {
        g_MaiarsKeyCardConfig = Maiar_MaiarsKeyCardsConfigManager.LoadConfig();
    }
	else if(g_Game.IsClient())
	{
		return g_ClientMaiarsKeyCardConfig; 
	}
    return g_MaiarsKeyCardConfig;
};
