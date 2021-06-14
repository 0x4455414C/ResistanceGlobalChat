modded class ChatLine {
    TextWidget m_RoleWidget;
    void ChatLine (Widget root_widget) {
        m_RootWidget = GetGame ().GetWorkspace ().CreateWidgets ("SchanaModGlobalChat/GUI/layouts/chatline.layout", root_widget);

        m_RoleWidget = TextWidget.Cast (m_RootWidget.FindAnyWidget ("ChatItemSenderRoleWidget"));
        m_NameWidget = TextWidget.Cast (m_RootWidget.FindAnyWidget ("ChatItemSenderWidget"));
        m_TextWidget = TextWidget.Cast (m_RootWidget.FindAnyWidget ("ChatItemTextWidget"));

        m_RoleWidget.SetTextExactSize (GetSchanaModGlobalChatSettings ().GetSize ());
        m_NameWidget.SetTextExactSize (GetSchanaModGlobalChatSettings ().GetSize ());
        m_TextWidget.SetTextExactSize (GetSchanaModGlobalChatSettings ().GetSize ());
    }

    void SchanaUpdateSize () {
        m_RoleWidget.SetTextExactSize (GetSchanaModGlobalChatSettings ().GetSize ());
        m_NameWidget.SetTextExactSize (GetSchanaModGlobalChatSettings ().GetSize ());
        m_TextWidget.SetTextExactSize (GetSchanaModGlobalChatSettings ().GetSize ());
    }
	
	
	
    override void Set (ChatMessageEventParams params) {
		
        super.Set (params);
        int channel = params.param1;
		int cindex = params.param3.IndexOf (" : ");
        int sindex = params.param3.IndexOf ("|-|");

		string theName = params.param2;
		string theText = params.param3;
        string theRole = null;
		if (params.param2 == "" && cindex > 0){
			theName = params.param3;            
            if (sindex > 0){
                theRole = theName;
				theName = theName.Substring ((sindex+3), cindex);
				theRole = theRole.Substring (0, sindex);
              
                Print(theRole);
                // TODO MORE HERE
            } else {
				theName = theName.Substring (0, cindex);
			}
            
            // TRIM String
			cindex = cindex + 3;
			int len = theText.Length () - cindex;
			theText = theText.Substring (cindex,len);

          
		}
        if (channel & CCSystem) {
            if (params.param2 == "" && params.param3.IndexOf (" : ") > 0) {
                if (theRole!=null){
                    m_RoleWidget.setText (theRole + " ");
                }
				if (theName != theText){
					m_NameWidget.SetText (theName + ": ");
				}
				m_TextWidget.SetText (theText);
                SetSchanaColour (GetSchanaModGlobalChatSettings ().GetColorGlobal (), GetSchanaModGlobalChatSettings ().GetColorGlobalPlayer ());
            } else {
                SetColour (GetSchanaModGlobalChatSettings ().GetColorAlert ());
            }
        } else if (channel & CCAdmin) {
            SetColour (GetSchanaModGlobalChatSettings ().GetColorServer ());
        } else if (channel == 0 || channel & CCDirect) {
            if (theRole){
                m_RoleWidget.SetText (theRole + " ");
            }
			m_NameWidget.SetText (theName + ": ");
			m_TextWidget.SetText (theText);
            SetSchanaColour (GetSchanaModGlobalChatSettings ().GetColorDirect (), GetSchanaModGlobalChatSettings ().GetColorDirectPlayer (), GetResistanceChatSettings().FindRoleByName().GetColour(); );
        } else {
            SetColour (GetSchanaModGlobalChatSettings ().GetColorServer ());
        }
    }
	
	protected void SetSchanaColour (int tcolour, int pcolour, int rcolour = 0)
	{
		m_NameWidget.SetColor (pcolour);
		m_TextWidget.SetColor (tcolour);
		//TODO HERE ADD RCOLOUR
        m_RoleWidget.SetColor (rcolour);
	}
}