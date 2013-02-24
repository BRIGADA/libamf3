/*
 * Amf3TypeNumber.h
 *
 *  Created on: 23.02.2013
 *      Author: brigada
 */

#ifndef AMF3TYPENUMBER_H_
#define AMF3TYPENUMBER_H_

#include "Amf3TypeSimple.h"

class Amf3TypeNumber: public Amf3TypeSimple<double> {
public:
	Amf3TypeNumber(double value = 0);
	virtual ~Amf3TypeNumber();
};

#endif /* AMF3TYPENUMBER_H_ */
