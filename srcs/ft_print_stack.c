/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:22:35 by aquincho          #+#    #+#             */
/*   Updated: 2022/06/13 10:31:55 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_write_ope(t_stack **stack, t_numope num_ope)
{
	t_stack	*tmp;
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->data = num_ope;
	new->next = NULL;
	if (!(*stack))
		*stack = new;
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

static t_stack	*ft_print_ope_rotat(t_stack *ope)
{
	if (ope->data == 4 && (!ope->next || ope->next->data != 5))
		write(1, "ra\n", 3);
	else if (ope->data == 5 && (!ope->next || ope->next->data != 4))
		write(1, "rb\n", 3);
	else if ((ope->data == 4 && ope->next && ope->next->data == 5)
		|| (ope->data == 4 && ope->next && ope->next->data == 5))
	{
		write(1, "rr\n", 3);
		ope = ope->next;
	}
	else if (ope->data == 6 && (!ope->next || ope->next->data != 7))
		write(1, "rra\n", 4);
	else if (ope->data == 7 && (!ope->next || ope->next->data != 6))
		write(1, "rrb\n", 4);
	else if ((ope->data == 6 && ope->next && ope->next->data == 7)
		|| (ope->data == 7 && ope->next && ope->next->data == 6))
	{
		write(1, "rrr\n", 4);
		ope = ope->next;
	}
	return (ope);
}

void	ft_print_ope(t_stack *ope)
{
	if (!ope)
		return ;
	while (ope)
	{
		if (ope->data == 0 && (!ope->next || ope->next->data != 1))
			write(1, "sa\n", 3);
		else if (ope->data == 1 && (!ope->next || ope->next->data != 0))
			write(1, "sb\n", 3);
		else if ((ope->data == 0 && ope->next && ope->next->data == 1)
			|| (ope->data == 1 && ope->next && ope->next->data == 0))
		{
			write(1, "ss\n", 3);
			ope = ope->next;
		}
		else if (ope->data == 2)
			write(1, "pa\n", 3);
		else if (ope->data == 3)
			write(1, "pb\n", 3);
		else
			ope = ft_print_ope_rotat(ope);
		ope = ope->next;
	}
}

void	ft_print_stack(t_stack *stack)
{
	if (!stack)
		return ;
	while (stack)
	{
		ft_printf("%d\n", stack->data);
		stack = stack->next;
	}
}
