# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Debug                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achantra <achantra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 15:30:48 by achantra          #+#    #+#              #
#    Updated: 2025/02/02 13:27:23 by achantra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a
MINILIBXTAR = minilibx-linux.tgz
MINILIBXDIR = minilibx-linux
MINILIBX = $(MINILIBXDIR)/libmlx_Linux.a

SRC_PATH = srcs/
BONUS_PATH = bonus/

SRC = main.c \
	debug.c \
	clean/clean_env.c \
	clean/clean_element.c \
	parsing/parsing.c \
	parsing/init_env.c \
	parsing/init_utils.c \
	parsing/print_error.c \
	parsing/parse_color.c \
	parsing/parse_number.c \
	parsing/parse_coordinates.c \
	parsing/init_elements.c \
	parsing/init_ambient.c \
	parsing/init_light.c \
	parsing/init_camera.c \
	parsing/init_forms.c \
	image/manage_window.c \
	image/manage_image.c \
	image/generate_image.c \
	image/cam_ray_tracing.c \
	math/vector_operator.c \
	math/vector_operator2.c \
	math/double_operator.c \
	color/color.c \
	intersection/sphere_intersection.c \

#BONUS = 

SRCS = $(addprefix $(SRC_PATH), $(SRC))
#BONUS_SRCS = $(addprefix $(BONUS_PATH), $(BONUS))

OBJ = $(SRCS:.c=.o)
#OBJ_BONUS = $(BONUS_SRCS:.c=.o)

CC = cc
CFLAGS = -g3 -Wall -Wextra -Werror -I $(LIBFTDIR) -I includes -I $(MINILIBXDIR)

.PHONY: all clean fclean re libft

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MINILIBX) -lm -lX11 -lXext

$(LIBFT):
	make -C $(LIBFTDIR)

$(MINILIBX) :
	tar -xzvf $(MINILIBXTAR)
	make -C $(MINILIBXDIR)

#bonus: $(LIBFT) $(MINILIBX) $(OBJ) $(OBJ_BONUS)
#	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(OBJ_BONUS) $(LIBFT) $(MINILIBX) -lm -lX11 -lXext

clean:
	rm -f $(OBJ)
# rm -f $(OBJ_BONUS)
	make clean -C $(LIBFTDIR)
	@if [ -d $(MINILIBXDIR) ]; then make clean -C $(MINILIBXDIR); fi

fclean: clean
	rm -f $(NAME)
	rm -rf $(MINILIBXDIR)
	make fclean -C $(LIBFTDIR)

re: fclean all