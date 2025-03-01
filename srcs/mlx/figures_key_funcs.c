/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures_key_funcs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:24:45 by mgalvez           #+#    #+#             */
/*   Updated: 2025/03/01 18:08:39 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	ft_rotate_figure(int keysym, t_env *env, t_element *figure)
{
	t_coordinates	lerp;

	if (keysym == XK_Up)
		lerp = sub_vec(&figure->vector, &figure->vector_up);
	if (keysym == XK_Down)
		lerp = sub_vec(&figure->vector_up, &figure->vector);
	if (keysym == XK_Up || keysym == XK_Down)
	{
		lerp = mult_vec(&lerp, 0.1);
		figure->vector_up = add_vec(&figure->vector_up, &lerp);
		normalize_vec(&figure->vector_up);
	}
	if (keysym == XK_Left)
		lerp = sub_vec(&figure->vector, &figure->vector_right);
	if (keysym == XK_Right)
		lerp = sub_vec(&figure->vector_right, &figure->vector);
	if (keysym == XK_Left || keysym == XK_Right)
	{
		lerp = mult_vec(&lerp, 0.1);
		figure->vector_right = add_vec(&figure->vector_right, &lerp);
		normalize_vec(&figure->vector_right);
	}
	figure->vector = vect_prod_vec(&figure->vector_right, &figure->vector_up);
	normalize_vec(&figure->vector);
}

static void	ft_translate_figure(int keysym, t_env *env, t_element *figure)
{
	if (keysym == XK_a)
		double_decrement(&figure->coord.x);
	if (keysym == XK_d)
		double_increment(&figure->coord.x);
	if (keysym == XK_q)
		double_decrement(&figure->coord.y);
	if (keysym == XK_e)
		double_increment(&figure->coord.y);
	if (keysym == XK_s)
		double_decrement(&figure->coord.z);
	if (keysym == XK_w)
		double_increment(&figure->coord.z);
}

static void	ft_change_height(int keysym, t_env *env, t_element *figure)
{
	if (keysym == XK_KP_Divide && !equal_double(figure->height, 1))
	{
		double_decrement(&figure->height);
		if (figure->height < 1)
			figure->height = 1;
	}
	if (keysym == XK_KP_Multiply)
		double_increment(&figure->height);
}

static void	ft_change_diameter(int keysym, t_env *env, t_element *figure)
{
	if (keysym == XK_KP_Subtract && !equal_double(figure->diameter, 1))
	{
		double_decrement(&figure->diameter);
		if (figure->diameter < 1)
			figure->diameter = 1;
	}
	if (keysym == XK_KP_Add)
		double_increment(&figure->diameter);
	figure->radius = figure->diameter / 2;
}

void	move_object(int keysym, t_env *env)
{
	t_element	*figure;

	figure = find_selected_object(env);
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
	if (figure->id == CYLINDER)
		find_cylinder_disks(figure);
}
