/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_radix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:20:15 by aquincho          #+#    #+#             */
/*   Updated: 2022/06/10 15:21:48 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	ft_fill_keys(t_construct *construct)
{
	int		**array;
	int		i;
	t_stack	*tmp;

	array = ft_sort_array(construct->a);
	i = 0;
	tmp = construct->a;
	while (tmp)
	{
		i = 0;
		while (tmp->data != array[0][i])
			i++;
		tmp->key = array[1][i];
		tmp = tmp->next;
	}
}

void	ft_sort_radix(t_construct *construct)
{
	int	shift;
	int	i;
	int	size;

	ft_fill_keys(construct);
	size = ft_stack_size(construct->a);
	shift = 0;
	while (!ft_stack_sorted(construct->a))
	{
		i = 0;
		while (i < size)
		{
			if (((construct->a->key >> shift) & 1) == 0)
				ft_push(&construct->a, &construct->b, &construct->ope, pb);
			else
				ft_rotate(&construct->a, &construct->ope, ra);
			i++;
		}
		while (construct->b)
			ft_push(&construct->b, &construct->a, &construct->ope, pa);
		shift++;
	}
}
