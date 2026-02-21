
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -MMD -MP -std=c++98

FILE_NAMES =	megaphone
				
SRC_FILES = $(FILE_NAMES:%=%.cpp)
OBJ_FILES = $(FILE_NAMES:%=%.o)
DEP_FILES = $(OBJ_FILES:.o=.d)

NAME = megaphone

.PHONY: all clean fclean re

all : $(NAME)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS)  -c $< -o $@


$(NAME): $(OBJ_FILES) 
	@$(CXX) $(CXXFLAGS) $(OBJ_FILES) -o $(NAME)
	@echo "Fichier compile"
	
clean :
	@rm -f $(OBJ_FILES) $(DEP_FILES)
	@echo "Fichier object supprime"

fclean : clean	
	@rm -f $(NAME)
	@echo "Fichier executable supprime"

re : fclean all

# Automatic inclusion of .d files if they exist
-include $(DEP_FILES)