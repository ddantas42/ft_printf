# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddantas- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/24 10:29:01 by ddantas-          #+#    #+#              #
#    Updated: 2022/05/24 10:40:45 by ddantas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCCA = gcc -Wall -Wextra -Werror

NAME = libftprintf.a

FILESC = ft_printf.c \
		ft_printf_utils.c \
		ft_printf_functions.c \

FILESLIBFTC = ./libft/ft_itoa.c \
		./libft/ft_strlen.c \

FILES0 = $(FILESC:.c=.o)
FILESLIB0 = $(FILESLIBFTC:.c=.o)
FILESLIBFT0 = $(FILESLIB0:./libft/=)

all:
	$(GCCA) -c $(FILESC) $(FILESLIBFTC)
	ar rc $(NAME) $(FILES0) $(FILESLIBFTC0)

clean:
	rm -f *.o

fclean: clean
	rm -f libftprintf.a

re: fclean all