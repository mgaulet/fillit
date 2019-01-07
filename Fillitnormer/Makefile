# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fchanal <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/18 23:36:28 by fchanal           #+#    #+#              #
#    Updated: 2017/01/19 19:01:04 by mgaulet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = src/*.c
FLAG = -Wall -Werror -Wextra

all : $(NAME)

$(NAME):
	gcc -Iheader $(SRC) -o $(NAME)

clean:
	rm $(NAME)

re: clean all
