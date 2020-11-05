#NAME = RTv1
SRC = src/main.c\
		src/ft_light.c\
		src/parser.c\
		src/ft_sphere.c\
		src/ft_trace.c\
		src/ft_count.c\
		src/ft_plane.c\
		src/ft_cam.c\
		src/ft_con.c\
		src/ft_cylinder.c\
		src/ft_normal.c\
		src/ft_valid.c
		



OBJ = $(SRC:.c=.o)
LIBS = libft/libft.a vec_op/veclib.a
HEADERS = -I ./includes -I ./libft -I ./vec_op
HDR = includes/rtv1.h
FLAGS = -Wall -Wextra
CGFLAGS =  -framework OpenGL -framework AppKit
INCLUDES	=	-I./frameworks/SDL2.framework/Versions/A/Headers \
				-I./frameworks/SDL2_ttf.framework/Versions/A/Headers \
				-I./frameworks/SDL2_image.framework/Versions/A/Headers \
				-I./frameworks/SDL2_mixer.framework/Headers \
				-F./frameworks/
FRAMEWORKS	=	-F./frameworks \
				-rpath ./frameworks \
				-framework OpenGL -framework AppKit -framework OpenCl \
				-framework SDL2 -framework SDL2_ttf -framework SDL2_image \
				-framework SDL2_mixer

all: $(NAME)

$(NAME): libft/libft.a vec_op/veclib.a $(OBJ) $(HDR)
	@gcc $(FLAGS) $(CGFLAGS) $(FRAMEWORKS) $(OBJ) $(LIBS) -o $(NAME)
	@printf "Compailing RTv1 done\n"

.c.o: $(HDR)
	@gcc $(FLAGS) $(INCLUDES) $(HEADERS) -c $< -o $@

clean:
	@make clean -C libft
	@make clean -C vec_op
	@rm -rf $(OBJ)
	@printf "All objects of RTv1 was deleted\n"

fclean:
	@make fclean -C libft
	@make fclean -C vec_op
	@rm -rf $(OBJ)
	@rm -rf $(NAME)
	@printf "All objects and binary of RTv1 was deleted\n"

libft/libft.a:
	@make -C libft

vec_op/veclib.a:
	@make -C vec_op 

re: fclean all