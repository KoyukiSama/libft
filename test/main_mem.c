
#include "../libft/libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define GREEN "\x1b[32m"
#define RED "\x1b[31m"
#define RESET "\x1b[0m"

#define TEST_MEMCMP(res1, res2, n, name)										\
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

int main(void)
{
	printf("++++++++++++memset++++++++++++\n");
	char ft_buf[100] = {0};
	char buf[100] = {0};
	TEST_MEMCMP(ft_memset(ft_buf, 'A', 0), buf, 100, "ft_memset(buf, 'A', 0)");
	TEST_MEMCMP(ft_memset(ft_buf, 'X', 5), memset(buf, 'X', 5), 100, "ft_memset(buf, 'X', 5)");
	TEST_MEMCMP(ft_memset(ft_buf, 255, 3), memset(buf, 255, 3), 100, "ft_memset(buf, 255, 3)");
	TEST_MEMCMP(ft_memset(ft_buf, 0, 4), memset(buf, 0, 4), 100, "ft_memset(buf, 0, 4)");

	printf("++++++++++++memcpy++++++++++++\n");
	char src_buf[100] = {5};
	TEST_MEMCMP(ft_memcpy(ft_buf, src_buf, 0), memcpy(buf, src_buf, 0), 100, "ft_memcpy(buf, src, 0)");
	memset(src_buf, 'A', 100);
	TEST_MEMCMP(ft_memcpy(ft_buf, src_buf, 100), memcpy(buf, src_buf, 100), 100, "ft_memcpy(buf, src, 5)");

	printf("++++++++++++memmove++++++++++++\n");
	memset(buf, 'A', 100);
	memset(ft_buf, 'A', 100);
	memset(buf + 10, 'B', 90);
	memset(ft_buf + 10, 'B', 90);
	TEST_MEMCMP(ft_memmove(ft_buf, ft_buf + 10, 90), memmove(buf, buf + 10, 90), 90, "ft_memmove(buf, buf + 10, 90)");

	memset(buf, 'A', 100);
	memset(ft_buf, 'A', 100);
	memset(buf + 10, 'B', 90);
	memset(ft_buf + 10, 'B', 90);
	TEST_MEMCMP(ft_memmove(ft_buf + 10, ft_buf, 90), memmove(buf + 10, buf, 90), 90, "ft_memmove(buf + 10, buf, 90)");

	memset(src_buf, 'Z', 100);
	memset(buf, 'A', 100);
	memset(ft_buf, 'A', 100);
	TEST_MEMCMP(ft_memmove(ft_buf, src_buf, 100), memmove(buf, src_buf, 100), 100, "ft_memmove(buf, src, 100)");

	printf("++++++++++++memchr++++++++++++\n");
	memset(buf, 'A', 10);
	memset(buf + 10, 'B', 10);
	memset(buf + 20, 'C', 10);
	memset(buf + 30, 'D', 10);
	memset(buf + 40, 'E', 10);
	memset(buf + 50, 'F', 10);
	TEST_PTRCMP(ft_memchr(buf, 'B', 60), memchr(buf, 'B', 60), "ft_memchr(buf, 'B', 60)");
	TEST_PTRCMP(ft_memchr(buf, '0', 60), memchr(buf, '0', 60), "ft_memchr(buf, 0, 60)");
	TEST_PTRCMP(ft_memchr(buf, '\0', 60), memchr(buf, '\0', 60), "ft_memchr(buf, '\\0', 60)");
	TEST_PTRCMP(ft_memchr(buf, '\0', 0), memchr(buf, '\0', 0), "ft_memchr(buf, '\\0', 0)");

	printf("++++++++++++memcmp++++++++++++\n");
	TEST_BYTECMP(ft_memcmp(buf, buf, 60), memcmp(buf, buf, 60), "ft_memcmp(buf, buf, 60)");
	memcpy(src_buf, buf, 60);
	memset(buf, '0', 1);
	TEST_BYTECMP(ft_memcmp(buf, src_buf, 60), memcmp(buf, src_buf, 60), "ft_memcmp(buf, src, 60)");
	memset(buf, 'A', 2);
	memset(buf + 1, '0', 1);
	TEST_BYTECMP(ft_memcmp(buf, src_buf, 60), memcmp(buf, src_buf, 60), "ft_memcmp(buf, src, 60)");
	TEST_BYTECMP(ft_memcmp(buf, src_buf, 0), memcmp(buf, src_buf, 0), "ft_memcmp(buf, src, 0)");
	memset(buf + 1, '\0', 1);
	TEST_BYTECMP(ft_memcmp(buf, src_buf, 60), memcmp(buf, src_buf, 60), "ft_memcmp(buf, src, 60)");
	
	printf("++++++++++++calloc++++++++++++\n");
	char *calloc_ft = ft_calloc(0, 0);
	char *calloc_lib;
	free(calloc_ft);
	printf(GREEN"[PASS] "RESET"ft_calloc(0, 0)\n");
	calloc_ft = ft_calloc(8, 8);
	calloc_lib = ft_calloc(8, 8);
	TEST_MEMCMP(calloc_ft, calloc_lib, 8 * 8, "ft_calloc(8, 8)");
	free(calloc_ft);
	free(calloc_lib);
	calloc_ft = ft_calloc(SIZE_MAX, 2);
	TEST_PTRCMP(calloc_ft, NULL, "ft_calloc(SIZE_MAX, 2)");
}


