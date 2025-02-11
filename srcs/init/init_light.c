/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:23:59 by achantra          #+#    #+#             */
/*   Updated: 2025/02/11 20:04:51 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
- L(u)
		∗ x,y,z coordinates of the light point: -40.0,50.0,0.0
		∗ the light brightness ratio in range [0.0,1.0]: 0.6
		∗ (unused in mandatory part)R,G,B colors in range [0-255]: 10, 0, 255
*/

int	new_light(t_env *env, char **data)
{
	t_light	*light;

	if (env->light)
		return (ft_freetab(data),
			ft_putstr("Error: wrong data: double L\n", 2), 1);
	if (ft_tablen(data) != 4)
		return (ft_freetab(data), ft_putstr("Error: wrong data: L\n", 2), 1);
	light = ft_calloc(sizeof(t_light), 1);
	if (!light)
		return (ft_freetab(data), perror("Error"), 1);
	light->coord = parse_coordinates(data[1]);
	if (!light->coord)
		return (clean_light(light), ft_freetab(data), 1);
	light->bright = parse_ratio(data[2]);
	if (light->bright < 0)
		return (clean_light(light), ft_freetab(data), 1);
	light->color = parse_color(data[3]);
	if (!light->color)
		return (clean_light(light), ft_freetab(data), 1);
	env->light = light;
	return (ft_freetab(data), 0);
}
