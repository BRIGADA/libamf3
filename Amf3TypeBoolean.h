/*
 * Amf3TypeBoolean.h
 *
 *  Created on: 23.02.2013
 *      Author: brigada
 */

#ifndef AMF3TYPEBOOLEAN_H_
#define AMF3TYPEBOOLEAN_H_

#include "Amf3TypeSimple.h"

class Amf3TypeBoolean : public Amf3TypeSimple<bool> {
public:
	Amf3TypeBoolean(bool value = false);
	virtual ~Amf3TypeBoolean();

	virtual uint8_t type();
};

#endif /* AMF3TYPEBOOLEAN_H_ */
