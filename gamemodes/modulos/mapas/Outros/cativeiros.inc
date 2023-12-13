#include <YSI_Coding\y_hooks>

hook OnGameModeInit() 
{
    //-----------------------------[ JAULA CATIVEIRO 1 ]------------------------
    CreateDynamicObject(986, 303.89999, 302.10001, 997.59998, 0, 0, 224);
    CreateDynamicObject(986, 303.90039, 302.09961, 997.59998, 0, 0, 223.995);
    //-----------------------------[ JAULA CATIVEIRO 3 ]------------------------
    CreateDynamicObject(986, 248.7, 303.70001, 997.59998, 0, 0, 226);
    CreateDynamicObject(986, 248.7002, 303.7002, 997.59998, 0, 0, 226);
    //-----------------------------[ JAULA CATIVEIRO 4 ]------------------------
    CreateDynamicObject(986, -113.8, -10.2, 999, 0, 0, 0);
    CreateDynamicObject(986, -113.7998, -10.2002, 999, 0, 0, 0);
    return Y_HOOKS_CONTINUE_RETURN_1;
}