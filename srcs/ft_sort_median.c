/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_median.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:09:32 by aquincho          #+#    #+#             */
/*   Updated: 2022/06/15 16:09:35 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_median(t_construct *construct);
/*{
	int	median;
	int	nb_iter;
	//int	i;
	int	nb_to_process;

	nb_iter = ft_stack_size(construct->a) / 5;
	if (ft_stack_size(construct->a) % 5 == 0)
		nb_iter--;
	while (nb_iter)
	{
		while (ft_stack_size(construct->a) > 5)
		{
			median = ft_find_median(construct->a);
			nb_to_process = ft_stack_size(construct->a);
			while (nb_to_process > 0 && ft_stack_size(construct->a) != 5)
			{
				if (construct->a->data < median)
					ft_push(&construct->a, &construct->b, &construct->ope, pb);
				else
					ft_rotate(&construct->a, &construct->ope, ra);
				nb_to_process--;
			}
		}
		ft_sort_5elemts(construct);
		while (construct->a)
		{
			ft_push(&construct->a, &construct->b, &construct->ope, pb);
			ft_rotate(&construct->b, &construct->ope, rb);
		}
		if (nb_iter > 1)
			nb_to_process = 5;
		else
			nb_to_process = ft_stack_size(construct->a) % 5;
		while (nb_to_process > 0)
		{
			ft_push(&construct->b, &construct->a, &construct->ope, pa);
			nb_to_process--;
		}
		ft_sort_5elemts(construct);
		while (construct->a)
		{
			ft_push(&construct->a, &construct->b, &construct->ope, pb);
			ft_rotate(&construct->b, &construct->ope, rb);
		}
		//nb_iter--;
		nb_iter = 0;
	}
}*/
