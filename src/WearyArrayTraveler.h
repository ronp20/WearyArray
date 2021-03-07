/*
 * FileParser.h
 *
 *  Created on: 6 Mar 2021
 *      Author: ron_po
 */

#ifndef WEARYARRAYTRAVELER_H_
#define WEARYARRAYTRAVELER_H_
#include "Defines.h"
//#include "WearyArray.h"
#include <stdint.h>

struct WearyArray;

typedef struct WearyArrayTraveler
{
	struct WearyArray* wearyArray;
}WearyArrayTraveler;

WearyArrayTraveler* WearyArrayTravelerCreate(const char* p_path);

BOOLEAN WearyArrayTraveleIsTraveler(WearyArrayTraveler* p_wearyArrayTraveler);

void WearyArrayTravelerDestroy(WearyArrayTraveler* p_wearyArrayTraveler);

void WearyArrayTravelerPrint(const WearyArrayTraveler* p_wearyArrayTraveler);

#endif /* WEARYARRAYTRAVELER_H_ */
