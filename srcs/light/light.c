/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez <mgalvez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:33:10 by mgalvez           #+#    #+#             */
/*   Updated: 2025/02/16 17:17:47 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	get_specular(t_color *color, t_light *light,
				t_ray *ray, t_element *figure)
{
}

static void	get_diffuse()
{
}

static void	get_ambiant(t_color *color, t_amb *amb)
{
	color->r = ((color->r * amb->color->r) / 255) * amb->bright;
	color->g = ((color->g * amb->color->g) / 255) * amb->bright;
	color->b = ((color->b * amb->color->b) / 255) * amb->bright;
}

static void	get_color()
{
}

static double	find_lightray_intsec(t_ray *ray, t_element *figure)
{
	double	distance;

	distance = __DBL_MAX__;
	figure->c_inter[0] = __DBL_MAX__;
	figure->c_inter[1] = __DBL_MAX__;
	if (figure->id == SPHERE)
		intersect_sphere(figure, ray);
	if (figure->id == CYLINDER)
		intersect_cylinder(figure, ray);
	if (figure->c_inter[0] < distance)
		distance = figure->c_inter[0];
	if (figure->c_inter[1] < distance)
		distance = figure->c_inter[1];
	return (distance);
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
	double			intsec_point;

	origin = *env->light->coord;
	direction = find_lightray_dir(env, ray);
	normalize_vec(&direction);
	light_ray.origin = &origin;
	light_ray.direction = &direction;
	intsec_point = find_lightray_intsec(&light_ray, figure);
}
