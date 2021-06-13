modded class PlayerBase extends ManBase {
    static const int SCHANA_RPC_CHAT_CLIENT_SEND_GLOBAL = -44301;

    override void OnRPC (PlayerIdentity sender, int rpc_type, ParamsReadContext ctx) {
        switch (rpc_type) {
            case SCHANA_RPC_CHAT_CLIENT_SEND_GLOBAL:
                {
                    Param1<string> chatParams;
                    if (!ctx.Read (chatParams)) return;
                    string name = sender.GetName ();
                    Print(sender.GetPlainId());
					//Use Plain ID here to identify admins
				    //76561197997664497
                    string text = name + " : " + chatParams.param1;

                    ref array<Man> players = new array<Man> ();
                    GetGame ().GetPlayers (players);

                    for (int i = 0; i < players.Count (); ++i) {
                        if (players[i] && players[i].GetIdentity ()) {
                            GetGame ().RPCSingleParam (players[i], ERPCs.RPC_USER_ACTION_MESSAGE, new Param1<string> (text), true, players[i].GetIdentity ());
                        }
                    }

                    break;
                }
        }

        super.OnRPC (sender, rpc_type, ctx);
    }
}