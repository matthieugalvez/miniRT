/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:21:35 by achantra          #+#    #+#             */
/*   Updated: 2025/02/01 17:33:35 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
/*
	- cy
		∗ x,y,z coordinates of the center of the cylinder: 50.0,0.0,20.6
		∗ 3d normalized vector of axis of cylinder. In range [-1,1] for each x,y,z axis 0.0,0.0,1.0
		∗ the cylinder diameter: 14.2
		∗ the cylinder height: 21.42
		∗ R,G,B colors in range [0,255]: 10, 0, 255
*/

int	new_cylinder(t_env *env, char **data)
{
	t_element	*cylinder;

	cylinder = malloc(sizeof(t_element));
	if (!cylinder)
		return (perror("Error\n"), 1);
	cylinder->id = CYLINDER;
	// Check data
	// Parse cylinder
	return (0);
}
