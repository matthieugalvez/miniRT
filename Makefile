# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achantra <achantra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 15:30:48 by achantra          #+#    #+#              #
#    Updated: 2025/02/10 18:22:06 by mgalvez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= miniRT

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
LIBS	= -lm -lX11 -lXext

SRCS_DIR	= srcs
INCS_DIR	= includes
LIBFT_DIR	= libft

MINILIBX_TAR	= minilibx-linux.tgz
MINILIBX_DIR	= minilibx-linux
MINILIBX		= $(MINILIBX_DIR)/libmlx_Linux.a

CLEAN_SRCS	= clean_element.c clean_env.c
IMAGE_SRCS	= cam_ray_tracing.c color.c generate_image.c manage_image.c manage_window.c
INIT_SRCS	= init_ambient.c init_camera.c init_elements.c init_env.c init_forms.c \
			  init_light.c init_utils.c
INTRSC_SRCS	= intersection.c
MATH_SRCS	= double_operator.c vector_operator.c vector_operator2.c
PARSE_SRCS	= parse_color.c parse_coordinates.c parse_number.c parsing.c print_error.c

SRCS_LST	= $(addprefix clean/, ${CLEAN_SRCS}) \
			  $(addprefix image/, ${IMAGE_SRCS}) \
			  $(addprefix init/, ${INIT_SRCS}) \
			  $(addprefix intersection/, ${INTRSC_SRCS}) \
			  $(addprefix math/, ${MATH_SRCS}) \
			  $(addprefix parsing/, ${PARSE_SRCS}) \
			  main.c \
			  debug.c

SRCS	= $(addprefix ${SRCS_DIR}/, ${SRCS_LST})
LIBFT	= $(addprefix ${LIBFT_DIR}/, libft.a)
OBJS	= $(SRCS:.c=.o)

#BONUS = 
#BONUS_SRCS = $(addprefix $(BONUS_PATH), $(BONUS))
#OBJ_BONUS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(MINILIBX) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(LIBS) $(OBJS) $(MINILIBX) $(LIBFT) -o $@

fsanitize: $(MINILIBX) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(LIBS) $(OBJS) $(MINILIBX) $(LIBFT) -o $@ -fsanitize=leak

g3: $(MINILIBX) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(LIBS) $(OBJS) $(MINILIBX) $(LIBFT) -o $@ -g3

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MINILIBX) :
	tar -xzvf $(MINILIBX_TAR)
	make -C $(MINILIBX_DIR)

#bonus: $(LIBFT) $(MINILIBX) $(OBJ) $(OBJ_BONUS)
#	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(OBJ_BONUS) $(LIBFT) $(MINILIBX) -lm -lX11 -lXext

clean:
	rm -f $(OBJS)
# rm -f $(OBJ_BONUS)
	make clean -C $(LIBFT_DIR)
#	if [ -d $(MINILIBXDIR) ]; then make clean -C $(MINILIBXDIR); fi

fclean: clean
	rm -f $(NAME) fsanitize g3
	rm -rf $(MINILIBX_DIR)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re fsanitize g3
