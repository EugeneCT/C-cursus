SRC =   main.cpp 
OBJ = $(SRC:.cpp=.o)

NAME = array

# Compiler and flags
CC = c++ -Wall -Wextra -Werror -std=c++98

# Default target: build the executable
all: $(NAME)

# Link object files to create the executable
$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

# Rule to create object files from source files
%.o: %.cpp
	$(CC) -c $(CXXFLAGS) $< -o $@

# Clean up object files
clean:
	rm -rf $(OBJ)

# Clean everything, including the executable
fclean: clean
	rm -rf $(NAME)

re: fclean all

# Mark these as not actual files
.PHONY: all clean fclean re
