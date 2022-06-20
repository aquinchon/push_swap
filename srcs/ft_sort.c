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

void	ft_sort(t_construct *construct)
{
	if (!construct->a || !construct->a->next)
		return ;
	if (ft_stack_size(construct->a) == 2 && !ft_stack_sorted(construct->a))
	{
		ft_swap(construct->a);
		ft_write_ope(&construct->ope, "sa");
	}
	else if (ft_stack_size(construct->a) == 3)
		ft_sort_3elemts(construct);
	else if (ft_stack_size(construct->a) <= 5)
		ft_sort_5elemts(construct);
	else
		ft_sort_radix(construct);
}
