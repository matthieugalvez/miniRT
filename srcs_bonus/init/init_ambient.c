/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ambient.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:22:45 by achantra          #+#    #+#             */
/*   Updated: 2025/03/01 17:42:05 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

/*
	- A(u) :
		* ambient lighting ratio in range [0.0,1.0]: 0.2
		* R,G,B colors in range [0-255]: 255, 255, 255
*/

static int	init_ambient(t_amb *amb, char **data)
{
	amb->bright = parse_ratio(data[1]);
	if (amb->bright < 0)
	{
		ft_freetab(data);
		return (1);
	}
	if (parse_color(data[2], &amb->color))
	{
		ft_freetab(data);
		return (1);
	}
	return (0);
}

int	new_ambient(t_env *env, char **data)
{
	if (env->amb_cmpt || ft_tablen(data) != 3)
	{
		ft_freetab(data);
		ft_putstr("Error: wrong data: ambiant light\n", 2);
		return (1);
	}
	env->amb_cmpt += 1;
	if (init_ambient(&env->amb, data))
		return (1);
	return (ft_freetab(data), 0);
}
