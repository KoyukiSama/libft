
#include "../libft/libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[] = "hello";
	char str2[6];
	char str_sol[6];

	ft_strlcpy(str2, str, 7); // my func
	printf("%s\n", str2);

	ft_strlcpy(str_sol, str, 7); // string.h
	printf("%s\n", str_sol);
}