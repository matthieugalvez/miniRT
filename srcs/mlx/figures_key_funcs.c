/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures_key_funcs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:24:45 by mgalvez           #+#    #+#             */
/*   Updated: 2025/02/25 15:03:33 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	ft_rotate_figure(int keysym, t_env *env, t_element *figure)
{
	if (keysym == XK_Right)
		figure->vector->x -= 0.1;
	if (keysym == XK_Left)
		figure->vector->x += 0.1;
	if (keysym == XK_Up)
		figure->vector->y -= 0.1;
	if (keysym == XK_Down)
		figure->vector->y += 0.1;
	normalize_vec(figure->vector);
}

static void	ft_translate_figure(int keysym, t_env *env, t_element *figure)
{
	if (keysym == XK_a)
		figure->coord->x -= 0.1;
	if (keysym == XK_d)
		figure->coord->x += 0.1;
	if (keysym == XK_q)
		figure->coord->y -= 0.1;
	if (keysym == XK_e)
		figure->coord->y += 0.1;
	if (keysym == XK_s)
		figure->coord->z -= 0.1;
	if (keysym == XK_w)
		figure->coord->z += 0.1;
}

static void	ft_change_height(int keysym, t_env *env, t_element *figure)
{
	if (keysym == XK_KP_Divide && figure->height > 0)
			figure->height--;
	if (keysym == XK_KP_Multiply && figure->height < __DBL_MAX__)
			figure->height++;
}

static void	ft_change_diameter(int keysym, t_env *env, t_element *figure)
{
	if (keysym == XK_KP_Subtract && figure->diameter > 0)
		figure->diameter--;
	if (keysym == XK_KP_Add && figure->diameter < __DBL_MAX__)
		figure->diameter++;
}

void	move_object(int keysym, t_env *env)
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
	if ((keysym == XK_KP_Add || keysym == XK_KP_Subtract)
		&& figure->id != PLANE)
		ft_change_diameter(keysym, env, figure);
	else if ((keysym == XK_KP_Divide || keysym == XK_KP_Multiply)
		&& figure->id == CYLINDER)
		ft_change_height(keysym, env, figure);
	else if (keysym == XK_w || keysym == XK_a
		|| keysym == XK_s || keysym == XK_d
		|| keysym == XK_q || keysym == XK_e)
		ft_translate_figure(keysym, env, figure);
	else if (keysym >= XK_Left && keysym <= XK_Down && figure->id != SPHERE)
		ft_rotate_figure(keysym, env, figure);
}
