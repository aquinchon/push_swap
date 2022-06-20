/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:10:42 by aquincho          #+#    #+#             */
/*   Updated: 2022/06/15 16:11:30 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_check_ope(char *data, t_construct *construct)
{
	if ((ft_strncmp(data, "sa\n", 3) && ft_strncmp(data, "sb\n", 3) \
		&& ft_strncmp(data, "ss\n", 3) && ft_strncmp(data, "pa\n", 3) \
		&& ft_strncmp(data, "pb\n", 3) && ft_strncmp(data, "ra\n", 3) \
		&& ft_strncmp(data, "rb\n", 3) && ft_strncmp(data, "rr\n", 3) \
		&& ft_strncmp(data, "rra\n", 4) && ft_strncmp(data, "rrb\n", 4) \
		&& ft_strncmp(data, "rrr\n", 4)))
	{
		write(2, "Error\n", 6);
		free(data);
		ft_free_construct(construct, 1);
		exit (1);
	}
	return (0);
}

void	ft_build_ope(t_construct *construct)
{
	char	*get_ope;
	char	*trim_ope;

	get_ope = get_next_line(0);
	while (get_ope && !ft_check_ope(get_ope, construct))
	{
		trim_ope = ft_strtrim(get_ope, "\n");
		free(get_ope);
		ft_write_ope(&construct->ope, trim_ope);
		get_ope = get_next_line(0);
	}
	free(get_ope);
}

int	main(int argc, char *argv[])
{
	t_construct	*construct;

	if (argc < 2)
		exit (0);
	construct = ft_init_construct();
	ft_build_stack(argc, argv, construct);
	ft_build_ope(construct);
	if (!ft_check_pushswap(construct))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free_construct(construct, 1);
}
