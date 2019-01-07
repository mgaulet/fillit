/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:28:15 by mgaulet           #+#    #+#             */
/*   Updated: 2017/01/19 18:35:44 by mgaulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

int		ft_rcf(int **forme, int size);
void	putforme(int **forme);
int		**ft_stk_int(int fd, char *buff, int **forme);
int		ft_error_open(int *size, char *str);
int		**ft_open(int size, char *str);
void	ft_tabint(int size, int **tab);
void	ft_initsize(int *sizex, int size);
int		algo(int ***forme, int size, int sizex, int **type);
int		ft_rec(int **main, int **forme, int *tab, int sizex);
void	printtab(int *tab, int sizex);

int		ft_twins(int **forme, int size);
int		**ft_ini_frm(int **forme, int size);
int		ft_cmp_frm(int **forme, int size);

int		ft_cmp_0(int *forme);
int		ft_cmp_1(int *forme);
int		ft_cmp_2(int *forme);
int		ft_cmp_3(int *forme);
int		ft_cmp_4(int *forme);
int		ft_cmp_5(int *forme);
int		ft_cmp_6(int *forme);
int		ft_cmp_7(int *forme);
int		ft_cmp_8(int *forme);
int		ft_cmp_9(int *forme);
int		ft_cmp_10(int *forme);
int		ft_cmp_11(int *forme);
int		ft_cmp_12(int *forme);
int		ft_cmp_13(int *forme);
int		ft_cmp_14(int *forme);
int		ft_cmp_15(int *forme);
int		ft_cmp_16(int *forme);
int		ft_cmp_17(int *forme);
int		ft_cmp_18(int *forme);

#endif
