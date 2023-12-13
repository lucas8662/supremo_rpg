#include <YSI_Coding\y_hooks>

hook OnGameModeInit() {

    CreateDynamicObject(18282, -12.40001, -2494.71411, 35.84215, 0.00000, 0.00000, 300.71634);
    CreateDynamicObject(1522, -16.92780, -2498.16699, 35.83230, 0.00000, 0.00000, 30.46800);
    CreateDynamicObject(19858, -220.42926, 1400.26147, 28.02210, 0.00000, 0.00000, 0.00000);

    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerConnect(playerid) {
	
    RemoveBuildingForPlayer(playerid, 17445, -11.2734, -2498.9766, 35.4766, 0.25);
    RemoveBuildingForPlayer(playerid, 17446, -34.8594, -2486.6016, 35.4766, 0.25);
    RemoveBuildingForPlayer(playerid, 17447, -10.1719, -2526.5859, 37.2500, 0.25);
    RemoveBuildingForPlayer(playerid, 17041, -34.8594, -2486.6016, 35.4766, 0.25);
    RemoveBuildingForPlayer(playerid, 17042, -24.3203, -2528.1641, 35.5469, 0.25);
    RemoveBuildingForPlayer(playerid, 17070, -23.3750, -2507.1250, 35.6719, 0.25);
    RemoveBuildingForPlayer(playerid, 17044, -11.2734, -2498.9766, 35.4766, 0.25);
    RemoveBuildingForPlayer(playerid, 17045, -10.1719, -2526.5859, 37.2500, 0.25);
    RemoveBuildingForPlayer(playerid, 16154, -219.4375, 1407.3828, 26.7656, 0.25);

	return Y_HOOKS_CONTINUE_RETURN_1;
}