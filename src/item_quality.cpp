#include <cassert>
#include "items.h"


void ItemQualityLow::writeQuality(BitWriter &writer) {
  assert(lowID >= 0 && lowID <= 3);
  writer.writeBit(lowID, 3, true);
}

void ItemQualityNormal::writeQuality(BitWriter &writer) { 
  // do nothing
}

void ItemQualityMagicEnhanced::writeQuality(BitWriter &writer) {
  assert(isValidID(prefixID, MagicalPrefixes, MagicalPrefixesLength));
  assert(isValidID(suffixID, MagicalSuffixes, MagicalSuffixesLength));
  writer.writeBit(prefixID, 11, true);
  writer.writeBit(suffixID, 11, true);
}

void ItemQualityRareCrafted::writeQuality(BitWriter &writer) {
  // rare 1
  assert(isValidID(rareID1, RareNames, RareNamesLength));
  writer.writeBit(rareID1, 8, true);
  // rare 2
  assert(isValidID(rareID2, RareNames, RareNamesLength));
  writer.writeBit(rareID2, 8, true);

	// Array of 6 possible prefixes and suffixes. First read 1 bit. If 1, read 11 more
	// for the prefix/suffix id defined in MagicPrefix.txt and MagicSuffix.txt.
	// Even indices are prefixes, odd suffixes.
	for (int i = 0; i < 6; i++) {
    int idx = i / 2;
    if (i % 2 == 0) { // prefix
      if (idx < preCnt) {
        writer.writeBit(1, 1, true);
        writer.writeBit(prefix[idx], 11, true);
      } else {
        writer.writeBit(0, 1, true);
      }
    } else { // suffix
      if (idx < sufCnt) {
        writer.writeBit(1, 1, true);
        writer.writeBit(suffix[idx], 11, true);
      } else {
        writer.writeBit(0, 1, true);
      }
    }
	}

}

void ItemQualityUnique::writeQuality(BitWriter &writer) {
  assert(isValidID(uniqueID, UniqueNames, UniqueNamesLength));
  writer.writeBit(uniqueID, 12, true);
}

void ItemQualityPartOfSet::writeQuality(BitWriter &writer) {
  assert(isValidID(setID, SetNames, SetNamesLength));
  writer.writeBit(setID, 12, true);
}
