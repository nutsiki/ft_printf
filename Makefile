CC = gcc
FLAGS = -Werror -Wall -Wextra

NAME = libftprintf.a

SRC = ft_printf.c\
        sources/buffer.c\
        sources/check_hls.c\
        sources/check_type.c\
        sources/convert_add.c\
        sources/convert_oux.c\
        sources/fill_add.c\
        sources/fill_char.c\
        sources/fill_const_str.c\
        sources/fill_int.c\
        sources/fill_oct.c\
        sources/fill_pc.c\
        sources/fill_str.c\
        sources/fill_unsigned.c\
        sources/make_code.c\
        sources/utils.c\
        sources/utils_2.c\
        sources/bonus_n.c\
        sources/bonus_wchar.c\
        sources/bonus_wstring.c\


BONUS = sources/bonus_n.c\
        sources/bonus_wchar.c\
        sources/bonus_wstring.c\



OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) includes/ft_printf.h
	ar rc $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CCFLAGS) -c -g -v -o $@ $<

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: all $(BONUS_OBJ)

.PHONY : all clean fclean re bonus
