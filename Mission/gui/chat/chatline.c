modded class ChatLine {
    TextWidget m_RoleWidget;
    void ChatLine (Widget root_widget) {
        m_RootWidget = GetGame ().GetWorkspace ().CreateWidgets ("TheResistanceChat/GUI/layouts/chatline.layout", root_widget);

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
        string theRole = "";
		if (params.param2 == "" && cindex > 0){
			theName = params.param3;            
            theName = theName.Substring (0, cindex);
            if (sindex > 0){
                theRole = theName;
				theName = theName.SubstringInverted (theName, 0, (sindex+3));
				theRole = theRole.Substring (0, sindex);
            }
			cindex = cindex + 3;
			int len = theText.Length () - cindex;
			theText = theText.Substring (cindex,len);
		}
        if (channel & CCSystem) {
            if (params.param2 == "" && params.param3.IndexOf (" : ") > 0) {
                if (theRole!=""){
                    //TODO ONE MORE CHECK IN HERE MAYBE
                    m_RoleWidget.SetText ("["+theRole + "] ");
                }
				if (theName != theText){
					m_NameWidget.SetText (theName + ": ");
				}
				m_TextWidget.SetText (theText);
                //GetSchanaModGlobalChatSettings().GetColorAlert()
                RoleSettingsData role;
                ref array<RoleSettingsData> m_Roles = g_ResistanceRoles;
                for (int i=0;i<m_Roles.Count();i++){
                    if (m_Roles.GetName() == theRole){
                        role = m_Roles[i];
                    }
                }
                if (role != null && role.GetName()!=""){
                    SetSchanaColour (GetSchanaModGlobalChatSettings ().GetColorGlobal (), GetSchanaModGlobalChatSettings ().GetColorGlobalPlayer (), role.GetColour());
                } else {
                    theRole="";
                    SetSchanaColour (GetSchanaModGlobalChatSettings ().GetColorGlobal (), GetSchanaModGlobalChatSettings ().GetColorGlobalPlayer (), GetSchanaModGlobalChatSettings().GetColorAlert());
                }
                // SetSchanaColour (GetSchanaModGlobalChatSettings ().GetColorGlobal (), GetSchanaModGlobalChatSettings ().GetColorGlobalPlayer (), GetSchanaModGlobalChatSettings().GetColorAlert());
            } else {
                SetColour (GetSchanaModGlobalChatSettings ().GetColorAlert ());
            }
        } else if (channel & CCAdmin) {
            SetColour (GetSchanaModGlobalChatSettings ().GetColorServer ());
        } else if (channel == 0 || channel & CCDirect) {
            if (theRole!=""){
                m_RoleWidget.SetText ("["+theRole + "] ");
            }
			m_NameWidget.SetText (theName + ": ");
			m_TextWidget.SetText (theText);
            // GetSchanaModGlobalChatSettings().GetColorAlert()
            
               for (int j=0;j<m_Roles.Count();j++){
                    if (m_Roles.GetName() == theRole){
                        role = m_Roles[j];
                    }
                }
                if (role.GetName()!=""){
                    SetSchanaColour (GetSchanaModGlobalChatSettings ().GetColorGlobal (), GetSchanaModGlobalChatSettings ().GetColorGlobalPlayer (), role.GetColour());
                } else {
                    theRole="";
                    SetSchanaColour (GetSchanaModGlobalChatSettings ().GetColorGlobal (), GetSchanaModGlobalChatSettings ().GetColorGlobalPlayer (), GetSchanaModGlobalChatSettings().GetColorAlert());
                }
            //  SetSchanaColour (GetSchanaModGlobalChatSettings ().GetColorGlobal (), GetSchanaModGlobalChatSettings ().GetColorGlobalPlayer (), GetSchanaModGlobalChatSettings().GetColorAlert());
        } else {
            SetColour (GetSchanaModGlobalChatSettings ().GetColorServer ());
        }
    }
	
	protected void SetSchanaColour (int tcolour, int pcolour, int rcolour)
	{
		m_NameWidget.SetColor (pcolour);
		m_TextWidget.SetColor (tcolour);
		//TODO HERE ADD RCOLOUR
        m_RoleWidget.SetColor (rcolour);
	}
}