# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymohamed <ymohamed@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/25 13:53:10 by ymohamed          #+#    #+#              #
#    Updated: 2022/09/19 13:47:35 by ymohamed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

SOURCES = \
		push_swap.c ps_atoi.c ps_str_utilits.c ps_list_utils.c

OBJECTS = $(SOURCES:%.c=%.o)


CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS) 

clean:
	/bin/rm -f $(OBJECTS) $(OBJECTSB)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

test:
	gcc -g -Wall -Werror -Wextra push_swap.c ps_atoi.c ps_str_utilits.c ps_list_utils.c -o ps

td:
	/bin/rm -f ps

