/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ambient.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:22:45 by achantra          #+#    #+#             */
/*   Updated: 2025/02/02 16:12:40 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
	- A(u) :
		* ambient lighting ratio in range [0.0,1.0]: 0.2
		* R,G,B colors in range [0-255]: 255, 255, 255
*/

t_amb	*init_ambient(void)
{
	t_amb	*amb;

	amb = malloc(sizeof(t_amb));
	if (!amb)
		return (NULL);
	amb->color = NULL;
	return (amb);
}

int	new_ambient(t_env *env, char **data)
{
	t_amb	*amb;

	if (env->amb)
		return (ft_free_tab(data), print_data_err("double A"), 1);
	if (len_tab(data) != 3)
		return (ft_free_tab(data), print_data_err("A"), 1);
	amb = init_ambient();
	if (!amb)
		return (ft_free_tab(data), perror("Error"), 1);
	amb->light = parse_ratio(data[1]);
	if (amb->light < 0)
		return (clean_ambient(amb), ft_free_tab(data), 1);
	amb->color = parse_color(data[2]);
	if (!amb->color)
		return (clean_ambient(amb), ft_free_tab(data), 1);
	env->amb = amb;
	return (ft_free_tab(data), 0);
}
