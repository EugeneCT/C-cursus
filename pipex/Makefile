# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cliew <cliew@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 12:18:06 by cliew             #+#    #+#              #
#    Updated: 2024/01/31 19:39:00 by cliew            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDE := ./include
NAME := pipex
SRC := pipex.c utils.c
BONUS_SRC:=pipex_bonus.c utils_bonus.c
SRCS := $(SRC)
BONUS_SRCS := $(BONUS_SRC)
OBJS := $(SRCS:.c=.o)
BONUS_OBJS := $(BONUS_SRCS:.c=.o)
LIB := ./libft_max/libft_max.a
LIBR := ranlib
CC := cc
CFLAGS := -g -std=c99 -Wall -Wextra -Werror -I$(INCLUDE)
AR := ar crs
RM := rm -rf

.PHONY: all bonus clean fclean re

all: $(NAME)


$(NAME): $(OBJS) $(LIB)

	@$(CC) $(CFLAGS) $(OBJS) $(LIB) -o ${NAME}




%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB):
	$(MAKE) -C ./libft_max

clean:
	$(RM) $(OBJS)
	$(RM) $(BONUS_OBJS)
	$(MAKE) -C ./libft_max clean

fclean: clean
	$(RM) $(TARGET)
	$(MAKE) -C ./libft_max fclean

re: fclean all

bonus: $(BONUS_OBJS) $(LIB)

	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIB) -o ${NAME}

		

