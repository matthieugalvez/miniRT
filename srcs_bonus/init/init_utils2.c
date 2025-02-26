/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:30:55 by achantra          #+#    #+#             */
/*   Updated: 2025/02/26 11:32:54 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

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