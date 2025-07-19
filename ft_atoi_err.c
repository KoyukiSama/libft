/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi_err.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/24 14:24:42 by kclaes        #+#    #+#                 */
/*   Updated: 2025/07/19 17:26:24 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "limits.h"

static int	ft_check_pos_neg(const char **nptr);

// returns error when overflow
int	ft_atoi_err(const char *nptr, int *error)
{
	long	nbr;
	int		sign;

	nbr = 0;
	while (ft_isspace(*nptr))
		nptr++;
	sign = ft_check_pos_neg(&nptr);
	while (ft_isdigit(*nptr))
	{
		nbr = (*nptr - '0') + nbr * 10;
		nptr++;
	}
	nbr *= sign;
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (*error = 1, nbr);
	return (*error = 0, nbr);
}

// returns sign
static int	ft_check_pos_neg(const char **nptr)
{
	if (**nptr == '-')
		return ((*nptr)++, -1);
	else if (**nptr == '+')
		return ((*nptr)++, 1);
	return (1);
}

// #include <stdio.h>
// int main(int argc, char **argv)
// {
// 	(void) argc;
// 	int error;
// 	printf("%d, ", ft_atoi_err(argv[1], &error));
// 	printf("%i\n", error);
// }
