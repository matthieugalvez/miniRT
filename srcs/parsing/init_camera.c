/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:23:23 by achantra          #+#    #+#             */
/*   Updated: 2025/02/04 22:19:55 by achantra         ###   ########.fr       */
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
	cam->dir = NULL;
	cam->dir_right = NULL;
	cam->dir_up = NULL;
	return (cam);
}

int	find_cam_direction(t_camera *cam)
{
	t_coordinates	tmp_up;

	normalize_vec(cam->dir);
	tmp_up = change_vec(0, 1, 0);
	if (cam->dir->x == 0 && cam->dir->z == 0)
		tmp_up = change_vec(1, 0, 0);
	cam->dir_right = vectorial_prod_vec(tmp_up, *(cam->dir));
	if (!cam->dir_right)
		return (clean_camera(cam), 1);
	normalize_vec(cam->dir_right);
	cam->dir_up = vectorial_prod_vec(*(cam->dir), *(cam->dir_right));
	if (!cam->dir_up)
		return (clean_camera(cam), 1);
	normalize_vec(cam->dir_up);
	return (0);
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
	cam->dir = parse_vector(data[2]);
	if (!cam->dir)
		return (clean_camera(cam), ft_free_tab(data), 1);
	cam->fov = parse_fov(data[3]);
	if (cam->fov < 0)
		return (clean_camera(cam), ft_free_tab(data), 1);
	ft_free_tab(data);
	find_cam_direction(cam);
	env->camera = cam;
	return (0);
}

void	find_viewport(t_env *env)
{
	env->vp_w = 2 * tan(env->camera->fov * M_PI / 360);
	env->vp_h = env->vp_w / env->a_ratio;
}
