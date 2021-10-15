# Program name
NAME = fdf

# Folders
LIBDIR = ./libft
LINUX_MLX_DIR = ./minilibx_linux
MAC_MLX_DIR = ./minilibx
SRCPATH = src/
OBJPATH = obj/
HDRPATH = include
LINUX_KEY = key_setting/linux
MAC_KEY = key_setting/macos

# Compiling flags
LINUX_LFLAGS = -L $(LIBDIR) -lft -L$(LINUX_MLX_DIR)\
		 	   -lmlx -L/usr/include/../lib -lXext -lX11 -lm -lbsd
		       
MAC_LFLAGS =  -L $(LIBDIR) -lft -L$(MAC_MLX_DIR)\
			  -lmlx -framework OpenGL -framework AppKit
			  
IFLAGS = -I $(HDRPATH) -I $(LIBDIR)/include
CFLAGS = $(IFLAGS) #-Wall -Wextra -Werror $(IFLAGS)
LIBRARIES += $(LIBDIR)/libft.a

# Source files paths
FILES =	map/map_reader.c \
		map/map_create.c \
		map/utils.c \
		window/create_window.c\
		window/key_event.c\
		draw/draw.c\
		draw/draw_line.c\
		error/error.c
		
MAIN_FILE = fdf.c
BNS_FILE = fdf_bonus.c

# Paths Setting
SRC = $(addprefix $(SRCPATH), $(FILES))
OBJ = $(addprefix $(OBJPATH), $(FILES:.c=.o))
MAIN_SRC = $(addprefix $(SRCPATH), $(MAIN_FILE))
MAIN_OBJ = $(addprefix $(OBJPATH), $(MAIN_FILE:.c=.o))
BNS_SRC = $(addprefix $(SRCPATH), $(BNS_FILE))

# OS Check
UNAME = $(shell uname)

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
ifeq ($(UNAME), Linux)
	@$(CC) -c $(CFLAGS) -I$(LINUX_KEY) $< -o $@
endif
ifeq ($(UNAME), Darwin)
	@$(CC) -c $(CFLAGS) -I$(MAC_KEY) $< -o $@
endif

$(NAME): $(OBJ) $(MAIN_OBJ)
	@echo $(CYAN)"$(UNAME) Compiling $@"
ifeq ($(UNAME), Linux)
	@$(MAKE) all -C $(LIBDIR)
	@$(MAKE) -C $(LINUX_MLX_DIR)
	@$(CC) $(CFLAGS) -I$(LINUX_KEY) $(OBJ) $(MAIN_OBJ) -o $(NAME) $(LINUX_LFLAGS)
endif
ifeq ($(UNAME), Darwin)
	@$(MAKE) all -C $(LIBDIR)
	@$(MAKE) -C $(MAC_MLX_DIR)
	@$(CC) $(CFLAGS) -I$(MAC_KEY) $(OBJ) $(MAIN_OBJ) -o $(NAME) $(MAC_LFLAGS)
endif
	@echo $(GREEN)"$(UNAME) Done $@"$(END)

bonus: $(OBJ)
	@echo $(CYAN)"Compiling $@"
	@$(MAKE) all -C $(LIBDIR)
	@$(MAKE) -C $(LINUX_MLX_DIR)
	@$(CC) $(CFLAGS) $(OBJ) $(BNS_SRC) -o $(NAME) $(LINUX_LFLAGS)
	@echo $(GREEN)"Done $@"$(END)

debug: $(OBJ)
	@echo $(CYAN)"Creating debug files $@"
	@$(MAKE) all -C $(LIBDIR)
	@$(MAKE) -C $(LINUX_MLX_DIR)
	@$(CC) $(CFLAGS) $(OBJ) $(MAIN_SRC) -g -o $(NAME) $(LINUX_LFLAGS)
	@echo $(GREEN)"Done $@"$(END)
	@echo $(WHITE)"Start with \"lldb $(NAME)\""$(END)

bonus_debug: $(OBJ)
	@echo $(CYAN)"Creating debug files $@"
	@$(MAKE) all -C $(LIBDIR)
	@$(MAKE) -C $(LINUX_MLX_DIR)
	@$(CC) $(CFLAGS) $(OBJ) $(BNS_SRC) -g -o $(NAME) $(LFLLINUX_LFLAGSAGS)
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
ifeq ($(UNAME), Linux)
	@$(MAKE) -C $(LINUX_MLX_DIR) clean
endif
ifeq ($(UNAME), Darwin)
	@$(MAKE) -C $(MAC_MLX_DIR) clean
endif
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