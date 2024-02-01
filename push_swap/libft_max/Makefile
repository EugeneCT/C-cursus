# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 12:18:06 by cliew             #+#    #+#              #
#    Updated: 2024/01/10 23:38:08 by cliew            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft_max.a
LIB1= ./libft/*.c
LIB2= ./getnextline/*.c
LIB3= ./printf/*.c

# SRCS =  $(LIB1) $(LIB2) $(LIB3)
# OBJS = $(SRCS:.c=.o)
SRCS = $(wildcard $(LIB1) $(LIB2) $(LIB3))
OBJS = $(patsubst %.c, %.o, $(SRCS))
CC = cc -Wall -Wextra -Werror -c
LIBC = ar rcs
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)
	

.c.o:
	$(CC) $< -o $(<:.c=.o)

clean:
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re: fclean all
