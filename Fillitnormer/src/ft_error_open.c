/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_open.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 14:08:25 by mgaulet           #+#    #+#             */
/*   Updated: 2017/01/19 18:54:46 by mgaulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		smallbloc(int *rc, char *buff, int *tab)
{
	*rc = 0;
	tab[4] += (*buff == '#') ? 1 : 0;
	tab[2] += 1;
	*buff == '#' ? tab[1]++ : 0;
	if (tab[1] > 4)
		return (0);
	if ((*buff != '.' && *buff != '#' && *buff != '\n')
			|| (*buff != '\n' && tab[2] == 5))
		return (0);
	if (tab[2] == 5)
	{
		tab[2] = 0;
		tab[0] += 1;
	}
	return (1);
}

int		bloc(int *rc, int fd, int *tab, char *buff)
{
	while (read(fd, buff, 1))
	{
		if (!(smallbloc(rc, buff, tab)))
			return (0);
		if (tab[0] == 4)
		{
			if (tab[4] != 4)
				return (0);
			tab[4] = 0;
			tab[3] += 1;
			if (!(read(fd, buff, 1)))
				break ;
			if (*buff != '\n' || tab[1] != 4)
				return (0);
			tab[1] = 0;
			tab[0] = 0;
			*rc = 1;
		}
	}
	if (tab[0] != 4)
		return (0);
	return (1);
}

int		ft_error_open(int *size, char *str)
{
	int		fd;
	char	buff[1];
	int		i;
	int		rc;
	int		tab[5];

	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	tab[3] = 0;
	tab[4] = 0;
	i = 0;
	if ((fd = open(str, O_RDWR)) == -1)
		return (0);
	if (!(bloc(&rc, fd, tab, buff)))
		return (0);
	*size = tab[3];
	if (rc || tab[2])
		return (0);
	return (1);
}
