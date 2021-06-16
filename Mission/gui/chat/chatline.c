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
                ref array<RoleSettingsData> m_Roles = g_ResistanceRoles;
				RoleSettingsData roleMatched = null;
                for (int i=0;i<m_Roles.Count();i++){
                    RoleSettingsData role = m_Roles[i];
                    string roleName = role.GetName();
                    if (roleName == theRole){
                        roleMatched = role;
                    }
                }
                if (roleMatched != null){
                    SetSchanaColour (GetSchanaModGlobalChatSettings ().GetColorGlobal (), GetSchanaModGlobalChatSettings ().GetColorGlobalPlayer (), roleMatched.GetColour());
                } else {
                    theRole="";
                    SetSchanaColour (GetSchanaModGlobalChatSettings ().GetColorGlobal (), GetSchanaModGlobalChatSettings ().GetColorGlobalPlayer (), 0);
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
            //! TODO FIX THE NAME CAP ISSUE
			m_NameWidget.SetText (theName + ": ");
			m_TextWidget.SetText (theText);
            // GetSchanaModGlobalChatSettings().GetColorAlert()
            
                ref array<RoleSettingsData> m_RolesAlt = g_ResistanceRoles;
				RoleSettingsData roleMatchedAlt = null;
                for (int j=0;j<m_RolesAlt.Count();j++){
                    RoleSettingsData roleAlt = m_RolesAlt[j];
                    string roleNameAlt = roleAlt.GetName();
                    if (roleNameAlt == theRole){
                        roleMatchedAlt = roleAlt;
                    }
                }
                if (roleMatchedAlt != null){
                    // TODO FIX COLOURS HERE
                    SetSchanaColour (GetSchanaModGlobalChatSettings ().GetColorDirect (), GetSchanaModGlobalChatSettings ().GetColorDirectPlayer (), roleMatchedAlt.GetColour());
                } else {
                    theRole="";
                    // TODO FIX COLOURS HERE
                    SetSchanaColour (GetSchanaModGlobalChatSettings ().GetColorDirect (), GetSchanaModGlobalChatSettings ().GetColorDirectPlayer (), 0);
                }
            //  SetSchanaColour (GetSchanaModGlobalChatSettings ().GetColorDirect (), GetSchanaModGlobalChatSettings ().GetColorGlobalPlayer (), GetSchanaModGlobalChatSettings().GetColorAlert());
        } else {
            SetColour (GetSchanaModGlobalChatSettings ().GetColorServer ());
        }
    }
	
	protected void SetSchanaColour (int tcolour, int pcolour, int rcolour)
	{
		m_NameWidget.SetColor (pcolour);
		m_TextWidget.SetColor (tcolour);
		//TODO HERE ADD RCOLOUR
        if (rcolour == 0){
            m_RoleWidget.Show(false);
        } else {
            m_RoleWidget.SetColor (rcolour);
        }
	}
}