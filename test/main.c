
#include "../libft/libft.h"
#include <stdio.h>

int main(void)
{
	printf("%i", isalpha('Z'));
	char *str = "hello";
	char *str2[6];
	ft_strlcpy(str2, str, 6);
	printf("%s", str2);
}