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
	ft_stack_print(construct->a);
	ft_stack_print(construct->b);
	ft_free_construct(construct);
}
