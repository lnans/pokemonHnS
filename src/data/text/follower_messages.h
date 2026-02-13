extern const u8 EventScript_FollowerIsShivering[];
extern const u8 EventScript_FollowerNostalgia[];
extern const u8 EventScript_FollowerHopping[];
extern const u8 EventScript_FollowerJumpOnPlayer[];
extern const u8 EventScript_FollowerCuddling[];
extern const u8 EventScript_FollowerShiverCuddling[];
extern const u8 EventScript_FollowerGetCloser[];
extern const u8 EventScript_FollowerPokingPlayer[];
extern const u8 EventScript_FollowerLookAround[];
extern const u8 EventScript_FollowerLookAway[];
extern const u8 EventScript_FollowerLookAwayBark[];
extern const u8 EventScript_FollowerLookAwayPoke[];
extern const u8 EventScript_FollowerPokeGround[];
extern const u8 EventScript_FollowerStartled[];
extern const u8 EventScript_FollowerFastHopping[];
extern const u8 EventScript_FollowerDizzy[];
extern const u8 EventScript_FollowerLookAroundScared[];
extern const u8 EventScript_FollowerDance[];
extern const u8 EventScript_FollowerLookUp[];

// 'Generic', unconditional happy messages
static const u8 sHappyMsg00[] = _("{STR_VAR_1} commence à te donner des\ncoups dans le ventre.");
static const u8 sHappyMsg01[] = _("{STR_VAR_1} est heureux mais timide.");
static const u8 sHappyMsg02[] = _("{STR_VAR_1} te suit joyeusement.");
static const u8 sHappyMsg03[] = _("{STR_VAR_1} reste calme.");
static const u8 sHappyMsg04[] = _("{STR_VAR_1} semble ravi de marcher\navec toi !");
static const u8 sHappyMsg05[] = _("{STR_VAR_1} rayonne de santé.");
static const u8 sHappyMsg06[] = _("{STR_VAR_1} a l'air très heureux.");
static const u8 sHappyMsg07[] = _("{STR_VAR_1} fait de gros efforts.");
static const u8 sHappyMsg08[] = _("{STR_VAR_1} renifle les odeurs\ndans l'air.");
static const u8 sHappyMsg09[] = _("{STR_VAR_1} saute de joie !");
static const u8 sHappyMsg10[] = _("{STR_VAR_1} se sent toujours\nsuper bien !");
static const u8 sHappyMsg11[] = _("Ton POKéMON a senti une odeur de\nfumée.");
static const u8 sHappyMsg12[] = _("{STR_VAR_1} te donne des coups\ndans le ventre.");
static const u8 sHappyMsg13[] = _("Ton POKéMON s'étire et se\nrelaxe.");
static const u8 sHappyMsg14[] = _("{STR_VAR_1} veut mener la marche !");
static const u8 sHappyMsg15[] = _("{STR_VAR_1} fait de son mieux\npour te suivre.");
static const u8 sHappyMsg16[] = _("{STR_VAR_1} se blottit contre toi !");
static const u8 sHappyMsg17[] = _("{STR_VAR_1} déborde d'énergie !");
static const u8 sHappyMsg18[] = _("{STR_VAR_1} semble très heureux !");
static const u8 sHappyMsg19[] = _("{STR_VAR_1} est si heureux qu'il\nne tient pas en place !");
static const u8 sHappyMsg20[] = _("{STR_VAR_1} hoche lentement la tête.");
static const u8 sHappyMsg21[] = _("{STR_VAR_1} est très enthousiaste !");
static const u8 sHappyMsg22[] = _("{STR_VAR_1} se promène et écoute\nles sons autour.");
static const u8 sHappyMsg23[] = _("{STR_VAR_1} semble très intéressé.");
static const u8 sHappyMsg24[] = _("{STR_VAR_1} se force à continuer.");
static const u8 sHappyMsg25[] = _("{STR_VAR_1} te regarde avec joie !");
static const u8 sHappyMsg26[] = _("{STR_VAR_1} te regarde en souriant.");
static const u8 sHappyMsg27[] = _("Ton POKéMON sent l'odeur\ndes fleurs.");
static const u8 sHappyMsg28[] = _("{STR_VAR_1} est très heureux\nde te voir !");
static const u8 sHappyMsg29[] = _("{STR_VAR_1} se tourne vers toi et\nsourit.");
static const u8 sHappyMsg30[] = _("{STR_VAR_1} se blottit joyeusement !");
// Conditional messages begin here, index 31
static const u8 sHappyMsg31[] = _("Ton POKéMON a l'air content du\nbeau temps.");
static const u8 sHappyMsg32[] = _("{STR_VAR_1} est très serein et\nsûr de lui!");

const struct FollowerMsgInfo gFollowerHappyMessages[] = {
    {sHappyMsg00, EventScript_FollowerPokingPlayer},
    {sHappyMsg01}, {sHappyMsg02}, {sHappyMsg03}, {sHappyMsg04}, {sHappyMsg05}, {sHappyMsg06}, {sHappyMsg07},
    {sHappyMsg08, EventScript_FollowerLookAround},
    {sHappyMsg09, EventScript_FollowerHopping},
    {sHappyMsg10}, {sHappyMsg11},
    {sHappyMsg12, EventScript_FollowerPokingPlayer},
    {sHappyMsg13, EventScript_FollowerLookAround},
    {sHappyMsg14}, {sHappyMsg15},
    {sHappyMsg16, EventScript_FollowerCuddling},
    {sHappyMsg17}, {sHappyMsg18},
    {sHappyMsg19, EventScript_FollowerFastHopping},
    {sHappyMsg20}, {sHappyMsg21}, {sHappyMsg22}, {sHappyMsg23}, {sHappyMsg24}, {sHappyMsg25}, {sHappyMsg26}, {sHappyMsg27}, {sHappyMsg28}, {sHappyMsg29},
    {sHappyMsg30, EventScript_FollowerCuddling},
    {sHappyMsg31}, {sHappyMsg32},
};

// Unconditional neutral messages
static const u8 sNeutralMsg00[] = _("{STR_VAR_1} gratte le sol.");
static const u8 sNeutralMsg01[] = _("{STR_VAR_1} monte la garde.");
static const u8 sNeutralMsg02[] = _("{STR_VAR_1} fixe le vide.");
static const u8 sNeutralMsg03[] = _("{STR_VAR_1} se promène.");
static const u8 sNeutralMsg04[] = _("Ton POKéMON bâille fort !");
static const u8 sNeutralMsg05[] = _("Ton POKéMON regarde partout.");
static const u8 sNeutralMsg06[] = _("{STR_VAR_1} te regarde en souriant.");
static const u8 sNeutralMsg07[] = _("{STR_VAR_1} observe autour.");
static const u8 sNeutralMsg08[] = _("{STR_VAR_1} pousse un cri.");
static const u8 sNeutralMsg09[] = _("{STR_VAR_1} danse !");
static const u8 sNeutralMsg10[] = _("{STR_VAR_1} est très motivé.");
static const u8 sNeutralMsg11[] = _("{STR_VAR_1} regarde au loin.");
static const u8 sNeutralMsg12[] = _("{STR_VAR_1} reste vigilant !");
static const u8 sNeutralMsg13[] = _("{STR_VAR_1} regarde au loin et\naboie !");

const struct FollowerMsgInfo gFollowerNeutralMessages[] = {
    {sNeutralMsg00, EventScript_FollowerPokeGround},
    {sNeutralMsg01},
    {sNeutralMsg02, EventScript_FollowerLookAway},
    {sNeutralMsg03, EventScript_FollowerLookAround},
    {sNeutralMsg04},
    {sNeutralMsg05, EventScript_FollowerLookAround},
    {sNeutralMsg06}, {sNeutralMsg07}, {sNeutralMsg08},
    {sNeutralMsg09, EventScript_FollowerDance},
    {sNeutralMsg10},
    {sNeutralMsg11, EventScript_FollowerLookAway},
    {sNeutralMsg12},
    {sNeutralMsg13, EventScript_FollowerLookAwayBark},
};

// Unconditional sad messages
static const u8 sSadMsg00[] = _("{STR_VAR_1} est étourdi.");
static const u8 sSadMsg01[] = _("{STR_VAR_1} marche sur tes pieds !");
static const u8 sSadMsg02[] = _("{STR_VAR_1} semble fatigué.");
// Conditional messages begin, index 3
static const u8 sSadMsg03[] = _("{STR_VAR_1} n'est pas heureux.");
static const u8 sSadMsg04[] = _("{STR_VAR_1} va tomber !");
static const u8 sSadMsg05[] = _("{STR_VAR_1} semble prêt à tomber !");
static const u8 sSadMsg06[] = _("{STR_VAR_1} fait tout pour suivre…");
static const u8 sSadMsg07[] = _("{STR_VAR_1} est nerveux.");

const struct FollowerMsgInfo gFollowerSadMessages[] = {
    {sSadMsg00, EventScript_FollowerDizzy},
    {sSadMsg01}, {sSadMsg02},
    {sSadMsg03}, {sSadMsg04}, {sSadMsg05}, {sSadMsg06}, {sSadMsg07},
};

// Unconditional upset messages
static const u8 sUpsetMsg00[] = _("{STR_VAR_1} a l'air malheureux…");
static const u8 sUpsetMsg01[] = _("{STR_VAR_1} fait une tête\ndésolée.");
static const u8 sUpsetMsg02[] = _("…Ton POKéMON a l'air d'avoir\nun peu froid.");
// Conditional messages, index 3
static const u8 sUpsetMsg03[] = _("{STR_VAR_1} s'abrite dans l'herbe\nà cause de la pluie.");

const struct FollowerMsgInfo gFollowerUpsetMessages[] = {
    {sUpsetMsg00}, {sUpsetMsg01},
    {sUpsetMsg02, EventScript_FollowerIsShivering},
    {sUpsetMsg03},
};

// Unconditional angry messages
static const u8 sAngryMsg00[] = _("{STR_VAR_1} rugit !");
static const u8 sAngryMsg01[] = _("{STR_VAR_1} a l'air en colère !");
static const u8 sAngryMsg02[] = _("{STR_VAR_1} semble énervé.");
static const u8 sAngryMsg03[] = _("Ton POKéMON te tourne le dos.");
static const u8 sAngryMsg04[] = _("{STR_VAR_1} crie.");

const struct FollowerMsgInfo gFollowerAngryMessages[] = {
    {sAngryMsg00}, {sAngryMsg01}, {sAngryMsg02},
    {sAngryMsg03, EventScript_FollowerLookAway},
    {sAngryMsg04},
};

// Unconditional pensive messages
static const u8 sPensiveMsg00[] = _("{STR_VAR_1} regarde le sol\nfixement.");
static const u8 sPensiveMsg01[] = _("{STR_VAR_1} observe les environs.");
static const u8 sPensiveMsg02[] = _("{STR_VAR_1} regarde en bas.");
static const u8 sPensiveMsg03[] = _("{STR_VAR_1} lutte contre le\nsommeil…");
static const u8 sPensiveMsg04[] = _("{STR_VAR_1} a l'air de se\npromener.");
static const u8 sPensiveMsg05[] = _("{STR_VAR_1} regarde autour de lui\ndistraitement.");
static const u8 sPensiveMsg06[] = _("{STR_VAR_1} a bâillé tout fort!");
static const u8 sPensiveMsg07[] = _("{STR_VAR_1} se détend confortablement.");
static const u8 sPensiveMsg08[] = _("{STR_VAR_1} te fixe le visage\nsans bouger.");
static const u8 sPensiveMsg09[] = _("{STR_VAR_1} fixe ton visage\navec attention.");
static const u8 sPensiveMsg10[] = _("{STR_VAR_1} concentre son\nattention sur toi.");
static const u8 sPensiveMsg11[] = _("{STR_VAR_1} fixe le vide.");
static const u8 sPensiveMsg12[] = _("{STR_VAR_1} flaire le sol.");
static const u8 sPensiveMsg13[] = _("Ton POKéMON fixe le vide\navec attention.");
static const u8 sPensiveMsg14[] = _("{STR_VAR_1} s'est concentré d'un\nregard perçant!");
static const u8 sPensiveMsg15[] = _("{STR_VAR_1} se concentre.");
static const u8 sPensiveMsg16[] = _("{STR_VAR_1} s'est tourné vers toi\net a hoché la tête.");
static const u8 sPensiveMsg17[] = _("{STR_VAR_1} a l'air un peu\nnerveux…");
static const u8 sPensiveMsg18[] = _("{STR_VAR_1} regarde tes empreintes.");
static const u8 sPensiveMsg19[] = _("{STR_VAR_1} te regarde droit\ndans les yeux.");

const struct FollowerMsgInfo gFollowerPensiveMessages[] = {
    {sPensiveMsg00},
    {sPensiveMsg01, EventScript_FollowerLookAround},
    {sPensiveMsg02}, {sPensiveMsg03}, {sPensiveMsg04},
    {sPensiveMsg05, EventScript_FollowerLookAround},
    {sPensiveMsg06}, {sPensiveMsg07}, {sPensiveMsg08}, {sPensiveMsg09}, {sPensiveMsg10},
    {sPensiveMsg11, EventScript_FollowerLookAway},
    {sPensiveMsg12, EventScript_FollowerPokeGround},
    {sPensiveMsg13, EventScript_FollowerLookAway},
    {sPensiveMsg14}, {sPensiveMsg15}, {sPensiveMsg16}, {sPensiveMsg17}, {sPensiveMsg18}, {sPensiveMsg19},
};

// All 'love' messages are unconditional
static const u8 sLoveMsg00[] = _("{STR_VAR_1} se rapproche !");
static const u8 sLoveMsg01[] = _("{STR_VAR_1} rougit !");
static const u8 sLoveMsg02[] = _("Oh ! {STR_VAR_1} te fait un câlin !");
static const u8 sLoveMsg03[] = _("Oh ! {STR_VAR_1} devient joueur !");
static const u8 sLoveMsg04[] = _("{STR_VAR_1} se frotte à toi !");
static const u8 sLoveMsg05[] = _("{STR_VAR_1} rougit.");
static const u8 sLoveMsg06[] = _("Ah ! {STR_VAR_1} se blottit !");
static const u8 sLoveMsg07[] = _("{STR_VAR_1} te regarde avec adoration !");
static const u8 sLoveMsg08[] = _("{STR_VAR_1} se rapproche.");
static const u8 sLoveMsg09[] = _("{STR_VAR_1} reste près de tes pieds.");

const struct FollowerMsgInfo gFollowerLoveMessages[] = {
    {sLoveMsg00, EventScript_FollowerGetCloser},
    {sLoveMsg01},
    {sLoveMsg02, EventScript_FollowerCuddling},
    {sLoveMsg03},
    {sLoveMsg04, EventScript_FollowerCuddling},
    {sLoveMsg05},
    {sLoveMsg06, EventScript_FollowerCuddling},
    {sLoveMsg07},
    {sLoveMsg08, EventScript_FollowerGetCloser},
    {sLoveMsg09},
};

// Unconditional surprised messages
static const u8 sSurpriseMsg00[] = _("{STR_VAR_1} est sur le point\nde tomber!");
static const u8 sSurpriseMsg01[] = _("{STR_VAR_1} t'a bousculé!");
static const u8 sSurpriseMsg02[] = _("{STR_VAR_1} ne semble pas encore\nhabitué à son nom.");
static const u8 sSurpriseMsg03[] = _("{STR_VAR_1} regarde en bas.");
static const u8 sSurpriseMsg04[] = _("Ton POKéMON a trébuché et a\nfailli tomber!");
static const u8 sSurpriseMsg05[] = _("{STR_VAR_1} sent quelque chose\net hurle!");
static const u8 sSurpriseMsg06[] = _("{STR_VAR_1} a l'air rafraîchi!");
static const u8 sSurpriseMsg07[] = _("{STR_VAR_1} s'est soudain retourné\net s'est mis à aboyer!");
static const u8 sSurpriseMsg08[] = _("{STR_VAR_1} s'est soudain retourné!");
static const u8 sSurpriseMsg09[] = _("Ton POKéMON a été surpris que tu\nlui parles tout à coup!");
static const u8 sSurpriseMsg10[] = _("Sniff, Sniff, ça sent vraiment\nbon par ici!");
static const u8 sSurpriseMsg11[] = _("{STR_VAR_1} se sent rafraîchi.");
static const u8 sSurpriseMsg12[] = _("{STR_VAR_1} titube et a l'air\nsur le point de tomber.");
static const u8 sSurpriseMsg13[] = _("{STR_VAR_1} est sur le point\nde tomber.");
static const u8 sSurpriseMsg14[] = _("{STR_VAR_1} avance avec\nprudence.");
static const u8 sSurpriseMsg15[] = _("{STR_VAR_1} se tend sous l'effet\nde la nervosité.");
static const u8 sSurpriseMsg16[] = _("{STR_VAR_1} a senti quelque chose\nd'étrange et s'est surpris!");
static const u8 sSurpriseMsg17[] = _("{STR_VAR_1} a peur et s'est\nblotti contre toi!");
static const u8 sSurpriseMsg18[] = _("{STR_VAR_1} sent une présence\ninhabituelle…");
static const u8 sSurpriseMsg19[] = _("{STR_VAR_1} se tend sous l'effet\nde la nervosité.");
// Conditional messages, index 20
static const u8 sSurpriseMsg20[] = _("{STR_VAR_1} a l'air très surpris\nqu'il pleuve!");

const struct FollowerMsgInfo gFollowerSurpriseMessages[] = {
    {sSurpriseMsg00},
    {sSurpriseMsg01, EventScript_FollowerPokingPlayer},
    {sSurpriseMsg02}, {sSurpriseMsg03}, {sSurpriseMsg04}, {sSurpriseMsg05}, {sSurpriseMsg06},
    {sSurpriseMsg07, EventScript_FollowerLookAwayBark},
    {sSurpriseMsg08, EventScript_FollowerLookAway},
    {sSurpriseMsg09},
    {sSurpriseMsg10, EventScript_FollowerLookAround},
    {sSurpriseMsg11}, {sSurpriseMsg12}, {sSurpriseMsg13}, {sSurpriseMsg14}, {sSurpriseMsg15}, {sSurpriseMsg16},
    {sSurpriseMsg17, EventScript_FollowerCuddling},
    {sSurpriseMsg18},
    {sSurpriseMsg19, EventScript_FollowerLookAround},
    {sSurpriseMsg20},
};

// Unconditional curious messages
static const u8 sCuriousMsg00[] = _("Ton POKéMON regarde partout\ncomme s'il cherchait quelque chose.");
static const u8 sCuriousMsg01[] = _("Ton POKéMON ne regardait pas où\nil allait et t'a bousculé!");
static const u8 sCuriousMsg02[] = _("Sniff, Sniff! Il y a quelque chose\npar ici?");
static const u8 sCuriousMsg03[] = _("{STR_VAR_1} fait rouler un caillou\nen jouant.");
static const u8 sCuriousMsg04[] = _("{STR_VAR_1} se promène et cherche\nquelque chose.");
static const u8 sCuriousMsg05[] = _("{STR_VAR_1} te flaire.");
static const u8 sCuriousMsg06[] = _("{STR_VAR_1} a l'air un peu\nhésitant…");

const struct FollowerMsgInfo gFollowerCuriousMessages[] = {
    {sCuriousMsg00, EventScript_FollowerLookAround},
    {sCuriousMsg01, EventScript_FollowerPokingPlayer},
    {sCuriousMsg02}, {sCuriousMsg03},
    {sCuriousMsg04, EventScript_FollowerLookAround},
    {sCuriousMsg05}, {sCuriousMsg06},
};

// Unconditional music messages
static const u8 sMusicMsg00[] = _("{STR_VAR_1} fait étalage de son\nagilité!");
static const u8 sMusicMsg01[] = _("{STR_VAR_1} se déplace avec\njoie!");
static const u8 sMusicMsg02[] = _("Oh! {STR_VAR_1} s'est soudain mis à\ndanser de joie!");
static const u8 sMusicMsg03[] = _("{STR_VAR_1} te suit sans\nproblème!");
static const u8 sMusicMsg04[] = _("{STR_VAR_1} a l'air de vouloir\njouer avec toi.");
static const u8 sMusicMsg05[] = _("{STR_VAR_1} sautille joyeusement.");
static const u8 sMusicMsg06[] = _("{STR_VAR_1} chante et fredonne.");
static const u8 sMusicMsg07[] = _("{STR_VAR_1} te mordille les pieds!");
static const u8 sMusicMsg08[] = _("{STR_VAR_1} se retourne et te\nregarde.");
static const u8 sMusicMsg09[] = _("{STR_VAR_1} fait des efforts pour\nmontrer sa force!");
static const u8 sMusicMsg10[] = _("Oh! {STR_VAR_1} a soudain dansé\nde joie!");
static const u8 sMusicMsg11[] = _("{STR_VAR_1} est de bonne humeur!");
static const u8 sMusicMsg12[] = _("{STR_VAR_1} sautille sans souci!");
static const u8 sMusicMsg13[] = _("Ton POKéMON semble sentir une\nodeur nostalgique…");
// Conditional music messages, index 14
static const u8 sMusicMsg14[] = _("{STR_VAR_1} est très content\nqu'il pleuve.");

const struct FollowerMsgInfo gFollowerMusicMessages[] = {
    {sMusicMsg00, EventScript_FollowerLookAround},
    {sMusicMsg01},
    {sMusicMsg02, EventScript_FollowerDance},
    {sMusicMsg03},
    {sMusicMsg04, EventScript_FollowerHopping},
    {sMusicMsg05, EventScript_FollowerHopping},
    {sMusicMsg06}, {sMusicMsg07}, {sMusicMsg08}, {sMusicMsg09},
    {sMusicMsg10, EventScript_FollowerDance},
    {sMusicMsg11},
    {sMusicMsg12, EventScript_FollowerHopping},
    {sMusicMsg13, EventScript_FollowerNostalgia},
    {sMusicMsg14}
};


static const u8 sPoisonedMsg00[] = _("{STR_VAR_1} tremble à cause du\npoison.");

const struct FollowerMsgInfo gFollowerPoisonedMessages[] = {
    {sPoisonedMsg00, EventScript_FollowerIsShivering},
};
