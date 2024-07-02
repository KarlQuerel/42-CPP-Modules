# Project #
NAME		=	megaphone

# Compiler #
CXX			=	c++
CXX_FLAGS		=	-Wall -Wextra -Werror -std=c++98 -g3
RM			=	rm -rf

# Files #
FILES		=	megaphone.cpp
SRC			=	$(FILES:=.cpp)
OBJ			=	$(SRC:.cpp=.o)
HEADER		=

#Colors:
GREEN		=	\e[92;5;118m
YELLOW		=	\e[93;5;226m
GRAY		=	\e[33;2;37m
RESET		=	\e[0m
CURSIVE		=	\e[33;3m

.PHONY: all clean fclean re

# Rules #
all: $(NAME)

$(NAME):
	@ $(CXX) $(CXX_FLAGS) megaphone.cpp -o $(NAME)
	@printf "$(GREEN)    - Executable ready.\n$(RESET)"

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