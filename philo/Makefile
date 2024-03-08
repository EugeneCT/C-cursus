# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 12:18:06 by cliew             #+#    #+#              #
#    Updated: 2024/03/08 10:23:46 by cliew            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


INCLUDE := ./include
NAME := philo
SRC := philo.c utilities.c
SRCS := $(SRC)
OBJS := $(SRCS:.c=.o)
# LIB := ./libft_max/libft_max.a
# LIBR := ranlib
CC := cc
# CFLAGS := -g -std=c99 -Wall -Wextra -Werror  -fsanitize=thread -pthread -I$(INCLUDE)
CFLAGS := -g -std=c99 -Wall -Wextra -Werror -I$(INCLUDE)

AR := ar crs
RM := rm -rf

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) 

	@$(CC) $(CFLAGS) $(OBJS) -o ${NAME}

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all


		

