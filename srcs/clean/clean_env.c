/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:24:42 by achantra          #+#    #+#             */
/*   Updated: 2025/02/04 11:24:23 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	clean_element(t_env *env)
{
	t_element	*buf;

	clean_ambient(env->amb);
	clean_light(env->light);
	clean_camera(env->camera);
	if (env->elem)
	{
		while (env->elem)
		{
			buf = env->elem;
			env->elem = env->elem->next;
			if (buf->id == CYLINDER)
				clean_cylinder(buf);
			else if (buf->id == SPHERE)
				clean_sphere(buf);
			else if (buf->id == PLANE)
				clean_plane(buf);
		}
	}
}

void	clean_mlx(t_env *env)
{
	if (env->mlx)
	{
		if (env->img.img)
			mlx_destroy_image(env->mlx, env->img.img);
		if (env->win)
			mlx_destroy_window(env->mlx, env->win);
		mlx_destroy_display(env->mlx);
		free(env->mlx);
	}
}

int	clean_env(t_env *env)
{
	clean_element(env);
	clean_mlx(env);
	free(env);
	exit (0);
	return (0);
}

int	clean_env_err(t_env *env)
{
	clean_element(env);
	clean_mlx(env);
	free(env);
	exit (1);
	return (1);
}
