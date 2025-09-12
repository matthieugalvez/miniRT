/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_ray_tracing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:08:44 by achantra          #+#    #+#             */
/*   Updated: 2025/09/11 19:22:51 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	init_hitpoint(t_env *env, t_hitpoint *hitpoint, double distance)
{
	t_ray			*ray;

	ray = &env->camera.ray;
	hitpoint->coord.x = distance * ray->direction.x + ray->origin.x;
	hitpoint->coord.y = distance * ray->direction.y + ray->origin.y;
	hitpoint->coord.z = distance * ray->direction.z + ray->origin.z;
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
			figure->cam_intersec_type = figure->intersec_type;
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
	t_coordinates	buf_vec_x;
	t_coordinates	buf_vec_y;

	vector.x = (((2 * (i + 0.5)) / WIN_W) - 1) * env->vp_w / 2;
	vector.y = (1 - (2 * (j + 0.5)) / WIN_H) * env->vp_h / 2;
	vector.z = env->camera.dir.z;
	buf_vec_x = mult_vec(&env->camera.dir_right, vector.x);
	buf_vec_x = add_vec(&env->camera.dir, &buf_vec_x);
	buf_vec_y = mult_vec(&env->camera.dir_up, vector.y);
	vector = add_vec(&buf_vec_x, &buf_vec_y);
	normalize_vec(&vector);
	env->camera.ray.direction = vector;
}

int	draw_image(t_env *env)
{
	int				i;
	int				j;
	int				color;
	t_coordinates	direction;

	env->camera.ray.origin = env->camera.coord;
	env->camera.ray.direction = direction;
	j = 0;
	while (j < WIN_H)
	{
		i = 0;
		while (i < WIN_W)
		{
			find_ray_direction(i, j, env);
			color = get_color(env, &env->camera.ray);
			my_pixel_put(i, j, env, color);
			i++;
		}
		j++;
	}
	return (0);
}
