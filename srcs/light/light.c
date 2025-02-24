/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:33:10 by mgalvez           #+#    #+#             */
/*   Updated: 2025/02/24 17:33:10 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*static t_coordinates	get_reflexion_vec(t_coordinates *light_ray,
							t_coordinates *normal_at_hp)
{
	t_coordinates	factor;
	double			cos_angle;

	cos_angle = scalar_prod_vec(*normal_at_hp, *light_ray);
	factor = mult_vec(mult_vec(*normal_at_hp, 2), cos_angle);
	return (sub_vec(*light_ray, factor));
}

static void	get_specular(t_coordinates reflexion_vec, t_ray *cam_ray,
						t_light *light, t_color *color)
{
	double	cos_angle;
	double	factor;
	double	specular;

	cos_angle = scalar_prod_vec(reflexion_vec, mult_vec(*cam_ray->direction, -1));
	if (cos_angle <= 0)
		return ;
	factor = pow(cos_angle, 200);
	specular = light->bright * 0.075 * factor;
	color->r += light->color->r * specular;
	color->g += light->color->g * specular;
	color->b += light->color->b * specular;
}
*/
static void	get_diffuse(t_light *light, t_color *color,
						t_color *figure_color, double cos_angle)
{
	double			specular_factor;
	t_color			applied_diffuse;

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

static void	get_ambiant(t_color *color, t_amb *amb)
{
	color->r = (color->r * (amb->color->r * amb->bright * 0.5)) / 255;
	color->g = (color->g * (amb->color->g * amb->bright * 0.5)) / 255;
	color->b = (color->b * (amb->color->b * amb->bright * 0.5)) / 255;
}

int	apply_light(t_env *env, t_ray *cam_ray,
					t_element *figure, t_coordinates *hitpoint)
{
	t_color			color;
	t_coordinates	normal_at_hp;
	t_ray			light_ray;
	double			cos_angle;
//	t_coordinates	reflexion_vec;

	color = *figure->color;
	init_ray(&light_ray, env, hitpoint);
	normal_at_hp = get_normal_at(figure, hitpoint, &light_ray, cam_ray);
	get_ambiant(&color, env->amb);
	cos_angle = scalar_prod_vec(normal_at_hp,
			mult_vec(*light_ray.direction, -1));
	if (!find_shadow(env, figure, &light_ray) && cos_angle >= 0)
		get_diffuse(env->light, &color, figure->color, cos_angle);
//	reflexion_vec = get_reflexion_vec(light_ray.direction, &normal_at_hp);
//	normalize_vec(&reflexion_vec);
//	get_specular(reflexion_vec, cam_ray, env->light, &color);
	if (color.r > 255)
		color.r = 255;
	if (color.g > 255)
		color.g = 255;
	if (color.b > 255)
		color.b = 255;
	free(light_ray.direction);
	return (rgb_to_hexa(&color));
}
