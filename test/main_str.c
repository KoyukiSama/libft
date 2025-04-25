
#include "../libft/libft.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

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
	} while (0);														\

int main(void)
{
	printf("++++++++++++ft_strlen++++++++++++\n");
	TEST_SIZETCMP(ft_strlen("helooooo"), strlen("helooooo"), "ft_strlen(\"helooooo\")");
	TEST_SIZETCMP(ft_strlen(""), strlen(""), "ft_strlen(\"\")");
	TEST_SIZETCMP(ft_strlen("a\0bcd"), strlen("a\0bcd"), "ft_strlen(\"a\\0bcd\")");
	
	printf("++++++++++++ft_strlcpy++++++++++++\n");
	char ft_buf[20] = {0};
	char buf[20] = {0};
	char src[] = "AAABB\0CCC";
	char src2[] = "";
	TEST_SIZETCMP(ft_strlcpy(ft_buf, src, 0), strlcpy(buf, src, 0), "ft_strlcpy(buf, src, 0): len");
	TEST_MEMCMP(ft_buf, buf, 10, "ft_strlcpy(ft_buf, buf, 0)");

	ft_bzero(ft_buf, 10);
	ft_bzero(buf, 10);
	TEST_SIZETCMP(ft_strlcpy(ft_buf, src, 1), strlcpy(buf, src, 1), "ft_strcpy(buf, src, 1): len");
	TEST_MEMCMP(ft_buf, buf, 10, "ft_strlcpy(ft_buf, buf, 1)");

	ft_bzero(ft_buf, 10);
	ft_bzero(buf, 10);
	TEST_SIZETCMP(ft_strlcpy(ft_buf, src, 10), strlcpy(buf, src, 10), "ft_strcpy(buf, src, 10): len");
	TEST_MEMCMP(ft_buf, buf, 10, "ft_strlcpy(ft_buf, buf, 10)");
	
	ft_bzero(ft_buf, 10);
	ft_bzero(buf, 10);
	TEST_SIZETCMP(ft_strlcpy(ft_buf, src, 3), strlcpy(buf, src, 3), "ft_strcpy(buf, src, 3): len");
	TEST_MEMCMP(ft_buf, buf, 3, "ft_strlcpy(ft_buf, buf, 3)");

	ft_bzero(ft_buf, 10);
	ft_bzero(buf, 10);
	TEST_SIZETCMP(ft_strlcpy(ft_buf, src2, 10), strlcpy(buf, src2, 10), "ft_strcpy(buf, src, 10): len");
	TEST_MEMCMP(ft_buf, buf, 10, "ft_strlcpy(ft_buf, buf-empty, 10)");
	
	printf("++++++++++++ft_strlcat++++++++++++\n");
	char src_cat[] = "AAABBBCCC";
	char dst[] = "hello";
	char ft_dst[] = "hello";
	TEST_SIZETCMP(ft_strlcat(ft_dst, src, 10), strlcat(dst, src, 10), "ft_strlcpy(buf, src, 0): len");
	TEST_MEMCMP(ft_buf, buf, 10, "ft_strlcpy(ft_buf, buf, 0)");

}
