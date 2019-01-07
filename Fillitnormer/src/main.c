/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 13:33:21 by mgaulet           #+#    #+#             */
/*   Updated: 2017/01/19 18:35:45 by mgaulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		error(void)
{
	write(1, "error\n", 6);
	return (0);
}

int		ft_error(int **forme, int size)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (x != size)
	{
		while (i != 3)
		{
			if (forme[x][i] == 4 && forme[x][i + 1] == 5)
				return (0);
			if (forme[x][i] == 8 && forme[x][i + 1] == 9)
				return (0);
			if (forme[x][i] == 12 && forme[x][i + 1] == 13)
				return (0);
			i++;
		}
		i = 0;
		x++;
	}
	if (!(ft_twins(forme, size)))
		return (0);
	return (1);
}

void	freeforme(int **forme)
{
	int x;
	int *tmp;

	x = 0;
	while (*forme)
	{
		tmp = *forme++;
		free(tmp);
	}
	free(*forme);
}

int		main(int argc, char **argv)
{
	int **forme;
	int size;
	int sizex;

	size = 0;
	sizex = 0;
	if (argc > 2)
		return (error());
	if (!(ft_error_open(&size, argv[1])))
		return (error());
	forme = ft_open(size, argv[1]);
	if (!(ft_rcf(forme, size)))
		return (error());
	forme = ft_ini_frm(forme, size);
	if (!(ft_cmp_frm(forme, size)))
		return (error());
	ft_initsize(&sizex, size);
	if (sizex == 2 && *(*forme + 3) == 4)
		sizex = 4;
	ft_tabint(sizex, forme);
	algo(&forme, size, sizex, forme);
	return (0);
}
