/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ambient.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:22:45 by achantra          #+#    #+#             */
/*   Updated: 2025/02/11 19:59:06 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
	- A(u) :
		* ambient lighting ratio in range [0.0,1.0]: 0.2
		* R,G,B colors in range [0-255]: 255, 255, 255
*/

int	new_ambient(t_env *env, char **data)
{
	t_amb	*amb;

	if (env->amb)
		return (ft_freetab(data),
			ft_putstr("Error: wrong data: double A\n", 2), 1);
	if (ft_tablen(data) != 3)
		return (ft_freetab(data), ft_putstr("Error: wrong data: A\n", 2), 1);
	amb = ft_calloc(sizeof(t_amb), 1);
	if (!amb)
		return (ft_freetab(data), perror("Error"), 1);
	amb->light = parse_ratio(data[1]);
	if (amb->light < 0)
		return (clean_ambient(amb), ft_freetab(data), 1);
	amb->color = parse_color(data[2]);
	if (!amb->color)
		return (clean_ambient(amb), ft_freetab(data), 1);
	env->amb = amb;
	return (ft_freetab(data), 0);
}
