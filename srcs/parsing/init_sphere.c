/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:21:57 by achantra          #+#    #+#             */
/*   Updated: 2025/02/02 12:56:20 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
	- sp
		∗ x,y,z coordinates of the sphere center: 0.0,0.0,20.6
		∗ the sphere diameter: 12.6
		* R,G,B colors in range [0-255]: 10, 0, 255
*/

int	new_sphere(t_env *env, char **data)
{
	t_element	*sphere;

	sphere = malloc(sizeof(t_element));
	if (!sphere)
		return (ft_free_tab(data), perror("Error\n"), 1);
	if (len_tab(data) != 4)
		return (free(sphere), ft_free_tab(data), print_data_err(), 1);
	sphere->id = SPHERE;
	sphere->coord = parse_coordinates(data[1]);
	if (!sphere->coord)
		return (clean_sphere(sphere), ft_free_tab(data), 1);
	sphere->diameter = parse_positive_number(data[2]);
	if (sphere->diameter <= 0)
		return (clean_sphere(sphere), ft_free_tab(data), 1);
	sphere->color = parse_color(data[3]);
	if (!sphere->color)
		return (clean_sphere(sphere), ft_free_tab(data), 1);
	sphere->next = NULL;
	add_back_elem(env->elem, sphere);
	return (ft_free_tab(data), 0);
}
