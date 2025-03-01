/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:23:23 by achantra          #+#    #+#             */
/*   Updated: 2025/03/01 17:41:28 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

/*
- C(u)
	∗ x,y,z coordinates of the view point: -50.0,0,20
	∗ 3d normalized orientation vector.
		In range [-1,1] for each x,y,z axis: 0.0,0.0,1.0
	∗ FOV : Horizontal field of view in degrees in range [0,180]: 70
*/

static int	find_dir(t_camera *cam)
{
	t_coordinates	tmp_up;

	tmp_up = find_tmp_up(&cam->dir);
	cam->dir_up = vect_prod_vec(&tmp_up, &cam->dir);
	normalize_vec(&cam->dir_up);
	cam->dir_right = vect_prod_vec(&cam->dir, &cam->dir_up);
	normalize_vec(&cam->dir_right);
	cam->dir_up = mult_vec(&cam->dir_up, -1);
	return (0);
}

static int	init_camera(t_camera *cam, char **data)
{
	if (parse_coordinates(data[1], &cam->coord))
	{
		ft_freetab(data);
		return (1);
	}
	if (parse_vector(data[2], &cam->dir))
	{
		ft_freetab(data);
		return (1);
	}
	cam->fov = parse_fov(data[3]);
	if (cam->fov < 0)
	{
		ft_freetab(data);
		return (1);
	}
	ft_freetab(data);
	normalize_vec(&cam->dir);
	return (find_dir(cam));
}

int	new_camera(t_env *env, char **data)
{
	if (env->cam_cmpt || ft_tablen(data) != 4)
	{
		ft_freetab(data);
		ft_putstr("Error: wrong data: camera\n", 2);
		return (1);
	}
	env->cam_cmpt += 1;
	if (init_camera(&env->camera, data))
		return (1);
	find_viewport(env);
	return (0);
}
