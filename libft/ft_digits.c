/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_digits.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/28 13:42:24 by kclaes        #+#    #+#                 */
/*   Updated: 2025/04/28 14:19:44 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_digits(int nbr)
{
	int	count;

	if (nbr == 0)
		return (1);
	count = 0;
	while (nbr)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}
