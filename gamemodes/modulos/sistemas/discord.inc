#include <YSI_Coding\y_hooks>
//DISCORD SYSTEM
enum discordInfo
{
    DCC_Guild:server_id,
    DCC_User:bot_id,

	DCC_Channel:logs_anticheat,
	DCC_Channel:logs_uacdebug,
    DCC_Channel:logs_chatadmin,
	DCC_Channel:logs_chathelper,
	DCC_Channel:logs_chatnoob,
	DCC_Channel:logs_admincmd,
	DCC_Channel:logs_editarorg,
	DCC_Channel:logs_conce,
	DCC_Channel:logs_mudarnick,
	DCC_Channel:logs_correio,
	DCC_Channel:logs_propriedades,
	DCC_Channel:logs_casas,
	DCC_Channel:logs_cofres,
	DCC_Channel:logs_grafite,
	DCC_Channel:logs_bans,
	DCC_Channel:logs_av,
	DCC_Channel:logs_adminv,
	DCC_Channel:logs_su,
	DCC_Channel:logs_empresas,
	DCC_Channel:logs_caixadeitens,
	DCC_Channel:logs_pegaritem,
	DCC_Channel:logs_droparitem,
	DCC_Channel:logs_atividadeorg,
	DCC_Channel:logs_lojamv,
	DCC_Channel:logs_leilao,
	DCC_Channel:logs_cupom,
	DCC_Channel:logs_players,
	DCC_Channel:logs_fazendas,
	DCC_Channel:logs_editarconta,
	DCC_Channel:logs_relato,
	DCC_Channel:logs_cheaters,
	DCC_Channel:logs_divulguer,
	DCC_Channel:logs_familias,
	DCC_Channel:logs_misterios,
	DCC_Channel:logs_abrircaixa,
	DCC_Channel:logs_vipchat,
	DCC_Channel:logs_bugs,
	DCC_Channel:logs_assaltos,
	DCC_Channel:logs_bonus,
	DCC_Channel:logs_editarrg,
	DCC_Channel:logs_deletarconta,
	DCC_Channel:logs_lojaext,

    DCC_Embed:embed,

}
new DiscordInfo[discordInfo];

new msgencoded[500]; // strings discord


hook OnGameModeInit() 
{
	// INFO BOT
    if (_:DiscordInfo[server_id] == 0)
            DiscordInfo[server_id] = DCC_FindGuildById("935007690407673936"); // server
		
	if (_:DiscordInfo[bot_id] == 0)
            DiscordInfo[bot_id] = DCC_FindUserById("1117009956047171604"); // bot
	
	// CANAIS
	if (_:DiscordInfo[logs_anticheat] == 0)
            DiscordInfo[logs_anticheat] = DCC_FindChannelById("1119601874631393280");

	if (_:DiscordInfo[logs_uacdebug] == 0)
            DiscordInfo[logs_uacdebug] = DCC_FindChannelById("1121527983128191016");

	if (_:DiscordInfo[logs_chatadmin] == 0)
            DiscordInfo[logs_chatadmin] = DCC_FindChannelById("1117012483102748772");
	
	if (_:DiscordInfo[logs_chathelper] == 0)
            DiscordInfo[logs_chathelper] = DCC_FindChannelById("1117012609783316500");
	
	if (_:DiscordInfo[logs_admincmd] == 0)
            DiscordInfo[logs_admincmd] = DCC_FindChannelById("1117012631367204874");
	
	if (_:DiscordInfo[logs_editarorg] == 0)
            DiscordInfo[logs_editarorg] = DCC_FindChannelById("1117012652611350578");
	
	if (_:DiscordInfo[logs_conce] == 0)
            DiscordInfo[logs_conce] = DCC_FindChannelById("1117012695443587082");

	if (_:DiscordInfo[logs_mudarnick] == 0)
            DiscordInfo[logs_mudarnick] = DCC_FindChannelById("1117012714200510544");

	if (_:DiscordInfo[logs_correio] == 0)
            DiscordInfo[logs_correio] = DCC_FindChannelById("1117012742713397290");

	if (_:DiscordInfo[logs_propriedades] == 0)
            DiscordInfo[logs_propriedades] = DCC_FindChannelById("1117012766025334895");

	if (_:DiscordInfo[logs_casas] == 0)
            DiscordInfo[logs_casas] = DCC_FindChannelById("1117012782643163206");

	if (_:DiscordInfo[logs_cofres] == 0)
            DiscordInfo[logs_cofres] = DCC_FindChannelById("1117012801362341968");

	if (_:DiscordInfo[logs_grafite] == 0)
            DiscordInfo[logs_grafite] = DCC_FindChannelById("1117012818743541760");
	
	if (_:DiscordInfo[logs_bans] == 0)
            DiscordInfo[logs_bans] = DCC_FindChannelById("1117012837810831391");
	
	if (_:DiscordInfo[logs_av] == 0)
            DiscordInfo[logs_av] = DCC_FindChannelById("1117012855997345832");
	
	if (_:DiscordInfo[logs_adminv] == 0)
            DiscordInfo[logs_adminv] = DCC_FindChannelById("1117012872657109132");
	
	if (_:DiscordInfo[logs_su] == 0)
            DiscordInfo[logs_su] = DCC_FindChannelById("1117012889316900864");

	if (_:DiscordInfo[logs_empresas] == 0)
            DiscordInfo[logs_empresas] = DCC_FindChannelById("1117012906257678416");

	if (_:DiscordInfo[logs_caixadeitens] == 0)
            DiscordInfo[logs_caixadeitens] = DCC_FindChannelById("1117012921973743616");

	if (_:DiscordInfo[logs_pegaritem] == 0)
            DiscordInfo[logs_pegaritem] = DCC_FindChannelById("1117012945524752405");

	if (_:DiscordInfo[logs_droparitem] == 0)
            DiscordInfo[logs_droparitem] = DCC_FindChannelById("1117012963975499796");

	if (_:DiscordInfo[logs_atividadeorg] == 0)
            DiscordInfo[logs_atividadeorg] = DCC_FindChannelById("1117012982514339900");

	if (_:DiscordInfo[logs_lojamv] == 0)
            DiscordInfo[logs_lojamv] = DCC_FindChannelById("1117013001485156373");
	
	if (_:DiscordInfo[logs_leilao] == 0)
            DiscordInfo[logs_leilao] = DCC_FindChannelById("1117013020812529684");
	
	if (_:DiscordInfo[logs_cupom] == 0)
            DiscordInfo[logs_cupom] = DCC_FindChannelById("1117013038759940147");
	
	if (_:DiscordInfo[logs_players] == 0)
            DiscordInfo[logs_players] = DCC_FindChannelById("1117013055386161232");
	
	if (_:DiscordInfo[logs_fazendas] == 0)
            DiscordInfo[logs_fazendas] = DCC_FindChannelById("1117013072305999914");

	if (_:DiscordInfo[logs_editarconta] == 0)
            DiscordInfo[logs_editarconta] = DCC_FindChannelById("1117013089863335976");

	if (_:DiscordInfo[logs_relato] == 0)
            DiscordInfo[logs_relato] = DCC_FindChannelById("1117013106929979392");

	if (_:DiscordInfo[logs_cheaters] == 0)
            DiscordInfo[logs_cheaters] = DCC_FindChannelById("1117013123283558511");

	if (_:DiscordInfo[logs_divulguer] == 0)
            DiscordInfo[logs_divulguer] = DCC_FindChannelById("1117013139448402000");

	if (_:DiscordInfo[logs_familias] == 0)
            DiscordInfo[logs_familias] = DCC_FindChannelById("1117013160713527347");

	if (_:DiscordInfo[logs_misterios] == 0)
            DiscordInfo[logs_misterios] = DCC_FindChannelById("1117013177708838922");
	
	if (_:DiscordInfo[logs_abrircaixa] == 0)
            DiscordInfo[logs_abrircaixa] = DCC_FindChannelById("1117013199741538365");
	
	if (_:DiscordInfo[logs_vipchat] == 0)
            DiscordInfo[logs_vipchat] = DCC_FindChannelById("1117013215797334126");
	
	if (_:DiscordInfo[logs_bugs] == 0)
            DiscordInfo[logs_bugs] = DCC_FindChannelById("1117013230905200740");
	
	if (_:DiscordInfo[logs_assaltos] == 0)
            DiscordInfo[logs_assaltos] = DCC_FindChannelById("1117013247283961946");

	if (_:DiscordInfo[logs_bonus] == 0)
            DiscordInfo[logs_bonus] = DCC_FindChannelById("1117013260844150794");

	if (_:DiscordInfo[logs_editarrg] == 0)
            DiscordInfo[logs_editarrg] = DCC_FindChannelById("1117013277399076894");

	if (_:DiscordInfo[logs_deletarconta] == 0)
            DiscordInfo[logs_deletarconta] = DCC_FindChannelById("1117013292230123560");

	if (_:DiscordInfo[logs_lojaext] == 0)
            DiscordInfo[logs_lojaext] = DCC_FindChannelById("1117013309036691539");
	
	if (_:DiscordInfo[logs_chatnoob] == 0)
            DiscordInfo[logs_chatnoob] = DCC_FindChannelById("1117027917466181693");

    return Y_HOOKS_CONTINUE_RETURN_1;
}

SendDCMSG(log[], const string[])
{
	if(Comparar(log, "logs_anticheat"))
	{
		DCC_SendChannelMessage(DiscordInfo[logs_anticheat] , string);
	}
	if(Comparar(log, "logs_uacdebug"))
	{
		DCC_SendChannelMessage(DiscordInfo[logs_uacdebug] , string);
	}
	if(Comparar(log, "logs_chatadmin"))
	{
		DCC_SendChannelMessage(DiscordInfo[logs_chatadmin] , string);
	}
	if(Comparar(log, "logs_chathelper"))
	{
		DCC_SendChannelMessage(DiscordInfo[logs_chathelper] , string);
	}
	if(Comparar(log, "logs_admincmd"))
	{
		DCC_SendChannelMessage(DiscordInfo[logs_admincmd] , string);
	}
	if(Comparar(log, "logs_editarorg"))
	{
		DCC_SendChannelMessage(DiscordInfo[logs_editarorg] , string);
	}
	if(Comparar(log, "logs_conce"))
	{
		DCC_SendChannelMessage(DiscordInfo[logs_conce] , string);
	}
	if(Comparar(log, "logs_mudarnick"))
	{
		DCC_SendChannelMessage(DiscordInfo[logs_mudarnick] , string);
	}
	if(Comparar(log, "logs_correio"))
	{
		DCC_SendChannelMessage(DiscordInfo[logs_correio] , string);
	}
	if(Comparar(log, "logs_propriedades"))
	{
		DCC_SendChannelMessage(DiscordInfo[logs_propriedades] , string);
	}
	if(Comparar(log, "logs_casas"))
	{
		DCC_SendChannelMessage(DiscordInfo[logs_casas] , string);
	}
	if(Comparar(log, "logs_cofres"))
	{
		DCC_SendChannelMessage(DiscordInfo[logs_cofres] , string);
	}
	if(Comparar(log, "logs_grafite"))
	{
		DCC_SendChannelMessage(DiscordInfo[logs_grafite] , string);
	}
	if(Comparar(log, "logs_bans"))
	{
		DCC_SendChannelMessage(DiscordInfo[logs_bans] , string);
	}
	if(Comparar(log, "logs_av"))
	{
		DCC_SendChannelMessage(DiscordInfo[logs_av] , string);
	}
	if(Comparar(log, "logs_adminv"))
	{
		DCC_SendChannelMessage(DiscordInfo[logs_adminv] , string);
	}
	if(Comparar(log, "logs_su"))
	{
		DCC_SendChannelMessage(DiscordInfo[logs_su] , string);
	}
	if(Comparar(log, "logs_empresas"))
	{
		DCC_SendChannelMessage(DiscordInfo[logs_empresas] , string);
	}
	if(Comparar(log, "logs_caixadeitens"))
	{
		DCC_SendChannelMessage(DiscordInfo[logs_caixadeitens] , string);
	}
	if(Comparar(log, "logs_pegaritem"))
	{
		DCC_SendChannelMessage(DiscordInfo[logs_pegaritem] , string);
	}
	if(Comparar(log, "logs_droparitem"))
	{
		DCC_SendChannelMessage(DiscordInfo[logs_droparitem] , string);
	}
	if(Comparar(log, "logs_atividadeorg"))
	{
		DCC_SendChannelMessage(DiscordInfo[logs_atividadeorg] , string);
	}
	if(Comparar(log, "logs_lojamv"))
	{
		DCC_SendChannelMessage(DiscordInfo[logs_lojamv] , string);
	}
	if(Comparar(log, "logs_leilao"))
	{
		DCC_SendChannelMessage(DiscordInfo[logs_leilao] , string);
	}
	if(Comparar(log, "logs_cupom"))
	{
		DCC_SendChannelMessage(DiscordInfo[logs_cupom] , string);
	}
	if(Comparar(log, "logs_players"))
	{
		DCC_SendChannelMessage(DiscordInfo[logs_players] , string);
	}
	if(Comparar(log, "logs_fazendas"))
	{
		DCC_SendChannelMessage(DiscordInfo[logs_fazendas] , string);
	}
	if(Comparar(log, "logs_editarconta"))
	{
		DCC_SendChannelMessage(DiscordInfo[logs_editarconta] , string);
	}
	if(Comparar(log, "logs_relato"))
	{
		DCC_SendChannelMessage(DiscordInfo[logs_relato] , string);
	}
	if(Comparar(log, "logs_cheaters"))
	{
		DCC_SendChannelMessage(DiscordInfo[logs_cheaters] , string);
	}
	if(Comparar(log, "logs_divulguer"))
	{
		DCC_SendChannelMessage(DiscordInfo[logs_divulguer] , string);
	}
	if(Comparar(log, "logs_familias"))
	{
		DCC_SendChannelMessage(DiscordInfo[logs_familias] , string);
	}
	if(Comparar(log, "logs_misterios"))
	{
		DCC_SendChannelMessage(DiscordInfo[logs_misterios] , string);
	}
	if(Comparar(log, "logs_abrircaixa"))
	{
		DCC_SendChannelMessage(DiscordInfo[logs_abrircaixa] , string);
	}
	if(Comparar(log, "logs_vipchat"))
	{
		DCC_SendChannelMessage(DiscordInfo[logs_vipchat] , string);
	}
	if(Comparar(log, "logs_bugs"))
	{
		DCC_SendChannelMessage(DiscordInfo[logs_bugs] , string);
	}
	if(Comparar(log, "logs_assaltos"))
	{
		DCC_SendChannelMessage(DiscordInfo[logs_assaltos] , string);
	}
	if(Comparar(log, "logs_bonus"))
	{
		DCC_SendChannelMessage(DiscordInfo[logs_bonus] , string);
	}
	if(Comparar(log, "logs_editarrg"))
	{
		DCC_SendChannelMessage(DiscordInfo[logs_editarrg] , string);
	}
	if(Comparar(log, "logs_deletarconta"))
	{
		DCC_SendChannelMessage(DiscordInfo[logs_deletarconta] , string);
	}
	if(Comparar(log, "logs_lojaext"))
	{
		DCC_SendChannelMessage(DiscordInfo[logs_lojaext] , string);
	}
	if(Comparar(log, "logs_chatnoob"))
	{
		DCC_SendChannelMessage(DiscordInfo[logs_chatnoob] , string);
	}
	return 1;
}