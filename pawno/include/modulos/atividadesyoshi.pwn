/* *************************************************************************** *
*  Nome do arquivo:      modules/minhaatividade.pwn
*
*  Description: Sistema de atividades.
*
*           Copyright Brasil Perfect City.  All rights reserved.
* *************************************************************************** */

#include <YSI\y_hooks>

//------------------------------------------------------------------------------

#define PASTA_ATIVIDADES 			"Atividades/%s.cfg"
#define MAX_ATIVIDADE 				31

enum _:enum_AtividadePlayer
{
	atividade_dia[365],
	atividade_ano[365]
};
new AtividadePlayer[MAX_PLAYERS][enum_AtividadePlayer],
	AtividadeTimer[MAX_PLAYERS] = -1;

//------------------------------------------------------------------------------

public OnPlayerAtivUpdate(playerid);

//------------------------------------------------------------------------------

hook OnPlayerConnect(playerid)
{
	AtividadeTimer[playerid] = -1;
	for(new i; i < 365; i ++)
	{
		AtividadePlayer[playerid][atividade_dia][i] = 0;
		AtividadePlayer[playerid][atividade_ano][i] = 0;
	}
	IniciarAtividade(playerid);
	return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerDisconnect(playerid, reason)
{
	SalvarAtividade(playerid);
	for(new i; i < 365; i ++)
	{
		AtividadePlayer[playerid][atividade_dia][i] = 0;
		AtividadePlayer[playerid][atividade_ano][i] = 0;
	}
	if(AtividadeTimer[playerid] != -1)
		KillTimer(AtividadeTimer[playerid]), AtividadeTimer[playerid] = -1;
	return Y_HOOKS_CONTINUE_RETURN_1;	
}

public OnPlayerAtivUpdate(playerid)
{
	if(CheckConnect(playerid))
		AtividadePlayer[playerid][atividade_dia][getdate()-1]++;
}

//------------------------------------------------------------------------------

ConvertAtividade(number)
{
    new hours = 0, mins = 0, secs = 0, string[100];
    hours = floatround(number / 3600);
    mins = floatround((number / 60) - (hours * 60));
    secs = floatround(number - ((hours * 3600) + (mins * 60)));
    new days = 0;

    if(hours >= 24)
    {
        days = floatround((hours/24), floatround_floor);
        hours = hours % 24;
    }

    if(days > 0)
    {
        format(string, 100, "%d dias, %02d:%02d:%02d", days, hours, mins, secs);
    }
    else if(hours > 0)
    {
        format(string, 100, "%02d:%02d:%02d", hours, mins, secs);
    }
    else
    {
        format(string, 100, "%02d:%02d", mins, secs);
    }
    return string;
}

ReturnUserActivy(text[], playerid = INVALID_PLAYER_ID)
{
    new pos = 0;
    while (text[pos] < 0x21)
    {
        if (text[pos] == 0) return INVALID_PLAYER_ID;
        pos++;
    }
    new userid = INVALID_PLAYER_ID;
    if (IsNumeric(text[pos]))
    {
        userid = strval(text[pos]);
        if (userid >=0 && userid < MAX_PLAYERS)
        {
            if(!IsPlayerConnected(userid))
            {
                userid = INVALID_PLAYER_ID;
            }
            else
            {
                return userid;
            }
        }
    }

    new len = strlen(text[pos]);
    new count = 0;
    new name[MAX_PLAYER_NAME];
    foreach(new i: Player)
    {
        GetPlayerName(i, name, sizeof (name));
        if (strcmp(name, text[pos], true, len) == 0)
        {
            if (len == strlen(name))
            {
                return i;
            }
            else
            {
                count++;
                userid = i;
            }
        }
    }

    if (count != 1)
    {
        if (playerid != INVALID_PLAYER_ID)
        {
            if (count)
            {
                SendClientMessage(playerid, 0xFF0000AA, "Multiple users found, please narrow earch");
            }
            else
            {
                SendClientMessage(playerid, 0xFF0000AA, "No matching user found");
            }
        }
        userid = INVALID_PLAYER_ID;
    }
    return userid;
}


ShowActivity(playerid, Nome[], dias)
{
	new giveid = ReturnUserActivy(Nome), index, dia = getdate()-1, Buffer[2048], bool:Resetou = false, ano, str[128];
	getdate(ano, index, index);
	if(giveid == INVALID_PLAYER_ID)
	{
		format(str, 20+MAX_PLAYER_NAME, PASTA_ATIVIDADES, Nome);
		if(!fexist(str))
			return SendClientMessage(playerid, -1, "Conta não encontrada.");
		if(!DOF2_FileExists(str))
			return SendClientMessage(playerid, -1, "Conta não encontrada.");
		
		new File:handle = fopen(str, io_read);
		if(handle)
		{
			new file_len = flength(handle);
			if(file_len == (enum_AtividadePlayer*4))
			{
				new Atividade[enum_AtividadePlayer];
				fblockread(handle, Atividade);
				if(Atividade[atividade_ano][dia-1] != ano)
				{
					Atividade[atividade_dia][dia-1] = 0;
					Atividade[atividade_ano][dia-1] = ano;
				}
				fclose(handle);
			
				format(str, sizeof str, "{F5DEB3}Nome: {E0FFFF}%s\n{F5DEB3}Status: {B22222}Offline\n\n", Nome);
				strcat(Buffer, str);
				for(new i = 0; i != dias; i++)
				{
					index = dia-i;
					if(index < 0)
					{
						index = 365-(index*-1);
						if(!Resetou)
							Resetou = true;
					}
					if(!Resetou)
					{
						if(Atividade[atividade_ano][index] != ano)
						{
							Atividade[atividade_ano][index] = 0;
							Atividade[atividade_dia][index] = 0;
						}
					}

					if(i > 1)
						format(str, sizeof str, "{F5DEB3}Horas jogadas a %d dias: {E0FFFF}%s\n", i, ConvertAtividade(Atividade[atividade_dia][index]));
					else if(i == 1)
						format(str, sizeof str, "{F5DEB3}Horas jogadas ontem: {E0FFFF}%s\n", ConvertAtividade(Atividade[atividade_dia][index]));
					else
						format(str, sizeof str, "{F5DEB3}Horas jogadas hoje: {E0FFFF}%s\n", ConvertAtividade(Atividade[atividade_dia][index]));

					strcat(Buffer, str);
				}
			}
			else
				return SendClientMessage(playerid, -1, "O arquivo não é compativel com a array da atividade.");
		}
		else
			return SendClientMessage(playerid, -1, "Conta não encontrada");
	}
	else
	{
		if(strcmp(UserInfo[giveid][user_nome], Nome, true))
			return SendClientMessage(playerid, -1, "Conta não encontrada");

		format(str, sizeof str, "{F5DEB3}Nome: {E0FFFF}%s\n{F5DEB3}Status: {FFFF00}Online\n\n", Nome);
		strcat(Buffer, str);
		for(new i = 0; i != dias; i++)
		{
			index = dia-i;
			if(index < 0)
			{
				index = 365-(index*-1);
				if(!Resetou)
					Resetou = true;
			}
			if(!Resetou)
			{
				if(AtividadePlayer[giveid][atividade_ano][index] != ano)
				{
					AtividadePlayer[giveid][atividade_ano][index] = 0;
					AtividadePlayer[giveid][atividade_dia][index] = 0;
				}
			}

			if(i > 1)
				format(str, sizeof str, "{F5DEB3}Horas jogadas a %d dias: {E0FFFF}%s\n", i, ConvertAtividade(AtividadePlayer[giveid][atividade_dia][index]));
			else if(i == 1)
				format(str, sizeof str, "{F5DEB3}Horas jogadas ontem: {E0FFFF}%s\n", ConvertAtividade(AtividadePlayer[giveid][atividade_dia][index]));
			else
				format(str, sizeof str, "{F5DEB3}Horas jogadas hoje: {E0FFFF}%s\n", ConvertAtividade(AtividadePlayer[giveid][atividade_dia][index]));
			strcat(Buffer, str);
		}
	}
	strcat(Buffer, "\n\n{B22222}OBS: {828282}Esse resultado pode ter um percentual de erro de até de 1%");
	format(str, sizeof str, "{F5DEB3}Atividades de {E0FFFF}%s", Nome);
	ShowPlayerDialog(playerid, 566, DIALOG_STYLE_MSGBOX, str, Buffer, "Fechar", "");
	return true;
}

CMD:minhaatividade(playerid)
{
	ShowActivity(playerid, UserInfo[playerid][user_nome], MAX_ATIVIDADE);
	return 1;
}

TrocarNickAtividades(oldnick[], newnick[])
{
	new oldfile[80], newfile[80];
	format(oldfile, sizeof oldfile, PASTA_ATIVIDADES, oldnick);
	format(newfile, sizeof newfile, PASTA_ATIVIDADES, newnick);
	DOF2_RenameFile(oldfile, newfile);
}


CMD:veratividades(playerid, params[])
{
	if(CheckAdmin(playerid, 5))
		return 1;
	new Nome[MAX_PLAYER_NAME];
	if(sscanf(params, "s[24]", Nome))
		return SendClientMessage(playerid, -1, "USO: /veratividades [Nome do jogador]");

	ShowActivity(playerid, Nome, MAX_ATIVIDADE);
	return 1;
}

SalvarAtividade(playerid)
{
	new str[20+MAX_PLAYER_NAME];
	format(str, sizeof str, PASTA_ATIVIDADES, UserInfo[playerid][user_nome]);
	new File:handle = fopen(str, io_write);
	if(handle)
	{
		fblockwrite(handle, AtividadePlayer[playerid]);
		fclose(handle);
	}
}

IniciarAtividade(playerid)
{
	new str[20+MAX_PLAYER_NAME], mes, dia, ano;
	getdate(ano, mes, dia);
	format(str, sizeof str, PASTA_ATIVIDADES, UserInfo[playerid][user_nome]);
	new File:handle = fopen(str, io_read);
	if(handle)
	{
		new file_len = flength(handle);
		if(file_len == (enum_AtividadePlayer*4))
		{
			fblockread(handle, AtividadePlayer[playerid]);
			if(AtividadePlayer[playerid][atividade_ano][dia-1] != ano)
			{
				AtividadePlayer[playerid][atividade_dia][dia-1] = 0;
				AtividadePlayer[playerid][atividade_ano][dia-1] = ano;
			}
			fclose(handle);
			AtividadeTimer[playerid] = SetTimerEx("OnPlayerAtivUpdate", 1000, true, "i", playerid);
		}
		else
			printf("O arquivo\"%s\' não é compativel com a array das atividades;", str);
	}
	else
	{
		AtividadePlayer[playerid][atividade_dia][dia-1] = 0;
		AtividadePlayer[playerid][atividade_ano][dia-1] = ano;
		AtividadeTimer[playerid] = SetTimerEx("OnPlayerAtivUpdate", 1000, true, "i", playerid);
	}
}