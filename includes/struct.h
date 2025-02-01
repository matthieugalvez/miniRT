/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:33:04 by achantra          #+#    #+#             */
/*   Updated: 2025/02/01 18:17:09 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "libft.h"

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

typedef struct s_camera
{
	t_coordinates		*coord;
	t_coordinates		*vector;
	double				fov;
}						t_camera;

typedef struct s_light
{
	t_coordinates		*coord;
	double				bright;
}						t_light;

typedef struct s_amb
{
	double				ratio;
	t_color				*color;
}						t_amb;

typedef struct s_element
{
	int					id;
	t_coordinates		*coord;
	t_coordinates		*vector;
	t_color				*color;
	double				diameter;
	double				height;
	struct s_element	*next;
}						t_element;

typedef struct s_env
{
	t_element			**elem;
	t_camera			*camera;
	t_light				*light;
	t_amb				*amb;
}						t_env;

#endif