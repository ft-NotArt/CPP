# COLORS

YELLOW			=	\x1b[0m\x1b[38;2;255;204;0m
LIGHT_YELLOW	=	\x1b[0m\x1b[38;2;255;224;102m
DARK_YELLOW		=	\x1b[1m\x1b[38;2;153;122;0m

# TARGET

NAME		=	Megaphone

# FLAGS

MAKEFLAGS	=	-s
CXX			=	g++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

# FILES

FILES		=	Megaphone

SRC			=	$(addsuffix .cpp, $(FILES))
OBJ			=	$(addsuffix .o, $(FILES))

# RULES

all			:	$(NAME)

$(NAME)		:	$(OBJ)
				$(CXX) $(CXXFLAGS) $^ -o $@
				echo -e '$(LIGHT_YELLOW) \tCompiled$(DARK_YELLOW) $@'

clean		:
				$(RM) $(OBJ) $(CHECKER_OBJ)
				echo -e '$(LIGHT_YELLOW) \tCleaned$(YELLOW) $(OBJ) $(CHECKER_OBJ)'

fclean		:	clean
				$(RM) $(NAME) $(CHECKER)
				echo -e '$(LIGHT_YELLOW) \tCleaned$(DARK_YELLOW) $(NAME)'

re			:	fclean all

.PHONY		=	all clean fclean re