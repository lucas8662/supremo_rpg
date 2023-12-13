//######################################################[Includes]#######################################################//

#include <a_samp>
#include <YSI_CODING\y_hooks>

//####################################################[Vars/Defines]#####################################################//

#define Pasta_Decoracao 			"TemasDecorados/%s"
#define MAX_OBJS 					800

enum enum_Objetos
{
	object_id,
	object_model,
	Float:object_pos[6],
	Float:object_range
};
new Objetos[MAX_OBJS][enum_Objetos],
	TemaCarregado[20],
	TemaPlayer[MAX_PLAYERS][50];


//####################################################[Hooks/Funcs]#####################################################//

hook OnGameModeInit()
{
	TemaCarregado[0] = EOS;
	for(new i; i < MAX_OBJS; i ++)
	{
		Objetos[i][object_model] = -1;
		for(new x; x < 6; x ++)
			Objetos[i][object_pos][x] = 0.0;
	}

	return 1;
}

hook OnPlayerConnect(playerid)
{
	for(new i; i < sizeof(TemaPlayer[]); i ++)
		TemaPlayer[playerid][i] = 0;
	return 1;
}

CarregarTema(tema[])
{
	new string[256];
	format(string, 80, Pasta_Decoracao, tema);
	new File:file = fopen(string, io_read);
	if(file)
	{
		new type, igualdade, tmpobject[enum_Objetos], templastid[32], count, tmp[16];
		while(fread(file, string))
		{
			if(count >= MAX_OBJS)
			{
				printf("O tema que foi carregado possui muitos objetos, só foi carregado até 800.");
				ABroadCast(COLOR_YELLOW, "[Error-ADMIN] - O tema que foi carregado possui muitos objetos, só foi carregado até 800.", 1);
				break;
			}

			strtrim(string);
			if(strfind(string, "CreateObject(", true) != -1) type = 1;
			else if(strfind(string, "CreateDynamicObject(", true) != -1) type = 1;
			else if(strfind(string, "RemoveBuildingForPlayer(", true) != -1) type = 2;
			else continue;

			igualdade = strfind(string, "="); 
			if(igualdade != -1) 
			{
				strmid(templastid, string, 0, igualdade);
				strtrim(templastid);
			}

			strmid(string, string, strfind(string, "(") + 1, strfind(string, ");"));

			if(type == 1)
			{
				if(sscanf(string, "p<,>dffffff", tmpobject[object_model], tmpobject[object_pos][0], tmpobject[object_pos][1], tmpobject[object_pos][2], tmpobject[object_pos][3], tmpobject[object_pos][4], tmpobject[object_pos][5]))
					continue;
				
			    Objetos[count][object_model] = tmpobject[object_model];
			    Objetos[count][object_pos][0] = tmpobject[object_pos][0];
			    Objetos[count][object_pos][1] = tmpobject[object_pos][1];
			    Objetos[count][object_pos][2] = tmpobject[object_pos][2];
			    Objetos[count][object_pos][3] = tmpobject[object_pos][3];
			    Objetos[count][object_pos][4] = tmpobject[object_pos][4];
			    Objetos[count][object_pos][5] = tmpobject[object_pos][5];
			    Objetos[count][object_range] = 300.0;
			    Objetos[count][object_id] = CreateDynamicObject(Objetos[count][object_model], Objetos[count][object_pos][0], Objetos[count][object_pos][1], Objetos[count][object_pos][2], Objetos[count][object_pos][3], Objetos[count][object_pos][4], Objetos[count][object_pos][5], .streamdistance = Objetos[count][object_range]);
				count++;
			}
			else if(type == 2)
			{
				if(sscanf(string, "p<,>s[16]iffff", tmp, tmpobject[object_model], tmpobject[object_pos][0], tmpobject[object_pos][1], tmpobject[object_pos][2], tmpobject[object_range]))
					continue;

				RemoveBuilding(tmpobject[object_model], tmpobject[object_pos][0], tmpobject[object_pos][1], tmpobject[object_pos][2], tmpobject[object_range]);
			}
		}
		fclose(file);
		format(TemaCarregado, sizeof TemaCarregado, tema);
		strmid(TemaCarregado, TemaCarregado, 0, strfind(TemaCarregado, ".txt"));
		printf("|== Tema carregado(%s) ==|", TemaCarregado);
		return 1;
	}
	return 0;
}

DescarregarTema()
{
	format(TemaCarregado, sizeof TemaCarregado, "");
	strtrim(TemaCarregado);
	for(new i; i < MAX_OBJS; i ++)
	{
		if(IsValidDynamicObject(Objetos[i][object_id]))
			DestroyDynamicObject(Objetos[i][object_id]);
		Objetos[i][object_model] = -1;
		Objetos[i][object_id] = -1;
		for(new x; x < 6; x ++)
			Objetos[i][object_pos][x] = 0.0;
	}
}

//######################################################[Comandos]######################################################//

//flags:carregartema(CMD_LIVRE)
Comando(carregartema)
{
	if(CheckAdmin(playerid, 10))
		return true;
	if(!isnull(TemaCarregado))
		return SendClientMessage(playerid, COLOR_ERRO, fmat_return("|ERROR| O servidor ja esta carregado com o tema %s, use /descarregartema.", TemaCarregado));

	gs_Buffer[0] = EOS;
	new dir:diretorio = dir_open("./scriptfiles/TemasDecorados/"), tema[20], type;
	while(dir_list(diretorio, tema, type))
	{
		if(type == FM_FILE)
		{
			strmid(tema, tema, 0, strfind(tema, ".txt"));
			strcat(gs_Buffer, fmat_return("%s\n", tema));
		}
	}
	ShowPlayerDialogEx(playerid, DIALOG_CARREGARTEMA, DIALOG_STYLE_LIST, "» {1E90FF}Temas pre-definidos »{FFFFFF} Carregar", gs_Buffer, "Carregar", "Fechar");
	return true;
}
//alias:carregartema("comando2");

//flags:descarregartema(CMD_LIVRE)
Comando(descarregartema)
{
	if(CheckAdmin(playerid, 10))
		return true;
	if(isnull(TemaCarregado))
		return SendClientMessage(playerid, COLOR_ERRO, "|ERROR| Não tem nenhum tema carregado.");

	ABroadCast(COLOR_YELLOW, fmat_return("[Administração] O %s %s descarregou o tema: %s.", AccountRank(UserInfo[playerid][user_adminlevel]), PlayerGetName(playerid), TemaCarregado), 2);
	DescarregarTema();
	return true;
}
//alias:descarregartema("comando2");''
