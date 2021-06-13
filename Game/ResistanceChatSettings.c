class ResistanceChatSettings {
	
    protected static string profilePath = "$profile:";
    protected static string dir = "ResistanceGlobalChat";
    protected static string file = "chat-settings.json";
    protected static string fullPath = profilePath + dir + "/" + file;

    protected static ref ChatSettingsData m_ChatSettingsData;

    static vector defaultColourDirect    = "255 255 255"; // white
    static vector defaultColourGlobal    = "1 255 238"; // amber 300
    static vector defaultColourServer    = "255 89 1"; // light blue 300
    static vector defaultColourAlert     = "255 1 1"; // deep orange 300

    ref SchanaColour ColourDirect        = new SchanaColour (defaultColourDirect);
    ref SchanaColour ColourDirectPlayer  = new SchanaColour (defaultColourDirect);
   	ref SchanaColour ColourGlobal        = new SchanaColour (defaultColourGlobal);
    ref SchanaColour ColourGlobalPlayer  = new SchanaColour (defaultColourGlobal);
    ref SchanaColour ColourServer        = new SchanaColour (defaultColourServer);
    ref SchanaColour ColourAlert         = new SchanaColour (defaultColourAlert);
	
    void ResistanceChatSettings(){
        loadConfig();
    }

    protected void loadConfig(){
        if (!FileExist(fullPath)){
            MakeDirectory(profilePath + dir + "/");
        }

        m_ChatSettingsData = new ChatSettingsData();
    }

    protected ChatSettingsData getConfig(){
        if (!m_ChatSettingsData){
            loadConfig();
        }
        return m_ChatSettingsData;
    }

    protected void makeConfig(){
        ref array<ref string> playerIds;
        playerIds.Insert("76561197997664497");
        // ref array<ref RoleSettingsData> roles = new RoleSettingsData("Staff", playerIds, defaultColourAlert);
        m_ChatSettingsData = new ChatSettingsData(defaultColourDirect, defaultColourGlobal, defaultColourServer, defaultColourAlert);
        JsonFileLoader<ChatSettingsData>.JsonSaveFile(profilePath + dir + "/" + file, m_ChatSettingsData);
    }
}
