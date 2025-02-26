/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:33:04 by achantra          #+#    #+#             */
/*   Updated: 2025/02/26 12:12:59 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_color
{
	int					r;
	int					g;
	int					b;
}						t_color;

typedef struct s_coordinates
{
	double				x;
	double				y;
	double				z;

}						t_coordinates;

typedef struct s_hitpoint
{
	t_coordinates	*coord;
	t_color			*color;
}					t_hitpoint;

typedef struct s_ray
{
	t_coordinates		*direction;
	t_coordinates		*origin;
}						t_ray;

typedef struct s_camera
{
	t_coordinates		*coord;
	t_coordinates		*dir;
	t_coordinates		*dir_right;
	t_coordinates		*dir_up;
	double				fov;
	t_ray				*ray;
}						t_camera;

typedef struct s_light
{
	t_coordinates		*coord;
	double				bright;
	t_color				*color;
	struct s_light		*next;
}						t_light;

typedef struct s_amb
{
	double				bright;
	t_color				*color;
}						t_amb;

typedef struct s_element
{
	int					id;
	t_coordinates		*coord;
	t_coordinates		*vector;
	t_color				*color;
	t_color				*colorbis;
	double				diameter;
	double				height;
	double				c_inter[2];
	int					intersec_type;
	struct s_element	*next;
}						t_element;

typedef struct s_img
{
	void				*img;
	char				*img_pixels;
	int					bits_per_pixel;
	int					endian;
	int					line_len;
}						t_img;

typedef struct s_env
{
	t_element			*figure;
	t_camera			*camera;
	t_light				*light;
	t_amb				*amb;
	void				*mlx;
	void				*win;
	double				vp_w;
	double				vp_h;
	double				a_ratio;
	t_img				img;
	int					selected_object;
	int					help;
}						t_env;

#endif
