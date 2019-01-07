/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rcf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 18:33:46 by mgaulet           #+#    #+#             */
/*   Updated: 2017/01/19 18:35:42 by mgaulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	connexion(int *frm, int nb_frm, int *nb, int *tab)
{
	int i;
	int y;
	int tmp;

	i = 0;
	y = 0;
	while (i != 4)
	{
		tmp = nb_frm + tab[i];
		while (y != 4)
		{
			if (!((nb_frm == 4 || nb_frm == 8 ||
							nb_frm == 12 || nb_frm == 16) && tab[i] == 1))
				if (!((nb_frm == 1 || nb_frm == 5 ||
								nb_frm == 9 || nb_frm == 13) && tab[i] == -1))
					if (tmp == frm[y])
						*nb += 1;
			y++;
		}
		y = 0;
		i++;
	}
}

int		ft_rcf(int **forme, int size)
{
	int tab[4];
	int i;
	int y;
	int nb;
	int *formeactu;

	tab[0] = -1;
	tab[1] = 1;
	tab[2] = -4;
	tab[3] = 4;
	i = 0;
	y = 0;
	nb = 0;
	while (i != size)
	{
		formeactu = forme[i];
		while (y != 4)
			connexion(forme[i], formeactu[y++], &nb, tab);
		y = 0;
		if (nb < 6)
			return (0);
		nb = 0;
		i++;
	}
	return (1);
}
