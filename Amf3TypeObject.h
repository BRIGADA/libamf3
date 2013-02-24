/*
 * Amf3TypeObject.h
 *
 *  Created on: 23.02.2013
 *      Author: brigada
 */

#ifndef AMF3TYPEOBJECT_H_
#define AMF3TYPEOBJECT_H_

#include "Amf3Type.h"
#include <map>
#include <vector>

typedef std::map<std::string, Amf3Type> ObjectPropertiesType;
typedef std::vector<Amf3Type> ArrayElementsType;

class Amf3TypeObject: public Amf3Type {
public:
	Amf3TypeObject();
	virtual ~Amf3TypeObject();
	ObjectPropertiesType properties;
	ArrayElementsType elements;
};

#endif /* AMF3TYPEOBJECT_H_ */
