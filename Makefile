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
CC := cc
MINILIBX_DIR := minilibx-linux
CFLAGS := -Wall -Werror -Wextra
MINILIBX_FLAGS := -I${MINILIBX_DIR} -L${MINILIBX_DIR}
LDFLAGS = -lmlx -lXext -lX11
MAP_DIR := maps/
TEXTURES_DIR := textures/
SRC_FILE_NAMES := main close_window_esc close_window_click
SRCS := $(addsuffix .c, $(SRC_FILE_NAMES))
OBJS := ${SRCS:.c=.o}	

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${MINILIBX_FLAGS} ${OBJS} ${LDFLAGS} -o $@

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
