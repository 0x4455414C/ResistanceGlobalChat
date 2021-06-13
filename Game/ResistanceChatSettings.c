ref ResistanceChatSettings g_ResistanceChatSettings;

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

    //* Mod Configs
	
    // void ResistanceChatSettings(){
    //     if (!g_ResistanceChatSettings) {
    //         g_ResistanceChatSettings = new ref ResistanceChatSettings;
    //     }
    //     loadConfig();
    // }

    static ref ResistanceChatSettings ResistanceChatSettings () {
        if (!g_ResistanceChatSettings) {
            g_ResistanceChatSettings = new ref ResistanceChatSettings;
            
            if ( GetGame ().IsServer ()){
                g_ResistanceChatSettings.loadConfig();
            }
        }
        return g_ResistanceChatSettings;
    }

    protected void loadConfig(){
        if (!FileExist(fullPath)){
            MakeDirectory(profilePath + dir + "/");
        }

        m_ChatSettingsData = new ChatSettingsData();
        if (FileExist(fullPath)){
            JsonFileLoader< ChatSettingsData>.JsonLoadFile(profilePath + dir + "/" + file, m_ChatSettingsData);
        } else {
            makeConfig();
        }
    }

    protected void makeConfig(){
        // ref array<ref string> playerIds;
        // playerIds.Insert("76561197997664497");
        // ref array<ref RoleSettingsData> roles = new RoleSettingsData("Staff", playerIds, defaultColourAlert);
        m_ChatSettingsData = new ChatSettingsData(defaultColourDirect, defaultColourGlobal, defaultColourServer, defaultColourAlert);
        JsonFileLoader<ChatSettingsData>.JsonSaveFile(profilePath + dir + "/" + file, m_ChatSettingsData);
    }

    ChatSettingsData getConfig(){
        if (!m_ChatSettingsData){
            loadConfig();
        }
        return m_ChatSettingsData;
    }

    //* Getters
    int GetColourDirect () {
        return ColourDirect.Get ();
    }
	
    int GetColourDirectPlayer () {
        return ColourDirectPlayer.Get ();
    }


    int GetColourGlobal () {
        return ColourGlobal.Get ();
    }
	
    int GetColourGlobalPlayer () {
        return ColourGlobalPlayer.Get ();
    }

    int GetColourServer () {
        return ColourServer.Get ();
    }

    int GetColourAlert () {
        return ColourAlert.Get ();
    }

    array<RoleSettingsData> GetRoles(){
        return m_ChatSettingsData.getRoles();
    }

    string GetTest () {
        return "Hello World";
    }

    //* Debug

    void Debug (){
		Print ("[SchanaChat] ColourDirect");
		Print (ColourDirect.Debug ());
		Print ("[SchanaChat] ColourDirectPlayer");
		Print (ColourDirectPlayer.Debug ());
		Print ("[SchanaChat] ColourGlobal");
		Print (ColourGlobal.Debug ());
		Print ("[SchanaChat] ColourGlobalPlayer");
		Print (ColourGlobalPlayer.Debug ());
		Print ("[SchanaChat] ColourServer");
		Print (ColourServer.Debug ());
		Print ("[SchanaChat] ColourAlert");
		Print (ColourAlert.Debug ());
	}
}
