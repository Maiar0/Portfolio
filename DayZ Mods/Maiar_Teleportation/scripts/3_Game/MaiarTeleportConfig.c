class Maiar_TeleportTerminalsConfigManager
{
	//private static ref Maiar_TeleportTerminals m_Globals = NULL;
	//private static const int MAX_CONFIG_LINES = 500;
	private static const string configPath = "$profile:\\TeleportTerminals\\TeleportTerminals.json";
	private static const string configRoot = "$profile:\\TeleportTerminals\\";
	
	string g_ticket01_name;
	vector g_ticket01;
	string g_ticket02_name;
	vector g_ticket02;
	string g_ticket03_name;
	vector g_ticket03;
	string g_ticket04_name;
	vector g_ticket04;
	string g_ticket05_name;
	vector g_ticket05;
	
	string g_token01_name;
	vector g_token01;
	string g_token02_name;
	vector g_token02;
	string g_token03_name;
	vector g_token03;
	string g_token04_name;
	vector g_token04;
	string g_token05_name;
	vector g_token05;
	
	vector Terminal01_Position;
	vector Terminal01_Orientation;
	
	vector Terminal02_Position;
	vector Terminal02_Orientation;
	
	void Maiar_TeleportTerminalsConfigManager() {};
	
	void LoadDefaultSettings() 
	{
		
		g_ticket01_name = "Green Mountain";
		g_ticket01 = "3722.648438 402.012390 5996.782715";
		g_ticket02_name = "Klen";
		g_ticket02 = "11402.566406 327.005127 11370.631836";
		g_ticket03_name = "NWAF";
		g_ticket03 = "4784.779785 339.174866 10397.754883";
		g_ticket04_name = "Tisy";
		g_ticket04 = "1846.568115 427.308594 13611.927734";
		g_ticket05_name = "Krona Castle";
		g_ticket05 = "1533.677979 297.354858 9114.691406";
		
		g_token01_name = "Green Mountain";
		g_token01 = "3722.648438 402.012390 5996.782715";
		g_token02_name = "Klen";
		g_token02 = "11402.566406 327.005127 11370.631836";
		g_token03_name = "NWAF";
		g_token03 = "4784.779785 339.174866 10397.754883";
		g_token04_name = "Tisy";
		g_token04 = "1846.568115 427.308594 13611.927734";
		g_token05_name = "Krona Castle";
		g_token05 = "1533.677979 297.354858 9114.691406";
		
		Terminal01_Position = "3707.276611 402.012421 5981.590332";
		Terminal01_Orientation = "0 0 0";
		
		Terminal02_Position = "11482.769531 351.082550 11312.946289";
		Terminal02_Orientation = "0 0 0"

		SaveConfig();
	};
	
	protected void SaveConfig()
	{
		if (!FileExist(configRoot))
			MakeDirectory(configRoot);
		JsonFileLoader<Maiar_TeleportTerminalsConfigManager>.JsonSaveFile(configPath, this);
	};
	
	//Dont use that to load the config!
	static ref Maiar_TeleportTerminalsConfigManager LoadConfig() 
	{
        ref Maiar_TeleportTerminalsConfigManager settings = new Maiar_TeleportTerminalsConfigManager();
		
        if(!FileExist(configRoot))
            MakeDirectory(configRoot);
		
        if(FileExist(configPath))
        {
            JsonFileLoader<Maiar_TeleportTerminalsConfigManager>.JsonLoadFile(configPath, settings);
        }
        else
        {
            settings.LoadDefaultSettings();
        }
        return settings;
    }
}

/* Global Getter for config */
static ref Maiar_TeleportTerminalsConfigManager g_TeleportTerminalConfig;
static ref Maiar_TeleportTerminalsConfigManager g_ClientTeleportTerminalConfig;
static ref Maiar_TeleportTerminalsConfigManager GetTeleportTerminalConfig()
{
    if (g_Game.IsServer() && !g_TeleportTerminalConfig) 
    {
        g_TeleportTerminalConfig = Maiar_TeleportTerminalsConfigManager.LoadConfig();
    }
	else if(g_Game.IsClient())
	{
		return g_ClientTeleportTerminalConfig; //GetsFilled on mission start with an RPC.
	}
    return g_TeleportTerminalConfig;
};

/*class MaiarTeleportGlobals
{
	
	
	static Maiar_TeleportTerminals Get()
	{
		if (m_Globals == NULL)
		{
			Set();
		}
		Print(m_Globals)
		return m_Globals;
	}

	static void Set()
	{
		m_Globals = LoadConfig();
	}

	private static Maiar_TeleportTerminals LoadConfig()
	{
		Maiar_TeleportTerminals config = new Maiar_TeleportTerminals;

		if (!FileExist(configPath))
        {
            Print("[TeleportTerminals] 'TeleportTerminals' does not exist, creating default config");
            CreateDefaultConfig(config);
        }

		JsonFileLoader<Maiar_TeleportTerminals>.JsonLoadFile(configPath, config);
		Print("[TeleportTerminals] 'TeleportTerminals' found, loaded config");
		return config;
	}

	private static void CreateDefaultConfig(Maiar_TeleportTerminals config)
	{
		
		config.g_ticket01_name = "Green Mountain";
		config.g_ticket01 = "3722.648438 402.012390 5996.782715";
		config.g_ticket02_name = "Klen";
		config.g_ticket02 = "11402.566406 327.005127 11370.631836";
		config.g_ticket03_name = "NWAF";
		config.g_ticket03 = "4784.779785 339.174866 10397.754883";
		config.g_ticket04_name = "Tisy";
		config.g_ticket04 = "1846.568115 427.308594 13611.927734";
		config.g_ticket05_name = "Krona Castle";
		config.g_ticket05 = "1533.677979 297.354858 9114.691406";
		
		config.g_token01_name = "Green Mountain";
		config.g_token01 = "3722.648438 402.012390 5996.782715";
		config.g_token02_name = "Klen";
		config.g_token02 = "11402.566406 327.005127 11370.631836";
		config.g_token03_name = "NWAF";
		config.g_token03 = "4784.779785 339.174866 10397.754883";
		config.g_token04_name = "Tisy";
		config.g_token04 = "1846.568115 427.308594 13611.927734";
		config.g_token05_name = "Krona Castle";
		config.g_token05 = "1533.677979 297.354858 9114.691406";
		
		config.Terminal01_Position = "3707.276611 402.012421 5981.590332";
		config.Terminal01_Orientation = "0 0 0";
		
		config.Terminal02_Position = "11482.769531 351.082550 11312.946289";
		config.Terminal02_Orientation = "0 0 0"
		
		
        if (!FileExist(configRoot))
        {
            Print("[TeleportTerminals] '" + configRoot + "' does not exist, creating directory");
            MakeDirectory(configRoot);
        }
        JsonFileLoader<Maiar_TeleportTerminals>.JsonSaveFile(configPath, config);
	}
	
	
}*/