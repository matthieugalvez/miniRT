/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:37:52 by achantra          #+#    #+#             */
/*   Updated: 2025/09/12 10:15:26 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft.h"
# include "mlx.h"
# include "struct.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define SPHERE 0
# define PLANE 1
# define CYLINDER 2
# define CONE 3

# define HEXA "0123456789abcdef"
# define EPSILON 1e-6

# define WIN_W 960
# define WIN_H 1025

# define INCR_TRAN 1
# define INCR_ROT 0.1
# define INCR_EL 0.1
# define INCR_ZOOM 1

// # define DBLUE 0x00008b
// # define LBLUE 0x1e90ff
// # define TBLUE 0x40e0d0

// INIT
void			init_env(t_env *env);
int				init_element(t_env *env, char *line);
int				new_camera(t_env *env, char **data);
t_coordinates	find_tmp_up(t_coordinates *vector);
int				new_plane(t_env *env, char **data);
int				new_sphere(t_env *env, char **data);
int				new_cylinder(t_env *env, char **data);
int				new_cone(t_env *env, char **data);
void			find_disks(t_element *figure);
int				find_vectors(t_element *element);
int				new_ambient(t_env *env, char **data);
int				new_light(t_env *env, char **data);
int				init_mlx(t_env *env);
void			find_viewport(t_env *env);
int				ft_is_float(char *data);
void			add_back_elem(t_element **elem, t_element *new_elem);
void			add_back_light(t_light **light, t_light *new_light);

// PARSING
int				check_entry(int ac, char **av);
int				parse_file(char *path, t_env *env);
int				parse_figure_color_data(t_element *figure,
					t_env *env, char *data);
int				parse_color(char *data, t_color *color);
int				parse_coordinates(char *data, t_coordinates *coordinates);
int				parse_vector(char *data, t_coordinates *coordinates);
double			parse_ratio(char *data);
double			parse_fov(char *data);
double			parse_length(char *data);
int				parse_xpm_file(t_env *env, t_img *img, char *data);
int				check_element(t_env *env);

// CLEAN
void			clean_light(t_light *light);
void			clean_figure(t_env *env, t_element *figure);
int				clean_env(t_env *env, int exit_code);

// MLX
int				ft_key(int keysym, t_env *env);
void			move_light(int keysym, t_env *env);
void			move_camera(int keysym, t_env *env);
void			move_object(int keysym, t_env *env);
int				print_image(t_env *env);
void			check_help(t_env *env);
int				print_selected_light(t_env *env);
int				print_selected_object(t_env *env);
t_element		*find_selected_object(t_env *env);

// IMAGE
int				draw_image(t_env *env);
void			get_uv_coords(t_hitpoint *hitpoint, t_element *figure,
					double *uv_coords);
t_coordinates	get_ref(t_coordinates *temp_coord, double teta,
					t_coordinates *u, t_element *figure);
void			get_pixel_pl(t_img *texture, double *uv_coords, int *x, int *y);
void			get_pixel_sp(t_img *texture, double *uv_coords, int *x, int *y);
int				rgb_to_hexa(t_color *color);
void			my_pixel_put(int i, int j, t_env *env, int color);
void			find_hitpoint_color(t_hitpoint *hitpoint, t_element *figure);

// INTERSECTION
double			find_intsec(t_ray *ray, t_element *figure);
void			intersect_cylinder(t_element *cy, t_ray *ray);
void			intersect_cone(t_element *co, t_ray *ray);

// LIGHT
int				apply_light(t_env *env, t_element *figure,
					t_hitpoint *hitpoint);
t_color			compute_light_source(t_env *env, t_hitpoint *hitpoint,
					t_element *figure, t_light *light);

// MATH
void			double_increment(double *d);
void			double_decrement(double *d);
int				equal_double(double a, double b);
t_coordinates	*new_vec(double x, double y, double z);
t_coordinates	change_vec(double x, double y, double z);
t_coordinates	add_vec(t_coordinates *v1, t_coordinates *v2);
t_coordinates	sub_vec(t_coordinates *v1, t_coordinates *v2);
t_coordinates	mult_vec(t_coordinates *v, double fact);
t_coordinates	div_vec(t_coordinates *v, double fact);
double			scalar_prod_vec(t_coordinates *v1, t_coordinates *v2);
double			get_norm(t_coordinates *vector);
void			normalize_vec(t_coordinates *vector);
t_coordinates	vect_prod_vec(t_coordinates *v1, t_coordinates *v2);
t_coordinates	get_normal_at(t_element *figure, t_coordinates *point,
					t_ray *light_ray, t_ray *cam_ray);
t_coordinates	normal_at_cy(t_element *cylinder, t_coordinates *point);
t_coordinates	normal_at_co(t_element *cone, t_coordinates *point);
void			make_bump_map_normal(t_element *figure,
					t_coordinates *normal_at_hp, double *bubv);

// DEBUG
void			debug_env(t_env *env);

#endif
