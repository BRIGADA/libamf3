/*
 * main.cpp
 *
 *  Created on: 23.02.2013
 *      Author: brigada
 */

#include <fstream>
#include "BinaryStream.h"
#include "Deserializer.h"

void printObject(Amf3TypeObject o);

void printObject(Amf3TypeObject o)
{
	std::cout << "Object {}" << std::endl;
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
		printObject(reinterpret_cast<Amf3TypeObject>(ttt));
	}
	catch (const char * msg) {
		std::cout<<"Exception: '"<<msg<<"'"<<std::endl;
	}
	catch (...)
	{
		std::cout<<"Unknown exception"<<std::endl;
	}

}


