
#include "tester_macro.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

static char trans_same(unsigned int i, char c)
{
	(void)i;
	return c;
}
static char trans_upper(unsigned int i, char c)
{
	(void)i;
	return (char)ft_toupper((unsigned char)c);
}
static char trans_shifti(unsigned int i, char c)
{
	return (char)(c + i);
}
static char trans_digiti(unsigned int i, char c)
{
	(void)c;
	return (char)('0' + (i % 10));
}

int main(void)
{
	printf("++++++++++++ft_split++++++++++++\n");
	char *arr[] = {NULL};
	char *arr1[] = {"a", NULL};
	char *arr2[] = {"a", "b", NULL};
	char *arr3[] = {"a", "b", "c", NULL};
	TEST_STRSCMP(ft_split("", ','), arr, "ft_split(\"\", ',') -> [NULL]");
	TEST_STRSCMP(ft_split("a", ','), arr1, "ft_split(\"a\", ',') -> [\"a\", NULL]");
	TEST_STRSCMP(ft_split(",", ','), arr, "ft_split(\",\", ',') -> [NULL]");
	TEST_STRSCMP(ft_split(",,", ','), arr, "ft_split(\",,\", ',') -> [NULL]");
	TEST_STRSCMP(ft_split(",a,", ','), arr1, "ft_split(\",a,\", ',') -> [\"a\", NULL]");
	TEST_STRSCMP(ft_split("a,b", ','), arr2, "ft_split(\"a,b\", ',') -> [\"a\", \"b\", NULL]");
	TEST_STRSCMP(ft_split("a,,b", ','), arr2, "ft_split(\"a,,b\", ',') -> [\"a\", \"b\", NULL]");
	TEST_STRSCMP(ft_split("a b c", ' '), arr3, "ft_split(\"a b c\", ' ') -> [\"a\", \"b\", \"c\", NULL]");

	printf("++++++++++++ft_strmapi++++++++++++\n");
	TEST_STRCMP(ft_strmapi("", trans_same), "", "ft_split(\"\", trans_same)");
	TEST_STRCMP(ft_strmapi("Hello, World!", trans_same), "Hello, World!", "ft_split(\"Hello, World!\", trans_same)");
	TEST_STRCMP(ft_strmapi("Hello, World!", trans_upper), "HELLO, WORLD!", "ft_split(\"Hello, World!\", trans_upper)");
	TEST_STRCMP(ft_strmapi("abcd", trans_shifti), "aceg", "ft_split(\"abcd\", trans_shifti)");
	TEST_STRCMP(ft_strmapi("xxxxxx", trans_digiti), "012345", "ft_split(\"\", trans_digiti)");
}
