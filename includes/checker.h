/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:17:22 by aquincho          #+#    #+#             */
/*   Updated: 2022/06/16 11:17:40 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include <stdlib.h>
# include <limits.h>
# include "push_swap.h"

/* Construction de la pile d'operations checker.c*/
void	ft_build_ope(t_construct *construct);
/* Verification des operations de tri ft_check_pushswap.c */
int		ft_check_pushswap(t_construct *construct);

#endif
