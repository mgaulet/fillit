/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 14:10:40 by mgaulet           #+#    #+#             */
/*   Updated: 2017/01/19 16:35:36 by mgaulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		**ft_stk_int(int fd, char *buff, int **forme)
{
	int **tmp_f;
	int tab[4];

	tab[3] = 0;
	tmp_f = forme;
	tab[2] = 0;
	tab[0] = 0;
	while ((tab[1] = read(fd, buff, 1)))
	{
		tab[2]++;
		if (*buff == '\n')
			tab[0]++;
		if (*buff == '#')
			*(*(forme) + tab[3]++) = tab[2] - tab[0];
		if (tab[3] == 4)
			*(*(forme) + tab[3]) = 0;
		if (tab[2] == 21)
		{
			tab[3] = 0;
			tab[0] = 0;
			tab[2] = 0;
			forme += 1;
		}
	}
	return (tmp_f);
}
