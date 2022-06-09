/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:54:23 by aquincho          #+#    #+#             */
/*   Updated: 2022/05/04 13:54:27 by aquincho           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	signe;
	int	resultat;
	int	checkint;

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
		checkint = resultat;
		resultat = resultat * 10 + (nptr[i] - '0');
		if (checkint != (resultat - (nptr[i] - '0')) / 10)
		{
			write(2, "Errori\n", 7);
			exit (1);
		}
		i++;
	}
	return (resultat * signe);
}
