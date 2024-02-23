# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 12:18:06 by cliew             #+#    #+#              #
#    Updated: 2024/02/23 21:44:20 by cliew            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


INCLUDE := ./include
NAME := fdf
SRC := fdf.c rotate.c utils.c transform.c mouse_events.c key_events.c inits.c clean.c render.c
SRCS := $(SRC)
OBJS := $(SRCS:.c=.o)
LIB := ./libft_max/libft_max.a
LIBR := ranlib
CC := cc
CFLAGS := -g -std=c99 -Wall -Wextra -Werror -I$(INCLUDE)
AR := ar crs
RM := rm -rf

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(LIB)

	@$(CC) $(CFLAGS) $(OBJS) $(LIB) -o ${NAME} minilibx-linux/libmlx.a -lX11 -lXext -lm -lbsd

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB):
	$(MAKE) -C ./libft_max

clean:
	$(RM) $(OBJS)
	$(MAKE) -C ./libft_max clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C ./libft_max fclean

re: fclean all


		

