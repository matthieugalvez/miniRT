/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:23:23 by achantra          #+#    #+#             */
/*   Updated: 2025/02/01 17:34:55 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
- C(u)
		∗ x,y,z coordinates of the view point: -50.0,0,20
		∗ 3d normalized orientation vector. In range [-1,1] for each x,y,z axis: 0.0,0.0,1.0
		∗ FOV : Horizontal field of view in degrees in range [0,180]: 70
*/

int new_camera(t_env *env, char **data)
{
    t_camera   *cam;
    
    cam = malloc(sizeof(t_camera));
    if (!cam)
        return (perror("Error"), 1);
    // Check data
	// Parse cam
    return (0);
}
