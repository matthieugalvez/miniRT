/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_figures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:21:35 by achantra          #+#    #+#             */
/*   Updated: 2025/03/02 15:16:03 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static int	parse_sphere_color_data(t_element *sphere, t_env *env, char *data)
{
	t_color	*next_color;

	if (!sphere->color_cmpt)
		next_color = &sphere->color;
	else if (sphere->color_cmpt == 1)
		next_color = &sphere->colorbis;
	if (!ft_strrncmp(data, ".xpm", 4))
	{
		if (!sphere->color_cmpt && !sphere->texture_cmpt)
		{
			sphere->texture_cmpt += 1;
			return (parse_xpm_file(env, &sphere->texture, data));
		}
		else
		{
			sphere->bump_map_cmpt += 1;
			return (parse_xpm_file(env, &sphere->bump_map, data));
		}
	}
	else if (parse_color(data, next_color))
		return (1);
	sphere->color_cmpt += 1;
	return (0);
}

static int	init_sphere(t_element *sphere, t_env *env, char **data)
{
	if (parse_sphere_color_data(sphere, env, data[3]))
	{
		clean_figure(env, sphere);
		ft_freetab(data);
		return (1);
	}
	if (data[4] && parse_sphere_color_data(sphere, env, data[4]))
	{
		clean_figure(env, sphere);
		ft_freetab(data);
		return (1);
	}
	ft_freetab(data);
	if (sphere->color_cmpt && sphere->texture_cmpt)
	{
		clean_figure(env, sphere);
		ft_putstr("Error: wrong data: sphere\n", 2);
		return (1);
	}
	sphere->vector = change_vec(0, 1, 0);
	add_back_elem(&env->figure, sphere);
	return (find_vectors(sphere));
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
	return (init_sphere(sphere, env, data));
}

static int	init_plan(t_element *plan, t_env *env, char **data)
{
	if (parse_coordinates(data[1], &plan->coord) || parse_color(data[3],
			&plan->color))
	{
		clean_figure(env, plan);
		ft_freetab(data);
		return (1);
	}
	plan->color_cmpt += 1;
	if (data[4])
	{
		if (parse_color(data[4], &plan->colorbis))
		{
			clean_figure(env, plan);
			ft_freetab(data);
			return (1);
		}
		plan->color_cmpt += 1;
	}
	add_back_elem(&env->figure, plan);
	ft_freetab(data);
	return (find_vectors(plan));
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
	if (parse_vector(data[2], &plane->vector))
	{
		clean_figure(env, plane);
		ft_freetab(data);
		return (1);
	}
	normalize_vec(&plane->vector);
	return (init_plan(plane, env, data));
}
