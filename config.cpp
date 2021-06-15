class CfgPatches
{
	class TheResistanceChat {
		requiredAddons[] = {
			"SchanaModGlobalChatDefine"
		};
	};
};

class CfgMods
{
	class TheResistanceChat
	{
		name = "TheResistanceChat";
		action = "https://github.com/schana/dayz-mod-global-chat";
		credits = "99.99% Schana, 0.01% DUAL";
		author = "schana";
		type = "mod";
		inputs = "TheResistanceChat/Data/Inputs.xml";
		dependencies[] = {
			"Game",
			"Mission",
			"World"
		};
		class defs
		{
			class gameScriptModule
			{
				files[] = {
					"TheResistanceChat/Game"
				};
			};
			class missionScriptModule
			{
				files[] = {
					"TheResistanceChat/Mission"
				};
			};
			class worldScriptModule
			{
				files[] = {
					"TheResistanceChat/World"
				};
			};
		};
	};
};
