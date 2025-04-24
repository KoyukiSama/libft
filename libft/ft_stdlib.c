/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_stdlib.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/24 14:24:42 by kclaes        #+#    #+#                 */
/*   Updated: 2025/04/24 15:47:45 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int atoi(const char *nptr)
{
	int	nbr;
	int	sign;

	nbr = 0;
	sign = 1;
	while (ft_isspace(*nptr++));
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (ft_isdigit(*nptr))
	{
		nbr = ft_toint(*nptr) + nbr * 10;
		nptr++;
	}
	return (nbr * sign);
}
