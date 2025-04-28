/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/28 13:35:40 by kclaes        #+#    #+#                 */
/*   Updated: 2025/04/28 21:52:48 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		sign;
	char	str[12];
	int		str_len;
	int		str_len_cpy;

	str_len = 0;
	sign = 0;
	if (n < 0)
	{
		str_len++;
		sign = 1;
		n = -n;
	}
	str_len += ft_digits(n);
	str_len_cpy = str_len--;
	while (str_len >= 0)
	{
		str[str_len] = ft_tochar(n % 10);
		n /= 10;
		str_len--;
	}
	if (sign)
		str[0] = '-';
	write(fd, str, str_len_cpy);
}
