/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez <mgalvez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:33:10 by mgalvez           #+#    #+#             */
/*   Updated: 2025/02/16 20:37:11 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "struct.h"

static void	get_specular(t_color *color, t_light *light,
				t_ray *ray, t_element *figure)
{
}

static void	get_diffuse()
{
}

/*static t_color	get_color(t_env *env, t_coordinates *normal_at_hp,
					t_ray *cam_ray, t_ray *light_ray)
{
}*/

static void	get_ambiant(t_color *color, t_amb *amb)
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
	direction = find_lightray_dir(env, cam_ray);
	normalize_vec(&direction);
	light_ray.origin = &origin;
	light_ray.direction = &direction;
	get_ambiant(&color, env->amb);
//	get_color(env, &normal_at_hp, cam_ray, &light_ray);
	return (rgb_to_hexa(&color));
}
