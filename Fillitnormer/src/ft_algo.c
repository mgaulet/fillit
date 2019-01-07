/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 13:43:13 by mgaulet           #+#    #+#             */
/*   Updated: 2017/01/19 15:31:17 by mgaulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		inittab(int **tab, int sizex)
{
	int *tmp;
	int taille;
	int i;

	taille = (sizex * sizex) + sizex;
	if (!(*tab = (int *)malloc(sizeof(int) * (taille + sizex))))
		return (0);
	tmp = *tab;
	i = 1;
	while (taille--)
	{
		if (i == sizex + 1)
		{
			**tab = 1000;
			i = 0;
		}
		else
			**tab = 0;
		i += 1;
		*tab += 1;
	}
	while (sizex-- != 0)
		*(*(tab))++ = 1000;
	*tab = tmp;
	return (1);
}

void	printtab(int *tab, int sizex)
{
	int i;
	int taille;
	int b;
	int cah;

	taille = (sizex * sizex) + sizex;
	i = 0;
	b = 0;
	while (taille--)
	{
		if (tab[i] == 1000)
			write(1, "\n", 1);
		else
		{
			if (64 != (cah = (char)(tab[i] + 64)))
				write(1, &cah, 1);
			else
				write(1, ".", 1);
		}
		i++;
		b++;
	}
}

void	ft_tabintmin(int size, int **tab)
{
	int **tmp;
	int *tmp1;
	int tabt[3];

	tmp = tab;
	while (*tab)
	{
		tmp1 = *tab;
		tabt[1] = 0;
		tabt[2] = size - 2;
		tabt[0] = 3;
		while (**tab)
		{
			if (**tab > tabt[0])
			{
				tabt[0] += 3;
				*(*tab) += (tabt[1] += tabt[2]);
			}
			else
				*(*(tab)) += tabt[1];
			*tab += 1;
		}
		*(tab++) = tmp1;
	}
	tab = tmp;
}

void	ft_tabintmo(int size, int **tab)
{
	int **tmp;
	int *tmp1;
	int tabt[3];

	tmp = tab;
	while (*tab)
	{
		tmp1 = *tab;
		tabt[1] = 0;
		tabt[2] = 4 - size;
		tabt[0] = size;
		while (**tab)
		{
			if (**tab > tabt[0])
			{
				tabt[0] += size;
				*(*tab) += (tabt[1] += tabt[2]);
			}
			else
				*(*(tab)) += tabt[1];
			*tab += 1;
		}
		*(tab++) = tmp1;
	}
	tab = tmp;
}

int		algo(int ***forme, int size, int sizex, int **type)
{
	int *tab;
	int nb;
	int **formecp;

	nb = 0;
	if (!(inittab(&tab, sizex)))
		return (0);
	if ((nb = ft_rec(*forme, *forme, tab, sizex)) == 2)
	{
		while (nb == 2)
		{
			nb = 0;
			free(tab);
			ft_tabintmo(++sizex, *forme);
			inittab(&tab, sizex);
			ft_tabint(sizex, *forme);
			nb = ft_rec(*forme, *forme, tab, sizex);
		}
	}
	printtab(tab, sizex);
	free(tab);
	return (1);
}
