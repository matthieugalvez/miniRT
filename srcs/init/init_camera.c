/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:23:23 by achantra          #+#    #+#             */
/*   Updated: 2025/02/20 15:56:06 by mgalvez          ###   ########.fr       */
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

static int	find_dir(t_camera *cam)
{
	t_coordinates	tmp_up;

	if (!equal_double(cam->dir->y, 0) || !equal_double(cam->dir->z, 0))
		tmp_up = change_vec(1, 0, 0);
	else
		tmp_up = change_vec(0, 1, 0);
	cam->dir_up = vectorial_prod_vec(tmp_up, *(cam->dir));
	if (!cam->dir_up)
	{
		clean_camera(cam);
		return (1);
	}
	normalize_vec(cam->dir_up);
	cam->dir_right = vectorial_prod_vec(*(cam->dir), *(cam->dir_up));
	if (!cam->dir_right)
	{
		clean_camera(cam);
		return (1);
	}
	normalize_vec(cam->dir_right);
	*cam->dir_up = mult_vec(*cam->dir_up, -1);
	return (0);
}

static int	init_camera(t_camera *cam, char **data)
{
	cam->coord = parse_coordinates(data[1]);
	if (!cam->coord)
	{
		clean_camera(cam);
		ft_freetab(data);
		return (1);
	}
	cam->dir = parse_vector(data[2]);
	if (!cam->dir)
	{
		clean_camera(cam);
		ft_freetab(data);
		return (1);
	}
	cam->fov = parse_fov(data[3]);
	if (cam->fov < 0)
	{
		clean_camera(cam);
		ft_freetab(data);
		return (1);
	}
	ft_freetab(data);
	return (find_dir(cam));
}

int	new_camera(t_env *env, char **data)
{
	t_camera	*cam;

	if (env->camera || ft_tablen(data) != 4)
	{
		ft_freetab(data);
		ft_putstr("Error: wrong data: camera\n", 2);
		return (1);
	}
	cam = ft_calloc(sizeof(t_camera), 1);
	if (!cam)
	{
		ft_freetab(data);
		perror("Error");
		return (1);
	}
	if (init_camera(cam, data))
		return (1);
	env->camera = cam;
	find_viewport(env);
	return (0);
}
