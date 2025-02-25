/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:24:42 by achantra          #+#    #+#             */
/*   Updated: 2025/02/25 18:00:06 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static void	clean_element(t_env *env)
{
	clean_ambient(env->amb);
	clean_light(env->light);
	clean_camera(env->camera);
	clean_figure(env->figure);
}

static void	clean_mlx(t_env *env)
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

int	clean_env(t_env *env, int exit_code)
{
	clean_element(env);
	clean_mlx(env);
	exit (exit_code);
	return (exit_code);
}
