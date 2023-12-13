#include <a_samp> 
#include <pawn.cmd> 
#include <DOF2> 

#define FILTERSCRIPT 

#define MAX_GZ     60 
#define dGz     999 
#define branca      0xFFFFFF76 
#define azul        0x0000FF76 
#define amarela     0xFFFF0076 
#define verde       0x00FF0076 
#define vermelho    0xFF000076 
#define roxo        0xA020F076 
#define preto       0x00000076 


new 
    editandoGz[MAX_PLAYERS], 
    bool:editando[MAX_PLAYERS], 
    Float:pX[MAX_PLAYERS], 
    Float:pY[MAX_PLAYERS], 
    Gangzone[MAX_GZ] 
; 
enum gI{ 

    Float:minX, 
    Float:minY, 
    Float:maxX, 
    Float:maxY, 
    cor 

}; 
new gZ[MAX_GZ][gI]; 
//------------------------------------------------ 


#if defined FILTERSCRIPT 

public OnFilterScriptInit() 
{ 
    print(#\nCriação de GangZone\nBy Yiakin); 
    SendClientMessageToAll(-1, " Sistema de Criação de GangZone carregado com sucesso. By Yiakin. "); 
    CarregarGangZones(); 
    return 1; 
} 
public OnFilterScriptExit() 
{ 
    DOF2_Exit(); 
    for(new i; i < MAX_GZ; i ++){ 
     
        DestruirGz(i); 
    } 
    return 1; 
} 

#endif 

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]) 
{ 
    new 
        str [128], 
        file[25] 
    ; 
    if(dialogid == dGz){ 
        if(response){ 
            format(file, sizeof file, "GangZones/%d.ini", listitem); 
            switch (listitem){ 

                case 0:{ 
                    CriarArquivo(playerid); 
                } 
                default:{ 
                    VerificarArquivo(playerid, listitem-1); 
                } 
            } 
        } 
        else{ 
            editando[playerid] = false; 
            editandoGz[playerid] = -1; 
        } 
    } 
    else if(dialogid == dGz + 1){ 
        new 
            str2[2000], 
            linha[30] 
        ; 
        if(response){ 
            switch(listitem){ 
                case 0:{ 

                    editando[playerid] = true; 
                    SendClientMessage(playerid, -1, "Aperte 'ALT' para marcar uma coordenada. Para voltar aperte 'C' ."); 

                } 
                case 1:{ 
                    ShowPlayerDialog(playerid, dGz + 2,DIALOG_STYLE_LIST,"{FFFFFF}Editando Cor", "{FFFFFF}Branca\nAzul\nAmarela\nVerde\nVermelho\nRoxo\nPreto","Confirmar","Voltar"); 
                } 
                case 2:{ 
                    format(file, sizeof file, "GangZones/%d.ini", editandoGz[playerid]); 
                    DOF2_RemoveFile(file); 
                    gZ[editandoGz[playerid]][minX] = 0; 
                    gZ[editandoGz[playerid]][minY] = 0; 
                    gZ[editandoGz[playerid]][maxX] = 0; 
                    gZ[editandoGz[playerid]][maxY] = 0; 
                    gZ[editandoGz[playerid]][cor] = 0; 
                    DestruirGz(editandoGz[playerid]); 
                    format(str2, sizeof str2, "{FFFFFF}Criar Gangzone\n"); 
                    for(new i; i < MAX_GZ; i ++){ 
                        format(file, sizeof file, "GangZones/%d.ini", i); 
                         if(DOF2_FileExists(file)){ 
                            format(linha, sizeof linha, "{FFFFFF}GangZone [%d]\n", i); 
                            strcat(str2, linha); 
                        } 
                    } 
                    editandoGz[playerid] = -1; 
                    ShowPlayerDialog(playerid, dGz, DIALOG_STYLE_LIST,"{FFFFFF}Criação GangZone",str2,"Continuar","Sair"); 
                } 
            } 
        } 
        else{ 
            format(str2, sizeof str2, "{FFFFFF}Criar Gangzone\n"); 
            for(new i; i < MAX_GZ; i ++){ 
                format(file, sizeof file, "GangZones/%d.ini", i); 
                 if(DOF2_FileExists(file)){ 
                    format(linha, sizeof linha, "{FFFFFF}GangZone [%d]\n", i); 
                    strcat(str2, linha); 
                } 
            } 
            editandoGz[playerid] = -1; 
            ShowPlayerDialog(playerid, dGz, DIALOG_STYLE_LIST,"{FFFFFF}Criação GangZone",str2,"Continuar","Sair"); 
        } 
    } 
    else if(dialogid == dGz + 2){ 
        if(response){ 
            switch(listitem){ 

                case 0: gZ[editandoGz[playerid]][cor] = branca; 
                case 1: gZ[editandoGz[playerid]][cor] = azul; 
                case 2: gZ[editandoGz[playerid]][cor] = amarela; 
                case 3: gZ[editandoGz[playerid]][cor] = verde; 
                case 4: gZ[editandoGz[playerid]][cor] = vermelho; 
                case 5: gZ[editandoGz[playerid]][cor] = roxo; 
                case 6: gZ[editandoGz[playerid]][cor] = preto; 
             
            } 
            SalvarGz(editandoGz[playerid]); 
            SendClientMessage(playerid, -1, "Cor da gangzone alterada com sucesso! "); 
            TrocarCorGz(editandoGz[playerid]); 
            format(str, sizeof str, "{FFFFFF}GangZone[%d]", editandoGz[playerid]); 
            ShowPlayerDialog(playerid, dGz+1, DIALOG_STYLE_LIST, str,"{FFFFFF}Editar coordenada\nMudar cor\nDeletar gangzone","Continuar","Sair"); 
        } 
        else{ 
            format(str, sizeof str, "{FFFFFF}GangZone[%d]", editandoGz[playerid]); 
            ShowPlayerDialog(playerid, dGz+1, DIALOG_STYLE_LIST, str,"{FFFFFF}Editar coordenada\nMudar cor\nDeletar gangzone","Continuar","Sair"); 
        } 
    } 
    return true; 
} 
public OnPlayerConnect(playerid) 
{ 
    editandoGz[playerid] = -1; 
    new file[25]; 
    for(new i; i < MAX_GZ; i ++){ 
        format(file, sizeof file, "GangZones/%d.ini", i); 
         if(DOF2_FileExists(file)) 
            GangZoneShowForPlayer(playerid,Gangzone[i], gZ[i][cor]); 
    } 
    return true; 
} 
public OnPlayerKeyStateChange(playerid, newkeys, oldkeys) 
{ 
    new 
        Float:x, 
        Float:y, 
        Float:z, 
        str[50] 
    ; 
    static c[MAX_PLAYERS]; 
    if(newkeys & KEY_WALK){ 
        if(!IsPlayerInAnyVehicle(playerid) && editando[playerid] == true)
        { 
            if(c[playerid] == 0)
            { 
                c[playerid] ++; 
                GetPlayerPos(playerid, x, y, z); 
                pX[playerid] = x; 
                pY[playerid] = y; 
                SendClientMessage(playerid, -1, "Coordenada salva com sucesso."); 
            } 
            else
            { 
                c[playerid] = 0; 
                editando[playerid] = false; 
                GetPlayerPos(playerid, x, y, z); 
                if(pX[playerid] > x){ 
                    gZ[editandoGz[playerid]][maxX] = pX[playerid]; 
                    gZ[editandoGz[playerid]][minX] = x; 
                } 
                else
                { 

                    gZ[editandoGz[playerid]][maxX] = x; 
                    gZ[editandoGz[playerid]][minX] = pX[playerid]; 
                }
                if(pY[playerid] > y){ 
                    gZ[editandoGz[playerid]][maxY] = pY[playerid]; 
                    gZ[editandoGz[playerid]][minY] = y; 
                } 
                else{ 
                    gZ[editandoGz[playerid]][maxY] = y; 
                    gZ[editandoGz[playerid]][minY] = pY[playerid]; 
                } 
                gZ[editandoGz[playerid]][cor] = branca; 
                CriarGz(editandoGz[playerid]); 
                SalvarGz(editandoGz[playerid]); 
                 
                GangZoneShowForPlayer(playerid, Gangzone[editandoGz[playerid]], gZ[editandoGz[playerid]][cor]); 
                format(str, 128, "Gangzone[%d] criada com sucesso.", editandoGz[playerid]); 
                SendClientMessage(playerid, -1, str); 
                format(str, sizeof str, "{FFFFFF}GangZone[%d]", editandoGz[playerid]); 
                editando[playerid] = false; 
                ShowPlayerDialog(playerid, dGz+1, DIALOG_STYLE_LIST, str,"{FFFFFF}Editar coordenada\nMudar cor\nDeletar gangzone","Continuar","Sair"); 
            } 
        } 
    } 
    else if(newkeys & KEY_CROUCH){ 
        if(!IsPlayerInAnyVehicle(playerid) && editando[playerid] == true){ 
            format(str, sizeof str, "{FFFFFF}GangZone[%d]", editandoGz[playerid]); 
            editando[playerid] = false; 
            pX[playerid] = 0; 
            pY[playerid] = 0; 
            c[playerid] = 0; 
            ShowPlayerDialog(playerid, dGz+1, DIALOG_STYLE_LIST, str,"{FFFFFF}Editar coordenada\nMudar cor\nDeletar gangzone","Continuar","Sair"); 
        } 
    } 
    return true; 
} 
//------------------------------------------------ 


CMD:gangzone(p){ 

    new 
        str[2000], 
        file[25], 
        linha[30] 
    ; 
     
    format(str, sizeof str, "{FFFFFF}Criar Gangzone\n"); 
    for(new i; i < MAX_GZ; i ++){ 
        format(file, sizeof file, "GangZones/%d.ini", i); 
         if(DOF2_FileExists(file)){ 
            format(linha, sizeof linha, "{FFFFFF}GangZone [%d]\n", i); 
            strcat(str, linha); 
        } 
    } 
    ShowPlayerDialog(p, dGz, DIALOG_STYLE_LIST,"{FFFFFF}Criação GangZone",str,"Continuar","Sair"); 
    return true; 
} 

//------------------------------------------------- 

stock CarregarGangZones(){ 
    new file[25]; 
    for(new i; i < MAX_GZ; i ++){ 
        format(file, sizeof file, "GangZones/%d.ini", i); 
        if(DOF2_FileExists(file)) 
            CarregarGz(i); 
    } 
} 
stock CarregarGz(i){ 
    new file[25]; 
    format(file, sizeof file, "GangZones/%d.ini", i); 
    if(DOF2_FileExists(file)){ 
        gZ[i][minX] = DOF2_GetFloat(file, "minX"); 
        gZ[i][minY] = DOF2_GetFloat(file, "minY"); 
        gZ[i][maxX] = DOF2_GetFloat(file, "maxX"); 
        gZ[i][maxY] = DOF2_GetFloat(file, "maxY"); 
        gZ[i][cor]  = DOF2_GetInt(file, "cor"); 
        CriarGz(i); 
    } 
} 
stock VerificarArquivo(p,i){ 
    new 
        str[50], 
        file[25] 
    ; 
    format(file, sizeof file, "GangZones/%d.ini", i); 
    if(!DOF2_FileExists(file)){ 
        for(new x = i; x < MAX_GZ; x ++){ 
            format(file, sizeof file, "GangZones/%d.ini", x); 
            if(DOF2_FileExists(file)){ 
                format(str, sizeof str, "{FFFFFF}GangZone[%d]", x); 
                editandoGz[p] = x; 
                ShowPlayerDialog(p, dGz+1, DIALOG_STYLE_LIST, str,"{FFFFFF}Editar coordenada\nMudar cor\nDeletar gangzone","Continuar","Sair"); 
                break; 
            } 
        } 
    } 
    else{ 
        format(str, sizeof str, "{FFFFFF}GangZone[%d]", i); 
        editandoGz[p] = i; 
        ShowPlayerDialog(p, dGz+1, DIALOG_STYLE_LIST, str,"{FFFFFF}Editar coordenada\nMudar cor\nDeletar gangzone","Continuar","Sair"); 
    } 
} 
stock CriarArquivo(p){ 
    new 
        str[50], 
        file[25] 
    ; 
    for(new x = 0; x < MAX_GZ; x ++){ 
        format(file, sizeof file, "GangZones/%d.ini", x); 
        if(!DOF2_FileExists(file)){ 
            format(str, sizeof str, "{FFFFFF}GangZone[%d]", x); 
            editandoGz[p] = x; 
            ShowPlayerDialog(p, dGz+1, DIALOG_STYLE_LIST, str,"{FFFFFF}Editar coordenada\nMudar cor\nDeletar gangzone","Continuar","Sair"); 
            break; 
        } 
    } 
} 
stock CriarGz(id){ 

    Gangzone[id] = GangZoneCreate(gZ[id][minX], gZ[id][minY], gZ[id][maxX], gZ[id][maxY]); 
    GangZoneShowForAll(Gangzone[id], gZ[id][cor]); 
    return true; 

} 
stock TrocarCorGz(id){ 
    GangZoneHideForAll(Gangzone[id]); 
    GangZoneShowForAll(Gangzone[id], gZ[id][cor]); 
    return true; 
} 
stock DestruirGz(id){ 
    GangZoneHideForAll(Gangzone[id]); 
    GangZoneDestroy(Gangzone[id]); 
} 
stock SalvarGz(i){ 
     
    new file[25]; 
    format(file, sizeof file, "GangZones/%d.ini", i); 
    if(!DOF2_FileExists(file)) 
        DOF2_CreateFile(file); 
    DOF2_SetFloat(file, "minX",gZ[i][minX]); 
    DOF2_SetFloat(file, "minY",gZ[i][minY]); 
    DOF2_SetFloat(file, "maxX",gZ[i][maxX]); 
    DOF2_SetFloat(file, "maxY",gZ[i][maxY]); 
    DOF2_SetInt(file, "cor",gZ[i][cor]); 
    DOF2_SaveFile(); 
}  