#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmaury <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/22 17:24:16 by fmaury            #+#    #+#              #
#    Updated: 2016/12/12 11:31:28 by fmaury           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=		fillit

SRC			=		ft_lecture.c \
					ft_lstnew.c \
					ft_stock_trans.c \
					ft_valide.c \
					main.c \
					ft_memcpy.c \
					ft_decal.c \
					ft_assemblage.c \
					ft_lstadd.c \
					ft_verif_liens.c \
					ft_verif_t.c \
					ft_tmp_prev.c \
					ft_putchar.c \
					ft_putstr.c \
					ft_cpytab.c \
					ft_placement.c \
					ft_affich_tab.c \
					ft_isok.c

OBJ			=		$(SRC:.c=.o)

CFLAGS		=		-Wall -Wextra -Werror

all			:		$(NAME)

$(NAME)		:		$(OBJ)
					gcc $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ)		:		$(SRC)
					gcc $(CFLAGS) -c $(SRC)

clean		:
					rm -f $(OBJ)

fclean		:		clean
					rm -f $(NAME)

re			:		fclean all

.PHONY		:		all clean re
