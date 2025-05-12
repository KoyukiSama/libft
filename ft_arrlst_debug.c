/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_arrlst_debug.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/12 21:50:12 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/12 22:09:38 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arrlst.h"
#include <stdio.h>

#define GRN "\e[0;32m"
#define BLU "\e[0;34m"
#define WHT "\e[0;37m"

void ft_print_arrlst(t_arrlst *arrlst)
{
	size_t	i = 0;

	i = 0;
	while (i < arrlst->len)
	{
		printf(GRN"%s, "WHT, (char *)(arrlst->arr[i]));
		i++;
	}
	while (i < arrlst->cap)
	{
		printf(BLU"%s, "WHT, (char *)(arrlst->arr[i]));
		i++;
	}
	putchar('\n');
}

void ft_print_arrlst_strt_stats(t_arrlst *arrlst)
{
	printf("len_strt: %lu\n", arrlst->strt_len);
	printf("cap_strt: %lu\n", arrlst->strt_cap);
}

void ft_print_arrlst_stats(t_arrlst *arrlst)
{
	printf("len: %lu\n", arrlst->len);
	printf("cap: %lu\n", arrlst->cap);
}

int main(void)
{
	t_arrlst *arr1 = ft_arrlst_create(5, 10);
	
	ft_print_arrlst_strt_stats(arr1);
	ft_print_arrlst_stats(arr1);
	ft_print_arrlst(arr1);
}
