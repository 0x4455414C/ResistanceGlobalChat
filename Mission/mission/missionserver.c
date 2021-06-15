modded class MissionServer extends MissionBase {
    override void OnInit () {
        super.OnInit ();
		Print ("[SchanaChat] OnInit");
		// GetSchanaModGlobalChatServerSettings ();
		GetResistanceChatSettings();
		GetRPCManager ().AddRPC ( "SchanaChat", "SchanaChatSettingsRPC", this, SingeplayerExecutionType.Both );
		GetRPCManager ().AddRPC ( "SchanaChat", "SchanaRoleColoursRPC", this, SingeplayerExecutionType.Both );
	}
	
	void SchanaChatSettingsRPC( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target ) {
		PlayerIdentity RequestedBy = PlayerIdentity.Cast(sender);
		if (RequestedBy){
			Print ("[SchanaChat] Settings Requested By " + RequestedBy.GetId ());
			GetRPCManager ().SendRPC ("SchanaChat", "SchanaChatSettingsRPC", new Param1< ResistanceChatSettings >( GetResistanceChatSettings () ), true, RequestedBy);
		}
	}

	void SchanaRoleColoursRPC( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target ) {
		PlayerIdentity RequestedBy = PlayerIdentity.Cast(sender);
		if (RequestedBy){
			Print ("[SchanaChat] Roles Requested By " + RequestedBy.GetId ());
			GetRPCManager ().SendRPC ("SchanaChat", "SchanaRoleColoursRPC", new Param1< array<RoleSettingsData> >( GetResistanceChatSettings ().GetRoles () ), true, RequestedBy);
		}	
	}	

}