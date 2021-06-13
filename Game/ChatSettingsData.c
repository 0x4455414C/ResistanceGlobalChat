class ChatSettingsData {
	
    ref SchanaColour m_ColourDirect      ;
    ref SchanaColour m_ColourDirectPlayer;
   	ref SchanaColour m_ColourGlobal      ;
    ref SchanaColour m_ColourGlobalPlayer;
    ref SchanaColour m_ColourServer      ;
    ref SchanaColour m_ColourAlert       ;
    
    // ref array<ref RoleSettingsData> roles = new RoleSettingsData("Staff", playerIds, defaultColourAlert);
    // ref array<ref RoleSettingsData> m_Roles;
    protected ref array<ref RoleSettingsData> m_RolesArray;

    void ChatSettingsData(vector colourDirect = "255 255 255" , vector colourGlobal = "1 255 238", vector colourServer = "255 89 1", vector colourAlert = "255 1 1")
	{
		m_ColourDirect       = new SchanaColour(colourDirect);
		m_ColourDirectPlayer = new SchanaColour(colourDirect);
		m_ColourGlobal       = new SchanaColour(colourGlobal);
		m_ColourGlobalPlayer = new SchanaColour(colourGlobal);
		m_ColourServer       = new SchanaColour(colourServer);
		m_ColourAlert        = new SchanaColour(colourAlert);

        ref array<ref string> playerIds;
        playerIds.Insert("76561197997664497");
        // "Staff", playerIds, defaultColourAlert
        m_RolesArray = new array<ref RoleSettingsData>;
    }
}   
