/*
 * Deserializer.h
 *
 *  Created on: 23.02.2013
 *      Author: brigada
 */

#ifndef DESERIALIZER_H_
#define DESERIALIZER_H_

#define ET_EXTERNAL 0x01
#define ET_DYNAMIC  0x02

#include "BinaryStream.h"
#include "Amf3Type.h"
#include "Amf3TypeObject.h"
#include "Amf3TypeInteger.h"
#include <map>
#include <vector>

typedef struct {
	std::string name;
	uint8_t encoding;
	std::vector<std::string> properties;
} ReferenceDefenitionType;

typedef std::vector<Amf3TypeObject> ReferenceObjectsType;

typedef std::vector<ReferenceDefenitionType> ReferenceDefenitionsType;

typedef std::vector<std::string> ReferenceStringsType;

class Deserializer {
public:
	Deserializer(BinaryStream &stream);
	virtual ~Deserializer();
	Amf3Type readType();
	Amf3TypeObject readObject();
	Amf3TypeObject readArray();
	uint32_t readInteger();
	std::string readString();

protected:
	BinaryStream &_stream;
	ReferenceObjectsType _referenceObjects;
	ReferenceDefenitionsType _referenceDefenitions;
	ReferenceStringsType _referenceStrings;
};

#endif /* DESERIALIZER_H_ */
