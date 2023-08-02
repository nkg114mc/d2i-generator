
#include <vector>
#include <cassert>
#include <iostream>

#include "items.h"

void ComplexItem::writeToFile(BitWriter &writer)
{

	// writer header first (111 bits)
	writeHeader(writer);

	// write the complex part

	writer.writeBit(globalID, 32, true);

	// offset 143
	writer.writeBit(level, 7, true);

	// offset 150
	writer.writeBit(quality, 4, true);

	// If this is true, it means the item has more than one picture associated with it.
	writer.writeBit(isMultiplePictures, 1, true);
	if (isMultiplePictures > 0)
	{
		writer.writeBit(pictureID, 3, true);
	}

	writer.writeBit(isClassSpecific, 1, true);
	if (isClassSpecific > 0)
	{
		writer.writeBit(classSpecificCode, 11, true);
	}

	// write quality info
	writeQuality(writer);

	if (isGivenRuneword > 0)
	{
		writer.writeBit(givenRunewordCode, 12, true);
		writer.writeBit(0, 4, true); // padding only
	}

	if (personalized)
	{
		// write name string
		for (int i = 0; i < 32; i++)
		{
			writer.writeBit((uint64_t)personName[i], 7, true);
			if (personName[i] == 0x0)
			{
				break;
			}
		}
	}

	// If the item is a tome, it will contain 5 extra bits, we're not
	// interested in these bits, the value is usually 1, but not sure
	// what it is.
	if (isTomeItem())
	{
		writer.writeBit(0x1F, 5, true);
	}

	writer.writeBit(timestamp, 1, true);

	if (bigItemType == ITEM_AMOR || bigItemType == ITEM_SHIELD)
	{
		std::cout << "This is a defense item." << std::endl;

		// If the item is an armor, it will have this field of defense data.
		assert(defRating >= 0 && defRating < 2048);
		writer.writeBit(defRating, 11, true);
	}

	if (bigItemType == ITEM_AMOR || bigItemType == ITEM_WEAPON || bigItemType == ITEM_SHIELD)
	{
		std::cout << "This is a durable item." << std::endl;

		assert(maxDurability >= 0 && maxDurability < 256);
		writer.writeBit(maxDurability, 8, true);

		// Some weapons like phase blades don't have durability, so we'll
		// check if the item has max durability, then we can safely assume
		// it has current durability too.
		if (maxDurability > 0)
		{
			writer.writeBit(maxDurability, 9, true); // current durability
		}
	}

	if (isQuantityItem())
	{
		assert(quality >= 0 && quality < 512);
		writer.writeBit(quality, 9, true);
	}
	else
	{
		std::cout << "Not a quantity item." << std::endl;
	}
	/*
			  if quantityMap[parsed.Type] {
				  // If the item is a stacked item, e.g. a javelin or something, these 9
				  // bits will contain the quantity.
				  parsed.Quantity = reverseBits(ibr.ReadBits64(9, true), 9)
				  readBits += 9
			  }
	*/

	// If the item is socketed, it will contain 4 bits of data which are the nr
	// of total sockets the item have, regardless of how many are occupied by
	// an item.
	if (socketed > 0)
	{
		writer.writeBit(totalNrOfSockets, 4, true);
	}

	// set magic list length
	// If the item is part of a set, these bit will tell us how many lists
	// of magical properties follow the one regular magical property list.
	if (quality == PartOfSet)
	{
		// 0 --> 00000 = 0
		// 1 --> 00001 = 1
		// 2 --> 00011 = 3
		// 3 --> 00111 = 7
		// 4 --> 01111 = 15
		// 5 --> 11111 = 31
		uint64_t lenBits[6] = {0, 1, 3, 7, 15, 31};

		// write list number
		assert(setMagicAttrListList.size() <= 5); // at most 5 lists
		uint64_t setListLen = lenBits[setMagicAttrListList.size()];
		writer.writeBit(setListLen, 5, true);
	}

	// write magic attributes
	writeMagicList(magicAttrList, writer);

	// set magic lists
	if (quality == PartOfSet &&
		setMagicAttrListList.size() > 0)
	{
	/*
		// 0 --> 00000 = 0
		// 1 --> 00001 = 1
		// 2 --> 00011 = 3
		// 3 --> 00111 = 7
		// 4 --> 01111 = 15
		// 5 --> 11111 = 31
		uint64_t lenBits[6] = {0, 1, 3, 7, 15, 31};

		// write list number
		assert(setMagicAttrListList.size() <= 5); // at most 5 lists
		uint64_t setListLen = lenBits[setMagicAttrListList.size()];
		writer.writeBit(setListLen, 5, true);
	*/
	}

	if (isGivenRuneword > 0)
	{
		writeMagicList(runewordMagicAttrList, writer);
	}

	// align to bytes
	writer.flushBufferAligned();

	// following socketed items
	writeSocketedGems(socketedItemList, writer);
}

void ComplexItem::writeSocketedGems(std::vector<CommonItem> &gems, BitWriter &writer)
{
	assert(socketed > 0);
	assert(gems.size() <= totalNrOfSockets);
	assert(gems.size() == nItemsInSockets);
	for (int i = 0; i < gems.size(); i++)
	{
		std::cout << gems[i].typeCodeChar << std::endl;
		gems[i].writeHeader(writer);
		writer.flushBufferAligned();
	}
}

void ComplexItem::writeQuality(BitWriter &writer)
{
	assert(qualityData != nullptr);
	qualityData->writeQuality(writer);
}

void ComplexItem::writeMagicList(std::vector<MagicAttribute> &magicList, BitWriter &writer)
{
	for (int j = 0; j < magicList.size(); j++)
	{
		writeSingleMagic(magicList[j], writer);
	}
	writer.writeBit(0x1FF, 9, true);
}

void ComplexItem::writeSingleMagic(MagicAttribute &magic, BitWriter &writer)
{
	// write property code
	writer.writeBit(magic.propCode, 9, true);
	// write property values
	for (int i = 0; i < magic.valueCount; i++)
	{
		writer.writeBit(magic.mValues[i].value, magic.mValues[i].bits, true);
	}
}

bool ComplexItem::isTomeItem()
{
	for (int i = 0; i < TomeCodeLength; i++)
	{
		if (typeCodeChar.substr(0, 3) == TomeCode[i])
		{
			return true;
		}
	}
	return false;
}

bool ComplexItem::isDurableItem()
{
	/*
		for (int i = 0; i < TomeCodeLength; i++) {
			if (typeCodeChar.substr(0, 3) == TomeCode[i]) {
				return true;
			}
		}
		return false;
	*/
}

bool ComplexItem::isQuantityItem()
{
	for (int i = 0; i < QuantityCodeLength; i++)
	{
		if (typeCodeChar.substr(0, 3) == QutityCode[i])
		{
			return true;
		}
	}
	return false;
}
