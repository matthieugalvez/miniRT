# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achantra <achantra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 15:30:48 by achantra          #+#    #+#              #
#    Updated: 2025/02/28 14:04:16 by mgalvez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= miniRT
BONUS				= miniRT_bonus

CC					= cc
CFLAGS				= -Wall -Wextra -Werror
LIBS				= -lm -lX11 -lXext

SRCS_DIR			= srcs
OBJS_DIR			= .objs
SRCS_BONUS_DIR		= srcs_bonus
OBJS_BONUS_DIR		= .objs_bonus
INCS_DIR			= includes
LIBFT_DIR			= libft
MLX_DIR				= mlx_linux

CLEAN_SRCS			= clean_element.c clean_env.c
IMAGE_SRCS			= cam_ray_tracing.c image_utils.c
INIT_SRCS			= init_ambient.c init_camera.c init_elements.c init_env.c \
					  init_figures.c init_light.c init_mlx.c init_utils.c init_utils2.c
LIGHT_SRCS			= light.c light_utils.c
INTRSC_SRCS			= intersection.c intsec_cylinder.c
MATH_SRCS			= double_operator.c vector_operator.c vector_operator2.c \
					  normal_operator.c
MLX_SRCS			= key_funcs.c camera_key_funcs.c figures_key_funcs.c \
					  light_key_funcs.c manage_window.c mlx_utils.c
PARSE_SRCS			= parse_color.c parse_coordinates.c parse_number.c parsing.c

SRCS_LST			= ${addprefix clean/, ${CLEAN_SRCS}} \
					  ${addprefix image/, ${IMAGE_SRCS}} \
					  ${addprefix init/, ${INIT_SRCS}} \
					  ${addprefix light/, ${LIGHT_SRCS}} \
					  ${addprefix intersection/, ${INTRSC_SRCS}} \
					  ${addprefix math/, ${MATH_SRCS}} \
					  ${addprefix mlx/, ${MLX_SRCS}} \
					  ${addprefix parsing/, ${PARSE_SRCS}} \
					  main.c
OBJS_LST			= ${SRCS_LST:.c=.o}

BONUS_CLEAN_SRCS	= clean_element.c clean_env.c
BONUS_IMAGE_SRCS	= cam_ray_tracing.c image_utils.c check_color.c
BONUS_INIT_SRCS		= init_ambient.c init_camera.c init_elements.c init_env.c \
					  init_figures.c init_cone.c init_light.c init_mlx.c init_utils.c \
					  init_utils2.c
BONUS_LIGHT_SRCS	= light.c compute_light_source.c light_utils.c

BONUS_INTRSC_SRCS	= intersection.c intsec_cylinder.c intsec_cone.c
BONUS_MATH_SRCS		= double_operator.c vector_operator.c vector_operator2.c \
					  normal_operator.c normal_operator2.c
BONUS_MLX_SRCS		= key_funcs.c camera_key_funcs.c figures_key_funcs.c \
					  light_key_funcs.c manage_window.c print_str_funcs.c \
					  mlx_utils.c
BONUS_PARSE_SRCS	= parse_color.c parse_coordinates.c parse_number.c parsing.c

SRCS_BONUS_LST		= ${addprefix clean/, ${BONUS_CLEAN_SRCS}} \
					  ${addprefix image/, ${BONUS_IMAGE_SRCS}} \
					  ${addprefix init/, ${BONUS_INIT_SRCS}} \
					  ${addprefix light/, ${BONUS_LIGHT_SRCS}} \
					  ${addprefix intersection/, ${BONUS_INTRSC_SRCS}} \
					  ${addprefix math/, ${BONUS_MATH_SRCS}} \
					  ${addprefix mlx/, ${BONUS_MLX_SRCS}} \
					  ${addprefix parsing/, ${BONUS_PARSE_SRCS}} \
					  main.c debug.c
OBJS_BONUS_LST			= ${SRCS_BONUS_LST:.c=.o}

SRCS				= ${addprefix ${SRCS_DIR}/, ${SRCS_LST}}
OBJS				= ${addprefix ${OBJS_DIR}/, ${OBJS_LST}}
SRCS_BONUS			= ${addprefix ${SRCS_BONUS_DIR}/, ${SRCS_BONUS_LST}}
OBJS_BONUS			= ${addprefix ${OBJS_BONUS_DIR}/, ${OBJS_BONUS_LST}}
LIBFT				= ${LIBFT_DIR}/libft.a
MLX					= ${MLX_DIR}/libmlx_Linux.a

INCS_PARAM			= -I ${INCS_DIR} -I ${LIBFT_DIR} -I ${MLX_DIR}

ERASE				= \033[2K\r
BLUE				= \033[34m
YELLOW				= \033[33m
GREEN				= \033[32m
END					= \033[0m

all: libft ${NAME} ${BONUS}

mandatory: libft ${NAME}

bonus: libft ${BONUS}

${NAME}: ${LIBFT} ${OBJS}
	@ ${CC} ${CFLAGS} ${LIBS} ${INCS_PARAM} ${OBJS} ${LIBFT} ${MLX} -o $@
	@ printf "${ERASE}${GREEN}$@ made\n${END}"

${BONUS}: ${LIBFT} ${OBJS_BONUS}
	@ ${CC} ${CFLAGS} ${LIBS} ${INCS_PARAM} ${OBJS_BONUS} ${LIBFT} ${MLX} -o $@
	@ printf "${ERASE}${GREEN}$@ made\n${END}"

fsanitize: libft ${OBJS}
	@ ${CC} ${CFLAGS} ${LIBS} ${INCS_PARAM} ${OBJS} ${LIBFT} ${MLX} -o $@ -fsanitize=address
	@ printf "${ERASE}${GREEN}$@ made\n${END}"

fsanitize_bonus: libft ${OBJS_BONUS}
	@ ${CC} ${CFLAGS} ${LIBS} ${INCS_PARAM} ${OBJS_BONUS} ${LIBFT} ${MLX} -o $@ -fsanitize=address
	@ printf "${ERASE}${GREEN}$@ made\n${END}"

g3: libft ${OBJS}
	@ ${CC} ${CFLAGS} ${LIBS} ${INCS_PARAM} ${OBJS} ${LIBFT} ${MLX} -o $@ -g3
	@ printf "${ERASE}${GREEN}$@ made\n${END}"

g3_bonus: libft ${OBJS_BONUS}
	@ ${CC} ${CFLAGS} ${LIBS} ${INCS_PARAM} ${OBJS_BONUS} ${LIBFT} ${MLX} -o $@ -g3
	@ printf "${ERASE}${GREEN}$@ made\n${END}"

${LIBFT}: libft

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

${OBJS_BONUS_DIR}/%.o: ${SRCS_BONUS_DIR}/%.c
	@ mkdir -p ${OBJS_BONUS_DIR}
	@ mkdir -p ${OBJS_BONUS_DIR}/clean
	@ mkdir -p ${OBJS_BONUS_DIR}/image
	@ mkdir -p ${OBJS_BONUS_DIR}/init
	@ mkdir -p ${OBJS_BONUS_DIR}/light
	@ mkdir -p ${OBJS_BONUS_DIR}/intersection
	@ mkdir -p ${OBJS_BONUS_DIR}/math
	@ mkdir -p ${OBJS_BONUS_DIR}/mlx
	@ mkdir -p ${OBJS_BONUS_DIR}/parsing
	@ ${CC} ${FLAGS} ${INCS_PARAM} -c -o $@ $<
	@ printf "${ERASE}${BLUE} > compilation: ${END}$<"

clean:
	@ make clean -C ${LIBFT_DIR}
	@ rm -rf ${OBJS_DIR}
	@ printf "${YELLOW}${OBJS_DIR} removed\n${END}"
	@ rm -rf ${OBJS_BONUS_DIR}
	@ printf "${YELLOW}${OBJS_BONUS_DIR} removed\n${END}"

fclean:
	@ make fclean -C ${LIBFT_DIR}
	@ rm -rf ${OBJS_DIR}
	@ printf "${YELLOW}${OBJS_DIR} removed\n${END}"
	@ rm -rf ${OBJS_BONUS_DIR}
	@ printf "${YELLOW}${OBJS_BONUS_DIR} removed\n${END}"
	@ rm -f ${NAME} ${BONUS} fsanitize fsanitize_bonus g3 g3_bonus
	@ printf "${YELLOW}binary removed\n${END}"

re: fclean all

.PHONY: all mandatory bonus fsanitize fsanitize_bonus g3 g3_bonus libft clean fclean re
