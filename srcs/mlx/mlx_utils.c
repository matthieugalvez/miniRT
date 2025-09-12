/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalvez <mgalvez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 13:58:57 by mgalvez           #+#    #+#             */
/*   Updated: 2025/09/11 19:27:54 by mgalvez          ###   ########.fr       */
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
