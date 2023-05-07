# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takuokam <takuokam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 18:31:13 by takuokam          #+#    #+#              #
#    Updated: 2023/01/08 19:47:44 by takuokam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long
CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror 
SRCS	:= main.c map_reading.c error_map_reading.c error_map_reading_second.c utils.c window.c event_handle.c put_digit_num.c player.c ghost.c treat_img.c game_end.c
OBJS	:= main.o map_reading.o error_map_reading.o error_map_reading.o utils.o window.o event_handle.o put_digit_num.o player.o ghost.o treat_img.o game_end.o

GNLDIR	:=	./gnl
GNL		:=	$(GNLDIR)/gnl.a

LIBFTDIR	:=	./libft
LIBFT		:=	$(LIBFTDIR)/libft.a

LIBMLXDIR	:=	./minilibx
LIBMLX :=./libmlx.a
LIBFLAGS := -L/usr/X11R6/lib -lmlx -lX11 -lXext -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):$(OBJS)
	$(MAKE) -C $(GNLDIR)
	$(MAKE) -C $(LIBFTDIR)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(GNL) $(LIBFT) $(LIBMLX) $(LIBFLAGS)

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
