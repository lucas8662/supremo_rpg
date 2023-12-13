/*
Esse anti hack detecta:

	- Weapons
		• Weapon Cheat
		• Freeze ammo
		• Ammo Cheat
		• Rapid fire
	- Anti Fake-Kill
	- Anti Fake-Connect
	- Anti Slide-Bug
	- Anti Spam-Chat
	- Dessincronização
*/

//##########################################################################################################//
//###############################################[Vars/Defines]#############################################//
//##########################################################################################################//


//Weapons
#define ysac_MAX_WEAPONIDS 		   47
#define ysac_IMMU_TIME	   		   2000
#define ysac_MAX_RAPID_TIME_NORMAL 300
#define ysac_MAX_WARNINGS_FREEZE   4
#define ysac_MAX_SPOOF_WARNS	   3

enum ysac_WEAP_DATA
{
	ysacPlayerAmmo,
	ysacPlayerWeapons,

	ysacNewAmmo,
	ysacOldAmmo
}

enum ysac_PLAYER_DATA
{
	bool:ysacWepImmu,
	bool:ysacAmmoImmu,

	ysacASWarns,
	ysacFirstTick,
	ysacSecondTick,
	ysacFirstShot,
	ysacSecondShot,
	ysacConstWep,
	ysacUpdateTicks,
	ysacAntibugTicks,

	ysacRepeater,
	ysacCheckTimer
}

static 
	ysac_Weapons[MAX_PLAYERS][ysac_WEAP_DATA][ysac_MAX_WEAPONIDS],
	ysac_Player[MAX_PLAYERS][ysac_PLAYER_DATA];

//Fake Kill

#define FKI_MAX_ERROR_WARNS 3

enum FKI_PLAYER_DATA
{
	bool:FkiDmgChk,
	bool:FkiSpwnChk,
	bool:FkiJustDied,

	FkiWTicks,

	FkiDeTimer
}

static 
	FKI_Player[MAX_PLAYERS][FKI_PLAYER_DATA];

static FKI_IsWeaponValid(Weapon) 
	return ( 0 <= Weapon <= 18 || 22 <= Weapon <= 46   );

static FKI_IsAPlane(vehicleid)
{
	switch(GetVehicleModel(vehicleid))
	{
		case 592, 577, 511, 512, 593, 520, 553, 476, 519, 460, 513, 464: return 1;
		case 548, 425, 417, 487, 488, 497, 563, 447, 469, 465, 501: return 1; 
	}
	return 0;
}

static IsKillFalse(killid)
{
	switch(killid)
	{
		case 54, 255, 53, 51, 47: return 1;
	}
	return 0;
}

//Fake Connect

#define AFC_NUMBER 30

#if !defined gpci
	native gpci(playerid, serial[], len);
#endif

static AFC_IsPlayerBot(playerid)
{  
	if(IsPlayerNPC(playerid)) return 0;
	new TempId[80], TempNumb;  
	gpci(playerid, TempId, sizeof(TempId));  
	for(new i; i < strlen(TempId); i++)  
	{  
		if(TempId[i] >= '0' && TempId[i] <= '9')  TempNumb++;  
	}  
	return (TempNumb >= AFC_NUMBER || strlen(TempId) <= AFC_NUMBER);
}

//Anti Slide-Bug

enum SBA_DATA_INFO
{
	slidecheck,

	bool:possibleslide
};

static
	SBA_Player[MAX_PLAYERS][SBA_DATA_INFO];

GetPlayerOnFootSpeed(playerid)
{
	new Float:ST[4];
	GetPlayerVelocity(playerid,ST[0],ST[1],ST[2]);
	ST[3] = floatsqroot(floatpower(floatabs(ST[0]), 2.0) + floatpower(floatabs(ST[1]), 2.0) + floatpower(floatabs(ST[2]), 2.0)) * 179.28625;
	
	return floatround(ST[3]);
}

IsPAiming(playerid)
{
	new playeranim = GetPlayerAnimationIndex(playerid);
	if (((playeranim >= 1160) && (playeranim <= 1163)) || (playeranim == 1167) || (playeranim == 1365) ||
	(playeranim == 1643) || (playeranim == 1453) || (playeranim == 220)) return 1;

	return 0;
}

//Anti Chat-Spam

enum ASPA_PLAYER_DATA
{
	AspaTextone,
	AspaTexttwo,

	AspaRTimer,
	AspaWarns
}

static 
	Aspa_Player[MAX_PLAYERS][ASPA_PLAYER_DATA];

#define MAX_WAIT_TIME 500

//Dessicronização

#define FL_INVALID_PLAYER_STATS 			-1			
#define FL_ADDED_VALUE	  					80
#define FL_MAX_DESYNC_WARNS 				3
#define FL_KICK_TYPE_PING_LAG 				1
#define FL_KICK_TYPE_DESYNC_LAG 			2
#define FL_MAX_LAG_PING 					450
#define FL_MAX_WAIT_TIME 					3
#define FL_MAX_WARNINGS 					3

enum FLAGGERS_PLAYER_INFO
{
	bool:FLdesynced,
	bool:FLlagger,
	bool:FLspawn,

	FLUpdated,
	FLwarns,
	FLAmmo,
	FLPing,
	FLDwarns,

	FLSTimer,
	FLTimer
};

new 
	FLaggers_Player[MAX_PLAYERS][FLAGGERS_PLAYER_INFO];

FL_GetWeaponSlot(weaponid) 
{ 
	switch(weaponid) 
	{ 
		case 0..1:   return 0;
		case 2..9:   return 1;
		case 22..24: return 2;
		case 25..27: return 3;
		case 28..29: return 4;
		case 32:	 return 4;
		case 30..31: return 5;
		case 33..34: return 6;
		case 35..38: return 7;
		case 16..18: return 8;
		case 39:	 return 8;
		case 41..43: return 9;
		case 10..15: return 10;
		case 44..46: return 11;
		case 40:	 return 12;
	} 
	return 0; 
}

IsPlayerLagging(playerid)
{
	if(playerid > MAX_PLAYERS || playerid < 0) return 0;
	return (FLaggers_Player[playerid][FLwarns] > 1);
}

IsPlayerDesynced(playerid) 
{
	if(playerid > MAX_PLAYERS || playerid < 0) return 0;
	return FLaggers_Player[playerid][FLdesynced];
}

//##########################################################################################################//
//################################################[Callbacks]###############################################//
//##########################################################################################################//

forward ysac_Detector(playerid);
public ysac_Detector(playerid)
{
	if(!IsPlayerESC(playerid))
	{
		//Detector de fraude de arma:
		new ysacAmmo,ysacWep;
		for(new s; s<ysac_MAX_WEAPONIDS; s++)
		{
			if(!ysac_IsWeaponValid(s)) continue;
			GetPlayerWeaponData(playerid, ysac_GetWeaponSlot(s), ysacWep, ysacAmmo);
			if(ysac_Weapons[playerid][ysacPlayerWeapons][ysacWep] != ysacWep && !ysac_Player[playerid][ysacWepImmu] && !ysac_IsWeaponSys(ysacWep))
			{
				ysac_ResetPlayerWeapons(playerid);
				CallLocalFunction("OnPlayerGunCheat", "iiii", playerid, ysacWep, ysacAmmo, 1);
				return 0;
			}
			//Detector de fraude de munição:
			if(!ysac_Player[playerid][ysacAmmoImmu] && ysac_Weapons[playerid][ysacPlayerAmmo][ysacWep] < ysacAmmo 
				&& ysac_IsWeaponAmmoable(ysacWep))	
			{
				if(ysac_Player[playerid][ysacASWarns] < ysac_MAX_SPOOF_WARNS)
				{	
					ysac_Player[playerid][ysacASWarns]++;
					SetPlayerAmmo(playerid, ysacWep, ysac_Weapons[playerid][ysacPlayerAmmo][ysacWep]);
				}
				else 
				{
					ysac_Player[playerid][ysacASWarns] = 0;
			   		ysac_ResetPlayerWeapons(playerid);
					CallLocalFunction("OnPlayerGunCheat", "iiii", playerid, ysacWep, ysacAmmo, 2);
				}
				return 0;
			}
		}
	}
	return 1;
}

forward ysac_ProtHandler(handleid, handletype);
public ysac_ProtHandler(handleid, handletype)
{
	switch(handletype)
	{
		case 0:
		{
			ysac_Player[handleid][ysacWepImmu]  = false;
		}
		case 1:
		{
			ysac_Player[handleid][ysacAmmoImmu] = false;
		}
	}
	return 1;
}

forward ysac_DelayRapid(playerid, weapon, ammo);
public ysac_DelayRapid(playerid, weapon, ammo)
{
	if(ysac_Player[playerid][ysacFirstShot] == ysac_Player[playerid][ysacSecondShot])
	{
		ysac_Player[playerid][ysacAntibugTicks]++;
		if(ysac_Player[playerid][ysacAntibugTicks] == ysac_MAX_WARNINGS_FREEZE)
			ysac_Player[playerid][ysacAntibugTicks] = 0;
	}
	ysac_Player[playerid][ysacFirstShot] =0; 
	ysac_Player[playerid][ysacSecondShot]=0; 
	return 1;
}

static ysac_IsWeaponAmmoable(Weapon)
	return ( 22 <= Weapon <= 43 || 16 <= Weapon <= 18  );

static ysac_IsWeaponValid(Weapon)
	return ( 0 <= Weapon <= 18 || 22 <= Weapon <= 46   );

static ysac_IsWeaponSys(Weapon)
	return (Weapon == 46 || Weapon == 0 || Weapon == 40);

static IsPlayerESC(playerid)
	return (GetTickCount() > (ysac_Player[playerid][ysacUpdateTicks]+2000));

static ysac_IsWepRapid(Weapon)
{
	switch(Weapon)
	{
		case 26, 27, 23, 22, 30, 31, 28, 29, 32, 34, 38: return 1;
	}
	return 0;
}

static ysac_GetWeaponSlot(weaponid) 
{ 
	switch(weaponid) 
	{ 
		case 0..1:   return 0;
		case 2..9:   return 1;
		case 22..24: return 2;
		case 25..27: return 3;
		case 28..29: return 4;
		case 32:	 return 4;
		case 30..31: return 5;
		case 33..34: return 6;
		case 35..38: return 7;
		case 16..18: return 8;
		case 39:	 return 8;
		case 41..43: return 9;
		case 10..15: return 10;
		case 44..46: return 11;
		case 40: 	 return 12;
	} 
	return 0; 
}

forward FKI_RJDead(playerid);
public FKI_RJDead(playerid) return FKI_Player[playerid][FkiJustDied] = false;

forward RemoveSlideCheck(playerid);
public RemoveSlideCheck(playerid)
{
	SBA_Player[playerid][possibleslide] =false;

	return 1;
}

forward CheckPlayerSlide(playerid);
public CheckPlayerSlide(playerid)
{
	new SBA_Wep = GetPlayerWeapon(playerid);
	new Float:SBA_Speed = GetPlayerOnFootSpeed(playerid);
	if(SBA_Speed > 15 && GetPlayerSurfingVehicleID(playerid) == INVALID_VEHICLE_ID && IsPAiming(playerid) && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT && SBA_Player[playerid][possibleslide] && 22<=SBA_Wep<=38)
	{
		CallLocalFunction("OnPlayerSlide", "ddf", playerid, SBA_Wep, SBA_Speed);
	}

	return 1;
}

public FL_FixSBug(playerid)
{
	SetPlayerAmmo(playerid, 0, FLaggers_Player[playerid][FLAmmo]);
	FLaggers_Player[playerid][FLspawn] = true;

	return 1;
}

public FL_Cooloff(playerid) 
	return  FLaggers_Player[playerid][FLDwarns]   = 0;

public FL_CheckStats(playerid)
{
	new FL_PING = GetPlayerPing(playerid);

	if(FLaggers_Player[playerid][FLspawn] &&  GetTickCount() < (FLaggers_Player[playerid][FLUpdated]+1500))
	{
		if(FLaggers_Player[playerid][FLwarns] < FL_MAX_WARNINGS)
		{
			//Ping filter:
			if(FL_PING >= FL_MAX_LAG_PING && FLaggers_Player[playerid][FLPing] == FL_INVALID_PLAYER_STATS)
			{
				FLaggers_Player[playerid][FLPing] = FL_PING;
			}

			else if(FL_PING >= FLaggers_Player[playerid][FLPing] && FLaggers_Player[playerid][FLPing] != FL_INVALID_PLAYER_STATS)
			{
				FLaggers_Player[playerid][FLwarns]++, 
				FLaggers_Player[playerid][FLPing] = FL_PING;
			}

			else if(FLaggers_Player[playerid][FLPing] != FL_INVALID_PLAYER_STATS && FL_PING + FL_ADDED_VALUE < FLaggers_Player[playerid][FLPing]) 
			{
				if(FLaggers_Player[playerid][FLwarns] > 0 ) FLaggers_Player[playerid][FLwarns]--;
				FLaggers_Player[playerid][FLPing] = FL_INVALID_PLAYER_STATS;
			}

			else if(FLaggers_Player[playerid][FLPing] != FL_INVALID_PLAYER_STATS) 
			{
				FLaggers_Player[playerid][FLPing] = FL_INVALID_PLAYER_STATS;
			}
		}

		//Final-Stage filter:
		else if(FLaggers_Player[playerid][FLwarns] >= FL_MAX_WARNINGS)
		{
			FLaggers_Player[playerid][FLwarns] = 0;
			#if defined OnPlayerLagout
				OnPlayerLagout(playerid, 1, FL_PING);
			#endif
		}
	
		//Desync filter:
		if(FLaggers_Player[playerid][FLDwarns] < FL_MAX_DESYNC_WARNS)
		{
			new
				FLaggersWep,
				FlaggersAmmo;

			GetPlayerWeaponData(playerid, 0, FLaggersWep, FlaggersAmmo);

			switch(FLaggers_Player[playerid][FLAmmo])
			{
				case 0:
				{
					FLaggers_Player[playerid][FLAmmo] = 1;
					SetPlayerAmmo(playerid, FLaggersWep, 1);
				}
				case 1:
				{
					if(FlaggersAmmo != FLaggers_Player[playerid][FLAmmo])
					{
						if(FLaggers_Player[playerid][FLDwarns] == 0) SetTimerEx("FL_Cooloff", 50000, false, "i", playerid);
						FLaggers_Player[playerid][FLDwarns]++;
						SetPlayerAmmo(playerid, FLaggersWep, FLaggers_Player[playerid][FLAmmo]);
					}
					FLaggers_Player[playerid][FLAmmo] = 0;
					SetPlayerAmmo(playerid, FLaggersWep, 0);
				}
			}
		}

		else if(FLaggers_Player[playerid][FLDwarns] >= FL_MAX_DESYNC_WARNS && !FLaggers_Player[playerid][FLdesynced])
		{
			FLaggers_Player[playerid][FLdesynced] = true;
			#if defined OnPlayerLagout
				OnPlayerLagout(playerid, 2, GetPlayerPing(playerid));
			#endif
		}
	}

	return 1;
}

//##########################################################################################################//
//##################################################[Hooks]#################################################//
//##########################################################################################################//

//Callbacks

public OnPlayerText(playerid, text[])
{
	if(Aspa_Player[playerid][AspaTexttwo] == 0 && Aspa_Player[playerid][AspaTextone] ==0 ) Aspa_Player[playerid][AspaTextone] = GetTickCount(); 
	else if(Aspa_Player[playerid][AspaTextone] != 0 && Aspa_Player[playerid][AspaTexttwo] == 0) Aspa_Player[playerid][AspaTexttwo] = GetTickCount(); 
	
	else if(Aspa_Player[playerid][AspaTextone] != 0 && Aspa_Player[playerid][AspaTexttwo] != 0 && Aspa_Player[playerid][AspaTexttwo] - Aspa_Player[playerid][AspaTextone] < MAX_WAIT_TIME) 
	{ 
		Aspa_Player[playerid][AspaWarns]++;
		switch(Aspa_Player[playerid][AspaWarns])
		{
			case 1:
			{
				KillTimer(Aspa_Player[playerid][AspaRTimer]);
				Aspa_Player[playerid][AspaRTimer] = SetTimerEx("ASPA_RWarns", 1500, false, "i", playerid);
			}
			case 2:
			{
				KillTimer(Aspa_Player[playerid][AspaRTimer]);
				Aspa_Player[playerid][AspaRTimer] = SetTimerEx("ASPA_RWarns", 3000, false, "i", playerid);
			}
			case 3:
			{
				KillTimer(Aspa_Player[playerid][AspaRTimer]);
				Aspa_Player[playerid][AspaWarns] = 0;
				CallLocalFunction("OnPlayerSpamChat", "i", playerid);
			}
		}
		Aspa_Player[playerid][AspaTextone] = 0; 
		Aspa_Player[playerid][AspaTexttwo] = 0; 
		return 0; 
	} 
	else if(Aspa_Player[playerid][AspaTextone] != 0 && Aspa_Player[playerid][AspaTexttwo] != 0 && Aspa_Player[playerid][AspaTexttwo] - Aspa_Player[playerid][AspaTextone] >= MAX_WAIT_TIME) 
	{ 
		Aspa_Player[playerid][AspaTextone] =0; 
		Aspa_Player[playerid][AspaTexttwo] =0; 
	}
	#if defined ysac_OnPlayerText
		return ysac_OnPlayerText(playerid, text[]);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerText
	#undef OnPlayerText
#else
	#define _ALS_OnPlayerText
#endif
 
#define OnPlayerText ysac_OnPlayerText
#if defined ysac_OnPlayerText
	forward ysac_OnPlayerText(playerid, text[]);
#endif

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if( (newkeys & 128) && ( newkeys & 8)  && (newkeys & 2))
	{
		if(!SBA_Player[playerid][possibleslide]) SetTimerEx("RemoveSlideCheck",2000,false,"i",playerid);
		SBA_Player[playerid][possibleslide] =true;
	}
	#if defined ysac_OnPlayerKeyStateChange
		return ysac_OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerKeyStateChange
	#undef OnPlayerKeyStateChange
#else
	#define _ALS_OnPlayerKeyStateChange
#endif
 
#define OnPlayerKeyStateChange ysac_OnPlayerKeyStateChange
#if defined ysac_OnPlayerKeyStateChange
	forward ysac_OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
#endif

public OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ)
{
	//Weapons
	new ysacTempWeap, ysacTempAmmos;
	ysacTempWeap = GetPlayerWeapon(playerid);
	ysacTempAmmos= GetPlayerAmmo(playerid);

	if(ysac_Player[playerid][ysacSecondTick] == 0 && ysac_Player[playerid][ysacFirstTick] ==0 )
	{
		ysac_Player[playerid][ysacFirstTick] = GetTickCount(); 
		ysac_Player[playerid][ysacFirstShot] = ysacTempAmmos;
		ysac_Player[playerid][ysacConstWep]  = ysacTempWeap;
	}
	else if(ysac_Player[playerid][ysacFirstTick] != 0 && ysac_Player[playerid][ysacSecondTick] == 0)
	{
		ysac_Player[playerid][ysacSecondTick] = GetTickCount(); 
		ysac_Player[playerid][ysacSecondShot] = ysacTempAmmos;
	} 
	
	else if(ysac_Player[playerid][ysacFirstTick] != 0 && ysac_Player[playerid][ysacSecondTick] != 0 ) 
	{
		if(ysac_Player[playerid][ysacSecondTick] - ysac_Player[playerid][ysacFirstTick] < ysac_MAX_RAPID_TIME_NORMAL && ysac_Player[playerid][ysacConstWep] == ysacTempWeap && !ysac_IsWepRapid(ysacTempWeap) && GetPlayerState(playerid) != 3)
		
			CallLocalFunction("OnPlayerGunCheat", "iiii", playerid, ysacTempWeap, ysacTempAmmos, 4);
			ysac_Player[playerid][ysacFirstTick] = 0; 
			ysac_Player[playerid][ysacSecondTick]= 0; 
			return 0; 
		}
		else 
		{
			ysac_Player[playerid][ysacFirstTick] =0; 
			ysac_Player[playerid][ysacSecondTick]=0; 
		}

		if(ysac_Player[playerid][ysacFirstShot] == ysac_Player[playerid][ysacSecondShot] && ysac_Player[playerid][ysacConstWep] == ysacTempWeap 
			&& ysac_IsWeaponAmmoable(ysacTempWeap) && !ysac_IsWepRapid(ysacTempWeap) && GetPlayerState(playerid) != 3)
		
			ysac_Player[playerid][ysacAntibugTicks]++;
			if(ysac_Player[playerid][ysacAntibugTicks] == ysac_MAX_WARNINGS_FREEZE)
			{
				ysac_Player[playerid][ysacFirstShot] =0; 
				ysac_Player[playerid][ysacSecondShot]=0; 
				ysac_Player[playerid][ysacAntibugTicks] = 0;
				if(!ysac_IsPlayerPaused(playerid))
				{
					CallLocalFunction("OnPlayerGunCheat", "iiii", playerid, ysacTempWeap, ysacTempAmmos, 3);
				}
				return 0;
			}
		}
		else if(ysac_Player[playerid][ysacConstWep] == ysacTempWeap && ysac_IsWeaponAmmoable(ysacTempWeap) && (ysac_IsWepRapid(ysacTempWeap) || GetPlayerState(playerid) == 3))
		
			KillTimer(ysac_Player[playerid][ysacRepeater]);
			ysac_Player[playerid][ysacRepeater] = SetTimerEx("ysac_DelayRapid", 700, false, "iii", playerid, ysacTempWeap, ysacTempAmmos);
		}
		else 
		{
			ysac_Player[playerid][ysacFirstShot] =0; 
			ysac_Player[playerid][ysacSecondShot]=0; 
		}
	}

	//Fake-kill
	switch(hittype)
	{
		case BULLET_HIT_TYPE_PLAYER:
		{
			FKI_Player[hitid][FkiDmgChk] = true;
		}
		case BULLET_HIT_TYPE_VEHICLE:
		{
			foreach(new i: Player)
			{
				if(GetPlayerVehicleID(i) == hitid) FKI_Player[i][FkiDmgChk] = true;
			}
		}
	}
	#if defined ysac_OnPlayerWeaponShot
		return ysac_OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerWeaponShot
	#undef OnPlayerWeaponShot
#else
	#define _ALS_OnPlayerWeaponShot
#endif
 
#define OnPlayerWeaponShot ysac_OnPlayerWeaponShot
#if defined ysac_OnPlayerWeaponShot
	forward ysac_OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ);
#endif

public OnPlayerDisconnect(playerid)
{
	//Weapons
	KillTimer(ysac_Player[playerid][ysacCheckTimer]);

	ysac_Player[playerid][ysacAmmoImmu] = false;
	ysac_Player[playerid][ysacWepImmu]  = false;
	ysac_Player[playerid][ysacAntibugTicks] = 0;
	ysac_Player[playerid][ysacASWarns] = 0;

	//Fake-Kill
	FKI_Player[playerid][FkiSpwnChk] = false;
	FKI_Player[playerid][FkiDmgChk] = false;
	FKI_Player[playerid][FkiWTicks] = 0;

	//Slide-Bug
	SBA_Player[playerid][possibleslide]=false;
	KillTimer(SBA_Player[playerid][slidecheck]);

	//Chat-Spam
	Aspa_Player[playerid][AspaTextone] = 0; 
	Aspa_Player[playerid][AspaTexttwo] = 0; 

	//Dessicronização
	FLaggers_Player[playerid][FLdesynced] = false;
	FLaggers_Player[playerid][FLlagger]   = false;
	FLaggers_Player[playerid][FLspawn]	= false;
	FLaggers_Player[playerid][FLAmmo]	 = 0;
	FLaggers_Player[playerid][FLwarns]	= 0;
	FLaggers_Player[playerid][FLDwarns]   = 0;
	KillTimer(FLaggers_Player[playerid][FLTimer]);

	#if defined ysac_OnPlayerDisconnect
		return ysac_OnPlayerDisconnect(playerid);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
 
#define OnPlayerDisconnect ysac_OnPlayerDisconnect
#if defined ysac_OnPlayerDisconnect
	forward ysac_OnPlayerDisconnect(playerid);
#endif

public OnPlayerDeath(playerid, killerid, reason)
{
	//FakeKill
	if(!FKI_Player[playerid][FkiSpwnChk] || FKI_Player[playerid][FkiJustDied])
	{
		CallLocalFunction("OnPlayerFakeKill", "iiii", playerid, killerid, reason, 2);
		return 0;
	}
	if(!FKI_Player[playerid][FkiDmgChk] && killerid != INVALID_PLAYER_ID  && IsPlayerConnected(killerid))
	{
		if(!IsKillFalse(reason)) 
		{
			#if defined FKI_OnPlayerDeath
				return FKI_OnPlayerDeath(playerid, killerid, reason);
			#else
				return 1;
			#endif
		}
		if(GetPlayerState(killerid) == 2 && !FKI_IsAPlane(GetPlayerVehicleID(playerid)))
		{
			static Float:TPX, Float:TPY, Float:TPZ;
			GetPlayerPos(killerid, TPX, TPY, TPZ);
			if(!IsPlayerInRangeOfPoint(playerid, 5.0, TPX, TPY, TPZ))
			{
				CallLocalFunction("OnPlayerFakeKill", "iiii", playerid, killerid, reason, 1);
				return 0;
			}
		}
		else if(!FKI_IsWeaponValid(reason) || reason == 0)
		{
			FKI_Player[playerid][FkiWTicks]++;
			if(FKI_Player[playerid][FkiWTicks] == FKI_MAX_ERROR_WARNS) 
			{
				FKI_Player[playerid][FkiWTicks] = 0;
				CallLocalFunction("OnPlayerFakeKill", "iiii", playerid, killerid, reason, 1);
			}
		}
		else CallLocalFunction("OnPlayerFakeKill", "iiii", playerid, killerid, reason, 1);
	}
	KillTimer(FKI_Player[playerid][FkiDeTimer]);
	FKI_Player[playerid][FkiDeTimer] = SetTimerEx("FKI_RJDead", 5000, false, "i", playerid);

	FKI_Player[playerid][FkiJustDied] = true;
	FKI_Player[playerid][FkiSpwnChk] = false;
	FKI_Player[playerid][FkiDmgChk] = false;

	//Dessicronização
	FLaggers_Player[playerid][FLspawn] = false;
	#if defined ysac_OnPlayerDeath
		return ysac_OnPlayerDeath(playerid, killerid, reason);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerDeath
	#undef OnPlayerDeath
#else
	#define _ALS_OnPlayerDeath
#endif

public OnPlayerTakeDamage(playerid, issuerid, Float:amount, weaponid, bodypart)
{
	if(issuerid != INVALID_PLAYER_ID && IsPlayerConnected(issuerid))
		FKI_Player[playerid][FkiDmgChk] = true;

	#if defined ysac_OnPlayerTakeDamage
		return ysac_OnPlayerTakeDamage(playerid, issuerid, Float:amount, weaponid, bodypart);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerTakeDamage
	#undef OnPlayerTakeDamage
#else
	#define _ALS_OnPlayerTakeDamage
#endif
 
#define OnPlayerTakeDamage ysac_OnPlayerTakeDamage
#if defined ysac_OnPlayerTakeDamage
	forward ysac_OnPlayerTakeDamage(playerid, issuerid, Float:amount, weaponid, bodypart);
#endif

public OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid, bodypart)
{
	if(damagedid != INVALID_PLAYER_ID && IsPlayerConnected(damagedid))
		FKI_Player[damagedid][FkiDmgChk] = true;

	#if defined ysac_OnPlayerGiveDamage
		return ysac_OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid, bodypart);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerGiveDamage
	#undef OnPlayerGiveDamage
#else
	#define _ALS_OnPlayerGiveDamage
#endif
 
#define OnPlayerGiveDamage ysac_OnPlayerGiveDamage
#if defined ysac_OnPlayerGiveDamage
	forward ysac_OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid, bodypart);
#endif

#define OnPlayerDeath ysac_OnPlayerDeath
#if defined ysac_OnPlayerDeath
	forward ysac_OnPlayerDeath(playerid, killerid, reason);
#endif

public OnPlayerSpawn(playerid)
{
	//Weapons
	for(new s; s<ysac_MAX_WEAPONIDS; s++)
	{
		ysac_Weapons[playerid][ysacNewAmmo][s] = 0;
		ysac_Weapons[playerid][ysacOldAmmo][s] = 0;
	}
	ysac_ResetPlayerWeapons(playerid);

	//FakeKill
	FKI_Player[playerid][FkiSpwnChk] = true;
	
	//Dessicronização
	KillTimer(FLaggers_Player[playerid][FLSTimer]);
	FLaggers_Player[playerid][FLSTimer] = SetTimerEx("FL_FixSBug", 3000, false, "i", playerid);

	#if defined ysac_OnPlayerSpawn
		return ysac_OnPlayerSpawn(playerid);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerSpawn
	#undef OnPlayerSpawn
#else
	#define _ALS_OnPlayerSpawn
#endif
 
#define OnPlayerSpawn ysac_OnPlayerSpawn
#if defined ysac_OnPlayerSpawn
	forward ysac_OnPlayerSpawn(playerid);
#endif

public OnPlayerConnect(playerid)
{
	//Weapons
	ysac_Player[playerid][ysacCheckTimer] = SetTimerEx("ysac_Detector", 1000, true, "i", playerid);
	ysac_ResetPlayerWeapons(playerid);

	//Anti Fake-Connect
	if(AFC_IsPlayerBot(playerid))
		Kick(playerid);

	//Anti Slide-Bug
	SBA_Player[playerid][slidecheck] = SetTimerEx("CheckPlayerSlide",1000,true,"d",playerid);

	//Dessicronização
	FLaggers_Player[playerid][FLPing]	 = FL_INVALID_PLAYER_STATS;
	FLaggers_Player[playerid][FLTimer]	= SetTimerEx("FL_CheckStats", FL_MAX_WAIT_TIME*1000, true, "i", playerid);
	#if defined ysac_OnPlayerConnect
		return ysac_OnPlayerConnect(playerid);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif
 
#define OnPlayerConnect ysac_OnPlayerConnect
#if defined ysac_OnPlayerConnect
	forward ysac_OnPlayerConnect(playerid);
#endif

//Funções 

stock ysac_GivePlayerWeapon(playerid, weaponid, ammo)
{
	//Weapons
	if(playerid <0 || playerid > MAX_PLAYERS) return 0;
	if(!ysac_IsWeaponValid(weaponid) || (ysac_IsWeaponAmmoable(weaponid) && ammo ==0)) return 0;
	ysac_Weapons[playerid][ysacNewAmmo][weaponid] = 0;
	ysac_Weapons[playerid][ysacOldAmmo][weaponid] = 0;
	if(!ysac_Player[playerid][ysacWepImmu]) SetTimerEx("ysac_ProtHandler", ysac_IMMU_TIME, false, "d",playerid, 0);
	ysac_Player[playerid][ysacWepImmu] = true;
	switch(ysac_IsWeaponAmmoable(weaponid))
	{
		case 0:
		{
			if(ysac_Weapons[playerid][ysacPlayerWeapons][weaponid] == weaponid)
			{
				ysac_Weapons[playerid][ysacPlayerAmmo][weaponid] = 1;
				GivePlayerWeapon(playerid, weaponid, 1);
			}
			else
			{
				ysac_Weapons[playerid][ysacPlayerWeapons][weaponid] = weaponid;
				ysac_Weapons[playerid][ysacPlayerAmmo][weaponid] = 1;
				GivePlayerWeapon(playerid, weaponid, 1);
			}
		}
		case 1:
		{
			if(ysac_Weapons[playerid][ysacPlayerWeapons][weaponid] == weaponid)
			{
				if(!ysac_Player[playerid][ysacAmmoImmu]) SetTimerEx("ysac_ProtHandler",ysac_IMMU_TIME,false,"d",playerid, 1);
				ysac_Player[playerid][ysacAmmoImmu] = true;
				new ysacFixWep, ysacFixAmmo;
				GivePlayerWeapon(playerid, weaponid, ammo);
				GetPlayerWeaponData(playerid, ysac_GetWeaponSlot(weaponid), ysacFixWep, ysacFixAmmo);
				ysac_Weapons[playerid][ysacPlayerAmmo][weaponid] = ysacFixAmmo + ammo;
			}
			else
			{
				ysac_Weapons[playerid][ysacPlayerWeapons][weaponid] = weaponid;
				ysac_Weapons[playerid][ysacPlayerAmmo][weaponid] = ammo;
				GivePlayerWeapon(playerid, weaponid, ammo);
			}
		}	
	}

	//Dessicronização
	if(playerid > MAX_PLAYERS || playerid < 0) return 0;
	if(FL_GetWeaponSlot(weaponid) == 0) 
	{
		switch(weaponid)
		{
			case 0:
			{
				GivePlayerWeapon(playerid, weaponid, ammo);
				SetPlayerAmmo(playerid, 0, FLaggers_Player[playerid][FLAmmo]);
			}
			case 1:
			{
				GivePlayerWeapon(playerid, weaponid, ammo);
				SetPlayerAmmo(playerid, 0, FLaggers_Player[playerid][FLAmmo]);
			}
		}
		return 1;
	}
	GivePlayerWeapon(playerid, weaponid, ammo);
	return 1;
}
#if defined _ALS_GivePlayerWeapon
    #undef GivePlayerWeapon
#else
    #define _ALS_GivePlayerWeapon
#endif
 
#define GivePlayerWeapon ysac_GivePlayerWeapon

stock ysac_SetPlayerAmmo(playerid, weaponid, ammo)
{
	//Weapons
	if(playerid <0 || playerid > MAX_PLAYERS) return 0;
	if(!ysac_IsWeaponValid(weaponid) || (ysac_IsWeaponAmmoable(weaponid) && ammo ==0)) return 0;
	ysac_Weapons[playerid][ysacNewAmmo][weaponid] = 0;
	ysac_Weapons[playerid][ysacOldAmmo][weaponid] = 0;

	if(!ysac_Player[playerid][ysacWepImmu]) SetTimerEx("ysac_ProtHandler", ysac_IMMU_TIME, false, "d",playerid, 0);
	ysac_Player[playerid][ysacWepImmu] = true;

	switch(ysac_IsWeaponAmmoable(weaponid))
	{
		case 0:
		{
			ysac_Weapons[playerid][ysacPlayerAmmo][weaponid] = 1;
			return SetPlayerAmmo(playerid, weaponid, 1);
		}
		case 1:
		{
			ysac_Weapons[playerid][ysacPlayerAmmo][weaponid] = ammo;
			return SetPlayerAmmo(playerid, weaponid, ammo);
		}
	}

	//Dessicronização
	if(playerid > MAX_PLAYERS || playerid < 0) return 0;
	return (FL_GetWeaponSlot(weaponid) == 0) ? SetPlayerAmmo(playerid, 0, FLaggers_Player[playerid][FLAmmo]) : SetPlayerAmmo(playerid, weaponid, ammo);
}
#if defined _ALS_SetPlayerAmmo
    #undef SetPlayerAmmo
#else
    #define _ALS_SetPlayerAmmo
#endif
 
#define SetPlayerAmmo ysac_SetPlayerAmmo

stock ysac_ResetPlayerWeapons(playerid)
{
	//Weapons
	if(playerid <0 || playerid > MAX_PLAYERS) return 0;
	if(!ysac_Player[playerid][ysacWepImmu]) SetTimerEx("ysac_ProtHandler",ysac_IMMU_TIME,false,"d",playerid, 0);
	ysac_Player[playerid][ysacWepImmu] = true;

	for(new s; s<ysac_MAX_WEAPONIDS; s++)
	{
		if(ysac_Weapons[playerid][ysacPlayerWeapons][s] != 0)
		{
			ysac_Weapons[playerid][ysacPlayerWeapons][s] = 0;
			ysac_Weapons[playerid][ysacPlayerAmmo][s] = 0;
		}
	}

	if(playerid > MAX_PLAYERS || playerid < 0) return 0;
	ResetPlayerWeapons(playerid);
	return SetPlayerAmmo(playerid, 0, FLaggers_Player[playerid][FLAmmo]);
}
#if defined _ALS_ResetPlayerWeapons
    #undef ResetPlayerWeapons
#else
    #define _ALS_ResetPlayerWeapons
#endif
 
#define ResetPlayerWeapons ysac_ResetPlayerWeapons