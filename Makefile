# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/27 15:38:16 by ylai              #+#    #+#              #
#    Updated: 2024/09/02 19:55:04 by ylai             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long
CC := cc
MINILIBX_DIR := minilibx-linux
FT_PRINTF_DIR := ft_printf
FT_PRINTF := ${FT_PRINTF_DIR}/libftprintf.a
LIBFT_DIR := libft
LIBFT := ${LIBFT_DIR}/libft.a
CFLAGS := -Wall -Werror -Wextra -g
MINILIBX_FLAGS := -I${MINILIBX_DIR} -L${MINILIBX_DIR}
LDFLAGS = -lmlx -lXext -lX11
MAP_DIR := maps/
TEXTURES_DIR := textures/
GNL_DIR := get_next_line/
GNL_FILE_NAMES := get_next_line_bonus get_next_line_utils_bonus
SRC_FILE_NAMES := main check_shape \
									sl_strlen count_lines copy_map initialise \
									check_map_con find_item count_items check_path \
									free_map render_map move_player \
									load_image
SRCS := $(addsuffix .c, $(SRC_FILE_NAMES)) \
				$(addsuffix .c, $(addprefix ${GNL_DIR}, ${GNL_FILE_NAMES}))
OBJS := ${SRCS:.c=.o}
BONUS_NAME := so_long_bonus
BONUS_FILE_NAMES := main_bonus check_shape \
										sl_strlen count_lines copy_map initialise_bonus \
										check_map_con find_item count_items check_path \
										free_map render_map_bonus move_player_bonus \
										load_image
BONUS_SRCS := $(addsuffix .c, $(BONUS_FILE_NAMES)) \
					$(addsuffix .c, $(addprefix ${GNL_DIR}, ${GNL_FILE_NAMES}))
BONUS_OBJS := ${BONUS_SRCS:.c=.o}
	
all: ${FT_PRINTF} ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${MINILIBX_FLAGS} ${OBJS} ${FT_PRINTF} ${LDFLAGS} -o $@

clean:
	@make -C ${FT_PRINTF_DIR} clean
	@make -C ${LIBFT_DIR} clean
	rm -f ${OBJS}
	rm -f ${BONUS_OBJS}

fclean: clean
	@make -C ${FT_PRINTF_DIR} fclean
	@make -C ${LIBFT_DIR} fclean
	rm -f ${NAME}
	rm -f ${BONUS_NAME}

re: fclean all

bonus: ${FT_PRINTF} ${LIBFT} ${BONUS_NAME}

${BONUS_NAME}: ${BONUS_OBJS}
	${CC} ${CFLAGS} ${MINILIBX_FLAGS} ${BONUS_OBJS} ${FT_PRINTF} ${LIBFT} ${LDFLAGS} -o $@

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

${FT_PRINTF}:
	@make -C ${FT_PRINTF_DIR}

${LIBFT}:
	@make -C ${LIBFT_DIR}

.PHONY: all clean fclean re
