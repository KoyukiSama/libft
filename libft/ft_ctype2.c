/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ctype2.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/22 16:36:29 by kclaes        #+#    #+#                 */
/*   Updated: 2025/04/24 15:37:56 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	unsigned char	uc;

	uc = (unsigned char) c;
	if (uc >= 'a' && uc <= 'z')
		return (uc + 'A' - 'a');
	return (c);
}

int	ft_tolower(int c)
{
	unsigned char	uc;

	uc = (unsigned char) c;
	if (uc >= 'A' && uc <= 'Z')
		return (uc + 'a' - 'A');
	return (c);
}

int	ft_toint(char c)
{
	return ((int)(c - '0'));
}

char	ft_tochar(int c)
{
	return ((char)(c + '0'));
}

int	ft_isspace(int c)
{
	unsigned char	uc;

	uc = (unsigned char) c;
	if ((uc >= '\t' && uc <= '\r') || uc == ' ')
		return (1);
	return (0);
}
