/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:39:22 by achantra          #+#    #+#             */
/*   Updated: 2025/02/25 18:00:16 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

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
