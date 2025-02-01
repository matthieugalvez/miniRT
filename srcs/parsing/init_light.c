/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:23:59 by achantra          #+#    #+#             */
/*   Updated: 2025/02/01 17:34:37 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
- L(u)
		∗ x,y,z coordinates of the light point: -40.0,50.0,0.0
		∗ the light brightness ratio in range [0.0,1.0]: 0.6
		∗ (unused in mandatory part)R,G,B colors in range [0-255]: 10, 0, 255
*/

int new_light(t_env *env, char **data)
{
    t_light   *light;
    
    light = malloc(sizeof(t_light));
    if (!light)
        return (perror("Error"), 1);
    // Check data
	// Parse light
    return (0);
}
