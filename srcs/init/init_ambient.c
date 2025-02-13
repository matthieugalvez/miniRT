/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ambient.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:22:45 by achantra          #+#    #+#             */
/*   Updated: 2025/02/13 13:14:54 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
	- A(u) :
		* ambient lighting ratio in range [0.0,1.0]: 0.2
		* R,G,B colors in range [0-255]: 255, 255, 255
*/

static int	init_ambient(t_amb *amb, char **data)
{
	amb->light = parse_ratio(data[1]);
	if (amb->light < 0)
	{
		clean_ambient(amb);
		ft_freetab(data);
		return (1);
	}
	amb->color = parse_color(data[2]);
	if (!amb->color)
	{
		clean_ambient(amb);
		ft_freetab(data);
		return (1);
	}
	return (0);
}

int	new_ambient(t_env *env, char **data)
{
	t_amb	*amb;

	if (env->amb || ft_tablen(data) != 3)
	{
		ft_freetab(data);
		ft_putstr("Error: wrong data: ambiant light\n", 2);
		return (1);
	}
	amb = ft_calloc(sizeof(t_amb), 1);
	if (!amb)
	{
		ft_freetab(data);
		perror("Error");
		return (1);
	}
	if (init_ambient(amb, data))
		return (1);
	env->amb = amb;
	return (ft_freetab(data), 0);
}
