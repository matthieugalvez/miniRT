/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:39:22 by achantra          #+#    #+#             */
/*   Updated: 2025/03/01 15:44:53 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

t_coordinates	get_ref(t_coordinates *temp_coord, double teta,
						t_coordinates *u, t_element *figure)
{
	double			cos_teta;
	t_coordinates	buf_vec;
	t_coordinates	ref_cy;

	cos_teta = cos(teta);
	buf_vec = vect_prod_vec(u, figure->vector);
	buf_vec = mult_vec(&buf_vec, sin(teta));
	ref_cy = mult_vec(temp_coord, cos_teta);
	ref_cy = add_vec(&ref_cy, &buf_vec);
	buf_vec = mult_vec(u, (1 - cos_teta) * scalar_prod_vec(u, figure->vector));
	return (add_vec(&ref_cy, &buf_vec));
}

void	my_pixel_put(int i, int j, t_env *env, int color)
{
	int	offset;

	if (i >= WIN_W || j >= WIN_H || i < 0 || j < 0)
		return ;
	offset = (env->img.line_len * j) + (i * (env->img.bits_per_pixel / 8));
	*((unsigned int *)((env->img).img_pixels + offset)) = color;
}

int	rgb_to_hexa(t_color *color)
{
	return (color->r << 16 | color->g << 8 | color->b);
}
