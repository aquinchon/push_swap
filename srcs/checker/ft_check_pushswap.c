/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_pushswap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 11:53:10 by aquincho          #+#    #+#             */
/*   Updated: 2022/06/20 11:53:14 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_operate_rotate(t_construct *construct, char *ope)
{
	if (!ft_strncmp(ope, "ra", 3))
		ft_rotate(&(construct)->a);
	else if (!ft_strncmp(ope, "rb", 3))
		ft_rotate(&(construct)->b);
	else if (!ft_strncmp(ope, "rr", 3))
	{
		ft_rotate(&(construct)->a);
		ft_rotate(&(construct)->b);
	}
	else if (!ft_strncmp(ope, "rra", 3))
		ft_rrotate(&(construct)->a);
	else if (!ft_strncmp(ope, "rrb", 3))
		ft_rrotate(&(construct)->b);
	else if (!ft_strncmp(ope, "rrr", 3))
	{
		ft_rrotate(&(construct)->a);
		ft_rrotate(&(construct)->b);
	}
}

static void	ft_operate(t_construct *construct, char *ope)
{
	if (!ft_strncmp(ope, "sa", 3))
		ft_swap(construct->a);
	else if (!ft_strncmp(ope, "sb", 3))
		ft_swap(construct->b);
	else if (!ft_strncmp(ope, "ss", 3))
	{
		ft_swap(construct->a);
		ft_swap(construct->b);
	}
	else if (!ft_strncmp(ope, "pa", 3))
		ft_push(&construct->b, &construct->a);
	else if (!ft_strncmp(ope, "pb", 3))
		ft_push(&construct->a, &construct->b);
	else
		ft_operate_rotate(construct, ope);
}

int	ft_check_pushswap(t_construct *construct)
{
	t_ope	*tmp;

	tmp = construct->ope;
	while (tmp)
	{
		ft_operate(construct, tmp->data);
		tmp = tmp->next;
	}
	if (ft_stack_sorted(construct->a) && !construct->b)
		return (0);
	else
		return (1);
}
