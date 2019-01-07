/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 14:10:04 by mgaulet           #+#    #+#             */
/*   Updated: 2017/01/19 15:31:15 by mgaulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_tabint(int size, int **tab)
{
	int **tmp;
	int *tmp1;
	int tabt[3];

	tmp = tab;
	while (*tab)
	{
		tmp1 = *tab;
		tabt[1] = 0;
		tabt[2] = size - 3;
		tabt[0] = 4;
		while (**tab)
		{
			if (**tab > tabt[0])
			{
				tabt[0] += 3;
				**tab += (tabt[1] += tabt[2]);
			}
			else
				**tab += tabt[1];
			*tab += 1;
		}
		*(tab++) = tmp1;
	}
	tab = tmp;
}

void	ft_initsize(int *sizex, int size)
{
	int nb;
	int i;

	i = 1;
	nb = size * 4;
	while ((i * i) < nb)
		++i;
	*sizex = i;
}
