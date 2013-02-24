/*
 * Amf3TypeNumber.cpp
 *
 *  Created on: 23.02.2013
 *      Author: brigada
 */

#include "Amf3TypeNumber.h"

Amf3TypeNumber::Amf3TypeNumber(double value) : Amf3TypeSimple(value) {
	_type = AMF3_NUMBER;
}

Amf3TypeNumber::~Amf3TypeNumber() {
}

