/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:55:30 by achantra          #+#    #+#             */
/*   Updated: 2025/02/25 14:03:36 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	print_selected_object(t_env *env)
{
	t_element	*figure;
	int			i;

	mlx_string_put(env->mlx, env->win, WIN_W - 160, WIN_H - 25,
		0xffffff, "Selected object: ");
	mlx_string_put(env->mlx, env->win, WIN_W - 60, WIN_H - 25,
		0xffffff, ft_itoa(env->selected_object));
	figure = env->figure;
	i = 1;
	while (i < env->selected_object)
	{
		figure = figure->next;
		i++;
	}
	if (!figure->id)
		mlx_string_put(env->mlx, env->win, WIN_W - 50, WIN_H - 25,
			0xffffff, "Sphere");
	if (figure->id == 1)
		mlx_string_put(env->mlx, env->win, WIN_W - 50, WIN_H - 25,
			0xffffff, "Plane");
	if (figure->id == 2)
		mlx_string_put(env->mlx, env->win, WIN_W - 50, WIN_H - 25,
			0xffffff, "Cylinder");
}

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

static int	print_image(t_env *env)
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
	if (env->selected_object)
		print_selected_object(env);
	return (0);
}

static void	move_object(int keysym, t_env *env)
{
	t_element	*figure;
	int			i;

	figure = env->figure;
	i = 1;
	while (i < env->selected_object)
	{
		figure = figure->next;
		i++;
	}
	if (keysym == XK_KP_Add || keysym == XK_KP_Subtract || figure->id != PLANE)
		ft_change_diameter(keysym, env, figure);
	if (keysym == XK_KP_Divide || keysym == XK_KP_Multiply
		|| figure->id == CYLINDER)
		ft_change_height(keysym, env, figure);
	else if (keysym == XK_w || keysym == XK_a
		|| keysym == XK_s || keysym == XK_d
		|| keysym == XK_q || keysym == XK_e)
		ft_translate_figure(keysym, env, figure);
	else if (keysym >= XK_Left && keysym <= XK_Down && figure->id != SPHERE)
		ft_rotate_figure(keysym, env, figure);
}

int	ft_key(int keysym, t_env *env)
{
	if (keysym == XK_Escape)
		return (clean_env(env, 0));
	else if (keysym == XK_space || keysym == XK_Return)
		ft_select(keysym, env);
	else if (keysym == XK_i || keysym == XK_k
		|| keysym == XK_j || keysym == XK_l
		|| keysym == XK_u || keysym == XK_o)
		ft_translate_light(keysym, env);
	else if (keysym == XK_p || keysym == XK_semicolon)
		ft_dim(keysym, env);
	else if (!env->selected_object)
	{
		if (keysym == XK_KP_Add || keysym == XK_KP_Subtract)
			ft_zoom(keysym, env);
		else if (keysym == XK_w || keysym == XK_a
			|| keysym == XK_s || keysym == XK_d)
			ft_translate(keysym, env);
		else if (keysym == XK_q || keysym == XK_e)
			ft_elevate(keysym, env);
		else if (keysym >= XK_Left && keysym <= XK_Down)
			ft_rotate(keysym, env);
	}
	else
		move_object(keysym, env);
	return (print_image(env));
}
