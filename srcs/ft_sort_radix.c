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
	ft_free_array(array);
}

static void	ft_sort_bit(t_construct *construct, int shift, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (((construct->a->key >> shift) & 1) == 0)
		{
			ft_push(&construct->a, &construct->b);
			ft_write_ope(&construct->ope, "pb");
		}
		else
		{
			ft_rotate(&construct->a);
			ft_write_ope(&construct->ope, "ra");
		}
		i++;
	}
	while (construct->b)
	{
		ft_push(&construct->b, &construct->a);
		ft_write_ope(&construct->ope, "pa");
	}
}

void	ft_sort_radix(t_construct *construct)
{
	int	shift;
	int	size;

	ft_fill_keys(construct);
	size = ft_stack_size(construct->a);
	shift = 0;
	while (!ft_stack_sorted(construct->a))
	{
		ft_sort_bit(construct, shift, size);
		shift++;
	}
}
