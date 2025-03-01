/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:50:45 by achantra          #+#    #+#             */
/*   Updated: 2025/03/01 17:39:54 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static int	init_cone(t_element *cone, t_env *env, char **data)
{
	if (data[6])
	{
		if (parse_color(data[6], &cone->colorbis))
		{
			clean_figure(cone);
			ft_freetab(data);
			ft_putstr("Error: wrong data: cylinder\n", 2);
			return (1);
		}
		cone->color_cmpt += 1;
	}
	cone->diameter = parse_length(data[3]);
	cone->radius = cone->diameter / 2;
	cone->height = parse_length(data[4]);
	if (cone->diameter <= 0 || cone->height <= 0)
	{
		clean_figure(cone);
		ft_freetab(data);
		ft_putstr("Error: wrong data: cone\n", 2);
		return (1);
	}
	find_disks(cone);
	add_back_elem(&env->figure, cone);
	ft_freetab(data);
	return (find_vectors(cone));
}

int	new_cone(t_env *env, char **data)
{
	t_element	*cone;

	cone = ft_calloc(sizeof(t_element), 1);
	if (!cone)
	{
		ft_freetab(data);
		perror("Error");
		return (1);
	}
	cone->id = CONE;
	if (ft_tablen(data) < 6 || ft_tablen(data) > 7
		||parse_coordinates(data[1], &cone->coord)
		|| parse_vector(data[2], &cone->vector)
		|| parse_color(data[5], &cone->color))
	{
		clean_figure(cone);
		ft_freetab(data);
		ft_putstr("Error: wrong data: cone\n", 2);
		return (1);
	}
	cone->color_cmpt += 1;
	normalize_vec(&cone->vector);
	return (init_cone(cone, env, data));
}
