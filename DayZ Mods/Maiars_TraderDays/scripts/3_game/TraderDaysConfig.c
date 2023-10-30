class Maiar_TraderDays
{
	
	int g_Monday;
	int g_Tuesday;
	int g_Wednesday;
	int g_Thursday;
	int g_Friday;
	int g_Saturday;
	int g_Sunday;
	
}

class TraderDaysGlobals
{
	private static ref Maiar_TraderDays m_Globals = NULL;
	private static const int MAX_CONFIG_LINES = 500;
	private static const string configPath = "$profile:\\TraderDaysDrJones\\TraderDaysDrJones.json";
	private static const string configRoot = "$profile:\\TraderDaysDrJones\\";
	
	static Maiar_TraderDays Get()
	{
		if (m_Globals == NULL)
		{
			Set();
		}
		return m_Globals;
	}

	static void Set()
	{
		m_Globals = LoadConfig();
	}

	private static Maiar_TraderDays LoadConfig()
	{
		Maiar_TraderDays config = new Maiar_TraderDays;

		if (!FileExist(configPath))
        {
            Print("[TraderDaysDrJones] 'TraderDaysDrJones' does not exist, creating default config");
            CreateDefaultConfig(config);
        }

		JsonFileLoader<Maiar_TraderDays>.JsonLoadFile(configPath, config);
		Print("[TraderDaysDrJones] 'TraderDaysDrJones' found, loaded config");
		return config;
	}

	private static void CreateDefaultConfig(Maiar_TraderDays config)
	{
		//config.g_TraderDays = TraderAvailble.IsTraderAvailble();	//On/Off for traders
		config.g_Monday = 1;
		config.g_Tuesday = 1;
		config.g_Wednesday = 1;
		config.g_Thursday = 1;
		config.g_Friday = 1;
		config.g_Saturday = 1;
		config.g_Sunday = 1;
		
		
        if (!FileExist(configRoot))
        {
            Print("[TraderDaysDrJones] '" + configRoot + "' does not exist, creating directory");
            MakeDirectory(configRoot);
        }
        JsonFileLoader<Maiar_TraderDays>.JsonSaveFile(configPath, config);
	}
	
}