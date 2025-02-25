/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_key_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:26:30 by achantra          #+#    #+#             */
/*   Updated: 2025/02/25 16:55:58 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	ft_rotate(int keysym, t_camera *camera)
{
	t_coordinates	lerp;

	if (keysym == XK_Up)
		lerp = sub_vec(*camera->dir, *camera->dir_up);
	if (keysym == XK_Down)
		lerp = sub_vec(*camera->dir_up, *camera->dir);
	if (keysym == XK_Up || keysym == XK_Down)
	{
		lerp = mult_vec(lerp, 0.1);
		*camera->dir_up = add_vec(*camera->dir_up, lerp);
		normalize_vec(camera->dir_up);
	}
	if (keysym == XK_Left)
		lerp = sub_vec(*camera->dir, *camera->dir_right);
	if (keysym == XK_Right)
		lerp = sub_vec(*camera->dir_right, *camera->dir);
	if (keysym == XK_Left || keysym == XK_Right)
	{
		lerp = mult_vec(lerp, 0.1);
		*camera->dir_right = add_vec(*camera->dir_right, lerp);
		normalize_vec(camera->dir_right);
	}
	free(camera->dir);
	camera->dir = vect_prod_vec(*camera->dir_right, *camera->dir_up);
	normalize_vec(camera->dir);
}

static void	ft_translate(int keysym, t_camera *camera)
{
	if (keysym == XK_w)
		*camera->coord = add_vec(*camera->coord, *camera->dir);
	if (keysym == XK_s)
		*camera->coord = sub_vec(*camera->coord, *camera->dir);
	if (keysym == XK_a)
		*camera->coord = sub_vec(*camera->coord, *camera->dir_right);
	if (keysym == XK_d)
		*camera->coord = add_vec(*camera->coord, *camera->dir_right);
	if (keysym == XK_q)
		*camera->coord = sub_vec(*camera->coord, *camera->dir_up);
	if (keysym == XK_e)
		*camera->coord = add_vec(*camera->coord, *camera->dir_up);
}

static void	ft_zoom(int keysym, t_env *env)
{
	if (env->camera->fov < 180 && keysym == XK_KP_Subtract)
	{
		env->camera->fov += 5;
		if (env->camera->fov > 180)
			env->camera->fov = 180;
	}
	if (env->camera->fov > 0 && keysym == XK_KP_Add)
	{
		env->camera->fov -= 5;
		if (env->camera->fov < 0)
			env->camera->fov = 0;
	}
	find_viewport(env);
}

void	move_camera(int keysym, t_env *env)
{
	if (keysym == XK_KP_Add || keysym == XK_KP_Subtract)
		ft_zoom(keysym, env);
	else if (keysym == XK_w || keysym == XK_a
		|| keysym == XK_s || keysym == XK_d
		|| keysym == XK_q || keysym == XK_e)
		ft_translate(keysym, env->camera);
	else if (keysym >= XK_Left && keysym <= XK_Down)
		ft_rotate(keysym, env->camera);
}
