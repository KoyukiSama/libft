
#include "../libft/libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define GREEN "\x1b[32m"
#define RED "\x1b[31m"
#define RESET "\x1b[0m"

#define TEST(res1, res2, n, name)										\
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

int main(void)
{
	char ft_buf[100];
	char buf[100];

	ft_memset(buf, 0, 100);
	ft_memset(ft_buf, 0, 100);
	TEST(ft_memset(ft_buf, 'A', 0), buf, 100, "ft_memset(buf, 'A', 0)");
	TEST(ft_memset(ft_buf, 'X', 5), memset(buf, 'X', 5), 100, "ft_memset(buf, 'X', 5)");
	TEST(ft_memset(ft_buf, 255, 3), memset(buf, 255, 3), 100, "ft_memset(buf, 255, 3)");
	TEST(ft_memset(ft_buf, 0, 4), memset(buf, 0, 4), 100, "ft_memset(buf, 0, 4)");

}


