
#include "../libft/libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define GREEN "\x1b[32m"
#define RED "\x1b[31m"
#define RESET "\x1b[0m"

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

void memprint(const void *mem, size_t n)
{
	const unsigned char *p;
	
	p = mem;
	for (size_t i = 0; i < n; i++) {
		printf("%02x ", p[i]);
	}
	printf("\n");
}

#define TEST_PTRCMP(res1, res2, name)									\
	do {																\
		if ((uintptr_t)res1 == (uintptr_t)res2)							\
			printf(GREEN "[PASS] " RESET "%s\n", name); 				\
		else															\
		{																\
			printf(RED "[FAIL] " RESET "%s\n", name);					\
			printf("MINE:  = %p", res1);								\
			printf("CORR:  = %p", res2);								\
		}																\
	} while (0);														\

#define TEST_BYTECMP(res1, res2, name)									\
	do {																\
		if (res1 == res2)												\
			printf(GREEN "[PASS] " RESET "%s\n", name); 				\
		else															\
		{																\
			printf(RED "[FAIL] " RESET "%s\n", name);					\
			printf("MINE:  = %cu", res1);								\
			printf("CORR:  = %cu", res2);								\
		}																\
	} while (0);														\
	
#define TEST_INTCMP(res1, res2, name)									\
	do {																\
		if (res1 == res2)												\
			printf(GREEN "[PASS] " RESET "%s\n", name); 				\
		else															\
		{																\
			printf(RED "[FAIL] " RESET "%s\n", name);					\
			printf("MINE:  = %i", res1);								\
			printf("CORR:  = %i", res2);								\
		}																\
	} while (0);														\

int main(void)
{
	printf("++++++++++++ft_atoi++++++++++++\n");

	TEST_INTCMP(ft_atoi("42"), ft_atoi("42"), "ft_atoi(\"42\")");
	TEST_INTCMP(ft_atoi("   -123"), ft_atoi("   -123"), "ft_atoi(\"   -123\")");
	TEST_INTCMP(ft_atoi("+99"), ft_atoi("+99"), "ft_atoi(\"+99\")");
	TEST_INTCMP(ft_atoi("abc"), ft_atoi("abc"), "ft_atoi(\"abc\")");
	TEST_INTCMP(ft_atoi("123abc"), ft_atoi("123abc"), "ft_atoi(\"123abc\")");
	TEST_INTCMP(ft_atoi("   +00000"), ft_atoi("   +00000"), "ft_atoi(\"   +00000\")");
	TEST_INTCMP(ft_atoi("2147483647"), ft_atoi("2147483647"), "ft_atoi(\"2147483647\")");
	TEST_INTCMP(ft_atoi("-2147483648"), ft_atoi("-2147483648"), "ft_atoi(\"-2147483648\")");
	TEST_INTCMP(ft_atoi("  ++-4404"), ft_atoi("  ++-4404"), "ft_atoi(\"  ++-4404\")");
	TEST_INTCMP(ft_atoi("  +-+4404"), ft_atoi("  +-+4404"), "ft_atoi(\"  +-+4404\")");
	TEST_INTCMP(ft_atoi("  -+-4404"), ft_atoi("  -+-4404"), "ft_atoi(\"  -+-4404\")");
}


