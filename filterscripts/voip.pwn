#include <a_samp>
#include <sampvoice>

/* ~~ Variaveis */
new SV_LSTREAM: lstream[ MAX_PLAYERS ] = { SV_NULL, ... };

public SV_VOID:OnPlayerActivationKeyPress(SV_UINT:playerid, SV_UINT:keyid)
{
    if( keyid == 0x42 && lstream[ playerid ] ) SvAttachSpeakerToStream( lstream[ playerid ], playerid );
}
public SV_VOID:OnPlayerActivationKeyRelease(SV_UINT:playerid,SV_UINT:keyid)
{
    if (keyid == 0x42 && lstream[ playerid ] ) SvDetachSpeakerFromStream( lstream[ playerid ], playerid );
}
public OnFilterScriptInit()
{
	return 1;
}
public OnFilterScriptExit()
{
	return 1;
}
public OnPlayerConnect( playerid )
{
	if( SvGetVersion( playerid ) == SV_NULL)
    {
        SendClientMessage( playerid, -1, "Could not find plugin sampvoice.");
    }
    // Checking for a microphone
    else if( SvHasMicro( playerid ) == SV_FALSE)
    {
        SendClientMessage(playerid, -1, "The microphone could not be found.");
    }
    if(( lstream[ playerid ] = SvCreateDLStreamAtPlayer( 40.0, SV_INFINITY, playerid, 0x00ff00ff, "Local" )))
    {
    // Assign microphone activation keys to the player
        SvAddKey( playerid, 0x42 );
        SvAddKey( playerid, 0x5A );
    }
	return 1;
}
public OnPlayerDisconnect( playerid, reason)
{
    if( lstream[ playerid ] )
	{
		SvDeleteStream( lstream[ playerid ] );
		lstream[ playerid ] = SV_NULL;
	}
	return 1;
}
