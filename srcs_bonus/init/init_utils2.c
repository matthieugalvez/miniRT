/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:30:55 by achantra          #+#    #+#             */
/*   Updated: 2025/03/02 18:57:19 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

void	find_disks(t_element *figure)
{
	t_coordinates	disk_vec;

	disk_vec = mult_vec(&figure->vector, figure->height / 2);
	figure->t_disk_c = add_vec(&figure->coord, &disk_vec);
	figure->b_disk_c = sub_vec(&figure->coord, &disk_vec);
}

t_coordinates	find_tmp_up(t_coordinates *vector)
{
	t_coordinates	tmp_up;

	if (equal_double(vector->x, 0))
	{
		if (vector->z < 0)
			tmp_up = change_vec(-1, 0, 0);
		else
			tmp_up = change_vec(1, 0, 0);
	}
	else
	{
		if (vector->x < 0)
			tmp_up = change_vec(0, 0, 1);
		else
			tmp_up = change_vec(0,0,-1);
	}
	return (tmp_up);
}

int	find_vectors(t_element *element)
{
	t_coordinates	tmp_up;

	tmp_up = find_tmp_up(&element->vector);
	element->vector_up = vect_prod_vec(&tmp_up, &element->vector);
	normalize_vec(&element->vector_up);
	element->vector_right
		= vect_prod_vec(&element->vector, &element->vector_up);
	normalize_vec(&element->vector_right);
	element->vector_up = mult_vec(&element->vector_up, -1);
	return (0);
}

static t_light	*last_light(t_light *light)
{
	t_light	*last;

	last = light;
	while (last->next)
		last = last->next;
	return (last);
}

void	add_back_light(t_light **light, t_light *new_light)
{
	t_light	*last;

	if (!light || !*light)
		*light = new_light;
	else
	{
		last = last_light(*light);
		last->next = new_light;
	}
}
