# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/11 16:36:16 by fmotte            #+#    #+#              #
#    Updated: 2026/01/26 15:38:17 by fmotte           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =======================================
#            MAKEFILE PROJET
# =======================================

# =======================================
#                FLAGS
# =======================================
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98


# =======================================
#              FILE
# =======================================
FILE_NAMES =	main
				

# =======================================
#              VARIABLE
# =======================================
SRC_PATH = .
OBJ_PATH = .
HEA_PATH = .

SRC_FILES = $(FILE_NAMES:%=$(SRC_PATH)/%.cpp) $(CLASS_FILE:%=$(SRC_PATH)/%.cpp)
OBJ_FILES = $(FILE_NAMES:%=$(OBJ_PATH)/%.o) $(CLASS_FILE:%=$(OBJ_PATH)/%.o)
HEA_FILES = $(CLASS_FILE:%=$(HEA_PATH)/%.hpp)

NAME = Sed_is_for_losers


# =======================================
#              RULES
# =======================================
.PHONY: all clean fclean re

all : $(NAME)

$(OBJ_PATH) :
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp $(HEA_FILES) | $(OBJ_PATH)
	@$(CXX) $(CXXFLAGS) -I $(HEA_PATH) -O3 -c $< -o $@


$(NAME): $(OBJ_FILES) 
	@$(CXX) $(CXXFLAGS) $(OBJ_FILES) -o $(NAME)
	@echo "Fichier compile"
	
clean :
	@rm -f $(OBJ_FILES)
	@echo "Fichier object supprime"

fclean : clean	
	@rm -f $(NAME)
	@echo "Fichier executable supprime"

re : fclean all
