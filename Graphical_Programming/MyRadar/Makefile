##
## EPITECH PROJECT, 2024
## B-CPE-110-STG-1-1-settingup-adrien.raphanaud
## File description:
## Makefile
##

SRC =	my_radar.c \
		src/create_shapes.c \
		src/create_texture.c \
		src/check_collisions.c \
		src/read_file.c \
		src/handlers/display.c \
		src/handlers/update_pos_and_coll.c \
		src/handlers/events.c \
		src/handlers/timers.c \
		src/handlers/updates.c \
		src/print_h_flag.c \
		src/destroy_sprites.c \
		src/init_and_close_lists.c \
		src/kill_dead_planes.c

OBJ = $(SRC:.c=.o)

NAME =	my_radar

CFLAGS =  -I./include -O3

LIBRARIES = -lm -lcsfml-graphics -lcsfml-window -lcsfml-system

all: $(NAME)

$(NAME): $(OBJ)
	make -C lib/
	gcc -o $(NAME) $(OBJ) -L./lib -lmy $(LIBRARIES) $(CFLAGS)

debug: CFLAGS += -g -Wextra -Wall
debug: re

clean:
	make -C lib/ clean
	rm -f $(OBJ)

fclean: clean
	make -C lib/ fclean
	rm -f $(NAME)

re: fclean all

## Useless, but I don't care
notemp: all clean
