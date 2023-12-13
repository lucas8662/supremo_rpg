/*
Anti fake kill by Rogue 2018/3/25
----
Last Updated April 5th.
-=-=-=-=-=-=-
Callbacks:
----------
OnPlayerFakeKill(playerid, spoofedid, spoofedreason, faketype);
-------------
playerid = the cheater who did a fake kill action
spoofedid = the player alleged to have killed the cheater
spoofedreason = the weapon used in the process (spoofed by the cheater)
faketype 1 = normal fake kill (one time)
faketype 2 = spammed fake kill (must kick or ban instantly)
-=-=-=-=-=--=-=-=
*/
#include <YSI_Coding\y_hooks>

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

forward FKI_RJDead(playerid);
public FKI_RJDead(playerid) return FKI_Player[playerid][FkiJustDied] = false;

hook OnPlayerDisconnect(playerid, reason)
{
	FKI_Player[playerid][FkiSpwnChk]= false;
	FKI_Player[playerid][FkiDmgChk] = false;
	FKI_Player[playerid][FkiWTicks] = 0;
	return 1;
}

hook OnPlayerDeath(playerid, killerid, reason)
{
	if( IsPlayerNPC( playerid ) || IsPlayerNPC( killerid )) return 1;
	if(!FKI_Player[playerid][FkiSpwnChk] || FKI_Player[playerid][FkiJustDied])
	{
		OnPlayerFakeKill( killerid, playerid, reason, 2 );
		return 0;
	}
	if(!FKI_Player[playerid][FkiDmgChk] && killerid != INVALID_PLAYER_ID  && IsPlayerConnected(killerid))
	{
		if(!IsKillFalse(reason)) 
		{
			return 1;
		}
		if(GetPlayerState(killerid) == 2 && !FKI_IsAPlane(GetPlayerVehicleID(playerid)))
		{
			static Float:TPX, Float:TPY, Float:TPZ;
			GetPlayerPos(killerid, TPX, TPY, TPZ);
			if(!IsPlayerInRangeOfPoint(playerid, 5.0, TPX, TPY, TPZ))
			{
				OnPlayerFakeKill( killerid, playerid, reason, 1);
				return 0;
			}
		}
		else if(!FKI_IsWeaponValid(reason) || reason == 0)
		{
			FKI_Player[playerid][FkiWTicks]++;
			if(FKI_Player[playerid][FkiWTicks] == FKI_MAX_ERROR_WARNS) 
			{
				FKI_Player[playerid][FkiWTicks] = 0;
				OnPlayerFakeKill( killerid, playerid, reason, 1);
			}
		}
		else OnPlayerFakeKill( killerid, playerid, reason, 1);
	}
	KillTimer(FKI_Player[playerid][FkiDeTimer]);
	FKI_Player[playerid][FkiDeTimer] = SetTimerEx("FKI_RJDead", 5000, false, "i", playerid);

	FKI_Player[playerid][FkiJustDied] = true;
	FKI_Player[playerid][FkiSpwnChk] = false;
	FKI_Player[playerid][FkiDmgChk] = false;
	return 1;
}
hook OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid, bodypart)
{
	if(damagedid != INVALID_PLAYER_ID && IsPlayerConnected(damagedid))
	{
		FKI_Player[damagedid][FkiDmgChk] = true;
	}
	return 1;
}
hook OnPlayerTakeDamage(playerid, issuerid, Float:amount, weaponid, bodypart)
{
	if(issuerid != INVALID_PLAYER_ID && IsPlayerConnected(issuerid))
	{
		FKI_Player[playerid][FkiDmgChk] = true;
	}
	return 1;
}
hook OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ)
{
	switch(hittype)
	{
		case BULLET_HIT_TYPE_PLAYER:
		{
			FKI_Player[hitid][FkiDmgChk] = true;
		}
		case BULLET_HIT_TYPE_VEHICLE:
		{
			for(new i, j = GetPlayerPoolSize(); i <= j; i++)
			{
				if(GetPlayerVehicleID(i) == hitid) FKI_Player[i][FkiDmgChk] = true;
			}
		}
	}
	return 1;
}
hook OnPlayerSpawn(playerid)
{
	FKI_Player[playerid][FkiSpwnChk] = true;
	return 1;
}

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