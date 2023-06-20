# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/08 21:30:27 by jinhyeok          #+#    #+#              #
#    Updated: 2023/06/14 17:58:32 by jinhyeok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCES = ./src/main.c\
		./src/init.c\
		./src/map_checker.c\
		./src/map_checker2.c\
		./src/map_checker3.c\
		./src/so_long.c\
        ./src/so_long_utils.c\
		./src/free.c\
		./src/get_next_line.c\
		./src/get_next_line_utils.c\
		./src/error.c\
		./src/exit.c\
		./src/dfs.c

SOURCES_BONUS = ./src_bonus/display_bonus.c \
				./src_bonus/error_bonus.c\
				./src_bonus/free_bonus.c\
				./src_bonus/game_msg_bonus.c\
				./src_bonus/img_load_bonus.c\
				./src_bonus/init_bonus.c\
				./src_bonus/main_bonus.c\
				./src_bonus/map_checker_bonus.c\
				./src_bonus/map_checker2_bonus.c\
				./src_bonus/map_checker3_bonus.c\
				./src_bonus/monster_bonus.c\
				./src_bonus/monster2_bonus.c\
				./src_bonus/player_bonus.c\
				./src_bonus/so_long_bonus.c\
				./src_bonus/so_long_utils_bonus.c\
				./src_bonus/get_next_line_bonus.c\
				./src_bonus/get_next_line_utils_bonus.c\
				./src_bonus/dfs_bonus.c
INCLUDES = includes

M_OBJ = $(SOURCES:./src/.c=.o)
B_OBJ = $(SOURCES_BONUS:./src_bonus/.c=.o)

ifdef BONUS
	OBJECTS = $(B_OBJ)
	NAME = so_long_bonus
else
	OBJECTS = $(M_OBJ)
	NAME = so_long
endif

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C ft_printf
	make -C mlx
	cp ./mlx/libmlx.dylib ./libmlx.dylib
	$(CC) $^ -Lft_printf -lftprintf -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@ -I $(INCLUDES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
bonus :
	make BONUS=1 all

clean:
	make -C ft_printf clean
	make -C mlx clean

fclean: clean
	rm -rf $(NAME)
	rm -rf ./so_long_bonus
	rm -rf ./libftprintf.a
	rm -rf ./mlx/libmlx.dylib
	rm -rf libmlx.dylib

re: fclean all

.PHONY: all clean fclean re