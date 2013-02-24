/*
 * main.cpp
 *
 *  Created on: 23.02.2013
 *      Author: brigada
 */

#include <fstream>
#include "BinaryStream.h"
#include "Deserializer.h"

void printType(Amf3Type * ptr, unsigned int indent);
void printTypeObject(Amf3TypeObject *o, unsigned int indent);

void printType(Amf3Type * ptr, unsigned int indent)
{
	switch(ptr->type())
	{
	case AMF3_OBJECT:
		printTypeObject(reinterpret_cast<Amf3TypeObject*>(ptr), indent);
		break;
	default:
		throw "UNKNOWN TYPE";
	}
}

void printTypeObject(Amf3TypeObject *o, unsigned int indent)
{
	std::cout<<"Object:"<<std::endl;
	std::cout<<"properties="<<o->properties.size()<<std::endl;

	ObjectPropertiesType::iterator it = o->properties.begin();
	while(it != o->properties.end()) {
		std::cout<<"  "<<(*it).first<<std::endl;
		++it;
	}
}

int main(int argc, char* argv[])
{
	if(argc < 2) return -1;

	std::fstream file(argv[1], std::fstream::in);
	BinaryStream bs(file);

	Deserializer decoder(bs);

	try
	{
		Amf3Type ttt = decoder.readType();

		std::cout<<"type="<<(int)ttt.type()<<std::endl;
		printType(&ttt, 0);
	}
	catch (const char * msg) {
		std::cout<<"Exception: '"<<msg<<"'"<<std::endl;
	}
	catch (...)
	{
		std::cout<<"Unknown exception"<<std::endl;
	}

}


