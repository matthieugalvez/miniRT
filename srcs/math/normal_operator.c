/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_operator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez <mgalvez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:54:12 by mgalvez           #+#    #+#             */
/*   Updated: 2025/02/19 12:27:04 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_coordinates	normal_at_sp(t_element *sphere, t_coordinates *point)
{
	t_coordinates	normal_at_vec;

	normal_at_vec = sub_vec(*point, *sphere->coord);
	normalize_vec(&normal_at_vec);
	return (normal_at_vec);
}

t_coordinates	get_normal_at(t_element *figure, t_coordinates *point)
{
//	if (figure->id == SPHERE)
	return (normal_at_sp(figure, point));
}
