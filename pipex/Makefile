# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cliew < cliew@student.42singapore.sg>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 12:18:06 by cliew             #+#    #+#              #
#    Updated: 2024/01/30 15:32:15 by cliew            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# INCLUDE:=./include
# TARGET:=pipex.a
# SRC:= project.c
# OBJS:=${SRCS:=.o}
# LIB:=./libft_max/libft_max.a
# LIBR:= ranlib
# CC:=cc
# CFLAGS:=-g -std=c99 -Wall -Wextra -Werror -I ${INCLUDE}
# AR:=ar crs
# RM:=rm -rf

# .PHONY: all clean fclean re
# .PHONY: $(LIB) 

# all: ${TARGET}
# ${TARGET}: ${OBJS} ${LIB}
# 	$(LIBR) $(LIB)
# 	@$(CC) $(CFLAGS) $(OBJS) $(LIB) -o ${TARGET}
# %.o: %.c
 

# clean:
# 	@$(RM) $(OBJS) $(LIB)
# fclean: clean
# 	@$(RM) $(TARGET)
# re: fclean all
INCLUDE := ./include
NAME := pipex
SRC := pipex.c utils.c
SRCS := $(SRC)
OBJS := $(SRCS:.c=.o)
LIB := ./libft_max/libft_max.a
LIBR := ranlib
CC := cc
CFLAGS := -g -std=c99 -Wall -Wextra -Werror -I$(INCLUDE)
AR := ar crs
RM := rm -rf

.PHONY: all s clean fclean re

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
	$(RM) $(TARGET)
	$(MAKE) -C ./libft_max fclean

re: fclean all


		

