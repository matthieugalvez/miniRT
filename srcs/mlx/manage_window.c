/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:55:30 by achantra          #+#    #+#             */
/*   Updated: 2025/02/26 10:01:48 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	find_object_id(t_env *env, char *str)
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
	if (!figure->id)
		str = ft_strjoin_free(str, ". Sphere", 1);
	if (figure->id == 1)
		str = ft_strjoin_free(str, ". Plane", 1);
	if (figure->id == 2)
		str = ft_strjoin_free(str, ". Cylinder", 1);
	if (!str)
		return (clean_env(env, 1));
	mlx_string_put(env->mlx, env->win, WIN_W - 175, WIN_H - 25, 0xffffff, str);
	free(str);
	return (0);
}

static int	print_selected_object(t_env *env)
{
	char		*str;
	char		*itoa_str;

	str = ft_calloc(sizeof(char), 1);
	if (!str)
		return (clean_env(env, 1));
	str = ft_strjoin_free(str, "Selected object: ", 1);
	if (!str)
		return (clean_env(env, 1));
	itoa_str = ft_itoa(env->selected_object);
	if (!itoa_str)
	{
		free(str);
		return (clean_env(env, 1));
	}
	str = ft_strjoin_free(str, itoa_str, 3);
	if (!str)
		return (clean_env(env, 1));
	return (find_object_id(env, str));
}

static void	print_help(t_env *env)
{
	mlx_string_put(env->mlx, env->win, 0, 10, 0xffffff, "Esc: Close window");
	mlx_string_put(env->mlx, env->win, 0, 25, 0xffffff, "Tab: Toggle help");
	mlx_string_put(env->mlx, env->win, 0, 40, 0xffffff,
		"Space: Select next object");
	mlx_string_put(env->mlx, env->win, 0, 55, 0xffffff,
		"Return: Select camera");
	mlx_string_put(env->mlx, env->win, 0, 70, 0xffffff,
		"wasd: Translate selected object");
	mlx_string_put(env->mlx, env->win, 0, 85, 0xffffff,
		"qe: Change selected object elevation");
	mlx_string_put(env->mlx, env->win, 0, 100, 0xffffff,
		"Arrows: Rotate selected object");
	mlx_string_put(env->mlx, env->win, 0, 115, 0xffffff,
		"-+: Resize selected object / change cam FoV");
	mlx_string_put(env->mlx, env->win, 0, 130, 0xffffff,
		"/*: Change object lenght (cylinder only)");
	mlx_string_put(env->mlx, env->win, 0, 145, 0xffffff,
		"ijkl: Translate light source");
	mlx_string_put(env->mlx, env->win, 0, 160, 0xffffff,
		"uo: Change light source elevation");
	mlx_string_put(env->mlx, env->win, 0, 175, 0xffffff,
		";p: Dim light source down/up");
}

static void	check_help(t_env *env)
{
	if (!env->help)
		mlx_string_put(env->mlx, env->win, 0, 10, 0xffffff,
			"Press 'Tab' to show keys");
	else
		print_help(env);
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
	check_help(env);
	if (env->selected_object)
		print_selected_object(env);
	return (0);
}
