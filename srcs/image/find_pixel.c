/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez <mgalvez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:07:17 by mgalvez           #+#    #+#             */
/*   Updated: 2025/09/11 19:23:15 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	get_pixel_sp(t_img *texture, double *uv_coords, int *x, int *y)
{
	*x = ((int)((1 - uv_coords[0]) * texture->w) + texture->w / 2)
		% texture->w;
	*y = (int)((1 - uv_coords[1]) * texture->h);
}

void	get_pixel_pl(t_img *texture, double *uv_coords, int *x, int *y)
{
	*x = (int)uv_coords[1] % (texture->w / 2);
	*y = (int)uv_coords[0] % (texture->h / 2);
	*x = texture->w / 2 + *x;
	*y = texture->h / 2 + *y;
}
