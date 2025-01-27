##
## EPITECH PROJECT, 2024
## B-CPE-110-STG-1-1-settingup-adrien.raphanaud
## File description:
## Makefile
##

.SILENT:

SRC =	my_putchar.c	\
	len_array.c \
	my_put_nbr.c	\
	my_getnbr.c	\
	my_putchar_ch.c	\
	my_put_nbr_ch.c \
	my_putstr.c	\
	my_strcmp.c	\
	my_strlen.c	\
	my_str_to_word_array.c \
	my_strncpy.c


OBJ = $(SRC:.c=.o)

NAME =	libmy.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

## Useless, but I don't care
notemp: all clean
