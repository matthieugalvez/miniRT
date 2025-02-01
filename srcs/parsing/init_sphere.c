/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:21:57 by achantra          #+#    #+#             */
/*   Updated: 2025/02/01 17:34:12 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
	- sp
		∗ x,y,z coordinates of the sphere center: 0.0,0.0,20.6
		∗ the sphere diameter: 12.6
			R,G,B colors in range [0-255]: 10, 0, 255
*/

int	new_sphere(t_env *env, char **data)
{
	t_element	*sphere;

	sphere = malloc(sizeof(t_element));
	if (!sphere)
		return (perror("Error\n"), 1);
	sphere->id = SPHERE;
	// Check data
	// Parse sphere
	return (0);
}
