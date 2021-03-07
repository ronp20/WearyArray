/*
 * WearyStruct.c
 *
 *  Created on: 4 Mar 2021
 *      Author: ron_po
 */
#include "WearyData.h"
#include <stdio.h>

WearyData* WearyDataCreate(uint64_t p_value)
{
	WearyData* wearyData = NULL;
	wearyData = (WearyData*)malloc(sizeof(WearyData));
	if(wearyData != NULL)
	{
		wearyData->isVisited = FALSE;
		wearyData->value = p_value;
	}

	return wearyData;
}

void WearyDataCDestroy(WearyData* p_wearyData)
{
	if(p_wearyData != NULL)
	{
		FREE(p_wearyData);
	}
}

BOOLEAN WearyDataIsVisited(const WearyData* p_wearyData)
{
	BOOLEAN retValue = FALSE;
	if(p_wearyData != NULL && p_wearyData->isVisited == TRUE)
	{
		retValue = TRUE;
	}

	return retValue;
}

void WearyDataSetVisited(WearyData* p_wearyData)
{
	if(p_wearyData != NULL)
	{
		p_wearyData->isVisited = TRUE;
	}
}

RETURN_STATUS WearyDataGetValue(const WearyData* p_wearyData, uint64_t* p_output)
{
	RETURN_STATUS retValue = ERROR;
	if(p_wearyData != NULL && p_output != NULL)
	{
		retValue = OK;
		*p_output = p_wearyData->value;
	}

	return retValue;
}

void WearyDataPrint(const WearyData* p_wearyData)
{
	if(p_wearyData != NULL)
	{
		printf("Is Visited = %d, Value = %lu\n", p_wearyData->isVisited, p_wearyData->value);
	}
}

