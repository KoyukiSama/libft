/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ctype2.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/22 16:36:29 by kclaes        #+#    #+#                 */
/*   Updated: 2025/04/23 23:09:41 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c + 'A' - 'a');
	return (c);
}

int	tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 'a' - 'A');
	return (c);
}
