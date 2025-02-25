/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_key_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez <mgalvez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:05:03 by mgalvez           #+#    #+#             */
/*   Updated: 2025/02/25 14:05:21 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ft_translate_light(int keysym, t_env *env)
{
	if (keysym == XK_j)
		env->light->coord->x -= 1;
	if (keysym == XK_l)
		env->light->coord->x += 1;
	if (keysym == XK_u)
		env->light->coord->y -= 1;
	if (keysym == XK_o)
		env->light->coord->y += 1;
	if (keysym == XK_k)
		env->light->coord->z -= 1;
	if (keysym == XK_i)
		env->light->coord->z += 1;
}

void	ft_dim(int keysym, t_env *env)
{
	if (keysym == XK_semicolon && env->light->bright > 0)
		env->light->bright -= 0.1;
	if (keysym == XK_p && env->light->bright < 1)
		env->light->bright += 0.1;
}
