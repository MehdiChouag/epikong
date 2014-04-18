##
## Makefile for  in /home/brunne_r/Public/sdl_test
## 
## Made by Romain Brunner
## Login   <brunne_r@epitech.net>
## 
## Started on  Fri 07/03/2014 00:00
##

SRCS	=	src/test.c \
		src/map.c \
		src/checkmap.c \
		src/transform.c \
		src/init.c \
		src/aff.c \
		src/gravity.c \
		src/move.c \
		src/refresh.c \
		src/kup.c \
		src/monster.c \
		src/menu.c \
		src/menu2.c \

CFLAGS	=	-W -Wall -Werror `sdl-config --cflags` -I ./header

OBJS	=	$(SRCS:.c=.o)

NAME	=	epikong

all:	$(NAME)

$(NAME):	$(OBJS)
	gcc `sdl-config --libs` -o $(NAME) $(OBJS) -lSDL -lSDL_image -lSDL_gfx -lSDL_ttf
clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all

debug : re
	./$(NAME)
