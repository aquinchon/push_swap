/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 09:55:34 by aquincho          #+#    #+#             */
/*   Updated: 2022/06/15 09:55:54 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_5elemts(t_construct *construct)
{
	int	**array_a;
	int	size;
	int	median;

	if (ft_stack_sorted(construct->a))
		return ;
	size = ft_stack_size(construct->a);
	array_a = ft_build_array(construct->a);
	median = ft_find_median(array_a, size);
	while (ft_stack_size(construct->b) < 2)
	{
		if (construct->a->data < median)
			ft_push(&construct->a, &construct->b, &construct->ope, pb);
		else
			ft_rotate(&construct->a, &construct->ope, ra);
	}
	ft_sort_3elemts(construct);
	if (construct->b->data < construct->b->next->data)
		ft_swap(construct->b, &construct->ope, sb);
	while (ft_stack_size(construct->b) > 0)
		ft_push(&construct->b, &construct->a, &construct->ope, pa);
	free (array_a[0]);
	free (array_a[1]);
	free (array_a);
}

void	ft_sort_3elemts(t_construct *construct)
{
	if (ft_stack_size(construct->a) == 2
		&& construct->a->data > construct->a->next->data)
		ft_swap(construct->a, &construct->ope, sa);
	if (ft_stack_sorted(construct->a))
		return ;
	if (construct->a->data > construct->a->next->data)
	{
		if (construct->a->data > ft_stack_last(construct->a)->data)
			ft_rotate(&construct->a, &construct->ope, ra);
		else
			ft_swap(construct->a, &construct->ope, sa);
		ft_sort_3elemts(construct);
	}
	if (ft_stack_last(construct->a)->data < construct->a->next->data)
	{
		ft_rrotate(&construct->a, &construct->ope, rra);
		ft_sort_3elemts(construct);
	}
}
