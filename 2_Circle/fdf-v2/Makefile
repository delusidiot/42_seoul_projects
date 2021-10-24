# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/23 05:05:46 by jjeon             #+#    #+#              #
#    Updated: 2021/10/24 09:19:52 by jjeon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME = fdf

# Folders
LIBDIR = libft/
LINUX_MLX_DIR = minilibx_linux/
MAC_MLX_DIR = minilibx_macos/
SRCPATH = src/
OBJPATH = obj/
HDRPATH = include/
LINUX_KEY = key_setting/linux
MAC_KEY = key_setting/macos

# Compiling flags
LINUX_LFLAGS =	-L $(LIBDIR) -lft -L$(LINUX_MLX_DIR)\
		 		-lmlx -L/usr/include/../lib -lXext -lX11 -lm -lbsd
			   
MAC_LFLAGS =	-L $(LIBDIR) -lft -L$(MAC_MLX_DIR)\
				-lmlx -framework OpenGL -framework AppKit
			  
IFLAGS = -I $(HDRPATH) -I $(LIBDIR)include
CFLAGS = -Wall -Wextra -Werror $(IFLAGS)
LIBRARIES += $(LIBDIR)libft.a

# Source files paths
FILES =	map/map_reader.c \
		map/map_create.c \
		map/map_check.c \
		map/utils.c \
		error/error.c \
		window/create_window.c \
		window/camera.c \
		window/utils.c \
		window/key_handler.c\
		window/key_release_handler.c\
		window/mouse_handler.c\
		draw/draw.c\
		draw/bresenham.c\
		draw/print_status.c\
		draw/color.c\
		draw/utils.c
	
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
	@$(CC) -c $(CFLAGS) -I$(LINUX_KEY) -I $(LINUX_MLX_DIR) $< -o $@
endif
ifeq ($(UNAME), Darwin)
	@$(CC) -c $(CFLAGS) -I$(MAC_KEY) -I $(MAC_MLX_DIR) $< -o $@
endif

$(NAME): $(OBJ) $(MAIN_OBJ)
	@echo $(CYAN)"$(UNAME) Compiling $@"
ifeq ($(UNAME), Linux)
	@$(MAKE) all -C $(LIBDIR)
	@$(MAKE) -C $(LINUX_MLX_DIR)
	@$(CC) $(CFLAGS) -I$(LINUX_KEY) $(OBJ) $(MAIN_OBJ) -o $(NAME) $(LINUX_LFLAGS) -I $(LINUX_MLX_DIR)
endif
ifeq ($(UNAME), Darwin)
	@$(MAKE) all -C $(LIBDIR)
	@$(MAKE) -C $(MAC_MLX_DIR)
	@$(CC) $(CFLAGS) -I$(MAC_KEY) $(OBJ) $(MAIN_OBJ) -o $(NAME) $(MAC_LFLAGS) -I $(MAC_MLX_DIR)
endif
	@echo $(GREEN)"$(UNAME) Done $@"$(END)

debug: $(OBJ) $(MAIN_OBJ)
	@echo $(CYAN)"Creating debug files $@"
ifeq ($(UNAME), Linux)
	@$(MAKE) all -C $(LIBDIR)
	@$(MAKE) -C $(LINUX_MLX_DIR)
	@$(CC) $(CFLAGS) -I$(LINUX_KEY) $(OBJ) $(MAIN_OBJ) -g -o $(NAME) $(LINUX_LFLAGS) -I $(LINUX_MLX_DIR)
endif
ifeq ($(UNAME), Darwin)
	@$(MAKE) all -C $(LIBDIR)
	@$(MAKE) -C $(MAC_MLX_DIR)
	@$(CC) $(CFLAGS) -I$(MAC_KEY) $(OBJ) $(MAIN_OBJ) -g -o $(NAME) $(MAC_LFLAGS) -I $(MAC_MLX_DIR)
endif
	@echo $(GREEN)"$(UNAME) Done $@"$(END)
	@echo $(WHITE)"Start with \"lldb $(NAME)\""$(END)

leak_check:	debug
	@echo $(CYAN) "valgrind start"
	valgrind --leak-check=full --log-file=memcheck.txt -v --error-limit=no ./fdf ./test_maps/42.fdf
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
ifeq ($(UNAME), Darwin)
	@$(MAKE) norm -C libft
	@echo $(RED)
	@norminette $(SRC) $(HDRPATH)
	@echo $(END)
endif

.PHONY: all clean fclean re norm debug leak_check
