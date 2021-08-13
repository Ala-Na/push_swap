# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anadege <anadege@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/03 15:49:20 by anadege           #+#    #+#              #
#    Updated: 2021/08/10 21:36:10 by anadege          ###   ########.fr        #
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

B_SRCS = ./checker_srcs/checker.c \
		 ./checker_srcs/instructions.c \
		 ./checker_srcs/operations_push_swap.c \
		 ./checker_srcs/operations_rotations_1.c \
		 ./checker_srcs/operations_rotations_2.c \
		 ./checker_srcs/parsing.c \
		 ./checker_srcs/utils_1.c \
		 ./checker_srcs/utils_2.c

HEADERS_FILE = includes

NAME = push_swap

BONUS = checker

CC	= cc

CFLAGS	= -Wall -Wextra -Werror

OBJS	= ${SRCS:.c=.o}

B_OBJS	= ${B_SRCS:.c=.o}

%.o: %.c
			${CC} -g ${CFLAGS} -I ${HEADERS_FILE} -o $@ -c $<

all:		${NAME} ${BONUS}
			@echo "\nWelcome to push_swap project!\n\nEnter a list of unique numbers to sort (with or without quotes) when lauching ./push_swap.\nOperations needed to sort them using two piles (a and b)will be displayed.\n\nThe operations are :\n- Swap a (sa) : Swap two elements at the top of pile a\n- Swap b (sb) : Swap two elements at the top of pile b\n- Push a (pa) : Push element at top of pile b to top of pile a.\n- Push b (pb) : Push element at top of pile a to pile b.\n- Rotate a (ra) : Move elements of pile a up to one posisition (element at top go to bottom).\n- Rotate b (rb) : Move elements of pile b up to one posisition (element at top go to bottom).\n- Reverse rotate a (rra) : Move elements of pile a down to one posisition (element at bottom go to top).\n- Reverse rotate b (rrb) : Move elements of pile a down to one posisition (element at bottom go to top).\n- Rr : Both ra and rb at the same time.\n- Rrr : Both rra and rrb at the same time.\n\nBonus :\nChecker program is present.\nEither enter a pile to sort when lauching ./checker and enter operations (sa/sb/...) followed by a newline (without spaces) or use it on ./push_swap result with pipe.\nIf elements are sorted after the operations given to checker, OK will appear. If not, or in case of error, Error will be displayed.\nPress CTRL + D to stop instructions.\n\n"

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

${BONUS}:	${B_OBJS}
			${CC} -o ${BONUS} ${B_OBJS}

clean:
			@rm -f ${OBJS}
			@rm -f ${B_OBJS}

fclean: 	clean
			@rm -f ${NAME}
			@rm -f ${BONUS}

re:			fclean all

.PHONY: all clean re

