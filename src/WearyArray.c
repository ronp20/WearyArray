/*
 * WearyArray.c
 *
 *  Created on: 5 Mar 2021
 *      Author: ron_po
 */
#include "WearyArray.h"
#include <stdio.h>
#include <stdlib.h>

#define INIT_CAPACITY 16

static RETURN_STATUS WearyArrayRealloc(WearyArray* p_wearyArray);

WearyArray* WearyArrayCreate()
{
	WearyArray* localWearyArray = (WearyArray*)malloc(sizeof(WearyArray));
	if(localWearyArray != NULL)
	{
		localWearyArray->wearyArr = (WearyData**)malloc(sizeof(WearyData) * INIT_CAPACITY);
		if(localWearyArray->wearyArr != NULL)
		{
			localWearyArray->size = 0;
			localWearyArray->capacity = INIT_CAPACITY;
		}
		else
		{
//			free(localWearyArray);
//			localWearyArray = NULL;
			FREE(localWearyArray);
		}
	}

	return localWearyArray;
}

void WearyArrayDestroy(WearyArray* p_wearyArray)
{
	if(p_wearyArray != NULL)
	{
		for(int i = 0; i < p_wearyArray->size; ++i)
		{
			WearyDataCDestroy(p_wearyArray->wearyArr[i]);
		}

		FREE(p_wearyArray->wearyArr);
	}

	FREE(p_wearyArray);
}

static RETURN_STATUS WearyArrayRealloc(WearyArray* p_wearyArray)
{
	RETURN_STATUS retValue = ERROR;
	WearyData** localWearyData = (WearyData**)realloc(p_wearyArray->wearyArr, sizeof(WearyData) * p_wearyArray->capacity * 2);
	if(localWearyData != NULL)
	{
		retValue = OK;
		p_wearyArray->capacity *= 2;
		p_wearyArray->wearyArr = localWearyData;
	}

	return retValue;
}


RETURN_STATUS WearyArrayPush(WearyArray* p_wearyArray, uint64_t p_value)
{
	RETURN_STATUS retValue = OK;
	if(p_wearyArray != NULL)
	{
		if(p_wearyArray->size == p_wearyArray->capacity)
		{
			retValue = WearyArrayRealloc(p_wearyArray);
		}

		if(retValue == OK)
		{
			WearyData* localWearyData = WearyDataCreate(p_value);
			if(localWearyData != NULL)
			{
				p_wearyArray->wearyArr[(p_wearyArray->size)++] = localWearyData;
			}
			else
			{
				retValue = ERROR;
			}
		}
	}
	else
	{
		retValue = ERROR;
	}

	return retValue;
}

static BOOLEAN IsTravelerRec(WearyData** p_wearyData, uint64_t p_currentIndex, uint64_t p_arraSize)
{
	uint64_t dataValue;
	if(p_currentIndex > p_arraSize ||
			WearyDataIsVisited(p_wearyData[p_currentIndex]) == OK)
	{
		return FALSE;
	}

	WearyDataSetVisited(p_wearyData[p_currentIndex]);
	if(p_currentIndex + 1 == p_arraSize)
	{
		return TRUE;
	}

	if(WearyDataGetValue(p_wearyData[p_currentIndex], &dataValue) == ERROR ||
		p_currentIndex + dataValue > p_arraSize)
	{
		return FALSE;
	}


	if(IsTravelerRec(p_wearyData, p_currentIndex + dataValue, p_arraSize) == TRUE)
	{
		return TRUE;
	}
	else
	{
		return IsTravelerRec(p_wearyData, p_currentIndex - dataValue, p_arraSize);
	}

}

BOOLEAN WearyArrayIsTraveler(WearyArray* p_wearyArray)
{
	BOOLEAN retValue = FALSE;
	if(p_wearyArray != NULL)
	{
		retValue = IsTravelerRec(p_wearyArray->wearyArr, 0, p_wearyArray->size);
	}

	return retValue;
}

void WearyArrayPrint(const WearyArray* p_wearyArray)
{
	if(p_wearyArray != NULL)
	{
		for(int i = 0; i < p_wearyArray->size; ++i)
		{
			WearyDataPrint(p_wearyArray->wearyArr[i]);
		}
		printf("Size = %lu, capacity = %lu\n", p_wearyArray->size, p_wearyArray->capacity);
	}
}
