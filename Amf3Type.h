/*
 * Amf3Type.h
 *
 *  Created on: 23.02.2013
 *      Author: brigada
 */

#ifndef AMF3TYPE_H_
#define AMF3TYPE_H_

#include <inttypes.h>
#include <iostream>

#define AMF3_UNDEFINED 			0x00
#define AMF3_NULL               0x01
#define AMF3_BOOLEAN_FALSE      0x02
#define AMF3_BOOLEAN_TRUE       0x03
#define AMF3_INTEGER            0x04
#define AMF3_NUMBER             0x05
#define AMF3_STRING             0x06
#define AMF3_XML                0x07
#define AMF3_DATE               0x08
#define AMF3_ARRAY              0x09
#define AMF3_OBJECT             0x0A
#define AMF3_XMLSTRING          0x0B
#define AMF3_BYTEARRAY          0x0C
#define AMF3_OBJECT_ENCODING    0x03

class Amf3Type {
public:
	Amf3Type(uint8_t type = AMF3_UNDEFINED);
	virtual ~Amf3Type();
	virtual uint8_t type();
protected:
	uint8_t _type;
};

#endif /* AMF3TYPE_H_ */
