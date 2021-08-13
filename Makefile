# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anadege <anadege@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/03 15:49:20 by anadege           #+#    #+#              #
#    Updated: 2021/08/13 16:15:41 by anadege          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ./srcs/main.c \
		  ./srcs/parsing.c \
		  ./srcs/tag_values.c \
		  ./srcs/tag_utils.c \
		  ./srcs/quick_sort.c \
		  ./srcs/push_swap_operations.c \
		  ./srcs/rotation_operations.c \
		  ./srcs/list_utils.c \
		  ./srcs/utils.c \
		  ./srcs/shorts_solutions.c \
		  ./srcs/check_order.c

HEADERS_FILE = includes

NAME = push_swap

BONUS = checker

CC	= cc

CFLAGS	= -Wall -Wextra -Werror

OBJS	= ${SRCS:.c=.o}

%.o: %.c
			${CC} -g ${CFLAGS} -I ${HEADERS_FILE} -o $@ -c $<

all:		${NAME}
			@echo "\nWelcome to push_swap project!\n\nEnter a list of unique numbers to sort (with or without quotes) when lauching ./push_swap.\nOperations needed to sort them using two piles (a and b)will be displayed.\n\nThe operations are :\n- Swap a (sa) : Swap two elements at the top of pile a\n- Swap b (sb) : Swap two elements at the top of pile b\n- Push a (pa) : Push element at top of pile b to top of pile a.\n- Push b (pb) : Push element at top of pile a to pile b.\n- Rotate a (ra) : Move elements of pile a up to one posisition (element at top go to bottom).\n- Rotate b (rb) : Move elements of pile b up to one posisition (element at top go to bottom).\n- Reverse rotate a (rra) : Move elements of pile a down to one posisition (element at bottom go to top).\n- Reverse rotate b (rrb) : Move elements of pile a down to one posisition (element at bottom go to top).\n- Rr : Both ra and rb at the same time.\n- Rrr : Both rra and rrb at the same time.\n\n"

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

clean:
			@rm -f ${OBJS}

fclean: 	clean
			@rm -f ${NAME}

re:			fclean all

.PHONY: all clean re

