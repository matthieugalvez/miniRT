/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:36:59 by achantra          #+#    #+#             */
/*   Updated: 2025/02/10 16:55:18 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	check_element(t_env *env)
{
	if (env->camera && env->amb && env->light && env->form)
		return (0);
	if (!env->camera)
		print_data_war("camera");
	if (!env->amb)
		print_data_war("ambient lightning");
	if (!env->light)
		print_data_war("light");
	if (!env->form)
		print_data_war("form");
	return (1);
}

int	print_image(t_env *env)
{
	mlx_destroy_image(env->mlx, env->img.img);
	env->img.img = mlx_new_image(env->mlx, WIN_W, WIN_H);
	if (!env->img.img)
		return (ft_putendl("Error: mlx", 2), clean_env_err(env));
	env->img.img_pixels = mlx_get_data_addr(env->img.img,
			&env->img.bits_per_pixel, &env->img.line_len, &env->img.endian);
	if (!env->img.img_pixels)
		return (ft_putendl("Error: mlx", 2), clean_env_err(env));
	if (check_element(env))
		return (1);
	color_image(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
	return (0);
}
