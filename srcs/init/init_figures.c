/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_figures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:21:35 by achantra          #+#    #+#             */
/*   Updated: 2025/02/27 21:40:40 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
- cy
	∗ x,y,z coordinates of the center of the cylinder: 50.0,0.0,20.6
	∗ 3d normalized vector of axis of cylinder.
		In range [-1,1] for each x,y,z axis 0.0,0.0,1.0
	∗ the cylinder diameter: 14.2
	∗ the cylinder height: 21.42
	∗ R,G,B colors in range [0,255]: 10, 0, 255
*/

static int	init_cylinder(t_element *cylinder, t_env *env, char **data)
{
	cylinder->coord = parse_coordinates(data[1]);
	cylinder->vector = parse_vector(data[2]);
	cylinder->color = parse_color(data[5]);
	if (!cylinder->coord || !cylinder->vector || !cylinder->color)
	{
		clean_figure(cylinder);
		ft_freetab(data);
		return (1);
	}
	normalize_vec(cylinder->vector);
	cylinder->diameter = parse_length(data[3]);
	cylinder->height = parse_length(data[4]);
	if (cylinder->diameter <= 0 || cylinder->height <= 0)
	{
		clean_figure(cylinder);
		ft_freetab(data);
		ft_putstr("Error: wrong data: cylinder\n", 2);
		return (1);
	}
	cylinder->radius = cylinder->diameter / 2;
	add_back_elem(&env->figure, cylinder);
	ft_freetab(data);
	return (find_vectors(cylinder));
}

int	new_cylinder(t_env *env, char **data)
{
	t_element	*cylinder;

	if (ft_tablen(data) != 6)
	{
		ft_freetab(data);
		ft_putstr("Error: wrong data: cylinder\n", 2);
		return (1);
	}
	cylinder = ft_calloc(sizeof(t_element), 1);
	if (!cylinder)
	{
		ft_freetab(data);
		perror("Error");
		return (1);
	}
	cylinder->id = CYLINDER;
	return (init_cylinder(cylinder, env, data));
}

static int	init_figure(t_element *figure, t_env *env, char **data)
{
	figure->coord = parse_coordinates(data[1]);
	if (!figure->coord)
	{
		clean_figure(figure);
		ft_freetab(data);
		return (1);
	}
	figure->color = parse_color(data[3]);
	if (!figure->color)
	{
		clean_figure(figure);
		ft_freetab(data);
		return (1);
	}
	add_back_elem(&env->figure, figure);
	ft_freetab(data);
	if (figure->id == PLANE)
		return (find_vectors(figure));
	return (0);
}

/*
	- sp
		∗ x,y,z coordinates of the sphere center: 0.0,0.0,20.6
		∗ the sphere diameter: 12.6
		* R,G,B colors in range [0-255]: 10, 0, 255
*/

int	new_sphere(t_env *env, char **data)
{
	t_element	*sphere;

	if (ft_tablen(data) != 4)
	{
		ft_freetab(data);
		ft_putstr("Error: wrong data: sphere\n", 2);
		return (1);
	}
	sphere = ft_calloc(sizeof(t_element), 1);
	if (!sphere)
	{
		ft_freetab(data);
		perror("Error");
		return (1);
	}
	sphere->id = SPHERE;
	sphere->diameter = parse_length(data[2]);
	if (sphere->diameter <= 0)
	{
		clean_figure(sphere);
		ft_freetab(data);
		ft_putstr("Error: wrong data: sphere\n", 2);
		return (1);
	}
	return (init_figure(sphere, env, data));
}

/*
- pl
	∗ identifier: pl
	∗ x,y,z coordinates of a point in the plane: 0.0,0.0,-10.0
	∗ 3d normalized normal vector. In range [-1,1] for each x,y,z axis: 0.0,1.0,0.0
	∗ R,G,B colors in range [0-255]: 0,0,225
*/

int	new_plane(t_env *env, char **data)
{
	t_element	*plane;

	if (ft_tablen(data) != 4)
	{
		ft_freetab(data);
		ft_putstr("Error: wrong data: plane\n", 2);
		return (1);
	}
	plane = ft_calloc(sizeof(t_element), 1);
	if (!plane)
	{
		ft_freetab(data);
		perror("Error");
		return (1);
	}
	plane->id = PLANE;
	plane->vector = parse_vector(data[2]);
	if (!plane->vector)
	{
		clean_figure(plane);
		ft_freetab(data);
		return (1);
	}
	normalize_vec(plane->vector);
	return (init_figure(plane, env, data));
}
