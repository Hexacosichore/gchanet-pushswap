# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gchanet <gchanet@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/01 16:32:21 by gchanet           #+#    #+#              #
#    Updated: 2021/11/25 19:57:11 by gchanet          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

BLU 		= \033[0;34m
GRN 		= \033[0;32m
RED 		= \033[0;31m
RST 		= \033[0m

SRC			= push.c \
				pushswap.c \
				rotate_rev.c \
				rotate.c \
				utils.c \
				swap.c
OBJ			= ${addprefix src/,	${SRC:.c=.o}}
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -Iinclude
CLIBFT		= -Llibft -lft
NAME		= push_swap
HEADER		= include/push_swap.h

all: ${NAME}

${NAME}: ${OBJ} 
	@${MAKE} -C libft libft.a
	@${CC} ${CFLAGS} ${OBJ} -o ${NAME} ${CLIBFT}
	@printf "${GRN}%10s${RST} %20s \n" "[DONE]" "$(NAME) has created"

%.o: %.c ${HEADER}
	@${CC} ${CFLAGS} -c $< -o $@
	@printf "${BLU}%10s${RST} %20s %20s\n" "[BUILD]" "$<" "$@"

clean:
	@rm -f ${OBJ}
	@printf "${GRN}%10s${RST} %20s \n" "[CLEAN]" "done"

fclean: clean
	@rm -f ${NAME}
	@printf "${GRN}%10s${RST} %20s \n" "[FCLEAN]" "done"

run: ${NAME}
	./push_swap 87 -487 781 -100 101 0 1

re: fclean all