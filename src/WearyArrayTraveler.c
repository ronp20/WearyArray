/*
 * FileParser.c
 *
 *  Created on: 6 Mar 2021
 *      Author: ron_po
 */
#include "WearyArrayTraveler.h"
#include "WearyArray.h"
#include <stdio.h>
#include <string.h>

static RETURN_STATUS BuildArrayFromJson(WearyArray* p_array, FILE* p_fp);
static RETURN_STATUS BuildArrayFromCSV(WearyArray* p_array, FILE* p_fp);
static RETURN_STATUS BuildArrayFromTSV(WearyArray* p_array, FILE* p_fp);
static RETURN_STATUS BuildArray(WearyArray* p_array, FILE* p_fp, const  char* p_delimiter,  uint64_t p_lineOffset);
static FILE_SUFFIX GetFileSuffix(const char* p_filePath);

#define JSON_SUFFIX ".json"
#define CSV_SUFFIX ".csv"
#define TSV_SUFFIX ".tsv"

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
	FILE_SUFFIX fileSuffix = NOT_SUPPORT;
	FILE* fp = NULL;

	if(p_path != NULL)
	{
		localWearyArrayTraveler = (WearyArrayTraveler*)malloc(sizeof(WearyArrayTraveler));
		if(localWearyArrayTraveler != NULL)
		{
			localWearyArrayTraveler->wearyArray = WearyArrayCreate();
			if(localWearyArrayTraveler->wearyArray != NULL)
			{
				fileSuffix = GetFileSuffix(p_path);
				if(fileSuffix != NOT_SUPPORT)
				{
					fp = fopen(p_path, "r");
				}
				if(fp != NULL)
				{
					switch(fileSuffix)
					{
					case JSON:
						currentStatus = BuildArrayFromJson(localWearyArrayTraveler->wearyArray, fp);
						break;
					case CSV:
						currentStatus = BuildArrayFromCSV(localWearyArrayTraveler->wearyArray, fp);
						break;
					case TSV:
						currentStatus = BuildArrayFromTSV(localWearyArrayTraveler->wearyArray, fp);
						break;
					default:
						break;
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

RETURN_STATUS BuildArray(WearyArray* p_array, FILE* p_fp, const  char* p_delimiter,  uint64_t p_lineOffset)
{
	RETURN_STATUS retValue = OK;
	char* line;
	size_t len = 0;
	char* token;
	uint64_t value = 0;
	char* strToSave;
	ssize_t read = getline(&line, &len, p_fp);
	printf("%s\n", line);
	if(read != -1)
	{
		token = strtok_r(line + p_lineOffset, p_delimiter, &strToSave);
		while(token != NULL)
		{
			sscanf(token, "%lu", &value);
			if(WearyArrayPush(p_array, value) != OK)
			{
				retValue = ERROR;
				break;
			}
			token = strtok_r(NULL, p_delimiter, &strToSave);
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

RETURN_STATUS BuildArrayFromTSV(WearyArray* p_array, FILE* p_fp)
{
	printf("Build From TSV\n");
	return BuildArray(p_array, p_fp, "\t", 0);
}

RETURN_STATUS BuildArrayFromCSV(WearyArray* p_array, FILE* p_fp)
{
	printf("Build From CSV\n");
	return BuildArray(p_array, p_fp, ",", 0);
}

RETURN_STATUS BuildArrayFromJson(WearyArray* p_array, FILE* p_fp)
{
	printf("Build From JSON\n");
	return BuildArray(p_array, p_fp, ",", 1);
}

FILE_SUFFIX GetFileSuffix(const char* p_filePath)
{
	FILE_SUFFIX retValue = NOT_SUPPORT;
	if(strstr(p_filePath, JSON_SUFFIX) != NULL)
	{
		retValue = JSON;
	}
	else if(strstr(p_filePath, CSV_SUFFIX) != NULL)
	{
		retValue = CSV;
	}
	else if(strstr(p_filePath, TSV_SUFFIX) != NULL)
	{
		retValue = TSV;
	}
	else
	{
		printf("The %s is not supported format\n", p_filePath);
	}

	return retValue;
}
