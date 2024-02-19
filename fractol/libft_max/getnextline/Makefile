# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 12:18:06 by cliew             #+#    #+#              #
#    Updated: 2024/01/10 21:47:54 by cliew            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.a
SRCS = gnl.c gnl_util.c
OBJS = $(SRCS:.c=.o)
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
