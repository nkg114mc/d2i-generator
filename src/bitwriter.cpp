
#include <cctype>
#include <cassert>
#include <iostream>

#include "bitwriter.h"

BitWriter::BitWriter() {
  startIdx = 0;
  startBit = 0;
  buffer[0] = 0;
}

void BitWriter::initFile(std::string fileName) {
  outf.open(fileName, std::ios::binary);
}

void BitWriter::close() {
  flushBuffer();
  if (startBit > 0) {
    outf << buffer[0]; // for last bit padding
  }
  outf.close();
}

void BitWriter::writeBit(uint64_t value, int bits, bool reverse) {

  if (bits <= 0) {
    return;
  }

  for (int i = 0; i < bits; i++) {
    //uint64_t mask = 1 << bits;
    //mask -= 1;

    if (reverse) {
      uint8_t b = value & 0x1;
      value = value >> 1;
      addOneBit(b);
    } else {
      int offset = bits - i - 1;
      uint8_t b = (value >> offset) & 0x1;
      addOneBit(b);
    }
  }

  flushBuffer();
}

void BitWriter::flushBuffer() {
  if (startIdx > 0) {
    for (int i = 0; i < startIdx; i++) {
      outf << buffer[i];
    }
    buffer[0] = buffer[startIdx];
    startIdx = 0;

    //std::cout << "call flush" << std::endl;
  }
}

void BitWriter::addOneBit(uint8_t b) {
  assert(startBit < 8 && startBit >= 0);

  buffer[startIdx] = buffer[startIdx] | ((b & 0x01) << startBit);
  startBit++;

  if (startBit >= 8) {
    startIdx++;
    buffer[startIdx] = 0;
    startBit = 0;
  }
}


