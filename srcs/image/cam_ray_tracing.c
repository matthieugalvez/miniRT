/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_ray_tracing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:08:44 by achantra          #+#    #+#             */
/*   Updated: 2025/02/15 19:09:55 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	first_inter(t_env *env, t_ray *ray,
				double *position, t_element *figure)
{
	int		color;
	int		update_color;
	t_color	new_color;

	color = 0;
	update_color = 0;
	if (figure->c_inter[0] >= 0 && figure->c_inter[0] < *position)
	{
		*position = figure->c_inter[0];
		update_color = 1;
	}
	if (figure->c_inter[1] >= 0 && figure->c_inter[1] < *position)
	{
		*position = figure->c_inter[1];
		update_color = 1;
	}
	if (update_color == 1)
	{
		new_color = *figure->color;
		apply_light(env, ray, figure, &new_color);
		color = rgb_to_hexa(&new_color);
	}
	return (color);
}

static int	first_color(t_env *env, t_ray *ray)
{
	t_element	*figure;
	int			color;
	double		position;

	position = __DBL_MAX__;
	figure = env->figure;
	while (figure)
	{
		figure->c_inter[0] = __DBL_MAX__;
		figure->c_inter[1] = __DBL_MAX__;
		if (figure->id == SPHERE)
			intersect_sphere(figure, ray);
		else if (figure->id == CYLINDER)
			intersect_cylinder(figure, ray);
		/*else if (figure->id == PLANE)
			intersect_plane(env, figure, ray);*/
		color = first_inter(env, ray, &position, figure);
		figure = figure->next;
	}
	return (color);
}

static void	my_pixel_put(int i, int j, t_env *env, t_ray *ray)
{
	int	offset;

	if (j >= WIN_H || i >= WIN_W || i < 0 || j < 0)
		return ;
	offset = (env->img.line_len * j) + (i * (env->img.bits_per_pixel / 8));
	*((unsigned int *)((env->img).img_pixels + offset)) = first_color(env, ray);
}

static void	find_ray_direction(int i, int j, t_env *env, t_coordinates *dir)
{
	dir->x = (((2 * (i + 0.5)) / WIN_W) - 1) * env->vp_w / 2;
	dir->y = (1 - (2 * (j + 0.5)) / WIN_H) * env->vp_h / 2;
	dir->z = -1;
	*(dir) = add_vec(mult_vec(*(env->camera->dir_up), dir->y),
			add_vec(*(env->camera->dir), mult_vec(*(env->camera->dir_right),
					dir->x)));
}

int	color_image(t_env *env)
{
	int				i;
	int				j;
	t_ray			ray;
	t_coordinates	direction;

	ray.origin = env->camera->coord;
	ray.direction = &direction;
	i = 0;
	while (i < WIN_W)
	{
		j = 0;
		while (j < WIN_H)
		{
			find_ray_direction(i, j, env, &direction);
			my_pixel_put(i, j, env, &ray);
			ft_bzero(&direction, sizeof(t_coordinates));
			j++;
		}
		i++;
	}
	return (0);
}
