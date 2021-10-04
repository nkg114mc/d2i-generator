#include <iostream>

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

void createComplexItem(std::string fileName) {

  BitWriter writer;
  writer.initFile(fileName);

  ComplexItem item;

  item.identified = 1;
  item.socketed = 0;
  item.newbee = 1;
  item.starterItem = 0;
  item.simpleItem = 0;
  item.ethereal = 0;
	item.personalized = 0;
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
	item.quality = Normal;
	item.isMultiplePictures = 0;
	item.pictureID = 0;
  item.isClassSpecific = 0;
  item.classSpecificCode = 0;

	item.givenRunewordCode = 0; // MARK: Runeword data
	//char personName[64];
  item.timestamp = 0;

  item.defRating = 2047;
  item.maxDurability = 40;
  item.quantity = 0;
  item.totalNrOfSockets = 0;

  item.writeToFile(writer);
  writer.close();
}



int main() {
  createComplexItem("testitem.d2i");
  return 0;
}


/*
	var readBits int
	// offset: 0 "J"
	j := ibr.ReadBits64(8, false)
	readBits += 8

	// offset: 8, "M"
	m := ibr.ReadBits64(8, false)
	readBits += 8

	if fmt.Sprintf("%c", j) != "J" || fmt.Sprintf("%c", m) != "M" {
		return errors.New("failed to find item header JM")
	}

	// offset: 16, unknown
	ibr.ReadBits64(4, true)
	readBits += 4

	// offset: 20
	item.Identified = reverseBits(ibr.ReadBits64(1, true), 1)
	readBits++

	// offset: 21, unknown
	ibr.ReadBits64(6, true)
	readBits += 6

	// offset: 27
	item.Socketed = reverseBits(ibr.ReadBits64(1, true), 1)
	readBits++

	// offset 28, unknown
	ibr.ReadBits64(1, true)
	readBits++

	// offset 29
	item.New = reverseBits(ibr.ReadBits64(1, true), 1)
	readBits++

	// offset 30, unknown
	_ = reverseBits(ibr.ReadBits64(2, true), 2)
	readBits += 2

	// offset 32
	item.IsEar = reverseBits(ibr.ReadBits64(1, true), 1)
	readBits++

	// offset 33
	item.StarterItem = reverseBits(ibr.ReadBits64(1, true), 1)
	readBits++

	// offset 34, unknown
	_ = reverseBits(ibr.ReadBits64(3, true), 3)
	readBits += 3

	// offset 37, if it's a simple item, it only contains 111 bits data
	item.SimpleItem = reverseBits(ibr.ReadBits64(1, true), 1)
	readBits++

	// offset 38
	item.Ethereal = reverseBits(ibr.ReadBits64(1, true), 1)
	readBits++

	// offset 39, unknown
	_ = reverseBits(ibr.ReadBits64(1, true), 1)
	readBits++

	// offset 40
	item.Personalized = reverseBits(ibr.ReadBits64(1, true), 1)
	readBits++

	// offset 41, unknown
	_ = reverseBits(ibr.ReadBits64(1, true), 1)
	readBits++

	// offset 42
	item.GivenRuneword = reverseBits(ibr.ReadBits64(1, true), 1)
	readBits++

	// offset 43, unknown
	_ = reverseBits(ibr.ReadBits64(5, true), 5)
	readBits += 5

	// offset 48
	item.Version = reverseBits(ibr.ReadBits64(8, true), 8)
	readBits += 8

	// offset 56, unknown
	_ = reverseBits(ibr.ReadBits64(2, true), 2)
	readBits += 2

	// offset 58
	item.LocationID = reverseBits(ibr.ReadBits64(3, true), 3)
	readBits += 3

	// offset 61
	item.EquippedID = reverseBits(ibr.ReadBits64(4, true), 4)
	readBits += 4

	// offset 65
	item.PositionX = reverseBits(ibr.ReadBits64(4, true), 4)
	readBits += 4

	// offset 69
	item.PositionY = reverseBits(ibr.ReadBits64(3, true), 3)
	readBits += 3

	// offset 72
	_ = reverseBits(ibr.ReadBits64(1, true), 1)
	readBits++

	// offset 73, if item is neither equipped or in the belt, this tells us where it is.
	item.AltPositionID = reverseBits(ibr.ReadBits64(3, true), 3)
	readBits += 3

	if item.IsEar == 0 {
		// offset 76, item type, 4 chars, each 8 bit (not byte aligned)
		var itemType string
		for j := 0; j < 4; j++ {
			itemType += fmt.Sprintf("%c", reverseBits(ibr.ReadBits64(8, true), 8))
		}

		item.Type = strings.Trim(itemType, " ")
		item.TypeID = item.getTypeID()

		switch item.TypeID {
		case armor:
			typeName, ok := armorCodes[item.Type]
			if ok {
				item.TypeName = typeName
			}
		case shield:
			typeName, ok := shieldCodes[item.Type]
			if ok {
				item.TypeName = typeName
			}
		case weapon:
			typeName, ok := weaponCodes[item.Type]
			if ok {
				item.TypeName = typeName
			}

			// Weapons have base damage, so we'll check our
			// map for the base damage of this weapon type.
			baseDamage, ok := weaponDamageMap[item.Type]
			if ok {

				// If the item is ethereal we need to add 50% enhanced
				// damage to the base damage.
				if item.Ethereal == 1 {
					baseDamage.Min = int((float64(baseDamage.Min) * 1.5))
					baseDamage.Max = int((float64(baseDamage.Max) * 1.5))
					baseDamage.TwoMin = int((float64(baseDamage.TwoMin) * 1.5))
					baseDamage.TwoMax = int((float64(baseDamage.TwoMax) * 1.5))
				}

				item.BaseDamage = &baseDamage

			}

		case other:
			typeName, ok := miscCodes[item.Type]
			if ok {
				item.TypeName = typeName
			}
		}

		// offset 108
		// If sockets exist, read the items, they'll be 108 bit basic items * nrOfSockets
		item.NrOfItemsInSockets = reverseBits(ibr.ReadBits64(3, true), 3)
	} else {

		// offset 76, the item is an ear, we need to read the ear data.
		earClass := reverseBits(ibr.ReadBits64(3, true), 3)
		readBits += 3

		earLevel := reverseBits(ibr.ReadBits64(7, true), 7)
		readBits += 7

		var name string
		for {
			c := reverseBits(ibr.ReadBits64(7, true), 7)

			if c == 0 {
				break
			}
			readBits += 7
			name += fmt.Sprintf("%c", c)
		}

		item.EarAttributes = earAttributes{
			Class: earClass,
			Level: earLevel,
			Name:  name,
		}

		// If the ear is not byte aligned, we'll have to byte align it before
		// reading the next property, so we'll simply queue the reader at the next
		// byte boundary by calculating the remainder.
		remainder := readBits % 8
		if remainder > 0 {
			bitsToAlign := uint(8 - remainder)
			_ = reverseBits(ibr.ReadBits64(bitsToAlign, true), bitsToAlign)
		}
	}
*/