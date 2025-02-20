/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:26:30 by achantra          #+#    #+#             */
/*   Updated: 2025/02/20 16:38:43 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ft_reinit(t_env *env)
{
	env->rot_x = 0;
	env->rot_y = 0;
	env->rot_z = 0;
}

void	ft_rotate(int keysym, t_env *env)
{
	t_coordinates	lerp;

	ft_bzero(&lerp, sizeof(t_coordinates));
	if (keysym == XK_Up)
		lerp = mult_vec(sub_vec(*env->camera->dir, *env->camera->dir_up), 0.1);
	if (keysym == XK_Down)
		lerp = mult_vec(sub_vec(*env->camera->dir_up, *env->camera->dir), 0.1);
	if (keysym == XK_Up || keysym == XK_Down)
	{
		*env->camera->dir_up = add_vec(*env->camera->dir_up, lerp);
		normalize_vec(env->camera->dir_up);
	}
	if (keysym == XK_Left)
		lerp = mult_vec(sub_vec(*env->camera->dir, *env->camera->dir_right),
				0.1);
	if (keysym == XK_Right)
		lerp = mult_vec(sub_vec(*env->camera->dir_right, *env->camera->dir),
				0.1);
	if (keysym == XK_Left || keysym == XK_Right)
	{
		*env->camera->dir_right = add_vec(*env->camera->dir_right, lerp);
		normalize_vec(env->camera->dir_up);
	}
	*env->camera->dir = add_vec(*env->camera->dir, lerp);
	normalize_vec(env->camera->dir);
}

void	ft_elevate(int keysym, t_env *env)
{
	if (keysym == XK_q)
		*env->camera->coord
			= sub_vec(*env->camera->coord, *env->camera->dir_up);
	if (keysym == XK_e)
		*env->camera->coord
			= add_vec(*env->camera->coord, *env->camera->dir_up);
}

void	ft_translate(int keysym, t_env *env)
{
	if (keysym == XK_w)
		*env->camera->coord = add_vec(*env->camera->coord, *env->camera->dir);
	if (keysym == XK_s)
		*env->camera->coord = sub_vec(*env->camera->coord, *env->camera->dir);
	if (keysym == XK_a)
		*env->camera->coord
			= sub_vec(*env->camera->coord, *env->camera->dir_right);
	if (keysym == XK_d)
		*env->camera->coord
			= add_vec(*env->camera->coord, *env->camera->dir_right);
}

void	ft_zoom(int keysym, t_env *env)
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
