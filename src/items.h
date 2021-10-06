#ifndef ITEM_H
#define ITEM_H

#include <fstream>
#include <vector>
#include "bitwriter.h"

enum {
  ITEM_MISC, ITEM_AMOR, ITEM_WEAPON, ITEM_SHIELD
};

enum Location {
	Stored   = 0x00,
	Equipped = 0x01,
	Belt     = 0x02,
	Cursor   = 0x04,
	Socketed = 0x06
};

// Rarity IDs.
enum Rarity {
	LowQuality        = 0x01,
	Normal            = 0x02,
	HighQuality       = 0x03,
	MagicallyEnhanced = 0x04,
	PartOfSet         = 0x05,
	Rare              = 0x06,
	Unique            = 0x07,
	Crafted           = 0x08
};


class CommonItem {
private:
  bool isEar;

  void writeNormalHeader(BitWriter &writer);
  void writeEarHeader(BitWriter &writer);
  uint32_t convertTypeCode(const char* str4Code);

public:
  CommonItem(bool itemIsEar);
  CommonItem();
  void writeHeader(BitWriter &writer);
  bool getIsEar();

  uint64_t identified;
  uint64_t socketed;
  uint64_t newbee;
  uint64_t starterItem;
  uint64_t simpleItem;
  uint64_t ethereal;
	uint64_t personalized;
	uint64_t isGivenRuneword;
	uint64_t version;
	uint64_t locationID;
	uint64_t equippedID;
	uint64_t positionX;
	uint64_t positionY;
	uint64_t altPositionID;
  std::string typeCodeChar;
  uint64_t nItemsInSockets;
};

class ItemQuality {
public:
  virtual void writeQuality(BitWriter &writer) = 0;
};

class ItemQualityLow : public ItemQuality {
public:
  uint64_t lowID;
  ItemQualityLow(uint64_t id) { lowID = id; }
  void writeQuality(BitWriter &writer);
};

class ItemQualityNormal : public ItemQuality {
public:
  void writeQuality(BitWriter &writer);
};

class ItemQualityMagicEnhanced : public ItemQuality {
public:
  uint64_t prefixID, suffixID;
  ItemQualityMagicEnhanced(uint64_t id1, uint64_t id2) { 
    prefixID = id1; suffixID = id2;
  }
  void writeQuality(BitWriter &writer);
};

class ItemQualityRareCrafted : public ItemQuality {
public:
  uint64_t rareID1, rareID2;
  uint64_t prefix[3];
  uint64_t suffix[3];
  int preCnt, sufCnt;
  ItemQualityRareCrafted(uint64_t rare1, uint64_t rare2, 
                         uint64_t pre1, uint64_t suf1, 
                         uint64_t pre2, uint64_t suf2, 
                         uint64_t pre3, uint64_t suf3) {
    
    rareID1 = rare1;
    rareID2 = rare2;
    preCnt = 0;
    sufCnt = 0;
    if (pre1 >= 0) {
      prefix[preCnt] = pre1;
      preCnt++;
    }
    if (pre2 >= 0) {
      prefix[preCnt] = pre2;
      preCnt++;
    }
    if (pre3 >= 0) {
      prefix[preCnt] = pre3;
      preCnt++;
    }
    if (suf1 >= 0) {
      suffix[sufCnt] = suf1;
      sufCnt++;
    }
    if (suf2 >= 0) {
      suffix[sufCnt] = suf2;
      sufCnt++;
    }
    if (suf3 >= 0) {
      suffix[sufCnt] = suf3;
      sufCnt++;
    }
  }
  void writeQuality(BitWriter &writer);
};

class ItemQualityUnique : public ItemQuality {
public:
  uint64_t uniqueID;
  ItemQualityUnique(uint64_t id) { uniqueID = id; }
  void writeQuality(BitWriter &writer);
};

class ItemQualityPartOfSet : public ItemQuality {
public: 
  uint64_t setID;
  ItemQualityPartOfSet(uint64_t id) { setID = id; }
  void writeQuality(BitWriter &writer);
};


struct MagicAttribute {
  int valueCount;
  int Bits[4];
};

class ComplexItem : public CommonItem {
public:

  int bigItemType;

  uint64_t globalID;
	uint64_t level;
	uint64_t quality;
	uint64_t isMultiplePictures;
	uint64_t pictureID;
  uint64_t isClassSpecific;
  uint64_t classSpecificCode;
  
/*
			switch parsed.Quality {
			case lowQuality:
				parsed.LowQualityID = reverseBits(ibr.ReadBits64(3, true), 3)
				readBits += 3

			case normal:
			// No extra data present

			case highQuality:
				// TODO: Figure out what these 3 bits are on a high quality item
				_ = reverseBits(ibr.ReadBits64(3, true), 3)
				readBits += 3

			case magicallyEnhanced:
				parsed.MagicPrefix = reverseBits(ibr.ReadBits64(11, true), 11)
				prefixName, ok := magicalPrefixes[parsed.MagicPrefix]
				if ok {
					parsed.MagicPrefixName = prefixName
				}

				parsed.MagicSuffix = reverseBits(ibr.ReadBits64(11, true), 11)
				suffixName, ok := magicalSuffixes[parsed.MagicSuffix]
				if ok {
					parsed.MagicSuffixName = suffixName
				}
				readBits += 22

			case partOfSet:
				parsed.SetID = reverseBits(ibr.ReadBits64(12, true), 12)

				setName, ok := setNames[parsed.SetID]
				if ok {
					parsed.SetName = setName
				}

				readBits += 12

			case rare, crafted:
				rBits, _ := parseRareOrCraftedBits(&ibr, &parsed)
				readBits += rBits

			case unique:
				parsed.UniqueID = reverseBits(ibr.ReadBits64(12, true), 12)

				uniqueName, ok := uniqueNames[parsed.UniqueID]
				if ok {
					parsed.UniqueName = uniqueName
				}

				readBits += 12
			}
*/
			
	uint64_t givenRunewordCode; // MARK: Runeword data
	std::string personName;
  uint64_t timestamp;

  uint64_t defRating;
  uint64_t maxDurability;
	uint64_t currentDurability;
  uint64_t quantity;
  ItemQuality *qualityData;
  uint64_t totalNrOfSockets;
	// setListValue
  std::vector<MagicAttribute> magicAttrList;
  std::vector<MagicAttribute> runewordMagicAttrList;

  // socketed items
  std::vector<CommonItem> socketedItemList;

  void writeToFile(BitWriter &writer);

private:
  void writeQuality(BitWriter &writer);
  void writeMagicList(std::vector<MagicAttribute> &magicList, BitWriter &writer);
  void writeSingleMagic(MagicAttribute &magic);
  void writeSocketedGems(std::vector<CommonItem> &gems, BitWriter &writer);
  bool isTomeItem();
  bool isDurableItem();
  bool isQuantityItem();

};

// utils
int getBigType(std::string code);
bool isValidID(uint64_t id, const uint64_t *idSet, int setSize);

// consts
extern const int AmorCodeLength;
extern const int WeaponCodeLength;
extern const int ShieldCodeLength;
extern const int QuantityCodeLength;
extern const int TomeCodeLength;
extern const int RareNamesLength;
extern const int SetNamesLength;
extern const int RunewordNamesLength;
extern const int UniqueNamesLength;
extern const int MagicalPrefixesLength;
extern const int MagicalSuffixesLength;

extern const std::string AmorCode[];
extern const std::string WeaponCode[];
extern const std::string ShieldCode[];
extern const std::string QutityCode[];
extern const std::string TomeCode[];

extern const uint64_t RareNames[];
extern const uint64_t SetNames[];
extern const uint64_t RunewordNames[];
extern const uint64_t UniqueNames[];
extern const uint64_t MagicalPrefixes[];
extern const uint64_t MagicalSuffixes[];

#endif
