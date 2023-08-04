#ifndef BITWRITER_H
#define BITWRITER_H

#include <cstdint>
#include <cctype>
#include <string>
#include <fstream>

class BitWriter
{
private:
	std::ofstream outf;
	uint8_t buffer[256];

	int startBit;
	int startIdx;

	void addOneBit(uint8_t b);
	void flushBuffer();

public:
	BitWriter();
	void writeBit(uint64_t value, int bits, bool reverse);
	void initFile(std::string fileName);
	void flushBufferAligned();
	void close();
};

#endif // #ifndef BITWRITER_H