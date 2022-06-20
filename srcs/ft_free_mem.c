/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_mem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 11:42:58 by aquincho          #+#    #+#             */
/*   Updated: 2022/06/10 11:44:03 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_stack *stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

void	ft_free_ope(t_ope *ope, int check)
{
	t_ope	*tmp;

	if (!ope)
		return ;
	while (ope)
	{
		tmp = ope;
		if (check)
			free(ope->data);
		ope = ope->next;
		free(tmp);
	}
	free(ope);
}

void	ft_free_construct(t_construct *construct, int check)
{
	if (construct->a)
		ft_free_stack(construct->a);
	if (construct->b)
		ft_free_stack(construct->b);
	if (construct->ope)
		ft_free_ope(construct->ope, check);
	free(construct);
}

void	ft_free_array(int **array)
{
	if (array[0])
		free(array[0]);
	if (array[1])
		free(array[1]);
	if (array)
		free(array);
}
