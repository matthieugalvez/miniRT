/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez <mgalvez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:50:41 by mgalvez           #+#    #+#             */
/*   Updated: 2025/02/28 14:01:05 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static int	find_object_id(t_env *env, char *str)
{
	t_element	*figure;

	figure = find_selected_object(env);
	if (!figure->id)
		str = ft_strjoin_free(str, ". Sphere", 1);
	if (figure->id == 1)
		str = ft_strjoin_free(str, ". Plane", 1);
	if (figure->id == 2)
		str = ft_strjoin_free(str, ". Cylinder", 1);
	if (figure->id == 3)
		str = ft_strjoin_free(str, ". Cone", 1);
	if (!str)
		return (clean_env(env, 1));
	mlx_string_put(env->mlx, env->win, WIN_W - 175, WIN_H - 25, 0xffffff, str);
	free(str);
	return (0);
}

int	print_selected_object(t_env *env)
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

int	print_selected_light(t_env *env)
{
	char		*str;
	char		*itoa_str;

	str = ft_calloc(sizeof(char), 1);
	if (!str)
		return (clean_env(env, 1));
	str = ft_strjoin_free(str, "Selected light: ", 1);
	if (!str)
		return (clean_env(env, 1));
	itoa_str = ft_itoa(env->selected_light + 1);
	if (!itoa_str)
	{
		free(str);
		return (clean_env(env, 1));
	}
	str = ft_strjoin_free(str, itoa_str, 3);
	if (!str)
		return (clean_env(env, 1));
	mlx_string_put(env->mlx, env->win, WIN_W - 115, 10, 0xffffff, str);
	free(str);
	return (0);
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
		"/*: Change object height (cylinder/cone only)");
	mlx_string_put(env->mlx, env->win, 0, 145, 0xffffff,
		"m: Select next light source");
	mlx_string_put(env->mlx, env->win, 0, 160, 0xffffff,
		"ijkl: Translate selected light source");
	mlx_string_put(env->mlx, env->win, 0, 175, 0xffffff,
		"uo: Change selected light source elevation");
	mlx_string_put(env->mlx, env->win, 0, 190, 0xffffff,
		";p: Dim selected light source down/up");
}

void	check_help(t_env *env)
{
	if (!env->help)
		mlx_string_put(env->mlx, env->win, 0, 10, 0xffffff,
			"Press 'Tab' to show keys");
	else
		print_help(env);
}
