# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/07 18:40:56 by ilmira            #+#    #+#              #
#    Updated: 2020/11/25 19:28:56 by aeclipso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1
SRC_DIR = ./src/
SRCF = main.c\
		error.c\
		error2.c\
		ft_board.c\
		ft_con.c\
		ft_cylinder.c\
		ft_light.c\
		ft_normal.c\
		ft_plane.c\
		ft_rot.c\
		ft_sphere.c\
		ft_trace.c\
		parser.c\
		parse_cam.c\
		parse_cone.c\
		parse_cylinder.c\
		parse_light.c\
		parse_plane.c\
		parse_rules.c\
		parse_sphere.c

OBJ_DIR = ./obj/
SRC = $(addprefix $(SRC_DIR), $(SRCF))
OBJ = $(addprefix $(OBJ_DIR), $(OBJF))
OBJF = $(SRCF:.c=.o)
LIBS = libft/libft.a veclib/veclib.a
HEADERS = -I ./includes -I ./libft -I ./veclib
HDR = includes/rtv1.h
FLAGS = -Wall -Wextra #-Werror -g
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

all: obj $(NAME)

obj:
	mkdir -p $(OBJ_DIR)

$(NAME): libft/libft.a veclib/veclib.a $(OBJ) $(HDR)
	gcc $(FLAGS) $(CGFLAGS) $(FRAMEWORKS) $(OBJ) $(LIBS) -o $(NAME)
	@printf "Compailing RTv1 done\n"

$(OBJ_DIR)%.o:$(SRC_DIR)%.c $(HDR)
	gcc $(FLAGS) $(INCLUDES) $(HEADERS) -c $< -o $@

clean:
	@make clean -C libft
	@make clean -C veclib
	@rm -Rf $(OBJ)
	@rm -Rf obj

fclean: clean
	@make fclean -C libft
	@make fclean -C veclib
	@rm -rf $(NAME)
	@printf "All objects and binary of RTv1 was deleted\n"

libft/libft.a:
	@make -C libft

veclib/veclib.a:
	@make -C veclib

re: fclean all