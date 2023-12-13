#include <YSI_Coding\y_hooks>

hook OnGameModeInit() 
{
    RemoveBuilding(3777, 831.960, -1191.140, 25.039, 0.250);
    RemoveBuilding(3777, 868.132, -1191.140, 25.039, 0.250);
    RemoveBuilding(5926, 816.335, -1217.148, 26.445, 0.250);
    RemoveBuilding(5927, 834.937, -1249.937, 19.875, 0.250);
    RemoveBuilding(5978, 887.984, -1287.132, 18.265, 0.250);
    RemoveBuilding(5979, 918.882, -1293.460, 14.929, 0.250);
    RemoveBuilding(5980, 917.718, -1259.523, 16.187, 0.250);
    RemoveBuilding(3777, 902.335, -1191.140, 25.039, 0.250);
    RemoveBuilding(6005, 895.257, -1256.929, 31.234, 0.250);
    RemoveBuilding(5836, 816.335, -1217.148, 26.445, 0.250);
    RemoveBuilding(3776, 831.960, -1191.140, 25.039, 0.250);
    RemoveBuilding(5835, 834.937, -1249.937, 19.875, 0.250);
    RemoveBuilding(5706, 887.984, -1287.132, 18.265, 0.250);
    RemoveBuilding(5735, 918.882, -1293.460, 14.929, 0.250);
    RemoveBuilding(3776, 868.132, -1191.140, 25.039, 0.250);
    RemoveBuilding(5838, 895.257, -1256.929, 31.234, 0.250);
    RemoveBuilding(3776, 902.335, -1191.140, 25.039, 0.250);
    RemoveBuilding(5837, 913.390, -1235.171, 17.640, 0.250);
    RemoveBuilding(5736, 917.718, -1259.523, 16.187, 0.250);

    new tmpobject;
    tmpobject = CreateDynamicObject(5736, 917.718811, -1259.523437, 16.187500, 0.000000, 0.000000, 0.000000, -1, -1, -1, 1000.00, 1000.00);
    SetDynamicObjectMaterial(tmpobject, 0, 3980, "cityhall_lan", "citywall4", 0x00000000);
    SetDynamicObjectMaterial(tmpobject, 1, 3980, "cityhall_lan", "citywall1", 0x00000000);
    SetDynamicObjectMaterial(tmpobject, 4, 3998, "civic04_lan", "sl_crthoosedg1", 0x00000000);
    tmpobject = CreateDynamicObject(5735, 918.882812, -1293.460937, 14.929698, 0.000000, 0.000000, 0.000000, -1, -1, -1, 1000.00, 1000.00);
    SetDynamicObjectMaterial(tmpobject, 0, 3980, "cityhall_lan", "citywall4", 0x00000000);
    SetDynamicObjectMaterial(tmpobject, 1, 3980, "cityhall_lan", "citywall1", 0x00000000);
    SetDynamicObjectMaterial(tmpobject, 4, 3998, "civic04_lan", "sl_crthoosedg1", 0x00000000);
    tmpobject = CreateDynamicObject(19536, 867.741882, -1174.794921, 15.986700, 0.000000, 0.000000, 0.000000, -1, -1, -1, 1000.00, 1000.00);
    SetDynamicObjectMaterial(tmpobject, 0, 16640, "a51", "concretemanky", 0xFFFFFFFF);
    tmpobject = CreateDynamicObject(7191, 850.772888, -1205.997924, 17.199800, 0.000000, 0.000000, 90.000000, -1, -1, -1, 1000.00, 1000.00);
    SetDynamicObjectMaterial(tmpobject, 0, 16640, "a51", "concretewall22_256", 0xFFFFFFFF);
    tmpobject = CreateDynamicObject(7191, 891.511352, -1183.479492, 17.199800, 0.000000, 0.000000, 0.000000, -1, -1, -1, 1000.00, 1000.00);
    SetDynamicObjectMaterial(tmpobject, 0, 16640, "a51", "concretewall22_256", 0xFFFFFFFF);
    tmpobject = CreateDynamicObject(7191, 830.513671, -1205.986328, 17.195800, 0.000000, 0.000000, -90.000000, -1, -1, -1, 1000.00, 1000.00);
    SetDynamicObjectMaterial(tmpobject, 0, 16640, "a51", "concretewall22_256", 0xFFFFFFFF);
    tmpobject = CreateDynamicObject(18981, 822.648315, -1241.644042, 13.682998, 0.000000, 90.000000, 0.000000, -1, -1, -1, 1000.00, 1000.00);
    SetDynamicObjectMaterial(tmpobject, 0, 4833, "airprtrunway_las", "greyground256", 0x00000000);
    tmpobject = CreateDynamicObject(18981, 822.647094, -1266.644042, 13.682998, 0.000000, 90.000000, 0.000000, -1, -1, -1, 1000.00, 1000.00);
    SetDynamicObjectMaterial(tmpobject, 0, 4833, "airprtrunway_las", "greyground256", 0x00000000);
    tmpobject = CreateDynamicObject(18981, 837.881469, -1266.536010, 13.677000, 0.000000, 90.000000, 0.000000, -1, -1, -1, 1000.00, 1000.00);
    SetDynamicObjectMaterial(tmpobject, 0, 4833, "airprtrunway_las", "greyground256", 0x00000000);
    tmpobject = CreateDynamicObject(18981, 837.885498, -1241.644042, 13.677000, 0.000000, 90.000000, 0.000000, -1, -1, -1, 1000.00, 1000.00);
    SetDynamicObjectMaterial(tmpobject, 0, 4833, "airprtrunway_las", "greyground256", 0x00000000);
    tmpobject = CreateDynamicObject(18981, 837.881469, -1266.536010, 12.677398, 0.000000, 90.000000, 0.000000, -1, -1, -1, 1000.00, 1000.00);
    SetDynamicObjectMaterial(tmpobject, 0, 4833, "airprtrunway_las", "greyground256", 0x00000000);
    tmpobject = CreateDynamicObject(18981, 835.372802, -1247.426391, 13.673000, 0.000000, 90.000000, 0.000000, -1, -1, -1, 1000.00, 1000.00);
    SetDynamicObjectMaterial(tmpobject, 0, 4833, "airprtrunway_las", "greyground256", 0x00000000);
    tmpobject = CreateDynamicObject(6874, 830.666503, -1265.434082, 14.163900, 0.000000, 0.000000, 180.000000, -1, -1, -1, 1000.00, 1000.00);
    SetDynamicObjectMaterial(tmpobject, 0, 4552, "ammu_lan2", "mallextmid01", 0x00000000);
    SetDynamicObjectMaterial(tmpobject, 1, 4552, "ammu_lan2", "mallextmid01", 0x00000000);
    tmpobject = CreateDynamicObject(18981, 895.091674, -1294.939086, 13.061900, 0.000000, 90.000000, 0.000000, -1, -1, -1, 1000.00, 1000.00);
    SetDynamicObjectMaterial(tmpobject, 0, 4833, "airprtrunway_las", "greyground256", 0x00000000);
    tmpobject = CreateDynamicObject(18981, 879.607788, -1295.510986, 13.061900, 0.000000, 90.000000, 0.000000, -1, -1, -1, 1000.00, 1000.00);
    SetDynamicObjectMaterial(tmpobject, 0, 4833, "airprtrunway_las", "greyground256", 0x00000000);
    tmpobject = CreateDynamicObject(18981, 895.087707, -1286.304931, 13.176098, 0.000000, 90.000000, 0.000000, -1, -1, -1, 1000.00, 1000.00);
    SetDynamicObjectMaterial(tmpobject, 0, 4833, "airprtrunway_las", "greyground256", 0x00000000);
    tmpobject = CreateDynamicObject(18981, 879.605773, -1286.308959, 13.192098, 0.000000, 90.000000, 0.000000, -1, -1, -1, 1000.00, 1000.00);
    SetDynamicObjectMaterial(tmpobject, 0, 4833, "airprtrunway_las", "greyground256", 0x00000000);
    tmpobject = CreateDynamicObject(18766, 924.414123, -1213.879516, 17.736320, 0.000000, 90.000000, 90.000000, -1, -1, -1, 1000.00, 1000.00);
    SetDynamicObjectMaterial(tmpobject, 0, 16640, "a51", "concretegroundl1_256", 0x00000000);
    tmpobject = CreateDynamicObject(18766, 924.414123, -1228.203002, 17.736299, 0.000000, 90.000000, 90.000000, -1, -1, -1, 1000.00, 1000.00);
    SetDynamicObjectMaterial(tmpobject, 0, 16640, "a51", "concretegroundl1_256", 0x00000000);
    tmpobject = CreateDynamicObject(18766, 924.411315, -1221.038574, 23.955240, 0.000000, 0.000000, 90.000000, -1, -1, -1, 1000.00, 1000.00);
    SetDynamicObjectMaterial(tmpobject, 0, 16640, "a51", "concretegroundl1_256", 0x00000000);
    tmpobject = CreateDynamicObject(19398, 924.807128, -1209.508056, 17.698200, 0.000000, 0.000000, 0.000000, -1, -1, -1, 1000.00, 1000.00);
    SetDynamicObjectMaterial(tmpobject, 0, 16640, "a51", "concretegroundl1_256", 0x00000000);
    tmpobject = CreateDynamicObject(19325, 850.398376, -1266.214721, 27.075296, 0.000000, 0.000000, 180.000000, -1, -1, -1, 1000.00, 1000.00);
    SetDynamicObjectMaterial(tmpobject, 0, 12855, "cunte_cop", "sw_PD", 0x00000000);
    tmpobject = CreateDynamicObject(2661, 818.283081, -1237.899414, 15.964822, 0.000000, 0.000000, 0.000000, -1, -1, -1, 1000.00, 1000.00);
    SetDynamicObjectMaterialText(tmpobject, 0, "Venture", 120, "Ariel", 20, 0, 0xFF000000, 0x00000000, 1);
    CreateDynamicObject(4691, 839.635314, -1172.291381, 16.113000, 0.000000, 0.000000, -90.000000, -1, -1, -1, 1000.00, 1000.00);
    CreateDynamicObject(19905, 828.286743, -1245.531127, 14.002658, 0.000000, 0.000000, 180.000000, -1, -1, -1, 1000.00, 1000.00);
    CreateDynamicObject(14394, 851.192382, -1269.060058, 13.354498, 0.000000, 0.000000, 180.000000, -1, -1, -1, 1000.00, 1000.00);
    CreateDynamicObject(14394, 851.192382, -1261.060058, 13.354498, 0.000000, 0.000000, 180.000000, -1, -1, -1, 1000.00, 1000.00);
    CreateDynamicObject(9241, 887.826354, -1290.701904, 15.239728, 0.000000, 0.000000, -90.000000, -1, -1, -1, 1000.00, 1000.00);
    CreateDynamicObject(17951, 841.680725, -1237.500122, 17.209392, 0.000000, -55.000000, 90.000000, -1, -1, -1, 1000.00, 1000.00);
    CreateDynamicObject(17951, 832.680725, -1237.485473, 17.373559, 0.000000, -80.000000, 90.000000, -1, -1, -1, 1000.00, 1000.00);
    CreateDynamicObject(17951, 823.680725, -1237.485473, 17.334899, 0.000000, -75.000000, 90.000000, -1, -1, -1, 1000.00, 1000.00);
    CreateDynamicObject(17951, 814.680725, -1237.485473, 15.969308, 0.000000, 0.000000, 90.000000, -1, -1, -1, 1000.00, 1000.00);
    CreateDynamicObject(8651, 849.529907, -1245.192138, 15.095120, 0.000000, 0.000000, 180.000000, -1, -1, -1, 1000.00, 1000.00);
    CreateDynamicObject(8843, 886.318542, -1195.373291, 15.994500, 0.000000, 0.000000, 0.000000, -1, -1, -1, 1000.00, 1000.00);
    CreateDynamicObject(8843, 879.566772, -1196.659301, 15.924698, 1.000000, 0.000000, 180.000000, -1, -1, -1, 1000.00, 1000.00);
    CreateDynamicObject(8843, 853.685180, -1165.975341, 15.994500, 0.000000, 0.000000, 90.000000, -1, -1, -1, 1000.00, 1000.00);
    CreateDynamicObject(8843, 825.913696, -1179.628784, 15.994500, 0.000000, 0.000000, 180.000000, -1, -1, -1, 1000.00, 1000.00);
    CreateDynamicObject(8843, 886.301269, -1182.685424, 15.990500, 0.000000, 0.000000, 0.000000, -1, -1, -1, 1000.00, 1000.00);
    CreateDynamicObject(8843, 853.423889, -1193.134277, 15.994500, 0.000000, 0.000000, -90.000000, -1, -1, -1, 1000.00, 1000.00);
    CreateDynamicObject(8168, 918.368041, -1228.145263, 17.713510, 0.000000, 0.000000, 196.680007, -1, -1, -1, 1000.00, 1000.00);
    return Y_HOOKS_CONTINUE_RETURN_1;
}