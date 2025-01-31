/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:01:10 by achantra          #+#    #+#             */
/*   Updated: 2024/11/15 17:14:18 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(va_list args)
{
	char	*nbr;
	int		len;

	nbr = ft_itoa(va_arg(args, int));
	ft_putstr_fd(nbr, 1);
	len = ft_strlen(nbr);
	return (free(nbr), len);
}

int	ft_print_uint(va_list args)
{
	char	*unbr;
	int		len;

	unbr = ft_itoa_unsigned(va_arg(args, unsigned int));
	ft_putstr_fd(unbr, 1);
	len = ft_strlen(unbr);
	return (free(unbr), len);
}
