/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_basic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:33:14 by aquincho          #+#    #+#             */
/*   Updated: 2022/06/10 15:34:17 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_basic(t_construct *construct)
{
	if (construct->a->data > construct->a->next->data)
		ft_swap(construct->a, &construct->ope, sa);
	while (construct->a->data > ft_stack_last(construct->a)->data)
		ft_rrotate(&construct->a, &construct->ope, rra);
	if (ft_stack_sorted(construct->a) && !construct->b)
		return ;
	if (!construct->b)
		ft_push(&construct->a, &construct->b, &construct->ope, pb);
	while (construct->a && construct->a->data > construct->b->data)
		ft_push(&construct->a, &construct->b, &construct->ope, pb);
	if (ft_stack_size(construct->a) > 1)
		ft_rotate(&construct->a, &construct->ope, ra);
	while (construct->b
		&& ft_stack_last(construct->a)->data < construct->b->data)
		ft_push(&construct->b, &construct->a, &construct->ope, pa);
	ft_rrotate(&construct->a, &construct->ope, rra);
	if (!ft_stack_sorted(construct->a))
		ft_sort_basic(construct);
	else
	{
		while (construct->b)
			ft_push(&construct->b, &construct->a, &construct->ope, pa);
	}
}

void	ft_sort(t_construct *construct)
{
	if (!construct->a || !construct->a->next)
		return ;
	if (ft_stack_size(construct->a) == 2 && !ft_stack_sorted(construct->a))
		ft_swap(construct->a, &construct->ope, sa);
	else if (ft_stack_size(construct->a) == 3)
		ft_sort_3elemts(construct);
	else if (ft_stack_size(construct->a) <= 5)
		ft_sort_5elemts(construct);
	else
		//ft_sort_basic(construct);
		//ft_sort_median(construct);
		ft_sort_radix(construct);
}
