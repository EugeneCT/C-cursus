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

NAME = libftprintf.a
SRCS = ft_printf.c printf_func.c
OBJS = $(SRCS:.c=.o)
CC = cc -Wall -Wextra -Werror -c
LIBC = ar rcs
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	make -C libft
	mv libft/libft.a $(NAME)
	$(LIBC) $(NAME) $(OBJS)

.c.o:
	$(CC) $< -o $(<:.c=.o)

clean:
	make -C libft clean
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re: fclean all