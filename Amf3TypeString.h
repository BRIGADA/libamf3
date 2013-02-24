/*
 * Amf3TypeString.h
 *
 *  Created on: 23.02.2013
 *      Author: brigada
 */

#ifndef AMF3TYPESTRING_H_
#define AMF3TYPESTRING_H_

#include "Amf3TypeSimple.h"

class Amf3TypeString: public Amf3TypeSimple<std::string> {
public:
	Amf3TypeString(std::string value = "");
	virtual ~Amf3TypeString();
};

#endif /* AMF3TYPESTRING_H_ */
