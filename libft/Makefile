# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takuokam <takuokam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 18:31:13 by takuokam          #+#    #+#              #
#    Updated: 2022/10/31 20:46:02 by takuokam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
FUNC	:= memset bzero memcpy memmove memchr memcmp strlen isalpha isdigit isalnum \
				isascii isprint toupper tolower strchr strrchr strncmp strlcpy strlcat strnstr \
				atoi calloc strdup substr strjoin strtrim split itoa strmapi putchar_fd putstr_fd \
				putendl_fd putnbr_fd striteri
B_FUNC	:=		lstnew lstadd_front lstsize lstlast lstadd_back lstdelone lstclear lstiter lstmap
CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror
SRCS	:= $(addprefix ft_,$(addsuffix .c, $(FUNC)))
B_SRCS	:= $(addprefix ft_,$(addsuffix .c, $(B_FUNC)))
OBJS	:= $(addprefix ft_,$(addsuffix .o, $(FUNC)))
B_OBJS	:= $(addprefix ft_,$(addsuffix .o, $(B_FUNC)))

ifdef WITH_BONUS
OBJS += $(B_OBJS)
endif

all: $(NAME)

$(NAME):$(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	rm -f $(NAME)
	
bonus:
	@make WITH_BONUS=1

re: fclean all

.PHONY:	all clean fclean re
