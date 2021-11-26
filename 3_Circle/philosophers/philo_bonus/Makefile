# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/26 07:18:50 by jjeon             #+#    #+#              #
#    Updated: 2021/11/26 14:22:30 by jjeon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo_bonus
LIBDIR		=	libft
SRCPATH		=	src/
OBJPATH		=	obj/
HDRPATH 	=	include/
LIBRARIES	=	$(LIBDIR)/libft.a

LFLAGS		=	-L $(LIBDIR) -lft -lpthread
IFLAGS		=	-I $(HDRPATH) -I $(LIBDIR)/include
CFLAGS		=	-Wall -Wextra -Werror $(IFLAGS)

FILES		=	init.c\
				main.c\
				philo.c\
				print.c\
				state.c\
				terminate.c\
				time.c\
				utils.c

# ============ Paths Setting ============
SRC			=	$(addprefix $(SRCPATH), $(FILES))
OBJ			=	$(addprefix $(OBJPATH), $(FILES:.c=.o))
# =======================================

# ========== Colors ==========
END			=	"\033[0;0m"
RED			=	"\033[1;31m"
GREEN		=	"\033[1;32m"
YELLOW		=	"\033[1;33m"
BLUE		=	"\033[1;34m"
PURPLE		=	"\033[1;35m"
CYAN		=	"\033[1;36m"
WHITE		=	"\033[1;37m"
# ============================

$(OBJPATH)%.o:	$(SRCPATH)%.c
			@mkdir -p $(@D)
			@$(CC) -c $(CFLAGS) $< -o $@

$(NAME)		:	$(OBJ)
			@echo $(CYAN)"Compiling $@"
			@$(MAKE) all -C $(LIBDIR)
			@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LFLAGS)
			@echo $(GREEN)"Done $@"$(END)

debug		:	$(OBJ)
			@echo $(CYAN)"Creating debug files $@"
			@$(MAKE) all -C $(LIBDIR)
			@$(CC) $(CFLAGS) $(OBJ) -g -o $(NAME) $(LFLAGS)
			@echo $(GREEN)"$(UNAME) Done $@"$(END)
			@echo $(WHITE)"Start with \"lldb $(NAME)\""$(END)

all			:	$(NAME)

clean		:
			@echo $(RED)"$(NAME) clean"$(END)
			@$(MAKE) -C $(LIBDIR) clean
			@rm -f $(OBJ)
			@rm -rf $(OBJPATH)

leak_check	:	debug
			@echo $(CYAN) "valgrind start"
			valgrind --leak-check=full --log-file=philo_memcheck.txt -v --error-limit=no ./philo
			@echo $(END)

fclean		:	clean
			@rm -f $(NAME) $(LIBRARIES)

re			:	fclean all

norm		:
			@$(MAKE) norm -C $(LIBDIR)
			@echo $(RED)
			@norminette $(SRC) $(HDRPATH)
			@echo $(END)

.PHONY		:	all clean fclean re norm debug leak_check
