CC = gcc
SRCPATH = src/
OBJPATH = obj/
HDRPATH = include/
LIB_PATH = libft/
GNL_PATH = get_next_line/
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a
LIB_FILES = ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strlen.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strnstr.c \
			ft_strncmp.c \
			ft_atoi.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c
GNL_FILES = get_next_line.c \
			get_next_line_utils.c
LIB_SRC_PATH = $(addprefix $(LIB_PATH), $(LIB_FILES))
GNL_SRC_PATH = $(addprefix $(GNL_PATH), $(GNL_FILES))
LIB_SRC = $(addprefix $(SRCPATH), $(LIB_SRC_PATH))
LIB_OBJ = $(addprefix $(OBJPATH), $(LIB_SRC_PATH:.c=.o))
GNL_SRC = $(addprefix $(SRCPATH), $(GNL_SRC_PATH))
GNL_OBJ = $(addprefix $(OBJPATH), $(GNL_SRC_PATH:.c=.o))

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
	@$(CC) -c $(CFLAGS) $< -o $@ -I $(HDRPATH)

$(NAME): $(LIB_OBJ) $(GNL_OBJ)
	@echo $(CYAN)"Compiling $@"
	@ar rcs $(NAME) $^
	@echo $(GREEN)"Done $@"$(END)

all: $(NAME)

clean:
	@echo $(RED)"$(NAME) clean"$(END)
	@rm -f $(LIB_OBJ) $(GNL_OBJ)
	@rm -rf $(OBJPATH)

fclean:
	@echo $(RED)"$(NAME) fclean"$(END)
	@rm -f $(LIB_OBJ) $(GNL_OBJ)
	@rm -rf $(OBJPATH)
	@rm -f $(NAME)

re: fclean all

norm:
	@echo $(RED)
	@norminette $(SRCPATH) $(HDRPATH)
	@echo $(END)

.PHONY: all clean fclean re norm
