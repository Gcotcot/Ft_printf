# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcot <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 12:13:33 by gcot              #+#    #+#              #
#    Updated: 2023/02/23 11:43:25 by gcot             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

SRC = ft_printf.c ft_conv_1.c ft_conv_2.c ft_itoa.c ft_itoa_u.c ft_putnbr_base.c ft_putnbr_base_adresse.c

BONUS = 

OBJ = *.o

FLAGS = -Wall -Werror -Wextra

all :
	gcc $(FLAGS) -c $(SRC)
	ar -rc $(NAME) $(OBJ)

clean : 
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)

re : fclean all

bonus :
	gcc $(FLAGS) -c $(BONUS) $(SRC)
	ar -rc $(NAME) $(OBJ)
