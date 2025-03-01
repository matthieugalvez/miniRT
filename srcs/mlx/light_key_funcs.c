/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_key_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez <mgalvez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:05:03 by mgalvez           #+#    #+#             */
/*   Updated: 2025/03/01 18:09:21 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ft_translate_light(int keysym, t_env *env)
{
	if (keysym == XK_j)
		double_decrement(&env->light->coord.x);
	if (keysym == XK_l)
		double_increment(&env->light->coord.x);
	if (keysym == XK_u)
		double_decrement(&env->light->coord.y);
	if (keysym == XK_o)
		double_increment(&env->light->coord.y);
	if (keysym == XK_k)
		double_decrement(&env->light->coord.z);
	if (keysym == XK_i)
		double_increment(&env->light->coord.z);
}

void	ft_dim(int keysym, t_env *env)
{
	if (keysym == XK_semicolon && !equal_double(env->light->bright, 0))
	{
		env->light->bright -= 0.1;
		if (env->light->bright < 0)
			env->light->bright = 0;
	}
	if (keysym == XK_p && !equal_double(env->light->bright, 1))
	{
		env->light->bright += 0.1;
		if (env->light->bright > 1)
			env->light->bright = 1;
	}
}
