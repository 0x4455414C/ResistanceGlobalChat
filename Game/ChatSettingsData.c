class ChatSettingsData {
	
    ref SchanaColour ColourDirect;
    ref SchanaColour ColourDirectPlayer;
   	ref SchanaColour ColourGlobal;
    ref SchanaColour ColourGlobalPlayer;
    ref SchanaColour ColourServer;
    ref SchanaColour ColourAlert;
    
    // ref array<ref RoleSettingsData> roles = new RoleSettingsData("Staff", playerIds, defaultColourAlert);
    // ref array<ref RoleSettingsData> m_Roles;
    protected ref array<RoleSettingsData> Roles;

    void ChatSettingsData(vector colourDirect = "255 255 255" , vector colourGlobal = "1 255 238", vector colourServer = "255 89 1", vector colourAlert = "255 1 1")
	{
		ColourDirect       = new SchanaColour(colourDirect);
		ColourDirectPlayer = new SchanaColour(colourDirect);
		ColourGlobal       = new SchanaColour(colourGlobal);
		ColourGlobalPlayer = new SchanaColour(colourGlobal);
		ColourServer       = new SchanaColour(colourServer);
		ColourAlert        = new SchanaColour(colourAlert);

        array<string> playerIds = {
            "76561197997664497"
        };

        Roles = new array<RoleSettingsData>;
        Roles.Insert(new RoleSettingsData("Staff", playerIds, ColourAlert))
    }

    ref array<RoleSettingsData> getRoles(){
        return Roles;
    }
}   
