#define IN_LOCAL	true
#define IN_MAINTENANCE false
#define FECHAR_ABERTURA         0
#define ANO_ABERTURA            2023
#define DIA_ABERTURA            17
#define MES_ABERTURA            6
#define HORA_ABERTURA           18
#define MINUTO_ABERTURA         00
#define SEGUNDO_ABERTURA        00
#define SENHA_SERVIDOR          "167943SUPREMO"
#define	SECONDS_TO_LOGIN 	    120

#if IN_LOCAL == false
    #define host        "127.0.0.1"
    #define User        "supremorpg"
    #define DB          "rpg"
    #define Pass        "q*65XxfN5Iv2$0Wr"
#else
    #define host        "127.0.0.1"
    #define User        "root"
    #define DB          "rpg"
    #define Pass        ""
#endif

#define SCRIPT_VERSION_MAIOR                            "1"
#define SCRIPT_VERSION_MENOR                            "0"
#define SCRIPT_VERSION_PATCH                            ".9"
#define SCRIPT_VERSION_NAME                             "SUPREMO:RPG"
#define SCRIPT_VERSION_SIGL                             "Beta"
#define SVVERSAO                ""SCRIPT_VERSION_NAME" - v"SCRIPT_VERSION_MAIOR"."SCRIPT_VERSION_MENOR""SCRIPT_VERSION_PATCH""
#define MPNOME                  "language PT-BR | Brasil"
#define GMDATE                  "04/01/2021"
#define RODAPEVERSION           "versao: ~w~"SCRIPT_VERSION_MAIOR"."SCRIPT_VERSION_MENOR""SCRIPT_VERSION_PATCH" ~b~~r~"SCRIPT_VERSION_SIGL""
#define NOMESERVER              "hostname [BR/PT] Supremo RPG [RPG versao "SCRIPT_VERSION_MAIOR"."SCRIPT_VERSION_MENOR""SCRIPT_VERSION_PATCH"]"
#define SITE_URL                "supremorpg.com"
#define LOJA_URL                "loja.supremorpg.com"
#define RADIO_URL               "radio."

//Sistema de Perm Full

#define NOME_SCRIPTER1   "FlaTz"
#define NOME_SCRIPTER2   "unfadedLIGHT"
#define NOME_SCRIPTER3   "san"