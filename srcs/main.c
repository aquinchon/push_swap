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
	ft_print_ope(construct->ope);
	ft_free_construct(construct, 0);
}
