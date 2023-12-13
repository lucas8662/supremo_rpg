#include <YSI_Coding\y_hooks>

hook OnPlayerConnect(playerid) 
{
	
    RemoveBuildingForPlayer(playerid, 14795, 1388.8828, -20.8828, 1005.2031, 0.25); // WAREHOUSE 1

	return Y_HOOKS_CONTINUE_RETURN_1;
}