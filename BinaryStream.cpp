/*
 * BinaryStream.cpp
 *
 *  Created on: 23.02.2013
 *      Author: brigada
 */

#include "BinaryStream.h"

BinaryStream::BinaryStream(std::iostream &stream) : _stream(stream){

}

BinaryStream::~BinaryStream() {

}

std::string BinaryStream::readBytes(uint32_t length) {
	char *buf = new char[length];
	_stream.read(buf, length);
	std::string result(buf, length);
	delete [] buf;
	return result;
}

BinaryStream& BinaryStream::writeBytes(std::string bytes) {
	_stream<<bytes;
	return *this;
}

uint8_t BinaryStream::read8() {
	uint8_t result;
	_stream.read(reinterpret_cast<char*>(&result), 1);
	return result;
}

BinaryStream& BinaryStream::write8(uint8_t value) {
	_stream.write(reinterpret_cast<char*>(&value), 1);
	return *this;
}

uint16_t BinaryStream::read16() {
	return (this->read8() << 8) | read8();
}

BinaryStream& BinaryStream::write16(uint16_t value) {
	write8(value >> 8);
	write8(0xff & value);
	return *this;
}

uint32_t BinaryStream::read32() {
	return (read8()<<24) | (read8()<<16) | (read8()<<8) | read8();
}

BinaryStream& BinaryStream::write32(uint32_t value) {
	write8(value >> 24);
	write8(value >> 16);
	write8(value >> 8);
	write8(value);
	return *this;
}

std::string BinaryStream::readUtf() {
	uint16_t length = read16();
	return readBytes(length);

}

BinaryStream& BinaryStream::writeUtf(std::string value) {
	write16(value.size());
	writeBytes(value);
	return *this;
}

std::string BinaryStream::readLongUtf() {
	uint32_t length = read32();
	return readBytes(length);
}

BinaryStream& BinaryStream::writeLongUtf(std::string value) {
	write32(value.size());
	writeBytes(value);
	return *this;
}

double BinaryStream::readDouble() {
	double result;
	_stream.read(reinterpret_cast<char *>(&result), 8);
	return result;
}
