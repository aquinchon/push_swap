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

/*# include "../libft/includes/libft.h"*/
# include "libft.h"
/*# include "../libft/includes/ft_printf.h"*/
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				data;
	int				key;
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
	pa,
	pb,
	ra,
	rb,
	rra,
	rrb,
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
int		ft_stack_size(t_stack *stack);
t_stack	*ft_stack_last(t_stack *stack);
/* Gestion de la memoire utilisee par les piles ft_free_mem.c */
void	ft_free_stack(t_stack *stack);
void	ft_free_construct(t_construct *construct);
void	ft_free_array(int **array);
/* Operations sur les piles ft_stack_ope.c */
void	ft_swap(t_stack *stack, t_stack **ope, t_numope n_ope);
void	ft_push(t_stack **from, t_stack **to, t_stack **ope, t_numope n_ope);
void	ft_rotate(t_stack **stack, t_stack **ope, t_numope n_ope);
void	ft_rrotate(t_stack **stack, t_stack **ope, t_numope n_ope);
/* Tri naif ft_sort.c */
void	ft_sort(t_construct *construct);
void	ft_sort_basic(t_construct *construct);
void	ft_sort_median(t_construct *construct);
void	ft_sort_radix(t_construct *construct);
/* Tri 3 a 5 elements ft_small_sort.c */
void	ft_sort_3elemts(t_construct *construct);
void	ft_sort_5elemts(t_construct *construct);
/* fonctions pour le tri ft_sort_utils.c */
int		ft_stack_sorted(t_stack *stack);
int		**ft_build_array(t_stack *stack);
int		**ft_sort_array(t_stack *stack);
int		ft_find_median(t_stack *stack);
/* print stack ou operations ft_print_stack.c */
void	ft_print_stack(t_stack *stack);
void	ft_write_ope(t_stack **stack, t_numope num_ope);
void	ft_print_ope(t_stack *ope);

#endif
