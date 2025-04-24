
#include "../libft/libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define GREEN "\x1b[32m"
#define RED "\x1b[31m"
#define RESET "\x1b[0m"

#define TEST(res1, res2, printf_type, input, name, pass_count)			\
	do {																\
		char fail = 0;													\
		if (res1 != res2)												\
		{																\
			fail = 1;													\
			printf(RED "[FAIL] " RESET "%s\n", name);					\
			printf("MINE:  = %"printf_type"\n", res1);					\
			printf("LIBC:  = %"printf_type"\n", res2);					\
		}																\
		if (i == pass_count && !fail)									\
			printf(GREEN "[PASS] " RESET "%s()\n", name); 				\
	} while (0);														\

int main(void)
{
	size_t pass_count = 300;

	for (size_t i = 0; i <= pass_count; i++)
	{
		TEST((ft_isalpha(i) > 0), (isalpha(i) > 0), "i", i, "ft_isalpha", pass_count);
	}
}
