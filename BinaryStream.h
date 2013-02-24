/*
 * BinaryStream.h
 *
 *  Created on: 23.02.2013
 *      Author: brigada
 */

#ifndef BINARYSTREAM_H_
#define BINARYSTREAM_H_

#include <iostream>
#include <inttypes.h>

class BinaryStream {
public:
	BinaryStream(std::iostream &stream);
	virtual ~BinaryStream();

	std::string readBytes(uint32_t length);
	BinaryStream& writeBytes(std::string bytes);

	uint8_t read8();
	BinaryStream& write8(uint8_t value);

	uint16_t read16();
	BinaryStream& write16(uint16_t value);

	uint32_t read32();
	BinaryStream& write32(uint32_t value);

	std::string readUtf();
	BinaryStream& writeUtf(std::string value);

	std::string readLongUtf();
	BinaryStream& writeLongUtf(std::string value);

	double readDouble();

protected:
	std::iostream &_stream;
};

#endif /* BINARYSTREAM_H_ */
