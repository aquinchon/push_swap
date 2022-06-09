/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:26:59 by aquincho          #+#    #+#             */
/*   Updated: 2022/06/06 12:27:02 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include <stdlib.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

typedef struct s_ope
{
	char			*ope;
	struct s_ope	*next;
}	t_ope;

typedef enum e_numope
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
}	t_numope;

typedef struct s_construct
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*ope;
}	t_construct;

/* Construction de la pile a ft_build_stack.c */
void	ft_build_stack(int argc, char **argv, t_construct *construct);
/* Verification integrite des donnees ft_check_data.c */
int		ft_isspace(char c);
int		ft_check_data(char *s, t_construct *construct);
int		ft_check_duplicate(int value, t_construct *construct);
/* Gestion des piles ft_stack_manager.c */
void	ft_free_stack(t_stack *stack);
void	ft_free_construct(t_construct *construct);
void	ft_print_stack(t_stack *stack);

#endif
