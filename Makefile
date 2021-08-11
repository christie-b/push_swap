# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/27 11:17:16 by cboutier          #+#    #+#              #
#    Updated: 2021/08/11 09:58:21 by cboutier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR	= srcs

NAMES		= push_swap.c sort.c radix.c push_swap_utils.c push_swap_utils2.c \
				small_sort.c ft_split.c check_sort.c check_args.c radix_utils.c \
				sort_utils.c \
				sort_hundred.c

SRCS		= $(addprefix $(SRCS_DIR)/, $(NAMES))

INCLUDES	= -Iincl

HEADER		= incl/push_swap.h

OBJS		= ${SRCS:.c=.o}

NAME		= push_swap

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g3 #-fsanitize=address 

RM		= rm -f

.c.o:
		$(CC) $(CFLAGS) ${INCLUDES} -c $< -o $(<:.c=.o)

${NAME}:	${OBJS} ${HEADER}
			${CC} ${CFLAGS} ${OBJS} ${INCLUDES} -o ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean
