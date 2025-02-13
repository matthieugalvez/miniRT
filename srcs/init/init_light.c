/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:23:59 by achantra          #+#    #+#             */
/*   Updated: 2025/02/13 13:39:17 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
- L(u)
		∗ x,y,z coordinates of the light point: -40.0,50.0,0.0
		∗ the light brightness ratio in range [0.0,1.0]: 0.6
		∗ (unused in mandatory part)R,G,B colors in range [0-255]: 10, 0, 255
*/

static int	init_light(t_light *light, char **data)
{
	light->coord = parse_coordinates(data[1]);
	if (!light->coord)
	{
		clean_light(light);
		ft_freetab(data);
		return (1);
	}
	light->bright = parse_ratio(data[2]);
	if (light->bright < 0)
	{
		clean_light(light);
		ft_freetab(data);
		return (1);
	}
	light->color = parse_color(data[3]);
	if (!light->color)
	{
		clean_light(light);
		ft_freetab(data);
		return (1);
	}
	return (0);
}

int	new_light(t_env *env, char **data)
{
	t_light	*light;

	if (env->light || ft_tablen(data) != 4)
	{
		ft_freetab(data);
		ft_putstr("Error: wrong data: light source\n", 2);
		return (1);
	}
	light = ft_calloc(sizeof(t_light), 1);
	if (!light)
	{
		ft_freetab(data);
		perror("Error");
		return (1);
	}
	if (init_light(light, data))
		return (1);
	env->light = light;
	ft_freetab(data);
	return (0);
}
