/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez <mgalvez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:33:10 by mgalvez           #+#    #+#             */
/*   Updated: 2025/02/19 13:11:56 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"

static void	get_specular(t_color *color, t_light *light,
				t_ray *ray, t_element *figure)
{
}

static void	get_diffuse(t_light *light, t_color *color, t_color *figure_color,
				t_coordinates *normal_at_hp, t_ray *light_ray)
{
	double	cos_angle;
	t_color	applied_diffuse;

	cos_angle = scalar_prod_vec(*normal_at_hp, *light_ray->direction);
	if (cos_angle < 0)
		return ;
	applied_diffuse.r = figure_color->r * (light->color->r * light->bright);
	applied_diffuse.g = figure_color->g * (light->color->g * light->bright);
	applied_diffuse.b = figure_color->b * (light->color->b * light->bright);
	applied_diffuse.r /= 255;
	applied_diffuse.g /= 255;
	applied_diffuse.b /= 255;
	applied_diffuse.r *= cos_angle;
	applied_diffuse.g *= cos_angle;
	applied_diffuse.b *= cos_angle;
	color->r += applied_diffuse.r;
	color->g += applied_diffuse.g;
	color->b += applied_diffuse.b;
}

static void	get_ambiant(t_color *color, t_amb *amb)
{
	color->r = (color->r * (amb->color->r * amb->bright)) / 255;
	color->g = (color->g * (amb->color->g * amb->bright)) / 255;
	color->b = (color->b * (amb->color->b * amb->bright)) / 255;
}

static t_coordinates	find_lightray_dir(t_env *env, t_coordinates *hitpoint)
{
	return (mult_vec(sub_vec(*hitpoint, *env->light->coord), -1));
}

int	apply_light(t_env *env, t_ray *cam_ray,
					t_element *figure, t_coordinates *hitpoint)
{
	t_color			color;
	t_coordinates	normal_at_hp;
	t_ray			light_ray;
	t_coordinates	origin;
	t_coordinates	direction;

	color = *figure->color;
	normal_at_hp = get_normal_at(figure, hitpoint);
	origin = *env->light->coord;
	direction = find_lightray_dir(env, hitpoint);
	normalize_vec(&direction);
	light_ray.origin = &origin;
	light_ray.direction = &direction;
	get_ambiant(&color, env->amb);
	get_diffuse(env->light, &color, figure->color, &normal_at_hp, &light_ray);
	if (color.r > 255)
		color.r = 255;
	if (color.g > 255)
		color.g = 255;
	if (color.b > 255)
		color.b = 255;
	return (rgb_to_hexa(&color));
}
