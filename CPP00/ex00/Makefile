
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

FILE_NAMES =	megaphone
				
SRC_FILES = $(FILE_NAMES:%=%.cpp)
OBJ_FILES = $(FILE_NAMES:%=%.o)

NAME = megaphone

.PHONY: all clean fclean re

all : $(NAME)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS)  -c $< -o $@


$(NAME): $(OBJ_FILES) 
	@$(CXX) $(CXXFLAGS) $(OBJ_FILES) -o $(NAME)

clean :
	@rm -f $(OBJ_FILES)

fclean : clean	
	@rm -f $(NAME)

re : fclean all
