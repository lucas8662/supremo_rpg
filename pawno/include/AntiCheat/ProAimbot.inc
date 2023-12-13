public OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ)
{
	if(hittype == BULLET_HIT_TYPE_PLAYER)
   	{
        if(!( -1000.0 <= fX <= 1000.0 ) || !( -1000.0 <= fY <= 1000.0 ) || !( -1000.0 <= fZ <= 1000.0 ))
        {
        	CallLocalFunction("OnPlayerCheater", "dds", playerid, 22, " ");
			return 0;
        }

		new Float:fOrigin[3], Float:fHitPos[3], Float:dist, Float:dist2;
		GetPlayerLastShotVectors(playerid, fOrigin[0], fOrigin[1], fOrigin[2], fHitPos[0], fHitPos[1], fHitPos[2]);

		dist = GetPlayerDistanceFromPoint(hitid, fHitPos[0], fHitPos[1], fHitPos[2]);
        dist2 = GetPlayerDistanceFromPoint(playerid, fHitPos[0], fHitPos[1], fHitPos[2]);

        CriarBolinha(playerid, fHitPos[0], fHitPos[1], fHitPos[2]);

	    if(dist2 < 4.0 && dist >= 30.0 && dist < 300.0 && GetPlayerSurfingVehicleID(playerid) == INVALID_VEHICLE_ID && GetPlayerState(hitid) == PLAYER_STATE_ONFOOT)
	    {
	        CallLocalFunction("OnPlayerCheater", "dds", playerid, 23, " ");
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