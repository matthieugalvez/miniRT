/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:22:19 by achantra          #+#    #+#             */
/*   Updated: 2025/02/01 17:33:56 by achantra         ###   ########.fr       */
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
		return (perror("Error"), 1);
	plane->id = PLANE;
	// Check data
	// Parse plane
	return (0);
}