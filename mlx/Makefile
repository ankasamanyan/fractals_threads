#
#

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "\033[92m•\033[0m\c"
# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11

all: $(NOM)

$(NOM):	$(OBJ)
	@ar rsc $(NOM) $(OBJ)
	@ranlib $(NOM)
# 	@echo "\033[92m\nMLX successfully compiled!\033[0m"

clean:
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app
	@echo "\033[0;31mMLX successfully cleaned!\033[0m"

re: clean all
