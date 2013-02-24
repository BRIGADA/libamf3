/*
 * utils.cpp
 *
 *  Created on: 23.02.2013
 *      Author: brigada
 */

#include "utils.h"
#include <stdarg.h>
#include <stdio.h>

std::string string_sprintf(std::string format, ...) {
	va_list ap;
	va_start(ap, format);

	char *buf = NULL;
	int length = vasprintf(&buf, format.data(), ap);
	va_end(ap);

	if(length == -1) {
		return "SPRINTF ERROR";
	}

	std::string result(buf, length);
	delete [] buf;

	return result;
}
