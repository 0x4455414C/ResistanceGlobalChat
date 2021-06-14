class RoleSettingsData {
    static vector red     = "255 1 1";

    protected string            Name;
    protected ref array<string> Members;
    protected ref SchanaColour  Colour = new SchanaColour(red);

    void RoleSettingsData(string roleName = "Staff", array<string> playerIds = null, SchanaColour roleColour = null){
        if (playerIds.Count() == 0){
            Members = {
                "76561197997664497"
            };
        }
        if (roleColour == null){
            Colour = new SchanaColour("255 1 1");
        }
        Name = roleName;
        Members = playerIds;
        Colour = roleColour;
    }

    string GetName(){
        return Name;
    }

    void GetName(string name){
        Name = name;
    }

    array<string> GetMembers(){
        return Members;
    }

    void GetMembers(array<string> ids){
        Members = ids;
    } 

    int GetColour(){
        return Colour.Get();
    }

    void SetColour(SchanaColour colour){
        Colour = colour;
    }
}
