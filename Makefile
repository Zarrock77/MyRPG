##
## EPITECH PROJECT, 2023
## MAKEFILE
## File description:
## MAKEFILE
##

SRC	=	src/engine/button/creator.c 	\
		src/engine/button/registrar.c 	\
		src/engine/button/render.c 		\
		src/engine/button/event.c 		\
		src/engine/button/modifier.c 	\
		src/engine/button/destroyer.c 	\
		\
		src/engine/image/creator.c 		\
		src/engine/image/destroyer.c 	\
		\
		src/pokedex/creator.c 			\
		src/pokedex/render.c 			\
		src/pokedex/destroyer.c 		\
		src/pokedex/get_first_frame.c 	\
		src/pokedex/handle_events.c 	\
		\
		src/team/creator.c 				\
		src/team/destroyer.c 			\
		\
		src/maths/compute_catch_rate.c 	\
		src/maths/compute_damage.c 		\
		src/maths/compute_gotten_xp.c 	\
		\
		src/intro/creator.c				\
		src/intro/render.c 				\
		src/intro/destroyer.c 			\
		\
		src/start/creator.c 			\
		src/start/render.c 				\
		src/start/destroyer.c 			\
		\
		src/menu/creator.c 				\
		src/menu/render.c 				\
		src/menu/destroyer.c 			\
		\
		src/pause/creator.c 			\
		src/pause/event.c 				\
		src/pause/render.c 				\
		src/pause/destroyer.c 			\
		\
		src/options/creator.c			\
		src/options/render.c 			\
		\
		src/fullscreen_loader/create_loader.c 	\
		src/fullscreen_loader/update_loader.c 	\
		src/fullscreen_loader/destroy_loader.c 	\
		\
		src/map/creator.c 				\
		src/map/render.c 				\
		src/map/destroyer.c 			\
		src/map/open_and_read.c 		\
		\
		src/lib/my_str_to_word_array.c 	\
		src/lib/my_strchr.c 			\
		src/lib/my_strdup.c 			\
		src/lib/my_strlen.c 			\
		src/lib/my_strpbrk.c 			\
		src/lib/my_strspn.c 			\
		src/lib/my_strtok.c 			\
		src/lib/my_strcpy.c 			\
		src/lib/my_itoa.c				\
		\
		src/player/creator.c 		\
		src/player/render.c 		\
		src/player/destroyer.c 		\
		src/player/move.c 			\
		src/player/clock_move.c 	\
		src/player/collision.c		\
		src/player/random.c			\
		\
		src/scene/creator.c 			\
		src/scene/render.c 				\
		src/scene/enemy.c 				\
		src/scene/trainer.c 			\
		src/scene/setup_scene.c 		\
		src/scene/event.c 				\
		src/scene/pokemon.c 			\
		src/scene/destroyer.c 			\
		\
		src/game/creator.c \
		src/game/render.c \
		src/game/event.c \
		src/game/destroyer.c \
		\
		src/dialog/creator.c \
		src/dialog/render.c \
		src/dialog/event.c \
		src/dialog/destroyer.c \
		\
		src/inventory/creator.c \
		src/inventory/render.c \
		src/inventory/event.c \
		src/inventory/destroyer.c \
		\
		src/item/creator.c \
		src/item/render.c \
		src/item/destroyer.c \
		\
		src/event/play.c \
		src/event/options.c \
		src/event/quit.c \
		src/event/resize_view.c \
		\
		src/main.c

SRC_TESTS	=

OBJ = $(SRC:.c=.o)

NAME = my_rpg

all	: $(NAME)

debug: CFLAGS += -g3

debug: clean $(NAME)

valgrind: debug
	valgrind ./$(NAME)

CPPFLAGS += -I includes/

CFLAGS += -Wextra -pedantic

CSFMLFLAGS = -lcsfml-window -lcsfml-graphics -lcsfml-system

$(NAME)	:	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDLIBS) $(CSFMLFLAGS)

clean:
	rm -f $(OBJ)

fclean :	clean
	rm -f $(NAME)

unit_test: $(SRC_TESTS)
	gcc -o unit_test $(OBJ) -I./includes $(SRC_TESTS) --coverage -lcriterion

tests_run: unit_test
	./unit_test

re: fclean all

.PHONY: all clean fclean re
