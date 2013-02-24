/*
 * Amf3TypeSimple.h
 *
 *  Created on: 23.02.2013
 *      Author: brigada
 */

#ifndef AMF3TYPESIMPLE_H_
#define AMF3TYPESIMPLE_H_

#include "Amf3Type.h"

template <class T> class Amf3TypeSimple: public Amf3Type {
public:
	Amf3TypeSimple();
	Amf3TypeSimple(T value) { _value = value; }
	virtual ~Amf3TypeSimple() {}
	T value() { return _value; }
	void setValue(T value) { _value = value; }
protected:
	T _value;

};

#endif /* AMF3TYPESIMPLE_H_ */
