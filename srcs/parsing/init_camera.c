/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:23:23 by achantra          #+#    #+#             */
/*   Updated: 2025/02/02 16:12:49 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
- C(u)
	∗ x,y,z coordinates of the view point: -50.0,0,20
	∗ 3d normalized orientation vector.
		In range [-1,1] for each x,y,z axis: 0.0,0.0,1.0
	∗ FOV : Horizontal field of view in degrees in range [0,180]: 70
*/

t_camera	*init_camera(void)
{
	t_camera	*cam;

	cam = malloc(sizeof(t_camera));
	if (!cam)
		return (NULL);
	cam->coord = NULL;
	cam->vector = NULL;
	return (cam);
}

int	new_camera(t_env *env, char **data)
{
	t_camera	*cam;

	if (env->camera)
		return (ft_free_tab(data), print_data_err("double C"), 1);
	if (len_tab(data) != 4)
		return (ft_free_tab(data), print_data_err("C"), 1);
	cam = init_camera();
	if (!cam)
		return (ft_free_tab(data), perror("Error"), 1);
	cam->coord = parse_coordinates(data[1]);
	if (!cam->coord)
		return (clean_camera(cam), ft_free_tab(data), 1);
	cam->vector = parse_vector(data[2]);
	if (!cam->vector)
		return (clean_camera(cam), ft_free_tab(data), 1);
	cam->fov = parse_fov(data[3]);
	if (cam->fov < 0)
		return (clean_camera(cam), ft_free_tab(data), 1);
	env->camera = cam;
	return (ft_free_tab(data), 0);
}
