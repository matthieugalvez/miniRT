/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:51:04 by achantra          #+#    #+#             */
/*   Updated: 2024/11/15 17:11:37 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_unsigned(unsigned int n)
{
	unsigned int	len;
	unsigned int	q;
	char			*nb;

	len = 1;
	q = n;
	while (q > 9)
	{
		q = q / 10;
		len++;
	}
	nb = malloc(sizeof(char) * (len + 1));
	if (!nb)
		return (NULL);
	nb[len] = '\0';
	while (len-- > 0)
	{
		nb[len] = (n % 10) + '0';
		n = n / 10;
	}
	return (nb);
}
