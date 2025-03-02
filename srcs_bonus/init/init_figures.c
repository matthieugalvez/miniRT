/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_figures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:21:35 by achantra          #+#    #+#             */
/*   Updated: 2025/03/02 19:06:35 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static int	parse_figure_color_data(t_element *figure, t_env *env, char *data)
{
	t_color	*next_color;

	if (!figure->color_cmpt)
		next_color = &figure->color;
	else if (figure->color_cmpt == 1)
		next_color = &figure->colorbis;
	if (!ft_strrncmp(data, ".xpm", 4))
	{
		if (!figure->color_cmpt && !figure->texture_cmpt)
		{
			figure->texture_cmpt += 1;
			return (parse_xpm_file(env, &figure->texture, data));
		}
		else if (figure-> id == SPHERE)
		{
			figure->bump_map_cmpt += 1;
			return (parse_xpm_file(env, &figure->bump_map, data));
		}
	}
	else if (parse_color(data, next_color))
		return (1);
	figure->color_cmpt += 1;
	return (0);
}

static int	init_figure(t_element *figure, t_env *env, char **data)
{
	if (parse_figure_color_data(figure, env, data[3]))
	{
		clean_figure(env, figure);
		ft_freetab(data);
		return (1);
	}
	if (data[4] && parse_figure_color_data(figure, env, data[4]))
	{
		clean_figure(env, figure);
		ft_freetab(data);
		return (1);
	}
	ft_freetab(data);
	if (figure->color_cmpt && figure->texture_cmpt)
	{
		clean_figure(env, figure);
		ft_putstr("Error: wrong data: color\n", 2);
		return (1);
	}
	add_back_elem(&env->figure, figure);
	return (find_vectors(figure));
}

int	new_sphere(t_env *env, char **data)
{
	t_element	*sphere;

	sphere = ft_calloc(sizeof(t_element), 1);
	if (!sphere)
	{
		ft_freetab(data);
		perror("Error");
		return (1);
	}
	sphere->id = SPHERE;
	sphere->diameter = parse_length(data[2]);
	if (ft_tablen(data) < 4 || ft_tablen(data) > 5 || parse_coordinates(data[1],
			&sphere->coord) || sphere->diameter <= 0)
	{
		clean_figure(env, sphere);
		ft_freetab(data);
		ft_putstr("Error: wrong data: sphere\n", 2);
		return (1);
	}
	sphere->vector = change_vec(1, 0, 0);
	return (init_figure(sphere, env, data));
}

int	new_plane(t_env *env, char **data)
{
	t_element	*plane;

	if (ft_tablen(data) < 4 || ft_tablen(data) > 5)
	{
		ft_freetab(data);
		ft_putstr("Error: wrong data: plane\n", 2);
		return (1);
	}
	plane = ft_calloc(sizeof(t_element), 1);
	if (!plane)
	{
		ft_freetab(data);
		perror("Error");
		return (1);
	}
	plane->id = PLANE;
	if (parse_coordinates(data[1], &plane->coord)
		|| parse_vector(data[2], &plane->vector))
	{
		clean_figure(env, plane);
		ft_freetab(data);
		return (1);
	}
	normalize_vec(&plane->vector);
	return (init_figure(plane, env, data));
}
