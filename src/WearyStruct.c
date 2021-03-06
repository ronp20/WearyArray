/*
 * WearyStruct.c
 *
 *  Created on: 4 Mar 2021
 *      Author: ron_po
 */
#include "WearyStruct.h"
#include <stdlib.h>
#include <stdio.h>


WearyData* WearyDataCreate(uint64_t p_value)
{
	WearyData* wearyData = NULL;
	wearyData = (WearyData*)malloc(sizeof(WearyData));
	if(wearyData != NULL)
	{
		wearyData->isVisited = FALSE;
		wearyData->value = p_value;
//		wearyData->left = NULL;
//		wearyData->right = NULL;
	}

	return wearyData;
}

void WearyDataCDestroy(WearyData* p_wearyData)
{
	if(p_wearyData != NULL)
	{
		free(p_wearyData);
	}
}
//
//void WearyDataCAddLeftNode(WearyData* p_current, WearyData* p_left)
//{
//	if(p_current != NULL)
//	{
//		p_current->left = p_left;
//	}
//}
//
//void WearyDataCAddRightNode(WearyData* p_current, WearyData* p_right)
//{
//	if(p_current != NULL)
//	{
//		p_current->right = p_right;
//	}
//}
//
//WearyData* WearyDataCGetLeftNode(const WearyData* p_wearyData)
//{
//	WearyData* localWearyData = NULL;
//	if(p_wearyData != NULL)
//	{
//		localWearyData = p_wearyData->left;
//	}
//
//	return localWearyData;
//}
//
//WearyData* WearyDataCGetRightNode(const WearyData* p_wearyData)
//{
//	WearyData* localWearyData = NULL;
//	if(p_wearyData != NULL)
//	{
//		localWearyData = p_wearyData->right;
//	}
//
//	return localWearyData;
//}

RETURN_STATUS WearyDataIsVisited(const WearyData* p_wearyData)
{
	RETURN_STATUS retValue = ERROR;
	if(p_wearyData != NULL && p_wearyData->isVisited == TRUE)
	{
		retValue = OK;
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

