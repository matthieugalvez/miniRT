/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:50:45 by achantra          #+#    #+#             */
/*   Updated: 2025/02/28 13:56:12 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static int	init_cone(t_element *cone, t_env *env, char **data)
{
	if (data[6])
		cone->colorbis = parse_color(data[6]);
	if (!cone->coord || !cone->vector || !cone->color
		|| (data[6] && !cone->colorbis))
	{
		clean_figure(cone);
		ft_freetab(data);
		return (1);
	}
	normalize_vec(cone->vector);
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
	find_cone_disk(cone);
	add_back_elem(&env->figure, cone);
	ft_freetab(data);
	return (find_vectors(cone));
}

int	new_cone(t_env *env, char **data)
{
	t_element	*cone;

	if (ft_tablen(data) < 6 || ft_tablen(data) > 7)
	{
		ft_freetab(data);
		ft_putstr("Error: wrong data: cone\n", 2);
		return (1);
	}
	cone = ft_calloc(sizeof(t_element), 1);
	if (!cone)
	{
		ft_freetab(data);
		perror("Error");
		return (1);
	}
	cone->id = CONE;
	cone->coord = parse_coordinates(data[1]);
	cone->vector = parse_vector(data[2]);
	cone->color = parse_color(data[5]);
	return (init_cone(cone, env, data));
}
