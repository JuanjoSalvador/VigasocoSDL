// GestorFrases.cpp
//
/////////////////////////////////////////////////////////////////////////////

#include "../systems/cpc6128.h"
#include "Juego.h"
#include "GestorFrases.h"
#include "Marcador.h"

using namespace Abadia;

/////////////////////////////////////////////////////////////////////////////
// tabla de frases
/////////////////////////////////////////////////////////////////////////////

	//CPC
	//char * GestorFrases::frases[0x38] = {

	//VGA
	//Anyadimos una frase mas que en la version original
	//para limpiar el area de frases al cargar/grabar las partidas
	//Cambiamos a un array de frases por cada idioma
	const char * GestorFrases::frases[8][0x38+1] = {
		{ // 0 Castellano
#ifdef LENG
	// Tiene que tener al menos un caracter, sino al hacer un frase++
	// en el bucle que recorre la frase se va de madre, al pensar
	// que al menos hay un caracter...
	" ", //	Limpiar el area de frases al cargar/salvar una partida
	"¿QUE EXTRAÑO LUGAR ES ESTE Y COMO HEMOS LLEGADO AQUI? ¿QUE ES ESTE TERRIBLE SILENCIO?",
	"ALGO NOS HA TRAIDO, ESTOY SEGURO PICKMAN, PERO ¿EL QUE?",
	"NO LO SE, HARLEY. LO AVERIGUAREMOS. ESTA NOCHE PARECE ETERNA",
	"ACABA DE AMANECER Y EL SOL PARECE MORIBUNDO. UN FRÍO ATROZ AZOTA LA LLANURA ALLÍ FUERA." ,
	"ESA SOMBRA SIGÁMOSLA", // TODO: añadir caracter para abrir y cerrar admiracion "¡ESA SOMBRA! ¡SIGÁMOSLA!"
	"AHORA NO PODÉIS INVOCARME. BAJO LA LUNA DEL TERCER DÍA, VOLVED, Y MIRADME CON OTROS OJOS."
#else
	"SECRETUM FINISH AFRICAE, MANUS SUPRA XXX AGE PRIMUM ET SEPTIMUM DE QUATOR",
	"BIENVENIDO A ESTA ABADIA, HERMANO. OS RUEGO QUE ME SIGAIS. HA SUCEDIDO ALGO TERRIBLE",
	"TEMO QUE UNO DE LOS MONJES HA COMETIDO UN CRIMEN. OS RUEGO QUE LO ENCONTREIS ANTES DE QUE LLEGUE BERNARDO GUI, PUES NO DESEO QUE SE MANCHE EL NOMBRE DE ESTA ABADIA",
	"DEBEIS RESPETAR MIS ORDENES Y LAS DE LA ABADIA. ASISTIR A LOS OFICIOS Y A LA COMIDA. DE NOCHE DEBEIS ESTAR EN VUESTRA CELDA",
	"DEJAD EL MANUSCRITO DE VENACIO O ADVERTIRE AL ABAD",
	"DADME EL MANUSCRITO, FRAY GUILLERMO",
	"LLEGAIS TARDE, FRAY GUILLERMO",
	"ESTA ES VUESTRA CELDA, DEBO IRME",
	"OS ORDENO QUE VENGAIS",
	"DEBEIS ABANDONAR EL EDIFICIO, HERMANO",
	"ADVERTIRE AL ABAD",
	"DEBEMOS IR A LA IGLESIA, MAESTRO",
	"DEBEMOS IR AL REFECTORIO, MAESTRO",
	"PODEIS IR A VUESTRAS CELDAS",
	"NO HABEIS RESPETADO MIS ORDENES. ABANDONAD PARA SIEMPRE ESTA ABADIA",
	"ESCUCHAD HERMANO, HE ENCONTRADO UN EXTRAÑO LIBRO EN MI CELDA",
	"ENTRAD EN VUESTRA CELDA, FRAY GUILLERMO",
	"HA LLEGADO BERNARDO, DEBEIS ABANDONAR LA INVESTIGACION",
	"¿DORMIMOS?, MAESTRO",
	"DEBEMOS ENCONTRAR UNA LAMPARA, MAESTRO",
	"VENID AQUI, FRAY GUILLERMO",
	"HERMANOS, VENACIO HA SIDO ASESINADO",
	"DEBEIS SABER QUE LA BIBLIOTECA ES UN LUGAR SECRETO. SOLO MALAQUIAS PUEDE ENTRAR. PODEIS IROS",
	"OREMOS",
	"HERMANOS, BERENGARIO HA DESAPARECIDO. TEMO QUE SE HAYA COMETIDO OTRO CRIMEN",
	"PODEIS COMER, HERMANOS",
	"HERMANOS, HAN ENCONTRADO A BERENGARIO ASESINADO",
	"VENID, FRAY GUILLERMO, DEBEMOS ENCONTRAR A SEVERINO",
	"DIOS SANTO... HAN ASESINADO A SEVERINO Y LE HAN ENCERRADO",
	"BERNARDO ABANDONARA HOY LA ABADIA",
	"MAÑANA ABANDONAREIS LA ABADIA",
	"ERA VERDAD, TENIA EL PODER DE MIL ESCORPIONES",
	"MALAQUIAS HA MUERTO",
	"SOIS VOS, GUILERMO... PASAD, OS ESTABA ESPERANDO. TOMAD, AQUI ESTA VUESTRO PREMIO",
	"ESTAIS MUERTO, FRAY GUILLERMO, HABEIS CAIDO EN LA TRAMPA",
	"VENERABLE JORGE, VOIS NO PODEIS VERLO, PERO MI MAESTRO LLEVA GUANTES. PARA SEPARAR LOS FOLIOS TENDRIA QUE HUMEDECER LOS DEDOS EN LA LENGUA, HASTA QUE HUBIERA RECIBIDO SUFICIENTE VENENO",
	"SE ESTA COMIENDO EL LIBRO, MAESTRO",
	"DEBEIS ABANDONAR YA LA ABADIA",
	"ES MUY EXTRAÑO, HERMANO GUILLERMO. BERENGARIO TENIA MANCHAS NEGRAS EN LA LENGUA Y EN LOS DEDOS",
	"PRONTO AMANECERA, MAESTRO",
	"LA LAMPARA SE AGOTA",
	"HABEIS ENTRADO EN MI CELDA",
	"SE HA AGOTADO LA LAMPARA",
	"JAMAS CONSEGUIREMOS SALIR DE AQUI",
	"ESPERAD, HERMANO",
	"OCUPAD VUESTRO SITIO, FRAY GUILLERMO",
	"ES EL COENA CIPRIANI DE ARISTOTELES. AHORA COMPRENDEREIS POR QUE TENIA QUE PROTEGERLO. CADA PALABRA ESCRITA POR EL FILOSOFO HA DESTRUIDO UNA PARTE DEL SABER DE LA CRISTIANDAD. SE QUE HE ACTUADO SIGUIENDO LA VOLUNTAD DEL SEÑOR... LEEDLO, PUES, FRAY GUILLERMO. DESPUES TE LO MOSTRARE A TI MUCHACHO",
	"FUE UNA BUENA IDEA ¿VERDAD?; PERO YA ES TARDE",
	"QUIERO QUE CONOZCAIS AL HOMBRE MAS VIEJO Y SABIO DE LA ABADIA",
	"VENERABLE JORGE, EL QUE ESTA ANTE VOS ES FRAY GUILLERMO, NUESTRO HUESPED",
	"SED BIENVENIDO, VENERABLE HERMANO; Y ESCUCHAD LO QUE OS DIGO. LAS VIAS DEL ANTICRISTO SON LENTAS Y TORTUOSAS. LLEGA CUANDO MENOS LO ESPERAS. NO DESPERDICIEIS LOS ULTIMOS DIAS",
	"LO SIENTO, VENERABLE HERMANO, NO PODEIS SUBIR A LA BIBLIOTECA",
	"SI LO DESEAIS, BERENGARIO OS MOSTRARA EL SCRIPTORIUM",
	"AQUI TRABAJAN LOS MEJORES COPISTAS DE OCCIDENTE",
	"AQUI TRABAJABA VENACIO",
	"VENERABLE HERMANO, SOY SEVERINO, EL ENCARGADO DEL HOSPITAL. QUIERO ADVERTIROS QUE EN ESTA ABADIA SUCEDEN COSAS MUY EXTRAÑAS. ALGUIEN NO QUIERE QUE LOS MONJES DECIDAN POR SI SOLOS LO QUE DEBEN SABER"
	// Tiene que tener al menos un caracter, sino al hacer un frase++
	// en el bucle que recorre la frase se va de madre, al pensar
	// que al menos hay un caracter...
	, " " //	Limpiar el area de frases al cargar/salvar una partida
#endif
		}, // Fin textos 0 castellano
		{  // 1 Inglés
	"SECRETUM FINIS AFRICAE, MANUS SUPRA AAA IDOLUM AGE PRIMUM ET SEPTIMUM DE QUATUOR",
	"WELCOME TO THIS ABBEY, BROTHER. I BEG YOU TO FOLLOW ME. SOMETHING HORRIBLE HAS HAPPENED",
	"I AM AFRAID THAT ONE OF THE MONKS HAS COMMITTED A MURDER. I BEG YOU TO FIND HIM BEFORE BERNARD GUI ARRIVES, AS I DO NOT WISH THE NAME OF THIS ABBEY TO BE STAINED.",
	"YOU MUST RESPECT MY ORDERS AND THE ONES OF THE ABBEY. ATTEND THE OFFICES AND MEAL. AT NIGHT YOU MUST BE IN YOUR CELL.",
	"LEAVE VENANTIUS MANUSCRIPT OR I WILL WARN THE ABBOT.",
	"GIVE THE MANUSCRIPT TO ME, BROTHER WILLIAM",
	"YOU ARE LATE, BROTHER WILLIAM",
	"THIS IS YOUR CELL. I HAVE TO GO",
	"I ORDER YOU TO COME",
	"YOU MUST LEAVE THE BUILDING, BROTHER",
	"I WILL WARN THE ABBOT",
	"WE MUST GO TO CHURCH, MASTER",
	"WE MUST GO TO THE REFECTORY, MASTER",
	"YOU MAY GO TO YOUR CELLS",
	"YOU HAVE NOT RESPECTED MY ORDERS. LEAVE THIS ABBEY FOR EVER.",
	"LISTEN BROTHER, I HAVE FOUND A STRANGE BOOK IN MY CELL.",
	"GO INTO YOUR CELL, BROTHER WILLIAM",
	"BERNARD HAS ARRIVED, YOU MUST STOP YOUR INVESTIGATION",
	"SHALL WE SLEEP, MASTER?",
	"WE MUST FIND A LAMP, MASTER",
	"COME HERE, BROTHER WILLIAM",
	"BROTHERS, VENANTIUS HAS BEEN MURDERED",
	"YOU MUST KNOW THAT THE LIBRARY IS A SECRET PLACE. JUST MALACHIA CAN GO IN. YOU MAY GO.",
	"OREMUS",
	"BROTHERS, BERENGAR HAS DISAPPEARED. I AM AFRAID ANOTHER MURDER HAS BEEN COMMITTED.",
	"YOU MAY EAT, BROTHERS",
	"BROTHERS, BERENGAR HAS BEEN FOUND MURDERED",
	"COME, BROTHER WILLIAM, WE HAVE TO FIND SEVERINUS",
	"HOLY GOD... SEVERINUS HAS BEEN MURDERED AND LOCKED IN",
	"BERNARD WILL LEAVE THE ABBEY TODAY",
	"TOMORROW, YOU WILL LEAVE THE ABBEY",
	"IT WAS TRUE, IT HAD THE POWER OF THOUSAND SCORPIONS",
	"MALACHIA IS DEAD",
	"IS IT YOU, WILLIAM... COME IN, I WAS WAITING FOR YOU. TAKE THIS, HERE IS YOUR REWARD",
	"YOU ARE DEAD, BROTHER WILLIAM. YOU FELL INTO THE TRAP",
	"VENERABLE JORGE, YOU CANNOT SEE IT, BUT MY MASTER IS WEARING GLOVES. IN ORDER TO SEPARATE THE SHEETS HE SHOULD DAMPEN HIS FINGERS WITH HIS TONGUE, UNTIL HE HAD RECEIVED ENOUGH POISON",
	"HE IS EATING THE BOOK, MASTER",
	"YOU MUST LEAVE THE ABBEY",
	"IT IS VERY STRANGE, BROTHER WILLIAM. BERENGAR HAD BLACK STAINS ON HIS TONGUE AND FINGERS",
	"DAWN WILL BREAK SOON, MASTER",
	"THE LAMP IS RUNNING OUT",
	"YOU HAVE ENTERED MY CELL",
	"THE LAMP HAS RUN OUT",
	"WE WILL NEVER MANAGE TO GET OUT OF HERE",
	"WAIT, BROTHER",
	"TAKE YOUR PLACE, BROTHER WILLIAM",
	"IT IS THE COENA CIPRIANI OF ARISTOTLE. NOW YOU WILL UNDERSTAND WHY I HAD TO PROTECT IT. EACH WORD WRITTEN BY THE PHILOSOPHER HAS DESTROYED A PART OF THE KNOWLEDGE OF CHRISTENDOM. "
	"I KNOW I HAVE ACTED FOLLOWING THE WILL OF GOD. READ IT, THEN, BROTHER WILLIAM. AFTER THAT I WILL SHOW IT TO YOU, KID.",
	"IT WAS A GOOD IDEA, WAS NOT IT?; BUT NOW IT IS TOO LATE.",
	"I WANT YOU TO MEET THE OLDEST AND WISEST MAN IN THE ABBEY",
	"VENERABLE JORGE, THE ONE BEFORE YOU IS BROTHER WILLIAM, OUR GUEST",
	"BE WELCOME, VENERABLE BROTHER; AND LISTEN WHAT I TELL YOU. THE ANTICHRIST MEANS ARE SLOW AND TORTUOUS. HE COMES WHEN YOU DO NOT EXPECT. DO NOT WASTE THE LAST DAYS",
	"I AM SORRY, VENERABLE BROTHER, YOU MAY NOT GO UP TO THE LIBRARY",
	"IF YOU WISH, BERENGAR WILL SHOW YOU THE SCRIPTORIUM",
	"THE BEST COPYISTS IN THE WEST WORK IN HERE",
	"VENANTIUS USED TO WORK HERE",
	"VENERABLE BROTHER, I AM SEVERINUS, THE RESPONSIBLE FOR THE HOSPITAL. I WANT TO WARN YOT THAT VERY STRANGE THINGS HAPPEN IN THIS ABBEY. SOMEONE DOES NOT WANT THE MONKS TO DECIDE BY THEMSELVES WHAT THEY HAVE TO KNOW.",
	" "
		}, // Fin textos 1 ingles
		{  // 2 Brasil
	"SECRETUM FINIS AFRICAE, MANUS SUPRA AAA IDOLUM AGE PRIMUM ET SEPTIMUM DE QUATUOR",
	"BEM-VINDO A ESTA ABADIA, IRMÃO. ROGO QUE ME SIGAS. ACONTECEU ALGO TERRÍVEL",
	"TEMO QUE UM DOS MONGES TENHA COMETIDO UM CRIME. ROGO-TE QUE O ENCONTRES ANTES QUE BERNARDO GUI CHEGUE, POIS NÃO DESEJO QUE SE MANCHE O NOME DESTA ABADIA",
	"DEVES RESPEITAR MINHAS ORDENS E AS REGRAS DA ABADIA; ASSISTIR AOS OFÍCIOS E ÀS REFEIÇÕES. À NOITE, DEVES ESTAR EM TUA CELA",
	"DEIXA O MANUSCRITO DE VENÂNCIO OU AVISAREI AO ABADE",
	"DÁ-ME O MANUSCRITO, FREI GUILHERME",
	"CHEGASTE TARDE, FREI GUILHERME",
	"ESTA É TUA CELA, DEVO IR",
	"ORDENO QUE VENHAS",
	"DEVES ABANDONAR O EDIFÍCIO, IRMÃO",
	"AVISAREI AO ABADE",
	"DEVEMOS IR Á IGREJA, MESTRE",
	"DEVEMOS IR AO REFEITÓRIO, MESTRE",
	"PODEIS IR PARA VOSSAS CELAS",
	"NÃO RESPEITASTE MINHAS ORDENS, ABANDONA PARA SEMPRE ESTA ABADIA",
	"ESCUTA, IRMÃO, ENCONTREI UM ESTRANHO LIVRO EM MINHA CELA",
	"ENTRA EM TUA CELA, FREI GUILHERME",
	"BERENGÁRIO CHEGOU, DEVES ABANDONAR A INVESTIGAÇÃO",
	"DORMIMOS, MESTRE?",
	"DEVEMOS ENCONTRAR UMA LAMPARINA, MESTRE",
	"VEM AQUI, FREI GUILHERME",
	"IRMÃOS, VENÂNCIO FOI ASSASSINADO",
	"DEVES SABER QUE A BIBLIOTECA É UM LUGAR SECRETO. SOMENTE MALAQUIAS PODE ENTRAR. PODES IR",
	"OREMOS",
	"IRMÃOS, BERENGÁRIO DESAPARECEU. TEMO QUE SE TENHA COMETIDO OUTRO CRIME",
	"PODEIS COMER, IRMÃOS",
	"IRMÃOS, ENCONTRARAM BERENGÁRIO ASSASSINADO",
	"VEM, FREI GUILHERME, DEVEMOS ENCONTRAR SEVERINO",
	"SANTO DEUS... ASSASSINARAM SEVERINO E O TRANCARAM",
	"BERNARDO ABANDONARÁ HOJE A ABADIA",
	"AMANHÃ ABANDONARÁS A ABADIA",
	"ERA VERDADE... TINHA O PODER DE MIL ESCORPIÕES",
	"MALAQUIAS ESTÁ MORTO",
	"ES TU, GUILHERME... PASSA, ESTAVA TE ESPERANDO. TOMA, AQUI ESTÁ TEU PRÊMIO",
	"ESTÁS MORTO, FREI GUILHERME, CAÍSTE NA ARMADILHA",
	"VENERÁVEL JORGE, NÃO PODES VER, MAS MEU MESTRE USA LUVAS. PARA SEPARAR AS FOLHAS, TERIA QUE UMEDECER OS DEDOS NA LÍNGUA ATÉ QUE TIVESSE RECEBIDO VENENO SUFICIENTE",
	"ESTÁ COMENDO O LIVRO, MESTRE",
	"DEVES ABANDONAR A ABADIA",
	"É MUITO ESTRANHO, IRMÃO GUILHERME. BERENGÁRIO TINHA MANCHAS NEGRAS NA LÍNGUA E NOS DEDOS",
	"LOGO AMANHECERÁ, MESTRE",
	"O ÓLEO ESTÁ SE ESGOTANDO",
	"ENTRASTE NA MINHA CELA",
	"O ÓLEO ESGOTOU-SE",
	"JAMAIS CONSEGUIREMOS SAIR DAQUI",
	"ESPERE, IRMÃO",
	"OCUPATEU LUGAR, FREI GUILHERME",
	"É O COENA CIPRIANI DE ARISTÓTELES. AGORA COMPREENDES POR QUE TINHA QUE PROTEGÊ-LO. CADA PALAVRA ESCRITA PELO FILÓSOFO DESTRUIU UMA PARTE DO SABER DA CRISTANTADE. SEI QUE AGI SEGUINDO A VONTADE DO SENHOR... "
	"LÊ O LIVRO AGORA, FREI GUILHERME, DEPOIS MOSTRA-O PARA TEU DISCÍPULO",
	"FOI UMA BOA IDÉIA, NÃO É VERDADE?  MAS JÁ É TARDE",
	"QUERO QUE CONHEÇAS O HOMEM MAIS VELHO E SÁBIO DA ABADIA",
	"VENERÁVEL JORGE, QUEM ESTÁ DIANTE DE TI É FREI GUILHERME, NOSSO HÓSPEDE",
	"SÊ BEM-VINDO, VENERÁVEL IRMÃO; E ESCUTA BEM O QUE TE DIGO. OS CAMINHOS DO ANTI-CRISTO SÃO LENTOS E TORTUOSOS. CHEGA QUANDO MENOS O ESPERAS. NÃO DESPERDICES OS ÚLTIMOS DIAS",
	"DESCULPA-ME, VENERÁVEL IRMÃO, MAS NÃO PODES SUBIR À BIBLIOTECA",
	"SE DESEJARES, BERENGÁRIO PODERÁ MOSTRAR-TE O SCRIPTORIUM",
	"AQUI TRABALHAM OS MELHORES COPISTAS DO OCIDENTE",
	"AQUI TRABALHAVA VENÂNCIO",
	"VENERÁVEL IRMÃO, SOU SEVERINO, O ENCARREGADO DA ENFERMARIA. QUERO ADVERTI-LO QUE NESTA ABADIA ACONTECEM COISAS MUITO ESTRANHAS. ALGUÉM NÃO QUER QUE OS MONGES DECIDAM POR SI SÒ O QUE DEVEM SABER",
	" "
		}, // Fin textos 2 Brasil
		{  // 3 Catalan
	"SECRETUM FINIS AFRICAE, MANUS SUPRA AAA IDOLUM AGE PRIMUM ET SEPTIMUM DE QUATUOR",
	"BENVINGUT A AQUESTA ABADIA, GERMÀ. US PREGO QUE EM SEGUIU. HA SUCCEIT QUELCOM TERRIBLE",
	"EM TEMO QUE UN DELS MONJOS HA COMÉS UN CRIM. US PREGO QUE EL TROBEU ABANS QUE ARRIBI BERNAT GUI, DONCS NO DESITJO QUE TAQUI EL NOM D'AQUESTA ABADIA",
	"HEU DE RESPECTAR LES MEVES ORDRES I LES DE L'ABADIA. ASSISTIR ALS OFICIS I AL DINAR. DE NIT HEU D'ESTAR A LA VOSTRA CEL.LA",
	"DEIXEU EL MANUSCRIT D'EN VENANCI O ADVERTIRÉ A L'ABAT",
	"DONEU-ME EL MANUSCRIT, FRA GUILLEM",
	"ARRIBEU TARD, FRA GUILLEM",
	"AQUESTA ES LA VOSTRA CEL.LA. HE D'ANAR-ME'N",
	"US ORDENO QUE VINGUEU ",
	"HEU D'ABANDONAR L'EDIFICI, GERMÀ",
	"ADVERTIRÉ A L'ABAT",
	"HEM D'ANAR A L'ESGLÉSIA, MESTRE",
	"HEM D'ANAR AL REFECTORI, MESTRE",
	"PODEU ANAR A LES VOSTRES CEL.LES ",
	"NO HEU RESPECTAT LES MEVES ORDRES. ABANDONEU PER SEMPRE AQUESTA ABADIA",
	"ESCOLTEU GERMÀ,, HE TROBAT UN ESTRANY LLIBRE A LA MEVA CEL.LA ",
	"ENTREU A LA VOSTRA CEL.LA, FRA GUILLEM",
	"HA ARRIVAT BERNAT, HEU D'ABANDONAR LA INVESTIGACIÓ",
	"DORMIM, MESTRE?",
	"HEM DE TROBAR UNA LÀMPADA, MESTRE",
	"VENIU AQUÍ, FRA GUILLEM",
	"GERMANS, VENANCI HA ESTAT ASSASSINAT",
	"HEU DE SABER QUE LA BIBLIOTECA ÉS UN LLOC SECRET. NOMÉS MALAQUIES POT ENTRAR. PODEU MARXAR.",
	"PREGUEM",
	"GERMANS, BERENGUER HA DESAPAREGUT. TEMO QUE S'HAGI COMÉS UN ALTRE CRIM",
	"PODEU MENJAR, GERMANS",
	"GERMANS, HAN TROBAT A BERENGUER ASSASSINAT",
	"VENIU, FRA GUILLEM, HEM DE TROBAR A SEVERÍ",
	"DÈU SANT... HAN ASSASSINAT A SEVERÍ I L'HAN TANCAT",
	"BERNAT ABANDONARÀ AVUI L'ABADIA",
	"DEMÀ, ABANDONAREU L'ABADIA",
	"ERA VERITAT, TENIA EL PODER DE MIL ESCORPINS",
	"MALAQUIES HA MORT",
	"SOU VOS, GUILLEM... PASSEU, US ESTAVA ESPERANT. TENIU, AQUÍ TENIU EL VOSTRE PREMI",
	"ESTEU MORT, FRA GUILLEM. HEU CAIGUT A LA TRAMPA",
	"VENERABLE JORDI, VOS NO PODEU VEURE-HO, PERO EL MEU MESTRE PORTA GUANTS. PER A SEPARAR ELS FOLIS HAURIA D' HUMITEJAR ELS DITS A LA LLENGUA, FINS QUE HAGUÉS REBUT PROU VERÍ",
	"S'ESTÀ MENJANT EL LLIBRE, MESTRE",
	"HEU D'ABANDONAR L'ABADIA",
	"ES MOLT ESTRANY, GERMÀ GUILLEM. BERENGUER TENIA TAQUES NEGRES A LA LLENGUA I ALS DITS",
	"AVIAT SORTIRÀ EL SOL, MESTRE",
	"LA LÀMPADA S'ESGOTA",
	"HEU ENTRAT A LA MEVA CEL.LA ",
	"S'HA ESGOTAT LA LÀMPADA",
	"MAI ACONSEGUIREM SORTIR D'AQUÍ",
	"ESPEREU, GERMÀ",
	"OCUPEU EL VOSTRE LLOC, FRA GUILLEM",
	"ÉS EL COENA CIPRIANI D'ARISTÒTIL. ARA COMPRENDREU PER QUÈ HAVIA DE PROTEGIR-LO. CADA PARAULA ESCRITA PEL FILÒSOF HA DESTRUÏT UNA PART DEL SABER DE LA CRISTIANDAT. "
	"SÉ QUE HE ACTUAT SEGUINT LA VOLUNTAT DEL SENYOR... LLEGIU-LO, DONCS, FRA GUILLEM. DESPRÉS T'HO DEMOSTRARÉ A TU NOI",
	"VA SER BONA IDEA OI?; PERÒ JA ÉS TARD",
	"VULL QUE CONEGUEU A L'HOME MÉS VELL I SAVI DE L'ABADIA",
	"VENERABLE JORDI, QUI ESTA DAVANT VOSTRE ES FRA GUILLEM, EL NOSTRE HOSTE",
	"SIGUEU BENVINGUT, VENERABLE GERMÀ; I ESCOLTEU EL QUE US DIC. LES VIES DE L'ANTICRIST SON LENTES I TORTUOSES. ARRIBA QUAN MENYS HO ESPERES. NO MALGASTEU ELS DARRERS DIES ",
	"HO SENTO, VENERABLE GERMÀ, NO PODEU PUJAR A LA BIBLIOTECA",
	"SI HO DESITGEU, BERENGUER US MOSTRARÀ L'SCRIPTORIUM",
	"AQUÍ TREBALLEN ELS MILLORS COPISTES D'OCCIDENT",
	"AQUÍ TREBALLAVA VENANCI",
	"VENERABLE GERMÀ, SÓC SEVERÍ, L'ENCARREGAT DE L'HOSPITAL. VULL ADVERTIR-VOS QUE A AQUESTA ABADIA SUCCEEIXEN COSES MOLT EXTRANYES. ALGÚ NO VOL QUE ELS MONJOS DECIDEIXIN PER SI SOLS EL QUE HAN DE SABER",
	" "
		}, // Fin textos 3 Catalan
		{  // 4 Gallego
	"SECRETUM FINIS AFRICAE, MANUS SUPRA AAA IDOLUM AGE PRIMUM ET SEPTIMUM DE QUATUOR",
	"BENVIDO A ESTA ABADÍA, IRMÁN. PRÉGOVOS QUE ME SIGADES. ACONTECEU ALGO TERRIBLE",
	"TÉMOME QUE UN DOS MONXES COMETERA UN CRIME. PRÉGOVOS QUE O ATOPEDES ANTES DE QUE CHEGUE BERNARDO GUI, POIS NON É O MEU DESEXO QUE SE MANCHE O NOME DESTA ABADÍA",
	"DEBEDES RESPECTA-LAS MIÑAS ORDES E AS DA ABADÍA. ASISTIR ÓS OFICIOS E Ó XANTAR. DE NOITE DEBEDES FICAR NA VOSA CELA",
	"DEIXADE O MANUSCRITO DE VENANCIO OU ADVERTIREI Ó ABADE",
	"DÁDEME O MANUSCRITO, FRAI GUILLERME",
	"CHEGADES TARDE, FRAI GUILLERME",
	"ESTA É A VOSA CELA. EU LISCO, TEÑO TAREFAS QUE FACER",
	"ORDÉNOVOS QUE VEÑADES",
	"DEBEDES ABANDONA-LO EDIFICIO, IRMÁN",
	"ADVERTIREI AO ABADE",
	"TEMOS QUE IR Á IGREXA, MESTRE",
	"TEMOS QUE IR AO REFECTORIO, MESTRE",
	"PODEDES RETIRARVOS ÁS VOSAS CELAS",
	"NON ACATÁSTEDES AS MIÑAS ORDES. DEIXADE PRA SEMPRE ESTA ABADÍA",
	"ESCOITADE IRMÁN, ATOPEI UN EXTRANO LIBRO NA MIÑA CELA",
	"ENTRADE NA VOSA CELA, FRAI GUILLERME",
	"CHEGOU BERNARDO, DEBEDES ABANDONA-LAS VOSAS PESQUISAS",
	"DURMIMOS?, MESTRE",
	"TEMOS QUE ATOPAR UNHA LÁMPADA, MESTRE",
	"VIDE AQUI, FRAI GUILLERME",
	"IRMÁNS, VENANCIO FOI ASASINADO",
	"DEBEDES SABER QUE A BIBLIOTECA É UN LUGAR SEGREDO. SÓ MALAQUÍAS PODE ENTRAR. PODEDES IRVOS.",
	"OREMOS",
	"IRMÁNS, BERENGARIO DESAPARECEU. TÉMOME QUE SE COMETERA OUTRO CRIME",
	"PODEDES XANTAR, IRMÁNS",
	"IRMÁNS, ATOPARON A BERENGARIO ASASINADO",
	"VIDE, FRAI GUILLERME, DEBEMOS ATOPAR A SEVERINO",
	"DEUS SANTO... ASESINARON A SEVERINO E PECHARONO DENTRO",
	"BERNARDO DEIXARÁ HOXE A ABADÍA",
	"MAÑÁN, ABANDONAREDES A ABADÍA",
	"ERA VERDADE, TIÑA O PODER DE MIL ESCORPIÓNS",
	"MALAQUIAS MORREU",
	"SODES VOS, GUILLERME... PASADE, ESTABAVOS AGARDANDO. TOMADE, AQUI ESTA O VOSO GALARDÓN",
	"ESTADES MORTO, FRAI GUILLERME. CAÉSTEDES NA TRAMPA",
	"VENERABLE XURXO, VOS NON PODEDES VELO, PERO O MEU MESTRE LEVA UNHAS LUVAS. PRA SEPARA-LOS FOLIOS TERÍA QUE HUMEDECE-LOS DEDOS NA LINGUA, ATA QUE RECIBIRA VELENO ABONDO",
	"ESTA A COME-LO LIBRO, MESTRE",
	"DEBEDES ABANDONA-LA ABADÍA",
	"ABOFÉ QUE É EXTRAÑO, IRMÁN GUILLERME. BERENGARIO TIÑA MANCHAS NEGRAS NA LINGUA E NOS DEDOS",
	"DESEGUIDO CHEGARÁ O AMENCER, MESTRE",
	"A LÁMPADA ESGÓTASE",
	"ENTRÁSTEDES NA MIÑA CELA",
	"ESGOTOUSE A LÁMPADA",
	"ENDEXAMAIS ACADEREMOS SAIR DE AQUÍ",
	"AGARDADE, IRMÁN",
	"OCUPADE O VOSO SITIO, FRAI GUILLERME",
	"É O COENA CIPRIANI DE ARISTÓTELES. AGORA COMPRENDEREDES POR QUE TIÑA QUE PROTEXELO. CADA PALABRA ESCRITA POLO FILÓSOFO FIXO ANACOS UNHA PARTE DO SABER DA CRISTIANDADE. "
	"SEI QUE OBREI SIGUINDO A VONTADE DO SEÑOR... LEDEO, POIS, FRAI GUILLERME. DESPOIS MOSTRAREICHO A TI RAPAZ",
	"FOI UNHA BOA IDEA  NON É VERDADE?; PERO XA É TARDE",
	"DESEXO QUE CONOZCADES Ó HOME MÁIS VELLO E SABIO DA ABADÍA",
	"VENERABLE XURXO, O QUE ESTA DIANTE VOSA É FRAI GUILLERME, O NOSO HÓSPEDE",
	"SEDE BENVIDO, VENERABLE IRMÁN; E ESCOITADE O QUE VOS DIGO. AS VIAS DO ANTICRISTO SONVOS LENTAS E TORTUOSAS. CHEGA CANDO MENOS O ESPERAS. NON MALGASTEDES OS DERRADEIROS DÍAS",
	"SINTOLLO, VENERABLE IRMÁN, NON PODEDES SUBIR Á BIBLIOTECA",
	"SE O DESEXASES, BERENGARIO MOSTRARAVOS O SCRIPTORIUM",
	"AQUI TRABALLAN OS MELLORES COPISTAS DE OCCIDENTE",
	"AQUI TRABALLABA VENANCIO",
	"VENERABLE IRMÁN, SON SEVERINO, O ENCARGADO DO HOSPITAL. QUERO PREVIRVOS QUE NESTA ABADÍA ACONTECEN COUSAS MOI EXTRANAS. ALGUÉN NON DESEXA QUE OS MONXES DECIDAN POR SI SÓS O QUE DEBEN DE SABER",
	" "

		}, // Fin textos 4 Gallego
		{  // 5 Italiano
	"SECRETUM FINIS AFRICAE, MANUS SUPRA  AAA IDOLUM AGE PRIMUM ET SEPTIMUM DE QUATUOR",
	"BENVENUTO A QUESTA ABBAZIA, FRATELLO. VI PREGO DI SEGUIRMI. QUALCOSA DI TERRIBILE É ACCADUTO",
	"TEMO CHE UNO DEI MONACI ABBIA COMMESSO UN CRIMINE. VI PREGO DI INCONTRARLO PRIMA CHE ARRIVI BERNARDO GUI, POICHÉ NON DESIDERO CHE IL NOME DI QUESTA ABBAZIA SI MACCHI",
	"DOVETE RISPETTARE I MIEI ORDINI E QUELLI DELLA ABBAZIA. PARTECIPARE ALLE FUNZIONI E AI PASTI. DI NOTTE DOVETE RESTARE NELLA VOSTRA CELLA",
	"LASCIATE IL MANOSCRITTO DI VENANZIO O AVVERTIRÒ L'ABATE",
	"DATEMI IL MANOSCRITTO, FRATE GUGLIELMO",
	"ARRIVATE TARDI, FRATE GUGLIELMO",
	"QUESTA È LA VOSTRA CELLA. DEVO ANDARE",
	"VI ORDINO DI VENIRE",
	"DOVETE ABBANDONARE L'EDIFICIO, FRATELLO",
	"AVVERTIRE L'ABATE",
	"DOBBIAMO ANDARE ALLA CHIESA, MAESTRO",
	"DOBBIAMO ANDARE AL REFETTORIO, MAESTRO",
	"POTETE RECARVI ALLE VOSTRE CELLE",
	"NON AVETE RISPETTATO I MIEI ORDINI. ABBANDONATE PER SEMPRE QUESTA ABBAZIA",
	"ASCOLTATE FRATELLO, HO TROVATO UNO STRANO LIBRO NELLA MIA CELLA",
	"ENTRATE NELLA VOSTRA CELLA, FRATE GUGLIELMO",
	"È ARRIVATO BERNARDO, DOVETE ABBANDONARE L'INVESTIGAZIONE",
	"DORMIAMO, MAESTRO?",
	"DOBBIAMO TROVARE UNA LAMPADA, MAESTRO",
	"VENITE QUI, FRATE GUGLIELMO",
	"FRATELLI, VENANZIO È STATO ASSASSINATO",
	"DOVETE SAPERE CHE LA BIBLIOTECA È UN LUOGO SEGRETO. SOLO MALACHIA PUÒ ENTRARE. POTETE ANDARE",
	"PREGHIAMO",
	"FRATELLI, BERENGARIO È SCOMPARSO. TEMO CHE SIA STATO COMMESSO UN ALTRO CRIMINE",
	"POTETE MANGIARE, FRATELLI",
	"FRATELLI, HANNO TROVATO BERNARDO ASSASSINATO",
	"VENITE, FRATE GUGLIELMO, DOBBIAMO TROVARE SEVERINO",
	"DIO SANTO... HANNO ASSASSINATO SEVERINO E LO HANNO SEPPELLITO",
	"BERNARDO DOVRÀ ABBANDONARE OGGI L'ABBAZIA",
	"DOMANI ABBANDONERETE L'ABBAZIA",
	"ERA VERO, AVEVA IL POTERE DI MILLE SCORPIONI",
	"MALACHIA È MORTO",
	"SIETE VOI, GUGLIELMO... PASSATE, VI STAVO ASPETTANDO. PRENDETE, QUESTO È IL VOSTRO PREMIO",
	"SIETE MORTO, FRATE GUGLIELMO. SIETE CADUTO NELLA TRAPPOLA",
	"VENERABILE JORGE, VOI NON POTETE VEDERLO, MA IL MIO MAESTRO PORTA I GUANTI. PER SEPARARE I FOGLI DOVREBBE INUMIDIRE LE DITA CON LA LINGUA, FINO AD AVER INGERITO SUFFICIENTE VELENO",
	"SI STA MANGIANDO IL LIBRO, MAESTRO",
	"DOVETE ABBANDONARE L'ABBAZIA",
	"È MOLTO STRANO, FRATE GUGLIELMO, BERENGARIO AVEVA MACCHIE NERE SULLA LINGUA E SULLE DITA",
	"PRESTO SARÀ L'ALBA, MAESTRO",
	"LA LAMPADA SI SPEGNE",
	"SIETE ENTRATI NELLA MIA CELLA",
	"SI È SPENTA LA LAMPADA",
	"NON RIUSCIREMO MAI A USCIRE DA QUI",
	"ASPETTATE, FRATELLO",
	"OCCUPATE IL VOSTRO POSTO, FRATE GUGLIELMO",
	"È IL COENA CYPRIANI DI ARISTOTELE. ORA CAPIRETE PERCHÉ DOVEVO PROTEGGERLO. OGNI PAROLA SCRITTA DAL FILOSOFO HA DISTRUTTO UNA PARTE DEL SAPERE DELLA CRISTIANITÀ. SO DI AVER AGITO SEGUENDO LA VOLONTÀ DEL SIGNORE... "
	"LEGGETELO, DUNQUE, FRATE GUGLIELMO. DOPO LO MOSTRERÒ A TE RAGAZZO",
	"È STATA UNA BUONA IDEA, VERO? PERÒ È GIÀ TARDI",
	"VOGLIO CHE CONOSCIATE L'UOMO PIÙ VECCHIO E SAGGIO DELL'ABBAZIA",
	"VENERABILE JORGE, COLUI CHE STA DAVANTI A VOI È FRATE GUGLIELMO, NOSTRO OSPITE",
	"SIETE IL BENVENUTO, VENERABILE FRATELLO; E ASCOLTATE QUELLO CHE VI DICO. LE VIE DELL'ANTICRISTO SONO LENTE E TORTUOSE. ARRIVA QUANDO MENO LO SI ASPETTA. NON SPRECATE GLI ULTIMI GIORNI",
	"SPIACENTE, VENERABILE FRATELLO, NON POTETE SALIRE ALLA BIBLIOTECA",
	"SE LO DESIDERATE BERENGARIO VI MOSTRERÀ LO SCRIPTORIUM",
	"QUI LAVORANO I MIGLIORI COPISTI D'OCCIDENTE",
	"QUI LAVORAVA VENANZIO",
	"VENERABILE FRATELLO, SONO SEVERINO, L'INCARICATO DELL'OSPEDALE. VOGLIO AVVERTIRVI CHE IN QUESTA ABBAZIA CAPITANO COSE MOLTO STRANE. QUALCUNO NON VUOLE CHE I MONACI DECIDANO DA SOLI QUELLO CHE DEVONO SAPERE",
	" "
		}, // Fin textos 5 Italiano
		{  // 6 Fines
	"SECRETUM FINIS AFRICAE, MANUS SUPRA AAA IDOLUM AGE PRIMUM ET SEPTIMUM DE QUATUOR",
	"TERVETULOA LUOSTARIIMME VELI. PYYDÄN TEITÄ SEURAAMAAN MINUA. JOTAIN KAUHEAA ON TAPAHTUNUT",
	"PELKÄÄN YHDEN MUNKEISTAMME SYYLLISTYNEEN MURHAAN. PYYDÄN, ETSIKÄÄ MURHAAJA ENNEN BERNARD GUIN SAAPUMISTA, JOTTA LUOSTARIMME NIMI EI TAHRIINTUISI VEREEN.",
	"TEIDÄN TULEE KUNNIOITTAMAN MINUN KÄSKYJÄNI JA TÄMÄN LUOSTARIN SÄÄNTÖJÄ. OSALLISTUKAA PALVELUKSIIN JA ATERIOILLE. YÖT TEIDÄN TULEE VIETTÄMÄN KAMMIOISSANNE.",
	"JÄTTÄKÄÄ VENANTIUKSEN KÄSIKIRJOITUS RAUHAAN TAI KERRON TOIMISTANNE APOTTILLE.",
	"VELI WILLIAM, LUOVUTTAKAA KÄSIKIRJOITUS MINULLE.",
	"VELI WILLIAM, OLETTE MYÖHÄSSÄ",
	"TÄMÄ ON KAMMIONNE. MINUN ON MENTÄVÄ.",
	"MÄÄRÄÄN TEIDÄT SEURAAMAAN MINUA",
	"TEIDÄN TULEE POISTUA RAKENNUKSESTA VELI.",
	"AION VAROITTAA APOTTIA",
	"MESTARI, MENKÄÄMME KIRKKOON",
	"MESTARI, MENKÄÄMME REFEKTORIOON.",
	"VOITTE MENNÄ KAMMIOIHINNE",
	"ETTE OLE KUNNIOITTANUT SÄÄNTÖJÄNI. POISTUKAA TÄSTÄ LUOSTARISTA IÄKSI.",
	"KUUNNELKAA VELJENI, OLEN LÖYTÄNYT KAMMIOSTANI KUMMALLISEN KIRJAN",
	"MENE KAMMIOOSI, VELI WILLIAM",
	"BERNARD ON SAAPUNUT. TEIDÄN TÄYTYY LOPETTAA TUTKIMUKSENNE.",
	"NUKUMMEKO MESTARINI?",
	"MESTARI, MEIDÄN ON LÖYDETTÄVÄ LAMPPU.",
	"VELI WILLIAM, TULKAA TÄNNE",
	"VELJET, VENANTIUS ON MURHATTU.",
	"TIEDÄ, ETTÄ KIRJASTO ON SALATTU PAIKKA JA VAIN MALACHIAS VOI LIIKKUA SIELLÄ. PALATKAA TOIMIINNE.",
	"RUKOILKAAMME",
	"VELJET, BERENGAR ON KADONNUT. PELKÄÄN, ETTÄ ON TAPAHTUNUT UUSI MURHA.",
	"VELJET, SYÖKÄÄMME.",
	"VELJET, BERENGAR ON LÖYDETTY MURHATTUNA.",
	"TULKAA VELI WILLIAM, MEIDÄN ON LÖYDETTÄVÄ SEVERINUS.",
	"JUMALAN TÄHDEN... SEVERINUS ON MURHATTU JA LUKITTU SISÄÄN.",
	"BERNARD JÄTTÄÄ LUOSTARIN TÄNÄÄN.",
	"HUOMENNA TEIDÄN ON LÄHDETTÄVÄ LUOSTARISTA",
	"TOTISESTI, SIINÄ OLI TUHANNEN SKORPIONIN VOIMA.",
	"MALACHIAS ON KUOLLUT.",
	"SINÄKÖ SE OLET, VELI WILLIAM... TULE SISÄÄN, ODOTIN SINUA. OTA TÄMÄ, SE ON PALKKIOSI.",
	"LANKESIT ANSAAN JA KUOLEMA ON OLEVA LOPULLINEN PALKKIOSI VELI WILLIAM.",
	"KUNNIOITETTU JORGE, ETTE VOI NÄHDÄ MESTARINI KÄYTTÄVÄN HANSIKKAITA. EROTTAAKSEEN SIVUT TOISISTAAN HÄNEN TULISI KOSTUTTAA SORMENPÄÄNSÄ KIELELLÄÄN KUNNES KIRJASTA OLISI VÄLITTYNYT TARPEEKSI MYRKKYÄ.",
	"MESTARINI, HÄN SYÖ KIRJAN SIVUJA",
	"TEIDÄN TÄYTYY LÄHTEÄ LUOSTARISTA.",
	"OUTOA VELI WILLIAM. BERENGARILLA OLI TUMMIA LÄIKKIÄ KIELESSÄÄN JA SORMENPÄISSÄÄN.",
	"MESTARINI, AAMU KOITTAA PIAN.",
	"LAMPUN VALO ON HIIPUMASSA.",
	"OLETTE ASTUNUT SISÄLLE KAMMIOONI",
	"LAMPUN TULI ON SAMMUNUT.",
	"EMME TULE IKINÄ PÄÄSEMÄÄN TÄÄLTÄ ULOS.",
	"VELI, ODOTA",
	"VELI WILLIAM, OTTAKAA PAIKKANNE",
	"SE ON ARISTOTELEEN COENA CYPRIANI. NYT YMMÄRRÄTTE MIKSI MINUN PITI SUOJELLA SITÄ. "
	"JOKAINEN TUON FILOSOFIN KIRJOITTAMA SANA ON TUHONNUT KRISTIKUNNAN KERÄÄMÄÄ TIETOA. TIEDÄN TOIMINEENI JUMALAN ARMOSSA. LUE VAIN VELI WILLIAM, SELAILE KIRJAA. OLET ANSAINNUT SEN. NÄYTÄN SEN VIELÄ SINULLEKIN, NOVIISI.",
	"SE OLI HYVÄ IDEA, EIKÖ OLLUTKIN? MUTTA NYT ON LIIAN MYÖHÄISTÄ.",
	"HALUAN TAVATA LUOSTARIN VANHIMMAN JA VIISAIMMAN MIEHEN.",
	"KUNNIOITETTU JORGE, MUNKKI EDESSÄNNE ON VELI WILLIAM, JOKA ON VIERAANAMME.",
	"OLE TERVETULLUT KUNNIOITETTU VELI JA KUUNTELE KERTOMUSTANI. ANTIKRISTUS TOIMII HITAASTI JA KIERTELEMÄLLÄ. HÄN TULEE SILLOIN KUN SITÄ VÄHITEN ODOTAMME. ÄLÄ TUHLAA VIIMEISIÄ PÄIVIÄ ENNEN ANTIKRISTUSTA.",
	"OLEN PAHOILLANI KUNNIOITETTU VELI, MUTTA ETTE VOI MENNÄ KIRJASTOON.",
	"JOS SE ON TAHTONNE, BERENGAR NÄYTTÄÄ TEILLE KIRJOITUSSALIN.",
	"LÄNTISEN MAAILMAN PARHAAT KOPISTIT TYÖSKENTELEVÄT TÄÄLLÄ.",
	"VENANTIUS TYÖSKENTELI TÄÄLLÄ.",
	"KUNNIOITETTU VELI, OLEN SEVERINUS JA VASTUUSSA SAIRASTUVASTA. LUOSTARISSA ON TAPAHTUNUT HYVIN OUTOJA ASIOITA. JOKU EI HALUA MUNKKIEN PÄÄTTÄVÄN ITSE TIEDONJANONSA RAJOISTA.",
	" "
		}, // Fin textos 6 Fines
		{  // 7 Portugues
	"SECRETUM FINIS AFRICAE, MANUS SUPRA AAA IDOLUM AGE PRIMUM ET SEPTIMUM DE QUATUOR",
	"BEM-VINDO A ESTA ABADIA, IRMÃO. ROGO-VOS QUE ME SIGAIS. ACONTECEU ALGO TERRÍVEL.",
	"TEMO QUE UM DOS MONGES TENHA COMETIDO UM CRIME. ROGO-VOS QUE O ENCONTREIS ANTES QUE CHEGUE BERNARDO GUI, POIS NÃO DESEJO QUE SE MANCHE O NOME DESTA ABADIA",
	"DEVEIS RESPEITAR AS MINHAS ORDENS E AS DA ABADIA. ASSISTIR AOS OFÍCIOS E ÀS REFEIÇÕES. DE NOITE DEVEREIS ESTAR NA VOSSA CELA",
	"DEIXAI O MANUSCRITO DE VENÂNCIO OU ADVERTIREI O ABADE",
	"DAI-ME O MANUSCRITO, FREI GUILHERME",
	"CHEGAIS TARDE, FREI GUILHERME",
	"ESTA É A VOSSA CELA. DEVO IR-ME",
	"ORDENO-VOS QUE VENHAIS",
	"DEVEIS ABANDONAR O EDÍFICIO, IRMÃO",
	"ADVERTIREI O ABADE",
	"DEVEMOS IR À IGREJA, MESTRE",
	"DEVEMOS IR AO REFEITÓRIO, MESTRE",
	"PODEIS IR PARA AS VOSSAS CELAS",
	"NÃO HAVEIS RESPEITADO AS MINHAS ORDENS. ABANDONAI PARA SEMPRE ESTA ABADIA.",
	"ESCUTAI IRMÃO, ENCONTREI UM ESTRANHO LIVRO NA MINHA CELA",
	"ENTRAI EM VOSSA CELA, FREI GUILHERME",
	"CHEGOU BERNARDO, DEVEIS ABANDONAR A INVESTIGAÇÃO",
	"DORMIMOS, MESTRE?",
	"DEVEMOS ENCONTRAR UMA LÂMPADA, MESTRE",
	"VINDE AQUI, FREI GUILHERME",
	"IRMÃOS, VENÂNCIO FOI ASSASSINADO.",
	"DEVEIS SABER QUE A BIBLIOTECA É UM LUGAR SECRETO. SÓ MALAQUIAS PODE ENTRAR. PODEIS IR-VOS.",
	"OREMOS",
	"IRMÃOS, BERENGÁRIO DESAPARECEU. TEMO QUE SE HAJA COMETIDO OUTRO CRIME",
	"PODEIS COMER, IRMÃOS",
	"IRMÃOS, ENCONTRARAM BERENGÁRIO ASSASSINADO",
	"VINDE, FREI GUILHERME, DEVEMOS ENCONTRAR SEVERINO",
	"SANTO DEUS... ASSASSINARAM SEVERINO E O HÃO ENCERRADO",
	"BERNARDO ABANDONARÁ HOJE A ABADIA",
	"AMANHÃ, ABANDONAREIS A ABADIA",
	"ERA VERDADE, TINHA O PODER DE MIL ESCORPIÕES",
	"MALAQUIAS ESTÁ MORTO",
	"SOIS VÓS, GUILHERME... PASSAI, ESTAVA-VOS ESPERANDO. TOMAI, AQUI ESTÁ O VOSSO PRÉMIO",
	"ESTAIS MORTO, FREI GUILHERME. HAVEIS CAÍDO NA ARMADILHA.",
	"VENERÁVEL JORGE, VOS NÃO PODEIS VÊ-LO, MAS O MEU MESTRE CALÇA LUVAS. PARA SEPARAR OS FÓLIOS TINHA QUE HUMEDECER OS DEDOS NA LÍNGUA, ATÉ QUE TIVESSE RECEBIDO SUFICIENTE VENENO",
	"ESTÁ A COMER O LIVRO, MESTRE",
	"DEVEIS ABANDONAR A ABADIA",
	"É MUITO ESTRANHO, IRMÃO GUILHERME. BERENGÁRIO TINHA MANCHAS NEGRAS NA LÍNGUA E NOS DEDOS",
	"EM BREVE AMANHECERÁ, MESTRE",
	"A LÂMPADA ESGOTA-SE",
	"HAVEIS ENTRADO NA MINHA CELA",
	"ESGOTOU-SE A LÂMPADA",
	"JAMAIS CONSEGUIREMOS SAIR DAQUI",
	"ESPERAI, IRMÃO",
	"OCUPAI O VOSSO SÍTIO, FREI GUILHERME",
	"É O COENA CIPRIANI DE ARISTÓTELES. AGORA COMPREENDEREIS POR QUE TINHA QUE PROTEGÊ-LO. CADA PALAVRA ESCRITA "
	"PELO FILOSOFO DESTRUIU UMA PARTE DO SABER DA CRISTANDADE. SEI QUE ACTUEI SEGUINDO A VONTADE DO SENHOR... LEDE-O POIS, FREI GUILHERME. DEPOIS MOSTRÁLO-EI A TI RAPAZ.",
	"FOI UMA BOA IDEIA VERDADE?; MAS JÁ É TARDE",
	"QUERO QUE CONHEÇAIS O HOMEM MAIS VELHO E MAIS SÁBIO DA ABADIA",
	"VENERÁVEL JORGE, QUEM ESTÁ ANTE VÓS É FREI GUILHERME, NOSSO HÓSPEDE",
	"SEDE BEM-VINDO, VENERÁVEL IRMÃO; E ESCUTAI O QUE VOS DIGO. AS VIAS DO ANTICRISTO SÃO LENTAS E TORTUOSAS. CHEGA QUANDO MENOS O ESPERAS. NÃO DESPERDICEIS OS ÚLTIMOS DIAS",
	"LAMENTO, VENERÁVEL IRMÃO, NÃO PODEIS SUBIR À BIBLIOTECA",
	"SE O DESEJAIS, BERENGÁRIO MOSTRAR-VOS-Á O SCRIPTORIUM",
	"AQUI TRABALHAM OS MELHORES COPISTAS DO OCIDENTE",
	"AQUI TRABALHAVA VENÂNCIO",
	"VENERÁVEL IRMÃO, SOU SEVERINO, O ENCARREGADO DO HOSPITAL. QUERO ADVERTIR-VOS QUE NESTA ABADIA SUCEDEM COISAS MUITO ESTRANHAS. ALGUÉM NÃO QUER QUE OS MONGES DECIDAM POR SI PRÓPRIOS O QUE DEVEM SABER",
	" "
		}, // Fin textos 7 Portugues
};

/////////////////////////////////////////////////////////////////////////////
// inicialización y limpieza
/////////////////////////////////////////////////////////////////////////////

GestorFrases::GestorFrases()
{
	cpc6128 = elJuego->cpc6128;
	contadorActualizacion = 0;
	reproduciendoFrase = mostrandoFrase = false;
	frasePergamino = frases[0][0]; // 0 castellano
}

GestorFrases::~GestorFrases()
{
}

/////////////////////////////////////////////////////////////////////////////
// métodos para mostrar una frase
/////////////////////////////////////////////////////////////////////////////

// muestra una frase por el marcador siempre y cuando no hubiera otra puesta
void GestorFrases::muestraFrase(int numFrase)
{
	// si ya está reproduciendo una frase, sale
	if (mostrandoFrase){
		return;
	}

	// prepara todo para que se muestre la frase
	dibujaFrase(numFrase);
}

// muestra una frase por el marcador. Si había otra, la para
void GestorFrases::muestraFraseYa(int numFrase)
{
	// para la frase actual
	reproduciendoFrase = mostrandoFrase = false;

	// limpia la parte del marcador donde se muestran las frases 
	elJuego->marcador->limpiaAreaFrases();

	// prepara todo para que se muestre la frase
	dibujaFrase(numFrase);
}

// actualiza el estado de la reproducción de las frases
void GestorFrases::actualizaEstado()
{
	mostrandoFrase = reproduciendoFrase;
}

/////////////////////////////////////////////////////////////////////////////
// dibujo de la frase
/////////////////////////////////////////////////////////////////////////////

// inicia el proceso para mostrar una frase por el marcador 
void GestorFrases::dibujaFrase(int numFrase)
{
	// inicia la frase
	fraseTerminada = false;
	reproduciendoFrase = mostrandoFrase = true;

	// guarda un puntero a la frase que se va a mostrar
	frase = frases[elJuego->idioma][numFrase]; // 1 ingles ... 7 portugues

	// si se va a mostrar la frase del pergamino, cambia el puntero ya que en C++ no se puede modificar un static char *
	if (numFrase == 0){
		frase = (char *)frasePergamino.c_str();
	}

	// indica que aún no se ha terminado la frase
	espaciosParaFin = 0;
}


void GestorFrases::procesaFraseActual()
{
	contadorActualizacion++;

	// sólo actualiza las frases 1 vez cada 45 llamadas
	if (contadorActualizacion != 45){
		return;
	} else {
		contadorActualizacion = 0;
	}

	// si no se está mostrando una frase en el marcador, sale
	if (!reproduciendoFrase){
		return;
	}
	
	// si no se ha terminado la frase actual, muestra otro caracter en el marcador
	if (!fraseTerminada){
//recorrer utf8 sacado de http://www.nubaria.com/en/blog/?p=371
//const unsigned char kFirstBitMask = 128; // 1000000
//const unsigned char kSecondBitMask = 64; // 0100000
//const unsigned char kThirdBitMask = 32; // 0010000
//const unsigned char kFourthBitMask = 16; // 0001000
//const unsigned char kFifthBitMask = 8; // 0000100
		//char32_t codePoint=0; // en la rama abadIA compilamos con -std=c++11 que en uchar.h define char32_t
		//para la rama master de VigasocoSDL usamos los tipos de Vigasoco definidos en core/Types.h
		//y eliminamos dependencias ya que queremos compilar VigasocoSDL en diversos sistemas
		//que igual solo tienen un compilador C++ básico y SDL
		UINT32 codePoint=0;
		char firstByte=*frase;
		std::string::difference_type offset=1; //TODO: esta var se puede ahorrar al ir incrementando mientras se lee cada byte
		if(firstByte&128) { // This means the first byte has a value greater than 127, and so is beyond the ASCII range.
        		if(firstByte & 32) // This means that the first byte has a value greater than 191, and so it must be at least a three-octet code point.
        		{
				if(firstByte & 16) // This means that the first byte has a value greater than 224, and so it must be a four-octet code point.
				{
					codePoint = (firstByte & 0x07) << 18;
					char secondByte = *(frase + 1);
					codePoint +=  (secondByte & 0x3f) << 12;
					char thirdByte = *(frase + 2);
					codePoint +=  (thirdByte & 0x3f) << 6;;
					char fourthByte = *(frase + 3);
					codePoint += (fourthByte & 0x3f);

					offset=4;	
				}
				else
				{
					codePoint = (firstByte & 0x0f) << 12;
					char secondByte = *(frase + 1);
					codePoint += (secondByte & 0x3f) << 6;
					char thirdByte = *(frase + 2);
					codePoint +=  (thirdByte & 0x3f);

					offset=3;	
				}
			}
			else
			{
				codePoint = (firstByte & 0x1f) << 6;
				char secondByte = *(frase + 1);
				codePoint +=  (secondByte & 0x3f);

				offset=2;	
			}
		}
		else
		{
			codePoint = firstByte;
		}
		frase+=offset;
		int caracter = codePoint;
		if (*frase == 0){
			fraseTerminada = true;
			espaciosParaFin = 17;
		}

		// realiza el scroll de la frase que se muestra en el marcador e imprime el nuevo carácter
		scrollFrase();
		// CPC elJuego->marcador->imprimirCaracter(caracter, 216, 164, 2, 3);
		elJuego->marcador->imprimirCaracter(caracter, 216, 164, 4, 0);
	} else if (espaciosParaFin != 0){
		// si la frase se ha terminado y solo se están poniendo espacios para que se borre del marcador
		espaciosParaFin--;

		if (espaciosParaFin != 0){
			// si el marcador está limpiándose, realiza el scroll y muestra espacios en blanco
			scrollFrase();
			// CPC elJuego->marcador->imprimirCaracter(0x20, 216, 164, 2, 3);
			elJuego->marcador->imprimirCaracter(0x20, 216, 164, 4, 0); // VGA
		} else {
			// si llega aquí, la frase ha terminado
			reproduciendoFrase = false;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// métodos de ayuda
/////////////////////////////////////////////////////////////////////////////

void GestorFrases::scrollFrase()
{
	// 8 líneas de alto
	//for (int j = 0; j < 8; j++){
	// con las traducciones hay nuevos caracteres que son de 8x10 en vez de 8x8
	// al tener que pintar el acento encima
	// 10 líneas de alto
	for (int j = -2; j < 8; j++){
		// desplaza 120/8 = 15 caracteres a la izquierda 1 caracter (cada caracter es de 8x8)
		for (int i = 0; i < 120; i++){
			cpc6128->setMode1Pixel(104 + i - 8, 164 + j, cpc6128->getMode1Pixel(104 + i, 164 + j));
		}
	}
}
