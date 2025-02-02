/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:22:19 by achantra          #+#    #+#             */
/*   Updated: 2025/02/02 12:56:47 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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

	plane = malloc(sizeof(t_element));
	if (!plane)
		return (ft_free_tab(data), perror("Error"), 1);
	if (len_tab(data) != 4)
		return (free(plane), ft_free_tab(data), print_data_err(), 1);
	plane->id = PLANE;
	plane->coord = parse_coordinates(data[1]);
	if (!plane->coord)
		return (clean_plane(plane), ft_free_tab(data), 1);
	plane->vector = parse_vector(data[2]);
	if (!plane->vector)
		return (clean_plane(plane), ft_free_tab(data), 1);
	plane->color = parse_color(data[3]);
	if (!plane->color)
		return (clean_plane(plane), free(plane), ft_free_tab(data), 1);
	plane->next = NULL;
	add_back_elem(env->elem, plane);
	return (ft_free_tab(data), 0);
}
