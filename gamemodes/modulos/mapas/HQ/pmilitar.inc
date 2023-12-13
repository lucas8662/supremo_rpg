#include <YSI_Coding\y_hooks>

hook OnGameModeInit() 
{
    new tmpobject;
    CreateDynamicObject(2886, 247.654113, 72.420867, 1003.990966, 0.000000, 0.000000, 0.000000);
    CreateDynamicObject(2886, 247.654113, 72.760917, 1003.990966, 0.000000, 0.000000, 180.000000);
    CreateDynamicObject(2886, 241.477325, 77.152580, 1005.469055, 0.000000, 0.000000, 270.000000);
    CreateDynamicObject(2886, 244.837356, 77.152580, 1004.108642, 0.000000, 0.000000, 450.000000);
    CreateDynamicObject(2886, 247.973281, 74.472053, 1004.020751, 0.000000, 0.000000, 270.000000);
    CreateDynamicObject(2886, 248.313247, 74.472053, 1004.020751, 0.000000, 0.000000, 450.000000);
    CreateDynamicObject(2886, 250.473281, 64.594291, 1004.100891, 0.000000, 0.000000, 270.000000);
    CreateDynamicObject(2886, 250.813140, 64.594291, 1004.100891, 0.000000, 0.000000, 450.000000);
    CreateDynamicObject(1497, 255.178314, 91.867591, 1001.445312, 0.000000, 0.000000, 0.000000);
    tmpobject = CreateDynamicObject(19355, 250.503768, 69.447425, 1005.421081, 0.000000, 0.000000, 0.000000);
    SetDynamicObjectMaterial(tmpobject, 0, 2922, "kmb_keypadx", "keypad_glass", 0x00000000);
    tmpobject = CreateDynamicObject(19355, 250.503768, 66.237457, 1005.421081, 0.000000, 0.000000, 0.000000);
    SetDynamicObjectMaterial(tmpobject, 0, 2922, "kmb_keypadx", "keypad_glass", 0x00000000);
    return Y_HOOKS_CONTINUE_RETURN_1;
}