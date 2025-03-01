/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:30:55 by achantra          #+#    #+#             */
/*   Updated: 2025/03/01 14:28:35 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

void	find_cylinder_disks(t_element *cylinder)
{
	t_coordinates	disk_vec;

	disk_vec = mult_vec(cylinder->vector, cylinder->height / 2);
	cylinder->t_disk_c = add_vec(cylinder->coord, &disk_vec);
	cylinder->b_disk_c = sub_vec(cylinder->coord, &disk_vec);
}

t_coordinates	find_tmp_up(t_coordinates *vector)
{
	t_coordinates	tmp_up;

	if (!equal_double(vector->y, 0) || !equal_double(vector->z, 0))
	{
		if (vector->y < 0 || vector->z < 0)
			tmp_up = change_vec(-1, 0, 0);
		else
			tmp_up = change_vec(1, 0, 0);
	}
	else
	{
		if (vector->x < 0)
			tmp_up = change_vec(0, -1, 0);
		else
			tmp_up = change_vec(0, 1, 0);
	}
	return (tmp_up);
}

int	find_vectors(t_element *element)
{
	t_coordinates	tmp_up;

	tmp_up = find_tmp_up(element->vector);
	element->vector_up = vect_prod_vec(&tmp_up, element->vector);
	normalize_vec(&element->vector_up);
	element->vector_right = vect_prod_vec(element->vector, &element->vector_up);
	normalize_vec(&element->vector_right);
	element->vector_up = mult_vec(&element->vector_up, -1);
	return (0);
}
