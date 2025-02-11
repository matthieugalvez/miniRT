/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:50:11 by achantra          #+#    #+#             */
/*   Updated: 2025/02/11 20:01:16 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	init_element(t_env *env, char *line)
{
	char	**data;

	data = ft_split(line, ' ');
	if (!data)
		return (perror("Error"), 1);
	if (!ft_strcmp(data[0], "A"))
		return (new_ambient(env, data));
	else if (!ft_strcmp(data[0], "L"))
		return (new_light(env, data));
	else if (!ft_strcmp(data[0], "C"))
		return (new_camera(env, data));
	else if (!ft_strcmp(data[0], "cy"))
		return (new_cylinder(env, data));
	else if (!ft_strcmp(data[0], "sp"))
		return (new_sphere(env, data));
	else if (!ft_strcmp(data[0], "pl"))
		return (new_plane(env, data));
	return (ft_printf_fd(2, "Error: wrong data: %s\n", data[0]), 1);
}
