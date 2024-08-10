# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/27 15:38:16 by ylai              #+#    #+#              #
#    Updated: 2024/08/10 16:10:23 by ylai             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long
CC := gcc
MINILIBX_DIR := minilibx-linux/
CFLAGS := -Wall -Werror -Wextra -I${MINILIBX_DIR} -L${MINILIBX_DIR}
LDFLAGS = -lmlx -lXext -lX11
INCLUDE_DIR := include/
SRC_DIR := src/
MAP_DIR := maps/
TEXTURES_DIR := textures/
SRC_FILES := main
SRCS := $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC_FILES)))
OBJS := ${SRCS:.c=.o}

${NAME}: ${OBJS}
	ar rcs $@ $^

${OBJS}: ${SRCS}
	${CC} ${CFLAGS} $< -o $@

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
