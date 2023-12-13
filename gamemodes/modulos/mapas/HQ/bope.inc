#include <YSI_Coding\y_hooks>
new bopeobjid;

hook OnGameModeInit() 
{
    bopeobjid = CreateDynamicObject(19380, 905.706359, -1048.042968, 30.501560, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bopeobjid, 0, 9514, "711_sfw", "ws_carpark2", 0);
    bopeobjid = CreateDynamicObject(19380, 916.206176, -1048.042968, 30.501560, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bopeobjid, 0, 9514, "711_sfw", "ws_carpark2", 0);


    CreateDynamicObject(18757, 221.76694, 179.37683, 1003.63190,   0.00000, 0.00000, 270.01398);
    return Y_HOOKS_CONTINUE_RETURN_1;
}