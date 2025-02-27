/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_ray_tracing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:08:44 by achantra          #+#    #+#             */
/*   Updated: 2025/02/27 14:19:02 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static void	init_hitpoint(t_env *env, t_hitpoint *hitpoint, double distance)
{
	t_ray			*ray;

	hitpoint->coord = ft_calloc(sizeof(t_coordinates), 1);
	if (!hitpoint->coord)
		clean_env(env, 1);
	ray = env->camera->ray;
	hitpoint->coord->x = distance * ray->direction->x + ray->origin->x;
	hitpoint->coord->y = distance * ray->direction->y + ray->origin->y;
	hitpoint->coord->z = distance * ray->direction->z + ray->origin->z;
}

static int	get_color(t_env *env, t_ray *ray)
{
	t_element		*figure;
	int				color;
	double			distance;
	double			intersec;
	t_hitpoint		hitpoint;

	figure = env->figure;
	color = 0;
	distance = __DBL_MAX__;
	while (figure)
	{
		intersec = find_intsec(ray, figure);
		if (intersec < distance - EPSILON)
		{
			distance = intersec;
			init_hitpoint(env, &hitpoint, distance);
			find_hitpoint_color(&hitpoint, figure);
			color = apply_light(env, figure, &hitpoint);
		}
		figure = figure->next;
	}
	return (color);
}

static void	find_ray_direction(int i, int j, t_env *env)
{
	t_coordinates	vector;

	vector.x = (((2 * (i + 0.5)) / WIN_W) - 1) * env->vp_w / 2;
	vector.y = (1 - (2 * (j + 0.5)) / WIN_H) * env->vp_h / 2;
	vector.z = -1;
	vector = add_vec(mult_vec(*(env->camera->dir_up), vector.y),
			add_vec(*(env->camera->dir), mult_vec(*(env->camera->dir_right),
					vector.x)));
	normalize_vec(&vector);
	*(env->camera->ray->direction) = vector;
}

int	draw_image(t_env *env)
{
	int				i;
	int				j;
	int				color;
	t_ray			ray;
	t_coordinates	direction;

	ray.origin = env->camera->coord;
	ray.direction = &direction;
	env->camera->ray = &ray;
	j = 0;
	while (j < WIN_H)
	{
		i = 0;
		while (i < WIN_W)
		{
			find_ray_direction(i, j, env);
			color = get_color(env, &ray);
			my_pixel_put(i, j, env, color);
			i++;
		}
		j++;
	}
	return (0);
}
