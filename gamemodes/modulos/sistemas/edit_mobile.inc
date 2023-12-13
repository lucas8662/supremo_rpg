#include <YSI_Coding\y_hooks>

#define forLoop(%0,%1) 				for(new it_%0 = 0, %0=0, sen_%0 = %1; %0 < sen_%0 && it_%0 < sen_%0; %0++, it_%0++)
#define EditAttachedObject(%0,%1) EditAttachedObjectEx(%0, %1)

// ~~ Arrays
const Float: MINIMUM_FOREHEADX = 0.1;
const Float: MINIMUM_FOREHEADY = 0.1;
const Float: MINIMUM_FOREHEADZ = 0.1;
const Float: MINIMUM_SCALERX = 3.0;
const Float: MINIMUM_SCALERY = 3.0;
const Float: MINIMUM_SCALERZ = 3.0;
const Float: MINIMUM_SCALEX = 0.1;
const Float: MINIMUM_SCALEY = 0.1;
const Float: MINIMUM_SCALEZ = 0.1;

// Enums & Arrays
enum Enum_InfoAttachedIndexed {
    r_Model,
    r_Bone,
    Float: r_OffSets[ 6 ],
    Float: r_Scale[ 3 ],
    r_MaterialColors[ 2 ],
};
enum {
	EDITING_POSITION, // 0
	EDITING_ROTACTION, // 1
	EDITING_SIZE, // 2
};
enum {
    B_TD_EDIT_ATTACHED_OBJECT,
    B_TD_EDIT_DYNAMIC_OBJECT,
}
enum e_info {
    gPlayerVarTipoEdit,
	Float: speed_cord,
	Float: speed_cordROT,
	Float: varOldPos[ 6 ],
	Float: VarOldScale[ 3 ],
	Float: OldPosObj[ 6 ],
	EditandoObjID,
	TipoEdicaoObj,
	bool: open_android,
	edit_attachid,
};
new Edit_Android[ MAX_PLAYERS ][ e_info ];
static VarAttachedIndexObj[ MAX_PLAYERS ][ MAX_PLAYER_ATTACHED_OBJECTS ][ Enum_InfoAttachedIndexed ], Text: TDAppAjustarObj[ 22 ], PlayerText: PTDAppAjustarObj[ MAX_PLAYERS ][ 1 ];

// Variaveis
new
	Text:TDEditorObjetos[23],
	PlayerText:PTDEditorObjetos[MAX_PLAYERS][2];

hook OnGameModeInit()
{
	// beditarobj
	TDEditorObjetos[0] = TextDrawCreate(148.7326, 161.4167, "Box");
	TextDrawLetterSize(TDEditorObjetos[0], 0.0000, 18.0277);
	TextDrawTextSize(TDEditorObjetos[0], 253.0000, 0.0000);
	TextDrawAlignment(TDEditorObjetos[0], 1);
	TextDrawColor(TDEditorObjetos[0], -1);
	TextDrawUseBox(TDEditorObjetos[0], 1);
	TextDrawBoxColor(TDEditorObjetos[0], 170);
	TextDrawSetOutline(TDEditorObjetos[0], 0);
	TextDrawBackgroundColor(TDEditorObjetos[0], 255);
	TextDrawFont(TDEditorObjetos[0], 1);
	TextDrawSetProportional(TDEditorObjetos[0], 1);
	TextDrawSetShadow(TDEditorObjetos[0], 0);

	TDEditorObjetos[1] = TextDrawCreate(148.7326, 161.4167, "Box");
	TextDrawLetterSize(TDEditorObjetos[1], 0.0000, 18.0277);
	TextDrawTextSize(TDEditorObjetos[1], 253.0000, 0.0000);
	TextDrawAlignment(TDEditorObjetos[1], 1);
	TextDrawColor(TDEditorObjetos[1], -1);
	TextDrawUseBox(TDEditorObjetos[1], 1);
	TextDrawBoxColor(TDEditorObjetos[1], 170);
	TextDrawSetOutline(TDEditorObjetos[1], 0);
	TextDrawBackgroundColor(TDEditorObjetos[1], 255);
	TextDrawFont(TDEditorObjetos[1], 1);
	TextDrawSetProportional(TDEditorObjetos[1], 1);
	TextDrawSetShadow(TDEditorObjetos[1], 0);

	TDEditorObjetos[2] = TextDrawCreate(143.3527, 154.4165, "Editor");
	TextDrawLetterSize(TDEditorObjetos[2], 0.5328, 1.8973);
	TextDrawAlignment(TDEditorObjetos[2], 1);
	TextDrawColor(TDEditorObjetos[2], -1);
	TextDrawSetOutline(TDEditorObjetos[2], 2);
	TextDrawBackgroundColor(TDEditorObjetos[2], 170);
	TextDrawFont(TDEditorObjetos[2], 0);
	TextDrawSetProportional(TDEditorObjetos[2], 1);
	TextDrawSetShadow(TDEditorObjetos[2], 0);

	TDEditorObjetos[3] = TextDrawCreate(151.2438, 183.3833, "ld_beat:left"); // nope
	TextDrawLetterSize(TDEditorObjetos[3], 0.0000, 0.0000);
	TextDrawTextSize(TDEditorObjetos[3], 13.0000, 14.8000);
	TextDrawAlignment(TDEditorObjetos[3], 1);
	TextDrawColor(TDEditorObjetos[3], -1);
	TextDrawSetOutline(TDEditorObjetos[3], 0);
	TextDrawBackgroundColor(TDEditorObjetos[3], 255);
	TextDrawFont(TDEditorObjetos[3], 4);
	TextDrawSetProportional(TDEditorObjetos[3], 0);
	TextDrawSetShadow(TDEditorObjetos[3], 0);
	TextDrawSetSelectable(TDEditorObjetos[3], true);

	TDEditorObjetos[4] = TextDrawCreate(236.0434, 183.3834, "ld_beat:right"); // nope
	TextDrawLetterSize(TDEditorObjetos[4], 0.0000, 0.0000);
	TextDrawTextSize(TDEditorObjetos[4], 13.0000, 14.8000);
	TextDrawAlignment(TDEditorObjetos[4], 1);
	TextDrawColor(TDEditorObjetos[4], -1);
	TextDrawSetOutline(TDEditorObjetos[4], 0);
	TextDrawBackgroundColor(TDEditorObjetos[4], 255);
	TextDrawFont(TDEditorObjetos[4], 4);
	TextDrawSetProportional(TDEditorObjetos[4], 0);
	TextDrawSetShadow(TDEditorObjetos[4], 0);
	TextDrawSetSelectable(TDEditorObjetos[4], true);

	TDEditorObjetos[5] = TextDrawCreate(151.2438, 200.8833, "ld_beat:left"); // nope
	TextDrawLetterSize(TDEditorObjetos[5], 0.0000, 0.0000);
	TextDrawTextSize(TDEditorObjetos[5], 13.0000, 14.8000);
	TextDrawAlignment(TDEditorObjetos[5], 1);
	TextDrawColor(TDEditorObjetos[5], -1);
	TextDrawSetOutline(TDEditorObjetos[5], 0);
	TextDrawBackgroundColor(TDEditorObjetos[5], 255);
	TextDrawFont(TDEditorObjetos[5], 4);
	TextDrawSetProportional(TDEditorObjetos[5], 0);
	TextDrawSetShadow(TDEditorObjetos[5], 0);
	TextDrawSetSelectable(TDEditorObjetos[5], true);

	TDEditorObjetos[6] = TextDrawCreate(235.8435, 200.6833, "ld_beat:right"); // nope
	TextDrawLetterSize(TDEditorObjetos[6], 0.0000, 0.0000);
	TextDrawTextSize(TDEditorObjetos[6], 13.0000, 14.8000);
	TextDrawAlignment(TDEditorObjetos[6], 1);
	TextDrawColor(TDEditorObjetos[6], -1);
	TextDrawSetOutline(TDEditorObjetos[6], 0);
	TextDrawBackgroundColor(TDEditorObjetos[6], 255);
	TextDrawFont(TDEditorObjetos[6], 4);
	TextDrawSetProportional(TDEditorObjetos[6], 0);
	TextDrawSetShadow(TDEditorObjetos[6], 0);
	TextDrawSetSelectable(TDEditorObjetos[6], true);

	TDEditorObjetos[7] = TextDrawCreate(228.9998, 161.5000, "Box");
	TextDrawLetterSize(TDEditorObjetos[7], 0.0000, 0.6294);
	TextDrawTextSize(TDEditorObjetos[7], 252.7395, 0.0000);
	TextDrawAlignment(TDEditorObjetos[7], 1);
	TextDrawColor(TDEditorObjetos[7], -1);
	TextDrawUseBox(TDEditorObjetos[7], 1);
	TextDrawBoxColor(TDEditorObjetos[7], -1291845377);
	TextDrawSetOutline(TDEditorObjetos[7], 0);
	TextDrawBackgroundColor(TDEditorObjetos[7], 255);
	TextDrawFont(TDEditorObjetos[7], 1);
	TextDrawSetProportional(TDEditorObjetos[7], 1);
	TextDrawSetShadow(TDEditorObjetos[7], 0);

	TDEditorObjetos[8] = TextDrawCreate(240.6997, 158.2998, "Fechar");
	TextDrawLetterSize(TDEditorObjetos[8], 0.1507, 1.1215);
	TextDrawTextSize(TDEditorObjetos[8], 10.0000, 10.0000);
	TextDrawAlignment(TDEditorObjetos[8], 2);
	TextDrawColor(TDEditorObjetos[8], -1);
	TextDrawUseBox(TDEditorObjetos[8], 1);
	TextDrawBoxColor(TDEditorObjetos[8], 0);
	TextDrawSetOutline(TDEditorObjetos[8], 0);
	TextDrawBackgroundColor(TDEditorObjetos[8], 255);
	TextDrawFont(TDEditorObjetos[8], 2);
	TextDrawSetProportional(TDEditorObjetos[8], 1);
	TextDrawSetShadow(TDEditorObjetos[8], 0);
	TextDrawSetSelectable(TDEditorObjetos[8], true);

	TDEditorObjetos[9] = TextDrawCreate(153.0000, 223.1001, "ld_beat:left");
	TextDrawLetterSize(TDEditorObjetos[9], 0.0000, 0.0000);
	TextDrawTextSize(TDEditorObjetos[9], 17.0000, 16.0000);
	TextDrawAlignment(TDEditorObjetos[9], 1);
	TextDrawColor(TDEditorObjetos[9], -1);
	TextDrawSetOutline(TDEditorObjetos[9], 0);
	TextDrawBackgroundColor(TDEditorObjetos[9], 255);
	TextDrawFont(TDEditorObjetos[9], 4);
	TextDrawSetProportional(TDEditorObjetos[9], 0);
	TextDrawSetShadow(TDEditorObjetos[9], 0);
	TextDrawSetSelectable(TDEditorObjetos[9], true);

	TDEditorObjetos[10] = TextDrawCreate(153.0000, 254.1001, "ld_beat:left");
	TextDrawLetterSize(TDEditorObjetos[10], 0.0000, 0.0000);
	TextDrawTextSize(TDEditorObjetos[10], 17.0000, 16.0000);
	TextDrawAlignment(TDEditorObjetos[10], 1);
	TextDrawColor(TDEditorObjetos[10], -1);
	TextDrawSetOutline(TDEditorObjetos[10], 0);
	TextDrawBackgroundColor(TDEditorObjetos[10], 255);
	TextDrawFont(TDEditorObjetos[10], 4);
	TextDrawSetProportional(TDEditorObjetos[10], 0);
	TextDrawSetShadow(TDEditorObjetos[10], 0);
	TextDrawSetSelectable(TDEditorObjetos[10], true);

	TDEditorObjetos[11] = TextDrawCreate(153.0000, 284.1003, "ld_beat:left");
	TextDrawLetterSize(TDEditorObjetos[11], 0.0000, 0.0000);
	TextDrawTextSize(TDEditorObjetos[11], 17.0000, 16.0000);
	TextDrawAlignment(TDEditorObjetos[11], 1);
	TextDrawColor(TDEditorObjetos[11], -1);
	TextDrawSetOutline(TDEditorObjetos[11], 0);
	TextDrawBackgroundColor(TDEditorObjetos[11], 255);
	TextDrawFont(TDEditorObjetos[11], 4);
	TextDrawSetProportional(TDEditorObjetos[11], 0);
	TextDrawSetShadow(TDEditorObjetos[11], 0);
	TextDrawSetSelectable(TDEditorObjetos[11], true);

	TDEditorObjetos[12] = TextDrawCreate(231.2001, 223.1001, "ld_beat:right");
	TextDrawLetterSize(TDEditorObjetos[12], 0.0000, 0.0000);
	TextDrawTextSize(TDEditorObjetos[12], 17.0000, 16.0000);
	TextDrawAlignment(TDEditorObjetos[12], 1);
	TextDrawColor(TDEditorObjetos[12], -1);
	TextDrawSetOutline(TDEditorObjetos[12], 0);
	TextDrawBackgroundColor(TDEditorObjetos[12], 255);
	TextDrawFont(TDEditorObjetos[12], 4);
	TextDrawSetProportional(TDEditorObjetos[12], 0);
	TextDrawSetShadow(TDEditorObjetos[12], 0);
	TextDrawSetSelectable(TDEditorObjetos[12], true);

	TDEditorObjetos[13] = TextDrawCreate(231.2001, 254.1001, "ld_beat:right");
	TextDrawLetterSize(TDEditorObjetos[13], 0.0000, 0.0000);
	TextDrawTextSize(TDEditorObjetos[13], 17.0000, 16.0000);
	TextDrawAlignment(TDEditorObjetos[13], 1);
	TextDrawColor(TDEditorObjetos[13], -1);
	TextDrawSetOutline(TDEditorObjetos[13], 0);
	TextDrawBackgroundColor(TDEditorObjetos[13], 255);
	TextDrawFont(TDEditorObjetos[13], 4);
	TextDrawSetProportional(TDEditorObjetos[13], 0);
	TextDrawSetShadow(TDEditorObjetos[13], 0);
	TextDrawSetSelectable(TDEditorObjetos[13], true);

	TDEditorObjetos[14] = TextDrawCreate(231.2001, 285.1003, "ld_beat:right");
	TextDrawLetterSize(TDEditorObjetos[14], 0.0000, 0.0000);
	TextDrawTextSize(TDEditorObjetos[14], 17.0000, 16.0000);
	TextDrawAlignment(TDEditorObjetos[14], 1);
	TextDrawColor(TDEditorObjetos[14], -1);
	TextDrawSetOutline(TDEditorObjetos[14], 0);
	TextDrawBackgroundColor(TDEditorObjetos[14], 255);
	TextDrawFont(TDEditorObjetos[14], 4);
	TextDrawSetProportional(TDEditorObjetos[14], 0);
	TextDrawSetShadow(TDEditorObjetos[14], 0);
	TextDrawSetSelectable(TDEditorObjetos[14], true);

	TDEditorObjetos[15] = TextDrawCreate(171.5997, 225.3002, "X-");
	TextDrawLetterSize(TDEditorObjetos[15], 0.2556, 1.1447);
	TextDrawAlignment(TDEditorObjetos[15], 1);
	TextDrawColor(TDEditorObjetos[15], -1291845377);
	TextDrawSetOutline(TDEditorObjetos[15], 0);
	TextDrawBackgroundColor(TDEditorObjetos[15], 255);
	TextDrawFont(TDEditorObjetos[15], 1);
	TextDrawSetProportional(TDEditorObjetos[15], 1);
	TextDrawSetShadow(TDEditorObjetos[15], 0);

	TDEditorObjetos[16] = TextDrawCreate(171.5997, 255.3002, "Y-");
	TextDrawLetterSize(TDEditorObjetos[16], 0.2556, 1.1447);
	TextDrawAlignment(TDEditorObjetos[16], 1);
	TextDrawColor(TDEditorObjetos[16], -1291845377);
	TextDrawSetOutline(TDEditorObjetos[16], 0);
	TextDrawBackgroundColor(TDEditorObjetos[16], 255);
	TextDrawFont(TDEditorObjetos[16], 1);
	TextDrawSetProportional(TDEditorObjetos[16], 1);
	TextDrawSetShadow(TDEditorObjetos[16], 0);

	TDEditorObjetos[17] = TextDrawCreate(171.5997, 285.7006, "Z-");
	TextDrawLetterSize(TDEditorObjetos[17], 0.2556, 1.1447);
	TextDrawAlignment(TDEditorObjetos[17], 1);
	TextDrawColor(TDEditorObjetos[17], -1291845377);
	TextDrawSetOutline(TDEditorObjetos[17], 0);
	TextDrawBackgroundColor(TDEditorObjetos[17], 255);
	TextDrawFont(TDEditorObjetos[17], 1);
	TextDrawSetProportional(TDEditorObjetos[17], 1);
	TextDrawSetShadow(TDEditorObjetos[17], 0);

	TDEditorObjetos[18] = TextDrawCreate(218.0000, 225.3002, "X+");
	TextDrawLetterSize(TDEditorObjetos[18], 0.2556, 1.1447);
	TextDrawAlignment(TDEditorObjetos[18], 1);
	TextDrawColor(TDEditorObjetos[18], 11731199);
	TextDrawSetOutline(TDEditorObjetos[18], 0);
	TextDrawBackgroundColor(TDEditorObjetos[18], 255);
	TextDrawFont(TDEditorObjetos[18], 1);
	TextDrawSetProportional(TDEditorObjetos[18], 1);
	TextDrawSetShadow(TDEditorObjetos[18], 0);

	TDEditorObjetos[19] = TextDrawCreate(218.0000, 255.8999, "Y+");
	TextDrawLetterSize(TDEditorObjetos[19], 0.2556, 1.1447);
	TextDrawAlignment(TDEditorObjetos[19], 1);
	TextDrawColor(TDEditorObjetos[19], 11731199);
	TextDrawSetOutline(TDEditorObjetos[19], 0);
	TextDrawBackgroundColor(TDEditorObjetos[19], 255);
	TextDrawFont(TDEditorObjetos[19], 1);
	TextDrawSetProportional(TDEditorObjetos[19], 1);
	TextDrawSetShadow(TDEditorObjetos[19], 0);

	TDEditorObjetos[20] = TextDrawCreate(218.0000, 286.4998, "Z+");
	TextDrawLetterSize(TDEditorObjetos[20], 0.2556, 1.1447);
	TextDrawAlignment(TDEditorObjetos[20], 1);
	TextDrawColor(TDEditorObjetos[20], 11731199);
	TextDrawSetOutline(TDEditorObjetos[20], 0);
	TextDrawBackgroundColor(TDEditorObjetos[20], 255);
	TextDrawFont(TDEditorObjetos[20], 1);
	TextDrawSetProportional(TDEditorObjetos[20], 1);
	TextDrawSetShadow(TDEditorObjetos[20], 0);

	TDEditorObjetos[21] = TextDrawCreate(162.6999, 314.0002, "Info");
	TextDrawLetterSize(TDEditorObjetos[21], 0.2069, 1.0749);
	TextDrawTextSize(TDEditorObjetos[21], 10.0000, 28.0000);
	TextDrawAlignment(TDEditorObjetos[21], 2);
	TextDrawColor(TDEditorObjetos[21], -1);
	TextDrawUseBox(TDEditorObjetos[21], 1);
	TextDrawBoxColor(TDEditorObjetos[21], -2147418256);
	TextDrawSetOutline(TDEditorObjetos[21], 0);
	TextDrawBackgroundColor(TDEditorObjetos[21], 255);
	TextDrawFont(TDEditorObjetos[21], 1);
	TextDrawSetProportional(TDEditorObjetos[21], 1);
	TextDrawSetShadow(TDEditorObjetos[21], 0);
	TextDrawSetSelectable(TDEditorObjetos[21], true);

	TDEditorObjetos[22] = TextDrawCreate(238.5997, 314.0002, "Salvar");
	TextDrawLetterSize(TDEditorObjetos[22], 0.2069, 1.0749);
	TextDrawTextSize(TDEditorObjetos[22], 10.0000, 28.0000);
	TextDrawAlignment(TDEditorObjetos[22], 2);
	TextDrawColor(TDEditorObjetos[22], -1);
	TextDrawUseBox(TDEditorObjetos[22], 1);
	TextDrawBoxColor(TDEditorObjetos[22], -2147418256);
	TextDrawSetOutline(TDEditorObjetos[22], 0);
	TextDrawBackgroundColor(TDEditorObjetos[22], 255);
	TextDrawFont(TDEditorObjetos[22], 1);
	TextDrawSetProportional(TDEditorObjetos[22], 1);
	TextDrawSetShadow(TDEditorObjetos[22], 0);
	TextDrawSetSelectable(TDEditorObjetos[22], true);

	// beditaracessorio
	TDAppAjustarObj[0] = TextDrawCreate(133.5139, 152.6665, "Box");
	TextDrawLetterSize(TDAppAjustarObj[0], 0.0000, 1.5664);
	TextDrawTextSize(TDAppAjustarObj[0], 280.0000, 0.0000);
	TextDrawAlignment(TDAppAjustarObj[0], 1);
	TextDrawColor(TDAppAjustarObj[0], -1);
	TextDrawUseBox(TDAppAjustarObj[0], 1);
	TextDrawBoxColor(TDAppAjustarObj[0], 96);
	TextDrawSetOutline(TDAppAjustarObj[0], 0);
	TextDrawBackgroundColor(TDAppAjustarObj[0], 255);
	TextDrawFont(TDAppAjustarObj[0], 1);
	TextDrawSetProportional(TDAppAjustarObj[0], 1);
	TextDrawSetShadow(TDAppAjustarObj[0], 0);

	TDAppAjustarObj[1] = TextDrawCreate(263.7767, 152.7498, "Box");
	TextDrawLetterSize(TDAppAjustarObj[1], 0.0000, 1.4972);
	TextDrawTextSize(TDAppAjustarObj[1], 279.6001, 0.0000);
	TextDrawAlignment(TDAppAjustarObj[1], 1);
	TextDrawColor(TDAppAjustarObj[1], -1);
	TextDrawUseBox(TDAppAjustarObj[1], 1);
	TextDrawBoxColor(TDAppAjustarObj[1], 96);
	TextDrawSetOutline(TDAppAjustarObj[1], 0);
	TextDrawBackgroundColor(TDAppAjustarObj[1], 255);
	TextDrawFont(TDAppAjustarObj[1], 1);
	TextDrawSetProportional(TDAppAjustarObj[1], 1);
	TextDrawSetShadow(TDAppAjustarObj[1], 0);

	TDAppAjustarObj[2] = TextDrawCreate(135.2194, 152.9667, "Editor_de_acessorios");
	TextDrawLetterSize(TDAppAjustarObj[2], 0.3330, 1.4016);
	TextDrawAlignment(TDAppAjustarObj[2], 1);
	TextDrawColor(TDAppAjustarObj[2], -128);
	TextDrawSetOutline(TDAppAjustarObj[2], 0);
	TextDrawBackgroundColor(TDAppAjustarObj[2], 255);
	TextDrawFont(TDAppAjustarObj[2], 1);
	TextDrawSetProportional(TDAppAjustarObj[2], 1);
	TextDrawSetShadow(TDAppAjustarObj[2], 0);

	TDAppAjustarObj[3] = TextDrawCreate(266.4519, 154.3332, "X");
	TextDrawLetterSize(TDAppAjustarObj[3], 0.3831, 1.2091);
	TextDrawTextSize(TDAppAjustarObj[3], 276.0000, 10.0000);
	TextDrawAlignment(TDAppAjustarObj[3], 1);
	TextDrawColor(TDAppAjustarObj[3], -16777088);
	TextDrawUseBox(TDAppAjustarObj[3], 1);
	TextDrawBoxColor(TDAppAjustarObj[3], 1);
	TextDrawSetOutline(TDAppAjustarObj[3], 0);
	TextDrawBackgroundColor(TDAppAjustarObj[3], 255);
	TextDrawFont(TDAppAjustarObj[3], 1);
	TextDrawSetProportional(TDAppAjustarObj[3], 1);
	TextDrawSetShadow(TDAppAjustarObj[3], 0);
	TextDrawSetSelectable(TDAppAjustarObj[3], true);

	TDAppAjustarObj[4] = TextDrawCreate(133.3453, 172.3677, "Box");
	TextDrawLetterSize(TDAppAjustarObj[4], 0.0000, 1.4728);
	TextDrawTextSize(TDAppAjustarObj[4], 279.7807, 0.0000);
	TextDrawAlignment(TDAppAjustarObj[4], 1);
	TextDrawColor(TDAppAjustarObj[4], -1);
	TextDrawUseBox(TDAppAjustarObj[4], 1);
	TextDrawBoxColor(TDAppAjustarObj[4], 96);
	TextDrawSetOutline(TDAppAjustarObj[4], 0);
	TextDrawBackgroundColor(TDAppAjustarObj[4], 255);
	TextDrawFont(TDAppAjustarObj[4], 1);
	TextDrawSetProportional(TDAppAjustarObj[4], 1);
	TextDrawSetShadow(TDAppAjustarObj[4], 0);

	TDAppAjustarObj[5] = TextDrawCreate(133.3453, 191.4523, "Box");
	TextDrawLetterSize(TDAppAjustarObj[5], 0.0000, 17.3208);
	TextDrawTextSize(TDAppAjustarObj[5], 280.0000, 0.0000);
	TextDrawAlignment(TDAppAjustarObj[5], 1);
	TextDrawColor(TDAppAjustarObj[5], -1);
	TextDrawUseBox(TDAppAjustarObj[5], 1);
	TextDrawBoxColor(TDAppAjustarObj[5], 96);
	TextDrawSetOutline(TDAppAjustarObj[5], 0);
	TextDrawBackgroundColor(TDAppAjustarObj[5], 255);
	TextDrawFont(TDAppAjustarObj[5], 1);
	TextDrawSetProportional(TDAppAjustarObj[5], 1);
	TextDrawSetShadow(TDAppAjustarObj[5], 0);

	TDAppAjustarObj[6] = TextDrawCreate(136.9989, 213.1663, "ld_beat:left");
	TextDrawLetterSize(TDAppAjustarObj[6], -0.0720, -0.1457);
	TextDrawTextSize(TDAppAjustarObj[6], 22.0000, 17.0000);
	TextDrawAlignment(TDAppAjustarObj[6], 1);
	TextDrawColor(TDAppAjustarObj[6], 16711935);
	TextDrawSetOutline(TDAppAjustarObj[6], 0);
	TextDrawBackgroundColor(TDAppAjustarObj[6], 255);
	TextDrawFont(TDAppAjustarObj[6], 4);
	TextDrawSetProportional(TDAppAjustarObj[6], 0);
	TextDrawSetShadow(TDAppAjustarObj[6], 0);
	TextDrawSetSelectable(TDAppAjustarObj[6], true);

	TDAppAjustarObj[7] = TextDrawCreate(136.9989, 254.0332, "ld_beat:left");
	TextDrawLetterSize(TDAppAjustarObj[7], -0.0720, -0.1457);
	TextDrawTextSize(TDAppAjustarObj[7], 22.0000, 17.0000);
	TextDrawAlignment(TDAppAjustarObj[7], 1);
	TextDrawColor(TDAppAjustarObj[7], 16711935);
	TextDrawSetOutline(TDAppAjustarObj[7], 0);
	TextDrawBackgroundColor(TDAppAjustarObj[7], 255);
	TextDrawFont(TDAppAjustarObj[7], 4);
	TextDrawSetProportional(TDAppAjustarObj[7], 0);
	TextDrawSetShadow(TDAppAjustarObj[7], 0);
	TextDrawSetSelectable(TDAppAjustarObj[7], true);

	TDAppAjustarObj[8] = TextDrawCreate(137.7677, 295.9169, "ld_beat:left");
	TextDrawLetterSize(TDAppAjustarObj[8], -0.0720, -0.1457);
	TextDrawTextSize(TDAppAjustarObj[8], 22.0000, 17.0000);
	TextDrawAlignment(TDAppAjustarObj[8], 1);
	TextDrawColor(TDAppAjustarObj[8], 16711935);
	TextDrawSetOutline(TDAppAjustarObj[8], 0);
	TextDrawBackgroundColor(TDAppAjustarObj[8], 255);
	TextDrawFont(TDAppAjustarObj[8], 4);
	TextDrawSetProportional(TDAppAjustarObj[8], 0);
	TextDrawSetShadow(TDAppAjustarObj[8], 0);
	TextDrawSetSelectable(TDAppAjustarObj[8], true);

	TDAppAjustarObj[9] = TextDrawCreate(252.2061, 213.1663, "ld_beat:right");
	TextDrawLetterSize(TDAppAjustarObj[9], -0.0720, -0.1457);
	TextDrawTextSize(TDAppAjustarObj[9], 22.0000, 17.0000);
	TextDrawAlignment(TDAppAjustarObj[9], 1);
	TextDrawColor(TDAppAjustarObj[9], -16776961);
	TextDrawSetOutline(TDAppAjustarObj[9], 0);
	TextDrawBackgroundColor(TDAppAjustarObj[9], 255);
	TextDrawFont(TDAppAjustarObj[9], 4);
	TextDrawSetProportional(TDAppAjustarObj[9], 0);
	TextDrawSetShadow(TDAppAjustarObj[9], 0);
	TextDrawSetSelectable(TDAppAjustarObj[9], true);

	TDAppAjustarObj[10] = TextDrawCreate(252.2061, 254.4689, "ld_beat:right");
	TextDrawLetterSize(TDAppAjustarObj[10], -0.0720, -0.1457);
	TextDrawTextSize(TDAppAjustarObj[10], 22.0000, 17.0000);
	TextDrawAlignment(TDAppAjustarObj[10], 1);
	TextDrawColor(TDAppAjustarObj[10], -16776961);
	TextDrawSetOutline(TDAppAjustarObj[10], 0);
	TextDrawBackgroundColor(TDAppAjustarObj[10], 255);
	TextDrawFont(TDAppAjustarObj[10], 4);
	TextDrawSetProportional(TDAppAjustarObj[10], 0);
	TextDrawSetShadow(TDAppAjustarObj[10], 0);
	TextDrawSetSelectable(TDAppAjustarObj[10], true);

	TDAppAjustarObj[11] = TextDrawCreate(252.2061, 296.6713, "ld_beat:right");
	TextDrawLetterSize(TDAppAjustarObj[11], -0.0720, -0.1457);
	TextDrawTextSize(TDAppAjustarObj[11], 22.0000, 17.0000);
	TextDrawAlignment(TDAppAjustarObj[11], 1);
	TextDrawColor(TDAppAjustarObj[11], -16776961);
	TextDrawSetOutline(TDAppAjustarObj[11], 0);
	TextDrawBackgroundColor(TDAppAjustarObj[11], 255);
	TextDrawFont(TDAppAjustarObj[11], 4);
	TextDrawSetProportional(TDAppAjustarObj[11], 0);
	TextDrawSetShadow(TDAppAjustarObj[11], 0);
	TextDrawSetSelectable(TDAppAjustarObj[11], true);

	TDAppAjustarObj[12] = TextDrawCreate(169.8845, 219.0164, "X+");
	TextDrawLetterSize(TDAppAjustarObj[12], 0.1712, 0.7541);
	TextDrawAlignment(TDAppAjustarObj[12], 1);
	TextDrawColor(TDAppAjustarObj[12], -128);
	TextDrawSetOutline(TDAppAjustarObj[12], 0);
	TextDrawBackgroundColor(TDAppAjustarObj[12], 255);
	TextDrawFont(TDAppAjustarObj[12], 2);
	TextDrawSetProportional(TDAppAjustarObj[12], 1);
	TextDrawSetShadow(TDAppAjustarObj[12], 0);

	TDAppAjustarObj[13] = TextDrawCreate(169.4476, 259.1831, "Y+");
	TextDrawLetterSize(TDAppAjustarObj[13], 0.1979, 0.9057);
	TextDrawAlignment(TDAppAjustarObj[13], 1);
	TextDrawColor(TDAppAjustarObj[13], -128);
	TextDrawSetOutline(TDAppAjustarObj[13], 0);
	TextDrawBackgroundColor(TDAppAjustarObj[13], 255);
	TextDrawFont(TDAppAjustarObj[13], 2);
	TextDrawSetProportional(TDAppAjustarObj[13], 1);
	TextDrawSetShadow(TDAppAjustarObj[13], 0);

	TDAppAjustarObj[14] = TextDrawCreate(170.2160, 301.3995, "Z+");
	TextDrawLetterSize(TDAppAjustarObj[14], 0.1819, 0.7949);
	TextDrawAlignment(TDAppAjustarObj[14], 1);
	TextDrawColor(TDAppAjustarObj[14], -128);
	TextDrawSetOutline(TDAppAjustarObj[14], 0);
	TextDrawBackgroundColor(TDAppAjustarObj[14], 255);
	TextDrawFont(TDAppAjustarObj[14], 2);
	TextDrawSetProportional(TDAppAjustarObj[14], 1);
	TextDrawSetShadow(TDAppAjustarObj[14], 0);

	TDAppAjustarObj[15] = TextDrawCreate(236.5637, 218.5662, "X-");
	TextDrawLetterSize(TDAppAjustarObj[15], 0.1886, 0.8065);
	TextDrawAlignment(TDAppAjustarObj[15], 1);
	TextDrawColor(TDAppAjustarObj[15], -128);
	TextDrawSetOutline(TDAppAjustarObj[15], 0);
	TextDrawBackgroundColor(TDAppAjustarObj[15], 255);
	TextDrawFont(TDAppAjustarObj[15], 2);
	TextDrawSetProportional(TDAppAjustarObj[15], 1);
	TextDrawSetShadow(TDAppAjustarObj[15], 0);

	TDAppAjustarObj[16] = TextDrawCreate(235.4268, 259.3829, "Y-");
	TextDrawLetterSize(TDAppAjustarObj[16], 0.2110, 0.9815);
	TextDrawAlignment(TDAppAjustarObj[16], 1);
	TextDrawColor(TDAppAjustarObj[16], -128);
	TextDrawSetOutline(TDAppAjustarObj[16], 0);
	TextDrawBackgroundColor(TDAppAjustarObj[16], 255);
	TextDrawFont(TDAppAjustarObj[16], 2);
	TextDrawSetProportional(TDAppAjustarObj[16], 1);
	TextDrawSetShadow(TDAppAjustarObj[16], 0);

	TDAppAjustarObj[17] = TextDrawCreate(237.1584, 302.1664, "Z-");
	TextDrawLetterSize(TDAppAjustarObj[17], 0.1660, 0.8707);
	TextDrawAlignment(TDAppAjustarObj[17], 1);
	TextDrawColor(TDAppAjustarObj[17], -128);
	TextDrawSetOutline(TDAppAjustarObj[17], 0);
	TextDrawBackgroundColor(TDAppAjustarObj[17], 255);
	TextDrawFont(TDAppAjustarObj[17], 2);
	TextDrawSetProportional(TDAppAjustarObj[17], 1);
	TextDrawSetShadow(TDAppAjustarObj[17], 0);

	TDAppAjustarObj[18] = TextDrawCreate(133.4181, 336.3500, "Box");
	TextDrawLetterSize(TDAppAjustarObj[18], 0.0000, 1.2197);
	TextDrawTextSize(TDAppAjustarObj[18], 176.0000, 0.0000);
	TextDrawAlignment(TDAppAjustarObj[18], 1);
	TextDrawColor(TDAppAjustarObj[18], -1);
	TextDrawUseBox(TDAppAjustarObj[18], 1);
	TextDrawBoxColor(TDAppAjustarObj[18], 96);
	TextDrawSetOutline(TDAppAjustarObj[18], 0);
	TextDrawBackgroundColor(TDAppAjustarObj[18], 255);
	TextDrawFont(TDAppAjustarObj[18], 1);
	TextDrawSetProportional(TDAppAjustarObj[18], 1);
	TextDrawSetShadow(TDAppAjustarObj[18], 0);

	TDAppAjustarObj[19] = TextDrawCreate(152.9548, 335.2499, "Alternar");
	TextDrawLetterSize(TDAppAjustarObj[19], 0.2831, 1.4014);
	TextDrawTextSize(TDAppAjustarObj[19], 10.0000, 41.0000); // 0.0 x - 41.0 y
	TextDrawAlignment(TDAppAjustarObj[19], 2);
	TextDrawColor(TDAppAjustarObj[19], -128);
	TextDrawUseBox(TDAppAjustarObj[19], 1);
	TextDrawBoxColor(TDAppAjustarObj[19], 1);
	TextDrawSetOutline(TDAppAjustarObj[19], 0);
	TextDrawBackgroundColor(TDAppAjustarObj[19], 255);
	TextDrawFont(TDAppAjustarObj[19], 1);
	TextDrawSetProportional(TDAppAjustarObj[19], 1);
	TextDrawSetShadow(TDAppAjustarObj[19], 0);
	TextDrawSetSelectable(TDAppAjustarObj[19], true);

	TDAppAjustarObj[20] = TextDrawCreate(241.1233, 336.9500, "Box");
	TextDrawLetterSize(TDAppAjustarObj[20], 0.0000, 1.1583);
	TextDrawTextSize(TDAppAjustarObj[20], 280.1200, 0.0000);
	TextDrawAlignment(TDAppAjustarObj[20], 1);
	TextDrawColor(TDAppAjustarObj[20], -1);
	TextDrawUseBox(TDAppAjustarObj[20], 1);
	TextDrawBoxColor(TDAppAjustarObj[20], 128);
	TextDrawSetOutline(TDAppAjustarObj[20], 0);
	TextDrawBackgroundColor(TDAppAjustarObj[20], 255);
	TextDrawFont(TDAppAjustarObj[20], 1);
	TextDrawSetProportional(TDAppAjustarObj[20], 1);
	TextDrawSetShadow(TDAppAjustarObj[20], 0);

	TDAppAjustarObj[21] = TextDrawCreate(259.4829, 335.2666, "Salvar");
	TextDrawLetterSize(TDAppAjustarObj[21], 0.3005, 1.3782);
	TextDrawTextSize(TDAppAjustarObj[21], 10.0000, 37.0000); // 0.0
	TextDrawAlignment(TDAppAjustarObj[21], 2);
	TextDrawColor(TDAppAjustarObj[21], -128);
	TextDrawUseBox(TDAppAjustarObj[21], 1);
	TextDrawBoxColor(TDAppAjustarObj[21], 1);
	TextDrawSetOutline(TDAppAjustarObj[21], 0);
	TextDrawBackgroundColor(TDAppAjustarObj[21], 255);
	TextDrawFont(TDAppAjustarObj[21], 1);
	TextDrawSetProportional(TDAppAjustarObj[21], 1);
	TextDrawSetShadow(TDAppAjustarObj[21], 0);
	TextDrawSetSelectable(TDAppAjustarObj[21], true);
	return 1;
}
hook OnPlayerConnect( playerid )
{
	Edit_Android[ playerid ][ edit_attachid ] = -1;
	Edit_Android[ playerid ][ EditandoObjID ] = -1;
	// ~~
	PTDAppAjustarObj[playerid][0] = CreatePlayerTextDraw(playerid, 206.4662, 172.1333, "Editando_a_posicao_do_objeto"); 
	PlayerTextDrawLetterSize(playerid, PTDAppAjustarObj[playerid][0], 0.2021, 1.3199);
	PlayerTextDrawAlignment(playerid, PTDAppAjustarObj[playerid][0], 2);
	PlayerTextDrawColor(playerid, PTDAppAjustarObj[playerid][0], -128);
	PlayerTextDrawSetOutline(playerid, PTDAppAjustarObj[playerid][0], 0);
	PlayerTextDrawBackgroundColor(playerid, PTDAppAjustarObj[playerid][0], 255);
	PlayerTextDrawFont(playerid, PTDAppAjustarObj[playerid][0], 2);
	PlayerTextDrawSetProportional(playerid, PTDAppAjustarObj[playerid][0], 1);
	PlayerTextDrawSetShadow(playerid, PTDAppAjustarObj[playerid][0], 0);
	// ~~
	PTDEditorObjetos[playerid][0] = CreatePlayerTextDraw(playerid, 200.6807, 184.4997, "EDITANDO_ROTACAO"); // nope
	PlayerTextDrawLetterSize(playerid, PTDEditorObjetos[playerid][0], 0.1668, 1.2364);
	PlayerTextDrawTextSize(playerid, PTDEditorObjetos[playerid][0], 0.0000, 97.0000);
	PlayerTextDrawAlignment(playerid, PTDEditorObjetos[playerid][0], 2);
	PlayerTextDrawColor(playerid, PTDEditorObjetos[playerid][0], -1);
	PlayerTextDrawUseBox(playerid, PTDEditorObjetos[playerid][0], 1);
	PlayerTextDrawBoxColor(playerid, PTDEditorObjetos[playerid][0], -2147418256);
	PlayerTextDrawSetOutline(playerid, PTDEditorObjetos[playerid][0], 0);
	PlayerTextDrawBackgroundColor(playerid, PTDEditorObjetos[playerid][0], 255);
	PlayerTextDrawFont(playerid, PTDEditorObjetos[playerid][0], 2);
	PlayerTextDrawSetProportional(playerid, PTDEditorObjetos[playerid][0], 1);
	PlayerTextDrawSetShadow(playerid, PTDEditorObjetos[playerid][0], 0);

	PTDEditorObjetos[playerid][1] = CreatePlayerTextDraw(playerid, 200.6807, 201.8995, "Velocidade:_0.1(m)"); // nope
	PlayerTextDrawLetterSize(playerid, PTDEditorObjetos[playerid][1], 0.1668, 1.2364);
	PlayerTextDrawTextSize(playerid, PTDEditorObjetos[playerid][1], 0.0000, 97.0000);
	PlayerTextDrawAlignment(playerid, PTDEditorObjetos[playerid][1], 2);
	PlayerTextDrawColor(playerid, PTDEditorObjetos[playerid][1], -1);
	PlayerTextDrawUseBox(playerid, PTDEditorObjetos[playerid][1], 1);
	PlayerTextDrawBoxColor(playerid, PTDEditorObjetos[playerid][1], -2147418256);
	PlayerTextDrawSetOutline(playerid, PTDEditorObjetos[playerid][1], 0);
	PlayerTextDrawBackgroundColor(playerid, PTDEditorObjetos[playerid][1], 255);
	PlayerTextDrawFont(playerid, PTDEditorObjetos[playerid][1], 2);
	PlayerTextDrawSetProportional(playerid, PTDEditorObjetos[playerid][1], 1);
	PlayerTextDrawSetShadow(playerid, PTDEditorObjetos[playerid][1], 0);
	return 1;
}
hook OnPlayerDisconnect( playerid, reason)
{
    CancelPlayerEditDynObject( playerid );
	for( new e_info: i; i < e_info; i++) Edit_Android[ playerid ][ i ] = 0;
	return 1;
}
hook OnPlayerDeath( playerid, killerid, reason )
{
	CancelPlayerEditDynObject( playerid );
	return 1;
}
hook OnClickDynamicTextDraw(playerid, Text:textid)
{
	new index = Edit_Android[ playerid ][ edit_attachid ];
	if(textid == Text:INVALID_TEXT_DRAW)
	{
		if( Edit_Android[ playerid ][ EditandoObjID ] != -1)
			return SelectTextDraw( playerid, -1 );
		// ~~
		CancelEditObjectAndroid(playerid, true);
	}
	new sObj = Edit_Android[ playerid ][ EditandoObjID ];
	if(sObj != -1)
	{
		new Float:oPos[6],
			Float:angle;

		GetPlayerFacingAngle(playerid, angle);
        GetDynamicObjectPos(sObj, oPos[0], oPos[1], oPos[2]);
        GetDynamicObjectRot(sObj, oPos[3], oPos[4], oPos[5]);

        // mudar edicao
        if(textid == TDEditorObjetos[3])
        {
            Edit_Android[ playerid ][ TipoEdicaoObj ] --;

            if(Edit_Android[ playerid ][ TipoEdicaoObj ] < 0) Edit_Android[ playerid ][ TipoEdicaoObj ] = 0;
        }

        // mudar edicao
        if(textid == TDEditorObjetos[4])
        {
            Edit_Android[ playerid ][ TipoEdicaoObj ] ++;

            if(Edit_Android[ playerid ][ TipoEdicaoObj ] > EDITING_ROTACTION) Edit_Android[ playerid ][ TipoEdicaoObj ] = EDITING_POSITION;
        }

		// -velocidade movimentação
		if(textid == TDEditorObjetos[5])
		{
		    if(Edit_Android[ playerid ][ TipoEdicaoObj ] == EDITING_POSITION)
		    {
			    Edit_Android[playerid][speed_cord] -= 0.05;

			    if(Edit_Android[playerid][speed_cord] < 0.0)
			        Edit_Android[playerid][speed_cord] = 0.0;
			}
			else
			{
			    Edit_Android[playerid][speed_cordROT] -= 10.0;

			    if(Edit_Android[playerid][speed_cordROT] < 0.0)
			        Edit_Android[playerid][speed_cordROT] = 0.0;
			}
		}

		// +velocidade movimentação
		if(textid == TDEditorObjetos[6])
		{
		    if(Edit_Android[ playerid ][ TipoEdicaoObj ] == EDITING_POSITION)
		    {
			    Edit_Android[playerid][speed_cord] += 0.05;
			}
			else
			{
			    Edit_Android[playerid][speed_cordROT] += 10.0;
			}
		}

		// fechar
		if(textid == TDEditorObjetos[8])
		{
		    CancelPlayerEditDynObject(playerid);

		    SendClientMessage(playerid, -1, "[Info] Voce cancelou o menu de edicao do objeto.");
		}

	    // -x
	    if(textid == TDEditorObjetos[9])
	    {
			if(Edit_Android[ playerid ][ TipoEdicaoObj ] == EDITING_POSITION) oPos[0] -= Edit_Android[playerid][speed_cord] * floatsin(-angle, degrees);
			else oPos[3] -= Edit_Android[playerid][speed_cordROT];

			SetDynamicObjectPos(sObj, oPos[0], oPos[1], oPos[2]);
			SetDynamicObjectRot(sObj, oPos[3], oPos[4], oPos[5]);
	    }

	    // -y
	    if(textid == TDEditorObjetos[10])
	    {
			if(Edit_Android[ playerid ][ TipoEdicaoObj ] == EDITING_POSITION) oPos[1] -= Edit_Android[playerid][speed_cord] * floatcos(-angle, degrees);
            else oPos[4] -= Edit_Android[playerid][speed_cordROT];

			SetDynamicObjectPos(sObj, oPos[0], oPos[1], oPos[2]);
			SetDynamicObjectRot(sObj, oPos[3], oPos[4], oPos[5]);
	    }

	    // -z
	    if(textid == TDEditorObjetos[11])
	    {
			if(Edit_Android[ playerid ][ TipoEdicaoObj ] == EDITING_POSITION) oPos[2] -= Edit_Android[playerid][speed_cord];
			else oPos[5] -= Edit_Android[playerid][speed_cordROT];

			SetDynamicObjectPos(sObj, oPos[0], oPos[1], oPos[2]);
			SetDynamicObjectRot(sObj, oPos[3], oPos[4], oPos[5]);
	    }

	    // +x
	    if(textid == TDEditorObjetos[12])
	    {
			if(Edit_Android[ playerid ][ TipoEdicaoObj ] == EDITING_POSITION) oPos[0] += Edit_Android[playerid][speed_cord] * floatsin(-angle, degrees);
            else oPos[3] += Edit_Android[playerid][speed_cordROT];

			SetDynamicObjectPos(sObj, oPos[0], oPos[1], oPos[2]);
			SetDynamicObjectRot(sObj, oPos[3], oPos[4], oPos[5]);
	    }

	    // +y
	    if(textid == TDEditorObjetos[13])
	    {
			if( Edit_Android[ playerid ][ TipoEdicaoObj ] == EDITING_POSITION) oPos[1] += Edit_Android[playerid][speed_cord] * floatcos(-angle, degrees);
            else oPos[4] += Edit_Android[playerid][speed_cordROT];

			SetDynamicObjectPos(sObj, oPos[0], oPos[1], oPos[2]);
			SetDynamicObjectRot(sObj, oPos[3], oPos[4], oPos[5]);
	    }
	    if(textid == TDEditorObjetos[14])
	    {
			if(Edit_Android[ playerid ][ TipoEdicaoObj ] == EDITING_POSITION) oPos[2] += Edit_Android[playerid][speed_cord];
			else oPos[5] += Edit_Android[playerid][speed_cordROT];
			// ~~
			SetDynamicObjectPos(sObj, oPos[0], oPos[1], oPos[2]);
			SetDynamicObjectRot(sObj, oPos[3], oPos[4], oPos[5]);
	    }
	    if( textid == TDEditorObjetos[ 21 ])
	    {
		    new s_Obj = Edit_Android[ playerid ][ EditandoObjID ];
		    if( s_Obj ^ -1)
		    {
		        new str[ 128 ], model = Streamer_GetIntData( STREAMER_TYPE_OBJECT, s_Obj, E_STREAMER_MODEL_ID );
		    	format( str, sizeof str, "{FFFFFF}Modelo do objeto: %i", model );
		    	SendClientMessage( playerid, -1, str );
		    }
	    }
	    if(textid == TDEditorObjetos[22])
	    {
	        CancelPlayerEditDynObject(playerid, true);
	    }
	    Streamer_Update( playerid );
		UpdatePlayerTextDraws( playerid, B_TD_EDIT_DYNAMIC_OBJECT );
    }
	if(textid == TDAppAjustarObj[3])
	{
	    CancelEditObjectAndroid(playerid, true);
	}
	if(textid == TDAppAjustarObj[6] && index != -1) // +x
	{
	    if(Edit_Android[ playerid ][ gPlayerVarTipoEdit ] == EDITING_POSITION) VarAttachedIndexObj[playerid][index][r_OffSets][0] += MINIMUM_FOREHEADX;
	    if(Edit_Android[ playerid ][ gPlayerVarTipoEdit ] == EDITING_ROTACTION) VarAttachedIndexObj[playerid][index][r_OffSets][3] += MINIMUM_SCALERX;
	    if(Edit_Android[ playerid ][ gPlayerVarTipoEdit ] == EDITING_SIZE) VarAttachedIndexObj[playerid][index][r_Scale][0] += MINIMUM_SCALEX;

		ResetEditObject(playerid, index);
	}
	if(textid == TDAppAjustarObj[7] && index != -1) // +y
	{
	    if(Edit_Android[ playerid ][ gPlayerVarTipoEdit ] == EDITING_POSITION) VarAttachedIndexObj[playerid][index][r_OffSets][1] += MINIMUM_FOREHEADY;
	    if(Edit_Android[ playerid ][ gPlayerVarTipoEdit ] == EDITING_ROTACTION) VarAttachedIndexObj[playerid][index][r_OffSets][4] += MINIMUM_SCALERY;
	    if(Edit_Android[ playerid ][ gPlayerVarTipoEdit ] == EDITING_SIZE) VarAttachedIndexObj[playerid][index][r_Scale][1] += MINIMUM_SCALEY;
		// ~~
		ResetEditObject(playerid, index);
	}

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

	if(textid == TDAppAjustarObj[8] && index != -1) // +z
	{
	    if(Edit_Android[ playerid ][ gPlayerVarTipoEdit ] == EDITING_POSITION) VarAttachedIndexObj[playerid][index][r_OffSets][2] += MINIMUM_FOREHEADZ;
	    if(Edit_Android[ playerid ][ gPlayerVarTipoEdit ] == EDITING_ROTACTION) VarAttachedIndexObj[playerid][index][r_OffSets][5] += MINIMUM_SCALERZ;
	    if(Edit_Android[ playerid ][ gPlayerVarTipoEdit ] == EDITING_SIZE) VarAttachedIndexObj[playerid][index][r_Scale][2] += MINIMUM_SCALEZ;

		// ------------ //

		ResetEditObject(playerid, index);
	}

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

	if(textid == TDAppAjustarObj[9] && index != -1) // -x
	{
	    if(Edit_Android[ playerid ][ gPlayerVarTipoEdit ] == EDITING_POSITION) VarAttachedIndexObj[playerid][index][r_OffSets][0] -= MINIMUM_FOREHEADX;
	    if(Edit_Android[ playerid ][ gPlayerVarTipoEdit ] == EDITING_ROTACTION) VarAttachedIndexObj[playerid][index][r_OffSets][3] -= MINIMUM_SCALERX;
	    if(Edit_Android[ playerid ][ gPlayerVarTipoEdit ] == EDITING_SIZE) VarAttachedIndexObj[playerid][index][r_Scale][0] -= MINIMUM_SCALEX;

		// ------------ //

		ResetEditObject(playerid, index);
	}

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

	if(textid == TDAppAjustarObj[10] && index != -1) // -y
	{
	    if(Edit_Android[ playerid ][ gPlayerVarTipoEdit ] == EDITING_POSITION) VarAttachedIndexObj[playerid][index][r_OffSets][1] -= MINIMUM_FOREHEADY;
	    if(Edit_Android[ playerid ][ gPlayerVarTipoEdit ] == EDITING_ROTACTION) VarAttachedIndexObj[playerid][index][r_OffSets][4] -= MINIMUM_SCALERY;
	    if(Edit_Android[ playerid ][ gPlayerVarTipoEdit ] == EDITING_SIZE) VarAttachedIndexObj[playerid][index][r_Scale][1] -= MINIMUM_SCALEY;

		// ------------ //

		ResetEditObject(playerid, index);
	}

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

	if(textid == TDAppAjustarObj[11] && index != -1) // -z
	{
	    if(Edit_Android[ playerid ][ gPlayerVarTipoEdit ] == EDITING_POSITION) VarAttachedIndexObj[playerid][index][r_OffSets][2] -= MINIMUM_FOREHEADZ;
	    if(Edit_Android[ playerid ][ gPlayerVarTipoEdit ] == EDITING_ROTACTION) VarAttachedIndexObj[playerid][index][r_OffSets][5] -= MINIMUM_SCALERZ;
	    if(Edit_Android[ playerid ][ gPlayerVarTipoEdit ] == EDITING_SIZE) VarAttachedIndexObj[playerid][index][r_Scale][2] -= MINIMUM_SCALEZ;

		// ------------ //

		ResetEditObject(playerid, index);
	}

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

    if(textid == TDAppAjustarObj[19] && index != -1) // alternar
    {
		new bool:sDebug;

	    if(Edit_Android[ playerid ][ gPlayerVarTipoEdit ] == EDITING_POSITION) Edit_Android[ playerid ][ gPlayerVarTipoEdit ] = EDITING_ROTACTION, sDebug = true;
	    if(Edit_Android[ playerid ][ gPlayerVarTipoEdit ] == EDITING_ROTACTION && !sDebug) Edit_Android[ playerid ][ gPlayerVarTipoEdit ] = EDITING_SIZE, sDebug = true;
	    if(Edit_Android[ playerid ][ gPlayerVarTipoEdit ] == EDITING_SIZE && !sDebug) Edit_Android[ playerid ][ gPlayerVarTipoEdit ] = EDITING_POSITION, sDebug = true;

        UpdatePlayerTextDraws(playerid, B_TD_EDIT_ATTACHED_OBJECT);
	}
	if(textid == TDAppAjustarObj[21] && index != -1) // salvar
    {
		SalvarEdicoesObjetoAndroid(playerid, index);
	}
	return 1;
}
private EditAttachedObjectAndroid(playerid, index)
{
	if(Edit_Android[ playerid ][ open_android ])
	    return 0;

    Edit_Android[ playerid ][ open_android ] = true;
    Edit_Android[ playerid ][ edit_attachid ] = index;
    Edit_Android[ playerid ][ gPlayerVarTipoEdit ] = EDITING_POSITION;

    forLoop(iii, 6) Edit_Android[ playerid ][ varOldPos ][ iii ] = VarAttachedIndexObj[playerid][index][r_OffSets][iii];
    forLoop(iii, 3) Edit_Android[ playerid ][ VarOldScale ][ iii ] = VarAttachedIndexObj[playerid][index][r_Scale][iii];
    // ------------------- //
    ShowPlayerTextDraws(playerid, B_TD_EDIT_ATTACHED_OBJECT);
    UpdatePlayerTextDraws(playerid, B_TD_EDIT_ATTACHED_OBJECT);
    HidePlayerTextDraws(playerid, B_TD_EDIT_ATTACHED_OBJECT);
    ShowPlayerTextDraws(playerid, B_TD_EDIT_ATTACHED_OBJECT);
	// ~~
	SelectTextDraw(playerid, -1);
	return 1;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

CancelEditObjectAndroid(playerid, bool:ResetahObject = false)
{
	if(!Edit_Android[ playerid ][ open_android ] || Edit_Android[ playerid ][ edit_attachid ] == -1)
	    return 0;

	new index = Edit_Android[ playerid ][ edit_attachid ];

	// vars
    Edit_Android[ playerid ][ open_android ] = false;
    Edit_Android[ playerid ][ edit_attachid ] = -1;
    Edit_Android[ playerid ][ gPlayerVarTipoEdit ] = EDITING_POSITION;

    // ------------------- //

	if(ResetahObject)
	{
	    RemovePlayerAttachedObject(playerid, index);

	    SetPlayerAttachedObject_Droid(playerid, index,
		VarAttachedIndexObj[playerid][index][r_Model],
		VarAttachedIndexObj[playerid][index][r_Bone],
		Edit_Android[ playerid ][ varOldPos ][0],
		Edit_Android[ playerid ][ varOldPos ][1],
		Edit_Android[ playerid ][ varOldPos ][2],
		Edit_Android[ playerid ][ varOldPos ][3],
		Edit_Android[ playerid ][ varOldPos ][4],
		Edit_Android[ playerid ][ varOldPos ][5],
	    Edit_Android[ playerid ][ VarOldScale ][0],
	    Edit_Android[ playerid ][ VarOldScale ][1],
	    Edit_Android[ playerid ][ VarOldScale ][2],
		VarAttachedIndexObj[playerid][index][r_MaterialColors][0],
		VarAttachedIndexObj[playerid][index][r_MaterialColors][1]);
    }

    // ------------------- //

    HidePlayerTextDraws(playerid, B_TD_EDIT_ATTACHED_OBJECT);
    CancelSelectTextDraw(playerid);

    forLoop(iii, 6) VarAttachedIndexObj[playerid][index][r_OffSets][iii] = Edit_Android[ playerid ][ varOldPos ][iii];
    forLoop(iii, 3) VarAttachedIndexObj[playerid][index][r_Scale][iii] = Edit_Android[ playerid ][ VarOldScale ][iii];
    forLoop(iii, 6) Edit_Android[ playerid ][ varOldPos ][iii] = 0.0;
    forLoop(iii, 3) Edit_Android[ playerid ][ VarOldScale ][iii] = 0.0;
	// ~~
    SendClientMessage(playerid, 0x00FFFFFF, "Voce cancela a edicao do objeto, o objeto foi para a posicao antiga!");
    return 1;
}
SalvarEdicoesObjetoAndroid(playerid, index)
{
	// vars
    Edit_Android[ playerid ][ open_android ] = false;
    Edit_Android[ playerid ][ edit_attachid ] = -1;
    Edit_Android[ playerid ][ gPlayerVarTipoEdit ] = EDITING_POSITION;

	// --------------------- //

    FinishEditingAttach(playerid,
    index,
    VarAttachedIndexObj[playerid][index][r_Model],
    VarAttachedIndexObj[playerid][index][r_Bone],
	VarAttachedIndexObj[playerid][index][r_OffSets][0],
	VarAttachedIndexObj[playerid][index][r_OffSets][1],
	VarAttachedIndexObj[playerid][index][r_OffSets][2],
	VarAttachedIndexObj[playerid][index][r_OffSets][3],
	VarAttachedIndexObj[playerid][index][r_OffSets][4],
	VarAttachedIndexObj[playerid][index][r_OffSets][5],
	VarAttachedIndexObj[playerid][index][r_Scale][0],
	VarAttachedIndexObj[playerid][index][r_Scale][1],
	VarAttachedIndexObj[playerid][index][r_Scale][2]);

    HidePlayerTextDraws(playerid, B_TD_EDIT_ATTACHED_OBJECT);
    CancelSelectTextDraw(playerid);

    // --------------------- //

    forLoop(iii, 6) Edit_Android[ playerid ][ varOldPos ][ iii ] = 0.0;
    forLoop(iii, 3) Edit_Android[ playerid ][ VarOldScale ][iii] = 0.0;

    return 1;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

ResetEditObject( playerid, index)
{
    RemovePlayerAttachedObject(playerid, index);

    SetPlayerAttachedObject_Droid(playerid, index,
	VarAttachedIndexObj[playerid][index][r_Model],
	VarAttachedIndexObj[playerid][index][r_Bone],
	VarAttachedIndexObj[playerid][index][r_OffSets][0],
	VarAttachedIndexObj[playerid][index][r_OffSets][1],
	VarAttachedIndexObj[playerid][index][r_OffSets][2],
	VarAttachedIndexObj[playerid][index][r_OffSets][3],
	VarAttachedIndexObj[playerid][index][r_OffSets][4],
	VarAttachedIndexObj[playerid][index][r_OffSets][5],
	VarAttachedIndexObj[playerid][index][r_Scale][0],
	VarAttachedIndexObj[playerid][index][r_Scale][1],
	VarAttachedIndexObj[playerid][index][r_Scale][2],
	0,
	0);
}
FinishEditingAttach(playerid, index, modelid, boneid, Float:fOffsetX, Float:fOffsetY, Float:fOffsetZ, Float:fRotX, Float:fRotY, Float:fRotZ, Float:fScaleX, Float:fScaleY, Float:fScaleZ)
{
    CallRemoteFunction( "SaveAttachmentAndroid", "ddddfffffffff", playerid, index, modelid, boneid, fOffsetX, fOffsetY, fOffsetZ, fRotX, fRotY, fRotZ, fScaleX, fScaleY, fScaleZ );
	return 1;
}
ShowPlayerTextDraws(playerid, tdid)
{
	if(tdid == B_TD_EDIT_ATTACHED_OBJECT)
	{
	    forLoop(td, sizeof(TDAppAjustarObj)) TextDrawShowForPlayer(playerid, TDAppAjustarObj[td]);
        forLoop(ptd, sizeof(PTDAppAjustarObj[])) PlayerTextDrawShow(playerid, PTDAppAjustarObj[playerid][ptd]);
	}
	if(tdid == B_TD_EDIT_DYNAMIC_OBJECT)
	{
	    forLoop(td, sizeof(TDEditorObjetos)) TextDrawShowForPlayer(playerid, TDEditorObjetos[td]);
        forLoop(ptd, sizeof(PTDEditorObjetos[])) PlayerTextDrawShow(playerid, PTDEditorObjetos[playerid][ptd]);
	}
}
HidePlayerTextDraws(playerid, tdid)
{
	if(tdid == B_TD_EDIT_ATTACHED_OBJECT)
	{
	    forLoop(td, sizeof(TDAppAjustarObj)) TextDrawHideForPlayer(playerid, TDAppAjustarObj[td]);
        forLoop(ptd, sizeof(PTDAppAjustarObj[])) PlayerTextDrawHide(playerid, PTDAppAjustarObj[playerid][ptd]);
	}
	if(tdid == B_TD_EDIT_DYNAMIC_OBJECT)
	{
	    forLoop(td, sizeof(TDEditorObjetos)) TextDrawHideForPlayer(playerid, TDEditorObjetos[td]);
        forLoop(ptd, sizeof(PTDEditorObjetos[])) PlayerTextDrawHide(playerid, PTDEditorObjetos[playerid][ptd]);
	}
}
UpdatePlayerTextDraws( playerid, tdid)
{
	new pString[ 128 ];
	if(tdid == B_TD_EDIT_ATTACHED_OBJECT)
	{
	    if(Edit_Android[ playerid ][ gPlayerVarTipoEdit ] == EDITING_POSITION) pString = "Editando a posicao do objeto";
	    if(Edit_Android[ playerid ][ gPlayerVarTipoEdit ] == EDITING_ROTACTION) pString = "Editando a rotacao do objeto";
	    if(Edit_Android[ playerid ][ gPlayerVarTipoEdit ] == EDITING_SIZE) pString = "Editando o tamanho do objeto";
		// ~~
		PlayerTextDrawSetString( playerid, PTDAppAjustarObj[playerid][0], pString);
	}
	if(tdid == B_TD_EDIT_DYNAMIC_OBJECT)
	{
		format(pString, sizeof(pString), "Editando %s", Edit_Android[ playerid ][ TipoEdicaoObj ] == EDITING_POSITION ? ("Posicao") : ("Rotacao"));
        PlayerTextDrawSetString(playerid, PTDEditorObjetos[playerid][0], pString);

		format(pString, sizeof(pString), "Velocidade: %0.1f(m)", Edit_Android[ playerid ][ TipoEdicaoObj ] == EDITING_POSITION ? Edit_Android[playerid][speed_cord] : Edit_Android[playerid][speed_cordROT]);
        PlayerTextDrawSetString(playerid, PTDEditorObjetos[playerid][1], pString);
	}
}
CancelPlayerEditDynObject(playerid, bool: SalvarAlteracoes = false)
{
	if(Edit_Android[ playerid ][ EditandoObjID ] == -1) return 0;

	new Float:oPos[6],
		sObj = Edit_Android[ playerid ][ EditandoObjID ];
	// ~~
	if(IsValidDynamicObject(sObj) && !SalvarAlteracoes)
	{
	    SetDynamicObjectPos(sObj, Edit_Android[ playerid ][ OldPosObj ][0], Edit_Android[ playerid ][ OldPosObj ][1], Edit_Android[ playerid ][ OldPosObj ][2]);
	    SetDynamicObjectRot(sObj, Edit_Android[ playerid ][ OldPosObj ][3], Edit_Android[ playerid ][ OldPosObj ][4], Edit_Android[ playerid ][ OldPosObj ][5]);
	}
	GetDynamicObjectPos(sObj, oPos[0], oPos[1], oPos[2]);
	GetDynamicObjectRot(sObj, oPos[3], oPos[4], oPos[5]);
	if( IsValidDynamicObject( sObj ) && SalvarAlteracoes)
	{
	    CallRemoteFunction( "SaveGatePlayer", "dddffffff", playerid, sObj, 1, oPos[ 0 ], oPos[ 1 ], oPos[ 2 ], oPos[ 3 ], oPos[ 4 ], oPos[ 5 ] );
	}
	Edit_Android[ playerid ][ EditandoObjID ] = -1;
	Edit_Android[ playerid ][ TipoEdicaoObj ] = 0;

	forLoop(i, 6) Edit_Android[ playerid ][ OldPosObj ][i] = 0.0;
	HidePlayerTextDraws(playerid, B_TD_EDIT_DYNAMIC_OBJECT);
	CancelSelectTextDraw(playerid);
	return 1;
}
SetPlayerAttachedObject_Droid(playerid, index, modelid, bone, Float:fOffsetX = 0.0, Float:fOffsetY = 0.0, Float:fOffsetZ = 0.0, Float:fRotX = 0.0, Float:fRotY = 0.0, Float:fRotZ = 0.0, Float:fScaleX = 1.0, Float:fScaleY = 1.0, Float:fScaleZ = 1.0, materialcolor1 = 0, materialcolor2 = 0)
{
 	SetPlayerAttachedObject(playerid, index, modelid, bone, Float:fOffsetX, Float:fOffsetY, Float:fOffsetZ, Float:fRotX, Float:fRotY, Float:fRotZ, Float:fScaleX, Float:fScaleY, Float:fScaleZ, materialcolor1, materialcolor2);

	VarAttachedIndexObj[playerid][index][r_Model] = modelid;
	VarAttachedIndexObj[playerid][index][r_Bone] = bone;
	VarAttachedIndexObj[playerid][index][r_OffSets][0] = fOffsetX;
	VarAttachedIndexObj[playerid][index][r_OffSets][1] = fOffsetY;
	VarAttachedIndexObj[playerid][index][r_OffSets][2] = fOffsetZ;
	VarAttachedIndexObj[playerid][index][r_OffSets][3] = fRotX;
	VarAttachedIndexObj[playerid][index][r_OffSets][4] = fRotY;
	VarAttachedIndexObj[playerid][index][r_OffSets][5] = fRotZ;
	VarAttachedIndexObj[playerid][index][r_Scale][0] = fScaleX == 0.0 ? 1.0 : fScaleX;
	VarAttachedIndexObj[playerid][index][r_Scale][1] = fScaleY == 0.0 ? 1.0 : fScaleY;
	VarAttachedIndexObj[playerid][index][r_Scale][2] = fScaleZ == 0.0 ? 1.0 : fScaleZ;
	VarAttachedIndexObj[playerid][index][r_MaterialColors][0] = materialcolor1;
	VarAttachedIndexObj[playerid][index][r_MaterialColors][1] = materialcolor2;
}
forward EditAttachedObjectEx( playerid, index);
public EditAttachedObjectEx( playerid, index)
{
	#undef EditAttachedObject
	if( IsPlayerAttachedObjectSlotUsed( playerid, index ))
	{
		if(!( IsPlayerAndroid( playerid ))) EditAttachedObject( playerid, index );
		else EditAttachedObjectAndroid( playerid, index );
	}
	#define EditAttachedObject(%0,%1) EditAttachedObjectEx(%0, %1)
	return 1;
}
private EditDynamicObjectEx( playerid, objectid)
{
	if( !IsPlayerConnected( playerid ) || !IsValidDynamicObject( objectid )) return 0;
	if( IsValidDynamicObject( objectid ))
	{
	    if(!(IsPlayerAndroid( playerid ))) EditDynamicObject(playerid, objectid);
	    else EditDynamicObjectAndroid(playerid, objectid);
	}
	return 1;
}
stock EditDynamicObjectAndroid(playerid, objectid)
{
    Edit_Android[ playerid ][ EditandoObjID ] = objectid;
    Edit_Android[ playerid ][ TipoEdicaoObj ] = EDITING_POSITION;

	GetDynamicObjectPos(objectid, Edit_Android[ playerid ][ OldPosObj ][0], Edit_Android[ playerid ][ OldPosObj ][1], Edit_Android[ playerid ][ OldPosObj ][2]);
	GetDynamicObjectRot(objectid, Edit_Android[ playerid ][ OldPosObj ][3], Edit_Android[ playerid ][ OldPosObj ][4], Edit_Android[ playerid ][ OldPosObj ][5]);

	// ~~~~~~~~~~~~~~~~~~~~~~~~ //

	if(Edit_Android[playerid][speed_cord] < 0.1)
	    Edit_Android[playerid][speed_cord] = 1.0;

	if(Edit_Android[playerid][speed_cordROT] < 0.1)
	    Edit_Android[playerid][speed_cordROT] = 1.0;

	// ~~~~~~~~~~~~~~~~~~~~~~~~ //

	// textdraws
	SelectTextDraw(playerid, -1);

	ShowPlayerTextDraws(playerid, B_TD_EDIT_DYNAMIC_OBJECT);
	UpdatePlayerTextDraws(playerid, B_TD_EDIT_DYNAMIC_OBJECT);
	return 1;
}
