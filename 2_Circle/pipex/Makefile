CC = gcc
LIBDIR = ./libft
SRCPATH = src/
OBJPATH = obj/
HDRPATH = include/
LFLAGS = -L $(LIBDIR) -lft
IFLAGS = -I $(HDRPATH) -I $(LIBDIR)/include
CFLAGS = -Wall -Wextra -Werror $(IFLAGS)
LIBRARIES += $(LIBDIR)/libft.a
NAME = pipex
FILES =	argument/ft_get_cmd.c\
		argument/ft_cmd_split.c\
		argument/ft_get_file.c\
		argument/ft_param_init.c\
		argument/ft_utils.c\
		process/ft_exec.c\
		process/ft_process.c
MAIN_FILE = ft_pipex.c
BNS_FILE = ft_pipex_bonus.c
SRC = $(addprefix $(SRCPATH), $(FILES))
OBJ = $(addprefix $(OBJPATH), $(FILES:.c=.o))
MAIN_SRC = $(addprefix $(SRCPATH), $(MAIN_FILE))
BNS_SRC = $(addprefix $(SRCPATH), $(BNS_FILE))

# ========== Colors ==========
END = "\033[0;0m"
RED = "\033[1;31m"
GREEN = "\033[1;32m"
YELLOW = "\033[1;33m"
BLUE = "\033[1;34m"
PURPLE = "\033[1;35m"
CYAN = "\033[1;36m"
WHITE = "\033[1;37m"
# ============================

$(OBJPATH)%.o: $(SRCPATH)%.c
	@mkdir -p $(@D)
	@$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(OBJ)
	@echo $(CYAN)"Compiling $@"
	@$(MAKE) all -C libft
	@$(CC) $(CFLAGS) $(OBJ) $(MAIN_SRC) -o $(NAME) $(LFLAGS)
	@echo $(GREEN)"Done $@"$(END)

bonus: $(OBJ)
	@echo $(CYAN)"Compiling $@"
	@$(MAKE) all -C libft
	@$(CC) $(CFLAGS) $(OBJ) $(BNS_SRC) -o $(NAME) $(LFLAGS)
	@echo $(GREEN)"Done $@"$(END)

debug: $(OBJ)
	@echo $(CYAN)"Creating debug files $@"
	@$(MAKE) all -C libft
	@$(CC) $(CFLAGS) $(OBJ) $(MAIN_SRC) -g -o $(NAME) $(LFLAGS)
	@echo $(GREEN)"Done $@"$(END)
	@echo $(WHITE)"Start with \"lldb $(NAME)\""$(END)

bonus_debug: $(OBJ)
	@echo $(CYAN)"Creating debug files $@"
	@$(MAKE) all -C libft
	@$(CC) $(CFLAGS) $(OBJ) $(BNS_SRC) -g -o $(NAME) $(LFLAGS)
	@echo $(GREEN)"Done $@"$(END)
	@echo $(WHITE)"Start with \"lldb $(NAME)\""$(END)

leak_check:	debug
	@echo $(CYAN) "valgrind start"
	valgrind --leak-check=full --log-file=memcheck.txt -v --error-limit=no ./$(NAME) infile "cat" "wc -c" outfile
	@echo $(END)

bonus_leak_check: bonus_debug
	@echo $(CYAN) "valgrind start"
	valgrind --leak-check=full --log-file=memcheck.txt -v --error-limit=no ./$(NAME) infile "cat" "wc -c" outfile
	@echo $(END)

all: $(NAME)

clean:
	@echo $(RED)"$(NAME) clean"$(END)
	@$(MAKE) -C libft clean
	@rm -f $(OBJ) $(BNS_OBJ)
	@rm -rf $(OBJPATH)

fclean: clean
	@rm -f $(NAME) $(LIBRARIES)

re: fclean all

norm:
	@$(MAKE) norm -C libft
	@echo $(RED)
	@norminette $(SRC) $(HDRPATH)
	@echo $(END)

.PHONY: all clean fclean re bonus norm debug leak_check bonus_debug bonus_leak_check
