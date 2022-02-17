# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/12 09:31:42 by jjeon             #+#    #+#              #
#    Updated: 2022/02/12 09:31:43 by jjeon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
UNAME		=	$(shell uname)

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
IFLAGS_BNS	=	-I $(INC_DIR_BNS) -I $(LIBFT_DIR)/$(INC_DIR)
ifeq ($(UNAME), Darwin)
	ifeq ($(USER), jeongyeong-yeon)
		IFLAGS		+=	-I/opt/homebrew/opt/readline/include
		IFLAGS_BNS	+=	-I/opt/homebrew/opt/readline/include
		LFLAGS		+=	-L/opt/homebrew/opt/readline/lib
	else
		IFLAGS		+=	-I${HOME}/.brew/opt/readline/include
		IFLAGS_BNS	+=	-I${HOME}/.brew/opt/readline/include
		LFLAGS		+=	-L${HOME}/.brew/opt/readline/lib
	endif
endif
#CFLAGS		+=	$(IFLAGS) $(LFLAGS)

# **************************************************************************** #
#                                Mandatory Files                               #
# **************************************************************************** #

FILES		=	parser/lexical_analysis/lexical_analyzer.c \
				parser/lexical_analysis/tokenizer.c \
				parser/lexical_analysis/token_value_analyzer.c \
				parser/lexical_analysis/token_check.c \
				parser/lexical_analysis/token_check_values.c \
				parser/lexical_analysis/token_flaging.c \
				parser/lexical_analysis/source.c \
				parser/lexical_analysis/wildcard_parser.c \
				parser/lexical_analysis/wildcard.c \
				parser/lexical_analysis/utils.c \
				parser/syntax_analysis/syntax_analyzer.c \
				parser/syntax_analysis/syntax_ast.c \
				parser/syntax_analysis/syntax_cmd.c \
				parser/syntax_analysis/syntax_others.c \
				parser/syntax_analysis/free_ast.c \
				parser/syntax_analysis/print_ast.c \
				parser/syntax_analysis/utils.c \
				executor/exec_command.c \
				executor/exec_pipe.c \
				executor/exec_redirect.c \
				executor/exec_builtins.c \
				executor/executor.c \
				executor/utils.c \
				exception/builtin_exception.c \
				exception/exception.c \
				exception/exec_exception.c \
				exception/prompt_exception.c \
				signal/signal.c \
				startup/start_minishell.c \
				prompt/prompt.c \
				prompt/prompt_syntax.c \
				prompt/print_prompt.c \
				utiles/end_of_word.c \
				utiles/is_white_space.c \
				utiles/change_lst_to_arr.c \
				utiles/flag_utile.c \
				utiles/err_msg_join.c \
				builtin/ft_export.c \
				builtin/ft_unset.c \
				builtin/ft_env.c \
				builtin/ft_echo.c \
				builtin/ft_cd.c \
				builtin/ft_exit.c \
				builtin/underscore.c \
				builtin/export_utile.c \
				builtin/export_sort.c \
				builtin/export_print.c \
				builtin/env_utile.c \
				builtin/ex_un_utile.c \
				builtin/str_conversion.c \
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

FILES_BNS	=	parser/lexical_analysis/lexical_analyzer_bonus.c \
				parser/lexical_analysis/tokenizer_bonus.c \
				parser/lexical_analysis/token_value_analyzer_bonus.c \
				parser/lexical_analysis/token_check_bonus.c \
				parser/lexical_analysis/token_check_values_bonus.c \
				parser/lexical_analysis/token_flaging_bonus.c \
				parser/lexical_analysis/source_bonus.c \
				parser/lexical_analysis/wildcard_parser_bonus.c \
				parser/lexical_analysis/wildcard_bonus.c \
				parser/lexical_analysis/utils_bonus.c \
				parser/syntax_analysis/syntax_analyzer_bonus.c \
				parser/syntax_analysis/syntax_ast_bonus.c \
				parser/syntax_analysis/syntax_cmd_bonus.c \
				parser/syntax_analysis/syntax_others_bonus.c \
				parser/syntax_analysis/free_ast_bonus.c \
				parser/syntax_analysis/print_ast_bonus.c \
				parser/syntax_analysis/utils_bonus.c \
				executor/exec_command_bonus.c \
				executor/exec_pipe_bonus.c \
				executor/exec_redirect_bonus.c \
				executor/exec_builtins_bonus.c \
				executor/executor_bonus.c \
				executor/utils_bonus.c \
				exception/builtin_exception_bonus.c \
				exception/exception_bonus.c \
				exception/exec_exception_bonus.c \
				exception/prompt_exception_bonus.c \
				signal/signal_bonus.c \
				startup/start_minishell_bonus.c \
				prompt/prompt_bonus.c \
				prompt/prompt_syntax_bonus.c \
				prompt/print_prompt_bonus.c \
				utiles/end_of_word_bonus.c \
				utiles/is_white_space_bonus.c \
				utiles/change_lst_to_arr_bonus.c \
				utiles/flag_utile_bonus.c \
				utiles/err_msg_join_bonus.c \
				builtin/ft_export_bonus.c \
				builtin/ft_unset_bonus.c \
				builtin/ft_env_bonus.c \
				builtin/ft_echo_bonus.c \
				builtin/ft_cd_bonus.c \
				builtin/ft_exit_bonus.c \
				builtin/underscore_bonus.c \
				builtin/export_utile_bonus.c \
				builtin/export_sort_bonus.c \
				builtin/export_print_bonus.c \
				builtin/env_utile_bonus.c \
				builtin/ex_un_utile_bonus.c \
				builtin/str_conversion_bonus.c \
				main_bonus.c

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

ifdef WITH_BONUS
	OBJ_DIR = $(OBJ_DIR_BNS)
	SRC_DIR = $(SRC_DIR_BNS)
	OBJS	= $(OBJS_BNS)
	IFLAGS	= $(IFLAGS_BNS)
endif

$(OBJ_DIR)/%.o	:	$(SRC_DIR)/%.c
			@mkdir -p $(@D)
			@$(CC) -c $(CFLAGS) $< -o $@ $(IFLAGS)

$(NAME)		:	$(OBJS)
			@echo $(CYAN)"Compiling $@"$(END)
			@$(MAKE) all -C $(LIBFT_DIR)
			@$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(LFLAGS) $(IFLAGS)
			@echo $(GREEN)"Done $@"$(END)

debug		:	$(OBJS)
			@echo $(CYAN)"Creating debug files $@"$(END)
			@$(MAKE) all -C $(LIBFT_DIR)
			@$(CC) $(OBJS) -g -o $(NAME) $(CFLAGS) $(LFLAGS) $(IFLAGS)
			@echo $(GREEN)"Done $@"$(END)
			@echo $(WHITE)"Start with \"lldb $(NAME)\""$(END)

bonus		:
			@echo $(PURPLE)"Compiling $@"$(END)
			@$(MAKE) WITH_BONUS=1 all
			@echo $(GREEN)"Done $@"$(END)

all			:	$(NAME)

clean		:	libft_clean
			@echo $(RED)"$(NAME) clean"$(END)
			@$(RM) -f $(OBJS) $(OBJS_BNS)
			@$(RM) $(RMFLAGS) $(OBJ_DIR) $(OBJ_DIR_BNS)

fclean		:	libft_fclean
			@echo $(RED)"$(NAME) fclean"$(END)
			@$(RM) -f $(OBJS) $(OBJS_BNS)
			@$(RM) $(RMFLAGS) $(OBJ_DIR) $(OBJ_DIR_BNS) $(NAME)

re			:	fclean all

bonus_re	:	fclean bonus

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

.PHONY		:	all clean fclean re bonus bonus_re\
				norm debug \
				libft libft_re libft_clean libft_fclean
