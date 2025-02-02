/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:21:35 by achantra          #+#    #+#             */
/*   Updated: 2025/02/02 16:13:09 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_element	*init_form(void)
{
	t_element	*elem;

	elem = malloc(sizeof(t_element));
	if (!elem)
		return (NULL);
	elem->coord = NULL;
	elem->vector = NULL;
	elem->color = NULL;
	return (elem);
}

/*
- cy
	∗ x,y,z coordinates of the center of the cylinder: 50.0,0.0,20.6
	∗ 3d normalized vector of axis of cylinder.
		In range [-1,1] for each x,y,z axis 0.0,0.0,1.0
	∗ the cylinder diameter: 14.2
	∗ the cylinder height: 21.42
	∗ R,G,B colors in range [0,255]: 10, 0, 255
*/

int	new_cylinder(t_env *env, char **data)
{
	t_element	*cylinder;

	if (len_tab(data) != 6)
		return (ft_free_tab(data), print_data_err("cy"), 1);
	cylinder = init_form();
	if (!cylinder)
		return (ft_free_tab(data), perror("Error\n"), 1);
	cylinder->id = CYLINDER;
	cylinder->coord = parse_coordinates(data[1]);
	if (!cylinder->coord)
		return (clean_cylinder(cylinder), ft_free_tab(data), 1);
	cylinder->vector = parse_vector(data[2]);
	if (!cylinder->vector)
		return (clean_cylinder(cylinder), ft_free_tab(data), 1);
	cylinder->diameter = parse_length(data[3]);
	cylinder->height = parse_length(data[4]);
	if (cylinder->diameter <= 0 || cylinder->height <= 0)
		return (clean_cylinder(cylinder), ft_free_tab(data), 1);
	cylinder->color = parse_color(data[5]);
	if (!cylinder->color)
		return (clean_cylinder(cylinder), ft_free_tab(data), 1);
	cylinder->next = NULL;
	add_back_elem(&env->elem, cylinder);
	return (ft_free_tab(data), 0);
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

	if (len_tab(data) != 4)
		return (ft_free_tab(data), print_data_err("pl"), 1);
	sphere = init_form();
	if (!sphere)
		return (ft_free_tab(data), perror("Error\n"), 1);
	sphere->id = SPHERE;
	sphere->coord = parse_coordinates(data[1]);
	if (!sphere->coord)
		return (clean_sphere(sphere), ft_free_tab(data), 1);
	sphere->diameter = parse_length(data[2]);
	if (sphere->diameter <= 0)
		return (clean_sphere(sphere), ft_free_tab(data), 1);
	sphere->color = parse_color(data[3]);
	if (!sphere->color)
		return (clean_sphere(sphere), ft_free_tab(data), 1);
	sphere->next = NULL;
	add_back_elem(&env->elem, sphere);
	return (ft_free_tab(data), 0);
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

	if (len_tab(data) != 4)
		return (ft_free_tab(data), print_data_err("pl"), 1);
	plane = init_form();
	if (!plane)
		return (ft_free_tab(data), perror("Error"), 1);
	plane->id = PLANE;
	plane->coord = parse_coordinates(data[1]);
	if (!plane->coord)
		return (clean_plane(plane), ft_free_tab(data), 1);
	plane->vector = parse_vector(data[2]);
	if (!plane->vector)
		return (clean_plane(plane), ft_free_tab(data), 1);
	plane->color = parse_color(data[3]);
	if (!plane->color)
		return (clean_plane(plane), ft_free_tab(data), 1);
	plane->next = NULL;
	add_back_elem(&env->elem, plane);
	return (ft_free_tab(data), 0);
}
