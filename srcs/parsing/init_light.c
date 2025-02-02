/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:23:59 by achantra          #+#    #+#             */
/*   Updated: 2025/02/02 16:12:53 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
- L(u)
		∗ x,y,z coordinates of the light point: -40.0,50.0,0.0
		∗ the light brightness ratio in range [0.0,1.0]: 0.6
		∗ (unused in mandatory part)R,G,B colors in range [0-255]: 10, 0, 255
*/

t_light	*init_light(void)
{
	t_light	*light;

	light = malloc(sizeof(t_light));
	if (!light)
		return (NULL);
	light->coord = NULL;
	light->color = NULL;
	return (light);
}

int	new_light(t_env *env, char **data)
{
	t_light	*light;

	if (env->light)
		return (ft_free_tab(data), print_data_err("double L"), 1);
	if (len_tab(data) != 4)
		return (ft_free_tab(data), print_data_err("L"), 1);
	light = init_light();
	if (!light)
		return (ft_free_tab(data), perror("Error"), 1);
	light->coord = parse_coordinates(data[1]);
	if (!light->coord)
		return (clean_light(light), ft_free_tab(data), 1);
	light->bright = parse_ratio(data[2]);
	if (light->bright < 0)
		return (clean_light(light), ft_free_tab(data), 1);
	light->color = parse_color(data[3]);
	if (!light->color)
		return (clean_light(light), ft_free_tab(data), 1);
	env->light = light;
	return (ft_free_tab(data), 0);
}
