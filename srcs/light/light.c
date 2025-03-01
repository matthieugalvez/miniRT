/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:33:10 by mgalvez           #+#    #+#             */
/*   Updated: 2025/03/01 14:38:28 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	get_diffuse(t_light *light, t_color *color, t_color *figure_color,
		double cos_angle)
{
	double	specular_factor;
	t_color	applied_diffuse;

	applied_diffuse.r = figure_color->r * (255 * light->bright);
	applied_diffuse.g = figure_color->g * (255 * light->bright);
	applied_diffuse.b = figure_color->b * (255 * light->bright);
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

static int	find_shadow(t_env *env, t_element *current_figure, t_ray *light_ray)
{
	t_element	*figure;
	double		intsec;
	double		distance;
	double		new_distance;

	figure = env->figure;
	distance = find_intsec(light_ray, current_figure);
	while (figure)
	{
		new_distance = find_intsec(light_ray, figure);
		if (new_distance < distance)
			return (1);
		figure = figure->next;
	}
	return (0);
}

static void	get_ambiant(t_color *color, t_amb *amb)
{
	color->r = (color->r * (amb->color->r * amb->bright * 0.5)) / 255;
	color->g = (color->g * (amb->color->g * amb->bright * 0.5)) / 255;
	color->b = (color->b * (amb->color->b * amb->bright * 0.5)) / 255;
}

int	apply_light(t_env *env, t_ray *cam_ray, t_element *figure,
		t_coordinates *hitpoint)
{
	t_color			color;
	t_coordinates	normal_at_hp;
	t_ray			light_ray;
	double			cos_angle;

	color = *figure->color;
	light_ray.origin = *env->light->coord;
	light_ray.direction = sub_vec(hitpoint, env->light->coord);
	normalize_vec(&light_ray.direction);
	normal_at_hp = get_normal_at(figure, hitpoint, &light_ray, cam_ray);
	get_ambiant(&color, env->amb);
	light_ray.direction = mult_vec(&light_ray.direction, -1);
	cos_angle = scalar_prod_vec(&normal_at_hp, &light_ray.direction);
	light_ray.direction = mult_vec(&light_ray.direction, -1);
	if (!find_shadow(env, figure, &light_ray) && cos_angle >= 0)
		get_diffuse(env->light, &color, figure->color, cos_angle);
	if (color.r > 255)
		color.r = 255;
	if (color.g > 255)
		color.g = 255;
	if (color.b > 255)
		color.b = 255;
	return (rgb_to_hexa(&color));
}
