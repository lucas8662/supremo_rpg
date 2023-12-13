#define STREAMER_DEFAULT_OBJECT_STREAMDISTANCE 200.0
#define PASTA_PUNIDOS "Punidos/%s.ini"
#define DestroyDynamicObjectEx(%0) 	if(IsValidDynamicObject(%0)) DestroyDynamicObject(%0),%0 = -1
#define IsPlayerAndroid(%0)         GetPVarInt(%0, "NotAndroid") == 0 && !IsPlayerNPC(%0)
#define forLoop(%0,%1) 				for(new it_%0 = 0, %0=0, sen_%0 = %1; %0 < sen_%0 && it_%0 < sen_%0; %0++, it_%0++)
#define     MAX_COFRES          (50)
#define     COFRE_COOLDOWN      1800000
#define     MAX_OBJETOSLIST     24
#define     MAX_OBJETOS         (1000)

#if defined MAX_PLAYERS
    #undef MAX_PLAYERS
    #define MAX_PLAYERS (503)
#endif

#if defined MAX_VEHICLES
    #undef MAX_VEHICLES
    #define MAX_VEHICLES (1500)
#endif

#define GetVehicleBoot(%0,%1,%2,%3) \
    (GetVehicleOffset((%0), VEHICLE_OFFSET_BOOT, %1, %2, %3))

#define GetVehicleHood(%0,%1,%2,%3) \
    (GetVehicleOffset((%0), VEHICLE_OFFSET_HOOD, %1, %2, %3))

#define GetVehicleRoof(%0,%1,%2,%3) \
    (GetVehicleOffset((%0), VEHICLE_OFFSET_ROOF, %1, %2, %3))

#define HTTP_IP_API_URL				"ip-api.com/csv"
#define HTTP_IP_API_END         	"?fields=country,countryCode,region,regionName,city,zip,lat,lon,timezone,isp,org,as,reverse,query,status,message"
#define HORA_MANHA              10
#define HORA_TARDE              20
#define HORA_NOITE              0
#define HORA_MADRUGADA          5
#define MAX_ORGS                    25
#define LEVEL_MULTIPLER             7
#define MAX_LEVEL                   150
#define COFRE_TIMER                 1800000
#define distplayer          50.0
#define public:do%0(%1) \
        forward%0(%1); \
        public%0(%1)
#define minrand(%0,%1) 			random(%1-%0)+%0
#define HASH_ENCRYPT 			"78sdjs86d2h"
#define vMultiplicador          0.00200
#define DestroyDynamic3DTextLabelEx(%0) if(IsValidDynamic3DTextLabel(%0)) DestroyDynamic3DTextLabel(%0),%0 = Text3D:-1
#define FREEZE_TIME 			2000
#define VWMorro                 55
#define VWCasarao               56
#define MAX_CONNECTIONS_FROM_IP 5
#define GasMax                  200
// ~~ Macros
#define Comando(%0) 			cmd:%0(playerid, params[])
#define ReturnCommand(%0) 		callcmd::%0(playerid, "")
#define Loop:%0(%1,%2)          for(new %0 = %1; %0 < %2; %0 ++)
#define LoopL:%0(%1,%2)         for(new %0 = %1; %0 != %2; %0 ++)
#define RegisterIter:%1; 		forward Iter@@@%1(); public Iter@@@%1() { Iter_Init(%1); }
#define GetOrgCategoria(%0) 	OrgsNames[%0][Categoria]
#define GetPlayerCash(%0)   	UserInfo[%0][user_cash]
#define STREAMER_ARRAY_PORTINHA         115
#define STREAMER_ARRAY_PORTAO           116
#define STREAMER_ARRAY_DERRUBAR         117
#define STREAMER_ARRAY_PORTAOPLAYER     118
#define STREAMER_ARRAY_CELAS            119
#define STREAMER_ARRAY_SOMCARRO         120
#define STREAMER_ARRAY_PORTAORG         121
#define STREAMER_ARRAY_BATERCARTAO      122
#define STREAMER_ARRA_AREANEUTRA        123
#define STREAMER_ARRAY_TRS              125
#define STREAMER_ARRAY_TRFBD            126
#define STREAMER_ARRAY_LIXEIRAS         127
#define STREAMER_ARRAY_MINAS            128
#define STREAMER_ARRAY_FAVELA           129
#define STREAMER_ARRAY_CP               130

#define MAX_EMPREGOS            20