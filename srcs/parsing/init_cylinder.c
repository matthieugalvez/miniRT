/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:21:35 by achantra          #+#    #+#             */
/*   Updated: 2025/02/02 13:09:20 by achantra         ###   ########.fr       */
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

int	new_cylinder(t_env *env, char **data)
{
	t_element	*cylinder;

	cylinder = malloc(sizeof(t_element));
	if (!cylinder)
		return (ft_free_tab(data), perror("Error\n"), 1);
	if (len_tab(data) != 6)
		return (free(cylinder), ft_free_tab(data), print_data_err(), 1);
	cylinder->id = CYLINDER;
	cylinder->coord = parse_coordinates(data[1]);
	if (!cylinder->coord)
		return (clean_cylinder(cylinder), ft_free_tab(data), 1);
	cylinder->vector = parse_vector(data[2]);
	if (!cylinder->vector)
		return (clean_cylinder(cylinder), ft_free_tab(data), 1);
	cylinder->diameter = parse_positive_number(data[3]);
	cylinder->height = parse_positive_number(data[4]);
	if (cylinder->diameter <= 0 || cylinder->height <= 0)
		return (clean_cylinder(cylinder), ft_free_tab(data), 1);
	cylinder->color = parse_color(data[5]);
	if (!cylinder->color)
		return (clean_cylinder(cylinder), ft_free_tab(data), 1);
	cylinder->next = NULL;
	add_back_elem(env->elem, cylinder);
	return (ft_free_tab(data), 0);
}
