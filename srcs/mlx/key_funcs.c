/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:26:30 by achantra          #+#    #+#             */
/*   Updated: 2025/02/20 15:38:37 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ft_reinit(t_env *env)
{
	env->rot_x = 0;
	env->rot_y = 0;
	env->rot_z = 0;
}

void	ft_elevate(int keysym, t_env *env)
{
}

void	ft_rotate(int keysym, t_env *env)
{
}

void	ft_translate(int keysym, t_env *env)
{
	if (keysym == XK_w)
		*env->camera->coord = add_vec(*env->camera->coord, *env->camera->dir);
	if (keysym == XK_s)
		*env->camera->coord = sub_vec(*env->camera->coord, *env->camera->dir);
//	if (keysym == XK_a)
//		*env->camera->coord = sub_vec(*env->camera->coord, *env->camera->dir_right);
//	if (keysym == XK_d)
//		*env->camera->coord = add_vec(*env->camera->coord, *env->camera->dir_right);
	printf("%f\n%f\n%f\n\n", env->camera->coord->x, env->camera->coord->y, env->camera->coord->z);
}

void	ft_zoom(int keysym, t_env *env)
{
	if (env->camera->fov < 180 && keysym == XK_KP_Add)
	{
		env->camera->fov += 5;
		if (env->camera->fov > 180)
			env->camera->fov = 180;
	}
	if (env->camera->fov > 0 && keysym == XK_KP_Subtract)
	{
		env->camera->fov -= 5;
		if (env->camera->fov < 0)
			env->camera->fov = 0;
	}
	find_viewport(env);
}
