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

//#define TEST

#ifndef TEST
int main(int argc, char* argv[]) {
	if(argc >= 2)
	{
		for(int i = 1; i < argc; ++i)
		{
			printf("Analyzing file %s\n", argv[i]);
			WearyArrayTraveler* wearyArrayTraveler = WearyArrayTravelerCreate(argv[i]);
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
#else
#include "WearyArray.h"
int main() {

	//TEST 1
	int test1[1] = {0};
	WearyArray* wearyArray = WearyArrayCreate();
	WearyArrayPush(wearyArray, test1[0]);
	if(WearyArrayIsTraveler(wearyArray) == TRUE)
	{
		printf("Test 1 OK\n");
	}
	else
	{
		printf("Test 1 Fail!");
	}
	WearyArrayDestroy(wearyArray);

	//TEST 2
	int test2[2] = {1, 2};
	wearyArray = WearyArrayCreate();
	WearyArrayPush(wearyArray, test2[0]);
	WearyArrayPush(wearyArray, test2[1]);
	if(WearyArrayIsTraveler(wearyArray) == TRUE)
	{
		printf("Test 2 OK\n");
	}
	else
	{
		printf("Test 2 Fail!\n");
	}
	WearyArrayDestroy(wearyArray);

	//TEST 3
	int test3[2] = {2, 2};
	wearyArray = WearyArrayCreate();
	WearyArrayPush(wearyArray, test3[0]);
	WearyArrayPush(wearyArray, test3[1]);
	if(WearyArrayIsTraveler(wearyArray) == FALSE)
	{
		printf("Test 3 OK\n");
	}
	else
	{
		printf("Test 3 Fail!\n");
	}
	WearyArrayDestroy(wearyArray);


	//TEST 4
	int test4[1] = {2};
	wearyArray = WearyArrayCreate();
	WearyArrayPush(wearyArray, test4[0]);
	if(WearyArrayIsTraveler(wearyArray) == TRUE)
	{
		printf("Test 4 OK\n");
	}
	else
	{
		printf("Test 4 Fail!\n");
	}
	WearyArrayDestroy(wearyArray);

	//TEST 5
	int test5[3] = {1, 2, 3};
	wearyArray = WearyArrayCreate();
	WearyArrayPush(wearyArray, test5[0]);
	WearyArrayPush(wearyArray, test5[1]);
	WearyArrayPush(wearyArray, test5[2]);
	if(WearyArrayIsTraveler(wearyArray) == FALSE)
	{
		printf("Test 5 OK\n");
	}
	else
	{
		printf("Test 5 Fail!\n");
	}
	WearyArrayDestroy(wearyArray);

	//TEST 6
	wearyArray = WearyArrayCreate();
	if(WearyArrayIsTraveler(wearyArray) == FALSE)
	{
		printf("Test 6 OK\n");
	}
	else
	{
		printf("Test 6 Fail!\n");
	}
	WearyArrayDestroy(wearyArray);


	//TEST 7
	int test7[9] = {1, 2, 3, 2, 5, 2, 7, 1, 9};
	wearyArray = WearyArrayCreate();
	for(int i = 0; i < 9; ++i) WearyArrayPush(wearyArray, test7[i]);
	if(WearyArrayIsTraveler(wearyArray) == TRUE)
	{
		printf("Test 7 OK\n");
	}
	else
	{
		printf("Test 7 Fail!\n");
	}
	WearyArrayDestroy(wearyArray);

	return EXIT_SUCCESS;
}
#endif
