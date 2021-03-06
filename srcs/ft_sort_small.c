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

static void	ft_build_b(t_construct *construct, int median, int nb_push)
{
	while (nb_push > 0)
	{
		if (construct->a->data < median)
		{
			ft_push(&construct->a, &construct->b);
			ft_write_ope(&construct->ope, "pb");
			nb_push--;
		}
		else
		{
			ft_rotate(&construct->a);
			ft_write_ope(&construct->ope, "ra");
		}
	}
}

void	ft_sort_5elemts(t_construct *construct)
{
	int	median;
	int	i_push;

	if (ft_stack_size(construct->a) <= 3)
		ft_sort_3elemts(construct);
	if (ft_stack_sorted(construct->a))
		return ;
	median = ft_find_median(construct->a);
	ft_build_b(construct, median, 2);
	ft_sort_3elemts(construct);
	if (construct->b->data < construct->b->next->data)
	{
		ft_swap(construct->b);
		ft_write_ope(&construct->ope, "sb");
	}
	i_push = 2;
	while (i_push > 0)
	{
		ft_push(&construct->b, &construct->a);
		ft_write_ope(&construct->ope, "pa");
		i_push--;
	}
}

static void	ft_cmp_first_last(t_construct *construct)
{
	if (construct->a->data > ft_stack_last(construct->a)->data)
	{
		ft_rotate(&construct->a);
		ft_write_ope(&construct->ope, "ra");
	}
	else
	{
		ft_swap(construct->a);
		ft_write_ope(&construct->ope, "sa");
	}
}

void	ft_sort_3elemts(t_construct *construct)
{
	if (ft_stack_size(construct->a) == 2
		&& construct->a->data > construct->a->next->data)
	{
		ft_swap(construct->a);
		ft_write_ope(&construct->ope, "sa");
	}
	if (ft_stack_sorted(construct->a))
		return ;
	if (construct->a->data > construct->a->next->data)
	{
		ft_cmp_first_last(construct);
		ft_sort_3elemts(construct);
	}
	if (ft_stack_last(construct->a)->data < construct->a->next->data)
	{
		ft_rrotate(&construct->a);
		ft_write_ope(&construct->ope, "rra");
		ft_sort_3elemts(construct);
	}
}
