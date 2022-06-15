/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:21:08 by aquincho          #+#    #+#             */
/*   Updated: 2022/06/07 16:21:15 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_check_duplicate(int value, t_construct *construct)
{
	t_stack	*tmp;

	tmp = construct->a;
	while (tmp != NULL)
	{
		if (tmp->data == value)
		{
			write(2, "Error\n", 6);
			ft_free_construct(construct);
			exit (1);
		}
		tmp = tmp->next;
	}
	free (tmp);
	return (0);
}

static int	ft_check_int(char c, int resultat, int signe,
	t_construct *construct)
{
	if ((signe == 1 && resultat <= (INT_MAX - (c - '0')) / 10)
		|| (signe == -1 && resultat * signe >= (INT_MIN + (c - '0')) / 10))
		return (1);
	else
	{
		write(2, "Error\n", 6);
		ft_free_construct(construct);
		exit (2);
	}
}

static int	ft_check_atoi(const char *nptr, t_construct *construct)
{
	int				i;
	int				signe;
	unsigned int	resultat;

	resultat = 0;
	signe = 1;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signe *= -1;
		i++;
	}
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		if (ft_check_int(nptr[i], resultat, signe, construct))
			resultat = resultat * 10 + (nptr[i] - '0');
		i++;
	}
	return (resultat * signe);
}

int	ft_check_data(char *s, t_construct *construct)
{
	int	i;
	int	value;

	i = 0;
	while (s[i] != '\0' && !ft_isspace(s[i]))
	{
		if (ft_isdigit(s[i]) || s[i] == '-' || s[i] == '+')
			i++;
		else
		{
			write(2, "Error\n", 6);
			ft_free_construct(construct);
			exit (1);
		}
	}
	value = ft_check_atoi(s, construct);
	ft_check_duplicate(value, construct);
	return (value);
}
