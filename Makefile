# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: terabu <terabu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 18:31:13 by takuokam          #+#    #+#              #
#    Updated: 2023/06/11 15:25:02 by terabu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := cub3d
CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror
INC		:=	-I inc/
SRC_DIR	:=	src/
OBJ_DIR	:=	objs/

# SRCS_NAME	:= main.c map_reading.c utils.c window.c event_handle.c put_digit_num.c player.c ghost.c treat_img.c game_end.c error_map_reading.c error_map_reading_second.c raycasting.c
SRCS_NAME	:= main.c raycasting.c input_data.c set_map.c
OBJS_NAME	:= $(SRCS_NAME:.c=.o)
# OBJS_NAME	:= main.o map_reading.o utils.o window.o event_handle.o put_digit_num.o player.o ghost.o treat_img.o game_end.o error_map_reading.o error_map_reading_second.o
# MAP_CHECK_NAME	:=	error_map_reading.c error_map_reading_second.c
# MAP_CHECK_NAME_O	:=	error_map_reading.o error_map_reading_second.o

# MAP_CHECK_DIR := map_check/

# SRCS_NAME += $(addprefix $(MAP_CHECK_DIR), $(MAP_CHECK_NAME))
# OBJS_NAME += $(addprefix $(MAP_CHECK_DIR), $(MAP_CHECK_NAME_O))

SRCS	:=	$(addprefix $(SRC_DIR), $(SRCS_NAME))
OBJS	:=	$(addprefix $(OBJ_DIR), $(OBJS_NAME))


GNLDIR	:=	./lib/gnl
GNL		:=	$(GNLDIR)/gnl.a

LIBFTDIR	:=	./lib/libft
LIBFT		:=	$(LIBFTDIR)/libft.a

LIBMLXDIR	:=	./lib/minilibx-linux
LIBMLX := ./libmlx.a
LIBFLAGS := -L/usr/X11R6/lib -lmlx -lX11 -lXext -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):$(OBJS)
	$(MAKE) -C $(GNLDIR)
	$(MAKE) -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(INC) -o $(NAME) $(SRCS) $(GNL) $(LIBFT) $(LIBMLX) $(LIBFLAGS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR) $(MAP_CHECK_DIR)
	@echo "##### Creating" [ $@ ] " #####"
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $^

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C $(GNLDIR)
	$(MAKE) clean -C $(LIBFTDIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(GNLDIR)
	$(MAKE) fclean -C $(LIBFTDIR)

re: fclean all

.PHONY:	all clean fclean re
