/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_ray_tracing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:08:44 by achantra          #+#    #+#             */
/*   Updated: 2025/02/06 13:35:11 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	find_ray_direction(int i, int j, t_env *env, t_ray *ray)
{
	t_coordinates	*vector;

	vector = malloc(sizeof(t_coordinates));
	if (!vector)
		return (1);
	vector->x = (((2 * (i + 0.5)) / WIN_W) - 1) * env->vp_w / 2;
	vector->y = (1 - (2 * (j + 0.5)) / WIN_H) * env->vp_h / 2;
	vector->z = -1;
	*(vector) = add_vec(multiply_vec(*(env->camera->dir_up), vector->y),
			add_vec(*(env->camera->dir), multiply_vec(*(env->camera->dir_right),
					vector->x)));
	ray->direction = vector;
	return (0);
}

void	my_pixel_put(int i, int j, t_env *env, t_ray *ray)
{
	int			offset;
	t_element	*buf;

	if (j >= WIN_H || i >= WIN_W || i < 0 || j < 0)
		return ;
	offset = (env->img.line_len * j) + (i * (env->img.bits_per_pixel / 8));
	buf = env->form;
	while (buf)
	{
		if (buf->id == SPHERE)
		{
			if (intersect_sphere(env, buf, ray))
				*((unsigned int *)((env->img).img_pixels
							+ offset)) = rgb_to_hexa(buf->color);
		}
		buf = buf->next;
	}
}

int	color_image(t_env *env)
{
	int		i;
	int		j;
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	if (!ray)
		return (perror("Error:"), clean_env(env));
	ray->origin = env->camera->coord;
	i = 0;
	while (i < WIN_W)
	{
		j = 0;
		while (j < WIN_H)
		{
			if (find_ray_direction(i, j, env, ray))
				return (free(ray), perror("Error:"), clean_env_err(env));
			my_pixel_put(i, j, env, ray);
			j++;
		}
		i++;
	}
	return (free(ray->direction), free(ray), 0);
}
