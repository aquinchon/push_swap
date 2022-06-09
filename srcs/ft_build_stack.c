/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:37:19 by aquincho          #+#    #+#             */
/*   Updated: 2022/06/07 13:37:21 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ft_stackpush(t_construct *construct, int content)
{
	t_stack *new;
	t_stack	*tmp;
	
	new = malloc(sizeof(t_stack));
	if (!new)
		return (construct->a);
	new->data = content;
	new->next = NULL;
	if (!construct->a)
	{
		return (new);
	}
	else
	{
		tmp = construct->a;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (construct->a);
}

void	ft_build_stack(int argc, char **argv, t_construct *construct)
{
	int	i;
	int	arg;
	int	value;

	arg = 1;
	while (arg < argc)
	{
		i = 0;
		while (argv[arg][i] != '\0')
		{
			while (ft_isspace(argv[arg][i]))
				i++;
			value = ft_check_data(argv[arg] + i, construct);
			construct->a = ft_stackpush(construct, value);
			while (ft_isdigit(argv[arg][i])
				|| argv[arg][i] == '-' || argv[arg][i] == '+')
				i++;
		}
		arg++;
	}
}
