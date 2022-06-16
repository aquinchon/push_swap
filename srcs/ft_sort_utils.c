/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 10:45:41 by aquincho          #+#    #+#             */
/*   Updated: 2022/06/15 10:45:45 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_sorted(t_stack *stack)
{
	if (!stack || !stack->next)
		return (2);
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_find_median(t_stack *stack)
{
	int	i;
	int	size;
	int	tmp;
	int	**array;

	i = 0;
	size = ft_stack_size(stack);
	array = ft_build_array(stack);
	while (i < size - 1)
	{
		if (array[0][i] > array[0][i + 1])
		{
			tmp = array[0][i];
			array[0][i] = array[0][i + 1];
			array[0][i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
	tmp = array[0][size / 2];
	ft_free_array(array);
	return (tmp);
}

int	**ft_sort_array(t_stack *stack)
{
	int	i;
	int	size;
	int	tmp;
	int	**array;

	i = 0;
	size = ft_stack_size(stack);
	array = ft_build_array(stack);
	while (i < size - 1)
	{
		if (array[0][i] > array[0][i + 1])
		{
			tmp = array[0][i];
			array[0][i] = array[0][i + 1];
			array[0][i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
	i = -1;
	while (++i < size)
		array[1][i] = i;
	return (array);
}

static int	**ft_init_array(int size)
{
	int	**array;
	int	i;

	array = malloc(sizeof(int) * (2 * size));
	array[0] = malloc(sizeof(int) * (size));
	array[1] = malloc(sizeof(int) * (size));
	if (!array || !array[0] || !array[1])
		return (NULL);
	i = 0;
	while (i < size)
	{
		array[0][i] = 0;
		array[1][i] = 0;
		i++;
	}
	return (array);
}

int	**ft_build_array(t_stack *stack)
{
	int	**array;
	int	size;
	int	i;

	size = ft_stack_size(stack);
	array = ft_init_array(size);
	if (!array)
		return (NULL);
	i = 0;
	while (i < size)
	{
		array[0][i] = stack->data;
		i++;
		stack = stack->next;
	}
	return (array);
}
