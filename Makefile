# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/27 15:38:16 by ylai              #+#    #+#              #
#    Updated: 2024/08/20 18:36:23 by ylai             ###   ########.fr        #
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
GNL_DIR := get_next_line/
GNL_FILE_NAMES := get_next_line_bonus get_next_line_utils_bonus
SRC_FILE_NAMES := main close_window_esc close_window_click check_map \
									check_line
SRCS := $(addsuffix .c, $(SRC_FILE_NAMES)) \
				$(addsuffix .c, $(addprefix ${GNL_DIR}, ${GNL_FILE_NAMES}))
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
