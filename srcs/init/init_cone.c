/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:50:45 by achantra          #+#    #+#             */
/*   Updated: 2025/09/11 19:25:04 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	init_figure(t_element *figure, t_env *env, char **data)
{
	if (parse_figure_color_data(figure, env, data[5]))
	{
		clean_figure(env, figure);
		ft_freetab(data);
		return (1);
	}
	if (data[6] && parse_figure_color_data(figure, env, data[6]))
	{
		clean_figure(env, figure);
		ft_freetab(data);
		return (1);
	}
	find_disks(figure);
	add_back_elem(&env->figure, figure);
	ft_freetab(data);
	return (find_vectors(figure));
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
	cone->diameter = parse_length(data[3]);
	cone->radius = cone->diameter / 2;
	cone->height = parse_length(data[4]);
	if (ft_tablen(data) < 6 || ft_tablen(data) > 7
		||parse_coordinates(data[1], &cone->coord)
		|| parse_vector(data[2], &cone->vector)
		|| cone->diameter <= 0 || cone->height <= 0)
	{
		clean_figure(env, cone);
		ft_freetab(data);
		ft_putstr("Error: wrong data: cone\n", 2);
		return (1);
	}
	normalize_vec(&cone->vector);
	return (init_figure(cone, env, data));
}

int	new_cylinder(t_env *env, char **data)
{
	t_element	*cylinder;

	cylinder = ft_calloc(sizeof(t_element), 1);
	if (!cylinder)
	{
		ft_freetab(data);
		perror("Error");
		return (1);
	}
	cylinder->id = CYLINDER;
	cylinder->diameter = parse_length(data[3]);
	cylinder->radius = cylinder->diameter / 2;
	cylinder->height = parse_length(data[4]);
	if (ft_tablen(data) < 6 || ft_tablen(data) > 7
		||parse_coordinates(data[1], &cylinder->coord)
		|| parse_vector(data[2], &cylinder->vector)
		|| cylinder->diameter <= 0 || cylinder->height <= 0)
	{
		clean_figure(env, cylinder);
		ft_freetab(data);
		ft_putstr("Error: wrong data: cylinder\n", 2);
		return (1);
	}
	normalize_vec(&cylinder->vector);
	return (init_figure(cylinder, env, data));
}
