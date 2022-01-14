NAME		=	minishell

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm
RMFLAGS		=	-rf

SRC_DIR		=	src
OBJ_DIR		=	obj
INC_DIR 	=	include
LIB_DIR		=	lib

# ================================== LIBFT =================================== #
LIBFT_DIR	=	$(LIB_DIR)/libft
LIBRARIES	=	$(LIBFT_DIR)/libft.a

# =============================== Compile Flags ============================== #
LFLAGS		=	-L $(LIBFT_DIR) -lft -lreadline
IFLAGS		=	-I $(INC_DIR) -I $(LIBFT_DIR)/$(INC_DIR)
CFLAGS		+=	$(IFLAGS) $(LFLAGS)

# **************************************************************************** #
#                                Mandatory Files                               #
# **************************************************************************** #

FILES		=	signal/signal.c \
				startup/start_minishell.c \
				prompt/prompt.c \
				prompt/print_prompt.c \
				main.c

# =============================== Path Setting =============================== #
SRCS		=	$(addprefix $(SRC_DIR)/, $(FILES))
OBJS		=	$(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))


# **************************************************************************** #
#                                  Bonus Files                                 #
# **************************************************************************** #
INC_DIR_BNS = include_bonus
SRC_DIR_BNS = src_bonus
OBJ_DIR_BNS = obj_bonus

FILES_BNS	=	main_bonus.c

# =============================== Path Setting =============================== #
SRCS_BNS	=	$(addprefix $(SRC_DIR_BNS)/, $(FILES_BNS))
OBJS_BNS	=	$(addprefix $(OBJ_DIR_BNS)/, $(FILES_BNS:.c=.o))


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

$(OBJ_DIR)/%.o	:	$(SRC_DIR)/%.c
			@mkdir -p $(@D)
			@$(CC) -c $(CFLAGS) $< -o $@

$(NAME)		:	$(OBJS)
			@echo $(CYAN)"Compiling $@"
			@$(MAKE) all -C $(LIBFT_DIR)
			@$(CC) $(OBJS) -o $(NAME) $(CFLAGS)
			@echo $(GREEN)"Done $@"$(END)

debug		:	$(OBJS)
			@echo $(CYAN)"Creating debug files $@"
			@$(MAKE) all -C $(LIBFT_DIR)
			@$(CC) $(OBJS) -g -o $(NAME) $(CFLAGS)
			@echo $(GREEN)"Done $@"$(END)
			@echo $(WHITE)"Start with \"lldb $(NAME)\""$(END)

all			:	$(NAME)

clean		:	libft_clean
			@echo $(RED)"$(NAME) clean"$(END)
			@$(RM) -f $(OBJS)
			@$(RM) $(RMFLAGS) $(OBJ_DIR)

fclean		:	libft_fclean
			@echo $(RED)"$(NAME) fclean"$(END)
			@$(RM) -f $(OBJS)
			@$(RM) $(RMFLAGS) $(OBJ_DIR) $(NAME)

re			:	fclean all

norm		:
			@$(MAKE) norm -C $(LIBFT_DIR)
			@echo $(RED)
			@norminette $(SRCS) $(INC_DIR)
			@echo $(END)

# =================================== Libft ================================== #
libft		:
			@$(MAKE) all -C $(LIBFT_DIR)
libft_re	:
			@$(MAKE) -C $(LIBFT_DIR) re
libft_clean	:
			@$(MAKE) -C $(LIBFT_DIR) clean
libft_fclean:
			@$(MAKE) -C $(LIBFT_DIR) fclean

# =================================== PHONY ================================== #

.PHONY		:	all clean fclean re bonus \
				norm debug \
				libft libft_re libft_clean libft_fclean