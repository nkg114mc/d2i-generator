#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cassert>
#include <algorithm>

#include "bitwriter.h"
#include "items.h"

void createItem(std::string fileName)
{

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

void createRune(std::string name, CommonItem &item)
{

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
	item.altPositionID = 0;
	item.typeCodeChar = name + std::string(" ");
	item.nItemsInSockets = 0;

	assert(item.typeCodeChar.length() == 4);
}

void insertRunes(ComplexItem &item, std::string *names, int length)
{
	for (int i = 0; i < length; i++)
	{
		CommonItem gem;
		createRune(names[i], gem);
		item.socketedItemList.push_back(gem);
	}
	item.nItemsInSockets = item.socketedItemList.size();
}

void createAttr(MagicAttribute &magic,
				MagicProperty &prop)
{
	magic.propCode = prop.code;
	magic.valueCount = prop.nCnt;
	for (int j = 0; j < prop.nCnt; j++)
	{
		int v = (1 << prop.bits[j]) - 1;
		MagicValue mValue(prop.bits[j], v);
		magic.mValues[j] = mValue;
	}
}

void insertMagics(ComplexItem &item)
{
	// for (int i = 0; i < 149; i++) {
	for (int i = 59; i < 149; i++)
	{
		// print property
		std::cout << existMagics[i].code << ": " << existMagics[i].desc << std::endl;
		MagicAttribute magic;
		createAttr(magic, existMagics[i]);
		item.magicAttrList.push_back(magic);
	}
}

void insertMagics2(ComplexItem &item)
{

	int mIdxs[] = {204};

	for (int i = 0; i < 10; i++)
	{
		int j = mIdxs[i];
		MagicAttribute magic;
		createAttr(magic, indexedMagics[j]);
		item.magicAttrList.push_back(magic);
	}
}

void insertMagics3(ComplexItem &item)
{
	for (int i = 0; i < 8; i++)
	{
		MagicProperty* magicPtr;
		magicPtr = &(existMagics[i]);
		if (magicPtr->nCnt == 1)
		{
			std::cout << "Adding ===>" << magicPtr->code << ": " << magicPtr->desc << std::endl;
			MagicAttribute magic;
			createAttr(magic, *magicPtr);
			item.magicAttrList.push_back(magic);
		}
	}

	for (int i = 86; i < 186; i++)
	{
		MagicProperty* magicPtr;
		magicPtr = &(existMagics[i]);
		if (magicPtr->nCnt == 1)
		{
			std::cout << "Adding ===>" << magicPtr->code << ": " << magicPtr->desc << std::endl;
			MagicAttribute magic;
			createAttr(magic, *magicPtr);
			item.magicAttrList.push_back(magic);
		}
	}

	std::cout << "Total inserted magics: " << item.magicAttrList.size() << std::endl;
}

void insertMagics4(ComplexItem &item)
{
	int flag[400];
	for (int i = 0; i < 400; i++)
	{
		flag[i] = 0;
		if (ustatsMagics[i].nCnt == 1)
		{
			flag[i] = 1;
		}
	}
	for (int i = 0; i < 29; i++)
	{
		flag[hiringBowMagics[i].code] = 0;
	}
	std::vector<int> idxs;
	for (int i = 0; i < 400; i++)
	{
		if (flag[i] > 0)
			idxs.push_back(i);
	}
	std::random_shuffle(idxs.begin(), idxs.end());

	for (int i = 0; i < 29; i++)
	{
		std::cout << hiringBowMagics[i].code << ": " << hiringBowMagics[i].desc << std::endl;
		MagicAttribute magic;
		createAttr(magic, hiringBowMagics[i]);
		item.magicAttrList.push_back(magic);
	} /*
	 for (int i = 0; i < 30; i++) {
	   int j = idxs[i];
	   std::cout << ustatsMagics[j].code << ": " << ustatsMagics[j].desc << std::endl;
	   MagicAttribute magic;
	   createAttr(magic, ustatsMagics[j]);
	   item.magicAttrList.push_back(magic);
	 }*/
}

void insertMagics5(ComplexItem &item)
{
	std::vector<int> idxs;
	for (int i = 0; i < 186; i++)
	{
		MagicProperty* magicPtr;
		magicPtr = &(existMagics[i]);
		if (magicPtr->nCnt == 1)
		{
			idxs.push_back(i);
		}
	}

	std::cout << "Total candiate magics: " << idxs.size() << std::endl;

	//std::random_shuffle(idxs.begin(), idxs.end());
	int N = 100; //idxs.size();
	for (int j = 0; j < N; j++) {
		MagicProperty* magicPtr;
		magicPtr = &(existMagics[idxs[j]]);
		std::cout << "Adding ===>" << magicPtr->code << ": " << magicPtr->desc << std::endl;
		MagicAttribute magic;
		createAttr(magic, *magicPtr);
		item.magicAttrList.push_back(magic);
	}

	std::cout << "Total inserted magics: " << item.magicAttrList.size() << std::endl;
}


void insertMagics6(ComplexItem &item)
{
	MagicAttribute magic;
	magic.propCode = 204;
	magic.valueCount = 4;
	magic.mValues[0] = MagicValue(6, 63);
	magic.mValues[1] = MagicValue(10, 15);
	magic.mValues[2] = MagicValue(8, 255);
	magic.mValues[3] = MagicValue(8, 255);

	item.magicAttrList.push_back(magic);

	magic.propCode = 195;
	magic.valueCount = 3;
	magic.mValues[0] = MagicValue(6, 63);
	magic.mValues[1] = MagicValue(10, 15);
	magic.mValues[2] = MagicValue(7, 127);

	item.magicAttrList.push_back(magic);

	magic.propCode = 188;
	magic.valueCount = 3;
	magic.mValues[0] = MagicValue(3, 1);
	magic.mValues[1] = MagicValue(13, 6);
	magic.mValues[2] = MagicValue(3, 7);

	item.magicAttrList.push_back(magic);

	magic.propCode = 189;
	magic.valueCount = 2;
	magic.mValues[0] = MagicValue(10, 1023);
	magic.mValues[1] = MagicValue(9, 15);

	item.magicAttrList.push_back(magic);

}

void insertMagics7(ComplexItem &item)
{
	for (int j = 0; j < 182; j++) {
		MagicProperty* magicPtr;
		magicPtr = &(validUstatsMagics[j]);
		if (magicPtr->nCnt == 1) {
			if (magicPtr->code >= 210 && magicPtr->code < 350) {
				std::cout << "Adding ===>" << magicPtr->code << ": " << magicPtr->desc << std::endl;
				MagicAttribute magic;
				createAttr(magic, *magicPtr);
				item.magicAttrList.push_back(magic);
			}
		}
	}

	std::cout << "Total inserted magics: " << item.magicAttrList.size() << std::endl;
}

void createComplexItem(std::string fileName)
{

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
	item.level = 1;
	item.quality = MagicallyEnhanced; //Unique;
	item.qualityData = new ItemQualityMagicEnhanced(132, 458);
	// item.qualityData = new ItemQualityRareCrafted(0x9c, 0x1, 132,458,139,687,247,726);
	// item.qualityData = new ItemQualityUnique(159);
	item.isMultiplePictures = 0;
	item.pictureID = 0;
	item.isClassSpecific = 0;
	item.classSpecificCode = 0;

	item.givenRunewordCode = 195; // MARK: Runeword data
	item.personName = std::string("abcdefg"); //("+ZJJl5lPRXARwuQ-");//("大娃肯定戴不上的帽子系列");
	item.timestamp = 0;

	item.defRating = 2047;
	item.maxDurability = 40;
	item.quantity = 0;
	item.totalNrOfSockets = 2;

	// std::string runes[] = {"r09", "r05"};
	// insertRunes(item, runes, 2);

	// add magics
	insertMagics7(item);

	item.writeToFile(writer);
	writer.close();

	delete item.qualityData;
}

int main()
{
	initMagics();
	readuStats();
	readAtmaProperties();
	createComplexItem("testitem13.d2i");
	return 0;
}
