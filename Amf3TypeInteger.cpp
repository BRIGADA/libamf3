/*
 * Amf3TypeInteger.cpp
 *
 *  Created on: 23.02.2013
 *      Author: brigada
 */

#include "Amf3TypeInteger.h"

Amf3TypeInteger::Amf3TypeInteger(int32_t value) :
	Amf3TypeSimple(value)
{
	_type = AMF3_INTEGER;
	std::cout<<">>> "<< __FUNCTION__<<std::endl;
}

Amf3TypeInteger::~Amf3TypeInteger() {
	std::cout<<">>> "<< __FUNCTION__<<std::endl;
}

