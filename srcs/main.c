/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:25:03 by aquincho          #+#    #+#             */
/*   Updated: 2022/06/06 12:25:09 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_construct	*ft_init_construct(void)
{
	t_construct	*construct;

	construct = malloc(sizeof(t_construct));
	if (!construct)
		exit (1);
	construct->a = NULL;
	construct->b = NULL;
	construct->ope = NULL;
	return (construct);
}

int	main(int argc, char *argv[])
{
	t_construct	*construct;

	construct = ft_init_construct();
	if (argc < 2)
	{
		free (construct);
		exit (1);
	}
	else
		ft_build_stack(argc, argv, construct);
	if (ft_stack_size(construct->a) > 1)
		ft_sort(construct);
/*	ft_printf("a: %d\n", ft_stack_size(construct->a));
	ft_print_stack(construct->a);
	ft_printf("b: %d\n", ft_stack_size(construct->b));
	ft_print_stack(construct->b);
	ft_printf("Sorted a: %d b: %d\n", ft_stack_sorted(construct->a),
		ft_stack_sorted(construct->b));
	ft_printf("nb ope: %d\n", ft_stack_size(construct->ope));*/
	ft_print_ope(construct->ope);
	ft_free_construct(construct);
}
