CarregarActors()
{
    _CreateDynamicActorEx("\n{E6E68C}Comerciante negro{FFFFFF}\n{FFFFFF}Pressione {DBED15}'Y'{FFFFFF} para interagir\n{E6E68C}Jailson", 143, 1760.5913,-2608.4773,114.5923,177.2195, MercadoNegroVW, 8.0);
    _CreateDynamicActorEx("\n{E6E68C}Comerciante negro{FFFFFF}\n{FFFFFF}Pressione {DBED15}'Y'{FFFFFF} para interagir\n{E6E68C}Ricardo", 30, 1742.9548,-2612.6118,114.5996,271.9056, MercadoNegroVW, 8.0);
    _CreateDynamicActorEx("\n{E6E68C}Comerciante negro{FFFFFF}\n{FFFFFF}Pressione {DBED15}'Y'{FFFFFF} para interagir\n{E6E68C}Shyv", 297, 1756.6973,-2608.4919,114.5923,184.3741, MercadoNegroVW, 8.0);
    _CreateDynamicActorEx("\n{E6E68C}Comerciante negro{FFFFFF}\n{E6E68C}Pedrinho Matador", 146, 1756.1968,-2616.3950,114.5923,1.9473, MercadoNegroVW, 8.0);
    _CreateDynamicActorEx("", 217,1144.4907,-1767.1284,16.5938,183.3823, 0, 5.0);
    _CreateDynamicActorEx("{FFF000}Claudinho{FFFFFF}\nAqui voce pode trocar seus respeitos por XP\nAperte {FF0000}'Y'{FFFFFF} para interagir.\n", 170, 1321.7059,-1718.6442,13.5469,80.7676, 0, 10);
    _CreateDynamicActorEx("\n{E6E68C}Traficante\nAperte {DBED15}F{FFFFFF} para interagir\n", 143, -1099.0513, -1182.7329, 129.2187, 85, .label_range = 3.0);
    CreateDynamicActor(288, 2290.1750, -119.3937, 26.4685, 87.6441);
    CreateDynamicActor(27, 4157.7773, -3155.5905, 3.6702, 274.2767);
    new ActorEleitoral = CreateDynamicActor(141, 2627.8427, -1288.4217, 81.1740, 359.6545, 1, .worldid = 1);
    ApplyDynamicActorAnimation(ActorEleitoral, "MISC", "Seat_talk_02", 4.0, 0, 0, 0, 1, 1000);
    CreateDynamicActor(11, 4356.2700, -3106.1972, 3.1551, 180.0, .invulnerable = 1, .health = 100.0);
    CreateDynamicActor(27, 4080.0451, -3204.6342, 4.7042, 360.0, .invulnerable = 1, .health = 100.0);
    _CreateDynamicActorEx("\n{E6E68C}Atendente{FFFFFF}", 205, 377.4190,-65.6953,1001.5078,179.5547, 21, 8.0); // BURGERSHOT

    _CreateDynamicActorEx("{FFF000}Atendente{FFFFFF}\nAperte {FFFFFF}'{0FFFFF}F{FFFFFF}' para interagir", 167,1465.5389,-2300.6426,13.5828,321.2832, 0, 8.0); // Lanchonete 1
    _CreateDynamicActorEx("{FFF000}Atendente{FFFFFF}\nAperte {FFFFFF}'{0FFFFF}F{FFFFFF}' para interagir", 167,1497.0040,-1668.0743,14.0469,182.0365, 0, 8.0); // Lanchonete 3
    _CreateDynamicActorEx("{FFD700}Atendente{FFFFFF}\nPressione {DBED15}F{FFFFFF} para interagir\n{E6E68C}Jorge", 46,1225.7617,-1427.5166,13.4345,11.7397, 0, 5.0); // Lanchonete 3
}

CarregarPickups()
{
    AddInfoPickup(1239, 1512.8739,1315.4952,10.9838, "{00BFFF}Agencia do Governo\n{FFFFFF}Aperte {00BFFF}'F'{FFFFFF} para abrir a agencia.", 0xFFFFFFFF);
    AddInfoPickup(1239, 222.1357, 114.6567, 1010.2187, "Use {00BFFF}/verificar placa {FFFFFF}neste local", 0xFFFFFF66, .VW = 1);
    AddInfoPickup(1239, 232.4603, 165.0354, 1003.0234, "Fichas:\n{FF0000}/Ficha{FFFFFF} e{FF0000} /Limpar", 0xFFFFFFFF); // BOPE
    AddInfoPickup(1239, -757.2892, 2545.4309, 1218.7587, "Fichas:\n{FF0000}/Ficha{FFFFFF} e{FF0000} /Limpar", 0xFFFFFFFF);
    AddInfoPickup(1239, 255.2565, 67.2219, 1003.6406, "Fichas:\n{FF0000}/Ficha{FFFFFF} e{FF0000} /Limpar", 0xFFFFFFFF);
    AddInfoPickup(1239, 219.2458, 110.4775, 1010.2117, "Fichas:\n{FF0000}/Ficha{FFFFFF} e{FF0000} /Limpar", 0xFFFFFFFF, .VW = 1);
    AddInfoPickup(1239, 966.1085, -1719.2229, -45.5947, "Cartorio SUPREMO\n{FFFFFF}Aperte {FFFF00}'F'{FFFFFF} para trocar de nick", 0xFFFF00FF, .VW = MiniEmpresa_Cartorio);
    AddInfoPickup(1239, 962.7619, -1719.2229, -45.5947, "Cartorio SUPREMO\n{FFFFFF}Aperte {FFFF00}'F'{FFFFFF} para criar uma familia", 0xFFFF00FF, .VW = MiniEmpresa_Cartorio);
    AddInfoPickup(1239, 2627.9577, -1287.0281, 81.1740, "{00BFFF}Centro eleitoral\n{F8F8FF}Aperte {B0E0E6}'F'{F8F8FF} para retirar seu titulo de eleitor.", -1, 1);
    AddInfoPickup(1239, 822.9670, 5.4621, 1004.1796, "{F8F8FF}Bilhete de Loteria\n{F8F8FF}Digite {B0E0E6}/apostar [Numero]{F8F8FF} para apostar na loteria.", -1);
    AddInfoPickup(1239, 822.8231, 0.8775, 1004.1796, "{F8F8FF}Pague suas dividas aqui!\n{F8F8FF}Digite {B0E0E6}/minhasdividas{F8F8FF} para abrir o menu de dividas.", -1);
    AddInfoPickup(1239, 1480.6146,-1674.5830,14.0469, "{2E9AFE}Anuncios de Itens\n{2E9AFE}Pressione {FFFFFF}'F'{2E9AFE} para anunciar.", -1);
    AddInfoPickup(2894, 1152.7583, -1305.1439, 1019.4139, "Contrato Hospitalar\nAperte a tecla {00FFFF}'F' {FFFFFF}para comprar um contrato.", -1, 1);
    AddInfoPickup(1241, 1148.7047, -1309.4540, 1019.4139, "Farmacia do Hospital\n{FFFFFF}Aperte {00BFFF}'F'{FFFFFF} para comprar algum remedio.", -1, 1);
    AddInfoPickup(1210, 1505.4789,1337.0066,10.9788, "{C4C4C2}Lista de empregos\nAperte a tecla {FFFFFF}'F' {C4C4C2}para pegar um emprego.", -1);
    AddInfoPickup(1210, -2033.0219, -117.3249, 1035.1718, "{C4C4C2}Auto-Escola\nPressione a tecla {FFFFFF}F {C4C4C2}para abrir o menu de Licencas.", -1, 1);
    AddInfoPickup(1271, -23.5346, -272.8204, 5.4296, "{00BFFF}Area de Carregamento\n{FFFFFF}Digite {00BFFF}/carregarcaminhao{FFFFFF} para carregar.", -1);
    AddInfoPickup(1271, -14.8307, -272.8204, 5.4296, "{00BFFF}Area de Carregamento\n{FFFFFF}Digite {00BFFF}/carregarcaminhao{FFFFFF} para carregar.", -1);
    AddInfoPickup(1271, 1751.5809, -2056.5300, 13.8122, "{00BFFF}Area de Carregamento\n{FFFFFF}Digite {00BFFF}/pegarprodutos{FFFFFF} para carregar o caminhao de produtos.", -1);
    AddInfoPickup(1239, -49.9776, -269.3625, 6.6331, "{C4C4C2}Central de Entregas\n{FFFFFF}Aperte {FFFFFF}'F'{C4C4C2} para escolher um trajeto.", -1);
    AddInfoPickup(1239, 1917.8865, -2651.3012, 13.5468, "{C4C4C2}Agencia dos Pilotos\n{FFFFFF}Aperte {FFFFFF}'F'{C4C4C2} para escolher um trajeto.", -1);
    AddInfoPickup(Itens[Item_KitReparo][item_modelo], 2494.0769, -1464.2416, 24.0251, "{00BFFF}Mecanicos\n{FFFFFF}Aperte {00BFFF}'F'{FFFFFF} para abrir o menu.", -1);
    AddInfoPickup(2901, -1172.8927, -911.6874, 129.2187, "{00BFFF}Sementes\n{FFFFFF}Aperte {00BFFF}'H'{FFFFFF} para carregar o reboque de fazenda.", -1);
    AddInfoPickup(2901, -1071.5642, -1207.4371, 129.2187, "{00BFFF}Local de Entrega\n{FFFFFF}Digite {00BFFF}/entregarpacotes{FFFFFF} para entregar os pacotes.", -1);
    AddInfoPickup(2901, 814.4028, -1103.0849, 25.7886, "{00BFFF}Coveiro\n{FFFFFF}Digite {00BFFF}/marcarcadaver{FFFFFF} para marcar um cadaver no mapa.", -1);
    AddInfoPickup(1572, 2168.0527, -1983.3184, 13.5546, "{00BFFF}Area de Descarregamento\n{FFFFFF}Digite /dlixo para descarregar seu lixo.", 1);
    AddInfoPickup(1239, 4356.2700, -3108.4265, 3.1551, "{C4C4C2}24-7 Ilha SUPREMO\n{FFFFFF}Aperte {00BFFF}'F'{FFFFFF} para comprar algum item.", 1);
    AddInfoPickup(Itens[Item_CaixaGrande][item_modelo], 1479.6538, -1639.8616, 14.1484, "{33CCFF}CAIXA SURPRESA\n{FFFFFF}Aperte {33CCFF}'F'{FFFFFF} para pegar.", 1, .VW = 0);
    AddInfoPickup(1239, -382.3761, -1426.3063, 26.1681, "{00BFFF}Pegar produtos\n{FFFFFF}Aperte {00BFFF}'Y'{FFFFFF} para carregar seu veiculo de produtos.", 1);
    AddInfoPickup(2060, 2805.0478, -2438.8728, 13.6294, "{00BFFF}Navio Cargueiro\n{FFFFFF}Aperte {00BFFF}'Y'{FFFFFF} para vender seus produtos.", 1);
    AddInfoPickup(348, 1081.1934,-1697.2982,13.5469, "{10A1D8}Treinamento LS\nAperte F para ir.", 0);
    AddInfoPickup(1239, 2144.1770, 1626.5814, 993.6882, "Porta:\n{FF0000}/plantarbomba", 0xFFFFFFFF);
    AddInfoPickup(1239, 386.7154, -1817.8643, 7.8410, "{00c1ff}Mercado do Peixe\n\n{FFFFFF}Venda aqui seus peixes.", 0xFFFF00FF);
    AddInfoPickup(19132, 4088.3674,-3216.0857,41.5980, "{FF0000}Emprego Minerador\n{FFFFFF}Pressione 'F' para pegar seu veiculo.", 0xFFFFFFFF);
    //GUERRA MORRO
    AddInfoPickup(1318, 1057.5962, 960.9265, -41.7163, "{FFFFFF}Pressione 'F' para ir para a guerra.", 0xFFFFFFFF);
    AddInfoPickup(1318, 1057.6670, 975.2425, -41.7163, "{FFFFFF}Pressione 'F' para voltar para a HQ.", 0xFFFFFFFF);


    AddInfoPickup(1247, 249.5056, 67.8394, 1003.6406, "{00BFFF}Policia Militar\n{FFFFFF}Digite /entregar para se entregar.", 1);

    AddInfoPickup(1247, 2361.4966, 2211.5959, -55.8314, "{00BFFF}Penitenciaria\n{FFFFFF}Digite /entregar para se entregar.", 1);

    PickupPatio = CreateDynamicPickup(1247, 1, 2299.6474, -106.5123, 26.4758);

    CreateDynamicPickup(1247, 23, 1805.9886, -1573.2638, 13.4495, -1);
	// ~~ Pickups FAQ
    CreateDynamicPickup(18631, 24, 1470.5566,-2281.3293,13.5828, 0 );
    CreateDynamicPickup(19941, 24, 1478.4470,-2281.1890,13.5828, 0 );
}

CriarMenus()
{
    // /Tunar
    TuningMenu = CreateMenu("~y~~h~Menu",1,20,120,150,40);
    AddMenuItem(TuningMenu,0,"Paint Jobs");
    AddMenuItem(TuningMenu,0,"Cores");
    AddMenuItem(TuningMenu,0,"Escapamentos");
    AddMenuItem(TuningMenu,0,"ParaChoque Dian");
    AddMenuItem(TuningMenu,0,"ParaChoque Trase");
    AddMenuItem(TuningMenu,0,"Capo");
    AddMenuItem(TuningMenu,0,"Aerofolios");
    AddMenuItem(TuningMenu,0,"Saias Laterais");
    AddMenuItem(TuningMenu,0,"Bullbars");
    AddMenuItem(TuningMenu,0,"Rodas");
    AddMenuItem(TuningMenu,0,"Som");
    AddMenuItem(TuningMenu,0,"Proxima Pag");

    Paintjobs = CreateMenu("~y~~h~Menu",1,20,120,150,40);
    AddMenuItem(Paintjobs,0,"Paintjob 1");
    AddMenuItem(Paintjobs,0,"Paintjob 2");
    AddMenuItem(Paintjobs,0,"Paintjob 3");
    AddMenuItem(Paintjobs,0,"Paintjob 4");
    AddMenuItem(Paintjobs,0,"Paintjob 5");
    AddMenuItem(Paintjobs,0,"Menu Principal");

    Colors = CreateMenu("~y~~h~Menu",1,20,120,150,40);
    AddMenuItem(Colors,0,"Preto");
    AddMenuItem(Colors,0,"Branco");
    AddMenuItem(Colors,0,"Vermelho");
    AddMenuItem(Colors,0,"Azul");
    AddMenuItem(Colors,0,"Verde");
    AddMenuItem(Colors,0,"Amarelo");
    AddMenuItem(Colors,0,"Rosa");
    AddMenuItem(Colors,0,"Marrom");
    AddMenuItem(Colors,0,"Proxima Pag");

    Colors1 = CreateMenu("~y~~h~Menu",1,20,120,150,40);
    AddMenuItem(Colors1,0,"Cinza");
    AddMenuItem(Colors1,0,"Ouro");
    AddMenuItem(Colors1,0,"Azul Escuro");
    AddMenuItem(Colors1,0,"Azul Claro");
    AddMenuItem(Colors1,0,"Verde");
    AddMenuItem(Colors1,0,"Cinza Claro");
    AddMenuItem(Colors1,0,"Vermelho Escuro");
    AddMenuItem(Colors1,0,"Marrom Escuro");
    AddMenuItem(Colors1,0,"Menu Principal");

    Exhausts = CreateMenu("~y~~h~Menu",1,20,120,150,40);
    AddMenuItem(Exhausts,0,"Wheel Arch Alien Exhaust");
    AddMenuItem(Exhausts,0,"Wheel Arch X-Flow Exhaust");
    AddMenuItem(Exhausts,0,"Locos Low Chromer Exhaust");
    AddMenuItem(Exhausts,0,"Locos Low Slamin Exhaust");
    AddMenuItem(Exhausts,0,"Menu Principal");

    Frontbumper = CreateMenu("~y~~h~Menu",1,20,120,150,40);
    AddMenuItem(Frontbumper,0,"Wheel Arch Alien bumper");
    AddMenuItem(Frontbumper,0,"Wheel Arch X-Flow bumper");
    AddMenuItem(Frontbumper,0,"Locos Low Chromer bumper");
    AddMenuItem(Frontbumper,0,"Locos Low Slamin bumper");
    AddMenuItem(Frontbumper,0,"Menu Principal");

    Rearbumper = CreateMenu("~y~~h~Menu",1,20,120,150,40);
    AddMenuItem(Rearbumper,0,"Wheel Arch Alien bumper");
    AddMenuItem(Rearbumper,0,"Wheel Arch X-Flow bumper");
    AddMenuItem(Rearbumper,0,"Locos Low Chromer bumper");
    AddMenuItem(Rearbumper,0,"Locos Low Slamin bumper");
    AddMenuItem(Rearbumper,0,"Menu Principal");

    Roof = CreateMenu("~y~~h~Menu",1,20,120,150,40);
    AddMenuItem(Roof,0,"Wheel Arch Alien Roof Vent");
    AddMenuItem(Roof,0,"Wheel Arch X-Flow Roof Vent");
    AddMenuItem(Roof,0,"Locos Low Hardtop Roof");
    AddMenuItem(Roof,0,"Locos Low Softtop Roof");
    AddMenuItem(Roof,0,"Menu Principal");

    Spoilers = CreateMenu("~y~~h~Menu",1,20,120,150,40);
    AddMenuItem(Spoilers,0,"Alien Spoiler");
    AddMenuItem(Spoilers,0,"X-Flow Spoiler");
    AddMenuItem(Spoilers,0,"Menu Principal");

    Sideskirts = CreateMenu("~y~~h~Menu",1,20,120,150,40);
    AddMenuItem(Sideskirts,0,"Wheel Arch Alien Side Skirts");
    AddMenuItem(Sideskirts,0,"Wheel Arch X-Flow Side Skirts");
    AddMenuItem(Sideskirts,0,"Locos Low Chrome Strip");
    AddMenuItem(Sideskirts,0,"Locos Low Chrome Flames");
    AddMenuItem(Sideskirts,0,"Locos Low Chrome Arches");
    AddMenuItem(Sideskirts,0,"Locos Low Chrome Trim");
    AddMenuItem(Sideskirts,0,"Locos Low Wheelcovers");
    AddMenuItem(Sideskirts,0,"Menu Principal");

    Bullbars = CreateMenu("~y~~h~Menu",1,20,120,150,40);
    AddMenuItem(Bullbars,0,"Locos Low Chrome Grill");
    AddMenuItem(Bullbars,0,"Locos Low Chrome Bars");
    AddMenuItem(Bullbars,0,"Locos Low Chrome Lights");
    AddMenuItem(Bullbars,0,"Locos Low Chrome Bullbar");
    AddMenuItem(Bullbars,0,"Menu Principal");

    Wheels = CreateMenu("~y~~h~Menu",1,20,120,150,40);
    AddMenuItem(Wheels,0,"Offroad");
    AddMenuItem(Wheels,0,"Mega");
    AddMenuItem(Wheels,0,"Wires");
    AddMenuItem(Wheels,0,"Twist");
    AddMenuItem(Wheels,0,"Grove");
    AddMenuItem(Wheels,0,"Import");
    AddMenuItem(Wheels,0,"Atomic");
    AddMenuItem(Wheels,0,"Ahab");
    AddMenuItem(Wheels,0,"Virtual");
    AddMenuItem(Wheels,0,"Access");
    AddMenuItem(Wheels,0,"Proxima Pag");
    AddMenuItem(Wheels,0,"Menu Principal");

    Wheels1 = CreateMenu("~y~~h~Menu",1,20,120,150,40);
    AddMenuItem(Wheels1,0,"Trance");
    AddMenuItem(Wheels1,0,"Shadow");
    AddMenuItem(Wheels1,0,"Rimshine");
    AddMenuItem(Wheels1,0,"Classic");
    AddMenuItem(Wheels1,0,"Cutter");
    AddMenuItem(Wheels1,0,"Switch");
    AddMenuItem(Wheels1,0,"Dollar");
    AddMenuItem(Wheels1,0,"Menu Principal");

    Carstereo = CreateMenu("~y~~h~Menu",1,20,120,150,40);
    AddMenuItem(Carstereo,0,"Bass Boost");
    AddMenuItem(Carstereo,0,"Menu Principal");

    // Pagina 2
    TuningMenu1= CreateMenu("~y~~h~Menu",1,20,120,150,40);
    AddMenuItem(TuningMenu1,0,"Hidraulica");
    AddMenuItem(TuningMenu1,0,"Nitro");
    AddMenuItem(TuningMenu1,0,"Neon");
    AddMenuItem(TuningMenu1,0,"Reparar");
    AddMenuItem(TuningMenu1,0,"Menu Principal");

    Hydraulics = CreateMenu("~y~~h~Menu",1,20,120,150,40);
    AddMenuItem(Hydraulics,0,"Hydraulico");
    AddMenuItem(Hydraulics,0,"Menu Principal");

    Nitro = CreateMenu("~y~~h~Menu",1,20,120,150,40);
    AddMenuItem(Nitro,0,"2x Nitro");
    AddMenuItem(Nitro,0,"5x Nitro");
    AddMenuItem(Nitro,0,"10x Nitro");
    AddMenuItem(Nitro,0,"Menu Principal");

    Neon = CreateMenu("~y~~h~Neons",1,20,120,150,40);
    AddMenuItem(Neon,0,"Neon: Azul");
    AddMenuItem(Neon,0,"Neon: Vermelho");
    AddMenuItem(Neon,0,"Neon: Verde");
    AddMenuItem(Neon,0,"Neon: Branco");
    AddMenuItem(Neon,0,"Neon: Rosa");
    AddMenuItem(Neon,0,"Neon: Amarelo");
    AddMenuItem(Neon,0,"Remover Neons");
    AddMenuItem(Neon,0,"Menu Principal");
}

CarregarPortoesOrgs()
{
    CreatePortao(968, 1268.13196, -2046.81995, 58.81000, 0.00000, -90.00000, 0.00000, 1268.13196, -2046.81995, 58.81000, 0.00000, 0.00000, 0.00000, 0, 0, .OrgID = TEAM_GOVERNO);
    CreatePortao(971, 1033.66736, -2292.95947, 14.58960, 0.00000, 0.00000, -65.92700, 1033.66736, -2292.95947, 7.51260, 0.00000, 0.00000, -65.92700, 0, 0, .OrgID = TEAM_BOMBEIROS);
    CreatePortao(980, 924.73297, -1221.73279, 18.67440,   0.00000, 0.00000, 90.00000, 924.73297, -1221.73279, 13.11640,   0.00000, 0.00000, 90.00000, 0, 0, TEAM_PCIVIL);
    CreatePortao(980, 1587.54150, -1638.18701, 14.75820, 0.0, 0.0, 0.0, 1587.54150, -1638.18701, 9.5222, 0.0, 0.0, 0.0, 0, 0, TEAM_PM);
    CreatePortao(985, -1533.949585, 494.472687, 7.890355, 0.000000, 0.000000, 0.000000, -1525.9495, 494.4726, 7.8903, 0.000000, 0.000000, 0.000000, 0, 0, .OrgID = TEAM_FA);
    CreatePortao(3113, -1465.7194, 501.4144, 1.0999, 0.000000, 0.000000, 0.000000, -1469.5000,500.4144,14.000000, 0.0, 0.0, 0.0, 0, 0, .OrgID = TEAM_FA);
    CreatePortao(988, -1445.166748, 289.214020, 7.226563, 0.000000, 0.000000, 90.000, -1445.1667,283.2140,7.2265, 0.000000, 0.000000, 90.000, 0, 0, .OrgID = TEAM_FA);
    CreatePortao(988, 2292.46167, -112.10227, 25.79861,   0.00000, 0.00000, 270.00000, 2292.46167, -112.10227, 21.3106,   0.00000, 0.00000, 270.00000, 0, 0, .OrgID = TEAM_PRF);
    CreatePortao(968, 781.350585, -1329.308471, 13.176884, 0.000000, 90.000000, 180.000000, 781.350585, -1329.308471, 13.176884, 0.000000, 0.000000, 180.000000, 0, 0, .OrgID = TEAM_SN);
    CreatePortao(968, 774.378845, -1385.443603, 13.199326, 0.000000, 90.000000, 360.000000, 774.378845, -1385.443603, 13.199326, 0.000000, 0.000000, 360.000000, 0, 0, .OrgID = TEAM_SN);
    CreatePortao(980, -73.13854, 2555.66333, 18.57799, 0.00000, 0.00000, 90.00000, -73.1385, 2555.6633, 13.0310, 0.00000, 0.00000, 90.00000, 0, 0, TEAM_AQ);
    CreatePortao(980, 368.73386, 2473.81177, 18.43380, 0.00000, 0.00000, 0.00000, 368.7339, 2473.8118, 12.6794, 0.00000, 0.00000, 0.00000, 0, 0, TEAM_AQ);
    CreatePortao(980, 426.86380, 2563.22607, 17.57699, 0.00000, 0.00000, -69.00000, 426.8638, 2563.2261, 12.3361, 0.00000, 0.00000, -69.00000, 0, 0, TEAM_AQ);
    CreatePortao(980, 941.1091,-1011.0341,34.6492,0.0000,0.0000,0.0000, 941.1091,-1011.0341,23.7548,0.0000,0.0000,0.0000, 0, 0, .OrgID = TEAM_BOPE );
    CreatePortao(980, 2313.5623,-1218.0345,23.6654,0.0000,0.0000,90.0000, 2313.5623,-1218.0345,18.4209,0.0000,0.0000,90.0000, 0, 0, .OrgID = TEAM_HIT );
    CreatePortao(980, 2360.8965,-1272.0590,23.2868,0.0000,0.0000,270.0000, 2360.8965,-1272.0590,18.9222,0.0000,0.0000,270.0000, 0, 0, .OrgID = TEAM_HIT );
}

CriarRadares()
{
    CreateRadar(857.47510, -1389.90039, 12.56080,  0.00000, 0.00000, 270.00000,  200.0, 60.0);
    CreateRadar(1611.7036, -977.6210,   37.3305,   0.0000,  0.0000,  80.0000,    200.0, 60.0);
    CreateRadar(2917.0669, -1405.4592,  9.8472,    0.0000,  0.0000,  181.9199,   200.0, 80.0);
    CreateRadar(-132.1991, -1245.1445,  2.0132,    0.0000,  0.0000,  161.4780,   200.0, 80.0);
    CreateRadar(1622.6321, -1244.0808,  47.1722,   0.0000,  0.0000,  -186.0000,  200.0, 80.0);
}

CriarATMS()
{
    CreateATM(1928.69604, -1784.04639, 13.15720, 0.00000, 0.00000, 88.44680);
    CreateATM(1837.20667, -1692.44824, 13.01124, 0.00000, 0.00000, 269.46243);
    CreateATM(1831.94666, -1405.75806, 12.99174, 0.00000, 0.00000, 176.68292);
    CreateATM(1363.55298, -1750.63855, 13.17531, 0.00000, 0.00000, 271.14401);
    CreateATM(1070.77478, -1881.54370, 13.16587, 0.00000, 0.00000, 271.18671);
    CreateATM(833.72095, -1384.92908, 13.07656, 0.00000, 0.00000, 0.00000);
    CreateATM(1186.30676, -1371.22632, 13.16235, 0.00000, 0.00000, 89.22408);
    CreateATM(1797.89026, -1190.45325, 23.54218, 0.00000, 0.00000, 182.18976);
    CreateATM(2209.10791, -1141.88208, 25.39645, 0.00000, 0.00000, 88.60888);
    CreateATM(2313.50586, -1373.55334, 23.69597, 0.00000, 0.00000, 271.93027);
    CreateATM(2351.94897, -1548.61584, 23.54486, 0.00000, 0.00000, 264.68781);
    CreateATM(2243.18921, -1722.77673, 13.15102, 0.00000, 0.00000, 0.00000);
    CreateATM(1940.07886, -2113.70752, 13.30774, 0.00000, 0.00000, 89.08496);
    CreateATM(1736.49780, -1863.44666, 13.17641, 0.00000, 0.00000, 178.34193);
    CreateATM(2310.53125, -7.17057, 26.34110, 0.00000, 0.00000, 359.03336);
    CreateATM(365.37585, -1354.45508, 14.12511, 0.00000, 0.00000, 29.47749);
    CreateATM(1296.89661, -1158.12537, 23.39852, 0.00000, 0.00000, 177.93507);
    CreateATM(1492.36804, -1022.19519, 23.41977, 0.00000, 0.00000, 0.00000);
    CreateATM(1830.88367, -1071.68689, 23.48169, 0.00000, 0.00000, 269.40909);
    CreateATM(1863.66504, -1270.39185, 13.16138, 0.00000, 0.00000, 182.03978);
    CreateATM(-1967.20374, 278.41309, 34.80040,   0.00000, 0.00000, -90.00000);
    CreateATM(566.76868, -1296.64185, 16.83580,   0.00000, 0.00000, 90.00000);
    CreateATM(2124.22900, -1157.50793, 23.62380,   0.00000, 0.00000, -90.00000);
}

CriarTerritorios()
{
    CreateTerritorio("Pista de Skate", 1861.9410,-1450.6462,1976.5867,-1351.4069, DOMINIO_GANG, TEAM_PM, TEAM_BOPE, TEAM_SOA, TEAM_HA, TEAM_LOWRIDER, TEAM_GROVE, TEAM_BALLAS, TEAM_AZTECAS, TEAM_VAGOS, TEAM_CV, TEAM_PCC);
    CreateTerritorio("Centro Comercial", -1984.0034, 441.6602, -1854.5898, 582.7585, DOMINIO_GANG, TEAM_PM, TEAM_BOPE, TEAM_SOA, TEAM_HA, TEAM_LOWRIDER, TEAM_GROVE, TEAM_BALLAS, TEAM_AZTECAS, TEAM_VAGOS, TEAM_CV, TEAM_PCC);
    CreateTerritorio("Farol", 133.1268, -1968.3923, 178.0602, -1880.1589, DOMINIO_GANG, TEAM_PM, TEAM_BOPE, TEAM_SOA, TEAM_HA, TEAM_LOWRIDER, TEAM_GROVE, TEAM_BALLAS, TEAM_AZTECAS, TEAM_VAGOS, TEAM_CV, TEAM_PCC);
    CreateTerritorio("Praia", 603.8044, -1938.465, 820.566, -1827.928, DOMINIO_GANG, TEAM_PM, TEAM_BOPE, TEAM_SOA, TEAM_HA, TEAM_LOWRIDER, TEAM_GROVE, TEAM_BALLAS, TEAM_AZTECAS, TEAM_VAGOS, TEAM_CV, TEAM_PCC);
    CreateTerritorio("Parque Gleen", 1871, -1253.5000915527344, 2055, -1145.5000915527344, DOMINIO_GANG, TEAM_PM, TEAM_BOPE, TEAM_SOA, TEAM_HA, TEAM_LOWRIDER, TEAM_GROVE, TEAM_BALLAS, TEAM_AZTECAS, TEAM_VAGOS, TEAM_CV, TEAM_PCC);
    CreateTerritorio("Usina", -907.0000,1365.0000,-480.0000,2148.0000, DOMINIO_TRFA, TEAM_AQ, TEAM_EIIS, TEAM_FA);
    CreateTerritorio("Montanhas SF", -2419.921875,-1722.65625,-2185.546875,-1517.578125, DOMINIO_TRFA, TEAM_AQ, TEAM_EIIS, TEAM_FA);
    CreateTerritorio("Docas SF", -2917.96875,919.921875,-2531.25,1201.171875, DOMINIO_TRFA, TEAM_AQ, TEAM_EIIS, TEAM_FA);
    CreateTerritorio("Pedreira", 377.0, 712.0, 877.0, 1012.0, DOMINIO_TRFA, TEAM_AQ, TEAM_EIIS, TEAM_FA);
    CreateTerritorio("Madereira", -580.323852, -214.494873, -412.323852, -32.494873, DOMINIO_MFPF, TEAM_PF, TEAM_MY, TEAM_MR);
    CreateTerritorio("Moonlighting", 2475.00,-2250.00,2746.875,-2182.03125, DOMINIO_MFPF, TEAM_PF, TEAM_MY, TEAM_MR);
    CreateTerritorio("Ocean Docks", 2662.5,-2596.875,2878.125,-2306.25, DOMINIO_MFPF, TEAM_PF, TEAM_MY, TEAM_MR);
    CreateTerritorio("O Mar Do Poeta", 2210.15625,-2709.375,2280.46875,-2430.46875, DOMINIO_MFPF, TEAM_PF, TEAM_MY, TEAM_MR);
    CreateTerritorio("Shopping", 1061.1545, -1566.9081, 1190.9424, -1411.1282, DOMINIO_MERCENARIO, TEAM_PM, TEAM_BOPE, TEAM_SOA, TEAM_HA);
}

CarregarPortinhas()
{
    CreatePortinha(1495, 924.83051, -1210.24561, 15.96960, 0.00000, 0.00000, 90.00000, 924.8305, -1211.5956, 15.9696, 0.00000, 0.00000, 90.00000, 0, TEAM_PCIVIL);
    CreatePortinha(2927, -763.61383056, 2579.07202148, 1217.51086425, 0.00000000, 0.00000000, -92.80000305, -763.74041748, 2579.03637695, 1220.05334472, 0.00000000, 0.00000000, -92.50007629, 0, .OrgID = TEAM_FA);
    CreatePortinha(2927, -746.82513427, 2535.30566406, 1221.60839843, 0.00000000, 0.00000000, 85.99987030, -746.82513427, 2535.30566406, 1224.04003906, 0.00000000, 0.00000000, 85.99987030, 0, .OrgID = TEAM_FA);
    CreatePortinha(2927, -765.38104248, 2552.25561523, 1221.60876464, 0.00000000, 0.00000000, -94.00000762, -765.38104248, 2552.25561523, 1224.61962890, 0.00000000, 0.00000000, -94.00000762, 0, .OrgID = TEAM_FA);
    CreatePortinha(2927, -766.49493408, 2536.47973632, 1221.60522460, 0.00000000, 0.00000000, 87.20001983, -766.49493408, 2536.47973632, 1224.08544921, 0.00000000, 0.00000000, 87.20001983, 0, .OrgID = TEAM_FA);
    CreatePortinha(2927, -763.98535156, 2568.90698242, 1221.55847167, 0.00000000, 0.00000000, 85.89994812, -763.98535156, 2568.90698242, 1223.83911132, 0.00000000, 0.00000000, 85.89994812, 0, .OrgID = TEAM_FA);
    CreatePortinha(19302, 253.19250, 109.07550, 1003.46613, 0.00000, 0.00000, 270.00000, 253.19250, 109.07550+1.5, 1003.46613, 0.00000, 0.00000, 270.00000, 0, TEAM_PF);
    CreatePortinha(19302, 239.55490, 125.08360, 1003.46613, 0.00000, 0.00000, 270.00000, 239.55490, 125.08360+1.5, 1003.46613, 0.00000, 0.00000, 270.00000, 0, TEAM_PF);
    CreatePortinha(19302, 253.19250, 125.24360, 1003.46613, 0.00000, 0.00000, 270.00000, 253.19250, 125.24360+1.5, 1003.46613, 0.00000, 0.00000, 270.00000, 0, TEAM_PF);
    CreatePortinha(1495, 368.909942, 161.566879, 1013.167480, 0.000000, 0.000000, 90.000000, 368.909942, 159.657211, 1013.167480, 0.000000, 0.000000, 90.000000, 0, .OrgID = TEAM_GOVERNO);

    CreatePortinha(2952, 228.260437, 152.305343, 1001.913208, 0.000000, 0.000000, 0.000000, 228.260437, 152.305343, 998.932922, 0.000000, 0.000000, 0.000000, 2, .OrgID = TEAM_BOPE);
    CreatePortinha(2952, 228.260437, 162.255264, 1001.913208, 0.000000, 0.000000, 0.000000, 228.260437, 162.255264, 998.932922, 0.000000, 0.000000, 0.000000, 2, .OrgID = TEAM_BOPE);
    CreatePortinha(2952, 230.330627, 169.845169, 1001.913208, 0.000000, 0.000000, 90.000000, 230.330627, 169.845169, 998.932922, 0.000000, 0.000000, 90.000000, 2, .OrgID = TEAM_BOPE);
}

CarregarLabels()
{
    CreateDynamic3DTextLabel("Aperte 'F' para abrir a porta.", 0xFFFFFF55, 247.654113, 72.420867, 1003.990966, 1.0);
    CreateDynamic3DTextLabel("Aperte 'F' para abrir a porta.", 0xFFFFFF55, 241.477325, 77.152580, 1005.469055, 1.0);
    CreateDynamic3DTextLabel("Aperte 'F' para abrir a porta.", 0xFFFFFF55, 244.837356, 77.152580, 1004.108642, 1.0);
    CreateDynamic3DTextLabel("Aperte 'F' para abrir a porta.", 0xFFFFFF55, 247.973281, 74.472053, 1004.020751, 1.0);
    CreateDynamic3DTextLabel("Aperte 'F' para abrir a porta.", 0xFFFFFF55, 250.473281, 64.594291, 1004.100891, 1.0);
}

CriarLabels()
{
    CreateDynamic3DTextLabel( "{0FFFFF}AJUDA PARA NOVATO\n{FFFFFF}Aperte {0FFFFF}'Y' {FFFFFF}para abrir.", 0x00BFFFFF, 1470.5566,-2281.3293,13.5828, 5.0, .testlos = 1);
    CreateDynamic3DTextLabel( "{CCA300}MENU VIP\nAperte 'Y' para abrir.", 0x00BFFFFF, 1478.4470,-2281.1890,13.5828, 5.0, .testlos = 1);
    CreateDynamic3DTextLabel("{CCCCCC}Penitenciaria de LS\n{FFFFFF}Use /prender para prender um procurado", 0xCCCCCCAA, 1805.9886, -1573.2638, 13.4495, 10.0);
    CreateDynamic3DTextLabel("Estilos de Lutas\naperte f Para Mudar Luta",COLOR_AZULBB,768.2192,-3.9873,1000.9203,15.0);
}

CriarEntradas()
{
    AddEntradaSaida(1318, 1318, "{00BFFF}Hospital\n{FFFFFF}Pressione {00BFFF}'F'{FFFFFF} para entrar.", "{FFFFFF}Pressione {00BFFF}'F'{FFFFFF} para sair.", 1172.6964, -1323.6467, 15.4019, 0, 0, 1172.4326, -1310.8219, 1019.4160, 1, 1, 3);
    AddEntradaSaida(1318, 1318, "{33AAEE}Segundo Andar\n{FFFFFF}Pressione {FF0000}'F' {FFFFFF}para subir", "{33AAEE}Primeiro Andar\n{FFFFFF}Pressione {FF0000}'F'{FFFFFF} para descer.", 1155.8608, -1296.9169, 1019.4288, 1, 1, 638.0893, -1239.6477, 1024.3918, 1, 1, 3); // HOSPITAL SEGUNDO ANDAR
    AddEntradaSaida(1318, 1318, "{33AAEE}Refeitorio\n{FFFFFF}Pressione {FF0000}'F' {FFFFFF}para entrar", "{33AAEE}Refeitorio\n{FFFFFF}Pressione {FF0000}'F'{FFFFFF} para sair.", 633.7870, -1248.9899, 1024.4025, 1, 1, 1123.8853, -1533.4841, 1010.2963, 1, 1, 3); // HOSPITAL REFEITORIO    
    AddEntradaSaida(1318, 1318, "", "", 2088.6104,-1560.4606,13.1459, 0, 0, 1467.9481, -516.2864, 991.6563, 10, 10); // DEPOSITO
    AddEntradaSaida(1318, 1318, "", "{FFFFFF}Aperte {FF0000}'F'{FFFFFF} ", 1208.5867,-1748.5859,13.5934, 0, 0, 1133.17114,-14.45600,1000.18213, 12); // CASINO
    AddEntradaSaida(1318, 1318, "", "", 2421.4651,-1219.3932,25.5522, 0, 0, 1204.8531,-13.8454,1000.9219, 2); // PUTEIRO
    AddEntradaSaida(1318, 1318, "", "", 2233.8235,-1332.4860,23.9814, 0, 0, 387.1423,2324.0554,1889.5800, 10, .tmCongelarE = 0); // IGREJA
    AddEntradaSaida(1247, 1247, "", "", 1524.4943, -1677.7766, 6.2187, 0, 0, 246.3902, 87.4527, 1003.6406, 6, 0, .OrgID = TEAM_PM, .tmCongelarE = 2);
    AddEntradaSaida(1247, 1247, "{33AAEE}Departamento da Policia Militar\nAperte F para Subir.", "{FFFFFF}Aperte {FF0000}'F'{FFFFFF} para descer.", 1568.6549, -1690.0300, 6.2187, 0, 0, 1564.8972, -1666.5032, 28.3956, 0, 0, .OrgID = TEAM_PM);
    AddEntradaSaida(1247, 1247, "", "{FFFFFF}Aperte {FF0000}'F'{FFFFFF} para ir para garagem.", 315.3871, -1514.2537, 24.9218, 0, 0, 225.6239, 124.3760, 999.0156, 10, 0, .OrgID = TEAM_PF);
    AddEntradaSaida(1247, 1247, "", "{FFFFFF}Aperte {FF0000}'F'{FFFFFF} para ir para a cobertura.", 314.1929, -1506.2513, 76.5390, 0, 0, 238.4356, 114.8731, 1010.2187, 10, 0, .OrgID = TEAM_PF);
    AddEntradaSaida(1318, 1318, "", "", 1248.2686,-1560.9211,13.5635, 0, 0, 2622.3662, -1267.8652, 81.1740, 0, 1, 3); // CARTORIO
    AddEntradaSaida(1318, 1318, "{C4C4C2}Penitenciaria LS\nAperte {FFFFFF}'F' {C4C4C2}para entrar.", "{FFFFFF}Aperte {FF0000}'F'{FFFFFF} para sair.", 1799.2744, -1578.3179, 14.0791, 0, 0, 2367.0222, 2214.3557, -55.8314, 1, CELA_VW, .tmCongelarE = 2);
    AddEntradaSaida(1318, 1318, "{C4C4C2}Loteria\nAperte {FFFFFF}'F' {C4C4C2}para entrar.", "{FFFFFF}Aperte {FF0000}'F'{FFFFFF} para sair.", 1631.8881, -1172.3654, 24.0842, 0, 0, 834.2374, 7.4005, 1004.1870, 3, 0);
    AddEntradaSaida(1318, 1318, "{00AAEE}Prefeitura\n{FFFFFF}Pressione {FF0000}'F' {FFFFFF}para entrar.", "{FFFFFF}Pressione {FF0000}'F'{FFFFFF}para sair.", 1481.0457, -1810.1051, 18.7957, 0, 0, 1495.9100, 1335.6722, 10.9788, 3, 7, .MsgEntrada = "~w~Bem vindo a ~n~~b~Prefeitura !");
    AddEntradaSaida(1318, 1318, "{C4C4C2}Centro de Licencas\nAperte {FFFFFF}'F' {C4C4C2}para entrar.", "", 1413.1544,-1700.7520,13.5395, 0, 0, -2029.7486, -118.7678, 1035.1715, 3, 1, .MsgEntrada = "~w~Bem vindo a~n~Auto-Escola !");
    AddEntradaSaida(1318, 1318, "{C4C4C2}Pizzaria\nAperte {FFFFFF}'F' para {C4C4C2}entrar", "", 2105.4885, -1806.4941, 13.5547, 0, 0, 372.3330, -133.2578, 1001.4921, 5, 1);
    AddEntradaSaida(1318, 1318, "{00AAEE}Banco Central\n{FFFFFF}Pressione 'F' para entrar", "{FFFFFF}Pressione {FF0000}'F'{FFFFFF} para sair.", 1457.5604,-1011.4336,26.8438, 0, 0, 1388.7634, -26.7338, 1000.8729, 1, 1);
    AddEntradaSaida(1318, 1318, "{00AAEE}Motel\n{FFFFFF}Pressione 'F' para entrar", "{FFFFFF}Pressione {FF0000}'F'{FFFFFF} para sair.", 2233.1982,-1159.7296,25.8906, 0, 0, 2214.5020, -1150.5605, 1025.7969, 15, 1);
    AddEntradaSaida(1318, 1318, "", "", 2229.4399,-1721.6360,13.5647, 0, 0, 771.7618,-5.6084,1000.7277, 5, 0); // GINASIO
    AddEntradaSaida(1318, 1318, "", "", 1307.0483,-1730.0083,13.5343, 0, 0, 1306.2925,-1730.1024,20.9956, 0, 0); // ~~ Casa da arvore
    AddEntradaSaida(1318, 1318, "", "", 1925.4889,170.1802,37.2813, 0, 0, 299.7800,310.8952,1003.3047, 4, 0); // CATIVEIRO 1
    AddEntradaSaida(1318, 1318, "", "", -796.0077,2259.3499,59.4689, 0, 0, 244.4940,305.0316,999.1484, 1, 0); // CATIVEIRO 2
    AddEntradaSaida(1318, 1318, "{33AAEE}Segundo Andar\n{FFFFFF}Pressione {FF0000}'F' {FFFFFF}para subir", "{33AAEE}Primeiro Andar\n{FFFFFF}Pressione {FF0000}'F'{FFFFFF} para descer.", 1527.5156, 1335.3510, 10.9787, 3, 7, 1527.5156, 1335.3848, 15.2138, 3, 7, 3); // PREFEITURA
    AddEntradaSaida(1318, 1318, "{33AAEE}Mercado Negro\n{FFFFFF}Pressione {FF0000}'F' {FFFFFF}para entrar", "{33AAEE}Mercado Negro\n{FFFFFF}Pressione {FF0000}'F'{FFFFFF} para sair.", 2729.3267, -2451.4250, 17.5937, 0, 0, 1763.826660, -2617.908936, 126.185997, 1, 16, 3, .id = 16);
    AddEntradaSaida(1247, 1247, "{33AAEE}Bope\nAperte F para Subir.", "{FFFFFF}Aperte {FF0000}'F'{FFFFFF} para descer.", 222.7910, 180.6397, 1003.0313, 3, 2, 915.4518, -1021.1534, 111.0547, 0, 0, .OrgID = TEAM_BOPE);
    AddEntradaSaida(1318, 1318, "{33AAEE}Mina\nAperte F para Entrar.", "{FFFFFF}Aperte {FF0000}'F'{FFFFFF} para Sair.", 995.5361, -73.5942, 22.0867, 0, 0, 2396.1985, -1506.7729, 1402.2000, 27, 0);
}

Float:GetPlayerDistanceFromPlayer(playerid, giveid)
{
    new Float:X, Float:Y, Float:Z;
    GetPlayerPos(giveid, X, Y, Z);
    return GetPlayerDistanceFromPoint(playerid, X, Y, Z);
}

GetVehicleOffset(vehicleid, type, &Float:x, &Float:y, &Float:z)
{
    new Float:fPos[4], Float:fSize[3];

    if(!Iter_Contains(Veiculos, vehicleid))
    {
        x = 0.0;
        y = 0.0;
        z = 0.0;
        return 0;
    }
    else
    {
        GetVehiclePos(vehicleid, fPos[0], fPos[1], fPos[2]);
        GetVehicleZAngle(vehicleid, fPos[3]);
        GetVehicleModelInfo(GetVehicleModel(vehicleid), VEHICLE_MODEL_INFO_SIZE, fSize[0], fSize[1], fSize[2]);

        switch (type)
        {
            case VEHICLE_OFFSET_BOOT:
            {
                x = fPos[0] - (floatsqroot(fSize[1] + fSize[1]) * floatsin(-fPos[3], degrees));
                y = fPos[1] - (floatsqroot(fSize[1] + fSize[1]) * floatcos(-fPos[3], degrees));
                z = fPos[2];
            }
            case VEHICLE_OFFSET_HOOD:
            {
                x = fPos[0] + (floatsqroot(fSize[1] + fSize[1]) * floatsin(-fPos[3], degrees));
                y = fPos[1] + (floatsqroot(fSize[1] + fSize[1]) * floatcos(-fPos[3], degrees));
                z = fPos[2];
            }
            case VEHICLE_OFFSET_ROOF:
            {
                x = fPos[0];
                y = fPos[1];
                z = fPos[2] + floatsqroot(fSize[2]);
            }
        }
    }
    return 1;
}
GetVehicleSpeed(vehicleid)
{
   new Float:xPos[3];
   GetVehicleVelocity(vehicleid, xPos[0], xPos[1], xPos[2]);
   return floatround(floatsqroot(xPos[0] * xPos[0] + xPos[1] * xPos[1] + xPos[2] * xPos[2]) * 180.00);
}
Float:GetPlayerDistanceToVehicle(playerid, vehicleid)
{
    if(IsPlayerConnected(playerid))
    {
        new Float:PX,Float:PY,Float:PZ,Float:X,Float:Y,Float:Z;
        GetPlayerPos(playerid,PX,PY,PZ);
        GetVehiclePos(vehicleid, X,Y,Z);
        new Float:Distance = (X-PX)*(X-PX)+(Y-PY)*(Y-PY)+(Z-PZ)*(Z-PZ);
        return Distance;
    }
    return 99999.0;
}
CheckAbertura()
{
    #if FECHAR_ABERTURA == 1
        ServidorTrancado = true;
        datetime2stamp(TimeStamp_Abertura, ANO_ABERTURA, MES_ABERTURA, DIA_ABERTURA, HORA_ABERTURA, MINUTO_ABERTURA, SEGUNDO_ABERTURA);
        SendRconCommand("password "SENHA_SERVIDOR"");
        TimerTrancar = SetTimer("TrocarNome", 1000, true);
    #endif
}
CarregarEmpregos()
{
    for(new i; i < MAX_EMPREGOS; i ++)
    {
        if(SpawnVEmprego[i][spawn_pos][0] != 0.0)
        {
            CreateDynamicPickup(19132, 1, SpawnVEmprego[i][spawn_pos][0], SpawnVEmprego[i][spawn_pos][1], SpawnVEmprego[i][spawn_pos][2], 0);
            CreateDynamic3DTextLabel(fmat_return("{FF0000}Emprego %s\n{FFFFFF}Pressione 'F' para pegar seu veiculo.", EmpregosNames[i]), -1, SpawnVEmprego[i][spawn_pos][0], SpawnVEmprego[i][spawn_pos][1], SpawnVEmprego[i][spawn_pos][2], 6.0, .testlos = 1, .worldid = 0);
        }
    }
}