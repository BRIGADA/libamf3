/*
 * Deserializer.cpp
 *
 *  Created on: 23.02.2013
 *      Author: brigada
 */

#include "Deserializer.h"
#include "Amf3TypeBoolean.h"
#include "Amf3TypeString.h"
#include "Amf3TypeNumber.h"
#include "utils.h"
#include <iostream>

Deserializer::Deserializer(BinaryStream &stream) : _stream(stream) {
	std::cout<<">>> "<< __FUNCTION__<<std::endl;
}

Deserializer::~Deserializer() {
	std::cout<<">>> "<< __FUNCTION__<<std::endl;
}

Amf3Type Deserializer::readType() {
	std::cout<<">>> "<< __FUNCTION__<<std::endl;

	uint8_t t = _stream.read8();
	switch(t)
	{
	case AMF3_BOOLEAN_FALSE:
		return Amf3TypeBoolean(false);

	case AMF3_BOOLEAN_TRUE:
		return Amf3TypeBoolean(true);

	case AMF3_OBJECT:
		return this->readObject();

	case AMF3_INTEGER:
		return Amf3TypeInteger(this->readInteger());

	case AMF3_NUMBER:
		return Amf3TypeNumber(_stream.readDouble());

	case AMF3_ARRAY:
		return this->readArray();
	case AMF3_STRING:
		return Amf3TypeString(this->readString());

	default:
		throw string_sprintf("Unknown type 0x%02x", t).data();
	}
}

Amf3TypeObject Deserializer::readObject() {
	std::cout<<">>> "<< __FUNCTION__<<std::endl;

	uint32_t traitsInfo = this->readInteger();
	std::cout<<string_sprintf("traitInfo=0x%08x", traitsInfo)<<std::endl;

	bool storedObject = (traitsInfo & 1) == 0;
	traitsInfo = traitsInfo >> 1;

	std::cout<<"storedObject="<<storedObject<<std::endl;
	if(storedObject) {
		return _referenceObjects[traitsInfo];
	}
	else {
		bool storedClass = (traitsInfo & 1) == 0;
		traitsInfo = traitsInfo >> 1;
		ReferenceDefenitionType classDef;

		std::cout<<"storedClass="<<storedClass<<std::endl;
		if(storedClass) {
			classDef = _referenceDefenitions[traitsInfo];
		}
		else {
			classDef.name = this->readString();
			classDef.encoding = traitsInfo & 3;
			traitsInfo = traitsInfo >> 2;
		}

		std::cout<<string_sprintf("name='%s', encoding=0x%x", classDef.name.data(), classDef.encoding)<<std::endl;

		Amf3TypeObject result;

		switch(classDef.encoding) {
		case ET_EXTERNAL:
			std::cout<<"ET_EXTERNAL"<<std::endl;
			if(!storedClass) {
				this->_referenceDefenitions.push_back(classDef);
			}
			throw string_sprintf("Need externalized data...");
			break;

		case ET_DYNAMIC: {
			std::cout<<"ET_DYNAMIC"<<std::endl;

			if(!storedClass) {
				this->_referenceDefenitions.push_back(classDef);
			}

			std::string property;
			while(!(property = this->readString()).empty()) {
				std::cout<<"property='"<<property<<"'"<<std::endl;
				classDef.properties.push_back(property);
				result.properties[property] = this->readType();
			}
			break;
		}
		default:
			std::cout<<"ET_DEFAULT"<<std::endl;
			break;
		}

		return result;
	}

}

uint32_t Deserializer::readInteger() {
	uint8_t count = 1;
	uint8_t intReference = _stream.read8();
	uint32_t result = 0;
	while((intReference & 0x80) && (count < 4)) {
		result = (result << 7) | (intReference & 0x7f);
		intReference = _stream.read8();
		count++;
	}
	if(count < 4) {
		result = (result << 7) | intReference;
	}
	else {
		result = (result << 8) | intReference;
	}

	return result;
}

Amf3TypeObject Deserializer::readArray() {
	uint32_t traitInfo = this->readInteger();
	bool isReference = (traitInfo & 1) == 0;
	traitInfo = traitInfo >> 1;
	if(isReference) {
		return _referenceObjects[traitInfo];
	}

	std::string key;

	Amf3TypeObject result;

	while(!(key = this->readString()).empty()) {
		result.properties[key] = this->readType();
	}

	while(traitInfo) {
		result.elements.push_back(this->readType());
		traitInfo--;
	}

	_referenceObjects.push_back(result);
	return result;
}

std::string Deserializer::readString() {
//	std::cout<<__FUNCTION__<<std::endl;

	uint32_t stringInfo = this->readInteger();
	bool isReference = (stringInfo & 1) == 0;
	stringInfo = stringInfo >> 1;

	if( isReference ) {
		return _referenceStrings[stringInfo];
	}

	if(!stringInfo) {
		return "";
	}

	std::string result = _stream.readBytes(stringInfo);
	_referenceStrings.push_back(result);
	return result;
}
