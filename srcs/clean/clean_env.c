/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:24:42 by achantra          #+#    #+#             */
/*   Updated: 2025/03/01 20:55:13 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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

void	clean_light(t_light *light)
{
	t_light	*buf;

	if (light)
	{
		while (light)
		{
			buf = light;
			light = light->next;
			free(buf);
		}
	}
}

void	clean_figure(t_element *figure)
{
	t_element	*buf;

	if (figure)
	{
		while (figure)
		{
			buf = figure;
			figure = figure->next;
			free(buf);
		}
	}
}

int	clean_env(t_env *env, int exit_code)
{
	clean_light(env->light);
	clean_figure(env->figure);
	clean_mlx(env);
	exit (exit_code);
	return (exit_code);
}
