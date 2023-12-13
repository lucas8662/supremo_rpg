#include <a_samp>
#include <YSI_Coding\y_hooks>

#define AC_MAX_CODES                    53
#define AC_MAX_CODE_LENGTH              (3 + 1)
#define AC_MAX_CODE_NAME_LENGTH         (500)

static const AC_CODE_NAME[AC_MAX_CODES][AC_MAX_CODE_NAME_LENGTH] =  
{ 
    {"AirBreak (onfoot)"}, 
    {"AirBreak (in vehicle)"}, 
    {"Teleport (onfoot)"}, 
    {"Teleport (in vehicle)"}, 
    {"Teleport (into/between vehicles)"}, 
    {"Teleport (vehicle to player)"}, 
    {"Teleport (pickups)"}, 
    {"FlyHack (onfoot)"}, 
    {"FlyHack (in vehicle)"}, 
    {"SpeedHack (onfoot)"}, 
    {"SpeedHack (in vehicle)"}, 
    {"Health hack (in vehicle)"}, 
    {"Health hack (onfoot)"}, 
    {"Armour hack"}, 
    {"Money hack"}, 
    {"Weapon hack"}, 
    {"Ammo hack (add)"}, 
    {"Ammo hack (infinite)"}, 
    {"Special actions hack"}, 
    {"GodMode from bullets (onfoot)"}, 
    {"GodMode from bullets (in vehicle)"}, 
    {"Invisible hack"}, 
    {"Lagcomp-spoof"}, 
    {"Tuning hack"}, 
    {"Parkour mod"}, 
    {"Quick turn"}, 
    {"Rapid fire"}, 
    {"FakeSpawn"}, 
    {"FakeKill"}, 
    {"Pro Aim"}, 
    {"CJ run"}, 
    {"CarShot"}, 
    {"CarJack"}, 
    {"UnFreeze"}, 
    {"AFK Ghost"}, 
    {"Full Aiming"}, 
    {"Fake NPC"}, 
    {"Reconnect"}, 
    {"High ping"}, 
    {"Dialog hack"}, 
    {"Sandbox"}, 
    {"Invalid version"}, 
    {"Rcon hack"}, 
    {"Tuning crasher"}, 
    {"Invalid seat crasher"}, 
    {"Dialog crasher"}, 
    {"Attached object crasher"}, 
    {"Weapon Crasher"}, 
    {"Connects to one slot"}, 
    {"Flood callback functions"}, 
    {"Flood change seat"}, 
	{"Anti-DoS"},
    {"Anti-NOPs"}
}; 

forward OnCheatDetected(playerid, ip_address[], type, code);
public OnCheatDetected(playerid, ip_address[], type, code)
{
	if(type) BlockIpAddress(ip_address, 0);
	else
	{
        if (AdminDuty[playerid] != Modo_Jogador)
            return 0;

		switch(code)
		{
			case 2,4,9,10,16,18,19,20,21,27,38,39,40,41,44,47,48,49,50,52: return 0;
			case 5, 6, 11, 22, 32: return 1;
			case 14: // Money Cheat
            {
                ResetPlayerMoney(playerid);
        		GivePlayerMoney(playerid, UserInfo[playerid][user_dinheiro]);
				return 0;
            }
			default:
			{
				new strtmp[sizeof KICK_MSG];
				format(strtmp, sizeof strtmp, KICK_MSG, code);
				SendClientMessage(playerid, -1, strtmp);
			}
		}
		SendAdminMessage(COLOR_LIGHTRED, fmat_return("AntiCheat: %s foi kickado por suspeitas de uso de cheats %s(#%03d)", PlayerName(playerid), AC_CODE_NAME[code], code));
		EscreverLogs("logs_anticheat", "%s foi kickado por suspeitas de uso de cheats %s(#%03d).", PlayerName(playerid), AC_CODE_NAME[code], code);
		AntiCheatKickWithDesync(playerid, code);
	}
	return 1;
}