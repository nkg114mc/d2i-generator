
#include <vector>
#include <cassert>
#include <iostream>

#include "items.h"


void ComplexItem::writeToFile(BitWriter &writer) {

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
	if (isMultiplePictures > 0) {
    writer.writeBit(pictureID, 3, true);
	}

  writer.writeBit(isClassSpecific, 1, true);
  if (isClassSpecific > 0) {
    writer.writeBit(classSpecificCode, 11, true);
  }

  // write quality info
  writeQuality();

	if (isGivenRuneword > 0) {
    writer.writeBit(givenRunewordCode, 12, true);
		writer.writeBit(0, 4, true); // padding only
  }

  if (personalized) {
    // write name string
    for (int i = 0; i < 32; i++) {
      writer.writeBit((uint64_t)personName[i], 7, true);
      if (personName[i] == 0x0) {
        break;
      }
    }
  }

	// If the item is a tome, it will contain 5 extra bits, we're not
	// interested in these bits, the value is usually 1, but not sure
	// what it is.
  /*
	if tomeMap[parsed.Type] {
		_ = reverseBits(ibr.ReadBits64(5, true), 5)
		readBits += 5
	}*/
  if (isTomeItem()) {
    writer.writeBit(0x1F, 5, true);
  }

  writer.writeBit(timestamp, 1, true);

	if (bigItemType == ITEM_AMOR || bigItemType == ITEM_SHIELD) {
		std::cout << "This is a defense item." << std::endl;
    /*
				// If the item is an armor, it will have this field of defense data.
				defRating := reverseBits(ibr.ReadBits64(11, true), 11)
				readBits += 11

				// We need to subtract 10 defense rating from all armors for
				// some reason, I'm not sure why.
				parsed.DefenseRating = int64((defRating - 10))
    */
    assert(defRating >= 0 && defRating < 2048);
    writer.writeBit(defRating, 11, true);
	}

	if (bigItemType == ITEM_AMOR || bigItemType == ITEM_WEAPON || bigItemType == ITEM_SHIELD) {
		std::cout << "This is a durable item." << std::endl;
      
    //parsed.MaxDurability = reverseBits(ibr.ReadBits64(8, true), 8)
		//readBits += 8
    assert(maxDurability >= 0 && maxDurability < 256);
		writer.writeBit(maxDurability, 8, true);

    // Some weapons like phase blades don't have durability, so we'll
		// check if the item has max durability, then we can safely assume
		// it has current durability too.
    if (maxDurability > 0) {
      writer.writeBit(maxDurability, 9, true); // current durability
    }

				/*
				if parsed.MaxDurability > 0 {
					parsed.CurrentDurability = reverseBits(ibr.ReadBits64(8, true), 8)
					// Seems to be a random bit here.
					_ = reverseBits(ibr.ReadBits64(1, true), 1)

					readBits += 9
				}*/
	}

  if (isQuantityItem()) {
    assert(quality >= 0 && quality < 512);
    writer.writeBit(quality, 9, true);
  } else {
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
	if (socketed > 0) {
    writer.writeBit(totalNrOfSockets, 4, true);
	}

  // write magic attributes
	writeMagicList(magicAttrList, writer);

	//var setListValue uint64 = 0
  /*
			if parsed.Quality == partOfSet {
				setListValue = reverseBits(ibr.ReadBits64(5, true), 5)
				readBits += 5

				listCount, ok := setListMap[setListValue]
				if !ok {
					return []Item{}, fmt.Errorf("unknown set list number %d", setListValue)
				}

				parsed.SetListCount = listCount
			}
  */

 	if (isGivenRuneword > 0) {
    writeMagicList(runewordMagicAttrList, writer);
  }

	// align to bytes
	writer.flushBufferAligned();

	// following socketed items
	writeSocketedGems(socketedItemList, writer);
}

void ComplexItem::writeSocketedGems(std::vector<CommonItem> &gems, BitWriter &writer) {
	assert(socketed > 0);
	assert(gems.size() <= totalNrOfSockets);
	assert(gems.size() == nItemsInSockets);
	for (int i = 0; i < gems.size(); i++) {
		std::cout << gems[i].typeCodeChar << std::endl;
		gems[i].writeHeader(writer);
		writer.flushBufferAligned();
	}
}

void ComplexItem::writeQuality() {
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
}

void ComplexItem::writeMagicList(std::vector<MagicAttribute> &magicList, BitWriter &writer) {
  for (int j = 0; j < magicList.size(); j++) {
    writeSingleMagic(magicList[j]);
  }
  writer.writeBit(0x1FF, 9, true);
}

void ComplexItem::writeSingleMagic(MagicAttribute &magic) {

}

bool ComplexItem::isTomeItem() {
	for (int i = 0; i < TomeCodeLength; i++) {
		if (typeCodeChar.substr(0, 3) == TomeCode[i]) {
			return true;
		}
	}
	return false;
}

bool ComplexItem::isDurableItem() {
/*
	for (int i = 0; i < TomeCodeLength; i++) {
		if (typeCodeChar.substr(0, 3) == TomeCode[i]) {
			return true;
		}
	}
	return false;
*/
}

bool ComplexItem::isQuantityItem() {
	for (int i = 0; i < QuantityCodeLength; i++) {
		if (typeCodeChar.substr(0, 3) == QutityCode[i]) {
			return true;
		}
	}
	return false;
}
