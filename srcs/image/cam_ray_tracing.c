/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_ray_tracing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:08:44 by achantra          #+#    #+#             */
/*   Updated: 2025/02/20 13:42:14 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	find_hitpoint(t_coordinates *hitpoint, t_ray *ray, double distance)
{
	hitpoint->x = distance * ray->direction->x + ray->origin->x;
	hitpoint->y = distance * ray->direction->y + ray->origin->y;
	hitpoint->z = distance * ray->direction->z + ray->origin->z;
}

static int	get_color(t_env *env, t_ray *ray)
{
	t_element		*figure;
	int				color;
	double			distance;
	double			intersec;
	t_coordinates	hitpoint;

	figure = env->figure;
	color = 0;
	distance = __DBL_MAX__;
	while (figure)
	{
		intersec = find_intsec(ray, figure);
		if (!equal_double(intersec, distance) && intersec < distance)
		{
			distance = intersec;
			find_hitpoint(&hitpoint, ray, distance);
			color = apply_light(env, ray, figure, &hitpoint);
		}
		figure = figure->next;
	}
	return (color);
}

static void	find_ray_direction(int i, int j, t_env *env, t_coordinates *dir)
{
	double	x_dir;
	double	y_dir;

	x_dir = (((2 * (i + 0.5)) / WIN_W) - 1) * env->vp_w / 2;
	dir->x = env->camera->dir->x + x_dir;
	y_dir = (1 - (2 * (j + 0.5)) / WIN_H) * env->vp_h / 2;
	dir->y = env->camera->dir->y + y_dir;
	dir->z = env->camera->dir->z;
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
	j = 0;
	while (j < WIN_W)
	{
		i = 0;
		while (i < WIN_H)
		{
			find_ray_direction(i, j, env, &direction);
			color = get_color(env, &ray);
			my_pixel_put(i, j, env, color);
			ft_bzero(&direction, sizeof(t_coordinates));
			i++;
		}
		j++;
	}
	return (0);
}
