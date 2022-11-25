#
#

NOM		=	libmlx.a

SRC		=	mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m	\
			mlx_xpm.c mlx_int_str_to_wordtab.c								\

SRC		+=	mlx_png.c mlx_mouse.m

OBJ1	=	$(SRC:.c=.o)

OBJ		=	$(OBJ1:.m=.o)

CFLAGS	+=	-O2 -Wno-deprecated-declarations

GREY	=	\033[90m

WHITE	=	\033[0m

# add to match string put with X11 in size and position
CFLAGS	+=	-DSTRINGPUTX11

all		:	$(NOM)

$(NOM)	:	$(OBJ)
			@(ar -cr $(NOM) $(OBJ))
			@(ranlib $(NOM))
			@(echo "$(GREY)$@ archive created$(WHITE)")

%.o		:	%.c
			@($(CC) $(CFLAGS) -c $< -o $@)
			@(echo "$(GREY)$@ comiled$(WHITE)")

%.o		:	%.m
			@($(CC) $(CFLAGS) -c $< -o $@)
			@(echo "$(GREY)$@ comiled$(WHITE)")

clean	:
			@(rm -f $(NOM) $(OBJ) *~)
			@(rm -f mlx_app)
			@(echo "$(GREY)minilibx cleaned$(WHITE)")

re		:	clean all

.PHONY	:	all clean re
