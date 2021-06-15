ref ResistanceChatSettings g_ResistanceChatSettings;
static ref ResistanceChatSettings GetResistanceChatSettings () {
    if (!g_ResistanceChatSettings) {
        g_ResistanceChatSettings = new ref ResistanceChatSettings;
        
        if ( GetGame ().IsServer ()){
            g_ResistanceChatSettings.loadConfig ();
        }
    }
    return g_ResistanceChatSettings;
}

class ResistanceChatSettings {
	
    protected static string profilePath = "$profile:";
    protected static string dir = "ResistanceGlobalChat";
    protected static string file = "chat-settings.json";
    protected static string fullPath = profilePath + dir + "/" + file;

    static vector defaultColourDirect        = "255 255 255";   // white
    static vector defaultColourGlobal        = "1 255 238";     // lt blue
    static vector defaultColourServer        = "255 89 1";      // orange
    static vector defaultColourAlert         = "163 5 0";       // red
    static ref array<string> defaultIds      = { "76561197997664497" };
    static ref RoleSettingsData defaultRole  = new RoleSettingsData("Staff", defaultIds, new SchanaColour(defaultColourAlert));

   

    protected ref SchanaColour ColourDirect        = new SchanaColour (defaultColourDirect);
    protected ref SchanaColour ColourDirectPlayer  = new SchanaColour (defaultColourDirect);
   	protected ref SchanaColour ColourGlobal        = new SchanaColour (defaultColourGlobal);
    protected ref SchanaColour ColourGlobalPlayer  = new SchanaColour (defaultColourGlobal);
    protected ref SchanaColour ColourServer        = new SchanaColour (defaultColourServer);
    protected ref SchanaColour ColourAlert         = new SchanaColour (defaultColourAlert);
    protected ref array<RoleSettingsData> Roles    = new array<RoleSettingsData>;

    // TODO GET ROLE COLOUR TO CLIENT FOR WIDGET COLOUR WITHOUT STORING IN CONFIG

    //* Mod Configs */
    void loadConfig(){
        if (FileExist(fullPath)){
            JsonFileLoader<ResistanceChatSettings>.JsonLoadFile(profilePath + dir + "/" + file, this);
        } else {
            makeConfig();
        }
    }

    protected void makeConfig(){
        if (!FileExist(fullPath)){
            MakeDirectory(profilePath + dir + "/");
        }

        // Roles.Insert(new RoleSettingsData("Staff", defaultIds, ColourAlert));
        JsonFileLoader<ResistanceChatSettings>.JsonSaveFile(profilePath + dir + "/" + file, this);
    }

    void SetRoles(){
        array<string> playerIds = {
            "76561197997664497"
        };

        Roles.Insert(new RoleSettingsData("Staff", playerIds, ColourAlert));
    }

    //* Getters */
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
        return Roles;
    }

    RoleSettingsData FindRoleByName(string name){
        for (int i=0; i<Roles.Count();i++){
            if (Roles[i].GetName() == name){
                return Roles[i];
            }
        }
        return null;
    }

    string GetTest () {
        return "Hello World";
    }

    //* Debug */

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
