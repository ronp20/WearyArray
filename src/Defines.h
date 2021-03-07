/*
 * Defines.h
 *
 *  Created on: 4 Mar 2021
 *      Author: ron_po
 */

#ifndef DEFINES_H_
#define DEFINES_H_
#include <stdlib.h>

#define FREE(ptr) ({free(ptr); ptr = NULL;})

typedef enum
{
	OK,
	ERROR
}RETURN_STATUS;

typedef enum
{
	JSON,
	CSV,
	TSV,
	NOT_SUPPORT
}FILE_SUFFIX;

typedef enum
{
	FALSE,
	TRUE
}BOOLEAN;


#endif /* DEFINES_H_ */
