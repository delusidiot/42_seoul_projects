CC = gcc
LIBDIR = ./libft
SRCPATH = src/
OBJPATH = obj/
HDRPATH = include/
LFLAGS = -L $(LIBDIR) -lft
IFLAGS = -I $(HDRPATH) -I $(LIBDIR)/include
CFLAGS = -Wall -Wextra -Werror $(IFLAGS)
LIBRARIES += $(LIBDIR)/libft.a
NAME = push_swap
BNS_NAME = checker

FILES = operations/ft_swap.c\
		operations/ft_push.c\
		operations/ft_rotate.c\
		operations/ft_reverse_rotate.c\
		operations/ft_utils.c\
		sorts/ft_sort.c\
		sorts/ft_quick_sort.c\
		sorts/ft_utils.c\
		sorts/ft_stack_sort.c\
		sorts/ft_huge_stack_sort.c\
		sorts/ft_huge_stack_A_to_B.c\
		sorts/ft_huge_stack_B_to_A.c\
		sorts/ft_huge_stack_gets.c\
		sorts/ft_search_push.c\
		argument/ft_argument.c\
		argument/ft_utils.c\
		argument/ft_init_free.c
MAIN_FILE = $(addprefix $(SRCPATH), ft_push_swap.c)
BNS_FILES = checkers/ft_checker_bonus.c
SRC = $(addprefix $(SRCPATH), $(FILES))
OBJ = $(addprefix $(OBJPATH), $(FILES:.c=.o))
BNS_SRC = $(addprefix $(SRCPATH), $(BNS_FILES))
BNS_OBJ = $(addprefix $(OBJPATH), $(BNS_FILES:.c=.o))

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
	@$(CC) $(CFLAGS) $(OBJ) $(MAIN_FILE) -o $(NAME) $(LFLAGS)
	@echo $(GREEN)"Done $@"$(END)

bonus: $(OBJ) $(BNS_OBJ) $(NAME)
	@echo $(CYAN)"Compiling $@"
	@$(CC) $(CFLAGS) $(OBJ) $(BNS_OBJ) -o $(BNS_NAME) $(LFLAGS)
	@echo $(GREEN)"Done $@"$(END)

test: $(OBJ) $(BNS_OBJ)
	@$(MAKE) all -C libft
	$(CC) $(CFLAGS) $(OBJ) $(BNS_OBJ) -g -o $(BNS_NAME) $(LFLAGS)
	valgrind --leak-check=full ./$(BNS_NAME) 3 2 1 > /dev/null

all: $(NAME)

clean:
	@echo $(RED)"$(NAME) clean"$(END)
	@$(MAKE) -C libft clean
	@rm -f $(OBJ) $(BNS_OBJ)
	@rm -rf $(OBJPATH)

fclean: clean
	@rm -f $(NAME) $(LIBRARIES) $(BNS_NAME)

re: fclean all

norm:
	@echo $(RED)
	@norminette $(SRC) $(BNS_SRC) $(HDRPATH)
	@echo $(END)

.PHONY: all clean fclean re bonus norm memory
