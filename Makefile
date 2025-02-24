# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achantra <achantra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 15:30:48 by achantra          #+#    #+#              #
#    Updated: 2025/02/24 17:30:03 by mgalvez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= miniRT

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
LIBS	= -lm -lX11 -lXext

SRCS_DIR	= srcs
INCS_DIR	= includes
LIBFT_DIR	= libft
MLX_DIR		= mlx_linux
OBJS_DIR	= .objs

CLEAN_SRCS	= clean_element.c clean_env.c
IMAGE_SRCS	= cam_ray_tracing.c image_utils.c
INIT_SRCS	= init_ambient.c init_camera.c init_elements.c init_env.c init_figures.c \
			  init_light.c init_utils.c
LIGHT_SRCS	= light.c light_utils.c
INTRSC_SRCS	= intersection.c intsec_cylinder.c
MATH_SRCS	= double_operator.c vector_operator.c vector_operator2.c normal_operator.c
MLX_SRCS	= key_funcs.c figures_key_funcs.c manage_window.c
PARSE_SRCS	= parse_color.c parse_coordinates.c parse_number.c parsing.c

SRCS_LST	= ${addprefix clean/, ${CLEAN_SRCS}} \
			  ${addprefix image/, ${IMAGE_SRCS}} \
			  ${addprefix init/, ${INIT_SRCS}} \
			  ${addprefix light/, ${LIGHT_SRCS}} \
			  ${addprefix intersection/, ${INTRSC_SRCS}} \
			  ${addprefix math/, ${MATH_SRCS}} \
			  ${addprefix mlx/, ${MLX_SRCS}} \
			  ${addprefix parsing/, ${PARSE_SRCS}} \
			  main.c debug.c
OBJS_LST	= ${SRCS_LST:.c=.o}

SRCS	= ${addprefix ${SRCS_DIR}/, ${SRCS_LST}}
OBJS	= ${addprefix ${OBJS_DIR}/, ${OBJS_LST}}
LIBFT	= ${LIBFT_DIR}/libft.a
MLX		= ${MLX_DIR}/libmlx_Linux.a

INCS_PARAM = -I ${INCS_DIR} -I ${LIBFT_DIR} -I ${MLX_DIR}

#BONUS = 
#BONUS_SRCS = ${addprefix ${BONUS_PATH}, ${BONUS}}
#BONUS_OBJS = ${BONUS_SRCS:.c=.o}

ERASE		= \033[2K\r
BLUE		= \033[34m
YELLOW		= \033[33m
GREEN		= \033[32m
END			= \033[0m

all: ${NAME}

${NAME}: libft ${OBJS}
	@ ${CC} ${CFLAGS} ${LIBS} ${INCS_PARAM} ${OBJS} ${LIBFT} ${MLX} -o $@
	@ printf "${ERASE}${GREEN}$@ made\n${END}"

fsanitize: libft ${OBJS}
	@ ${CC} ${CFLAGS} ${LIBS} ${INCS_PARAM} ${OBJS} ${LIBFT} ${MLX} -o $@ -fsanitize=address
	@ printf "${ERASE}${GREEN}$@ made\n${END}"

g3: libft ${OBJS}
	@ ${CC} ${CFLAGS} ${LIBS} ${INCS_PARAM} ${OBJS} ${LIBFT} ${MLX} -o $@ -g3
	@ printf "${ERASE}${GREEN}$@ made\n${END}"

libft:
	@ make -C ${LIBFT_DIR}

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	@ mkdir -p ${OBJS_DIR}
	@ mkdir -p ${OBJS_DIR}/clean
	@ mkdir -p ${OBJS_DIR}/image
	@ mkdir -p ${OBJS_DIR}/init
	@ mkdir -p ${OBJS_DIR}/light
	@ mkdir -p ${OBJS_DIR}/intersection
	@ mkdir -p ${OBJS_DIR}/math
	@ mkdir -p ${OBJS_DIR}/mlx
	@ mkdir -p ${OBJS_DIR}/parsing
	@ ${CC} ${FLAGS} ${INCS_PARAM} -c -o $@ $<
	@ printf "${ERASE}${BLUE} > compilation: ${END}$<"

#bonus: ${LIBFT} ${MINILIBX} ${OBJ} ${OBJ_BONUS}
#	${CC} ${CFLAGS} -o ${NAME} ${OBJ} ${OBJ_BONUS} ${LIBFT} ${MINILIBX} -lm -lX11 -lXext

clean:
	@ make clean -C ${LIBFT_DIR}
	@ rm -rf ${OBJS_DIR}
	@ printf "${YELLOW}${OBJS_DIR} removed\n${END}"
#	rm -f ${OBJ_BONUS}
#	if [ -d ${MINILIBXDIR} ]; then make clean -C ${MINILIBXDIR}; fi

fclean:
	@ make fclean -C ${LIBFT_DIR}
	@ rm -rf ${OBJS_DIR}
	@ printf "${YELLOW}${OBJS_DIR} removed\n${END}"
	@ rm -f ${NAME} fsanitize g3
	@ printf "${YELLOW}binary removed\n${END}"

re: fclean all

.PHONY: all fsanitize g3 libft clean fclean re
