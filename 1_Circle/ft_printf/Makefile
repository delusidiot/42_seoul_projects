CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = libftprintf.a
LIBNAME = libft.a

SOURCE = srcs/ft_printf.c\
		 srcs/ft_parameter.c\
		 srcs/ft_flags.c\
		 srcs/ft_specifier.c\
		 srcs/ft_character.c\
		 srcs/ft_integer.c\
		 srcs/ft_signed_itoa.c\
		 srcs/ft_utils.c\
		 srcs/ft_unicode.c\
		 srcs/ft_floating_convert.c\
		 srcs/ft_floating_decimal.c\
		 srcs/ft_floating_integer.c\
		 srcs/ft_floating_type.c\
		 srcs/ft_floating_gsp.c\
		 srcs/ft_floating_esp.c\
		 srcs/ft_floating_round.c\
		 srcs/ft_floating_to_str.c\
		 srcs/ft_add_sign.c\
		 srcs/ft_is_type.c\
		 srcs/ft_put_str.c\
		 srcs/ft_put_left_right.c
BONUS_SOURCE =	bonus/ft_printf_bonus.c\
				bonus/ft_parameter_bonus.c\
				bonus/ft_flags_bonus.c\
				bonus/ft_specifier_bonus.c\
				bonus/ft_character_bonus.c\
				bonus/ft_integer_bonus.c\
				bonus/ft_signed_itoa_bonus.c\
				bonus/ft_utils_bonus.c\
				bonus/ft_unicode_bonus.c\
				bonus/ft_floating_convert_bonus.c\
				bonus/ft_floating_decimal_bonus.c\
				bonus/ft_floating_integer_bonus.c\
				bonus/ft_floating_type_bonus.c\
				bonus/ft_floating_gsp_bonus.c\
				bonus/ft_floating_esp_bonus.c\
		 		bonus/ft_floating_round_bonus.c\
				bonus/ft_floating_to_str_bonus.c\
				bonus/ft_add_sign_bonus.c\
				bonus/ft_is_type_bonus.c\
				bonus/ft_put_str_bonus.c\
				bonus/ft_put_left_right_bonus.c
LIBDIR = libft
HEADERS = includes
OBJECTS = $(SOURCE:.c=.o)
BONUS_OBJECTS = $(BONUS_SOURCE:.c=.o)

%o: %c
	$(CC) -c $(CFLAGS) $< -o $(<:.c=.o) -I$(HEADERS) -I$(LIBDIR)

$(NAME): $(OBJECTS)
	$(MAKE) all -C ./libft
	cp libft/libft.a ./$(NAME)
	ar rcs $(NAME) $(OBJECTS)

bonus: $(BONUS_OBJECTS)
ifeq (,$(wildcard $(NAME)))
	$(MAKE) all -C ./libft
	cp libft/libft.a ./$(NAME)
	ar rcs $(NAME) $(BONUS_OBJECTS)
endif

all: $(NAME)

clean:
	$(MAKE) -C libft clean
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	$(RM) $(NAME) $(LIBDIR)/$(LIBNAME)

re: fclean all

.PHONY: all clean fclean re bonus
