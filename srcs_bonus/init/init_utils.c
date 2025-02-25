/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:36:06 by achantra          #+#    #+#             */
/*   Updated: 2025/02/25 18:01:12 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

void	find_viewport(t_env *env)
{
	env->vp_w = 2 * tan(env->camera->fov * M_PI / 360);
	env->vp_h = env->vp_w / env->a_ratio;
}

t_coordinates	*parse_vector(char *data)
{
	t_coordinates	*vector;
	char			**num;

	vector = parse_coordinates(data);
	if (!vector)
		return (NULL);
	if (vector->x < -1 || vector->y < -1 || vector->z < -1
		|| vector->x > 1 || vector->y > 1 || vector->z > 1)
	{
		free(vector);
		ft_putstr("Error: wrong data: vector\n", 2);
		return (NULL);
	}
	if (equal_double(vector->x, 0) && equal_double(vector->y, 0)
		&& equal_double(vector->z, 0))
	{
		free(vector);
		ft_putstr("Error: wrong data: vector\n", 2);
		return (NULL);
	}
	return (vector);
}

int	ft_is_float(char *data)
{
	int	i;
	int	n_float;
	int	len_data;

	i = 0;
	n_float = 0;
	len_data = ft_strlen(data);
	while (data[i])
	{
		if (ft_isdigit(data[i]) || (i == 0 && (data[i] == '-'
					|| data[i] == '+')))
			i++;
		else
		{
			if (i == 0 || i == len_data - 1 || !(data[i] == '.'))
				return (0);
			else if (data[i] == '.' && n_float)
				return (0);
			else if (data[i] == '.')
				n_float = 1;
			i++;
		}
	}
	return (1);
}

static t_element	*last_elem(t_element *elem)
{
	t_element	*last;

	last = elem;
	while (last->next)
		last = last->next;
	return (last);
}

void	add_back_elem(t_element **elem, t_element *new_elem)
{
	t_element	*last;

	if (!elem || !*elem)
		*elem = new_elem;
	else
	{
		last = last_elem(*elem);
		last->next = new_elem;
	}
}
