# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 12:18:06 by cliew             #+#    #+#              #
#    Updated: 2024/01/11 15:21:38 by cliew            ###   ########.fr        #
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
TARGET := pipex.a
SRC := pipex.c
SRCS := $(SRC)
OBJS := $(SRCS:.c=.o)
LIB := ./libft_max/libft_max.a
LIBR := ranlib
CC := cc
CFLAGS := -g -std=c99 -Wall -Wextra -Werror -I$(INCLUDE)
AR := ar crs
RM := rm -rf

.PHONY: all clean fclean re

all: $(TARGET)

$(TARGET): $(OBJS) $(LIB)

	@$(CC) $(CFLAGS) $(OBJS) $(LIB) -o ${TARGET}

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


		

