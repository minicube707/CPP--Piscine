
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98

FILE_NAMES =	tests\
				Account

SRC_FILES = $(FILE_NAMES:%=%.cpp)
OBJ_FILES = $(FILE_NAMES:%=%.o)


NAME = DreamJob

.PHONY: all clean fclean re

all : $(NAME)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS)  -c $< -o $@


$(NAME): $(OBJ_FILES) 
	@$(CXX) $(CXXFLAGS) $(OBJ_FILES) -o $(NAME)
	echo "Fichier compile"
	
clean :
	@rm -f $(OBJ_FILES)
	@echo "Fichier object supprime"

fclean : clean	
	@rm -f $(NAME)
	@echo "Fichier executable supprime"

re : fclean all
