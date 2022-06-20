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

void	ft_write_ope(t_ope	**ope, char *n_ope)
{
	t_ope	*tmp;
	t_ope	*new;

	new = malloc(sizeof(t_ope));
	if (!new)
		return ;
	new->data = n_ope;
	new->next = NULL;
	if (!(*ope))
		*ope = new;
	else
	{
		tmp = *ope;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	ft_print_ope(t_ope *ope)
{
	if (!ope)
		return ;
	while (ope)
	{
		ft_printf("%s\n", ope->data);
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
