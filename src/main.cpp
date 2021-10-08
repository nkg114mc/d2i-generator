#include <iostream>
#include <cassert>

#include "bitwriter.h"
#include "items.h"


/*

void writeHeader(CommonItem &item, BitWriter &writer) {

  int headj = (int)'J';
  writer.writeBit(headj, 8, true);
  int headm = (int)'M';
  writer.writeBit(headm, 8, true);

  // unknown
  writer.writeBit(0, 4, true);

  // offset: 20
  writer.writeBit(item.identified, 1, true);

	//item.Identified = reverseBits(ibr.ReadBits64(1, true), 1)
	//readBits++

	// offset: 21, unknown
  writer.writeBit(0, 6, true);

	// offset: 27
	//item.Socketed = reverseBits(ibr.ReadBits64(1, true), 1)
	//readBits++
  writer.writeBit(item.socketed, 1, true);

	// offset 28, unknown
	//ibr.ReadBits64(1, true)
	//readBits++
  writer.writeBit(0, 1, true);

	// offset 29
	//item.New = reverseBits(ibr.ReadBits64(1, true), 1)
	//readBits++
  writer.writeBit(item.newbee, 1, true);

	// offset 30, unknown
	//_ = reverseBits(ibr.ReadBits64(2, true), 2)
	//readBits += 2
  writer.writeBit(0, 2, true);

	// offset 32
	//item.IsEar = reverseBits(ibr.ReadBits64(1, true), 1)
	//readBits++
  writer.writeBit(0, 1, true); // not ear

	// offset 33
	//item.StarterItem = reverseBits(ibr.ReadBits64(1, true), 1)
	//readBits++
  writer.writeBit(item.starterItem, 1, true);

	// offset 34, unknown
	//_ = reverseBits(ibr.ReadBits64(3, true), 3)
	//readBits += 3
  writer.writeBit(0, 3, true);

	// offset 37, if it's a simple item, it only contains 111 bits data
	//item.SimpleItem = reverseBits(ibr.ReadBits64(1, true), 1)
	//readBits++
  writer.writeBit(item.simpleItem, 1, true);

	// offset 38
	//item.Ethereal = reverseBits(ibr.ReadBits64(1, true), 1)
	//readBits++
  writer.writeBit(item.ethereal, 1, true);

	// offset 39, unknown
	//_ = reverseBits(ibr.ReadBits64(1, true), 1)
	//readBits++
  writer.writeBit(0, 1, true);

	// offset 40
	//item.Personalized = reverseBits(ibr.ReadBits64(1, true), 1)
	//readBits++
  writer.writeBit(item.personalized, 1, true);

	// offset 41, unknown
	//_ = reverseBits(ibr.ReadBits64(1, true), 1)
	//readBits++
  writer.writeBit(0, 1, true);

	// offset 42
	//item.GivenRuneword = reverseBits(ibr.ReadBits64(1, true), 1)
	//readBits++
  writer.writeBit(item.isGivenRuneword, 1, true);

	// offset 43, unknown
	//_ = reverseBits(ibr.ReadBits64(5, true), 5)
	//readBits += 5
  writer.writeBit(0, 5, true);

	// offset 48
	//item.Version = reverseBits(ibr.ReadBits64(8, true), 8)
	//readBits += 8
  writer.writeBit(item.version, 8, true);

	// offset 56, unknown
	//_ = reverseBits(ibr.ReadBits64(2, true), 2)
	//readBits += 2
  writer.writeBit(0, 2, true);

	// offset 58
  writer.writeBit(item.locationID, 3, true);

	// offset 61
  writer.writeBit(item.equippedID, 4, true);

	// offset 65
  writer.writeBit(item.positionX, 4, true);

	// offset 69
  writer.writeBit(item.positionY, 3, true);

	// offset 72
  writer.writeBit(0, 1, true);

	// offset 73, if item is neither equipped or in the belt, this tells us where it is.
  writer.writeBit(item.altPositionID, 3, true);

	// offset 76, item type, 4 chars, each 8 bit (not byte aligned)
  item.copyCode(const char* src)
  writer.writeBit(item.typeCode, 32, true);
	
  // offset 108
  writer.writeBit(item.nItemsInSockets, 3, true);

}
*/


void createItem(std::string fileName) {

  BitWriter writer;
  writer.initFile(fileName);

  CommonItem item;

  item.identified = 1;
  item.socketed = 0;
  item.newbee = 1;
  item.starterItem = 0;
  item.simpleItem = 1;
  item.ethereal = 0;
	item.personalized = 0;
	item.isGivenRuneword = 0;
	item.version = 101;
	item.locationID = 0;
	item.equippedID = 0;
	item.positionX = 0;
	item.positionY = 0;
	item.altPositionID = 5;
  item.typeCodeChar = std::string("rvl ");
  item.nItemsInSockets = 0;

  item.writeHeader(writer);
  writer.close();
}

void createRune(std::string name, CommonItem &item) {

  item.identified = 1;
  item.socketed = 0;
  item.newbee = 0;
  item.starterItem = 0;
  item.simpleItem = 1;
  item.ethereal = 0;
	item.personalized = 0;
	item.isGivenRuneword = 0;
	item.version = 101;
	item.locationID = Location::Socketed;
	item.equippedID = 0;
	item.positionX = 0;
	item.positionY = 0;
	item.altPositionID = 5;
  item.typeCodeChar = name + std::string(" ");
  item.nItemsInSockets = 0;

  assert(item.typeCodeChar.length() == 4);
}

void insertRunes(ComplexItem &item, std::string *names, int length) {
  for (int i = 0; i < length; i++) {
    CommonItem gem;
    createRune(names[i], gem);
    item.socketedItemList.push_back(gem);
  }
  item.nItemsInSockets = item.socketedItemList.size();
}

void createAttr(MagicAttribute &magic, 
                MagicProperty &prop) {
  magic.propCode = prop.code;
  magic.valueCount = prop.nCnt;
  for (int j = 0; j < prop.nCnt; j++) {
    int v = (1 << prop.bits[j]) - 1;
    MagicValue mValue(prop.bits[j], v);
    magic.mValues[j] = mValue;
  }
}

void insertMagics(ComplexItem &item) {
  //for (int i = 0; i < 149; i++) {
  for (int i = 59; i < 149; i++) {
    // print property
    std::cout << existMagics[i].code << ": " <<  existMagics[i].desc << std::endl;
    MagicAttribute magic;
    createAttr(magic, existMagics[i]);
    item.magicAttrList.push_back(magic);
  }
}

void createComplexItem(std::string fileName) {

  BitWriter writer;
  writer.initFile(fileName);

  ComplexItem item;

  item.identified = 1;
  item.socketed = 1;
  item.newbee = 1;
  item.starterItem = 0;
  item.simpleItem = 0;
  item.ethereal = 0;
	item.personalized = 1;
	item.isGivenRuneword = 0;
	item.version = 101;
	item.locationID = 0;
	item.equippedID = 0;
	item.positionX = 0;
	item.positionY = 0;
	item.altPositionID = 5;
  item.typeCodeChar = std::string("6lw ");
  item.nItemsInSockets = 0;


  // complex properties

  item.bigItemType = getBigType(item.typeCodeChar);
  std::cout << "Item big type: " << item.bigItemType << std::endl;

  item.globalID = rand();
	item.level = 90;
	item.quality = Unique;
  //item.qualityData = new ItemQualityMagicEnhanced(132, 458);
  //item.qualityData = new ItemQualityRareCrafted(0x9c, 0x1, 132,458,139,687,247,726);
  item.qualityData = new ItemQualityUnique(159);
	item.isMultiplePictures = 0;
	item.pictureID = 0;
  item.isClassSpecific = 0;
  item.classSpecificCode = 0;

	item.givenRunewordCode = 195; // MARK: Runeword data
	item.personName = std::string("Ailolo");
  item.timestamp = 0;

  item.defRating = 2047;
  item.maxDurability = 40;
  item.quantity = 0;
  item.totalNrOfSockets = 2;

  std::string runes[] = {"r09", "r05"};
  //insertRunes(item, runes, 2);

  // add magics
  insertMagics(item);

  item.writeToFile(writer);
  writer.close();

  delete item.qualityData;
}



int main() {
  initMagics();
  createComplexItem("testitem83.d2i");
  return 0;
}
