/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:30:55 by achantra          #+#    #+#             */
/*   Updated: 2025/02/28 14:08:11 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

void	find_cylinder_disks(t_element *cylinder)
{
	t_coordinates	disk_vec;

	disk_vec = mult_vec(*(cylinder->vector), cylinder->height / 2);
	cylinder->t_disk_c = add_vec(*(cylinder->coord), disk_vec);
	cylinder->b_disk_c = sub_vec(*(cylinder->coord), disk_vec);
}

int	find_vectors(t_element *element)
{
	t_coordinates	tmp_up;

	if (!equal_double(element->vector->y, 0)
		|| !equal_double(element->vector->z, 0))
		tmp_up = change_vec(1, 0, 0);
	else
		tmp_up = change_vec(0, 1, 0);
	element->vector_up = vect_prod_vec(tmp_up, *(element->vector));
	if (!element->vector_up)
	{
		clean_figure(element);
		return (1);
	}
	normalize_vec(element->vector_up);
	element->vector_right = vect_prod_vec(*(element->vector),
			*(element->vector_up));
	if (!element->vector_right)
	{
		clean_figure(element);
		return (1);
	}
	normalize_vec(element->vector_right);
	*element->vector_up = mult_vec(*element->vector_up, -1);
	return (0);
}
