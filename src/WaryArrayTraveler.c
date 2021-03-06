/*
 ============================================================================
 Name        : WaryArrayTraveler.c
 Author      : Ron
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "WearyStruct.h"
#include "WearyArray.h"
#include <stdio.h>
#include <stdlib.h>


int main(void) {
	uint64_t arr[] = {4, 4, 1, 1, 2, 2, 1000, 1};

	// Not working
//	uint64_t arr[] = {4, 2, 1, 3, 2, 2, 1000, 1};
//	uint64_t arr[] = {4};


	WearyArray* wearyArray = WearyArrayCreate();
	for(int i = 0; i < 8; ++i)
	{
		WearyArrayPush(wearyArray, arr[i]);
	}


	if(WearyArrayIsTraveler(wearyArray) == TRUE)
	{
		printf("true\n");
	}
	else
	{
		printf("false\n");
	}

//	WearyArrayPrint(wearyArray);
	WearyArrayDestroy(wearyArray);


	return EXIT_SUCCESS;
}
