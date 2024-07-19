# Project #
NAME		=	unnecessary_violence

# Compiler #
CXX			=	c++
CXX_FLAGS		=	-Wall -Wextra -Werror -std=c++98
RM			=	rm -rf

# Objects #
OBJDIR		=	.objFiles

# Files #
FILES		=	main Weapon HumanA HumanB

SRC			=	$(FILES:=.cpp)
# OBJ			=	$(FILES:=.o)
OBJ			= $(addprefix $(OBJDIR)/, $(FILES:=.o))
HEADER		=	Weapon.hpp HumanA.hpp HumanB.hpp

#Colors:
GREEN		=	\e[92;5;118m
YELLOW		=	\e[93;5;226m
GRAY		=	\e[33;2;37m
RESET		=	\e[0m
CURSIVE		=	\e[33;3m

.PHONY: all clean fclean re

# Rules #
all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@$(CXX) $(OBJ) -o $(NAME)
	@printf "$(_SUCCESS) $(GREEN)   - Executable ready.\n$(RESET)"

$(OBJDIR)/%.o: %.cpp $(HEADER)
	@mkdir -p $(dir $@)
	@$(CXX) $(CXX_FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJDIR) $(OBJ)
	@printf "$(YELLOW)    - Object files removed.$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(YELLOW)    - Executable removed.$(RESET)\n"

re: fclean all