/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_xpm_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez <mgalvez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 20:33:15 by mgalvez           #+#    #+#             */
/*   Updated: 2025/09/11 19:28:23 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	parse_xpm_file(t_env *env, t_img *img, char *data)
{
	img->img = mlx_xpm_file_to_image(env->mlx, data, &img->w, &img->h);
	if (!img->img)
	{
		ft_putstr("Error: failed to load xpm file\n", 2);
		return (1);
	}
	img->img_pixels = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_len, &img->endian);
	return (0);
}
