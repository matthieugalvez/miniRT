/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:39:22 by achantra          #+#    #+#             */
/*   Updated: 2025/02/04 22:19:22 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	rgb_to_hexa(t_color *color)
{
	return (color->r << 16 | color->g << 8 | color->b);
}

void	find_ray_direction(int i, int j, t_env *env, t_coordinates *vector)
{
	vector->x = (((2 * (i + 0.5)) / WIN_W) - 1) * env->vp_w / 2;
	vector->y = (1 - (2 * (j + 0.5)) / WIN_H) * env->vp_h / 2;
	vector->z = -1;
	*(vector) = add_vec(multiply_vec(*(env->camera->dir_up), vector->y),
			add_vec(*(env->camera->dir),
				multiply_vec(*(env->camera->dir_right), vector->x)));
}

void	my_pixel_put(int i, int j, t_env *env, t_ray *ray)
{
	int			offset;
	t_element	*buf;

	if (j >= WIN_H || i >= WIN_W || i < 0 || j < 0)
		return ;
	offset = (env->img.line_len * j) + (i * (env->img.bits_per_pixel / 8));
	buf = env->elem;
	while (buf)
	{
		if (buf->id == SPHERE)
		{
			if (intersect_sphere(buf, ray))
				*((unsigned int *)((env->img).img_pixels
							+ offset)) = rgb_to_hexa(buf->color);
		}
		buf = buf->next;
	}
}

int	color_image(t_env *env)
{
	int				i;
	int				j;
	t_coordinates	*vector;
	t_ray			*ray;

	ray = malloc(sizeof(t_ray));
	vector = malloc(sizeof(t_coordinates));
	if (!env->amb || !env->camera || !env->light)
		return (1);
	i = 0;
	while (i < WIN_W)
	{
		j = 0;
		while (j < WIN_H)
		{
			ray->origin = env->camera->coord;
			find_ray_direction(i, j, env, vector);
			ray->direction = vector;
			my_pixel_put(i, j, env, ray);
			j++;
		}
		i++;
	}
	return (free(vector), free(ray), 0);
}
