class RoleSettingsData {
    protected string            Name;
    protected ref array<string> Members;
    protected ref SchanaColour  Colour;

    void RoleSettingsData(string roleName = "Staff", array<string> playerIds = null, SchanaColour roleColour = null){
        // "Staff", playerIds, defaultColourAlert
        if (!roleName){
            Name = "Staff"
        }
        if (!playerIds){
            Members = {
                "76561197997664497"
            };
        }
        if (!roleColour){
            Colour = new SchanaColour("255 0 0");
        }
        Name = roleName;
        Members = playerIds;
        Colour = roleColour;
    }

    string getRoleName(){
        return Name;
    }

    void setRoleName(string name){
        Name = name;
    }

    array<string> getPlayerIds(){
        return Members;
    }

    void setPlayerIds(array<string> ids){
        Members = ids;
    } 

    SchanaColour getRoleColour(){
        return Colour;
    }

    void setRoleColour(SchanaColour colour){
        Colour = colour;
    }
}
