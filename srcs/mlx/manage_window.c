/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:55:30 by achantra          #+#    #+#             */
/*   Updated: 2025/02/24 17:02:32 by mgalvez          ###   ########.fr       */
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
	draw_image(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
	return (0);
}

static void	move_object(int keysym, t_env *env)
{
}

int	ft_key(int keysym, t_env *env)
{
	if (keysym == XK_Escape)
		return (clean_env(env, 0));
	else if (keysym == XK_space || keysym == XK_Return)
		ft_select(env);
	else if (!env->selected_object)
	{
		if (keysym == XK_KP_Add || keysym == XK_KP_Subtract)
			ft_zoom(keysym, env);
		else if (keysym == XK_w || keysym == XK_a
			|| keysym == XK_s || keysym == XK_d)
			ft_translate(keysym, env);
		else if (keysym == XK_q || keysym == XK_e)
			ft_elevate(keysym, env);
		else if ((keysym >= XK_Left && keysym <= XK_Down))
			ft_rotate(keysym, env);
	}
	else
		move_object(keysym, env);
	print_image(env);
	return (0);
}

int	init_mlx(t_env *env)
{
	env->mlx = mlx_init();
	if (!env->mlx)
	{
		ft_putstr("Error: mlx\n", 2);
		return (clean_env(env, 1));
	}
	env->win = mlx_new_window(env->mlx, WIN_W, WIN_H, "miniRT");
	if (!env->win)
	{
		ft_putstr("Error: mlx\n", 2);
		return (clean_env(env, 1));
	}
	env->img.img = mlx_new_image(env->mlx, WIN_W, WIN_H);
	if (!env->img.img)
	{
		ft_putstr("Error: mlx\n", 2);
		return (clean_env(env, 1));
	}
	return (0);
}
