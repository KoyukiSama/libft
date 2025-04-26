
#ifndef TESTER_MACRO_H
#define TESTER_MACRO_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define GREEN "\x1b[32m"
#define RED "\x1b[31m"
#define RESET "\x1b[0m"

void memprint(const void *mem, size_t n);

#define TEST_MEMCMP(res1, res2, n, name)								\
	do {																\
		if (memcmp(res1, res2, n) == 0)									\
			printf(GREEN "[PASS] " RESET "%s\n", name); 				\
		else															\
		{																\
			printf(RED "[FAIL] " RESET "%s\n", name);					\
			printf("MINE:  = ");										\
			memprint(res1, n);											\
			printf("CORR:  = ");										\
			memprint(res2, n);											\
		}																\
	} while (0);														\

#define TEST_STRCMP(res1, res2, name)									\
	do {																\
		if (strcmp(res1, res2) == 0)									\
			printf(GREEN "[PASS] " RESET "%s\n", name); 				\
		else															\
		{																\
			printf(RED "[FAIL] " RESET "%s\n", name);					\
			printf("MINE:  = \"%s\"\n", res1);							\
			printf("CORR:  = \"%s\"\n", res2);							\
		}																\
	} while (0);														\

#define TEST_PTRCMP(res1, res2, name)									\
	do {																\
		if ((uintptr_t)res1 == (uintptr_t)res2)							\
			printf(GREEN "[PASS] " RESET "%s\n", name); 				\
		else															\
		{																\
			printf(RED "[FAIL] " RESET "%s\n", name);					\
			printf("MINE:  = %p\n", res1);								\
			printf("CORR:  = %p\n", res2);								\
		}																\
	} while (0);														\

#define TEST_BYTECMP(res1, res2, name)									\
	do {																\
		if (res1 == res2)												\
			printf(GREEN "[PASS] " RESET "%s\n", name); 				\
		else															\
		{																\
			printf(RED "[FAIL] " RESET "%s\n", name);					\
			printf("MINE:  = %cu\n", res1);								\
			printf("CORR:  = %cu\n", res2);								\
		}																\
	} while (0);														\
	
#define TEST_INTCMP(res1, res2, name)									\
	do {																\
		if (res1 == res2)												\
			printf(GREEN "[PASS] " RESET "%s\n", name); 				\
		else															\
		{																\
			printf(RED "[FAIL] " RESET "%s\n", name);					\
			printf("MINE:  = %i\n", res1);								\
			printf("CORR:  = %i\n", res2);								\
		}																\
	} while (0);														\

#define TEST_SIZETCMP(res1, res2, name)									\
	do {																\
		if (res1 == res2)												\
			printf(GREEN "[PASS] " RESET "%s\n", name); 				\
		else															\
		{																\
			printf(RED "[FAIL] " RESET "%s\n", name);					\
			printf("MINE:  = %lu\n", res1);								\
			printf("CORR:  = %lu\n", res2);								\
		}																\
	} while (0);

#endif