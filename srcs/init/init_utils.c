/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:36:06 by achantra          #+#    #+#             */
/*   Updated: 2025/02/10 16:51:53 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

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

double	ft_atof(char *num1, char *num2)
{
	int		len_num2;
	double	integer;
	double	decimal;

	if (!num2)
		return (ft_atol(num1));
	len_num2 = 0;
	while (num2[len_num2])
		len_num2++;
	integer = (double) ft_atol(num1);
	decimal = ft_atol(num2) / pow(10, len_num2);
	if (integer < 0)
		decimal *= -1;
	return (integer + decimal);
}

int	len_tab(char **tab)
{
	int	i;

	if (!tab)
		return (0);
	i = 0;
	while (tab[i])
		i++;
	return (i);
}

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
