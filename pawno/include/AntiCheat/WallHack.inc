public OnGameModeInit()
{
	SetTimer("WallHack", 500, true);
	#if defined ysac_OnGameModeInit
		return ysac_OnGameModeInit();
	#else
		return 1;
	#endif
}
#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif
 
#define OnGameModeInit ysac_OnGameModeInit
#if defined ysac_OnGameModeInit
	forward ysac_OnGameModeInit();
#endif

forward WallHack();
public WallHack()
{
	foreach(new playerid: Player)
    {
    	if(CheckConnect(playerid))
    	{
    		foreach(new i: Player)
	        {
	        	if(CheckConnect(i))
	        	{
	        		if(i == playerid)    continue;
		            if(GetPlayerDistanceFromPlayer(playerid, i) <= distplayer)
		            {
		                ShowPlayerNameTagForPlayer(playerid,i,true);
		            }
		            else
		            {
		                ShowPlayerNameTagForPlayer(playerid,i,false);
		            }
	        	}
		            
	        }
    	}
	        
    }
}