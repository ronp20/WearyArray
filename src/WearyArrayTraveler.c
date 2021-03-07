/*
 * FileParser.c
 *
 *  Created on: 6 Mar 2021
 *      Author: ron_po
 */
#include "WearyArrayTraveler.h"
//#include "Defines.h"
#include "WearyArray.h"
#include <stdio.h>
#include <string.h>


static RETURN_STATUS BuildArrayFromJson(WearyArray* p_array, FILE* p_fp);
//static uint64_t* FileParserParseCSV(const char* p_path);
//static uint64_t* FileParserParseTSV(const char* p_path);

#define JSON_SUFFIX ".json"
#define CSV_SUFFIX ".csv"
#define TSV_SUFFIX ".tsv"


RETURN_STATUS BuildArrayFromJson(WearyArray* p_array, FILE* p_fp)
{
	RETURN_STATUS retValue = OK;
	char* line;
	size_t len = 0;
	char* token;
	char delimiter[] = " ,";
	uint64_t value = 0;
	char* strToSave;
	ssize_t read = getline(&line, &len, p_fp);
	if(read != -1)
	{
		token = strtok_r(line, delimiter, &strToSave);
		sscanf(token, "[%lu", &value);
		WearyArrayPush(p_array, value);
		while(1)
		{
			token = strtok_r(NULL, delimiter, &strToSave);
			if(token != NULL)
			{
				sscanf(token, "%lu", &value);
				if(WearyArrayPush(p_array, value) != OK)
				{
					retValue = ERROR;
					break;
				}
			}
			else
			{
				break;
			}
		}
	}
	else
	{
		retValue = ERROR;
	}

	if(line != NULL)
	{
		FREE(line);
	}

	return retValue;
}

void WearyArrayTravelerDestroy(WearyArrayTraveler* p_wearyArrayTraveler)
{
	if(p_wearyArrayTraveler != NULL)
	{
		WearyArrayDestroy(p_wearyArrayTraveler->wearyArray);
		FREE(p_wearyArrayTraveler);
	}
}

WearyArrayTraveler* WearyArrayTravelerCreate(const char* p_path)
{
	WearyArrayTraveler* localWearyArrayTraveler = NULL;
	RETURN_STATUS currentStatus = OK;

	if(p_path != NULL)
	{
		localWearyArrayTraveler = (WearyArrayTraveler*)malloc(sizeof(WearyArrayTraveler));
		if(localWearyArrayTraveler != NULL)
		{
			localWearyArrayTraveler->wearyArray = WearyArrayCreate();
			if(localWearyArrayTraveler->wearyArray != NULL)
			{
				FILE* fp = fopen(p_path, "r");
				if(p_path != NULL)
				{
					if(strstr(p_path, JSON_SUFFIX) != NULL)
					{
						currentStatus = BuildArrayFromJson(localWearyArrayTraveler->wearyArray, fp);
					}
					else if(strstr(p_path, CSV_SUFFIX) != NULL)
					{
			//			localArray = FileParserParseCSV(p_path);
					}
					else if(strstr(p_path, TSV_SUFFIX) != NULL)
					{
			//			localArray = FileParserParseTSV(p_path);
					}

					fclose(fp);
				}
				else
				{
					currentStatus = ERROR;
				}

				if(currentStatus == ERROR)
				{
					FREE(localWearyArrayTraveler->wearyArray);
					FREE(localWearyArrayTraveler);
				}
			}
			else
			{
				FREE(localWearyArrayTraveler);
			}
		}
	}

	return localWearyArrayTraveler;
}

BOOLEAN WearyArrayTraveleIsTraveler(WearyArrayTraveler* p_wearyArrayTraveler)
{
	BOOLEAN retValue = FALSE;
	if(p_wearyArrayTraveler != NULL)
	{
		retValue = WearyArrayIsTraveler(p_wearyArrayTraveler->wearyArray);
	}

	return retValue;
}

void WearyArrayTravelerPrint(const WearyArrayTraveler* p_wearyArrayTraveler)
{
	if(p_wearyArrayTraveler != NULL)
	{
		WearyArrayPrint(p_wearyArrayTraveler->wearyArray);
	}
}
