/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_light_source.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez <mgalvez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:59:44 by mgalvez           #+#    #+#             */
/*   Updated: 2025/02/26 18:33:55 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

static void	get_specular(t_coordinates reflexion_vec, t_ray *cam_ray,
						t_light *light, t_color *color)
{
	double	cos_angle;
	double	factor;
	double	specular;

	cos_angle = scalar_prod_vec(reflexion_vec, *cam_ray->direction);
	if (cos_angle <= 0)
		return ;
	factor = pow(cos_angle, 250);
	specular = light->bright * 0.15 * factor;
	color->r += light->color->r * specular;
	color->g += light->color->g * specular;
	color->b += light->color->b * specular;
	if (color->r > 255)
		color->r = 255;
	if (color->g > 255)
		color->g = 255;
	if (color->b > 255)
		color->b = 255;
}

static t_coordinates	get_reflexion_vec(t_coordinates *light_ray,
							t_coordinates *normal_at_hp)
{
	t_coordinates	factor;
	double			cos_angle;

	cos_angle = 2 * scalar_prod_vec(*normal_at_hp, *light_ray);
	factor = mult_vec(*normal_at_hp, cos_angle);
	return (sub_vec(factor, *light_ray));
}

static t_color	get_diffuse(t_light *light, t_color *hitpoint_color,
			double cos_angle)
{
	double	specular_factor;
	t_color	applied_diffuse;

	applied_diffuse.r = hitpoint_color->r * (light->color->r * light->bright);
	applied_diffuse.g = hitpoint_color->g * (light->color->g * light->bright);
	applied_diffuse.b = hitpoint_color->b * (light->color->b * light->bright);
	applied_diffuse.r /= 255;
	applied_diffuse.g /= 255;
	applied_diffuse.b /= 255;
	applied_diffuse.r *= cos_angle;
	applied_diffuse.g *= cos_angle;
	applied_diffuse.b *= cos_angle;
	if (applied_diffuse.r > 255)
		applied_diffuse.r = 255;
	if (applied_diffuse.g > 255)
		applied_diffuse.g = 255;
	if (applied_diffuse.b > 255)
		applied_diffuse.b = 255;
	return (applied_diffuse);
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
		if (figure != current_figure)
		{
			new_distance = find_intsec(light_ray, figure);
			if (equal_double(new_distance, distance) || new_distance < distance)
				return (1);
		}
		figure = figure->next;
	}
	return (0);
}

t_color	compute_light_source(t_env *env, t_hitpoint *hitpoint,
				t_element *figure, t_light *light)
{
	t_coordinates	normal_at_hp;
	t_ray			light_ray;
	double			cos_angle;
	t_coordinates	reflexion_vec;
	t_color			color;

	ft_bzero(&color, sizeof(t_color));
	init_ray(&light_ray, env, hitpoint, light);
	normal_at_hp = get_normal_at(figure, hitpoint->coord,
			&light_ray, env->camera->ray);
	cos_angle = scalar_prod_vec(normal_at_hp, mult_vec(*light_ray.direction,
				-1));
	if (!find_shadow(env, figure, &light_ray) && cos_angle >= 0)
	{
		color = get_diffuse(light, hitpoint->color, cos_angle);
		//reflexion_vec = get_reflexion_vec(light_ray.direction, &normal_at_hp);
		//normalize_vec(&reflexion_vec);
		//get_specular(reflexion_vec, env->camera->ray, light, &color);
	}
	free(light_ray.direction);
	return (color);
}
