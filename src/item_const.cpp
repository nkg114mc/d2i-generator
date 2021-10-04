#include <cctype>
#include <string>
#include <iostream>

#include "items.h"

using std::string;




/*
// Armor
const string AlphaHelm = "dr6";

	AncientArmor      string = "aar"
	Antlers           string = "dr3"
	ArchonPlate       string = "utp"
	Armet             string = "ulm"
	AssaultHelmet     string = "ba4"
	AvengerGuard      string = "ba5"
	BalrogSkin        string = "upl"
	Basinet           string = "xhl"
	BattleBelt        string = "ztb"
	BattleBoots       string = "xtb"
	BattleGauntlets   string = "xtg"
	Belt              string = "mbl"
	BloodSpirit       string = "drb"
	BoneHelm          string = "bhm"
	BoneVisage        string = "uh9"
	Boneweave         string = "uhn"
	BoneweaveBoots    string = "umb"
	Bracers           string = "mgl"
	BrambleMitts      string = "ulg"
	BreastPlate       string = "brs"
	Cap               string = "cap"
	CarnageHelm       string = "bab"
	Casque            string = "xlm"
	ChainBoots        string = "mbt"
	ChainMail         string = "chn"
	ChaosArmor        string = "xul"
	Circlet           string = "ci0"
	ColossusGirdle    string = "uhc"
	ConquerorCrown    string = "bae"
	Corona            string = "urn"
	Coronet           string = "ci1"
	Crown             string = "crn"
	CrusaderGauntlets string = "utg"
	Cuirass           string = "xrs"
	DeathMask         string = "xsk"
	Demonhead         string = "usk"
	DemonhideArmor    string = "xla"
	DemonhideBoots    string = "xlb"
	DemonhideGloves   string = "xlg"
	DemonhideSash     string = "zlb"
	DestroyerHelm     string = "bad"
	Diadem            string = "ci3"
	DiamondMail       string = "ung"
	DreamSpirit       string = "drf"
	DuskShroud        string = "uui"
	EarthSpirit       string = "drd"
	EmbossedPlate     string = "xth"
	FalconMask        string = "dr4"
	FangedHelm        string = "ba2"
	FieldPlate        string = "fld"
	FullHelm          string = "fhl"
	PlateMail         string = "plt"
	FullPlateMail     string = "ful"
	FuryVisor         string = "bac"
	Gauntlets         string = "hgl"
	GhostArmor        string = "xui"
	GiantConch        string = "uhl"
	Girdle            string = "hbl"
	Gloves            string = "lgl"
	GothicPlate       string = "gth"
	GrandCrown        string = "xrn"
	GreatHauberk      string = "urs"
	GreatHelm         string = "ghm"
	GriffonHeadress   string = "dr7"
	GrimHelm          string = "xh9"
	GuardianCrown     string = "baf"
	HardLeatherArmor  string = "hla"
	HawkHelm          string = "dr2"
	HeavyBelt         string = "tbl"
	HeavyBoots        string = "vbt"
	HeavyBracers      string = "xmg"
	HeavyGloves       string = "vgl"
	HellforgedPlate   string = "ult"
	Helm              string = "hlm"
	HornedHelm        string = "ba3"
	HuntersGuise      string = "dr8"
	Hydraskull        string = "ukp"
	Hyperion          string = "urg"
	JawboneCap        string = "ba1"
	JawboneVisor      string = "ba6"
	KrakenShell       string = "uld"
	LacqueredPlate    string = "uth"
	LeatherArmor      string = "lea"
	LeatherBoots      string = "lbt"
	LightBelt         string = "vbl"
	LightGauntlets    string = "tgl"
	LightPlate        string = "ltp"
	LightPlatedBoots  string = "tbt"
	LinkedMail        string = "xng"
	LionHelm          string = "ba7"
	LoricatedMail     string = "ucl"
	MagePlate         string = "xtp"
	Mask              string = "msk"
	MeshArmor         string = "xhn"
	MeshBelt          string = "zmb"
	MeshBoots         string = "xmb"
	MirroredBoots     string = "utb"
	MithrilCoil       string = "umc"
	MyrmidonGreaves   string = "uhb"
	OgreGauntlets     string = "uhg"
	OrnatePlate       string = "xar"
	PlateBoots        string = "hbt"
	QuiltedArmor      string = "qui"
	RageMask          string = "ba8"
	RingMail          string = "rng"
	RussetArmor       string = "xpl"
	SacredArmor       string = "uar"
	SacredFeathers    string = "dr9"
	Sallet            string = "xkp"
	Sash              string = "lbl"
	SavageHelmet      string = "ba9"
	ScaleMail         string = "scl"
	ScarabHusk        string = "ula"
	ScarabshellBoots  string = "uvb"
	SerpentskinArmor  string = "xea"
	ShadowPlate       string = "uul"
	Shako             string = "uap"
	SharkskinBelt     string = "zvb"
	SharkskinBoots    string = "xvb"
	SharkskinGloves   string = "xvg"
	SharktoothArmor   string = "xld"
	SkullCap          string = "skp"
	SkySpirit         string = "dre"
	SlayerGuard       string = "baa"
	SpiderwebSash     string = "ulc"
	SpiredHelm        string = "uhm"
	SpiritMask        string = "dr5"
	SplintMail        string = "spl"
	StuddedLeather    string = "stu"
	SunSpirit         string = "drc"
	TemplarCoat       string = "xlt"
	Tiara             string = "ci2"
	TigulatedMail     string = "xcl"
	TotemicMask       string = "dra"
	TrellisedArmor    string = "xtu"
	TrollBelt         string = "utc"
	Vambraces         string = "umg"
	VampireboneGloves string = "uvg"
	VampirefangBelt   string = "uvc"
	WarBelt           string = "zhb"
	WarBoots          string = "xhb"
	WarGauntlets      string = "xhg"
	WarHat            string = "xap"
	WingedHelm        string = "xhm"
	WireFleece        string = "utu"
	WolfHead          string = "dr1"
	Wyrmhide          string = "uea"
	WyrmhideBoots     string = "ulb"

	// Misc
	Amethyst                      string = "gsv"
	AmnRune                       string = "r11"
	Amulet                        string = "amu"
	AntidotePotion                string = "yps"
	Arrows                        string = "aqv"
	BaalsEye                      string = "bey"
	BarkScroll                    string = "bks"
	BerRune                       string = "r30"
	Bolts                         string = "cqv"
	BookofSkill                   string = "ass"
	BurningEssenceofTerror        string = "bet"
	ChamRune                      string = "r32"
	ChargedEssenceofHatred        string = "ceh"
	GrandCharm                    string = "cm3"
	LargeCharm                    string = "cm2"
	SmallCharm                    string = "cm1"
	ChippedAmethyst               string = "gcv"
	ChippedDiamond                string = "gcw"
	ChippedEmerald                string = "gcg"
	ChippedRuby                   string = "gcr"
	ChippedSapphire               string = "gcb"
	ChippedSkull                  string = "skc"
	ChippedTopaz                  string = "gcy"
	DecipheredBarkScroll          string = "bkd"
	DiablosHorn                   string = "dhn"
	Diamond                       string = "gsw"
	DolRune                       string = "r14"
	ElRune                        string = "r01"
	EldRune                       string = "r02"
	Elixir                        string = "elx"
	Emerald                       string = "gsg"
	EthRune                       string = "r05"
	FalRune                       string = "r19"
	FesteringEssenceofDestruction string = "fed"
	FlawedAmethyst                string = "gfv"
	FlawedDiamond                 string = "gfw"
	FlawedEmerald                 string = "gfg"
	FlawedRuby                    string = "gfr"
	FlawedSapphire                string = "gfb"
	FlawedSkull                   string = "skf"
	FlawedTopaz                   string = "gfy"
	FlawlessAmethyst              string = "gzv"
	FlawlessDiamond               string = "glw"
	FlawlessEmerald               string = "glg"
	FlawlessRuby                  string = "glr"
	FlawlessSapphire              string = "glb"
	FlawlessSkull                 string = "skl"
	FlawlessTopaz                 string = "gly"
	FullHealingPotion             string = "hpf"
	FullManaPotion                string = "mpf"
	FullRejuvenationPotion        string = "rvl"
	Gold                          string = "gld"
	GoldBird                      string = "g34"
	GreaterHealingPotion          string = "hp5"
	GreaterManaPotion             string = "mp5"
	GulRune                       string = "r25"
	HealingPotion                 string = "hp3"
	HealingPotionMid              string = "hpo"
	HelRune                       string = "r15"
	Herb                          string = "hrb"
	HoradricCube                  string = "box"
	IdentifyBook                  string = "ibk"
	IdentifyScroll                string = "isc"
	IoRune                        string = "r16"
	IstRune                       string = "r24"
	IthRune                       string = "r06"
	JadeFigurine                  string = "j34"
	JahRune                       string = "r31"
	Jewel                         string = "jew"
	KeyofDestruction              string = "pk3"
	KeyofHate                     string = "pk2"
	KeyofTerror                   string = "pk1"
	KhalimsBrain                  string = "qbr"
	KhalimsEye                    string = "qey"
	KhalimsHeart                  string = "qhr"
	KoRune                        string = "r18"
	LamEsensTome                  string = "bbb"
	LargeBluePotion               string = "bpl"
	LargeRedPotion                string = "rpl"
	LemRune                       string = "r20"
	LesserHealingPotion           string = "hp1"
	LesserManaPotion              string = "mp1"
	LightHealingPotion            string = "hp2"
	LightManaPotion               string = "mp2"
	LoRune                        string = "r28"
	LumRune                       string = "r17"
	Maguffin                      string = "ice"
	MalRune                       string = "r23"
	ManaPotion                    string = "mp3"
	ManaPotionMid                 string = "mpo"
	MephistosBrain                string = "mbr"
	MephistoKey                   string = "luv"
	MephistoSoulStone             string = "mss"
	NefRune                       string = "r04"
	OhmRune                       string = "r27"
	OrtRune                       string = "r09"
	PerfectAmethyst               string = "gpv"
	PerfectDiamond                string = "gpw"
	PerfectEmerald                string = "gpg"
	PerfectRuby                   string = "gpr"
	PerfectSapphire               string = "gpb"
	PerfectSkull                  string = "skz"
	PerfectTopaz                  string = "gpy"
	PlayerEar                     string = "ear"
	PulRune                       string = "r21"
	RalRune                       string = "r08"
	RejuvenationPotion            string = "rvs"
	Ring                          string = "rin"
	Ruby                          string = "gsr"
	Sapphire                      string = "gsb"
	Scroll                        string = "0sc"
	ScrollofHoradric              string = "tr1"
	ScrollofMalah                 string = "tr2"
	PotionofLife                  string = "xyz"
	ShaelRune                     string = "r13"
	SkeletonKey                   string = "key"
	Skull                         string = "sku"
	SmallBluePotion               string = "bps"
	SmallRedPotion                string = "rps"
	SolRune                       string = "r12"
	StaminaPotion                 string = "vps"
	StandardofHeroes              string = "std"
	StrongHealingPotion           string = "hp4"
	StrongManaPotion              string = "mp4"
	SurRune                       string = "r29"
	TalRune                       string = "r07"
	ThawingPotion                 string = "wms"
	ThulRune                      string = "r10"
	TirRune                       string = "r03"
	TokenofAbsolution             string = "toa"
	Topaz                         string = "gsy"
	Torch                         string = "tch"
	TownPortalBook                string = "tbk"
	TownPortalScroll              string = "tsc"
	TwistedEssenceofSuffering     string = "tes"
	UmRune                        string = "r22"
	VexRune                       string = "r26"
	ViperAmulet                   string = "vip"
	ZodRune                       string = "r33"

	// Shields
	Aegis            string = "uow"
	AerinShield      string = "pa4"
	AkaranRondache   string = "pa7"
	AkaranTarge      string = "pa6"
	KurastShield     string = "pad"
	AncientShield    string = "xts"
	BarbedShield     string = "xpk"
	BladeBarrier     string = "upk"
	BloodlordSkull   string = "nef"
	BoneShield       string = "bsh"
	Buckler          string = "buc"
	CantorTrophy     string = "ne9"
	CrownShield      string = "pa5"
	Defender         string = "xuc"
	DemonHead        string = "ne5"
	DragonShield     string = "xit"
	FetishTrophy     string = "ne7"
	GargoyleHead     string = "ne4"
	GothicShield     string = "gts"
	GrimShield       string = "xsh"
	GildedShield     string = "pa9"
	HeirophantTrophy string = "nea"
	Heater           string = "uuc"
	HellspawnSkull   string = "neg"
	HeraldicShield   string = "pa3"
	KiteShield       string = "kit"
	LargeShield      string = "lrg"
	Luna             string = "uml"
	MinionSkull      string = "neb"
	Monarch          string = "uit"
	MummifiedTrophy  string = "ne6"
	OverseerSkull    string = "ned"
	Pavise           string = "xow"
	PreservedHead    string = "ne1"
	ProtectorShield  string = "pa8"
	Rondache         string = "pa2"
	RoundShield      string = "xml"
	RoyalShield      string = "paa"
	SacredRondache   string = "pac"
	SacredTarge      string = "pab"
	Scutum           string = "xrg"
	SextonTrophy     string = "ne8"
	SmallShield      string = "sml"
	SpikedShield     string = "spk"
	SuccubusSkull    string = "nee"
	Targe            string = "pa1"
	TowerShield      string = "tow"
	TrollNest        string = "ush"
	UnravellerHead   string = "ne3"
	VortexShield     string = "paf"
	Ward             string = "uts"
	ZakarumShield    string = "pae"
	ZombieHead       string = "ne2"

	// Weapons
	AncientAxe          string = "9gi"
	AncientSword        string = "9wd"
	Arbalest            string = "8lx"
	ArchonStaff         string = "6ws"
	AshwoodBow          string = "am6"
	Ataghan             string = "7sm"
	Axe                 string = "axe"
	BalancedAxe         string = "bal"
	BalancedKnife       string = "bkf"
	Balista             string = "8hx"
	BalrogBlade         string = "7gs"
	BalrogSpear         string = "7s7"
	BarbedClub          string = "9sp"
	Bardiche            string = "bar"
	BastardSword        string = "bsw"
	BattleAxe           string = "btx"
	BattleCestus        string = "7cs"
	BattleDart          string = "9tk"
	BattleHammer        string = "9wh"
	BattleScythe        string = "9s8"
	BattleStaff         string = "bst"
	BattleSword         string = "9bs"
	BeardedAxe          string = "9ba"
	BecDeCorbin         string = "9h9"
	BerserkerAxe        string = "7wa"
	Bill                string = "9vo"
	Blade               string = "bld"
	BladeBow            string = "6hb"
	BladeTalons         string = "btl"
	BoneKnife           string = "7dg"
	BoneWand            string = "bwn"
	Brandistock         string = "brn"
	BroadAxe            string = "bax"
	BroadSword          string = "bsd"
	BurntWand           string = "9wn"
	Caduceus            string = "7ws"
	CedarBow            string = "8lb"
	CedarStaff          string = "8cs"
	CeremonialBow       string = "am7"
	CeremonialJavelin   string = "ama"
	CeremonialPike      string = "am9"
	CeremonialSpear     string = "am8"
	Cestus              string = "ces"
	ChampionAxe         string = "7ga"
	ChampionSword       string = "7b7"
	ChokingGasPotion    string = "gpm"
	ChuKoNu             string = "8rx"
	Cinquedeas          string = "9kr"
	ClaspedOrb          string = "ob4"
	Claws               string = "clw"
	Claymore            string = "clm"
	Cleaver             string = "9ax"
	CloudySphere        string = "ob8"
	Club                string = "clb"
	ColossalSword       string = "7fb"
	ColossalBlade       string = "7gd"
	ColossusCrossbow    string = "6hx"
	ColossusVoulge      string = "7vo"
	CompositeBow        string = "cbw"
	ConquestSword       string = "7bs"
	Crossbow            string = "mxb"
	Crowbill            string = "9mp"
	CrusaderBow         string = "6l7"
	CrypticAxe          string = "7pa"
	CrypticSword        string = "7ls"
	CrystalSword        string = "crs"
	CrystallineGlobe    string = "ob7"
	Cudgel              string = "9cl"
	Cutlass             string = "9sm"
	DacianFalx          string = "9cm"
	Dagger              string = "dgr"
	Decapitator         string = "7bt"
	DecoyDagger         string = "d33"
	DemonCrossbow       string = "6rx"
	DemonHeart          string = "obd"
	DevilStar           string = "7mt"
	DiamondBow          string = "6s7"
	DimensionalBlade    string = "9cr"
	DimensionalShard    string = "obf"
	Dirk                string = "dir"
	DivineScepter       string = "9ws"
	DoubleAxe           string = "2ax"
	DoubleBow           string = "8cb"
	DragonStone         string = "ob5"
	EableOrb            string = "ob1"
	EdgeBow             string = "8sb"
	ElderStaff          string = "6cs"
	EldritchOrb         string = "obc"
	ElegantBlade        string = "7sb"
	Espadon             string = "92h"
	EttinAxe            string = "72a"
	ExecutionerSword    string = "9gd"
	ExplodingPotion     string = "opm"
	Falcata             string = "7ss"
	Falchion            string = "flc"
	FangedKnife         string = "7kr"
	Fascia              string = "9xf"
	FeralAxe            string = "7la"
	FeralClaws          string = "7lw"
	Flail               string = "fla"
	Flamberge           string = "flb"
	FlangedMace         string = "9ma"
	FlyingAxe           string = "7ta"
	FlyingKnife         string = "7tk"
	Francisca           string = "9ta"
	FulmatingPotion     string = "opl"
	Fuscina             string = "9tr"
	GhostGlaive         string = "7gl"
	GhostSpear          string = "7st"
	GhostWand           string = "7yw"
	GiantAxe            string = "gix"
	GiantSword          string = "gis"
	GiantThresher       string = "7wc"
	Gidbinn             string = "g33"
	Gladius             string = "9ss"
	Glaive              string = "glv"
	GloriousAxe         string = "7gi"
	GlowingOrb          string = "ob6"
	GnarledStaff        string = "cst"
	GorgonCrossbow      string = "6mx"
	GothicAxe           string = "9ga"
	GothicBow           string = "8lw"
	GothicStaff         string = "8bs"
	GothicSword         string = "9b9"
	GrandMatronBow      string = "amc"
	GrandScepter        string = "gsc"
	GraveWand           string = "9gw"
	GreatAxe            string = "gax"
	GreatBow            string = "6cb"
	GreatMaul           string = "gma"
	GreatPilum          string = "9pi"
	GreatPoleaxe        string = "7h7"
	GreatSword          string = "gsd"
	GreaterClaws        string = "9lw"
	GreaterTalons       string = "9tw"
	GrimScythe          string = "9wc"
	GrimWand            string = "gwn"
	Halberd             string = "hal"
	HandAxe             string = "hax"
	HandScythe          string = "9cs"
	Harpoon             string = "9ts"
	Hatchet             string = "9ha"
	HatchetHands        string = "axf"
	HeavenlyStone       string = "obb"
	HeavyCrossbow       string = "hxb"
	HellforgeHammer     string = "hfh"
	HighlandBlade       string = "7cm"
	HolyWaterSprinkler  string = "9qs"
	HoradricMalus       string = "hdm"
	HoradricStaff       string = "hst"
	HuntersBow          string = "hbw"
	Hurlbat             string = "9b8"
	HydraBow            string = "6lw"
	HydraEdge           string = "7fc"
	HyperionJavelin     string = "7ja"
	HyperionSpear       string = "7sr"
	JaggedStar          string = "9mt"
	Javelin             string = "jav"
	JoStaff             string = "8ss"
	Katar               string = "ktr"
	KhalimFlail         string = "qf1"
	Knout               string = "9fl"
	Kriss               string = "kri"
	Lance               string = "9p9"
	LargeAxe            string = "lax"
	LegendSpike         string = "7bl"
	LegendSword         string = "72h"
	LegendaryMallet     string = "7wh"
	LichWand            string = "7bw"
	LightCrossbow       string = "lxb"
	LochaberAxe         string = "9b7"
	LongBattleBow       string = "lbb"
	LongBow             string = "lbw"
	LongSiegeBow        string = "8l8"
	LongStaff           string = "lst"
	LongSword           string = "lsd"
	LongWarBow          string = "lwb"
	Mace                string = "mac"
	MaidenJavelin       string = "am5"
	MaidenPike          string = "am4"
	MaidenSpear         string = "am3"
	Mancatcher          string = "7br"
	MarteldeFer         string = "9gm"
	MatriarchalBow      string = "amb"
	MatriarchalPike     string = "ame"
	MatriarchalSpear    string = "amd"
	MatriarchalJavelin  string = "amf"
	Maul                string = "mau"
	MightyScepter       string = "7sc"
	MilitaryAxe         string = "9la"
	MilitaryPick        string = "mpi"
	MithralPoint        string = "7di"
	MorningStar         string = "mst"
	MythicalSword       string = "7wd"
	Naga                string = "9wa"
	OgreAxe             string = "7o7"
	OgreMaul            string = "7m7"
	OilPotion           string = "ops"
	Partizan            string = "9pa"
	PelletBow           string = "6lx"
	PetrifiedWand       string = "9yw"
	PhaseBlade          string = "7cr"
	Pike                string = "pik"
	Pilum               string = "pil"
	Poignard            string = "9dg"
	Poleaxe             string = "pax"
	PolishedWand        string = "7wn"
	QuarterStaff        string = "8ls"
	Quhab               string = "9ar"
	RancidGasPotion     string = "gps"
	RazorBow            string = "8hb"
	ReflexBow           string = "am2"
	ReinforcedMace      string = "7ma"
	RepeatingCrossbow   string = "rxb"
	Rondel              string = "9di"
	RuneBow             string = "8sw"
	RuneScepter         string = "9sc"
	RuneStaff           string = "8ws"
	RuneSword           string = "9ls"
	RunicTalons         string = "7tw"
	Sabre               string = "sbr"
	SacredGlobe         string = "ob2"
	Scepter             string = "scp"
	Scimitar            string = "scm"
	ScissorsKatar       string = "skr"
	ScissorsQuhab       string = "9qr"
	ScissorsSuwayyah    string = "7qr"
	Scourge             string = "7fl"
	Scythe              string = "scy"
	SeraphRod           string = "7qs"
	ShadowBow           string = "6lb"
	Shamshir            string = "9sb"
	Shillelah           string = "6bs"
	ShortBattleBow      string = "sbb"
	ShortBow            string = "sbw"
	ShortSiegeBow       string = "8s8"
	ShortSpear          string = "ssp"
	ShortStaff          string = "sst"
	ShortSword          string = "ssd"
	ShortWarBow         string = "swb"
	SiegeCrossbow       string = "8mx"
	SilverEdgedAxe      string = "7ba"
	Simbilan            string = "9s9"
	SmallCrescent       string = "7ax"
	SmokedSphere        string = "ob3"
	SparklingBall       string = "ob9"
	Spear               string = "spr"
	Spetum              string = "spt"
	Spiculum            string = "9gl"
	SpiderBow           string = "6sb"
	SpikedClub          string = "spc"
	StaffOfTheKings     string = "msf"
	StagBow             string = "am1"
	Stalagmite          string = "6ls"
	Stilleto            string = "9bl"
	StranglingGasPotion string = "gpl"
	StygianPike         string = "7tr"
	StygianPilum        string = "7pi"
	SuperKhalimFlail    string = "qf2"
	Suwayyah            string = "7ar"
	SwirlingCrystal     string = "oba"
	Tabar               string = "9bt"
	Thresher            string = "7s8"
	ThrowingAxe         string = "tax"
	ThrowingKnife       string = "tkf"
	ThrowingSpear       string = "tsp"
	ThunderMaul         string = "7gm"
	Tomahawk            string = "7ha"
	TombWand            string = "9bw"
	Trident             string = "tri"
	Truncheon           string = "7cl"
	Tulwar              string = "9fc"
	TuskSword           string = "9gs"
	TwinAxe             string = "92a"
	TwoHandedSword      string = "2hs"
	TyrantClub          string = "7sp"
	UnearthedWand       string = "7gw"
	VortexOrb           string = "obe"
	Voulge              string = "vou"
	WalkingStick        string = "6ss"
	Wand                string = "wnd"
	WarAxe              string = "wax"
	WarClub             string = "9m9"
	WarDart             string = "9bk"
	WarFist             string = "7xf"
	WarFork             string = "9br"
	WarHammer           string = "whm"
	WarJavelin          string = "9ja"
	WarPike             string = "7p7"
	WarScepter          string = "wsp"
	WarScythe           string = "wsc"
	WarSpear            string = "9sr"
	WarSpike            string = "7mp"
	WarStaff            string = "wst"
	WarSword            string = "wsd"
	WardBow             string = "6sw"
	WingedAxe           string = "7b8"
	WingedHarpoon       string = "7ts"
	WingedKnife         string = "7bk"
	WirtsLeg            string = "leg"
	WristBlade          string = "wrb"
	WristSpike          string = "9wb"
	WristSword          string = "7wb"
	Yari                string = "9st"
	YewWand             string = "ywn"
	Zweihander          string = "9fb"
)



// All item types that contain the quantity bits will exist in here,
// we'll use this when reading items to make sure we only read quantity bits
// when they exist, or we'll ruin the rest of the bit offsets for the item.
var quantityMap = map[string]bool{
	//Misc
	TownPortalBook:      true,
	IdentifyBook:        true,
	SkeletonKey:         true,
	RancidGasPotion:     true,
	OilPotion:           true,
	ChokingGasPotion:    true,
	ExplodingPotion:     true,
	StranglingGasPotion: true,
	FulmatingPotion:     true,
	Arrows:              true,
	Bolts:               true,

	//Throwables
	ThrowingKnife: true,
	ThrowingAxe:   true,
	BalancedKnife: true,
	BalancedAxe:   true,
	BattleDart:    true,
	Francisca:     true,
	WarDart:       true,
	Hurlbat:       true,
	FlyingKnife:   true,
	FlyingAxe:     true,
	WingedKnife:   true,
	WingedAxe:     true,

	//Javelins
	Javelin:            true,
	Pilum:              true,
	ShortSpear:         true,
	Glaive:             true,
	ThrowingSpear:      true,
	WarJavelin:         true,
	GreatPilum:         true,
	Simbilan:           true,
	Spiculum:           true,
	Harpoon:            true,
	HyperionJavelin:    true,
	StygianPilum:       true,
	BalrogSpear:        true,
	GhostGlaive:        true,
	WingedHarpoon:      true,
	MaidenJavelin:      true,
	CeremonialJavelin:  true,
	MatriarchalJavelin: true,
}

// Items that are tomes contain 5 extra bits, so we need to keep track of what
// items are tomes, and read the bits accordingly.
var tomeMap = map[string]bool{
	TownPortalBook: true,
	IdentifyBook:   true,
}

// Shield item codes mapped to their in game, human-friendly, readable name.
var shieldCodes = map[string]string{
	Aegis:            "Aegis",
	AerinShield:      "Aerin Shield",
	AkaranRondache:   "Akaran Rondache",
	AkaranTarge:      "Akaran Targe",
	KurastShield:     "Kurast Shield",
	AncientShield:    "Ancient Shield",
	BarbedShield:     "Barbed Shield",
	BladeBarrier:     "Blade Barrier",
	BloodlordSkull:   "Bloodlord Skull",
	BoneShield:       "Bone Shield",
	Buckler:          "Buckler",
	CantorTrophy:     "Cantor Trophy",
	CrownShield:      "Crown Shield",
	Defender:         "Defender",
	DemonHead:        "Demon Head",
	DragonShield:     "Dragon Shield",
	FetishTrophy:     "Fetish Trophy",
	GargoyleHead:     "Gargoyle Head",
	GothicShield:     "Gothic Shield",
	GrimShield:       "Grim Shield",
	GildedShield:     "Gilded Shield",
	HeirophantTrophy: "Heirophant Trophy",
	Heater:           "Heater",
	HellspawnSkull:   "Hellspawn Skull",
	HeraldicShield:   "Heraldic Shield",
	KiteShield:       "Kite Shield",
	LargeShield:      "Large Shield",
	Luna:             "Luna",
	MinionSkull:      "Minion Skull",
	Monarch:          "Monarch",
	MummifiedTrophy:  "Mummified Trophy",
	OverseerSkull:    "Overseer Skull",
	Pavise:           "Pavise",
	PreservedHead:    "Preserved Head",
	ProtectorShield:  "Protector Shield",
	Rondache:         "Rondache",
	RoundShield:      "Round Shield",
	RoyalShield:      "Royal Shield",
	SacredRondache:   "Sacred Rondache",
	SacredTarge:      "Sacred Targe",
	Scutum:           "Scutum",
	SextonTrophy:     "Sexton Trophy",
	SmallShield:      "Small Shield",
	SpikedShield:     "Spiked Shield",
	SuccubusSkull:    "Succubus Skull",
	Targe:            "Targe",
	TowerShield:      "Tower Shield",
	TrollNest:        "Troll Nest",
	UnravellerHead:   "Unraveller Head",
	VortexShield:     "Vortex Shield",
	Ward:             "Ward",
	ZakarumShield:    "Zakarum Shield",
	ZombieHead:       "Zombie Head",
}

// Armor item codes mapped to their in game, human-friendly, readable name.
var armorCodes = map[string]string{
	AlphaHelm:         "Alpha Helm",
	AncientArmor:      "Ancient Armor",
	Antlers:           "Antlers",
	ArchonPlate:       "Archon Plate",
	Armet:             "Armet",
	AssaultHelmet:     "Assault Helmet",
	AvengerGuard:      "Avenger Guard",
	BalrogSkin:        "Balrog Skin",
	Basinet:           "Basinet",
	BattleBelt:        "Battle Belt",
	BattleBoots:       "Battle Boots",
	BattleGauntlets:   "Battle Gauntlets",
	Belt:              "Belt",
	BloodSpirit:       "Blood Spirit",
	BoneHelm:          "Bone Helm",
	BoneVisage:        "Bone Visage",
	Boneweave:         "Boneweave",
	BoneweaveBoots:    "Boneweave Boots",
	Bracers:           "Bracers",
	BrambleMitts:      "Bramble Mitts",
	BreastPlate:       "Breast Plate",
	Cap:               "Cap",
	CarnageHelm:       "Carnage Helm",
	Casque:            "Casque",
	ChainBoots:        "Chain Boots",
	ChainMail:         "Chain Mail",
	ChaosArmor:        "Chaos Armor",
	Circlet:           "Circlet",
	ColossusGirdle:    "Colossus Girdle",
	ConquerorCrown:    "Conqueror Crown",
	Corona:            "Corona",
	Coronet:           "Coronet",
	Crown:             "Crown",
	CrusaderGauntlets: "Crusader Gauntlets",
	Cuirass:           "Cuirass",
	DeathMask:         "Death Mask",
	Demonhead:         "Demonhead",
	DemonhideArmor:    "Demonhide Armor",
	DemonhideBoots:    "Demonhide Boots",
	DemonhideGloves:   "Demonhide Gloves",
	DemonhideSash:     "Demonhide Sash",
	DestroyerHelm:     "Destroyer Helm",
	Diadem:            "Diadem",
	DiamondMail:       "Diamond Mail",
	DreamSpirit:       "Dream Spirit",
	DuskShroud:        "Dusk Shroud",
	EarthSpirit:       "Earth Spirit",
	EmbossedPlate:     "Embossed Plate",
	FalconMask:        "Falcon Mask",
	FangedHelm:        "Fanged Helm",
	FieldPlate:        "Field Plate",
	FullHelm:          "Full Helm",
	PlateMail:         "Plate Mail",
	FullPlateMail:     "Full Plate Mail",
	FuryVisor:         "Fury Visor",
	Gauntlets:         "Gauntlets",
	GhostArmor:        "Ghost Armor",
	GiantConch:        "Giant Conch",
	Girdle:            "Girdle",
	Gloves:            "Gloves",
	GothicPlate:       "Gothic Plate",
	GrandCrown:        "Grand Crown",
	GreatHauberk:      "Great Hauberk",
	GreatHelm:         "Great Helm",
	GriffonHeadress:   "Griffon Headress",
	GrimHelm:          "Grim Helm",
	GuardianCrown:     "Guardian Crown",
	HardLeatherArmor:  "Hard Leather Armor",
	HawkHelm:          "Hawk Helm",
	HeavyBelt:         "Heavy Belt",
	HeavyBoots:        "Heavy Boots",
	HeavyBracers:      "Heavy Bracers",
	HeavyGloves:       "Heavy Gloves",
	HellforgedPlate:   "Hellforged Plate",
	Helm:              "Helm",
	HornedHelm:        "Horned Helm",
	HuntersGuise:      "Hunter's Guise",
	Hydraskull:        "Hydraskull",
	Hyperion:          "Hyperion",
	JawboneCap:        "Jawbone Cap",
	JawboneVisor:      "Jawbone Visor",
	KrakenShell:       "Kraken Shell",
	LacqueredPlate:    "Lacquered Plate",
	LeatherArmor:      "Leather Armor",
	LeatherBoots:      "Leather Boots",
	LightBelt:         "Light Belt",
	LightGauntlets:    "Light Gauntlets",
	LightPlate:        "Light Plate",
	LightPlatedBoots:  "Light Plated Boots",
	LinkedMail:        "Linked Mail",
	LionHelm:          "Lion Helm",
	LoricatedMail:     "Loricated Mail",
	MagePlate:         "Mage Plate",
	Mask:              "Mask",
	MeshArmor:         "Mesh Armor",
	MeshBelt:          "Mesh Belt",
	MeshBoots:         "Mesh Boots",
	MirroredBoots:     "Mirrored Boots",
	MithrilCoil:       "Mithril Coil",
	MyrmidonGreaves:   "Myrmidon Greaves",
	OgreGauntlets:     "Ogre Gauntlets",
	OrnatePlate:       "Ornate Plate",
	PlateBoots:        "Plate Boots",
	QuiltedArmor:      "Quilted Armor",
	RageMask:          "Rage Mask",
	RingMail:          "Ring Mail",
	RussetArmor:       "Russet Armor",
	SacredArmor:       "Sacred Armor",
	SacredFeathers:    "Sacred Feathers",
	Sallet:            "Sallet",
	Sash:              "Sash",
	SavageHelmet:      "Savage Helmet",
	ScaleMail:         "Scale Mail",
	ScarabHusk:        "Scarab Husk",
	ScarabshellBoots:  "Scarabshell Boots",
	SerpentskinArmor:  "Serpentskin Armor",
	ShadowPlate:       "Shadow Plate",
	Shako:             "Shako",
	SharkskinBelt:     "Sharkskin Belt",
	SharkskinBoots:    "Sharkskin Boots",
	SharkskinGloves:   "Sharkskin Gloves",
	SharktoothArmor:   "Sharktooth Armor",
	SkullCap:          "Skull Cap",
	SkySpirit:         "Sky Spirit",
	SlayerGuard:       "Slayer Guard",
	SpiderwebSash:     "Spiderweb Sash",
	SpiredHelm:        "Spired Helm",
	SpiritMask:        "Spirit Mask",
	SplintMail:        "Splint Mail",
	StuddedLeather:    "Studded Leather",
	SunSpirit:         "Sun Spirit",
	TemplarCoat:       "Templar Coat",
	Tiara:             "Tiara",
	TigulatedMail:     "Tigulated Mail",
	TotemicMask:       "Totemic Mask",
	TrellisedArmor:    "Trellised Armor",
	TrollBelt:         "Troll Belt",
	Vambraces:         "Vambraces",
	VampireboneGloves: "Vampirebone Gloves",
	VampirefangBelt:   "Vampirefang Belt",
	WarBelt:           "War Belt",
	WarBoots:          "War Boots",
	WarGauntlets:      "War Gauntlets",
	WarHat:            "War Hat",
	WingedHelm:        "Winged Helm",
	WireFleece:        "Wire Fleece",
	WolfHead:          "Wolf Head",
	Wyrmhide:          "Wyrmhide",
	WyrmhideBoots:     "Wyrmhide Boots",
}

// Weapon item codes mapped to their in game, human-friendly, readable name.
var weaponCodes = map[string]string{
	AncientAxe:          "Ancient Axe",
	AncientSword:        "Ancient Sword",
	Arbalest:            "Arbalest",
	ArchonStaff:         "Archon Staff",
	AshwoodBow:          "Ashwood Bow",
	Ataghan:             "Ataghan",
	Axe:                 "Axe",
	BalancedAxe:         "Balanced Axe",
	BalancedKnife:       "Balanced Knife",
	Balista:             "Balista",
	BalrogBlade:         "Balrog Blade",
	BalrogSpear:         "Balrog Spear",
	BarbedClub:          "Barbed Club",
	Bardiche:            "Bardiche",
	BastardSword:        "Bastard Sword",
	BattleAxe:           "Battle Axe",
	BattleCestus:        "Battle Cestus",
	BattleDart:          "Battle Dart",
	BattleHammer:        "Battle Hammer",
	BattleScythe:        "Battle Scythe",
	BattleStaff:         "Battle Staff",
	BattleSword:         "Battle Sword",
	BeardedAxe:          "Bearded Axe",
	BecDeCorbin:         "Bec De Corbin",
	BerserkerAxe:        "Berserker Axe",
	Bill:                "Bill",
	Blade:               "Blade",
	BladeBow:            "Blade Bow",
	BladeTalons:         "Blade Talons",
	BoneKnife:           "Bone Knife",
	BoneWand:            "Bone Wand",
	Brandistock:         "Brandistock",
	BroadAxe:            "Broad Axe",
	BroadSword:          "Broad Sword",
	BurntWand:           "Burnt Wand",
	Caduceus:            "Caduceus",
	CedarBow:            "Cedar Bow",
	CedarStaff:          "Cedar Staff",
	CeremonialBow:       "Ceremonial Bow",
	CeremonialJavelin:   "Ceremonial Javelin",
	CeremonialPike:      "Ceremonial Pike",
	CeremonialSpear:     "Ceremonial Spear",
	Cestus:              "Cestus",
	ChampionAxe:         "Champion Axe",
	ChampionSword:       "Champion Sword",
	ChokingGasPotion:    "Choking Gas Potion",
	ChuKoNu:             "Chu-Ko-Nu",
	Cinquedeas:          "Cinquedeas",
	ClaspedOrb:          "Clasped Orb",
	Claws:               "Claws",
	Claymore:            "Claymore",
	Cleaver:             "Cleaver",
	CloudySphere:        "Cloudy Sphere",
	Club:                "Club",
	ColossalSword:       "Colossal Sword",
	ColossalBlade:       "Colossal Blade",
	ColossusCrossbow:    "Colossus Crossbow",
	ColossusVoulge:      "Colossus Voulge",
	CompositeBow:        "Composite Bow",
	ConquestSword:       "Conquest Sword",
	Crossbow:            "Crossbow",
	Crowbill:            "Crowbill",
	CrusaderBow:         "Crusader Bow",
	CrypticAxe:          "Cryptic Axe",
	CrypticSword:        "Cryptic Sword",
	CrystalSword:        "Crystal Sword",
	CrystallineGlobe:    "Crystalline Globe",
	Cudgel:              "Cudgel",
	Cutlass:             "Cutlass",
	DacianFalx:          "Dacian Falx",
	Dagger:              "Dagger",
	Decapitator:         "Decapitator",
	DecoyDagger:         "Decoy Dagger",
	DemonCrossbow:       "Demon Crossbow",
	DemonHeart:          "Demon Heart",
	DevilStar:           "Devil Star",
	DiamondBow:          "Diamond Bow",
	DimensionalBlade:    "Dimensional Blade",
	DimensionalShard:    "Dimensional Shard",
	Dirk:                "Dirk",
	DivineScepter:       "Divine Scepter",
	DoubleAxe:           "Double Axe",
	DoubleBow:           "Double Bow",
	DragonStone:         "Dragon Stone",
	EableOrb:            "Eable Orb",
	EdgeBow:             "Edge Bow",
	ElderStaff:          "Elder Staff",
	EldritchOrb:         "Eldritch Orb",
	ElegantBlade:        "Elegant Blade",
	Espadon:             "Espadon",
	EttinAxe:            "Ettin Axe",
	ExecutionerSword:    "Executioner Sword",
	ExplodingPotion:     "Exploding Potion",
	Falcata:             "Falcata",
	Falchion:            "Falchion",
	FangedKnife:         "Fanged Knife",
	Fascia:              "Fascia",
	FeralAxe:            "Feral Axe",
	FeralClaws:          "Feral Claws",
	Flail:               "Flail",
	Flamberge:           "Flamberge",
	FlangedMace:         "Flanged Mace",
	FlyingAxe:           "Flying Axe",
	FlyingKnife:         "Flying Knife",
	Francisca:           "Francisca",
	FulmatingPotion:     "Fulmating Potion",
	Fuscina:             "Fuscina",
	GhostGlaive:         "Ghost Glaive",
	GhostSpear:          "Ghost Spear",
	GhostWand:           "Ghost Wand",
	GiantAxe:            "Giant Axe",
	GiantSword:          "Giant Sword",
	GiantThresher:       "Giant Thresher",
	Gidbinn:             "Gidbinn",
	Gladius:             "Gladius",
	Glaive:              "Glaive",
	GloriousAxe:         "Glorious Axe",
	GlowingOrb:          "Glowing Orb",
	GnarledStaff:        "Gnarled Staff",
	GorgonCrossbow:      "Gorgon Crossbow",
	GothicAxe:           "Gothic Axe",
	GothicBow:           "Gothic Bow",
	GothicStaff:         "Gothic Staff",
	GothicSword:         "Gothic Sword",
	GrandMatronBow:      "Grand Matron Bow",
	GrandScepter:        "Grand Scepter",
	GraveWand:           "Grave Wand",
	GreatAxe:            "Great Axe",
	GreatBow:            "Great Bow",
	GreatMaul:           "Great Maul",
	GreatPilum:          "Great Pilum",
	GreatPoleaxe:        "Great Poleaxe",
	GreatSword:          "Great Sword",
	GreaterClaws:        "Greater Claws",
	GreaterTalons:       "Greater Talons",
	GrimScythe:          "Grim Scythe",
	GrimWand:            "Grim Wand",
	Halberd:             "Halberd",
	HandAxe:             "Hand Axe",
	HandScythe:          "Hand Scythe",
	Harpoon:             "Harpoon",
	Hatchet:             "Hatchet",
	HatchetHands:        "HatchetHands",
	HeavenlyStone:       "Heavenly Stone",
	HeavyCrossbow:       "Heavy Crossbow",
	HellforgeHammer:     "Hellforge Hammer",
	HighlandBlade:       "Highland Blade",
	HolyWaterSprinkler:  "Holy Water Sprinkler",
	HoradricMalus:       "Horadric Malus",
	HoradricStaff:       "Horadric Staff",
	HuntersBow:          "Hunters Bow",
	Hurlbat:             "Hurlbat",
	HydraBow:            "Hydra Bow",
	HydraEdge:           "Hydra Edge",
	HyperionJavelin:     "Hyperion Javelin",
	HyperionSpear:       "Hyperion Spear",
	JaggedStar:          "Jagged Star",
	Javelin:             "Javelin",
	JoStaff:             "Jo Staff",
	Katar:               "Katar",
	KhalimFlail:         "Khalim Flail",
	Knout:               "Knout",
	Kriss:               "Kriss",
	Lance:               "Lance",
	LargeAxe:            "Large Axe",
	LegendSpike:         "Legend Spike",
	LegendSword:         "Legend Sword",
	LegendaryMallet:     "Legendary Mallet",
	LichWand:            "Lich Wand",
	LightCrossbow:       "Light Crossbow",
	LochaberAxe:         "Lochaber Axe",
	LongBattleBow:       "Long Battle Bow",
	LongBow:             "Long Bow",
	LongSiegeBow:        "Long Siege Bow",
	LongStaff:           "Long Staff",
	LongSword:           "Long Sword",
	LongWarBow:          "Long War Bow",
	Mace:                "Mace",
	MaidenJavelin:       "Maiden Javelin",
	MaidenPike:          "Maiden Pike",
	MaidenSpear:         "Maiden Spear",
	Mancatcher:          "Mancatcher",
	MarteldeFer:         "Martel de Fer",
	MatriarchalBow:      "Matriarchal Bow",
	MatriarchalPike:     "Matriarchal Pike",
	MatriarchalSpear:    "Matriarchal Spear",
	MatriarchalJavelin:  "Matriarchal Javelin",
	Maul:                "Maul",
	MightyScepter:       "Mighty Scepter",
	MilitaryAxe:         "Military Axe",
	MilitaryPick:        "Military Pick",
	MithralPoint:        "Mithral Point",
	MorningStar:         "Morning Star",
	MythicalSword:       "Mythical Sword",
	Naga:                "Naga",
	OgreAxe:             "Ogre Axe",
	OgreMaul:            "Ogre Maul",
	OilPotion:           "Oil Potion",
	Partizan:            "Partizan",
	PelletBow:           "Pellet Bow",
	PetrifiedWand:       "Petrified Wand",
	PhaseBlade:          "Phase Blade",
	Pike:                "Pike",
	Pilum:               "Pilum",
	Poignard:            "Poignard",
	Poleaxe:             "Poleaxe",
	PolishedWand:        "Polished Wand",
	QuarterStaff:        "Quarter Staff",
	Quhab:               "Quhab",
	RancidGasPotion:     "Rancid Gas Potion",
	RazorBow:            "Razor Bow",
	ReflexBow:           "Reflex Bow",
	ReinforcedMace:      "Reinforced Mace",
	RepeatingCrossbow:   "Repeating Crossbow",
	Rondel:              "Rondel",
	RuneBow:             "Rune Bow",
	RuneScepter:         "Rune Scepter",
	RuneStaff:           "Rune Staff",
	RuneSword:           "Rune Sword",
	RunicTalons:         "Runic Talons",
	Sabre:               "Sabre",
	SacredGlobe:         "Sacred Globe",
	Scepter:             "Scepter",
	Scimitar:            "Scimitar",
	ScissorsKatar:       "Scissors Katar",
	ScissorsQuhab:       "Scissors Quhab",
	ScissorsSuwayyah:    "Scissors Suwayyah",
	Scourge:             "Scourge",
	Scythe:              "Scythe",
	SeraphRod:           "Seraph Rod",
	ShadowBow:           "Shadow Bow",
	Shamshir:            "Shamshir",
	Shillelah:           "Shillelah",
	ShortBattleBow:      "Short Battle Bow",
	ShortBow:            "Short Bow",
	ShortSiegeBow:       "Short Siege Bow",
	ShortSpear:          "Short Spear",
	ShortStaff:          "Short Staff",
	ShortSword:          "Short Sword",
	ShortWarBow:         "Short War Bow",
	SiegeCrossbow:       "Siege Crossbow",
	SilverEdgedAxe:      "Silver Edged Axe",
	Simbilan:            "Simbilan",
	SmallCrescent:       "Small Crescent",
	SmokedSphere:        "Smoked Sphere",
	SparklingBall:       "Sparkling Ball",
	Spear:               "Spear",
	Spetum:              "Spetum",
	Spiculum:            "Spiculum",
	SpiderBow:           "Spider Bow",
	SpikedClub:          "Spiked Club",
	StaffOfTheKings:     "Staff Of The Kings",
	StagBow:             "Stag Bow",
	Stalagmite:          "Stalagmite",
	Stilleto:            "Stilleto",
	StranglingGasPotion: "Strangling Gas Potion",
	StygianPike:         "Stygian Pike",
	StygianPilum:        "Stygian Pilum",
	SuperKhalimFlail:    "Super Khalim Flail",
	Suwayyah:            "Suwayyah",
	SwirlingCrystal:     "Swirling Crystal",
	Tabar:               "Tabar",
	Thresher:            "Thresher",
	ThrowingAxe:         "Throwing Axe",
	ThrowingKnife:       "Throwing Knife",
	ThrowingSpear:       "Throwing Spear",
	ThunderMaul:         "Thunder Maul",
	Tomahawk:            "Tomahawk",
	TombWand:            "Tomb Wand",
	Trident:             "Trident",
	Truncheon:           "Truncheon",
	Tulwar:              "Tulwar",
	TuskSword:           "Tusk Sword",
	TwinAxe:             "Twin Axe",
	TwoHandedSword:      "Two Handed Sword",
	TyrantClub:          "Tyrant Club",
	UnearthedWand:       "Unearthed Wand",
	VortexOrb:           "Vortex Orb",
	Voulge:              "Voulge",
	WalkingStick:        "Walking Stick",
	Wand:                "Wand",
	WarAxe:              "War Axe",
	WarClub:             "War Club",
	WarDart:             "War Dart",
	WarFist:             "War Fist",
	WarFork:             "War Fork",
	WarHammer:           "War Hammer",
	WarJavelin:          "War Javelin",
	WarPike:             "War Pike",
	WarScepter:          "War Scepter",
	WarScythe:           "War Scythe",
	WarSpear:            "War Spear",
	WarSpike:            "War Spike",
	WarStaff:            "War Staff",
	WarSword:            "War Sword",
	WardBow:             "Ward Bow",
	WingedAxe:           "Winged Axe",
	WingedHarpoon:       "Winged Harpoon",
	WingedKnife:         "Winged Knife",
	WirtsLeg:            "Wirts Leg",
	WristBlade:          "Wrist Blade",
	WristSpike:          "Wrist Spike",
	WristSword:          "Wrist Sword",
	Yari:                "Yari",
	YewWand:             "Yew Wand",
	Zweihander:          "Zweihander",
}

// Misc items codes, like jewelry, gems, potions and runes, mapped to their in
// game, human-friendly, readable name.
var miscCodes = map[string]string{
	Amethyst:                      "Amethyst",
	AmnRune:                       "Amn Rune",
	Amulet:                        "Amulet",
	AntidotePotion:                "Antidote Potion",
	Arrows:                        "Arrows",
	BaalsEye:                      "Baal's Eye",
	BarkScroll:                    "Bark Scroll",
	BerRune:                       "Ber Rune",
	Bolts:                         "Bolts",
	BookofSkill:                   "Book of Skill",
	BurningEssenceofTerror:        "Burning Essence of Terror",
	ChamRune:                      "Cham Rune",
	ChargedEssenceofHatred:        "Charged Essence of Hatred",
	GrandCharm:                    "Grand Charm",
	LargeCharm:                    "Large Charm",
	SmallCharm:                    "Small Charm",
	ChippedAmethyst:               "Chipped Amethyst",
	ChippedDiamond:                "Chipped Diamond",
	ChippedEmerald:                "Chipped Emerald",
	ChippedRuby:                   "Chipped Ruby",
	ChippedSapphire:               "Chipped Sapphire",
	ChippedSkull:                  "Chipped Skull",
	ChippedTopaz:                  "Chipped Topaz",
	DecipheredBarkScroll:          "Deciphered Bark Scroll",
	DiablosHorn:                   "Diablo's Horn",
	Diamond:                       "Diamond",
	DolRune:                       "Dol Rune",
	ElRune:                        "El Rune",
	EldRune:                       "Eld Rune",
	Elixir:                        "Elixir",
	Emerald:                       "Emerald",
	EthRune:                       "Eth Rune",
	FalRune:                       "Fal Rune",
	FesteringEssenceofDestruction: "Festering Essence of Destruction",
	FlawedAmethyst:                "Flawed Amethyst",
	FlawedDiamond:                 "Flawed Diamond",
	FlawedEmerald:                 "Flawed Emerald",
	FlawedRuby:                    "Flawed Ruby",
	FlawedSapphire:                "Flawed Sapphire",
	FlawedSkull:                   "Flawed Skull",
	FlawedTopaz:                   "Flawed Topaz",
	FlawlessAmethyst:              "Flawless Amethyst",
	FlawlessDiamond:               "Flawless Diamond",
	FlawlessEmerald:               "Flawless Emerald",
	FlawlessRuby:                  "Flawless Ruby",
	FlawlessSapphire:              "Flawless Sapphire",
	FlawlessSkull:                 "Flawless Skull",
	FlawlessTopaz:                 "Flawless Topaz",
	FullHealingPotion:             "Full Healing Potion",
	FullManaPotion:                "Full Mana Potion",
	FullRejuvenationPotion:        "Full Rejuvenation Potion",
	Gold:                          "Gold",
	GoldBird:                      "Gold Bird",
	GreaterHealingPotion:          "Greater Healing Potion",
	GreaterManaPotion:             "Greater Mana Potion",
	GulRune:                       "Gul Rune",
	HealingPotion:                 "Healing Potion",
	HealingPotionMid:              "Healing Potion",
	HelRune:                       "Hel Rune",
	Herb:                          "Herb",
	HoradricCube:                  "Horadric Cube",
	IdentifyBook:                  "Identify Book",
	IdentifyScroll:                "Identify Scroll",
	IoRune:                        "Io Rune",
	IstRune:                       "Ist Rune",
	IthRune:                       "Ith Rune",
	JadeFigurine:                  "Jade Figurine",
	JahRune:                       "Jah Rune",
	Jewel:                         "Jewel",
	KeyofDestruction:              "Key of Destruction",
	KeyofHate:                     "Key of Hate",
	KeyofTerror:                   "Key of Terror",
	KhalimsBrain:                  "Khalim's Brain",
	KhalimsEye:                    "Khalim's Eye",
	KhalimsHeart:                  "Khalim's Heart",
	KoRune:                        "Ko Rune",
	LamEsensTome:                  "Lam Esens Tome",
	LargeBluePotion:               "Large Blue Potion",
	LargeRedPotion:                "Large Red Potion",
	LemRune:                       "Lem Rune",
	LesserHealingPotion:           "Lesser Healing Potion",
	LesserManaPotion:              "Lesser Mana Potion",
	LightHealingPotion:            "Light Healing Potion",
	LightManaPotion:               "Light Mana Potion",
	LoRune:                        "Lo Rune",
	LumRune:                       "Lum Rune",
	Maguffin:                      "Maguffin",
	MalRune:                       "Mal Rune",
	ManaPotion:                    "Mana Potion",
	ManaPotionMid:                 "Mana Potion",
	MephistosBrain:                "Mephisto's Brain",
	MephistoKey:                   "Mephisto Key",
	MephistoSoulStone:             "Mephisto Soul Stone",
	NefRune:                       "Nef Rune",
	OhmRune:                       "Ohm Rune",
	OrtRune:                       "Ort Rune",
	PerfectAmethyst:               "Perfect Amethyst",
	PerfectDiamond:                "Perfect Diamond",
	PerfectEmerald:                "Perfect Emerald",
	PerfectRuby:                   "Perfect Ruby",
	PerfectSapphire:               "Perfect Sapphire",
	PerfectSkull:                  "Perfect Skull",
	PerfectTopaz:                  "Perfect Topaz",
	PlayerEar:                     "Player Ear",
	PulRune:                       "Pul Rune",
	RalRune:                       "Ral Rune",
	RejuvenationPotion:            "Rejuvenation Potion",
	Ring:                          "Ring",
	Ruby:                          "Ruby",
	Sapphire:                      "Sapphire",
	Scroll:                        "Scroll",
	ScrollofHoradric:              "Scroll of Horadric",
	ScrollofMalah:                 "Scroll of Malah",
	PotionofLife:                  "Potion of Life",
	ShaelRune:                     "Shael Rune",
	SkeletonKey:                   "Skeleton Key",
	Skull:                         "Skull",
	SmallBluePotion:               "Small Blue Potion",
	SmallRedPotion:                "Small Red Potion",
	SolRune:                       "Sol Rune",
	StaminaPotion:                 "Stamina Potion",
	StandardofHeroes:              "Standard of Heroes",
	StrongHealingPotion:           "Strong Healing Potion",
	StrongManaPotion:              "Strong Mana Potion",
	SurRune:                       "Sur Rune",
	TalRune:                       "Tal Rune",
	ThawingPotion:                 "Thawing Potion",
	ThulRune:                      "Thul Rune",
	TirRune:                       "Tir Rune",
	TokenofAbsolution:             "Token of Absolution",
	Topaz:                         "Topaz",
	Torch:                         "Torch",
	TownPortalBook:                "Town Portal Book",
	TownPortalScroll:              "Town Portal Scroll",
	TwistedEssenceofSuffering:     "Twisted Essence of Suffering",
	UmRune:                        "Um Rune",
	VexRune:                       "Vex Rune",
	ViperAmulet:                   "Viper Amulet",
	ZodRune:                       "Zod Rune",
}
*/

const int AmorCodeLength = 149;
const int WeaponCodeLength = 306;
const int ShieldCodeLength = 53;
const int QuantityCodeLength = 41;
const int TomeCodeLength = 2;
const int RareNamesLength = 201;
const int SetNamesLength = 127;

const int RunewordNamesLength = 79;
const int UniqueNamesLength = 401;

const int MagicalPrefixesLength = 637;
const int MagicalSuffixesLength = 747;

const string AmorCode[] = { 
"bac",
"vgl",
"ult",
"xhl",
"mbl",
"ci0",
"drf",
"urg",
"ltp",
"xmb",
"uhb",
"dr3",
"ulb",
"lbl",
"mbt",
"ukp",
"umc",
"uhg",
"ba9",
"xtu",
"mgl",
"hgl",
"plt",
"hlm",
"ulc",
"ba5",
"bab",
"utg",
"xlg",
"dr8",
"ztb",
"crn",
"skp",
"spl",
"cap",
"xrn",
"uar",
"umg",
"xap",
"dr1",
"ba2",
"utb",
"xea",
"urs",
"gth",
"bhm",
"dr2",
"lbt",
"uvg",
"upl",
"ghm",
"dr7",
"uul",
"umb",
"ful",
"xui",
"uhl",
"ba3",
"lea",
"xng",
"zlb",
"brs",
"bad",
"uui",
"dr4",
"xtg",
"xtb",
"xla",
"xth",
"ba4",
"rng",
"qui",
"chn",
"tgl",
"hbt",
"xvb",
"utp",
"xul",
"xmg",
"xvg",
"drb",
"bae",
"uld",
"ucl",
"xpl",
"dr9",
"uvb",
"dra",
"aar",
"baf",
"uap",
"dre",
"baa",
"stu",
"uhc",
"lgl",
"tbl",
"drc",
"urn",
"hbl",
"xar",
"zvb",
"xhm",
"fhl",
"msk",
"xlt",
"uvc",
"utu",
"xsk",
"fld",
"xtp",
"ci3",
"ung",
"ba7",
"zmb",
"xrs",
"uh9",
"uhn",
"hla",
"ba8",
"ula",
"dr6",
"ba1",
"uth",
"vbl",
"dr5",
"xcl",
"drd",
"xlm",
"ci2",
"utc",
"xhg",
"ulg",
"usk",
"xlb",
"tbt",
"scl",
"xld",
"ulm",
"xh9",
"vbt",
"xkp",
"uhm",
"xhb",
"ci1",
"ba6",
"zhb",
"uea",
"xhn"
};

const string WeaponCode[] = { 
"7cl",
"9fb",
"9ba",
"am7",
"9gw",
"9ar",
"8ws",
"sbb",
"7gs",
"6s7",
"hfh",
"9ls",
"6ls",
"9ja",
"bld",
"6cs",
"7ss",
"gix",
"9br",
"ob7",
"hax",
"9m9",
"6hb",
"am9",
"7bs",
"7kr",
"9ga",
"7sc",
"hxb",
"9vo",
"8lb",
"6bs",
"tsp",
"bar",
"7ga",
"axf",
"7fc",
"8ls",
"7b8",
"9b9",
"hbw",
"7m7",
"btl",
"obb",
"am4",
"7wd",
"wsp",
"7la",
"9tr",
"9wa",
"gps",
"spt",
"ama",
"obf",
"7st",
"9s8",
"8cs",
"7wc",
"7s8",
"9gs",
"9wh",
"7b7",
"7vo",
"9b8",
"7sp",
"9sr",
"9wd",
"brn",
"dir",
"lst",
"6ss",
"wsc",
"vou",
"7ts",
"9sp",
"9tk",
"gsd",
"6lw",
"ob9",
"spc",
"clw",
"flb",
"g33",
"scy",
"6lb",
"7wa",
"lax",
"mau",
"mpi",
"bal",
"9la",
"7di",
"flc",
"9lw",
"7o7",
"8mx",
"7gw",
"7bk",
"92h",
"9ta",
"2hs",
"am6",
"8rx",
"ktr",
"mst",
"6lx",
"9st",
"bax",
"9sb",
"btx",
"kri",
"pil",
"scp",
"d33",
"7lw",
"7bw",
"7wn",
"7ma",
"sst",
"jav",
"8lx",
"7s7",
"7dg",
"9mp",
"8sb",
"opl",
"6l7",
"am5",
"am3",
"am8",
"glv",
"7gi",
"9qs",
"72h",
"7wh",
"7gl",
"hst",
"ob3",
"7gm",
"8cb",
"9fl",
"am2",
"7mt",
"opm",
"gpl",
"9pi",
"9qr",
"am1",
"ob8",
"7tk",
"gis",
"amc",
"7fl",
"obe",
"ob1",
"amb",
"amf",
"ssp",
"6sw",
"8lw",
"qf1",
"9b7",
"9sc",
"9bl",
"7xf",
"wnd",
"whm",
"ob4",
"clm",
"9cl",
"hal",
"swb",
"7ax",
"8l8",
"ssd",
"9gi",
"bsw",
"9ax",
"6hx",
"7pa",
"7ja",
"wax",
"wst",
"bsd",
"9wn",
"9cm",
"9pa",
"7qr",
"8s8",
"72a",
"tkf",
"wrb",
"qf2",
"9bw",
"7sm",
"6mx",
"9ts",
"9mt",
"8ss",
"msf",
"9bk",
"ces",
"gpm",
"9cr",
"gsc",
"7p7",
"ywn",
"7gd",
"gma",
"7h7",
"9di",
"7ha",
"6ws",
"9wc",
"7tw",
"wsd",
"7ba",
"9s9",
"9bs",
"9kr",
"6cb",
"7br",
"amd",
"ops",
"7tr",
"8hx",
"ob6",
"7pi",
"crs",
"gwn",
"8hb",
"7wb",
"7ta",
"skr",
"92a",
"leg",
"7yw",
"pik",
"7ar",
"tax",
"dgr",
"ob5",
"scm",
"7qs",
"9ha",
"mac",
"lwb",
"9dg",
"7cs",
"mxb",
"7bt",
"2ax",
"9tw",
"7bl",
"fla",
"9gl",
"7sr",
"lsd",
"rxb",
"9bt",
"7mp",
"7sb",
"bwn",
"clb",
"9cs",
"spr",
"axe",
"7fb",
"cst",
"lbw",
"7cr",
"8sw",
"9gm",
"sbr",
"9sm",
"9xf",
"9ma",
"8bs",
"gax",
"lbb",
"6sb",
"9ss",
"7cm",
"bkf",
"9h9",
"7ls",
"6rx",
"obd",
"9ws",
"9yw",
"ob2",
"tri",
"9wb",
"oba",
"9fc",
"bst",
"7ws",
"cbw",
"lxb",
"ame",
"pax",
"obc",
"9gd",
"hdm",
"9p9",
"sbw"
};

const string ShieldCode[] = { 
"xpk",
"xrg",
"ne3",
"pa4",
"ne5",
"pa2",
"xml",
"pa3",
"kit",
"ned",
"tow",
"uts",
"xts",
"pae",
"xsh",
"neb",
"nea",
"pad",
"upk",
"ne7",
"paa",
"paf",
"pa7",
"ne8",
"buc",
"ne9",
"xuc",
"pa9",
"sml",
"bsh",
"nef",
"pa6",
"uuc",
"ne6",
"pab",
"pa1",
"ne4",
"gts",
"uow",
"lrg",
"uit",
"ne1",
"ush",
"neg",
"spk",
"nee",
"xit",
"xow",
"pa8",
"ne2",
"uml",
"pac",
"pa5"
};

const string QutityCode[] = { 
"tax",
"9b8",
"jav",
"7ts",
"am5",
"gps",
"gpl",
"7tk",
"ssp",
"7s7",
"aqv",
"9tk",
"9ta",
"pil",
"7pi",
"bal",
"9s9",
"7gl",
"9pi",
"9ts",
"7ja",
"key",
"opm",
"tkf",
"7bk",
"7b8",
"tbk",
"7ta",
"ama",
"glv",
"tsp",
"9gl",
"amf",
"bkf",
"9bk",
"9ja",
"ibk",
"ops",
"gpm",
"opl",
"cqv"
};

const string TomeCode[] = {
  "tbk",
  "ibk"
};

const uint64_t RareNames[] = {
80,147,151,27,32,50,74,76,176,183,57,79,108,7,26,30,36,56,123,173,126,135,171,2,
4,6,63,66,103,106,150,39,70,73,75,84,93,119,146,40,44,69,82,107,189,200,11,61,83,
129,172,17,186,167,178,42,92,116,131,162,20,72,78,161,197,9,23,77,115,141,16,49,
55,67,140,122,163,188,19,65,89,97,104,190,184,193,31,71,90,127,145,60,88,99,18,24,
48,52,58,102,110,118,179,194,95,98,117,10,25,38,45,47,142,180,86,125,148,152,156,
8,41,143,144,166,12,43,124,149,164,137,13,53,64,94,120,29,134,136,169,33,105,111,
130,132,174,160,182,185,62,114,121,139,159,175,22,37,59,68,87,91,101,153,157,5,21,
34,168,198,191,201,1,51,85,109,181,155,165,15,28,128,133,138,196,54,81,113,170,187,
14,96,154,199,100,112,158,192,195,3,35,46,177
};

const uint64_t SetNames[] = {
15,26,8,37,88,114,126,11,39,58,113,27,102,93,23,32,45,53,4,6,18,64,68,87,94,0,41,
89,29,84,91,9,33,52,71,74,90,109,115,3,120,55,73,31,42,54,81,99,103,125,24,47,72,
121,43,123,85,70,50,92,118,38,75,77,95,116,65,100,122,66,16,60,105,12,14,30,82,86,
97,98,104,1,36,44,46,83,35,59,61,69,79,96,110,34,76,117,49,56,21,13,67,5,111,78,
112,40,7,17,20,22,28,51,63,2,124,62,57,80,101,19,107,106,108,25,48,119,10
};

const uint64_t RunewordNames[] = { 
77,147,63,123,131,141,185,146,164,188,67,74,101,107,145,27,32,142,156,193,173,179,
39,70,92,108,159,2718,34,52,106,116,187,134,137,158,71,86,88,91,113,112,151,42,46,
57,59,135,162,30,60,80,98,117,37,53,95,124,64,100,120,128,73,81,195,36,56,153,155,
55,62,65,75,85,35,40,43,51,97
};

const uint64_t UniqueNames[] = {
159,166,167,190,252,43,49,95,358,367,377,143,179,215,64,88,133,42,147,270,123,326,
393,235,242,307,9,170,195,345,181,201,264,198,224,279,330,350,21,60,121,194,325,
384,76,151,191,257,305,356,98,99,205,20,211,396,239,30,74,234,152,199,210,219,271,
16,19,48,297,183,222,249,380,46,177,182,295,347,373,130,141,289,306,338,255,267,
272,203,346,227,292,311,399,7,26,202,383,77,105,245,184,206,313,351,355,3,18,164,
153,178,212,329,388,45,73,148,391,308,331,92,196,261,114,186,275,315,360,6,59,81,
389,2,72,277,363,387,102,104,258,161,162,163,217,284,38,70,100,328,364,378,89,291,
336,317,318,365,371,386,230,231,274,220,352,379,47,172,187,221,250,280,303,310,75,
111,150,321,86,116,132,157,236,266,395,66,103,149,12,339,381,175,200,246,273,296,
31,58,168,320,240,342,359,125,126,209,193,233,238,251,348,55,94,145,174,269,290,
316,392,62,80,118,229,301,323,61,171,223,110,139,189,204,218,28,36,63,332,112,
243,260,268,294,1,34,51,276,343,376,35,40,90,241,394,232,293,319,344,39,82,122,
254,300,397,22,52,79,91,137,237,248,334,24,27,32,362,382,160,188,247,349,65,129,
158,78,213,262,281,25,53,67,108,11,85,87,107,180,286,228,390,4,71,117,278,283,312,
375,37,96,165,256,374,97,140,225,84,259,333,370,106,263,309,146,155,282,314,327,
109,115,135,400,341,353,398,144,244,56,119,136,93,124,197,214,357,10,29,33,207,265,
372,128,138,173,14,169,340,302,304,322,354,361,54,156,226,366,176,285,287,288,298,
69,113,154,299,324,68,120,134,185,335,5,8,23,369,13,253,41,50,101,192,208,0,15,17,
385,127,131,142,216,337,44,57,83,368
};

const uint64_t MagicalPrefixes[] = {
132,139,247,311,346,436,544,3,560,566,145,143,171,455,640,14,241,402,486,565,170,
337,477,621,42,461,474,610,328,437,15,36,430,537,578,616,180,238,94,179,341,347,
352,358,442,611,156,325,645,152,101,124,153,173,269,496,506,25,582,575,129,185,
202,362,522,597,636,70,121,128,158,162,276,514,53,240,296,319,429,499,513,40,398,
529,622,642,279,264,379,476,491,109,137,174,334,428,431,459,13,140,233,354,507,
569,105,342,371,420,516,631,332,394,584,186,175,450,93,189,338,395,467,612,184,
154,155,195,555,646,107,304,426,147,561,159,363,365,381,638,667,134,536,234,535,
577,613,372,274,335,627,99,361,418,454,502,86,212,408,548,580,55,635,647,28,125,
187,236,244,650,114,146,209,329,380,465,471,609,33,169,197,494,574,614,37,196,248,
301,315,606,653,659,118,194,250,258,407,422,191,19,90,2,297,377,58,265,277,475,526,
581,608,664,87,59,106,150,563,27,253,353,359,384,599,221,166,266,321,462,512,619,
148,620,103,138,251,448,30,270,456,531,568,201,331,382,423,539,550,551,592,182,323,
345,473,127,151,249,385,440,542,559,591,43,119,220,303,326,432,458,656,72,190,260,
364,469,481,666,5,538,567,570,445,416,387,505,115,161,245,275,282,556,639,68,662,
441,497,594,641,313,383,484,589,49,81,284,370,447,75,207,355,409,472,586,113,167,
291,300,330,483,596,624,39,110,351,404,449,528,651,108,498,444,18,29,96,231,401,
417,470,7,389,552,601,57,215,490,104,20,76,78,520,541,6,344,593,206,397,524,617,
97,142,317,652,660,120,224,308,478,545,547,38,487,515,654,229,349,480,510,572,193,
130,163,199,368,468,517,41,438,629,632,343,287,333,367,439,464,511,669,183,292,668,
34,324,425,443,178,374,576,316,102,293,314,558,623,665,259,285,295,433,663,188,280,
603,243,375,564,309,312,434,595,208,281,298,410,424,65,263,322,378,634,77,254,318,
373,218,133,168,172,226,256,310,336,56,451,415,294,399,198,267,288,392,479,50,157,
164,217,219,262,305,466,64,605,391,453,283,532,225,227,273,588,177,246,356,482,628,
35,85,181,237,500,571,658,8,144,228,235,583,67,421,272,239,661,16,222,223,357,527,
530,546,149,214,320,598,657,141,213,252,299,414,488,495,88,69,160,302,403,518,579,
60,61,289,348,504,509,590,618,4,637,327,457,493,630,165,257,412,489,525,534,553,95,
573,625,122,340,427,554,585,261,508,419,205,216,452,126,306,600,255,84,210,307,485,
626,643,66,413,540,230,350,405,406,521,533,587,607,211,633,644,268,123,176,232,242,
388,435,523,32,604,204,26,271,366,519,557,200,278,286,360,386,492,503,602,9,136,203,
376,446,549,79,390,411,463,648,649,339,369,562,17,131,135,396,460,655,112,192,290,
393,400,501,543,615,111
};

const uint64_t MagicalSuffixes[] = {
458,687,726,360,369,374,384,434,471,626,641,223,713,657,128,424,577,637,34,230,
379,554,568,747,27,62,78,82,4,112,366,373,421,482,564,572,111,727,70,109,125,141,
163,240,251,15,525,580,604,512,184,395,399,621,132,126,131,135,166,319,330,418,2,
559,456,558,569,630,695,394,276,284,407,673,63,113,222,313,364,388,546,620,18,168,
247,426,631,51,685,677,279,321,447,486,110,333,613,655,691,332,225,520,648,650,169,
89,289,341,367,415,676,36,413,587,402,578,730,576,440,549,327,238,254,322,381,391,
643,30,628,121,185,353,466,644,178,420,463,507,537,682,5,286,478,494,524,542,647,
733,139,239,346,610,699,95,136,267,277,365,368,567,116,55,65,67,293,451,521,575,7,
619,745,590,14,108,124,183,270,324,411,1,618,659,481,106,312,513,541,654,87,237,297,
308,443,731,189,137,192,205,231,258,519,527,117,540,582,529,455,498,186,210,272,285,
439,584,656,736,150,594,188,50,200,259,398,419,453,474,44,465,323,140,299,362,377,99,
48,61,88,165,197,608,701,28,298,301,611,162,268,331,417,427,430,742,12,195,711,25,294,
390,409,646,681,724,143,84,444,617,721,75,114,202,226,290,389,556,612,38,707,123,212,
528,531,103,437,493,574,664,739,292,196,304,386,408,503,53,385,588,598,635,722,743,
156,115,127,233,491,516,69,104,221,229,718,74,658,47,523,544,33,716,262,158,219,314,
337,690,710,57,406,526,148,86,96,468,511,600,80,392,454,585,697,179,91,97,105,227,
506,634,698,59,206,241,473,35,338,397,492,514,638,640,119,557,565,597,609,177,201,
248,380,452,586,605,614,100,732,357,370,387,404,405,170,372,450,469,475,592,281,147,
228,311,689,129,336,633,666,265,464,476,740,275,244,361,652,729,138,43,164,303,438,
477,6,92,253,518,533,49,37,93,220,429,496,717,720,3,209,283,382,383,470,583,737,152,
203,208,271,428,517,706,712,161,725,90,167,181,535,581,669,71,310,462,499,692,13,263,
396,599,636,180,738,688,235,306,422,441,649,662,149,159,375,680,686,700,705,118,273,
309,508,552,571,651,704,45,23,122,371,400,457,10,497,562,414,21,54,79,85,236,335,355,
20,596,543,134,146,250,280,632,642,101,31,603,667,671,19,509,734,484,269,282,300,344,
553,625,663,142,81,214,624,29,302,467,589,41,215,660,187,345,539,679,683,317,339,495,
595,307,522,347,359,445,485,487,488,505,56,670,672,719,728,623,515,207,218,234,261,325,
326,548,72,723,160,173,198,213,17,193,249,320,348,358,431,489,24,145,155,172,252,376,
423,591,66,741,305,363,243,171,459,501,538,560,702,98,68,287,315,432,446,532,536,46,593,
318,412,551,153,480,561,334,52,264,266,354,410,460,573,16,675,645,130,174,278,349,629,
120,393,433,627,260,194,211,256,436,500,510,555,77,665,684,709,744,570,144,352,563,133,
94,245,291,403,504,601,639,60,342,401,653,83,182,343,157,176,674,714,11,224,328,356,607,
199,708,703,151,351,416,425,461,534,694,32,696,217,435,472,616,216,191,255,502,566,668,
64,40,190,316,442,479,530,550,39,693,606,42,107,204,274,295,661,22,257,350,678,715,8,154,
288,378,448,490,622,76,340,545,602,615,735,746,329,73,102,232,242,246,449,547,26,175,296,9,
483,579,58
};

int getBigType(string typeCode) {
  //std::cout << "[" << typeCode << "]" << std::endl;
  typeCode = typeCode.substr(0, 3);
  for (int i = 0; i < AmorCodeLength; i++) {
    if (AmorCode[i] == typeCode) {
      return ITEM_AMOR;
    }
  }
  for (int i = 0; i < WeaponCodeLength; i++) {
    if (WeaponCode[i] == typeCode) {
      return ITEM_WEAPON;
    }
  }
  for (int i = 0; i < ShieldCodeLength; i++) {
    if (ShieldCode[i] == typeCode) {
      return ITEM_SHIELD;
    }
  }
  return ITEM_MISC;
}