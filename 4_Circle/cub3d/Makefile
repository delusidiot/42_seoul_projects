# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/12 09:31:42 by jjeon             #+#    #+#              #
#    Updated: 2022/04/28 18:37:20 by jjeon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3d

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

# ================================== LIBFT =================================== #

MLX_DIR		=	$(LIB_DIR)/minilibx_opengl
MLX_FLAGS	=	-lmlx
ifeq ($(UNAME), Linux)
	MLX_FLAGS	+=	-L/usr/include/ -lXext -lX11 -lm -lbsd
else
	MLX_FLAGS	+=	-framework OpenGL -framework AppKit
endif

# =============================== Compile Flags ============================== #

LFLAGS		=	-L $(LIBFT_DIR) -lft
LFLAGS		+=	$(MLX_FLAGS)
IFLAGS		=	-I $(INC_DIR) -I $(LIBFT_DIR)/$(INC_DIR) -I $(MLX_DIR)

# **************************************************************************** #
#                                Mandatory Files                               #
# **************************************************************************** #

FILES		=	main.c

# =============================== Path Setting =============================== #
SRCS		=	$(addprefix $(SRC_DIR)/, $(FILES))
OBJS		=	$(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))


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
			@$(CC) -c $(CFLAGS) $< -o $@ $(IFLAGS)

$(NAME)		:	$(OBJS) libft mlx
			@echo $(CYAN)"Compiling $@"$(END)
			@$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(LFLAGS) $(IFLAGS)
			@echo $(GREEN)"Done $@"$(END)

debug		:	$(OBJS) libft mlx
			@echo $(CYAN)"Creating debug files $@"$(END)
			@$(CC) $(OBJS) -g -o $(NAME) $(CFLAGS) $(LFLAGS) $(IFLAGS)
			@echo $(GREEN)"Done $@"$(END)
			@echo $(WHITE)"Start with \"lldb $(NAME)\""$(END)

all			:	$(NAME)

clean		:	libft_clean mlx_clean
			@echo $(RED)"$(NAME) clean"$(END)
			@$(RM) -f $(OBJS) $(OBJS_BNS)
			@$(RM) $(RMFLAGS) $(OBJ_DIR) $(OBJ_DIR_BNS)

fclean		:	libft_fclean mlx_clean
			@echo $(RED)"$(NAME) fclean"$(END)
			@$(RM) -f $(OBJS) $(OBJS_BNS)
			@$(RM) $(RMFLAGS) $(OBJ_DIR) $(OBJ_DIR_BNS) $(NAME)

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

# ==================================== MLX =================================== #

mlx			:
			@$(MAKE) all -C $(MLX_DIR)
mlx_re		:
			@$(MAKE) -C $(MLX_DIR) re
mlx_clean	:
			@$(MAKE) -C $(MLX_DIR) clean

# =================================== PHONY ================================== #

.PHONY		:	all clean fclean re bonus bonus_re\
				norm debug \
				libft libft_re libft_clean libft_fclean\
				mlx mlx_re mlx_clean
