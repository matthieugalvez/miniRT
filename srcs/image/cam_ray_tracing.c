/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_ray_tracing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:08:44 by achantra          #+#    #+#             */
/*   Updated: 2025/02/12 18:19:46 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	find_ray_direction(int i, int j, t_env *env, t_ray *ray)
{
	t_coordinates	*vector;

	vector = ft_calloc(sizeof(t_coordinates), 1);
	if (!vector)
		return (1);
	vector->x = (((2 * (i + 0.5)) / WIN_W) - 1) * env->vp_w / 2;
	vector->y = (1 - (2 * (j + 0.5)) / WIN_H) * env->vp_h / 2;
	vector->z = -1;
	*(vector) = add_vec(mult_vec(*(env->camera->dir_up), vector->y),
			add_vec(*(env->camera->dir), mult_vec(*(env->camera->dir_right),
					vector->x)));
	ray->direction = vector;
	return (0);
}

static void	first_inter(double *position, int *color, t_element *figure)
{
	if (figure->c_inter[0] >= 0 && figure->c_inter[0] < *position)
	{
		*position = figure->c_inter[0];
		*color = rgb_to_hexa(figure->color);
	}
	if (figure->c_inter[1] >= 0 && figure->c_inter[1] < *position)
	{
		*position = figure->c_inter[1];
		*color = rgb_to_hexa(figure->color);
	}
}

static int	first_color(t_env *env, t_ray *ray)
{
	t_element	*figure;
	int			color;
	double		position;

	position = __DBL_MAX__;
	color = 0;
	figure = env->figure;
	while (figure)
	{
		ft_bzero(&figure->c_inter[0], sizeof(double) * 2);
		if (figure->id == SPHERE)
			intersect_sphere(env, figure, ray);
		else if (figure->id == CYLINDER)
			intersect_cylinder(env, figure, ray);
		/*else if (figure->id == PLANE)
			intersect_plane(env, figure, ray);*/
		first_inter(&position, &color, figure);
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

int	color_image(t_env *env)
{
	int		i;
	int		j;
	t_ray	*ray;

	ray = ft_calloc(sizeof(t_ray), 1);
	if (!ray)
		return (perror("Error"), clean_env(env, 1));
	ray->origin = env->camera->coord;
	i = 0;
	while (i < WIN_W)
	{
		j = 0;
		while (j < WIN_H)
		{
			if (find_ray_direction(i, j, env, ray))
				return (free(ray), perror("Error"), clean_env(env, 1));
			my_pixel_put(i, j, env, ray);
			free(ray->direction);
			j++;
		}
		i++;
	}
	return (free(ray), 0);
}
