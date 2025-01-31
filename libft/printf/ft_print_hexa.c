/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:39:05 by achantra          #+#    #+#             */
/*   Updated: 2024/11/19 12:25:32 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hex_l(unsigned long nbr)
{
	int	len;
	int	r;

	len = 0;
	if (nbr / 16 > 0)
		len += ft_put_hex_l(nbr / 16);
	r = (nbr % 16);
	if (r < 10)
		r = r + '0';
	else
		r = r - 10 + 'a';
	write(1, &r, 1);
	len++;
	return (len);
}

int	ft_put_hex_u(unsigned long nbr)
{
	int	len;
	int	r;

	len = 0;
	if (nbr / 16 > 0)
		len += ft_put_hex_u(nbr / 16);
	r = (nbr % 16);
	if (r < 10)
		r = r + '0';
	else
		r = r - 10 + 'A';
	write(1, &r, 1);
	len++;
	return (len);
}

int	ft_print_ptr(va_list args)
{
	void	*addr;
	int		nchar;

	addr = va_arg(args, void *);
	if (!addr)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	nchar = 0;
	nchar += write(1, "0x", 2);
	nchar += ft_put_hex_l((unsigned long)addr);
	return (nchar);
}

int	ft_print_hexa_l(va_list args)
{
	return (ft_put_hex_l(va_arg(args, unsigned int)));
}

int	ft_print_hexa_u(va_list args)
{
	return (ft_put_hex_u(va_arg(args, unsigned int)));
}
