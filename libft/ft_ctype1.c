/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ctype1.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/22 16:36:29 by kclaes        #+#    #+#                 */
/*   Updated: 2025/04/23 23:19:03 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	unsigned char uc;

	uc = (unsigned char) c;
	if ((uc >= 'a' && uc <= 'z')
		|| (uc >= 'A' && uc <= 'Z'))
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	unsigned char uc;

	uc = (unsigned char) c;
	if (uc >= '0' && uc <= '9')
		return (1);
	return (0);
}

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

int	ft_isascii(int c)
{
	unsigned char uc;

	uc = (unsigned char) c;
	if (uc >= 0 && uc <= 127)
		return (1);
	return (0);
}

int	ft_isprint(int c)
{
	unsigned char uc;

	uc = (unsigned char) c;
	if (uc >= 32 && uc <= 126)
		return (1);
	return (0);
}
