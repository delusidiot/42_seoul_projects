C = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a
SOURCE = ./ft_memset.c \
		 ./ft_bzero.c \
		 ./ft_memcpy.c \
		 ./ft_memccpy.c \
		 ./ft_memmove.c \
		 ./ft_memchr.c \
		 ./ft_memcmp.c \
		 ./ft_strlen.c \
		 ./ft_strlcpy.c \
		 ./ft_strlcat.c \
		 ./ft_strchr.c \
		 ./ft_strrchr.c \
		 ./ft_strnstr.c \
		 ./ft_strncmp.c \
		 ./ft_atoi.c \
		 ./ft_isalpha.c \
		 ./ft_isdigit.c \
		 ./ft_isalnum.c \
		 ./ft_isascii.c \
		 ./ft_isprint.c \
		 ./ft_toupper.c \
		 ./ft_tolower.c \
		 ./ft_calloc.c \
		 ./ft_strdup.c \
		 ./ft_substr.c \
		 ./ft_strjoin.c \
		 ./ft_strtrim.c \
		 ./ft_split.c \
		 ./ft_itoa.c \
		 ./ft_strmapi.c \
		 ./ft_putchar_fd.c \
		 ./ft_putstr_fd.c \
		 ./ft_putendl_fd.c \
		 ./ft_putnbr_fd.c
BONUS_SRC = ./ft_lstnew.c \
			./ft_lstadd_front.c \
			./ft_lstsize.c \
			./ft_lstlast.c \
			./ft_lstadd_back.c \
			./ft_lstdelone.c \
			./ft_lstclear.c \
			./ft_lstiter.c \
			./ft_lstmap.c
BONUS_OBJ = $(BONUS_SRC:.c=.o)
HEADERS = libft.h
OBJECTS = $(SOURCE:.c=.o)

%o: %c
	$(CC) -c $(CFLAGS) $< -o $(<:.c=.o) -I $(HEADERS)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $^
	ranlib $(NAME)

bonus: $(BONUS_OBJ) $(OBJECTS)
	ar rc $(NAME) $^
	ranlib $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJECTS) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test bonus
