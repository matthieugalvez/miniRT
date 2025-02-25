/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:55:30 by achantra          #+#    #+#             */
/*   Updated: 2025/02/25 15:50:30 by mgalvez          ###   ########.fr       */
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

static void	ft_select(int keysym, t_env *env)
{
	int			i;
	t_element	*current_figure;

	if (keysym == XK_Return)
	{
		env->selected_object = 0;
		return ;
	}
	env->selected_object += 1;
	i = 0;
	current_figure = env->figure;
	while (i < env->selected_object)
	{
		if (!current_figure)
		{
			env->selected_object = 0;
			return ;
		}
		current_figure = current_figure->next;
		i++;
	}
	return ;
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
		move_camera(keysym, env);
	else
		move_object(keysym, env);
	return (print_image(env));
}
