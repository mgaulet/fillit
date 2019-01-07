/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmp_frm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 13:32:29 by agaulet           #+#    #+#             */
/*   Updated: 2017/01/19 16:41:01 by mgaulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

typedef	int(*t_op)(int *);

int		ft_cmp_18(int *tab)
{
	int v1[4];
	int i;

	v1[0] = 1;
	v1[1] = 4;
	v1[2] = 5;
	v1[3] = 9;
	i = 0;
	while (tab[i] == v1[i] && i != 4)
		i++;
	if (i == 4)
		return (1);
	return (0);
}

void	ft_inii_tab(int *tab, int size)
{
	tab[0] = 0;
	tab[1] = size;
	tab[2] = 0;
	tab[3] = 0;
	tab[4] = 0;
}

void	ft_ini_ptr_fct(t_op *tab_op)
{
	tab_op[0] = ft_cmp_0;
	tab_op[1] = ft_cmp_1;
	tab_op[2] = ft_cmp_2;
	tab_op[3] = ft_cmp_3;
	tab_op[4] = ft_cmp_4;
	tab_op[5] = ft_cmp_5;
	tab_op[6] = ft_cmp_6;
	tab_op[7] = ft_cmp_7;
	tab_op[8] = ft_cmp_8;
	tab_op[9] = ft_cmp_9;
	tab_op[10] = ft_cmp_10;
	tab_op[11] = ft_cmp_11;
	tab_op[12] = ft_cmp_12;
	tab_op[13] = ft_cmp_13;
	tab_op[14] = ft_cmp_14;
	tab_op[15] = ft_cmp_15;
	tab_op[16] = ft_cmp_16;
	tab_op[17] = ft_cmp_17;
	tab_op[18] = ft_cmp_18;
}

int		ft_cmp_frm(int **forme, int size)
{
	int		tab[5];
	t_op	tab_op[18];

	ft_ini_ptr_fct(tab_op);
	ft_inii_tab(tab, size);
	while (size)
	{
		while (tab[4] != 19)
		{
			tab[3] += tab_op[tab[4]++](*forme);
			if (tab[3] == 1)
			{
				tab[2] += tab[3];
				tab[3] = 0;
				break ;
			}
		}
		tab[4] = 0;
		forme += 1;
		--size;
	}
	if (tab[1] == tab[2])
		return (1);
	return (0);
}
