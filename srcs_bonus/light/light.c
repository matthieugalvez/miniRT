/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:33:10 by mgalvez           #+#    #+#             */
/*   Updated: 2025/02/26 18:14:24 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static void	get_ambiant(t_color *color, t_amb *amb, t_color *hitpoint_color)
{
	color->r = (hitpoint_color->r * (amb->color->r * amb->bright * 0.5)) / 255;
	color->g = (hitpoint_color->g * (amb->color->g * amb->bright * 0.5)) / 255;
	color->b = (hitpoint_color->b * (amb->color->b * amb->bright * 0.5)) / 255;
	if (color->r > 255)
		color->r = 255;
	if (color->g > 255)
		color->g = 255;
	if (color->b > 255)
		color->b = 255;
}

int	apply_light(t_env *env, t_element *figure,
		t_hitpoint *hitpoint)
{
	t_color			color;
	t_color			new_color;
	t_light			*light;

	color = *hitpoint->color;
	get_ambiant(&color, env->amb, hitpoint->color);
	light = env->light;
	while (light)
	{
		new_color = compute_light_source(env, hitpoint, figure, light);
		color.r += new_color.r;
		color.g += new_color.g;
		color.b += new_color.b;
		light = light->next;
	}
	if (color.r > 255)
		color.r = 255;
	if (color.g > 255)
		color.g = 255;
	if (color.b > 255)
		color.b = 255;
	free(hitpoint->coord);
	return (rgb_to_hexa(&color));
}
