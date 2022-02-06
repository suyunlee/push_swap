# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suylee <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/31 13:10:55 by suylee            #+#    #+#              #
#    Updated: 2021/06/01 12:32:46 by suylee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			=	srcs/ft_quicksort.c srcs/function_a.c srcs/function_b.c srcs/function_ab.c\
						srcs/utils_two.c srcs/sort_three.c srcs/utils.c \
						srcs/get_node.c srcs/front_sort.c srcs/sixfive_sort.c
OBJ					= ${SRC:.c=.o}
SRC_PUSH_SWAP		= ./push_swap_srcs/push_swap.c
OBJ_PUSH_SWAP		= ${SRC_PUSH_SWAP:.c=.o}
NAME_PUSH_SWAP		=	push_swap
RM					=	rm -f
CFLAGS				=	-Wall -Wextra -Werror
LIBS				= ./libft/libft.a

.c.o:
	gcc ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${NAME_PUSH_SWAP}

${NAME_PUSH_SWAP}: ${OBJ} ${OBJ_PUSH_SWAP}
					@(make re -C ./libft/)
					gcc -o ${NAME_PUSH_SWAP} ${OBJ} ${OBJ_PUSH_SWAP} ${LIBS}

clean:
	@(make clean -C ./libft/)
	${RM} ${OBJ} ${OBJ_PUSH_SWAP}

fclean: clean
	@(make fclean -C ./libft/)
	${RM} ${NAME_PUSH_SWAP}

re: fclean all

.PHONY: all clean fclean re
