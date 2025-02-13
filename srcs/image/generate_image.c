/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:36:59 by achantra          #+#    #+#             */
/*   Updated: 2025/02/13 12:55:26 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	check_element(t_env *env)
{
	if (env->camera && env->amb && env->light && env->figure)
		return (0);
	if (!env->camera)
		ft_putstr("Warning: missing camera\n", 2);
	if (!env->amb)
		ft_putstr("Warning: missing ambiant light\n", 2);
	if (!env->light)
		ft_putstr("Warning: missing light\n", 2);
	if (!env->figure)
		ft_putstr("Warning: missing figure\n", 2);
	return (1);
}

int	print_image(t_env *env)
{
	mlx_destroy_image(env->mlx, env->img.img);
	env->img.img = mlx_new_image(env->mlx, WIN_W, WIN_H);
	if (!env->img.img)
	{
		ft_putstr("Error: mlx\n", 2);
		return (clean_env(env, 1));
	}
	env->img.img_pixels = mlx_get_data_addr(env->img.img,
			&env->img.bits_per_pixel, &env->img.line_len, &env->img.endian);
	if (!env->img.img_pixels)
	{
		ft_putstr("Error: mlx\n", 2);
		return (clean_env(env, 1));
	}
	if (check_element(env))
		return (1);
	color_image(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
	return (0);
}
