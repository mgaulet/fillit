/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ini_frm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 14:11:12 by mgaulet           #+#    #+#             */
/*   Updated: 2017/01/19 17:49:30 by mgaulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_twins(int **forme, int size)
{
	int i;
	int x;
	int y;

	y = 1;
	i = 0;
	x = 0;
	while (x != (size - 1))
	{
		while (y != size)
		{
			while (i != 4)
			{
				if (forme[x][i] != forme[y][i])
					break ;
				i++;
			}
			if (i == 4)
				return (0);
			i = 0;
			y++;
		}
		y = ++x + 1;
	}
	return (1);
}

int		**ft_ini_frm(int **forme, int size)
{
	int i;
	int y;
	int recup;

	i = 0;
	y = 0;
	while (i != size)
	{
		recup = *(*(forme + i) + y);
		recup--;
		if (*(*(forme + i) + y) != 1)
		{
			while (y != 4)
			{
				*(*(forme + i) + y) -= recup;
				y++;
			}
		}
		y = 0;
		i++;
	}
	return (forme);
}
