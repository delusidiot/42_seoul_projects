C = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a
SRCPATH = src/
OBJPATH = obj/
HDRPATH = include/
FILES = ft_memset.c \
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
		ft_putnbr_fd.c
BNS_FILES = ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c
SRC = $(addprefix $(SRCPATH), $(FILES))
OBJ = $(addprefix $(OBJPATH), $(FILES:.c=.o))
BNS_SRC = $(addprefix $(SRCPATH), $(BNS_FILES))
BNS_OBJ = $(addprefix $(OBJPATH), $(BNS_FILES:.c=.o))
HEADERS = include

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

$(NAME): $(OBJ)
	@ar rcs $(NAME) $^

bonus: $(BNS_OBJ) $(OBJ)
	@ar rcs $(NAME) $^

all: $(NAME)

clean:
	@rm -f $(OBJ) $(BNS_OBJ)
	@rmdir $(OBJPATH)

fclean: clean
	@rm -f $(NAME)

re: fclean all

norm:
	@echo $(RED)
	@norminette $(SRC) $(HDRPATH)
	@echo $(END)

.PHONY: all clean fclean re test bonus norm
