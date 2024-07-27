# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/27 15:38:16 by ylai              #+#    #+#              #
#    Updated: 2024/07/27 17:10:28 by ylai             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long
CC := cc
MINILIBX_DIR := minilibx-linux/
CFLAGS := -Wall -Werror -Wextra -I${MINILIBX_DIR}
LDFLAGS = -L${MINILIBX_DIR} -lmlx -lXext -lX11
INCLUDE_DIR := include/
SRC_DIR := src/
MAP_DIR := maps/
TEXTURES_DIR := textures/
SRC_FILES := main
SRCS := $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC_FILES)))
OBJS := ${SRCS:.c=.o}

${NAME}: ${OBJS}
	ar rcs $@ $^

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
