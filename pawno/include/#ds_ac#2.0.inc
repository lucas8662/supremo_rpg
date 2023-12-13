
/*

Anti Cheater Feito por dimmy_scarface


-------------------------Anti Cheaters------------------------------------------

Anti-Xiters:

				Nomes                  Precisão

		- Anti Car-AirBreak 			95%
		- Anti Player-AirBreak          95%
		- Anti Teleport 				100%
	 	- Anti Speed Hack 				100%
		- Anti Money-Hack       		100%
		- Anti Armour-Hack      		100%
		- Anti Health-Hack              100%
		- Anti Divulguer        		80%
		- Anti Fly-Hack         		95%
		- Anti Fake-Kill        		90%
		- Anti State-Hack       		100%
		- Anti JoyPad           		20% (Se acusar, é porque está usando mesmo)
		- Anti Weapon-Hack      		90%
		- Anti Armas proibidas  		100%
		- Anti Car-Flood                100%
		- Anti Rapid-Fire               100%
		- Anti No-Reload                100%
		- Anti Auto-CBUG / Macro        100%
		- Anti Pro-Aimbot               100% (AimBot que puxa a skin)
		//- Anti Puxar carros          	85%



--------------------------------------------------------------------------------
*/






#define RangeAB         110.0
#define Range_Driver    150.0

#define Cheat:%0(%1) forward %0(%1); public %0(%1)


#define AirBreak_Teleport        		(1)
#define Speed_Hack                      (2)
#define Money_Hack                      (3)
#define State_Hack                     	(4)
#define Cheater_Fly                     (5)
#define Weapon_Hack                     (6)
#define Armour_Hack                		(7)
#define Fake_Kill                       (8)
#define Player_Divulguer                (9)
#define Player_Joypad               	(10)
#define Armas_Proibidas                 (11)
#define Health_Hack                     (12)
#define Rapid_Fire                   	(13)
#define No_Reload                       (14)
#define Auto_Cbug                       (15)
#define Pro_Aim                         (16)
#define Warp_Car                        (17)
#define Bullet_Crasher                  (18)

new Slot_Weapon[MAX_PLAYERS][50];
new fAutoC[MAX_PLAYERS];

enum ctinfo
{
	Float:PLAYER_POS_X,
	Float:PLAYER_POS_Y,
	Float:PLAYER_POS_Z,
	Float:Teleport_X,
	Float:Teleport_Y,
	Float:Teleport_Z,
	Float:Colete,
	Float:cVida,
	AGUARDO,
	PLAYER_TIMER,
	MONEY_PLAYER,
	STATE_PLAYER,
	RAPID_FIRE_EAGLE,
	RAPID_FIRE_SHOTGUN,
	RAPID_FIRE_SNIPER,
	FAKE_KILL_PLAYER,
	bool:PLAYER_WEAPON_HACK,
	bool:Congelado,
};
new ds_info[MAX_PLAYERS][ctinfo];

public OnGameModeInit()
{
	SetTimer("NONE", 99999, true);
	return CallLocalFunction("ab_OnGameModeInit", "");
}
forward ab_OnGameModeInit();

public OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ)
{
	if(hittype == BULLET_HIT_TYPE_PLAYER)
   	{

        if(!( -1000.0 <= fX <= 1000.0 ) || !( -1000.0 <= fY <= 1000.0 ) || !( -1000.0 <= fZ <= 1000.0 ))
        {
			CallLocalFunction("PlayerCheater","id", playerid, Bullet_Crasher);
			return 0;
        }

		new Float:fOrigin[3], Float:fHitPos[3], Float:dist, Float:dist2;
		GetPlayerLastShotVectors(playerid, fOrigin[0], fOrigin[1], fOrigin[2], fHitPos[0], fHitPos[1], fHitPos[2]);

		dist = GetPlayerDistanceFromPoint(hitid, fHitPos[0], fHitPos[1], fHitPos[2]);
        dist2 = GetPlayerDistanceFromPoint(playerid, fHitPos[0], fHitPos[1], fHitPos[2]);

        CriarBolinha(playerid, fHitPos[0], fHitPos[1], fHitPos[2]);

	    if(dist2 < 4.0 && dist >= 30.0 && dist < 300.0 && GetPlayerSurfingVehicleID(playerid) == INVALID_VEHICLE_ID && GetPlayerState(hitid) == PLAYER_STATE_ONFOOT)
	    {
	        LogAimbot(playerid, dist2, dist);
	        CallLocalFunction("PlayerCheater","id", playerid, Pro_Aim);
	    }
	}

    if (!IsPlayerInAnyVehicle(playerid))
    {
		if(weaponid == 25)
		{
		    ds_info[playerid][RAPID_FIRE_SHOTGUN] ++;
		}
		else if(weaponid == 24)
		{
		    ds_info[playerid][RAPID_FIRE_EAGLE] ++;
		    fAutoC[playerid] ++;
		}
		else if(weaponid == 34)
		{
		    ds_info[playerid][RAPID_FIRE_SNIPER] ++;
		}

		if(ds_info[playerid][RAPID_FIRE_EAGLE] >= 11 || ds_info[playerid][RAPID_FIRE_SHOTGUN] >= 4 || ds_info[playerid][RAPID_FIRE_SNIPER] >= 4)
		{
			CallLocalFunction("PlayerCheater","id", playerid, 13);
			SetPlayerArmedWeapon(playerid, 0);
		}
		if(gettime() > GetPVarInt(playerid, "UmSegundo")){

			SetPVarInt(playerid, "UmSegundo", gettime() + 1);
			fAutoC[playerid] = 0;

		}else{
			if(fAutoC[playerid] > 4){

	        	CallLocalFunction("PlayerCheater","id", playerid, Auto_Cbug);
				fAutoC[playerid] = 0;
				SetPVarInt(playerid, "WarnningMacro", GetPVarInt(playerid, "WarnningMacro") + 1);
			}
		}
	}
	CallLocalFunction("AC_OnPlayerWeaponShot", "ddddfff", playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ);
	return 1;
}
#if defined _ALS_OnPlayerWeaponShot
	#undef OnPlayerWeaponShot
#else
	#define _ALS_OnPlayerWeaponShot
#endif
 
#define OnPlayerWeaponShot AC_OnPlayerWeaponShot
#if defined AC_OnPlayerWeaponShot
	forward AC_OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ);
#endif


stock isPlayerInWater(playerid)
{
    new Float:x,Float:y,Float:z;
    GetPlayerPos(playerid, x, y, z);
    if((x >= -1408.0629 && y >= 2021.0587 && x <= -460.9319 && y <= 2861.4893) ||//Represa do deserto de Las Venturas
    (x >= 1269.5886 && y >= -810.4507 && x <= 1288.8916 && y <= -800.5959) ||//Piscina de uma casa em VineWood (Mad Dog's Mansion)
    (x >= 1086.6010 && y >= -683.6998 && x <= 1103.0225 && y <= -662.1832) ||//Piscina de uma casa em VineWood (Perto Mad Dog's Mansion)
    (x >= 169.6879 && y >= -1392.6630 && x <= 281.5444 && y <= -1168.9749) ||// 2 Piscinas em VineWood
    (x >= -828.3018 && y >= -2107.1487 && x <= -443.5032 && y <= -1855.6273) ||//Lago da árvore caída, ou Lago Morto
    (x >= 1198.9982 && y >= -2407.0581 && x <= 1275.7397 && y <= -2341.6262) ||//Lago perto do aeroporto Los Santos
    (x >= 2293.1467 && y >= -1432.5869 && x <= 2331.7388 && y <= -1397.6476) ||//Lago perto da Igreja Los Santos
    (x >= 1915.3196 && y >= -1236.2382 && x <= 2016.6565 && y <= -1167.9290) ||//Park Glen Los Santos
    (x >= -2747.1692 && y >= -510.1152 && x <= -2663.2468 && y <= -411.4905) ||//Lago em San Fierro
    (x >= 1838.8041 && y >= 1463.2024 && x <= 2035.4167 && y <= 1703.0480) ||//Cascata do Login em Las Venturas
    (x >= 2049.6646 && y >= 1843.3029 && x <= 2119.9021 && y <= 1983.5464) ||//Navio Pirata em Las Venturas
    (x >= 2094.9255 && y >= 1085.2852 && x <= 2179.1790 && y <= 1183.0610) ||//Frente de um Cascino em Las Venturas
    (x >= 2545.3718 && y >= 2347.7112 && x <= 2593.6794 && y <= 2403.8040) ||
	(z < 0xF))//No mar
    {
     return 1;
    }
    return 0;
}


/*
isPlayerInWater(playerid)
{
	static Float:fX, Float:fY, Float:fZ;
	GetPlayerPos(playerid, fX, fY, fZ);
	if((fX >= 2044.6 && fX <= 2192.984 && fY >= 1206.358 && fY <= 1376.552) && fZ < 0xA) return 1;
	else if((fX >= 2048.504 && fX <= 2185.174 && fY >= 1063.239 && fY <= 1202.49) && fZ < 0xA) return 1;
	else if((fX >= 2204.698 && fX <= 2204.698 && fY >= 1426.837 && fY <= 1430.705) && fZ < 0xA) return 1;
	else if((fX >= 2032.885 && fX <= 2114.887 && fY >= 1852.325 && fY <= 1991.575) && fZ < 0xC) return 1;
	else if((fX >= 2517.086 && fX <= 2606.897 && fY >= 2316.493 && fY <= 2420.93) && fZ < 0x16) return 1;
	else if((fX >= 2554.5996 && fX <= 2507.7683 && fY >= 1548.6178 && fY <= 1588.9154) && fZ < 0xF) return 1;
	else if((fX >= -2043.628 && fX <= -1973.561 && fY >= -980.9415 && fY <= -724.0283) && fZ < 0x20) return 1;
	else if((fX >= -2753.912 && fX <= -2665.071 && fY >= -522.3632 && fY <= -380.3444) && fZ < 0x05) return 1;
	else if((fX >= 1219.864 && fX <= 1292.118 && fY >= -2435.881 && fY <= -2325.344) && fZ < 0xF) return 1;
	else if((fX >= 1923.388 && fX <= 2010.854 && fY >= -1223.924 && fY <= -1168.656) && fZ < 0x16) return 1;
	else if((fX >= 1269.301 && fX <= 1314.935 && fY >= -837.0452 && fY <= -781.7769) && fZ < 0x5A) return 1;
	else if((fX >= 1087.3953 && fX <= 1102.3138 && fY >= -682.6734 && fY <= -663.0043) && fZ < 0x71) return 1;
	else if((fX >= 1268.6118 && fX <= 1291.8774 && fY >= -784.2910 && fY <= -764.6104) && fZ < 0x43D) return 1;
	else if(fZ < 0xF) return 1;
	return 0;
}
*/
task AllCheater[1000](){

	new
	    Float:pX, Float:pY, Float:pZ,
		Float:x, Float:y, Float:z, Float:r_r;
	foreach(new i: Player)
	{
	    GetPlayerPos(i, pX, pY, pZ);
	    if(ds_info[i][AGUARDO] > 0)ds_info[i][AGUARDO]--;
		if(ds_info[i][STATE_PLAYER] > 0)ds_info[i][STATE_PLAYER]--;
		if(ds_info[i][FAKE_KILL_PLAYER] > 0 )ds_info[i][FAKE_KILL_PLAYER]--;

		x 			= ds_info[i][PLAYER_POS_X],
		y 			= ds_info[i][PLAYER_POS_Y],
		z 			= ds_info[i][PLAYER_POS_Z];

		if(IsPlayerInAnyVehicle(i))r_r = Range_Driver;
	    else r_r = RangeAB;


		/*---------------------- Speed Hack -------------------------------*/
		if(CheckConnect(i) && GetPlayerSpeed(i) > 290 && !IsAPlane(GetPlayerVehicleID(i)))
		{
			new string[120];
			format(string, sizeof string, "%.1f", GetPlayerSpeed(i));
		    CallLocalFunction("PlayerCheater","ids", i, Speed_Hack, string);
		}
		/*---------------------- Anti AirBreak ou Teleport -----------------*/
	    else if(!IsPlayerInRangeOfPoint(i, r_r, x, y, z)
		&& gettime() < ds_info[i][PLAYER_TIMER]
		&& ds_info[i][AGUARDO] < 1
		&& GetPlayerSurfingVehicleID(i) == 0xFFFF)
		{
		    if((GetPlayerState(i) == PLAYER_STATE_ONFOOT || GetPlayerState(i) == PLAYER_STATE_DRIVER))
		    {
				if(!IsPlayerInRangeOfPoint(i, 35.0,
				ds_info[i][Teleport_X], ds_info[i][Teleport_Y], ds_info[i][Teleport_Z]))
				{
					CallLocalFunction( "PlayerCheater" , "id", i , AirBreak_Teleport ) ;
				}
			}
		}
		ds_info[i][PLAYER_TIMER] 			= gettime()+2;
		ds_info[i][PLAYER_POS_X] 			= pX;
		ds_info[i][PLAYER_POS_Y] 			= pY;
		ds_info[i][PLAYER_POS_Z] 			= pZ;

		/*---------------------- Money Hack -------------------------------*/
		if(GetPlayerMoney(i) != ds_info[i][MONEY_PLAYER])
		{
		    ResetPlayerMoney(i);
			GivePlayerMoney(i, ds_info[i][MONEY_PLAYER]);
		}
		
		/*---------------------- Armas Proibidas --------------------------*/
		switch(GetPlayerWeapon(i))
		{
	   		case 37, 9, 26, 28, 32, 35, 36, 38, 22, 39, 41:
	   		{
	  		    CallLocalFunction("PlayerCheater","id", i, Armas_Proibidas);
			}
		}

		static Float:vidacolete;
		
		GetPlayerHealth(i, vidacolete);
		if(vidacolete > ds_info[i][cVida] && ds_info[i][cVida] > 0)
		{
		    SetPlayerHealth(i, ds_info[i][cVida]);
		}
		GetPlayerArmour(i, vidacolete);
		if(vidacolete > ds_info[i][Colete])
		{
		    SetPlayerArmour(i, ds_info[i][Colete]);
		}
		
		//---------------------- Rapid Fire --------------------------------*/
		ds_info[i][RAPID_FIRE_EAGLE] = 0;
		ds_info[i][RAPID_FIRE_SHOTGUN] = 0;
		ds_info[i][RAPID_FIRE_SNIPER] = 0;
		
		//----------------- Weapon Hack -------------------------------------*/
		if(ds_info[i][AGUARDO] < 1){
		
			if((GetPlayerWeapon(i)>10&&GetPlayerWeapon(i)<46&&GetPlayerAmmo(i)>0) && !Slot_Weapon[i][GetPlayerWeapon(i)])
			{
			
				CallLocalFunction("PlayerCheater","id", i, Weapon_Hack);
   				ab_ResetPlayerWeapons(i);
			}
		}
	}
	
	return true;
}

stock GetWarnningMacroValue(playerid)
{
	return GetPVarInt(playerid, "WarnningMacro");
}

//-------------- CallBacks ----------------------------------------------------
public OnEnterExitModShop(playerid, enterexit, interiorid)
{
    ds_info[playerid][AGUARDO] = 5;
    return CallLocalFunction("ab_OnEnterExitModShop", "idd", playerid, enterexit, interiorid);
}

forward ab_OnEnterExitModShop(playerid, enterexit, interiorid);
public OnPlayerConnect(playerid)
{
	ds_info[playerid][MONEY_PLAYER] = 0;
	ds_info[playerid][STATE_PLAYER] = 0;
	ds_info[playerid][FAKE_KILL_PLAYER] = 0;
    ds_info[playerid][cVida] = 100.0;
    ds_info[playerid][Colete] = 0.0;
	ds_info[playerid][Congelado] = false;
	ds_info[playerid][RAPID_FIRE_EAGLE] = 0;
	ds_info[playerid][RAPID_FIRE_SHOTGUN] = 0;
	ds_info[playerid][RAPID_FIRE_SNIPER] = 0;
	ab_ResetPlayerWeapons(playerid);
	return CallLocalFunction("ab_OnPlayerConnect", "i", playerid);
}
forward ab_OnPlayerConnect(playerid);

public OnPlayerSpawn(playerid)
{
    ds_info[playerid][STATE_PLAYER] = 0;
    ab_ResetPlayerWeapons(playerid);
    ds_info[playerid][AGUARDO] = 10;
    ds_info[playerid][cVida] = 100.0;
    ds_info[playerid][Colete] = 0.0;
	ds_info[playerid][RAPID_FIRE_EAGLE] = 0;
	ds_info[playerid][RAPID_FIRE_SHOTGUN] = 0;
	ds_info[playerid][RAPID_FIRE_SNIPER] = 0;
    ds_info[playerid][Congelado] = false;
    SetPlayerArmour(playerid, 0);
	return CallLocalFunction("ab_OnPlayerSpawn", "i", playerid);
}
forward ab_OnPlayerSpawn(playerid);


public OnPlayerDeath(playerid, killerid, reason)
{
    ds_info[playerid][Congelado] = false;
    /*----------------------- Fake Kill --------------------------------------*/
	ds_info[playerid][FAKE_KILL_PLAYER]++;
	if(ds_info[playerid][FAKE_KILL_PLAYER] > 3 )
	{
		CallLocalFunction("PlayerCheater","id", playerid, Fake_Kill);
		ds_info[playerid][FAKE_KILL_PLAYER] = 0 ;
		SendClientMessage(playerid, -1, "SERVER: Você foi banido deste servidor por suspeita de Fake Kill ou Crasher");
		BanEx(playerid, "Fake-Kill");
	}
	return CallLocalFunction("ab_OnPlayerDeath", "iid", playerid, killerid, reason);
}
forward ab_OnPlayerDeath(playerid, killerid, reason);

public OnPlayerStateChange(playerid, newstate, oldstate)
{
    /*----------------------- State Hack --------------------------------------*/
	ds_info[playerid][STATE_PLAYER]++;
	ds_info[playerid][AGUARDO] = 5;
	if(ds_info[playerid][STATE_PLAYER] >= 6)
	{
			CallLocalFunction("PlayerCheater","id", playerid, State_Hack);
			ds_info[playerid][STATE_PLAYER]=0;
			SendClientMessage(playerid, -1, "SERVER: Você foi kickado deste servidor por suspeita de State Hack ou Crasher");
			Kick(playerid);
	}
	return CallLocalFunction("ab_OnPlayerStateChange", "idd", playerid, newstate, oldstate);
}
forward ab_OnPlayerStateChange(playerid, newstate, oldstate);


public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{

	if(newkeys & KEY_CROUCH)
	    fAutoC[playerid] = 0;
	    
	if(GetPlayerState(playerid) == 1 && (newkeys & 2048 || newkeys & 4096))
	{
	    CallLocalFunction("PlayerCheater","id", playerid, Player_Joypad);
	}
	return CallLocalFunction("abb_OnPlayerKeyStateChange", "idd", playerid, newkeys, oldkeys);
}
forward abb_OnPlayerKeyStateChange(playerid, newkeys, oldkeys);

new possiveis_dv[][] =
{
	"ip.brasil",
	":7777",
	"PlayForever",
	"PlayHorny",
	"play horny",
	"PlayGames",
	"StartLife",
	"PlayFacil",
	":7779",
	":8888",
	":7778",
	":7775",
	"brasilplay",
	"Brasil Play",
	"CSA",
	"server.",
	"ip.",
	"samp."
};

stock AntiDivulguer(playerid, string[])
{
	new nums = 0, ponts = 0;
	for(new i; i < strlen(string); i++)
	{
		if(string[i] >= '0' && '9' >= string[i] || (string[i] == '.' || string[i] == ':')){
			if(string[i] == '.' || string[i] == ':'){
				ponts++;
			}
			else{
				nums++;
			}
			if(nums >= 8 && ponts >= 3)
			{
				CallLocalFunction("PlayerCheater","ids", playerid, Player_Divulguer, string);
				SendClientMessage(playerid, -1, "{00EAF6}ANTICHEAT:{FFFFFF} Você foi acusado:{00EAF6} (Divulgando IP)");
	            SendClientMessage(playerid, -1, "Info: Caso voce realmente não esteja divulgando um IP, avise imediatamente os admins usando /relatorio.");
	            SendClientMessage(playerid, -1, "Info: Se você estiver divulgando outro servidor aqui, será banido permanentemente sem chances de revisão!");
	            SendClientMessage(playerid, -1, "__________________________________________________________________________________________________________");
				return 1;
			}
		}
	}

	for(new iDv; iDv < sizeof(possiveis_dv); iDv++)
	{
	   	if(strfind(string, possiveis_dv[iDv], true) != -1)
	   	{
			CallLocalFunction("PlayerCheater","ids", playerid, Player_Divulguer, string);
			SendClientMessage(playerid, -1, "{00EAF6}ANTICHEAT:{FFFFFF} Você foi acusado:{00EAF6} (Divulgando IP)");
            SendClientMessage(playerid, -1, "Info: Caso voce realmente não esteja divulgando um IP, avise imediatamente os admins usando /relatorio.");
            SendClientMessage(playerid, -1, "Info: Se você estiver divulgando outro servidor aqui, será banido permanentemente sem chances de revisão!");
            SendClientMessage(playerid, -1, "__________________________________________________________________________________________________________");
			return 1;
		}
	}
	return 0;
}

public OnPlayerText(playerid, text[])
{
	if(AntiDivulguer(playerid, text))return 0;
	if(!strlen(text))return false;// < evitando um crasher do s0beit
	return CallLocalFunction("ab_OnPlayerText", "is", playerid, text);
}
forward ab_OnPlayerText(playerid, text[]);
//------------------------------------------------------------------------------

//PutPlayerInVehicle
Cheat:ab_PutPlayerInVehicle(playerid, vehicleid, seatid)
{
	new Float:x, Float:y, Float:z;
	GetVehiclePos(vehicleid, x, y, z);
    ds_info[playerid][AGUARDO] = 5;

	ds_info[playerid][Teleport_X] = x;
	ds_info[playerid][Teleport_Y] = y;
	ds_info[playerid][Teleport_Z] = z;
	
	SetPVarInt(playerid, "pCarSmasher", 0);
	return PutPlayerInVehicle(playerid, vehicleid, seatid);
}


//-------- MONEY ------------
Cheat:ab_GetPlayerMoney(playerid)
{
	return ds_info[playerid][MONEY_PLAYER];
}
Cheat:ab_GivePlayerMoney(playerid, money)
{
	ds_info[playerid][MONEY_PLAYER] = ds_info[playerid][MONEY_PLAYER]+=money;
	return true;
}
Cheat:ab_ResetPlayerMoney(playerid)
{
	return ds_info[playerid][MONEY_PLAYER] = 0;
}

stock ArmaSlot(armaid){

	switch(armaid){
	
	    case 0, 1:		return 0;
	    case 2..9:		return 1;
	    case 22..24:	return 2;
	    case 25..27:	return 3;
	    case 28,29,32:	return 4;
	    case 30,31:		return 5;
	    case 33,34:		return 6;
	    case 35..38:	return 7;
	    case 16..18,39:	return 8;
	    case 41..43:	return 9;
	    case 10..15:	return 10;
	    case 44..46:	return 11;
	    case 40:		return 12;
	}
	return 0;
}

stock ab_TogglePlayerControllable(playerid, status){

	if(status){
	
	    ds_info[playerid][Congelado] = false;
	}else{
	
	    ds_info[playerid][Congelado] = true;
	}
	return TogglePlayerControllable(playerid, status);
}

stock IsPlayerCongelado(playerid)
	return ds_info[playerid][Congelado];

Cheat:ab_GivePlayerWeapon(playerid, weaponid, ammo)
{
    ds_info[playerid][AGUARDO] = 5;

    Slot_Weapon[playerid][weaponid] = true;
	GivePlayerWeapon(playerid, weaponid, ammo);
	return true;
}
Cheat:ab_ResetPlayerWeapons(playerid)
{
    ds_info[playerid][AGUARDO] = 5;

    ResetPlayerWeapons(playerid);

	for(new x; x != 50; x++){
	
	    Slot_Weapon[playerid][x] = false;
	}

	return true;
}




//-------------- FLY- Anim-------------
Cheat:CheckAnim(playerid)
{
	new animation = GetPlayerAnimationIndex(playerid);
	if(animation == 1539 || animation == 1538 || animation == 1543)
	    return true;
	return 0;
}

//--------------- SetPlayerPos ----------
Cheat:ab_SetPlayerPos(playerid, Float:px, Float:py, Float:pz)
{
	ds_info[playerid][AGUARDO] = 6;

	ds_info[playerid][PLAYER_POS_X] = px;
	ds_info[playerid][PLAYER_POS_Y] = py;
	ds_info[playerid][PLAYER_POS_Z] = pz;

	ds_info[playerid][Teleport_X] = px;
	ds_info[playerid][Teleport_Y] = py;
	ds_info[playerid][Teleport_Z] = pz;
	return SetPlayerPos(playerid, px, py, pz);
}

Cheat:ab_SetVehiclePos(vehicleid, Float:x, Float:y, Float:z)
{
	foreach(new i: Player)
	{
	    if(IsPlayerInAnyVehicle(i) && GetPlayerVehicleID(i) == vehicleid)
	    {
			ds_info[i][AGUARDO] = 6;

			ds_info[i][Teleport_X] = x;
			ds_info[i][Teleport_Y] = y;
			ds_info[i][Teleport_Z] = z;
		}
	}
	SetVehiclePos(vehicleid, x, y, z);
	return 1;
}

//-------- COLETE/VIDA ---------
Cheat:ab_SetPlayerArmour(playerid, Float:armour)
{
	ds_info[playerid][Colete] = armour;
	SetPlayerArmour(playerid, armour);
	return updatetextlife(playerid);
}
Cheat:ab_SetPlayerHealth(playerid, Float:health)
{
	ds_info[playerid][cVida] = health;
	SetPlayerHealth(playerid, health);
	return updatetextlife(playerid);
}

stock GetPlayerArmourBCS(playerid, &Float:colete){
	colete = ds_info[playerid][Colete];
}
stock GetPlayerHealthBCS(playerid, &Float:vida){
	vida = ds_info[playerid][cVida];
	return 1;
}

#define GetPlayerHealth GetPlayerHealthBCS
#define GetPlayerArmour GetPlayerArmourBCS



public OnPlayerTakeDamage(playerid, issuerid, Float:amount, weaponid, bodypart)
{
	if(issuerid == INVALID_PLAYER_ID){
 		ds_info[playerid][cVida] -= amount;
	}
	return CallLocalFunction("ab_OnPlayerTakeDamage", "ddfdd", playerid, issuerid, amount, weaponid, bodypart);
}
forward ab_OnPlayerTakeDamage(playerid, issuerid, Float:amount, weaponid, bodypart);

#if defined _ALS_OnPlayerTakeDamage
	#undef OnPlayerTakeDamage
#else
	#define _ALS_OnPlayerTakeDamage
#endif
#define OnPlayerTakeDamage ab_OnPlayerTakeDamage


#if defined _ALS_OnGameModeInit
    #undef OnGameModeInit
#else
    #define _ALS_OnGameModeInit
#endif
#define OnGameModeInit ab_OnGameModeInit




#if defined _ALS_OnPlayerSpawn
    #undef OnPlayerSpawn
#else
    #define _ALS_OnPlayerSpawn
#endif
#define OnPlayerSpawn ab_OnPlayerSpawn




#if defined _ALS_OnPlayerStateChange
    #undef OnPlayerStateChange
#else
    #define _ALS_OnPlayerStateChange
#endif
#define OnPlayerStateChange ab_OnPlayerStateChange




#if defined _ALS_OnPlayerConnect
    #undef OnPlayerConnect
#else
    #define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect ab_OnPlayerConnect




#if defined _ALS_OnPlayerDeath
    #undef OnPlayerDeath
#else
    #define _ALS_OnPlayerDeath
#endif
#define OnPlayerDeath ab_OnPlayerDeath





#if defined _ALS_OnEnterExitModShop
    #undef OnEnterExitModShop
#else
    #define _ALS_OnEnterExitModShop
#endif
#define OnEnterExitModShop ab_OnEnterExitModShop





#if defined _ALS_OnPlayerText
    #undef OnPlayerText
#else
    #define _ALS_OnPlayerText
#endif
#define OnPlayerText ab_OnPlayerText





#if defined _ALS_OnPlayerKeyStateChange
    #undef OnPlayerKeyStateChange
#else
    #define _ALS_OnPlayerKeyStateChange
#endif
#define OnPlayerKeyStateChange abb_OnPlayerKeyStateChange





#if defined _ALS_SetPlayerArmour
	#undef SetPlayerArmour
#else
	#define _ALS_SetPlayerArmour
#endif
#define SetPlayerArmour                 ab_SetPlayerArmour





#if defined _ALS_SetPlayerHealth
	#undef SetPlayerHealth
#else
	#define _ALS_SetPlayerHealth
#endif
#define SetPlayerHealth                 ab_SetPlayerHealth


#define SetPlayerPos    				ab_SetPlayerPos
#define SetVehiclePos    				ab_SetVehiclePos
#define PutPlayerInVehicle              ab_PutPlayerInVehicle
#define GivePlayerMoney                 ab_GivePlayerMoney
#define GetPlayerMoney                 	ab_GetPlayerMoney
#define ResetPlayerMoney                ab_ResetPlayerMoney
#define ResetPlayerWeapons              ab_ResetPlayerWeapons
#define GivePlayerWeapon                ab_GivePlayerWeapon
#define TogglePlayerControllable        ab_TogglePlayerControllable

forward PlayerCheater(playerid, cheater, descricao[]);
