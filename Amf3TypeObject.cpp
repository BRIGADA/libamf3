/*
 * Amf3TypeObject.cpp
 *
 *  Created on: 23.02.2013
 *      Author: brigada
 */

#include "Amf3TypeObject.h"

Amf3TypeObject::Amf3TypeObject() : Amf3Type(AMF3_OBJECT) {
	std::cout<<">>> "<< __FUNCTION__<<std::endl;
}

Amf3TypeObject::~Amf3TypeObject() {
	std::cout<<">>> "<< __FUNCTION__<<std::endl;
}

