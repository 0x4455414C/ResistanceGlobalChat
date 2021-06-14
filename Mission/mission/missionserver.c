modded class MissionServer extends MissionBase {
    override void OnInit () {
        super.OnInit ();
		Print ("[SchanaChat] OnInit");
		// GetSchanaModGlobalChatServerSettings ();
		GetResistanceChatSettings();
		GetRPCManager ().AddRPC ( "SchanaChat", "SchanaChatSettingsRPC", this, SingeplayerExecutionType.Both );
	}
	
	void SchanaChatSettingsRPC( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target ) {
		PlayerIdentity RequestedBy = PlayerIdentity.Cast(sender);
		if (RequestedBy){
			Print ("[SchanaChat] Settings Requested By " + RequestedBy.GetId ());
			GetRPCManager ().SendRPC ("SchanaChat", "SchanaChatSettingsRPC", new Param1< ResistanceChatSettings >( ResistanceChatSettings () ), true, RequestedBy);
		}
	}
	
}