/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez <mgalvez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:33:10 by mgalvez           #+#    #+#             */
/*   Updated: 2025/02/15 16:39:35 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	apply_ambiant(t_color *color, t_amb *amb)
{
	color->r = (color->r + amb->color->r) * amb->light;
	color->g = (color->g + amb->color->g) * amb->light;
	color->b = (color->b + amb->color->b) * amb->light;
}
