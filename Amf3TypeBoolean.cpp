/*
 * Amf3TypeBoolean.cpp
 *
 *  Created on: 23.02.2013
 *      Author: brigada
 */

#include "Amf3TypeBoolean.h"

Amf3TypeBoolean::Amf3TypeBoolean(bool value) : Amf3TypeSimple(value) {
}

Amf3TypeBoolean::~Amf3TypeBoolean() {
}

uint8_t Amf3TypeBoolean::type() {
	return _value ? AMF3_BOOLEAN_TRUE : AMF3_BOOLEAN_FALSE;
}
