/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 20:52:43 by achantra          #+#    #+#             */
/*   Updated: 2024/11/26 22:55:00 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_error(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (!str[i + 1])
				return (1);
			i++;
		}
		i++;
	}
	return (0);
}

int	ft_format(char c, va_list args)
{
	if (c == 'c')
		return (ft_print_chr(args));
	else if (c == 's')
		return (ft_print_str(args));
	else if (c == 'p')
		return (ft_print_ptr(args));
	else if (c == 'd')
		return (ft_print_int(args));
	else if (c == 'i')
		return (ft_print_int(args));
	else if (c == 'u')
		return (ft_print_uint(args));
	else if (c == 'x')
		return (ft_print_hexa_l(args));
	else if (c == 'X')
		return (ft_print_hexa_u(args));
	else if (c == '%')
		return (write(1, "%", 1));
	else if (c != 0)
	{
		write(1, "%", 1);
		write(1, &c, 1);
		return (2);
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		nprint;

	if (!str)
		return (-1);
	va_start(args, str);
	nprint = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '%')
			nprint += write(1, &str[i], 1);
		else
			nprint += ft_format(str[++i], args);
		if (!str[i])
			break ;
		i++;
	}
	va_end(args);
	if (check_error(str))
		return (-1);
	return (nprint);
}
