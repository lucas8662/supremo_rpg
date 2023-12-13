/* *************************************************************************** *
*  Nome do arquivo:      modules/minhaatividade.pwn
*
*  Description: Sistema de atividades.
*
*           Copyright Brasil Perfect City.  All rights reserved.
* *************************************************************************** */

#include <YSI\y_hooks>

new DB:Connect;

hook OnGameModeInit()
{
    if((Connect = db_open("database.db")) == DB:0)
    {
		printf("Falha ao carregar o banco de dados (database.db)!");
		//SendRconCommand("exit");
	}
}