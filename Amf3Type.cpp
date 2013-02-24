/*
 * Amf3Type.cpp
 *
 *  Created on: 23.02.2013
 *      Author: brigada
 */

#include "Amf3Type.h"

Amf3Type::Amf3Type(uint8_t type) : _type(type) {
}

Amf3Type::~Amf3Type() {
}

uint8_t Amf3Type::type() {
	return _type;
}
