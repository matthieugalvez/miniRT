/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez <mgalvez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:49:04 by mgalvez           #+#    #+#             */
/*   Updated: 2025/03/01 18:12:40 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_element	*find_selected_object(t_env *env)
{
	t_element	*figure;
	int			i;

	figure = env->figure;
	i = 1;
	while (i < env->selected_object)
	{
		figure = figure->next;
		i++;
	}
	return (figure);
}
