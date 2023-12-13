#include <YSI_Coding\y_hooks>

hook OnGameModeInit() 
{
    CreateDynamicObjectEx(2886, 226.4140625, 73.708335876465, 1005.6146240234, 0, 0, 87.339508056641, .worlds = {0, 2});
    CreateDynamicObjectEx(2886, 239.83438110352, 123.27573394775, 1003.8567504883, 0, 0, 87.339508056641, .worlds = {0, 2});
    CreateDynamicObjectEx(2886, 319.48617553711, -164.84504699707, 1000.0415649414, 0, 0, 268.69067382813, .worlds = {0, 2});
    CreateDynamicObjectEx(2886, 320.203125, 309.40106201172, 999.86895751953, 0, 0, 89.324493408203, .worlds = {0, 2});
    CreateDynamicObjectEx(986, 253.36610, 114.93460, 1005.37903, 0.00000, 0.00000, 270.00000, .worlds = {0, 2});
    CreateDynamicObjectEx(986, 239.39999, 111.43900, 1005.37903, 0.00000, 0.00000, 90.000000, .worlds = {0, 2});
    CreateDynamicObjectEx(1498,  224.89999, 124.80000, 998.000000, 0.00000, 0.00000, 0.0000000, .worlds = {0, 2});
    CreateDynamicObjectEx(2911,  239.30000, 115.90000, 1009.20000, 0.00000, 0.00000, 270.00000, .worlds = {0, 2});
    CreateDynamicObjectEx(2911,  239.31000, 113.90000, 1009.20000, 0.00000, 0.00000, 90.000000, .worlds = {0, 2});
    CreateDynamicObjectEx(16095, 310.99999, -1503.500, 75.5000000, 0.00000, 0.00000, 141.25000000, .worlds = {0, 2});
    return Y_HOOKS_CONTINUE_RETURN_1;
}