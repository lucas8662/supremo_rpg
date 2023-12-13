new possiveis_dv[][] =
{
	"ip.brasil",
	":7777",
	"PlayForever",
	"PlayHorny",
	"play horny",
	"PlayGames",
	"StartLife",
	"PlayFacil",
	":7779",
	":8888",
	":7778",
	":7775",
	"brasilplay",
	"Brasil Play",
	"CSA",
	"server.",
	"ip.",
	"samp."
};

stock AntiDivulguer(playerid, string[])
{
	new nums = 0, ponts = 0;
	for(new i; i < strlen(string); i++)
	{
		if(string[i] >= '0' && '9' >= string[i] || (string[i] == '.' || string[i] == ':')){
			if(string[i] == '.' || string[i] == ':'){
				ponts++;
			}
			else{
				nums++;
			}
			if(nums >= 8 && ponts >= 3)
			{
				SendClientMessage(playerid, -1, "{00EAF6}ANTICHEAT:{FFFFFF} Você foi acusado:{00EAF6} (Divulgando IP)");
	            SendClientMessage(playerid, -1, "Info: Caso voce realmente não esteja divulgando um IP, avise imediatamente os admins usando /relatorio.");
	            SendClientMessage(playerid, -1, "Info: Se você estiver divulgando outro servidor aqui, será banido permanentemente sem chances de revisão!");
	            SendClientMessage(playerid, -1, "__________________________________________________________________________________________________________");
				new str[128];
				format(str, sizeof str, "[Anti-Divulguer]: %s foi pego divulgando o IP: %s!", PlayerGetName(playerid), string);
				CallLocalFunction("OnPlayerCheater", "dds", playerid, 999, str);
				return 1;
			}
		}
	}

	for(new iDv; iDv < sizeof(possiveis_dv); iDv++)
	{
	   	if(strfind(string, possiveis_dv[iDv], true) != -1)
	   	{
			SendClientMessage(playerid, -1, "{00EAF6}ANTICHEAT:{FFFFFF} Você foi acusado:{00EAF6} (Divulgando IP)");
            SendClientMessage(playerid, -1, "Info: Caso voce realmente não esteja divulgando um IP, avise imediatamente os admins usando /relatorio.");
            SendClientMessage(playerid, -1, "Info: Se você estiver divulgando outro servidor aqui, será banido permanentemente sem chances de revisão!");
            SendClientMessage(playerid, -1, "__________________________________________________________________________________________________________");
			new str[128];
			format(str, sizeof str, "[Anti-Divulguer]: %s foi pego divulgando o IP: %s!", PlayerGetName(playerid), string);
			CallLocalFunction("OnPlayerCheater", "dds", playerid, 999, str);
			return 1;
		}
	}
	return 0;
}