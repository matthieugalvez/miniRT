/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_key_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez <mgalvez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:05:03 by mgalvez           #+#    #+#             */
/*   Updated: 2025/09/11 19:27:45 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	ft_translate_light(int keysym, t_light *light)
{
	if (keysym == XK_j)
		double_decrement(&light->coord.x);
	if (keysym == XK_l)
		double_increment(&light->coord.x);
	if (keysym == XK_u)
		double_decrement(&light->coord.y);
	if (keysym == XK_o)
		double_increment(&light->coord.y);
	if (keysym == XK_k)
		double_decrement(&light->coord.z);
	if (keysym == XK_i)
		double_increment(&light->coord.z);
}

static void	ft_dim(int keysym, t_light *light)
{
	if (keysym == XK_semicolon && !equal_double(light->bright, 0))
	{
		light->bright -= 0.1;
		if (light->bright < 0)
			light->bright = 0;
	}
	if (keysym == XK_p && !equal_double(light->bright, 1))
	{
		light->bright += 0.1;
		if (light->bright > 1)
			light->bright = 1;
	}
}

void	move_light(int keysym, t_env *env)
{
	t_light	*light;
	int		i;

	light = env->light;
	i = 0;
	while (i < env->selected_light)
	{
		light = light->next;
		i++;
	}
	if (keysym == XK_i || keysym == XK_k
		|| keysym == XK_j || keysym == XK_l
		|| keysym == XK_u || keysym == XK_o)
		ft_translate_light(keysym, light);
	else if (keysym == XK_p || keysym == XK_semicolon)
		ft_dim(keysym, light);
}
