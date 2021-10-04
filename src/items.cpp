
#include <cassert>
#include "items.h"


void CommonItem::writeHeader(BitWriter &writer) {
  if (isEar) {
    writeEarHeader(writer);
  } else {
    writeNormalHeader(writer);
  }
}

void CommonItem::writeNormalHeader(BitWriter &writer) {

  int headj = (int)'J';
  writer.writeBit(headj, 8, true);
  int headm = (int)'M';
  writer.writeBit(headm, 8, true);

  // unknown
  writer.writeBit(0, 4, true);

  // offset: 20
  writer.writeBit(identified, 1, true);

	// offset: 21, unknown
  writer.writeBit(0, 6, true);

	// offset: 27
  writer.writeBit(socketed, 1, true);

	// offset 28, unknown
  writer.writeBit(0, 1, true);

	// offset 29
  writer.writeBit(newbee, 1, true);

	// offset 30, unknown
  writer.writeBit(0, 2, true);

	// offset 32
  writer.writeBit(0, 1, true); // not ear

	// offset 33
  writer.writeBit(starterItem, 1, true);

	// offset 34, unknown
  writer.writeBit(0, 3, true);

	// offset 37, if it's a simple item, it only contains 111 bits data
  writer.writeBit(simpleItem, 1, true);

	// offset 38
  writer.writeBit(ethereal, 1, true);

	// offset 39, unknown
  writer.writeBit(0, 1, true);

	// offset 40
  writer.writeBit(personalized, 1, true);

	// offset 41, unknown
  writer.writeBit(0, 1, true);

	// offset 42
  writer.writeBit(isGivenRuneword, 1, true);

	// offset 43, unknown
  writer.writeBit(0, 5, true);

	// offset 48
  writer.writeBit(version, 8, true);

	// offset 56, unknown
  writer.writeBit(0, 2, true);

	// offset 58
  writer.writeBit(locationID, 3, true);

	// offset 61
  writer.writeBit(equippedID, 4, true);

	// offset 65
  writer.writeBit(positionX, 4, true);

	// offset 69
  writer.writeBit(positionY, 3, true);

	// offset 72
  writer.writeBit(0, 1, true);

	// offset 73, if item is neither equipped or in the belt, this tells us where it is.
  writer.writeBit(altPositionID, 3, true);

  // offset 76, item type, 4 chars, each 8 bit (not byte aligned)
  assert(typeCodeChar.length() == 4);
  uint64_t typeCode = convertTypeCode(typeCodeChar.c_str());
  writer.writeBit(typeCode, 32, true);
	
  // offset 108
  writer.writeBit(nItemsInSockets, 3, true);
}

void CommonItem::writeEarHeader(BitWriter &writer) {

}

uint32_t CommonItem::convertTypeCode(const char* str4Code) {
  uint64_t res = 0;
  for (int i = 0; i < 4; i++) {
    uint64_t code8 = str4Code[i];
    res = res | (code8 << (i * 8));
  }
  return res;
}