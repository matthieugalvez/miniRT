/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:29:15 by achantra          #+#    #+#             */
/*   Updated: 2025/02/11 13:41:03 by mgalvez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	print_data_err(char *data)
{
	ft_printf_fd(2, "Error: wrong data: %s\n", data);
}

void	print_data_war(char *data)
{
	ft_printf_fd(2, "Warning: missing %s\n", data);
}
