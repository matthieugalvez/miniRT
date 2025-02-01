/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:50:11 by achantra          #+#    #+#             */
/*   Updated: 2025/02/01 19:35:42 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_element	*last_elem(t_element *elem)
{
	t_element	*last;

	if (!elem)
		return (NULL);
	last = elem;
	while (last->next)
		last = last->next;
	return (last);
}

void	add_back_elem(t_element **elem, t_element *new)
{
	t_element	*last;

	if (!elem || !*elem)
		*elem = new;
	else
	{
		last = last_elem(*elem);
		last->next = new;
	}
}

int	init_element(t_env *env, char *line)
{
	char **data;

	data = ft_split(line, ' ');
	if (!data)
		return (perror("Error"), 1);
	if (!ft_strcmp(data[0], "A"))
		return (new_ambient(env, data));
	/*
	else if (!ft_strcmp(data[0], "C"))
		return (new_camera(env, data));
	else if (!ft_strcmp(data[0], "L"))
		return (new_light(env, data));
	else if (!ft_strcmp(data[0], "cy"))
		return (new_cylinder(env, data));*/
	/*else if (!ft_strcmp(data[0], "sp"))
		return (new_sphere(env, data));
	else if (!ft_strcmp(data[0], "pl"))
		return (new_plane(env, data));
	*/
	return (1);
}