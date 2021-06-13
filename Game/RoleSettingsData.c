class RoleSettingsData {
    protected string            m_RoleName;
    protected ref array<string>    m_PlayerIds;
    protected ref SchanaColour  m_RoleColour;

    void RoleSettings(string roleName = "Staff", array<string> playerIds = null, SchanaColour roleColour = null){
        // "Staff", playerIds, defaultColourAlert
        m_RoleName = roleName;
        m_PlayerIds = playerIds;
        m_RoleColour = roleColour;
    }

    string getRoleName(){
        return m_RoleName;
    }

    void setRoleName(string name){
        m_RoleName = name;
    }

    array<string> getPlayerIds(){
        return m_PlayerIds;
    }

    void setPlayerIds(array<string> ids){
        m_PlayerIds = ids;
    } 

    SchanaColour getRoleColour(){
        return m_RoleColour;
    }

    void setRoleColour(SchanaColour colour){
        m_RoleColour = colour;
    }
}
