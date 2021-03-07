/*
 ============================================================================
 Name        : WaryArrayTraveler.c
 Author      : Ron
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "WearyArrayTraveler.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	if(argc >= 2)
	{
		for(int i = 1; i < argc; ++i)
		{
			printf("Analyzing file %s\n", argv[i]);
			WearyArrayTraveler* wearyArrayTraveler = WearyArrayTravelerCreate(argv[i]);
//			WearyArrayTravelerPrint(wearyArrayTraveler);

			BOOLEAN isTraveler = WearyArrayTraveleIsTraveler(wearyArrayTraveler);
			printf("Array Is Traveler = %s\n\n", isTraveler == TRUE? "True": "False");

			WearyArrayTravelerDestroy(wearyArrayTraveler);
		}
	}
	else
	{
		printf("Please insert a file\n");
	}

	return EXIT_SUCCESS;
}
