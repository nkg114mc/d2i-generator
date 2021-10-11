#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cassert>
#include <algorithm>

#include "bitwriter.h"
#include "items.h"


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

void insertMagics2(ComplexItem &item) {

  int mIdxs[] = { 204 };

  for (int i = 0; i < 10; i++) {
    int j = mIdxs[i];
    MagicAttribute magic;
    createAttr(magic, indexedMagics[j]);
    item.magicAttrList.push_back(magic);
  }
}

void insertMagics3(ComplexItem &item) {
  for (int i = 0; i < 200; i++) {
    if (ustatsMagics[i].nCnt == 1) {
      std::cout << ustatsMagics[i].code << ": " << ustatsMagics[i].desc << std::endl;
      MagicAttribute magic;
      createAttr(magic, ustatsMagics[i]);
      item.magicAttrList.push_back(magic);
    }
  }
}

void insertMagics4(ComplexItem &item) {
  int flag[400];
  for (int i = 0; i < 400; i++) {
    flag[i] = 0;
    if (ustatsMagics[i].nCnt == 1) {
      flag[i] = 1;
    }
  }
  for (int i = 0; i < 29; i++) {
    flag[hiringBowMagics[i].code] = 0;
  }
  std::vector<int> idxs;
  for (int i = 0; i < 400; i++) {
    if (flag[i] > 0) idxs.push_back(i);
  }
  std::random_shuffle(idxs.begin(), idxs.end());

  for (int i = 0; i < 29; i++) {
    std::cout << hiringBowMagics[i].code << ": " << hiringBowMagics[i].desc << std::endl;
    MagicAttribute magic;
    createAttr(magic, hiringBowMagics[i]);
    item.magicAttrList.push_back(magic);
  }/*
  for (int i = 0; i < 30; i++) {
    int j = idxs[i];
    std::cout << ustatsMagics[j].code << ": " << ustatsMagics[j].desc << std::endl;
    MagicAttribute magic;
    createAttr(magic, ustatsMagics[j]);
    item.magicAttrList.push_back(magic);
  }*/
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

  //std::string runes[] = {"r09", "r05"};
  //insertRunes(item, runes, 2);

  // add magics
  insertMagics4(item);

  item.writeToFile(writer);
  writer.close();

  delete item.qualityData;
}


int main() {
  initMagics();
  readuStats();
  createComplexItem("testitem11.d2i");
  return 0;
}
