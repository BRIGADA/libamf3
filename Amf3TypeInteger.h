/*
 * Amf3TypeInteger.h
 *
 *  Created on: 23.02.2013
 *      Author: brigada
 */

#ifndef AMF3TYPEINTEGER_H_
#define AMF3TYPEINTEGER_H_

#include "Amf3TypeSimple.h"

class Amf3TypeInteger: public Amf3TypeSimple<int32_t> {
public:
	Amf3TypeInteger(int32_t value = 0);
	virtual ~Amf3TypeInteger();
};

#endif /* AMF3TYPEINTEGER_H_ */
