# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cliew <cliew@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 12:18:06 by cliew             #+#    #+#              #
#    Updated: 2023/10/09 12:21:16 by cliew            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_nextl_ine.a
SRCS = get_next_line.c get_next_line_utils.c
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
