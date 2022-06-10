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

void	ft_swap(t_stack *stack)
{
	int	tmp;
	
	if (!stack || !stack->next)
		return ;
	tmp = stack->data;
	stack->data = stack->next->data;
	stack->next->data = tmp;
}

void	ft_push(t_stack **st_from, t_stack **st_to)
{
	t_stack	*tmp;
	
	if (!(*st_from) || *st_from == *st_to)
		return ;
	tmp = *st_from;
	*st_from = (*st_from)->next;
	tmp->next = *st_to;
	*st_to = tmp;
}

void	ft_rotate(t_stack **stack)
{
	t_stack	*tmp;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	ft_stack_last(*stack)->next = tmp;
	tmp->next = NULL;
}

void	ft_rrotate(t_stack **stack)
{
	t_stack	*tmp;
	int		size;
	int		i;
	
	if (!(*stack) || !(*stack)->next)
		return ;
	size = ft_stack_size(*stack);
	i = 0;
	tmp = ft_stack_last(*stack);
	tmp->next = *stack;
	*stack = tmp;
	ft_printf("rr3");
	while (i < size - 1)
	{
		tmp = tmp->next;
		i++;
	}
	tmp->next = NULL;
}
