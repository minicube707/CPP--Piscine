# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/11 16:36:16 by fmotte            #+#    #+#              #
#    Updated: 2026/02/09 19:32:23 by fmotte           ###   ########.fr        #
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
FILE_NAMES = main 

CLASS_FILE = Bureaucrat 

ABSTR_FILE = 	GradeTooLowException \
				GradeTooHighException \

# =======================================
#              VARIABLE
# =======================================
SRC_PATH = src
OBJ_PATH = obj
HEA_PATH = include

SRC_FILES = $(FILE_NAMES:%=$(SRC_PATH)/%.cpp) $(CLASS_FILE:%=$(SRC_PATH)/%.cpp)
OBJ_FILES = $(FILE_NAMES:%=$(OBJ_PATH)/%.o) $(CLASS_FILE:%=$(OBJ_PATH)/%.o)
HEA_FILES = $(CLASS_FILE:%=$(HEA_PATH)/%.hpp) $(ABSTR_FILE:%=$(HEA_PATH)/%.hpp)

NAME = Mommy_when_I_grow_up_I_want_to_be_a_bureaucrat


# =======================================
#              RULES
# =======================================
.PHONY: all clean fclean re

all : $(NAME)

$(OBJ_PATH) :
	mkdir -p $(OBJ_PATH)

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
