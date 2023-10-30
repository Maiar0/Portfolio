class Maiar_ExtractionSafezoneConfigManager
{
	private static const string configPath = "$profile:\\MaiarsExtractionSafezone\\MaiarsExtractionSafezone.json";
	private static const string configRoot = "$profile:\\MaiarsExtractionSafezone\\";
	
	int NumberofExtractionMachines = 3;
	int RangeSafeExtraction = 1000;
	ref array<ref SafezoneMachines> SafezoneMachine;
	ref array<ref ExtractionMachines> ExtractionMachine;
	ref array<ref SafezonePositions> SafezonePosition;
	
	void Maiar_ExtractionSafezoneConfigManager() 
	{
		ExtractionMachine = new ref array<ref ExtractionMachines>();
		SafezoneMachine = new ref array<ref SafezoneMachines>();
		SafezonePosition = new ref array<ref SafezonePositions>();
	};
	
	void LoadDefaultSettings() 
	{
		
		ExtractionMachine.Insert(new ref ExtractionMachines("Maiar_ExtractionPoint", "4783.703125 339.174866 10398.168945", "150 0 0"));
		ExtractionMachine.Insert(new ref ExtractionMachines("Maiar_ExtractionPoint", "4779.727051 339.237091 10395.559570", "150 0 0"));
		ExtractionMachine.Insert(new ref ExtractionMachines("Maiar_ExtractionPoint", "4774.583008 339.237091 10393.041992", "150 0 0"));
		
		SafezoneMachine.Insert(new ref SafezoneMachines("Maiar_SafezoneExtraction", "4785.153320 339.174896 10376.475586", "150 0 0"));
		SafezonePosition.Insert(new ref SafezonePositions("4785.153320 339.174896 10376.475586"));
		SaveConfig();
	};
	
	protected void SaveConfig()
	{
		if (!FileExist(configRoot))
			MakeDirectory(configRoot);
		JsonFileLoader<Maiar_ExtractionSafezoneConfigManager>.JsonSaveFile(configPath, this);
	};
	
	static ref Maiar_ExtractionSafezoneConfigManager LoadConfig() 
	{
        ref Maiar_ExtractionSafezoneConfigManager settings = new Maiar_ExtractionSafezoneConfigManager();
		
        if(!FileExist(configRoot))
            MakeDirectory(configRoot);
		
        if(FileExist(configPath))
        {
            JsonFileLoader<Maiar_ExtractionSafezoneConfigManager>.JsonLoadFile(configPath, settings);
        }
        else
        {
            settings.LoadDefaultSettings();
        }
        return settings;
    }
}

// Global Getter for config
static ref Maiar_ExtractionSafezoneConfigManager g_MaiarsExtractionSafezonesConfig;
static ref Maiar_ExtractionSafezoneConfigManager g_ClientMaiarsExtractionSafezonesConfig;
static ref Maiar_ExtractionSafezoneConfigManager GetMaiarsExtractionSafezonesConfig()
{
    if (g_Game.IsServer() && !g_MaiarsExtractionSafezonesConfig) 
    {
        g_MaiarsExtractionSafezonesConfig = Maiar_ExtractionSafezoneConfigManager.LoadConfig();
    }
	else if(g_Game.IsClient())
	{
		return g_ClientMaiarsExtractionSafezonesConfig; 
	}
    return g_MaiarsExtractionSafezonesConfig;
};
