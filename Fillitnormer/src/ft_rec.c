/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:27:56 by mgaulet           #+#    #+#             */
/*   Updated: 2017/01/19 15:31:13 by mgaulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_ch(int **tmp, int *taille)
{
	while (**tmp)
	{
		*tmp += 1;
		if (*tmp >= taille)
			return (2);
	}
	return (0);
}

void	supp(int *tab, int *forme, int *tmp)
{
	int nb;

	nb = ((tmp - tab) - *forme);
	*(tab + (nb + *forme)) = 0;
	*(tab + (nb + *(forme + 1))) = 0;
	*(tab + (nb + *(forme + 2))) = 0;
	*(tab + (nb + *(forme + 3))) = 0;
}

int		cpforme(int nb, int *tab, int *forme)
{
	if (*(tab + (nb + *(forme + 1))))
		return (0);
	if (*(tab + (nb + *(forme + 2))))
		return (0);
	if (*(tab + (nb + *(forme + 3))))
		return (0);
	return (1);
}

void	ft_vf_mv(int nb, int *tab, int **forme, int **main)
{
	*(tab + (nb + **forme)) = (forme - main) + 1;
	*(tab + (nb + *(*forme + 1))) = (forme - main) + 1;
	*(tab + (nb + *(*forme + 2))) = (forme - main) + 1;
	*(tab + (nb + *(*forme + 3))) = (forme - main) + 1;
}

int		ft_rec(int **main, int **forme, int *tab, int sizex)
{
	int *tmp;
	int *taille;
	int val[2];

	taille = (tab + ((sizex * sizex) + sizex) - 3);
	tmp = tab;
	if (!(*forme))
		return (0);
	while (1)
	{
		val[0] = 0;
		while (val[0] == 0)
		{
			if (ft_ch(&tmp, taille) == 2)
				return (2);
			val[1] = ((tmp++ - tab) - **forme);
			if ((val[0] = cpforme(val[1], tab, *forme)))
				ft_vf_mv(val[1], tab, forme, main);
		}
		if ((val[0] = ft_rec(main, (forme + 1), tab, sizex)) == 2)
			supp(tab, *(forme), tmp - 1);
		else
			return (0);
	}
	return (0);
}
