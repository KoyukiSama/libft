/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/28 13:35:40 by kclaes        #+#    #+#                 */
/*   Updated: 2025/04/28 22:31:04 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		sign;
	char	*str;
	int		str_len;

	str_len = 0;
	sign = 0;
	ft_set_negative(&n, &str_len, &sign);
	str_len += ft_digits(n);
	str = malloc(str_len + 1);
	if (!str)
		return (NULL);
	str[str_len--] = '\0';
	while (str_len >= 0)
	{
		str[str_len] = ft_tochar(n % 10);
		n /= 10;
		str_len--;
	}
	if (sign)
		str[0] = '-';
	return (str);
}

static void	ft_set_negative(int *n, int *str_len, int *sign)
{
	if (*n < 0)
	{
		(*str_len)++;
		*sign = 1;
		*n = -(*n);
	}
}
