/*
 * WearyTree.h
 *
 *  Created on: 4 Mar 2021
 *      Author: ron_po
 */

#ifndef WEARY_STRUCT_H_
#define WEARY_STRUCT_H_
#include "Defines.h"
#include <stdint.h>

typedef struct WearyData
{
	BOOLEAN isVisited;
	uint64_t value;
}WearyData;

WearyData* WearyDataCreate(uint64_t p_value);

void WearyDataCDestroy(WearyData* p_wearyData);

BOOLEAN WearyDataIsVisited(const WearyData* p_wearyData);

void WearyDataSetVisited(WearyData* p_wearyData);

RETURN_STATUS WearyDataGetValue(const WearyData* p_wearyData, uint64_t* p_output);

void WearyDataPrint(const WearyData* p_wearyData);

#endif /* WEARY_STRUCT_H_ */
