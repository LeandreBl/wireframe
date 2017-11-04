##
## EPITECH PROJECT, 2017
## 
## File description:
## makefile
##

NAME		= wireframe

CC		= gcc

MAKE		= make -C

LIB		= -L./lib/C -lmy
LIB		+= -lmy_csfml
LIB		+= -lc_graph_prog_full
LIB		+= -lm

SRCS		= src/main.c
SRCS		+= src/file_parser.c
SRCS		+= src/projections.c
SRCS		+= src/build_wires.c
SRCS		+= src/display.c
SRCS		+= src/free.c
SRCS		+= src/arrows.c
SRCS		+= src/shortcuts.c
SRCS		+= src/page.c
SRCS		+= src/change_proj.c
SRCS		+= src/init_frame.c
SRCS		+= src/menu.c
SRCS		+= src/menu_draw_line.c
SRCS		+= src/menu_preview.c

OBJ		= $(SRCS:.c=.o)

RM		= rm -f

CFLAGS		= -W -Werror -Wall -Wextra
CFLAGS		+= -I ./include
CFLAGS		+= -g3 -O3

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) lib/C
	$(MAKE) lib/C/CSFML
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LIB)
	@       tput setaf 2; cat include/signature; tput sgr0

clean:
	$(MAKE) lib/C clean
	$(MAKE) lib/C/CSFML clean
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) lib/C fclean
	$(MAKE) lib/C/CSFML fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
