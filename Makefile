# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymohamed <ymohamed@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/25 13:53:10 by ymohamed          #+#    #+#              #
#    Updated: 2022/10/03 01:50:58 by ymohamed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SOURCES = \
		push_swap.c ps_atoi.c ps_str_utils.c ps_list_utils.c ps_sort_utils.c \
		ps_algo_utils.c ps_sort_funcs.c

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SOURCES)

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
