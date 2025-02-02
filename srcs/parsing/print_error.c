/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:29:15 by achantra          #+#    #+#             */
/*   Updated: 2025/02/02 15:40:52 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	print_data_err(char *data)
{
	ft_putstr_fd("Error: wrong data: ", 2);
	ft_putendl_fd(data, 2);
}
