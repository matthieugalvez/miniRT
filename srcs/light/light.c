/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez <mgalvez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:33:10 by mgalvez           #+#    #+#             */
/*   Updated: 2025/02/15 19:21:39 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	apply_specular_ref(t_color *color, t_light *light,
				t_ray *ray, t_element *figure)
{
}

static void	apply_diffuse_ref(t_color *color, t_light *light,
				t_ray *ray, t_element *figure)
{
	double	distance;

	distance = __DBL_MAX__;
	figure->c_inter[0] = __DBL_MAX__;
	figure->c_inter[1] = __DBL_MAX__;
	if (figure->id == SPHERE)
		intersect_sphere(figure, ray);
	if (figure->c_inter[0] < distance)
		distance = figure->c_inter[0];
	if (figure->c_inter[1] < distance)
		distance = figure->c_inter[1];
	if (distance < __DBL_MAX__)
	{
		color->r = color->r + (light->color->r * light->bright);
		color->g = color->g + (light->color->g * light->bright);
		color->b = color->b + (light->color->b * light->bright);
	}
}

static void	apply_ambiant(t_color *color, t_amb *amb)
{
	color->r = ((color->r * amb->color->r) / 255) * amb->bright;
	color->g = ((color->g * amb->color->g) / 255) * amb->bright;
	color->b = ((color->b * amb->color->b) / 255) * amb->bright;
}

static t_coordinates	find_lightray_dir(t_env *env, t_ray *ray)
{
	t_coordinates	cam_to_light_vec;

	cam_to_light_vec = sub_vec(*env->camera->coord, *env->light->coord);
	return (add_vec(cam_to_light_vec, *ray->direction));
}

void	apply_light(t_env *env, t_ray *ray, t_element *figure, t_color *color)
{
	t_ray			light_ray;
	t_coordinates	origin;
	t_coordinates	direction;

	origin = *env->light->coord;
	direction = find_lightray_dir(env, ray);
	light_ray.origin = &origin;
	light_ray.direction = &direction;
	apply_ambiant(color, env->amb);
	apply_diffuse_ref(color, env->light, &light_ray, figure);
	apply_specular_ref(color, env->light, &light_ray, figure);
}
