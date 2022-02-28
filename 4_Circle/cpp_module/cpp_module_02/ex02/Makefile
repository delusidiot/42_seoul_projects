NAME		=	a.out

CXX			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98
UNAME		=	$(shell uname)

RM			=	rm
RMFLAGS		=	-rf

SRC_DIR		=	src
OBJ_DIR		=	obj
INC_DIR 	=	include

IFLAGS		=	-I$(INC_DIR)

FILES		=	Fixed.cpp \
				main.cpp

SRCS		=	$(addprefix $(SRC_DIR)/, $(FILES))
OBJS		=	$(addprefix $(OBJ_DIR)/, $(FILES:.cpp=.o))

# =============================== Font Colors ================================ #
END			=	"\033[0;0m"
RED			=	"\033[1;31m"
GREEN		=	"\033[1;32m"
YELLOW		=	"\033[1;33m"
BLUE		=	"\033[1;34m"
PURPLE		=	"\033[1;35m"
CYAN		=	"\033[1;36m"
WHITE		=	"\033[1;37m"
# ============================================================================ #

$(OBJ_DIR)/%.o	:	$(SRC_DIR)/%.cpp
				@mkdir -p $(@D)
				@$(CXX) -c $(CFLAGS) $< -o $@ $(IFLAGS)

$(NAME)		:	$(OBJS)
				@echo $(PURPLE)"Compling $@"$(END)
				@$(CXX) $(OBJS) -o $(NAME) $(CFLAGS) $(IFLAGS)
				@echo $(GREEN)"Done $@"$(END)

clean		:	
				@$(RM) $(RMFLAGS) $(OBJ_DIR)

fclean		:	clean
				@$(RM) $(RMFLAGS) $(NAME)

re			:	fclean $(NAME)

# =================================== PHONY ================================== #
.PHONY		:	all clean fclean re