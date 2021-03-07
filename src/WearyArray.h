/*
 * WearyArray.h
 *
 *  Created on: 5 Mar 2021
 *      Author: ron_po
 */

#ifndef WEARYARRAY_H_
#define WEARYARRAY_H_
#include "WearyData.h"

typedef struct WearyArray
{
	WearyData** wearyArr;
	uint64_t capacity;
	uint64_t size;
}WearyArray;

WearyArray* WearyArrayCreate();

void WearyArrayDestroy(WearyArray* p_wearyArray);

RETURN_STATUS WearyArrayPush(WearyArray* p_wearyArray, uint64_t p_value);

BOOLEAN WearyArrayIsTraveler(WearyArray* p_wearyArray);

void WearyArrayPrint(const WearyArray* p_wearyArray);

#endif /* WEARYARRAY_H_ */
