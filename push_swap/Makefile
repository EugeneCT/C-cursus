# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cliew <cliew@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 12:18:06 by cliew             #+#    #+#              #
#    Updated: 2024/02/05 15:54:09 by cliew            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


INCLUDE := ./include
NAME := push_swap
SRC := pushswap.c actions.c stack_utility.c stack_utility2.c chunk_simulate.c sort_helper.c
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

	@$(CC) $(CFLAGS) $(OBJS) $(LIB) -o ${NAME}

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


		

