/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/28 13:35:40 by kclaes        #+#    #+#                 */
/*   Updated: 2025/04/28 14:57:54 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char *ft_itoa(int n)
{
	int		sign;
	char	*str;
	int		str_len;

	str_len = 0;
	sign = 0;
	if (n < 0)
	{
		str_len++;
		sign = 1;
		n = -n;
	}
	str_len += ft_digits(n);
	str = malloc(str_len + 1);
	if (!str)
		return (NULL);
	str[str_len--] = '\0';
	printf("str[%i]: %c\n", str_len + 1, str[str_len + 1]);
	while (str_len >= 0)
	{
		printf("in loop str[%i]: %c\n", str_len, ft_tochar(str[str_len]));
		str[str_len] = ft_tochar(n % 10);
		n /= 10;
		str_len--;
	}
	if (sign)
		str[0] = '-';
	printf("str[0]: %c\n", str[0]);
	return (str);
}
