/*
 * Amf3TypeString.cpp
 *
 *  Created on: 23.02.2013
 *      Author: brigada
 */

#include "Amf3TypeString.h"

Amf3TypeString::Amf3TypeString(std::string value) : Amf3TypeSimple(value) {
	_type = AMF3_STRING;
}

Amf3TypeString::~Amf3TypeString() {
}
