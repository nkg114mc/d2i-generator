#include <iostream>
#include <sstream>
#include <cassert>
#include <map>
#include <string>
#include <utility>

#include "items.h"



void addUnaryMagic(ComplexItem &item, int code, MagicValue &value)
{
	MagicAttribute magic;
	magic.propCode = code;
	magic.valueCount = 1;
	
	
	
	magic.mValues[0] = value;


	// add to item
	item.magicAttrList.push_back(magic);
}

void addBinaryMagic(ComplexItem &item, int code, MagicValue &value1, MagicValue &value2)
{
}

void addTrippleMagic(ComplexItem &item, int code, MagicValue &value1, MagicValue &value2, MagicValue &value3)
{
}

void addQuadMagic(ComplexItem &item,
				  int code,
				  MagicValue &value1,
				  MagicValue &value2,
				  MagicValue &value3,
				  MagicValue &value4)
{
}

MagicProperty indexedMagics[512];
MagicProperty ustatsMagics[512];

MagicProperty noNeedMagics[] = {
	{25, 1, {8, -1, -1, -1}, 0, "Unknown (Invisible)"},
	{26, 1, {8, -1, -1, -1}, 0, "Unknown (Invisible)"},
	{67, 1, {7, -1, -1, -1}, 30, "Unknown (Invisible)"},
	{68, 1, {7, -1, -1, -1}, 30, "Unknown (Invisible)"},
	{71, 1, {8, -1, -1, -1}, 100, "Unknown (Invisible)"},
	{72, 1, {9, -1, -1, -1}, 0, "Unknown (Invisible)"},
	{82, 1, {9, -1, -1, -1}, 20, "Unknown (Invisible)"},
	{88, 1, {1, -1, -1, -1}, 0, "Unknown (Invisible)"},
	{90, 1, {5, -1, -1, -1}, 0, "Ambient light"},
	{91, 1, {8, -1, -1, -1}, 100, "Requirements {0}%"},
	{92, 1, {7, -1, -1, -1}, 0, "Level requirements +{0} (Invisible)"},
	{94, 1, {7, -1, -1, -1}, 64, "Unknown (Invisible)"},
	{179, 1, {3, -1, -1, -1}, 0, "+{0} to Druid Skill Levels"},	   //// Attack vs monster?
	{180, 1, {3, -1, -1, -1}, 0, "+{0} to Assassin Skill Levels"}, //// Damage vs monster?
	{194, 1, {4, -1, -1, -1}, 0, "Adds {0} extra sockets to the item"},
	{324, 1, {6, -1, -1, -1}, 0, "Unknown (Invisible)"},
	{356, 1, {2, -1, -1, -1}, 0, "Quest Item Difficulty +{0} (Invisible)"},
	
	{84, 2, {3, 3, -1, -1}, 0, "+{1} to {0} Skill Levels"},
};

MagicProperty existMagics[] = {
	// unary
	{0, 1, {8, -1, -1, -1}, 32, "+{0} to Strength"},
	{1, 1, {7, -1, -1, -1}, 32, "+{0} to Energy"},
	{2, 1, {7, -1, -1, -1}, 32, "+{0} to Dexterity"},
	{3, 1, {7, -1, -1, -1}, 32, "+{0} to Vitality"},
	{7, 1, {9, -1, -1, -1}, 32, "+{0} to Life"},
	{9, 1, {8, -1, -1, -1}, 32, "+{0} to Mana"},
	{11, 1, {8, -1, -1, -1}, 32, "+{0} to Maximum Stamina"},
	{16, 1, {9, -1, -1, -1}, 0, "+{0}% Enhanced Defense"},
	{19, 1, {10, -1, -1, -1}, 0, "+{0} to Attack rating"},
	{20, 1, {6, -1, -1, -1}, 0, "+{0}% Increased chance of blocking"},
	{21, 1, {6, -1, -1, -1}, 0, "+{0} to Minimum 1-handed damage"},
	{22, 1, {7, -1, -1, -1}, 0, "+{0} to Maximum 1-handed damage"},
	{23, 1, {6, -1, -1, -1}, 0, "+{0} to Minimum 2-handed damage"},
	{24, 1, {7, -1, -1, -1}, 0, "+{0} to Maximum 2-handed damage"},
	{27, 1, {8, -1, -1, -1}, 0, "Regenerate Mana {0}%"},
	{28, 1, {8, -1, -1, -1}, 0, "Heal Stamina {0}%"},
	{31, 1, {11, -1, -1, -1}, 10, "+{0} Defense"},
	{32, 1, {9, -1, -1, -1}, 0, "+{0} vs. Missile"},
	{33, 1, {8, -1, -1, -1}, 10, "+{0} vs. Melee"},
	{34, 1, {6, -1, -1, -1}, 0, "Damage Reduced by {0}"},
	{35, 1, {6, -1, -1, -1}, 0, "Magic Damage Reduced by {0}"},
	{36, 1, {8, -1, -1, -1}, 0, "Damage Reduced by {0}%"},
	{37, 1, {8, -1, -1, -1}, 0, "Magic Resist +{0}%"},
	{38, 1, {5, -1, -1, -1}, 0, "+{0}% to Maximum Magic Resist"}, //// 8?
	{39, 1, {8, -1, -1, -1}, 50, "Fire Resist +{0}%"},
	{40, 1, {5, -1, -1, -1}, 0, "+{0}% to Maximum Fire Resist"},
	{41, 1, {8, -1, -1, -1}, 50, "Lightning Resist +{0}%"},
	{42, 1, {5, -1, -1, -1}, 0, "+{0}% to Maximum Lightning Resist"},
	{43, 1, {8, -1, -1, -1}, 50, "Cold Resist +{0}%"},
	{44, 1, {5, -1, -1, -1}, 0, "+{0}% to Maximum Cold Resist"},
	{45, 1, {8, -1, -1, -1}, 50, "Poison Resist +{0}%"},
	{46, 1, {5, -1, -1, -1}, 0, "+{0}% to Maximum Poison Resist"},
	{49, 1, {9, -1, -1, -1}, 0, "+{0} to Maximum Fire Damage"},
	{60, 1, {7, -1, -1, -1}, 0, "{0}% Life Stolen Per Hit"},
	{62, 1, {7, -1, -1, -1}, 0, "{0}% Mana Stolen Per Hit"},
	{73, 1, {8, -1, -1, -1}, 0, "+{0} Maximum Durability"},
	{74, 1, {6, -1, -1, -1}, 30, "Replenish Life +{0}"},
	{75, 1, {7, -1, -1, -1}, 20, "Increase Maximum Durability {0}%"},
	{76, 1, {6, -1, -1, -1}, 10, "Increase Maximum Life {0}%"},
	{77, 1, {6, -1, -1, -1}, 10, "Increase Maximum Mana {0}%"},
	{78, 1, {7, -1, -1, -1}, 0, "Attacker Takes Damage of {0}"},
	{79, 1, {9, -1, -1, -1}, 100, "{0}% Extra Gold from Monsters"},
	{80, 1, {8, -1, -1, -1}, 100, "{0}% Better Chance of Getting Magic Items"},
	{81, 1, {7, -1, -1, -1}, 0, "Knockback"},
	{85, 1, {9, -1, -1, -1}, 50, "{0}% To Experience Gained"},
	{86, 1, {7, -1, -1, -1}, 0, "+{0} Life After Each Kill"},
	{87, 1, {7, -1, -1, -1}, 0, "Reduces Prices {0}%"},
	{89, 1, {4, -1, -1, -1}, 4, "+{0} to Light Radius"},
	{93, 1, {7, -1, -1, -1}, 20, "{0}% Increased Attack Speed"},
	{96, 1, {7, -1, -1, -1}, 20, "{0}% Faster Run/Walk"},
	{99, 1, {7, -1, -1, -1}, 20, "{0}% Faster Hit Recovery"},
	{102, 1, {7, -1, -1, -1}, 20, "{0}% Faster Block Rate"},
	{105, 1, {7, -1, -1, -1}, 20, "{0}% Faster Cast Rate"},
	{108, 1, {1, -1, -1, -1}, 0, "Rest In Peace"},
	{110, 1, {8, -1, -1, -1}, 20, "Poison Length Reduced by {0}%"},
	{111, 1, {9, -1, -1, -1}, 20, "Damage +{0}"},
	{112, 1, {7, -1, -1, -1}, 0, "Hit Causes Monsters to Flee {0}%"},
	{113, 1, {7, -1, -1, -1}, 0, "Hit Blinds Target +{0}"},
	{114, 1, {6, -1, -1, -1}, 0, "{0}% Damage Taken Goes to Mana"},
	{115, 1, {1, -1, -1, -1}, 0, "Ignore Target Defense"},
	{116, 1, {7, -1, -1, -1}, 0, "{0}% Target Defense"},
	{117, 1, {7, -1, -1, -1}, 0, "Prevent Monster Heal"},
	{118, 1, {1, -1, -1, -1}, 0, "Half Freeze Duration"},
	{119, 1, {9, -1, -1, -1}, 20, "{0}% Bonus to Attack Rating"},
	{120, 1, {7, -1, -1, -1}, 128, "{0} to Monster Defense Per Hit"},
	{121, 1, {9, -1, -1, -1}, 20, "+{0}% Damage to Demons"},
	{122, 1, {9, -1, -1, -1}, 20, "+{0}% Damage to Undead"},
	{123, 1, {10, -1, -1, -1}, 128, "+{0} to Attack Rating against Demons"},
	{124, 1, {10, -1, -1, -1}, 128, "+{0} to Attack Rating against Undead"},
	{125, 1, {1, -1, -1, -1}, 0, "Throwable"},
	{127, 1, {3, -1, -1, -1}, 0, "+{0} to All Skill Levels"},
	{128, 1, {5, -1, -1, -1}, 0, "Attacker Takes Lightning Damage of {0}"},
	{134, 1, {5, -1, -1, -1}, 0, "Freezes Target +{0}"},
	{135, 1, {7, -1, -1, -1}, 0, "{0}% Chance of Open Wounds"},
	{136, 1, {7, -1, -1, -1}, 0, "{0}% Chance of Crushing Blow"},
	{137, 1, {7, -1, -1, -1}, 0, "+{0} Kick Damage"},
	{138, 1, {7, -1, -1, -1}, 0, "+{0} to Mana After Each Kill"},
	{139, 1, {7, -1, -1, -1}, 0, "+{0} Life after each Demon Kill"},
	{140, 1, {7, -1, -1, -1}, 0, "Extra Blood (Invisible)"},
	{141, 1, {7, -1, -1, -1}, 0, "{0}% Deadly Strike"},
	{142, 1, {7, -1, -1, -1}, 0, "Fire Absorb {0}%"},
	{143, 1, {7, -1, -1, -1}, 0, "+{0} Fire Absorb"},
	{144, 1, {7, -1, -1, -1}, 0, "Lightning Absorb {0}%"},
	{145, 1, {7, -1, -1, -1}, 0, "+{0} Lightning Absorb"},
	{146, 1, {7, -1, -1, -1}, 0, "Magic Absorb {0}%"},
	{147, 1, {7, -1, -1, -1}, 0, "+{0} Magic Absorb"},
	{148, 1, {7, -1, -1, -1}, 0, "Cold Absorb {0}%"},
	{149, 1, {7, -1, -1, -1}, 0, "+{0} Cold Absorb"},
	{150, 1, {7, -1, -1, -1}, 0, "Slows Target by {0}%"},
	{152, 1, {1, -1, -1, -1}, 0, "Indestructible"},
	{153, 1, {1, -1, -1, -1}, 0, "Cannot Be Frozen"},
	{154, 1, {7, -1, -1, -1}, 20, "{0}% Slower Stamina Drain"},
	{156, 1, {7, -1, -1, -1}, 0, "Piercing Attack"},
	{157, 1, {7, -1, -1, -1}, 0, "Fires Magic Arrows"},
	{158, 1, {7, -1, -1, -1}, 0, "Fires Explosive Arrows or Bolts"},
	{159, 1, {6, -1, -1, -1}, 0, "+{0} to Minimum Throw Damage"},
	{160, 1, {7, -1, -1, -1}, 0, "+{0} to Maximum Throw Damage"},
	{214, 1, {6, -1, -1, -1}, 0, "+{0} to Defense (Based on Character Level)"},
	{215, 1, {6, -1, -1, -1}, 0, "{0}% Enhanced Defense (Based on Character Level)"},
	{216, 1, {6, -1, -1, -1}, 0, "+{0} to Life (Based on Character Level)"},
	{217, 1, {6, -1, -1, -1}, 0, "+{0} to Mana (Based on Character Level)"},
	{218, 1, {6, -1, -1, -1}, 0, "+{0} to Maximum Damage (Based on Character Level)"},
	{219, 1, {6, -1, -1, -1}, 0, "{0}% Enhanced Maximum Damage (Based on Character Level)"},
	{220, 1, {6, -1, -1, -1}, 0, "+{0} to Strength (Based on Character Level)"},
	{221, 1, {6, -1, -1, -1}, 0, "+{0} to Dexterity (Based on Character Level)"},
	{222, 1, {6, -1, -1, -1}, 0, "+{0} to Energy (Based on Character Level)"},
	{223, 1, {6, -1, -1, -1}, 0, "+{0} to Vitality (Based on Character Level)"},
	{224, 1, {6, -1, -1, -1}, 0, "+{0} to Attack Rating (Based on Character Level)"},
	{225, 1, {6, -1, -1, -1}, 0, "{0}% Bonus to Attack Rating (Based on Character Level)"},
	{226, 1, {6, -1, -1, -1}, 0, "+{0} Cold Damage (Based on Character Level)"},
	{227, 1, {6, -1, -1, -1}, 0, "+{0} Fire Damage (Based on Character Level)"},
	{228, 1, {6, -1, -1, -1}, 0, "+{0} Lightning Damage (Based on Character Level)"},
	{229, 1, {6, -1, -1, -1}, 0, "+{0} Poison Damage (Based on Character Level)"},
	{230, 1, {6, -1, -1, -1}, 0, "Cold Resist +{0}% (Based on Character Level)"},
	{231, 1, {6, -1, -1, -1}, 0, "Fire Resist +{0}% (Based on Character Level)"},
	{232, 1, {6, -1, -1, -1}, 0, "Lightning Resist +{0}% (Based on Character Level)"},
	{233, 1, {6, -1, -1, -1}, 0, "Poison Resist +{0}% (Based on Character Level)"},
	{234, 1, {6, -1, -1, -1}, 0, "+{0} Cold Absorb (Based on Character Level)"},
	{235, 1, {6, -1, -1, -1}, 0, "+{0} Fire Absorb (Based on Character Level)"},
	{236, 1, {6, -1, -1, -1}, 0, "+{0} Lightning Absorb (Based on Character Level)"},
	{237, 1, {6, -1, -1, -1}, 0, "{0} Poison Absorb (Based on Character Level)"},
	{238, 1, {5, -1, -1, -1}, 0, "Attacker Takes Damage of {0} (Based on Character Level)"},
	{239, 1, {6, -1, -1, -1}, 0, "{0}% Extra Gold from Monsters (Based on Character Level)"},
	{240, 1, {6, -1, -1, -1}, 0, "{0}% Better Chance of Getting Magic Items (Based on Character Level)"},
	{241, 1, {6, -1, -1, -1}, 0, "Heal Stamina Plus {0}% (Based on Character Level)"},
	{242, 1, {6, -1, -1, -1}, 0, "+{0} Maxmium Stamina (Based on Character Level)"},
	{243, 1, {6, -1, -1, -1}, 0, "{0}% Damage to Demons (Based on Character Level)"},
	{244, 1, {6, -1, -1, -1}, 0, "{0}% Damage to Undead (Based on Character Level)"},
	{245, 1, {6, -1, -1, -1}, 0, "+{0} to Attack Rating against Demons (Based on Character Level)"},
	{246, 1, {6, -1, -1, -1}, 0, "+{0} to Attack Rating against Undead (Based on Character Level)"},
	{247, 1, {6, -1, -1, -1}, 0, "{0}% Chance of Crushing Blow (Based on Character Level)"},
	{248, 1, {6, -1, -1, -1}, 0, "{0}% Chance of Open Wounds (Based on Character Level)"},
	{249, 1, {6, -1, -1, -1}, 0, "+{0} Kick Damage (Based on Character Level)"},
	{250, 1, {6, -1, -1, -1}, 0, "{0}% to Deadly Strike (Based on Character Level)"},
	{252, 1, {6, -1, -1, -1}, 0, "Repairs 1 Durability in {0} Seconds"},
	{253, 1, {6, -1, -1, -1}, 0, "Replenishes Quantity"},
	{254, 1, {8, -1, -1, -1}, 0, "Increased Stack Size"},
	{305, 1, {8, -1, -1, -1}, 50, "{0} Pierce Cold"},
	{306, 1, {8, -1, -1, -1}, 50, "{0} Pierce Fire"},
	{307, 1, {8, -1, -1, -1}, 50, "{0} Pierce Lightning"},
	{308, 1, {8, -1, -1, -1}, 50, "{0} Pierce Poision"},
	{329, 1, {9, -1, -1, -1}, 50, "{0}% To Fire Skill Damage"},
	{330, 1, {9, -1, -1, -1}, 50, "{0}% To Lightning Skill Damage"},
	{331, 1, {9, -1, -1, -1}, 50, "{0}% To Cold Skill Damage"},
	{332, 1, {9, -1, -1, -1}, 50, "{0}% To Poison Skill Damage"},
	{333, 1, {8, -1, -1, -1}, 0, "-{0}% To Enemy Fire Resistance"},
	{334, 1, {8, -1, -1, -1}, 0, "-{0}% To Enemy Lightning Resistance"},
	{335, 1, {8, -1, -1, -1}, 0, "-{0}% To Enemy Cold Resistance"},
	{336, 1, {8, -1, -1, -1}, 0, "-{0}% To Enemy Poison Resistance"},

	// binary
	{17, 2, {9, 9, -1, -1}, 0, "+{0}% Enhanced Damage"},
	{48, 2, {8, 9, -1, -1}, 0, "Adds {0}-{1} Fire Damage"},
	{50, 2, {6, 10, -1, -1}, 0, "Adds {0}-{1} Lightning Damage"},
	{52, 2, {8, 9, -1, -1}, 0, "Adds {0}-{1} Magic Damage"},
	{83, 2, {3, 3, -1, -1}, 0, "+{1} to {0} Class Character Levels"},
	{97, 2, {9, 6, -1, -1}, 0, "+{1} To {0} (Non-class-specific) Skill Levels"},
	{98, 2, {8, 1, -1, -1}, 0, "{1}+ to {0} (Visual effect only)"},
	{107, 2, {9, 3, -1, -1}, 0, "+{1} To {0 (class-specific) Skill Levels}"},

	{126, 2, {3, 3, -1, -1}, 0, "+{1} to {0} Type of Elemental Skills"},
	{151, 2, {9, 5, -1, -1}, 0, "Level +{1} {0} When Equipped"},
	{155, 2, {10, 7, -1, -1}, 0, "{0}% Chance to Reanimate Target"},

	{109, 2, {9, 5, -1, -1}, 0, "+{1} to spell {0} (char_class Only)"},
/*
	{181, 2, {9, 5, -1, -1}, 0, "+{1} to spell {0} (char_class Only)"},
	{182, 2, {9, 5, -1, -1}, 0, "+{1} to spell {0} (char_class Only)"},
	{183, 2, {9, 5, -1, -1}, 0, "+{1} to spell {0} (char_class Only)"},
	{184, 2, {9, 5, -1, -1}, 0, "+{1} to spell {0} (char_class Only)"},
	{185, 2, {9, 5, -1, -1}, 0, "+{1} to spell {0} (char_class Only)"},
	{186, 2, {9, 5, -1, -1}, 0, "+{1} to spell {0} (char_class Only)"},
	{187, 2, {9, 5, -1, -1}, 0, "+{1} to spell {0} (char_class Only)"},
*/
	{189, 2, {10, 9, -1, -1}, 0, "+{0} to {1} Skills (char_class Only)"},
	{190, 2, {10, 9, -1, -1}, 0, "+{0} to {1} Skills (char_class Only)"},
	{191, 2, {10, 9, -1, -1}, 0, "+{0} to {1} Skills (char_class Only)"},
	{192, 2, {10, 9, -1, -1}, 0, "+{0} to {1} Skills (char_class Only)"},
	{193, 2, {10, 9, -1, -1}, 0, "+{0} to {1} Skills (char_class Only)"},

	// tenary
	{54, 3, {8, 9, 8, -1}, 0, "Adds {0}-{1} Cold Damage over {2} Seconds"},
	{57, 3, {10, 10, 9, -1}, 0, "Adds {0}-{1} Poison Damage over {2} Seconds"},

	// Ok so get this, this is quite complicated, the id 188 is for items with
	// + x to a certain skill tree, e.g. 1 + to defensive auras (paladin).
	//
	// So here's how it works, the field is 19 bits long, here's the bits for
	// the defensive auras skiller.
	//
	// 001             0000000000             011              010
	//  ^                  ^                   ^                ^
	// levels        unknown padding        class id       skill tree offset
	//
	// So in the above example, the first 3 bits 001 are the + levels (1), we'll
	// ignore the padding, the second interesting set of 3 bits is the class id.
	// Refer to the class.go for class ids, but paladin is 011 (3), and the
	// last 3 bits 010 (2) is the offset from the start of the class skill tree.
	// Refer to skills.go to find the different tree offsets. Paladin offset is
	// 9. So remember the last 3 bits 010 (2), that means the skill tree is
	// 9 + 2 = 11, aka the defensive auras tree.
	//
	// When reading the values, remember the bits are read from the right,
	// so the values will be [2 3 1], offset 2, class id 3, 1 + to skills.
	{188, 3, {3, 13, 3, -1}, 0, "+{2} to {0} Skills ({1} only)"},
	// Order is spell id, level, % chance.
	{195, 3, {6, 10, 7, -1}, 0, "{2}% Chance to Cast Level {0} Skill {1} When you attack"},
	{196, 3, {6, 10, 7, -1}, 0, "{2}% Chance to Cast Level {0} Skill {1} When you kill"},
	{197, 3, {6, 10, 7, -1}, 0, "{2}% Chance to Cast Level {0} Skill {1} When you die"},
	{198, 3, {6, 10, 7, -1}, 0, "{2}% Chance to Cast Level {0} Skill {1} On Striking"},
	{199, 3, {6, 10, 7, -1}, 0, "{2}% Chance to Cast Level {0} Skill {1} On Level Up"},
	{201, 3, {6, 10, 7, -1}, 0, "{2}% Chance to Cast Level {0} Skill {1} When Struck"},

	// quad
	{204, 4, {6, 10, 8, 8}, 0, "Level {0} Skill {1} ({2}/{3} Charges)"}
};

void copyProperty(MagicProperty &src, MagicProperty &dest)
{
	dest.bias = src.bias;
	dest.code = src.code;
	dest.desc = src.desc;
	dest.nCnt = src.nCnt;
	for (int i = 0; i < 4; i++)
	{
		dest.bits[i] = src.bits[i];
	}
}

std::string propertyToString(MagicProperty &magic)
{
	std::string result = "";
	std::stringstream ss("");
	ss << "\t"
	   << "{";
	ss << magic.code << ", ";
	ss << magic.nCnt << ", ";
	ss << "{";
	for (int i = 0; i < 4; i++)
	{
		int v = -1;
		if (i < magic.nCnt)
		{
			v = magic.bits[i];
		}
		ss << v;
		if (i < 3)
		{
			ss << ", ";
		}
	}
	ss << "}, ";
	ss << magic.bias << ", ";
	if (magic.desc.length() > 0 && magic.desc[0] != '\"') {
		ss << "\"";
	}
	ss << magic.desc;
	if (magic.desc.length() > 0 && magic.desc[magic.desc.length() - 1] != '\"') {
		ss << "\"";
	}
	ss << "},";
	return ss.str();
}

void initMagics()
{
	for (int i = 0; i < 512; i++)
	{
		indexedMagics[i].nCnt = 0;
	}
	for (int i = 0; i < 187; i++)
	{
		int j = existMagics[i].code;
		copyProperty(existMagics[i], indexedMagics[j]);
	}
	std::cout << indexedMagics[0].nCnt << " " << indexedMagics[0].desc << " " << indexedMagics[0].code << std::endl;
}

struct UStatsParam
{
	std::string desc;
	std::string length;
	std::string base;
	std::string type;
};

class UStatsEntry
{
public:
	std::vector<std::string> tokens;

	std::string head;
	int nParams;
	int id;
	std::string name;
	std::string abbriev;
	std::vector<UStatsParam> params;

	void init()
	{
		assert(tokens.size() >= 5);
		head = tokens[0];
		id = std::atoi(tokens[1].c_str());
		abbriev = tokens[2];
		name = tokens[3];
		nParams = 0;
		if (tokens[4] != "")
		{
			nParams = std::atoi(tokens[4].c_str());
		}

		int idx = 5;
		if (nParams > 0)
		{
			for (int i = 0; i < nParams; i++)
			{
				if (i == 0)
				{
					UStatsParam param;
					param.base = tokens[idx + 0];
					param.length = tokens[idx + 1];
					param.desc = tokens[idx + 2];
					params.push_back(param);
					idx += 3;
				}
				else
				{
					UStatsParam param;
					param.type = tokens[idx + 0];
					param.base = tokens[idx + 1];
					param.length = tokens[idx + 2];
					param.desc = tokens[idx + 3];
					params.push_back(param);
					idx += 4;
				}
			}
		}
	}

	void toMagicProp(MagicProperty &prop)
	{
		prop.code = id;
		prop.nCnt = nParams;
		prop.desc = name;
		for (int i = 0; i < nParams; i++)
		{
			prop.bits[i] = std::atoi(params[i].length.c_str());
		}
	}
};

void string_split(std::string s, std::string delimiter, std::vector<std::string> &tokens)
{
	size_t pos = 0;
	std::string token;
	while ((pos = s.find(delimiter)) != std::string::npos)
	{
		token = s.substr(0, pos);
		tokens.push_back(token);
		s.erase(0, pos + delimiter.length());
	}
}

void readuStats()
{
	std::ifstream inf;

	inf.open("./uStats.txt", std::ios::binary);

	// vector<MagicProperty> props;
	// MagicProperty props[512];
	for (int i = 0; i < 512; i++)
	{
		ustatsMagics[i].nCnt = 0;
	}

	int cnt = 0;
	int first = 0;
	while (!inf.eof())
	{
		std::string line;
		std::getline(inf, line);

		if (line.length() <= 0)
		{
			continue;
		}

		first++;
		if (first <= 1)
		{
			continue; // column name row
		}

		UStatsEntry row;
		string_split(line, "\t", row.tokens);

		row.init();
		if (row.nParams > 0)
		{
			cnt++;
			std::cout << row.name << " len: = " << row.nParams << std::endl;
			// prop
			MagicProperty p;
			row.toMagicProp(p);
			row.toMagicProp(ustatsMagics[p.code]);
		}
	}

	std::cout << "cnt = " << cnt << std::endl;
	std::cout << "done read ustats" << std::endl;
	inf.close();

	////
	int paramCnt[5];
	for (int i = 0; i < 5; i++)
	{
		paramCnt[i] = 0;
	}
	for (int i = 0; i < 370; i++)
	{
		if (indexedMagics[i].nCnt != ustatsMagics[i].nCnt)
		{
			std::cout << i << ": [" << indexedMagics[i].desc << "] [" << ustatsMagics[i].desc << "] ";
			std::cout << indexedMagics[i].nCnt << " " << ustatsMagics[i].nCnt << std::endl;
		}
		if (ustatsMagics[i].nCnt > 0)
		{
			paramCnt[ustatsMagics[i].nCnt]++;
			std::cout << propertyToString(ustatsMagics[i]) << std::endl;
		}
	}
	for (int i = 1; i < 5; i++)
	{
		std::cout << "=====" << std::endl;
		std::cout << "cnt[" << i << "] = " << paramCnt[i] << std::endl;
		for (int j = 0; j < 370; j++)
		{
			if (ustatsMagics[j].nCnt == i)
			{
				std::cout << ustatsMagics[j].code << ": " << ustatsMagics[j].desc << std::endl;
			}
		}
	}
	////
	for (int i = 1; i < 5; i++)
	{
		for (int j = 0; j < 370; j++)
		{
			if (ustatsMagics[j].nCnt == i)
			{
				std::cout << propertyToString(ustatsMagics[j]) << std::endl;
			}
		}
	}
}

// valid ustats magics
MagicProperty validUstatsMagics[] = {
	{0, 1, {8, -1, -1, -1}, 0, "Strength"},
	{1, 1, {7, -1, -1, -1}, 0, "Energy"},
	{2, 1, {7, -1, -1, -1}, 0, "Dexterity"},
	{3, 1, {7, -1, -1, -1}, 0, "Vitality"},
	{7, 1, {9, -1, -1, -1}, 0, "Max Life"},
	{9, 1, {8, -1, -1, -1}, 0, "Max Mana"},
	{11, 1, {8, -1, -1, -1}, 0, "Max Stamina"},
	{16, 1, {9, -1, -1, -1}, 0, "Enhanced Defense %"},
	{18, 1, {9, -1, -1, -1}, 0, "Enchanced Min Dmg %"},
	{19, 1, {10, -1, -1, -1}, 0, "Attack Rating"},
	{20, 1, {6, -1, -1, -1}, 0, "Chance of Blocking %"},
	{21, 1, {6, -1, -1, -1}, 0, "Min 1-handed Dmg"},
	{22, 1, {7, -1, -1, -1}, 0, "Max 1-handed Dmg"},
	{23, 1, {6, -1, -1, -1}, 0, "Min 2-handed Dmg"},
	{24, 1, {7, -1, -1, -1}, 0, "Max 2-handed Dmg"},
	//{25, 1, {8, -1, -1, -1}, 0, "Damage % nv"},
	//{26, 1, {8, -1, -1, -1}, 0, "Regenerate Mana % nv"},
	{27, 1, {8, -1, -1, -1}, 0, "Regenerate Mana Plus %"},
	{28, 1, {8, -1, -1, -1}, 0, "Heal Stemina Plus %"},
	{31, 1, {11, -1, -1, -1}, 0, "Defense"},
	{32, 1, {9, -1, -1, -1}, 0, "Def vs Missile"},
	{33, 1, {8, -1, -1, -1}, 0, "Def vs Melee"},
	{34, 1, {6, -1, -1, -1}, 0, "Damage Reduced By"},
	{35, 1, {6, -1, -1, -1}, 0, "Magic Dmg Reduced By"},
	{36, 1, {8, -1, -1, -1}, 0, "Damage Reduced By %"},
	{37, 1, {8, -1, -1, -1}, 0, "Magic Resistance %"},
	{38, 1, {5, -1, -1, -1}, 0, "Max Magic Resistance %"},
	{39, 1, {8, -1, -1, -1}, 0, "Fire Resistance %"},
	{40, 1, {5, -1, -1, -1}, 0, "Max Fire Resistance %"},
	{41, 1, {8, -1, -1, -1}, 0, "Lightning Resistance %"},
	{42, 1, {5, -1, -1, -1}, 0, "Max Lightning Resistance %"},
	{43, 1, {8, -1, -1, -1}, 0, "Cold Resistance %"},
	{44, 1, {5, -1, -1, -1}, 0, "Max Cold Resistance %"},
	{45, 1, {8, -1, -1, -1}, 0, "Poison Resistance %"},
	{46, 1, {5, -1, -1, -1}, 0, "Max Poison Resistance %"},
	{49, 1, {9, -1, -1, -1}, 0, "Max Fire Damage"},
	//  {51, 1, {10, -1, -1, -1}, 0, "Max Lightning Dmg"},
	{53, 1, {9, -1, -1, -1}, 0, "Max Magic Damage"},
	//  {55, 1, {9, -1, -1, -1}, 0, "Max Cold Damage"},
	{56, 1, {8, -1, -1, -1}, 0, "Cold Length"},
	{58, 1, {10, -1, -1, -1}, 0, "Max Poison Dmg"},
	{59, 1, {9, -1, -1, -1}, 0, "Poison Length"},
	{60, 1, {7, -1, -1, -1}, 0, "Life Stolen Per Hit Min"},
	{62, 1, {7, -1, -1, -1}, 0, "Mana Stolen Per Hit Min"},
	{67, 1, {7, -1, -1, -1}, 0, "Run/Walk Speed % nv"},
	{68, 1, {7, -1, -1, -1}, 0, "Attack Speed % nv"},
	//  {71, 1, {8, -1, -1, -1}, 0, "value"},
	//  {72, 1, {9, -1, -1, -1}, 0, "Durabilty"},
	{73, 1, {8, -1, -1, -1}, 0, "Max Durability"},
	{74, 1, {6, -1, -1, -1}, 0, "Replenish Life"},
	{75, 1, {7, -1, -1, -1}, 0, "Max Durability %"},
	{76, 1, {6, -1, -1, -1}, 0, "Life %"},
	{77, 1, {6, -1, -1, -1}, 0, "Mana %"},
	{78, 1, {7, -1, -1, -1}, 0, "Attacker Takes Damage Of"},
	{79, 1, {9, -1, -1, -1}, 0, "Extra Gold From Monsters %"},
	{80, 1, {8, -1, -1, -1}, 0, "Chance Of Getting Magic Items %"},
	{81, 1, {7, -1, -1, -1}, 0, "Knock Back"},
	{82, 1, {9, -1, -1, -1}, 0, "Time Duration"},
	{85, 1, {9, -1, -1, -1}, 0, "Add experience"},
	{86, 1, {7, -1, -1, -1}, 0, "Heal after kill"},
	{87, 1, {7, -1, -1, -1}, 0, "Reduced prices"},
	//  {88, 1, {1, -1, -1, -1}, 0, "Double Herb Duration"},
	{89, 1, {4, -1, -1, -1}, 0, "Light Radius"},
	//  {90, 1, {24, -1, -1, -1}, 0, "Light Color nv"},
	{91, 1, {8, -1, -1, -1}, 0, "Requirements %"},
	{92, 1, {7, -1, -1, -1}, 0, "Level Require"},
	{93, 1, {7, -1, -1, -1}, 0, "Increased Attack Speed"},
	{94, 1, {7, -1, -1, -1}, 0, "Level Require %"},
	{96, 1, {7, -1, -1, -1}, 0, "Faster Run/Walk"},
	{99, 1, {7, -1, -1, -1}, 0, "Faster Hit Recovery Rate"},
	{102, 1, {7, -1, -1, -1}, 0, "Faster Block Rate"},
	{105, 1, {7, -1, -1, -1}, 0, "Faster Cast Rate"},
	{108, 1, {1, -1, -1, -1}, 0, "Rest in peace"},
	//  {109, 1, {9, -1, -1, -1}, 0, "Curse resistance"},
	{110, 1, {8, -1, -1, -1}, 0, "Poison Length Reduced By %"},
	{111, 1, {9, -1, -1, -1}, 0, "Damage"},
	{112, 1, {7, -1, -1, -1}, 0, "Hit Causes Monster To Flee %"},
	{113, 1, {7, -1, -1, -1}, 0, "Hit Blinds Target"},
	{114, 1, {6, -1, -1, -1}, 0, "Damage To Mana %"},
	{115, 1, {1, -1, -1, -1}, 0, "Ignore Target Defense"},
	{116, 1, {7, -1, -1, -1}, 0, "Target Defense %"},
	{117, 1, {7, -1, -1, -1}, 0, "Prevent Monster Heal"},
	{118, 1, {1, -1, -1, -1}, 0, "Half Freeze Duration"},
	{119, 1, {9, -1, -1, -1}, 0, "Bonus To Attack Rating %"},
	{120, 1, {7, -1, -1, -1}, 0, "Reduce Monster Defense per Hit"},
	{121, 1, {9, -1, -1, -1}, 0, "Damage To Demons %"},
	{122, 1, {9, -1, -1, -1}, 0, "Damage To Undead %"},
	{123, 1, {10, -1, -1, -1}, 0, "Attack Rating Against Demons"},
	{124, 1, {10, -1, -1, -1}, 0, "Attack Rating Against Undead"},
	{125, 1, {1, -1, -1, -1}, 0, "Throwable"},
	{127, 1, {3, -1, -1, -1}, 0, "All Skill Levels"},
	{128, 1, {5, -1, -1, -1}, 0, "Attacker Takes Lightning Dmg Of"},
	{134, 1, {5, -1, -1, -1}, 0, "Attack Freezes Target"},
	{135, 1, {7, -1, -1, -1}, 0, "Chance of Open Wounds"},
	{136, 1, {7, -1, -1, -1}, 0, "Chance of Crushing Blow"},
	{137, 1, {7, -1, -1, -1}, 0, "Kick Damage"},
	{138, 1, {7, -1, -1, -1}, 0, "Mana After Each Kill"},
	{139, 1, {7, -1, -1, -1}, 0, "Life After Each Demon Kill"},
	{140, 1, {7, -1, -1, -1}, 0, "Extra Blood"},
	{141, 1, {7, -1, -1, -1}, 0, "Chance of Deadly Strike"},
	{142, 1, {7, -1, -1, -1}, 0, "Fire Absorbs %"},
	{143, 1, {7, -1, -1, -1}, 0, "Fire Absorbs"},
	{144, 1, {7, -1, -1, -1}, 0, "Lightning Absorbs %"},
	{145, 1, {7, -1, -1, -1}, 0, "Lightning Absorbs"},
	{146, 1, {7, -1, -1, -1}, 0, "Magic Absorbs %"},
	{147, 1, {7, -1, -1, -1}, 0, "Magic Absorbs"},
	{148, 1, {7, -1, -1, -1}, 0, "Cold Absorbs %"},
	{149, 1, {7, -1, -1, -1}, 0, "Cold Absorbs"},
	{150, 1, {7, -1, -1, -1}, 0, "Slows Target By %"},
	{152, 1, {1, -1, -1, -1}, 0, "Indestructible"},
	{153, 1, {1, -1, -1, -1}, 0, "Cannot be Frozen"},
	{154, 1, {7, -1, -1, -1}, 0, "Slower Stamina Drain %"},
	{156, 1, {7, -1, -1, -1}, 0, "Pierce Attack %"},
	{157, 1, {7, -1, -1, -1}, 0, "Fire Magic Arrows or Bolts"},
	{158, 1, {7, -1, -1, -1}, 0, "Fire Explosive Arrows or Bolts"},
	{159, 1, {6, -1, -1, -1}, 0, "Min Throw Dmg nv"},
	{160, 1, {7, -1, -1, -1}, 0, "Max Throw Dmg nv"},
	//{181, 1, {3, -1, -1, -1}, 0, "fade"},
	{194, 1, {4, -1, -1, -1}, 0, "Increased Sockets"},
	{214, 1, {6, -1, -1, -1}, 0, "Defense (on Lvl)"},
	{215, 1, {6, -1, -1, -1}, 0, "Enhanced Defense (on Lvl)"},
	{216, 1, {6, -1, -1, -1}, 0, "Life (on Lvl)"},
	{217, 1, {6, -1, -1, -1}, 0, "Mana (on Lvl)"},
	{218, 1, {6, -1, -1, -1}, 0, "Maximum Damage (on Lvl)"},
	{219, 1, {6, -1, -1, -1}, 0, "Enhanced MaxDmg (on Lvl)"},
	{220, 1, {6, -1, -1, -1}, 0, "Strength (on Lvl)"},
	{221, 1, {6, -1, -1, -1}, 0, "Dexterity (on Lvl)"},
	{222, 1, {6, -1, -1, -1}, 0, "Energy (on Lvl)"},
	{223, 1, {6, -1, -1, -1}, 0, "Vitality (on Lvl)"},
	{224, 1, {6, -1, -1, -1}, 0, "Att Rating (on Lvl)"},
	{225, 1, {6, -1, -1, -1}, 0, "Bonus to Att Rating % (on Lvl)"},
	{226, 1, {6, -1, -1, -1}, 0, "Maximum Cold Dmg (on Lvl)"},
	{227, 1, {6, -1, -1, -1}, 0, "Maximum Fire Dmg (on Lvl)"},
	{228, 1, {6, -1, -1, -1}, 0, "Maximum Lightning Dmg (on Lvl)"},
	{229, 1, {6, -1, -1, -1}, 0, "Maximum Poison Dmg (on Lvl)"},
	{230, 1, {6, -1, -1, -1}, 0, "Cold Resistance % (on Lvl)"},
	{231, 1, {6, -1, -1, -1}, 0, "Fire Resistance % (on Lvl)"},
	{232, 1, {6, -1, -1, -1}, 0, "Lightning Resistance % (on Lvl)"},
	{233, 1, {6, -1, -1, -1}, 0, "Poison Resistance % (on Lvl)"},
	{234, 1, {6, -1, -1, -1}, 0, "Absorbs Cold Damage (on Lvl)"},
	{235, 1, {6, -1, -1, -1}, 0, "Absorbs Fire Damage (on Lvl)"},
	{236, 1, {6, -1, -1, -1}, 0, "Absorbs Lightning Damage (on Lvl)"},
	{237, 1, {6, -1, -1, -1}, 0, "Absorbs Poison (per lvl)"},
	{238, 1, {5, -1, -1, -1}, 0, "Attacker Takes Damage of (on Lvl)"},
	{239, 1, {6, -1, -1, -1}, 0, "Extra Gold From Monsters % (on Lvl)"},
	{240, 1, {6, -1, -1, -1}, 0, "Chance of Getting Magic Items % (on Lvl)"},
	{241, 1, {6, -1, -1, -1}, 0, "Heal Stamina Plus % (on Lvl)"},
	{242, 1, {6, -1, -1, -1}, 0, "Maximum Stamina (on Lvl)"},
	{243, 1, {6, -1, -1, -1}, 0, "Damage to Demons % (on Lvl)"},
	{244, 1, {6, -1, -1, -1}, 0, "Damage to Undead % (on Lvl)"},
	{245, 1, {6, -1, -1, -1}, 0, "Att Rating against Demons (on Lvl)"},
	{246, 1, {6, -1, -1, -1}, 0, "Att Rating against Undead (on Lvl)"},
	{247, 1, {6, -1, -1, -1}, 0, "Chance of Crushing Blow (on Lvl)"},
	{248, 1, {6, -1, -1, -1}, 0, "Chance of Open Wounds (on Lvl)"},
	{249, 1, {6, -1, -1, -1}, 0, "Kick Damage (on Lvl)"},
	{250, 1, {6, -1, -1, -1}, 0, "Chance of Deadly Strike (on Lvl)"},
	{252, 1, {6, -1, -1, -1}, 0, "Repair 1 Durability In Seconds"},
	{253, 1, {6, -1, -1, -1}, 0, "Replenish 1 Quantity In Seconds"},
	{254, 1, {8, -1, -1, -1}, 0, "Increased Stack Size"},
	{305, 1, {8, -1, -1, -1}, 0, "item_pierce_cold"},
	{306, 1, {8, -1, -1, -1}, 0, "item_pierce_fire"},
	{307, 1, {8, -1, -1, -1}, 0, "item_pierce_ltng"},
	{308, 1, {8, -1, -1, -1}, 0, "item_pierce_pois"},
	//  {324, 1, {6, -1, -1, -1}, 0, "item_extra_charges"},
	{329, 1, {9, -1, -1, -1}, 0, "passive_fire_mastery"},
	{330, 1, {9, -1, -1, -1}, 0, "passive_ltng_mastery"},
	{331, 1, {9, -1, -1, -1}, 0, "passive_cold_mastery"},
	{332, 1, {9, -1, -1, -1}, 0, "passive_pois_mastery"},
	{333, 1, {8, -1, -1, -1}, 0, "passive_fire_pierce"},
	{334, 1, {8, -1, -1, -1}, 0, "passive_ltng_pierce"},
	{335, 1, {8, -1, -1, -1}, 0, "passive_cold_pierce"},
	{336, 1, {8, -1, -1, -1}, 0, "passive_pois_pierce"},
	/*
	  {337, 1, {8, -1, -1, -1}, 0, "passive_critical_strike"},
	  {338, 1, {7, -1, -1, -1}, 0, "passive_dodge"},
	  {339, 1, {7, -1, -1, -1}, 0, "passive_avoid"},
	  {340, 1, {7, -1, -1, -1}, 0, "passive_evade"},
	  {341, 1, {8, -1, -1, -1}, 0, "passive_warmth"},
	  {342, 1, {8, -1, -1, -1}, 0, "passive_mastery_melee_th"},
	  {343, 1, {8, -1, -1, -1}, 0, "passive_mastery_melee_dmg"},
	  {344, 1, {8, -1, -1, -1}, 0, "passive_mastery_melee_crit"},
	  {345, 1, {8, -1, -1, -1}, 0, "passive_mastery_throw_th"},
	  {346, 1, {8, -1, -1, -1}, 0, "passive_mastery_throw_dmg"},
	  {347, 1, {8, -1, -1, -1}, 0, "passive_mastery_throw_crit"},
	  {348, 1, {8, -1, -1, -1}, 0, "passive_weaponblock"},
	  {349, 1, {8, -1, -1, -1}, 0, "passive_summon_resist"},
	*/
	{356, 1, {2, -1, -1, -1}, 0, "questitemdifficulty"},
	//  {357, 1, {9, -1, -1, -1}, 0, "passive_mag_mastery"},
	//  {358, 1, {8, -1, -1, -1}, 0, "passive_mag_pierce"},

	// 2
	{17, 2, {9, 9, -1, -1}, 0, "Enchanced Damage %"},
	{48, 2, {8, 9, -1, -1}, 0, "Fire Damage"},
	{50, 2, {6, 10, -1, -1}, 0, "Lightning Damage"},
	{52, 2, {8, 9, -1, -1}, 0, "Magic Damage"},
	{83, 2, {3, 3, -1, -1}, 0, "Add Class Skill"},
	{97, 2, {9, 6, -1, -1}, 0, "Non Class skill"},
	//{98, 2, {8, 1, -1, -1}, 0, "state"},
	{107, 2, {9, 3, -1, -1}, 0, "Single Skill"},
	{126, 2, {3, 3, -1, -1}, 0, "Elemental Skill"},
	{151, 2, {9, 5, -1, -1}, 0, "Aura"},
	{155, 2, {10, 7, -1, -1}, 0, "ReAnimate"},

	//{179, 2, {10, 9, -1, -1}, 0, "Attack Vs Monster"},
	//{180, 2, {10, 9, -1, -1}, 0, "Damage Vs Monster"},

	// 3
	{54, 3, {8, 9, 8, -1}, 0, "Cold Damage"},
	{57, 3, {10, 10, 9, -1}, 0, "Poison Damage"},
	{188, 3, {3, 13, 3, -1}, 0, "Add Skill Tab"},
	{195, 3, {6, 10, 7, -1}, 0, "Skill On Attack"},
	{196, 3, {6, 10, 7, -1}, 0, "Skill On Kill"},
	{197, 3, {6, 10, 7, -1}, 0, "Skill On Death"},
	{198, 3, {6, 10, 7, -1}, 0, "Skill On Hit"},
	{199, 3, {6, 10, 7, -1}, 0, "Skill On Levelup"},
	{201, 3, {6, 10, 7, -1}, 0, "Skill On Get Hit"},

	// 4
	{204, 4, {6, 10, 8, 8}, 0, "Charged Skill"}
};

MagicProperty hiringBowMagics[] = {
	{0, 1, {8, -1, -1, -1}, 0, "Strength"},
	{1, 1, {7, -1, -1, -1}, 0, "Energy"},
	{2, 1, {7, -1, -1, -1}, 0, "Dexterity"},
	{7, 1, {9, -1, -1, -1}, 0, "Max Life"},
	{16, 1, {9, -1, -1, -1}, 0, "Enhanced Defense %"},
	{18, 1, {9, -1, -1, -1}, 0, "Enchanced Min Dmg %"},
	{19, 1, {10, -1, -1, -1}, 0, "Attack Rating"},
	{21, 1, {6, -1, -1, -1}, 0, "Min 1-handed Dmg"},
	{22, 1, {7, -1, -1, -1}, 0, "Max 1-handed Dmg"},
	{23, 1, {6, -1, -1, -1}, 0, "Min 2-handed Dmg"},
	{24, 1, {7, -1, -1, -1}, 0, "Max 2-handed Dmg"},
	{25, 1, {8, -1, -1, -1}, 0, "Damage % nv"},
	{31, 1, {11, -1, -1, -1}, 0, "Defense"},
	{32, 1, {9, -1, -1, -1}, 0, "Def vs Missile"},
	{33, 1, {8, -1, -1, -1}, 0, "Def vs Melee"},
	{34, 1, {6, -1, -1, -1}, 0, "Damage Reduced By"},
	{35, 1, {6, -1, -1, -1}, 0, "Magic Dmg Reduced By"},
	{36, 1, {8, -1, -1, -1}, 0, "Damage Reduced By %"},
	{96, 1, {7, -1, -1, -1}, 0, "Faster Run/Walk"},
	{111, 1, {9, -1, -1, -1}, 0, "Damage"},
	{114, 1, {6, -1, -1, -1}, 0, "Damage To Mana %"},
	{218, 1, {6, -1, -1, -1}, 0, "Maximum Damage (on Lvl)"},
	{219, 1, {6, -1, -1, -1}, 0, "Enhanced MaxDmg (on Lvl)"},

	// 2
	{17, 2, {9, 9, -1, -1}, 0, "Enchanced Damage %"},
	{48, 2, {8, 9, -1, -1}, 0, "Fire Damage"},
	{50, 2, {6, 10, -1, -1}, 0, "Lightning Damage"},
	{52, 2, {8, 9, -1, -1}, 0, "Magic Damage"},

	// 3
	{54, 3, {8, 9, 8, -1}, 0, "Cold Damage"},
	{57, 3, {10, 10, 9, -1}, 0, "Poison Damage"},

};

struct AtmaParamType
{
	int bits;
	std::string type;
	std::string unit;
	std::string description;
};

class AtmaEntry
{
public:
	int id;
	int nParams;
	int bias;
	std::string name;
	std::string abbriev;
	std::string formatStr1;
	std::string formatStr2;	
	AtmaParamType params[4];

	void parseTokens(std::map<std::string, std::string> &csv) {
		id = -1;
		nParams = 0;
		abbriev = "";
		formatStr1 = "";
		formatStr2 = "";

		// parseing
		id = std::stoi(getOrDefault(csv, "Id", "-1"));

		if (id == -1) {
			// invalid
			return;
		}

		name = csv["Description"];
		nParams = std::stoi(getOrDefault(csv, "numFields", "0"));
		abbriev = csv["Code"];
		bias = std::stoi(getOrDefault(csv, "bias", "0"));
		std::cout << "bias = " << bias << std::endl;
		formatStr1 = csv["fmtString1"];
		formatStr2 = csv["fmtString2"];

		params[0].bits = std::stoi(getOrDefault(csv, "bits1", "0"));
		params[0].type = csv["type1"];
		params[0].unit = csv["units1"];
		params[0].description = csv["desc1"];

		params[1].bits =std::stoi(getOrDefault(csv, "bits2", "0"));
		params[1].type = csv["type2"];
		params[1].unit = csv["units2"];
		params[1].description = csv["desc2"];

		params[2].bits =std::stoi(getOrDefault(csv, "bits3", "0"));
		params[2].type = csv["type3"];
		params[2].unit = csv["units3"];
		params[2].description = csv["desc3"];

		params[3].bits = std::stoi(getOrDefault(csv, "bits4", "0"));
		params[3].type = csv["type4"];
		params[3].unit = csv["units4"];
		params[3].description = csv["desc4"];
	}

	std::string getOrDefault(std::map<std::string, std::string> &csv, 
	std::string key, std::string defValue) {
		if (csv.count(key) > 0) {
			return csv[key];
		} else {
			return defValue;
		}

	}

	void toMagicProp(MagicProperty &prop)
	{
		prop.code = id;
		prop.nCnt = nParams;
		prop.desc = formatStr1; //name;
		prop.bias = bias;
		for (int i = 0; i < nParams; i++)
		{
			prop.bits[i] = params[i].bits;
		}
	}
};

void readAtmaProperties()
{
	std::ifstream inf;
	inf.open("./ATMA_properties.txt", std::ios::binary | std::ios::in);

	std::vector<AtmaEntry> entries;
	int cnt = 0;
	int first = 0;
	std::vector<std::string> header;
	while (!inf.eof())
	{
		std::string line;
		std::getline(inf, line);

		if (line.length() <= 0) {
			continue;
		}

		first++;
		if (first <= 1) {
			string_split(line, "\t", header);
			std::cout << "Header length = " << header.size() << std::endl;
			continue; // column name row
		}

		std::vector<std::string> tokens;
		string_split(line, "\t", tokens);

		std::map<std::string, std::string> csvMapping;
		for (int i = 0; i < tokens.size(); i++) {
			if (tokens[i] != "") {
				csvMapping.insert(std::make_pair(header[i], tokens[i]));
				//std::cout << header[i] << ":" << tokens[i] << std::endl;
			}
		}

		std::string propCode = csvMapping["Id"];
		if (tokens.size() == 0 || propCode == "") {
			continue;
		}
		
		AtmaEntry entry;
		entry.parseTokens(csvMapping);
		if (entry.nParams > 0) {
			cnt++;
			entries.push_back(entry);
			std::cout << entry.id << " " << entry.name << " " << entry.formatStr2 << std::endl;
		}
	}

	std::cout << "cnt = " << cnt << std::endl;
	std::cout << "done read ATMA_properties" << std::endl;
	inf.close();

	for (int i = 1; i < 5; i++)
	{
		std::cout << "// " << i << " =====" << std::endl;
		for (int j = 0; j < entries.size(); j++)
		{
			if (entries[j].nParams == i)
			{
				MagicProperty magicProp;
				entries[j].toMagicProp(magicProp);
				std::cout << propertyToString(magicProp) << std::endl;
			}
		}
	}
}

MagicProperty atmaMagics[] = {
// 1 =====
	{0, 1, {8, -1, -1, -1}, 32, "%+d to Strength"},
	{1, 1, {7, -1, -1, -1}, 32, "%+d to Energy"},
	{2, 1, {7, -1, -1, -1}, 32, "%+d to Dexterity"},
	{3, 1, {7, -1, -1, -1}, 32, "%+d to Vitality"},
	{7, 1, {9, -1, -1, -1}, 32, "%+d to Life"},
	{9, 1, {8, -1, -1, -1}, 32, "%+d to Mana"},
	{11, 1, {8, -1, -1, -1}, 32, "%+d to Maximum Stamina"},
	{16, 1, {9, -1, -1, -1}, 0, "%+d%% Enhanced Defense"},
	{18, 1, {9, -1, -1, -1}, 0, "%+d%% Enhanced Minimum Damage"},
	{19, 1, {10, -1, -1, -1}, 0, "%+d to Attack Rating"},
	{20, 1, {6, -1, -1, -1}, 0, "%+d%% Increased Chance of Blocking"},
	{21, 1, {6, -1, -1, -1}, 0, "%+d to Minimum Damage"},
	{22, 1, {7, -1, -1, -1}, 0, "%+d to Maximum Damage"},
	{23, 1, {6, -1, -1, -1}, 0, "%+d to Minimum Damage"},
	{24, 1, {7, -1, -1, -1}, 0, "%+d to Maximum Damage"},
	{27, 1, {8, -1, -1, -1}, 0, "Regenerate Mana %d%%"},
	{28, 1, {8, -1, -1, -1}, 0, "Heal Stamina Plus %d%%"},
	{31, 1, {11, -1, -1, -1}, 10, "%+d Defense"},
	{32, 1, {9, -1, -1, -1}, 0, "%+d Defense vs. Missile"},
	{33, 1, {8, -1, -1, -1}, 0, "%+d Defense vs. Melee"},
	{34, 1, {6, -1, -1, -1}, 0, "Damage Reduced by %d"},
	{35, 1, {6, -1, -1, -1}, 0, "Magic Damage Reduced by %d"},
	{36, 1, {8, -1, -1, -1}, 0, "Damage Reduced by %d%%"},
	{37, 1, {8, -1, -1, -1}, 0, "Magic Resist %+d%%"},
	{38, 1, {5, -1, -1, -1}, 0, "%+d%% to Maximum Magic Resist"},
	{39, 1, {8, -1, -1, -1}, 50, "Fire Resist %+d%%"},
	{40, 1, {5, -1, -1, -1}, 0, "%+d%% to Maximum Fire Resist"},
	{41, 1, {8, -1, -1, -1}, 50, "Lightning Resist %+d%%"},
	{42, 1, {5, -1, -1, -1}, 0, "%+d%% to Maximum Lightning Resist"},
	{43, 1, {8, -1, -1, -1}, 50, "Cold Resist %+d%%"},
	{44, 1, {5, -1, -1, -1}, 0, "%+d%% to Maximum Cold Resist"},
	{45, 1, {8, -1, -1, -1}, 50, "Poison Resist %+d%%"},
	{46, 1, {5, -1, -1, -1}, 0, "%+d%% to Maximum Poison Resist"},
	{49, 1, {9, -1, -1, -1}, 0, "%+d to Maximum Fire Damage"},
	{53, 1, {9, -1, -1, -1}, 0, "%d maximum magic damage"},
	{56, 1, {8, -1, -1, -1}, 0, "%d seconds cold duration"},
	{58, 1, {10, -1, -1, -1}, 0, "%d maximum poison damage per second"},
	{59, 1, {9, -1, -1, -1}, 0, "%d seconds poison duration"},
	{60, 1, {7, -1, -1, -1}, 0, "%d%% Life stolen per hit"},
	{62, 1, {7, -1, -1, -1}, 0, "%d%% Mana stolen per hit"},
	{67, 1, {7, -1, -1, -1}, 30, "%d%% Faster Run/Walk"},
	{68, 1, {7, -1, -1, -1}, 30, "%d%% Increased Attack Speed"},
	{73, 1, {8, -1, -1, -1}, 0, "%+d Maximum Durability"},
	{74, 1, {6, -1, -1, -1}, 30, "Replenish Life %+d"},
	{75, 1, {7, -1, -1, -1}, 20, "Increase Maximum Durability %d%%"},
	{76, 1, {6, -1, -1, -1}, 10, "Increase Maximum Life %d%%"},
	{77, 1, {6, -1, -1, -1}, 10, "Increase Maximum Mana %d%%"},
	{78, 1, {7, -1, -1, -1}, 0, "Attacker Takes Damage of %d"},
	{79, 1, {9, -1, -1, -1}, 100, "%d%% Extra Gold from Monsters"},
	{80, 1, {8, -1, -1, -1}, 100, "%d%% Better Chance of Getting Magic Items"},
	{81, 1, {7, -1, -1, -1}, 0, "Knockback"},
	{82, 1, {9, -1, -1, -1}, 20, "%d seconds duration"},
	{85, 1, {9, -1, -1, -1}, 50, "%+d%% to Experience Gained"},
	{86, 1, {7, -1, -1, -1}, 0, "%+d Life after each Kill"},
	{87, 1, {7, -1, -1, -1}, 0, "Reduces All Vendor Prices %d%%"},
	{89, 1, {4, -1, -1, -1}, 4, "%+d to Light Radius"},
	{91, 1, {8, -1, -1, -1}, 100, "Requirements %+d%%"},
	{92, 1, {7, -1, -1, -1}, 0, "Required Level %+d"},
	{93, 1, {7, -1, -1, -1}, 20, "%d%% Increased Attack Speed"},
	{94, 1, {7, -1, -1, -1}, 64, "Required Level %d%%"},
	{96, 1, {7, -1, -1, -1}, 20, "%d%% Faster Run/Walk"},
	//{98, 1, {8, -1, -1, -1}, 100, "State"},
	{99, 1, {7, -1, -1, -1}, 20, "%d%% Faster Hit Recovery"},
	{102, 1, {7, -1, -1, -1}, 20, "%d%% Faster Block Rate"},
	{105, 1, {7, -1, -1, -1}, 20, "%d%% Faster Cast Rate"},
	{108, 1, {1, -1, -1, -1}, 0, "Slain Monsters Rest In Peace"},
	{110, 1, {8, -1, -1, -1}, 20, "Poison Length Reduced by %d%%"},
	{111, 1, {9, -1, -1, -1}, 20, "Adds %+d Damage"},
	{112, 1, {7, -1, -1, -1}, -1, "Hit Causes Monster to Flee %d%%"},
	{113, 1, {7, -1, -1, -1}, 0, "Hit Blinds Target %+d"},
	{114, 1, {6, -1, -1, -1}, 0, "%d%% Damage Taken Goes to Mana"},
	{115, 1, {1, -1, -1, -1}, 0, "Ignore Target Defense"},
	{116, 1, {7, -1, -1, -1}, 0, "-%d%% Target Defense"},
	{117, 1, {7, -1, -1, -1}, 0, "Prevent Monster Heal"},
	{118, 1, {1, -1, -1, -1}, 0, "Half Freeze Duration"},
	{119, 1, {9, -1, -1, -1}, 20, "%d%% Bonus to Attack Rating"},
	{120, 1, {7, -1, -1, -1}, 128, "%+d to Monster Defense Per Hit"},
	{121, 1, {9, -1, -1, -1}, 20, "%d%% Damage to Demons"},
	{122, 1, {9, -1, -1, -1}, 20, "%d%% Damage to Undead"},
	{123, 1, {10, -1, -1, -1}, 128, "%+d to Attack Rating against Demons"},
	{124, 1, {10, -1, -1, -1}, 128, "%+d to Attack Rating against Undead"},
	{125, 1, {1, -1, -1, -1}, 0, "Throwable"},
	{127, 1, {3, -1, -1, -1}, 0, "%+d to All Skill Levels"},
	{128, 1, {5, -1, -1, -1}, 0, "Attacker Takes Lightning Damage of %d"},
	{134, 1, {5, -1, -1, -1}, 0, "Freezes Target %+d"},
	{135, 1, {7, -1, -1, -1}, 0, "%d%% Chance of Open Wounds"},
	{136, 1, {7, -1, -1, -1}, 0, "%d%% Chance of Crushing Blow"},
	{137, 1, {7, -1, -1, -1}, 0, "%+d Kick Damage"},
	{138, 1, {7, -1, -1, -1}, 0, "%+d to Mana After Each Kill"},
	{139, 1, {7, -1, -1, -1}, 0, "%+d Life after each Demon Kill"},
	{140, 1, {7, -1, -1, -1}, 0, "%d%% Extra Bloody"},
	{141, 1, {7, -1, -1, -1}, 0, "%d%% Deadly Strike"},
	{142, 1, {7, -1, -1, -1}, 0, "%d%% Fire Absorb"},
	{143, 1, {7, -1, -1, -1}, 0, "%+d Fire Absorb"},
	{144, 1, {7, -1, -1, -1}, 0, "%d%% Lightning Absorb"},
	{145, 1, {7, -1, -1, -1}, 0, "%+d Lightning Absorb"},
	{146, 1, {7, -1, -1, -1}, 0, "%d%% Magic Absorb"},
	{147, 1, {7, -1, -1, -1}, 0, "%+d Magic Absorb"},
	{148, 1, {7, -1, -1, -1}, 0, "%d%% Cold Absorb"},
	{149, 1, {7, -1, -1, -1}, 0, "%+d Cold Absorb"},
	{150, 1, {7, -1, -1, -1}, 0, "Slows Target by %d%%"},
	{152, 1, {1, -1, -1, -1}, 0, "Indestructible"},
	{153, 1, {1, -1, -1, -1}, 0, "Cannot Be Frozen"},
	{154, 1, {7, -1, -1, -1}, 20, "%d%% Slower Stamina Drain"},
	{156, 1, {7, -1, -1, -1}, 0, "Piercing Attack [%d]"},
	{157, 1, {7, -1, -1, -1}, 0, "Fires Magic Arrows"},
	{158, 1, {7, -1, -1, -1}, 0, "Fires Explosive Arrows"},
	{159, 1, {6, -1, -1, -1}, 0, "%+d to Minimum Damage"},
	{160, 1, {7, -1, -1, -1}, 0, "%+d to Maximum Damage"},
	{194, 1, {4, -1, -1, -1}, 0, "Increased Sockets by %d"},
	{214, 1, {6, -1, -1, -1}, 0, "%+d to Defense (Based on Character Level)"},
	{215, 1, {6, -1, -1, -1}, 0, "%+d%% to Defense (Based on Character Level)"},
	{216, 1, {6, -1, -1, -1}, 0, "%+d to Life (Based on Character Level)"},
	{217, 1, {6, -1, -1, -1}, 0, "%+d to Mana (Based on Character Level)"},
	{218, 1, {6, -1, -1, -1}, 0, "%+d to Maximum Damage (Based on Character Level)"},
	{219, 1, {6, -1, -1, -1}, 0, "%+d%% to Maximum Damage (Based on Character Level)"},
	{220, 1, {6, -1, -1, -1}, 0, "%+d to Strength (Based on Character Level)"},
	{221, 1, {6, -1, -1, -1}, 0, "%+d to Dexterity (Based on Character Level)"},
	{222, 1, {6, -1, -1, -1}, 0, "%+d to Energy (Based on Character Level)"},
	{223, 1, {6, -1, -1, -1}, 0, "%+d to Vitality (Based on Character Level)"},
	{224, 1, {6, -1, -1, -1}, 0, "%+d to Attack Rating (Based on Character Level)"},
	{225, 1, {6, -1, -1, -1}, 0, "%d%% Bonus to Attack Rating (Based on Character Level)"},
	{226, 1, {6, -1, -1, -1}, 0, "%+d to Maximum Cold Damage (Based on Character Level)"},
	{227, 1, {6, -1, -1, -1}, 0, "%+d to Maximum Fire Damage (Based on Character Level)"},
	{228, 1, {6, -1, -1, -1}, 0, "%+d to Maximum Lightning Damage (Based on Character Level)"},
	{229, 1, {6, -1, -1, -1}, 0, "%+d to Maximum Poison Damage (Based on Character Level)"},
	{230, 1, {6, -1, -1, -1}, 0, "%+d to Maximum Cold Resist (Based on Character Level)"},
	{231, 1, {6, -1, -1, -1}, 0, "%+d to Maximum Fire Resist (Based on Character Level)"},
	{232, 1, {6, -1, -1, -1}, 0, "%+d to Maximum Resist Damage (Based on Character Level)"},
	{233, 1, {6, -1, -1, -1}, 0, "%+d to Maximum Poison Resist (Based on Character Level)"},
	{234, 1, {6, -1, -1, -1}, 0, "%+d to Cold Absorb (Based on Character Level)"},
	{235, 1, {6, -1, -1, -1}, 0, "%+d to Fire Absorb (Based on Character Level)"},
	{236, 1, {6, -1, -1, -1}, 0, "%+d to Lightning Absorb (Based on Character Level)"},
	{237, 1, {6, -1, -1, -1}, 0, "%+d to Poison Absorb (Based on Character Level)"},
	{238, 1, {5, -1, -1, -1}, 0, "Attacker Takes Damage of %d (Based on Character Level)"},
	{239, 1, {6, -1, -1, -1}, 0, "%d%% Extra Gold (Based on Character Level)"},
	{240, 1, {6, -1, -1, -1}, 0, "%d%% Better Chance of Getting Magic Items (Based on Character Level)"},
	{241, 1, {6, -1, -1, -1}, 0, "Heal Stamina Plus %d%% (Based on Character Level)"},
	{242, 1, {6, -1, -1, -1}, 0, "%+d to Maximum Stamina (Based on Character Level)"},
	{243, 1, {6, -1, -1, -1}, 0, "%d%% Damage to Demons (Based on Character Level)"},
	{244, 1, {6, -1, -1, -1}, 0, "%d%% Damage to Undead (Based on Character Level)"},
	{245, 1, {6, -1, -1, -1}, 0, "%d%% Bonus to Attack Rating Against Demons (Based on Character Level)"},
	{246, 1, {6, -1, -1, -1}, 0, "%d%% Bonus to Attack Rating Against Undead (Based on Character Level)"},
	{247, 1, {6, -1, -1, -1}, 0, "%d%% Crushing Blow (Based on Character Level)"},
	{248, 1, {6, -1, -1, -1}, 0, "%d%% Open Wounds (Based on Character Level)"},
	{249, 1, {6, -1, -1, -1}, 0, "%d Kick Damage (Based on Character Level)"},
	{250, 1, {6, -1, -1, -1}, 0, "%d%% Deadly Strike (Based on Character Level)"},
	{252, 1, {6, -1, -1, -1}, 0, "Repairs 1 durability in %d seconds"},
	{253, 1, {6, -1, -1, -1}, 0, "Replenishes Quantity"},
	{254, 1, {8, -1, -1, -1}, 0, "Increased Stack Size"},
	{305, 1, {8, -1, -1, -1}, 50, "%+d%% to Enemy Cold Resistance"},
	{306, 1, {8, -1, -1, -1}, 50, "%+d%% to Enemy Fire Resistance"},
	{307, 1, {8, -1, -1, -1}, 50, "%+d%% to Enemy Lightning Resistance"},
	{308, 1, {8, -1, -1, -1}, 50, "%+d%% to Enemy Poison Resistance"},
	{329, 1, {9, -1, -1, -1}, 50, "%+d%% to Fire Skill Damage"},
	{330, 1, {9, -1, -1, -1}, 50, "%+d%% to Lightning Skill Damage"},
	{331, 1, {9, -1, -1, -1}, 50, "%+d%% to Cold Skill Damage"},
	{332, 1, {9, -1, -1, -1}, 50, "%+d%% to Poison Skill Damage"},
	{333, 1, {8, -1, -1, -1}, 0, "-%d%% to Enemy Fire Resistance"},
	{334, 1, {8, -1, -1, -1}, 0, "-%d%% to Enemy Lightning Resistance"},
	{335, 1, {8, -1, -1, -1}, 0, "-%d%% to Enemy Cold Resistance"},
	{336, 1, {8, -1, -1, -1}, 0, "-%d%% to Enemy Poison Resistance"},
	{356, 1, {2, -1, -1, -1}, 0, "Quest Item Difficulty: %d"},
// 2 =====
	{17, 2, {9, 9, -1, -1}, 0, "%+d%% Enhanced Damage"},
	{48, 2, {8, 9, -1, -1}, 0, "%+d fire damage"},
	{50, 2, {6, 10, -1, -1}, 0, "%+d lightning damage"},
	{52, 2, {8, 9, -1, -1}, 0, "%+d magic damage"},
	{83, 2, {3, 3, -1, -1}, 0, "%+d to %s Skill Levels"},
	{97, 2, {9, 6, -1, -1}, 100, "%+d to %s"},
	{107, 2, {9, 3, -1, -1}, 0, "%+d to %s (%s Only)"},
	{126, 2, {3, 3, -1, -1}, 0, "%+d to %s Skills"},
	{151, 2, {9, 5, -1, -1}, 0, "Level %d %s Aura When Equipped"},
	{155, 2, {10, 7, -1, -1}, 0, "%d%% Reanimate As: %s"},
	{188, 2, {16, 3, -1, -1}, 0, "%+d%s (%s Only)"},
// 3 =====
	{54, 3, {8, 9, 8, -1}, 0, "%+d cold damage over %d seconds"},
	{57, 3, {10, 10, 9, -1}, 0, "%+d poison damage over %d seconds"},
	{195, 3, {6, 10, 7, -1}, 0, "%d%% Chance to cast Level %d %s on attack"},
	{196, 3, {6, 10, 7, -1}, 0, "%d%% Chance to cast Level %d %s When You Kill an Enemy"},
	{197, 3, {6, 10, 7, -1}, 0, "%d%% Chance to cast Level %d %s When You Die"},
	{198, 3, {6, 10, 7, -1}, 0, "%d%% Chance to cast Level %d %s on striking"},
	{199, 3, {6, 10, 7, -1}, 0, "%d%% Chance to cast Level %d %s When You Level Up"},
	{201, 3, {6, 10, 7, -1}, 0, "%d%% Chance to cast Level %d %s when struck"},
	{268, 3, {2, 10, 10, -1}, 0, "%+d to Defense (%s)"},
	{269, 3, {2, 10, 10, -1}, 0, "%+d to Max Damage %d %s"},
	{270, 3, {2, 10, 10, -1}, 0, "%+d to xxx (%s)"},
	{271, 3, {2, 10, 10, -1}, 0, "%+d to xxx (%s)"},
	{272, 3, {2, 10, 10, -1}, 0, "%+d to xxx (%s)"},
	{273, 3, {2, 10, 10, -1}, 0, "%+d to xxx (%s)"},
	{274, 3, {2, 10, 10, -1}, 0, "%+d to xxx (%s)"},
	{275, 3, {2, 10, 10, -1}, 0, "%+d to xxx (%s)"},
	{276, 3, {2, 10, 10, -1}, 0, "%+d to xxx (%s)"},
	{277, 3, {2, 10, 10, -1}, 0, "%+d to xxx (%s)"},
	{278, 3, {2, 10, 10, -1}, 0, "%+d to xxx (%s)"},
	{279, 3, {2, 10, 10, -1}, 0, "%+d to xxx (%s)"},
	{280, 3, {2, 10, 10, -1}, 0, "%+d to xxx (%s)"},
	{281, 3, {2, 10, 10, -1}, 0, "%+d to xxx (%s)"},
	{282, 3, {2, 10, 10, -1}, 0, "%+d to xxx (%s)"},
	{283, 3, {2, 10, 10, -1}, 0, "%+d to xxx (%s)"},
	{284, 3, {2, 10, 10, -1}, 0, "%+d to xxx (%s)"},
	{285, 3, {2, 10, 10, -1}, 0, "%+d to xxx (%s)"},
	{286, 3, {2, 10, 10, -1}, 0, "%+d to xxx (%s)"},
	{287, 3, {2, 10, 10, -1}, 0, "%+d to xxx (%s)"},
	{288, 3, {2, 10, 10, -1}, 0, "%+d to xxx (%s)"},
	{289, 3, {2, 10, 10, -1}, 0, "%+d to xxx (%s)"},
	{290, 3, {2, 10, 10, -1}, 0, "%+d to xxx (%s)"},
	{291, 3, {2, 10, 10, -1}, 0, "%+d to xxx (%s)"},
	{292, 3, {2, 10, 10, -1}, 0, "%+d to xxx (%s)"},
	{293, 3, {2, 10, 10, -1}, 0, "%+d to xxx (%s)"},
	{294, 3, {2, 10, 10, -1}, 0, "%+d to xxx (%s)"},
	{295, 3, {2, 10, 10, -1}, 0, "%+d to xxx (%s)"},
	{296, 3, {2, 10, 10, -1}, 0, "%+d to xxx (%s)"},
	{297, 3, {2, 10, 10, -1}, 0, "%+d to xxx (%s)"},
	{298, 3, {2, 10, 10, -1}, 0, "%+d to xxx (%s)"},
	{299, 3, {2, 10, 10, -1}, 0, "%+d to xxx (%s)"},
	{300, 3, {2, 10, 10, -1}, 0, "%+d to xxx (%s)"},
	{301, 3, {2, 10, 10, -1}, 0, "%+d to xxx (%s)"},
	{302, 3, {2, 10, 10, -1}, 0, "%+d to xxx (%s)"},
	{303, 3, {2, 10, 10, -1}, 0, "%+d to xxx (%s)"},
	//{304, 3, {2, 10, 10, -1}, 0, "%+d to xxx (%s)"},
// 4 =====
	{204, 4, {6, 10, 8, 8}, 0, "Level %d %s (%d/%d Charges)"}
};