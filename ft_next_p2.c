/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_next_p2.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/18 16:50:51 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/18 16:52:30 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stddef.h"

size_t	ft_next_p2(size_t nbr)
{
	if (nbr < 2)
		return (2);
	nbr--;
	nbr |= nbr >> 1;
	nbr |= nbr >> 2;
	nbr |= nbr >> 4;
	nbr |= nbr >> 8;
	nbr |= nbr >> 16;
	nbr |= nbr >> 32;
	return (nbr + 1);
}
