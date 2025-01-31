/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 20:52:13 by achantra          #+#    #+#             */
/*   Updated: 2024/12/16 20:41:10 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"
# include <stdarg.h>
# include <unistd.h>

char	*ft_itoa_unsigned(unsigned int n);
int		ft_print_chr(va_list args);
int		ft_print_str(va_list args);
int		ft_print_ptr(va_list args);
int		ft_print_int(va_list args);
int		ft_print_uint(va_list args);
int		ft_print_hexa_l(va_list args);
int		ft_print_hexa_u(va_list args);
int		ft_printf(const char *str, ...);

#endif