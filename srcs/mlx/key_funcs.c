/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez <mgalvez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 09:26:30 by mgalvez           #+#    #+#             */
/*   Updated: 2025/09/11 19:27:40 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	ft_select_object(int keysym, t_env *env)
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

static void	ft_select_light(t_env *env)
{
	int			i;
	t_light		*current_light;

	env->selected_light += 1;
	i = 0;
	current_light = env->light;
	while (i <= env->selected_light)
	{
		if (!current_light)
		{
			env->selected_light = 0;
			return ;
		}
		current_light = current_light->next;
		i++;
	}
	return ;
}

static void	ft_toggle_help(t_env *env)
{
	if (!env->help)
		env->help = 1;
	else
		env->help = 0;
}

int	ft_key(int keysym, t_env *env)
{
	if (keysym == XK_Escape)
		return (clean_env(env, 0));
	else if (keysym == XK_Tab)
		ft_toggle_help(env);
	else if (keysym == XK_m)
		ft_select_light(env);
	else if (keysym == XK_space || keysym == XK_Return)
		ft_select_object(keysym, env);
	else if (keysym == XK_i || keysym == XK_k
		|| keysym == XK_j || keysym == XK_l
		|| keysym == XK_u || keysym == XK_o
		|| keysym == XK_p || keysym == XK_semicolon)
		move_light(keysym, env);
	else if (!env->selected_object)
		move_camera(keysym, env);
	else
		move_object(keysym, env);
	return (print_image(env));
}
