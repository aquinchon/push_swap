/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_ope.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 08:52:24 by aquincho          #+#    #+#             */
/*   Updated: 2022/06/10 08:52:30 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *stack, t_stack **ope, t_numope n_ope)
{
	int	tmp;

	if (!stack || !stack->next)
		return ;
	tmp = stack->data;
	stack->data = stack->next->data;
	stack->next->data = tmp;
	ft_write_ope(ope, n_ope);
}

void	ft_push(t_stack **from, t_stack **to, t_stack **ope, t_numope n_ope)
{
	t_stack	*tmp;

	if (!(*from) || *from == *to)
		return ;
	tmp = *from;
	*from = (*from)->next;
	tmp->next = *to;
	*to = tmp;
	ft_write_ope(ope, n_ope);
}

void	ft_rotate(t_stack **stack, t_stack **ope, t_numope n_ope)
{
	t_stack	*tmp;

	if (!(*stack) || !(*stack)->next)
		return ;
	if (ft_stack_size(*stack) == 2)
	{
		ft_swap(*stack, ope, n_ope);
		return ;
	}
	tmp = *stack;
	*stack = (*stack)->next;
	ft_stack_last(*stack)->next = tmp;
	tmp->next = NULL;
	ft_write_ope(ope, n_ope);
}

void	ft_rrotate(t_stack **stack, t_stack **ope, t_numope n_ope)
{
	t_stack	*tmp;
	int		size;
	int		i;

	if (!(*stack) || !(*stack)->next)
		return ;
	if (ft_stack_size(*stack) == 2)
	{
		ft_swap(*stack, ope, n_ope);
		return ;
	}
	size = ft_stack_size(*stack);
	i = 0;
	tmp = ft_stack_last(*stack);
	tmp->next = *stack;
	*stack = tmp;
	while (i < size - 1)
	{
		tmp = tmp->next;
		i++;
	}
	tmp->next = NULL;
	ft_write_ope(ope, n_ope);
}
