/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 14:09:02 by mgaulet           #+#    #+#             */
/*   Updated: 2017/01/19 16:46:55 by mgaulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		**ft_open(int size, char *str)
{
	char	*buff;
	int		fd;
	int		**forme;
	int		i;

	i = 0;
	buff = (char *)malloc(sizeof(char) * 1);
	fd = open(str, O_RDWR);
	if (fd == -1)
		write(1, "error", 5);
	if (!(forme = (int **)malloc(sizeof(int *) * size + 1)))
		return (0);
	*(forme + (size)) = NULL;
	while (i != (size))
		if (!(forme[i++] = (int *)malloc(sizeof(int) * 5)))
			return (0);
	forme = ft_stk_int(fd, buff, forme);
	close(fd);
	return (forme);
}
