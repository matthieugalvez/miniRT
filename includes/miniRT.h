/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:37:52 by achantra          #+#    #+#             */
/*   Updated: 2025/02/10 16:53:35 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "struct.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define SPHERE 0
# define PLANE 1
# define CYLINDER 2

# define HEXA "0123456789abcdef"

# define WIN_W 1000
# define WIN_H 1000

# define INCR_TRAN 1
# define INCR_ROT 0.1
# define INCR_EL 0.1
# define INCR_ZOOM 1

# define DBLUE 0x00008b
# define LBLUE 0x1e90ff
# define TBLUE 0x40e0d0

# define KEY_ESC 65307
# define KEY_PLUS 65451
# define KEY_MINUS 65453
# define KEY_LEFT 65361
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_X 120
# define KEY_Y 121
# define KEY_Z 122
# define KEY_A 97
# define KEY_B 98
# define KEY_C 99
# define KEY_I 105
# define KEY_P 112
# define KEY_K 107
# define KEY_D 100
# define KEY_E 101

// PARSING
int				check_entry(int ac, char **av);
int				parse_file(char *path, t_env *env);
void			init_env(t_env *env);
int				new_cylinder(t_env *env, char **data);
int				new_sphere(t_env *env, char **data);
int				new_plane(t_env *env, char **data);
int				new_ambient(t_env *env, char **data);
int				new_light(t_env *env, char **data);
int				new_camera(t_env *env, char **data);
void			add_back_elem(t_element **elem, t_element *new_elem);
int				init_element(t_env *env, char *line);
int				ft_is_float(char *data);
double			ft_atof(char *num1, char *num2);
int				len_tab(char **tab);
int				count_coma(char *data);
t_color			*ft_color(char *num1, char *num2, char *num3);
t_color			*parse_color(char *data);
t_coordinates	*parse_coordinates(char *data);
t_coordinates	*parse_vector(char *data);
double			parse_ratio(char *data);
double			parse_fov(char *data);
double			parse_length(char *data);
void			find_viewport(t_env *env);

// ERROR
void			print_data_err(char *data);
void			print_data_war(char *data);

// CLEAN
void			clean_ambient(t_amb *amb);
void			clean_light(t_light *light);
void			clean_camera(t_camera *cam);
void			clean_form(t_element *form);
int				clean_env(t_env *env);
int				clean_env_err(t_env *env);

// MLX
int				init_mlx(t_env *env);
int				ft_key(int keysym, t_env *env);

// IMAGE
int				print_image(t_env *env);
int				rgb_to_hexa(t_color *color);
int				intersect_sphere(t_env *env, t_element *sp, t_ray *ray);
int				intersect_cylinder(t_env *env, t_element *cy, t_ray *ray);
int				color_image(t_env *env);

// MATH
t_coordinates	*new_vec(double x, double y, double z);
t_coordinates	change_vec(double x, double y, double z);
t_coordinates	add_vec(t_coordinates v1, t_coordinates v2);
t_coordinates	substract_vec(t_coordinates v1, t_coordinates v2);
t_coordinates	multiply_vec(t_coordinates v, double fact);
t_coordinates	divide_vec(t_coordinates v, double fact);
double			scalar_prod_vec(t_coordinates v1, t_coordinates v2);
double			norm_vec(t_coordinates vector);
void			normalize_vec(t_coordinates *vector);
t_coordinates	*vectorial_prod_vec(t_coordinates v1, t_coordinates v2);
int				equal_double(double a, double b);

// DEBUG
void			debug_env(t_env *env);

#endif
