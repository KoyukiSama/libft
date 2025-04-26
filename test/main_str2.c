
#include "tester_macro.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

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
}
