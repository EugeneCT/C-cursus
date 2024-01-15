# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 12:18:06 by cliew             #+#    #+#              #
#    Updated: 2024/01/10 21:23:22 by cliew            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_printf.c utilities.c
OBJS = $(SRCS:.c=.o)
CC = cc -Wall -Wextra -Werror -c
LIBC = ar rcs
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
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


---------------------------------------
INCLUDE:=./include
TARGET:=libft.AR
SRC:=
SRCS:=${addprefix ${SRCDIR}, ${SRC}}
OBJS:=${SRCS:=.o}
LIB:=gnl.a libft.a
CC:=cc
CFLAGS:=-g -std=c99 -Wall -Wextra -Werror -I ${INCLUDE}
AR:=ar crs
RM:=rm -rf

.PHONY: all clean fclean re

all: ${TARGET}
${TARGET}: ${OBJS} ${LIB}
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) -o ${TARGET}
%.o: %.c
 
libft.a:
	@make -C ./lib/libft
	@mv ./lib/libft/libft.a .
clean:
	@$(RM) $(OBJS) $(LIB)
fclean: clean
	@$(RM) $(TARGET)
re: fclean all


---------------------------------------------

TARGET := libft_max.a
AR:=ar crs
LIB1 := libft.a
LIB2 := gnl.a
LIB3 := printf.a

CFLAGS := -g -Wall -Wextra

all: $(TARGET)

$(TARGET): $(LIB1) $(LIB2) $(LIB3)
    AR $@ $(shell ar t $(LIB1)) $(shell ar t $(LIB2)) $(shell ar t $(LIB3))

$(LIB1) $(LIB2) $(LIB3):
    # Build each individual library if needed
    # Add your build commands here
    # Example: gcc -c -o file1.o file1.c && ar crs lib1.a file1.o

clean:
    rm -f $(TARGET)
    # Clean individual libraries if needed
    # Example: rm -f $(LIB1) file1.o

.PHONY: all clean