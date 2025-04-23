/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ctype2.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/22 16:36:29 by kclaes        #+#    #+#                 */
/*   Updated: 2025/04/23 23:25:12 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	toupper(int c)
{
	unsigned char uc;

	uc = (unsigned char) c;
	if (uc >= 'a' && uc <= 'z')
		return (uc + 'A' - 'a');
	return (c);
}

int	tolower(int c)
{
	unsigned char uc;

	uc = (unsigned char) c;
	if (uc >= 'A' && uc <= 'Z')
		return (uc + 'a' - 'A');
	return (c);
}
