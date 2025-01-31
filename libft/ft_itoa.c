/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:14:03 by achantra          #+#    #+#             */
/*   Updated: 2024/12/16 16:47:18 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		len;
	int		q;
	char	*nb;

	len = 1;
	q = n;
	while (q > 9 || q < -9)
	{
		q = q / 10;
		len ++;
	}
	if (n < 0)
		len ++;
	nb = malloc (sizeof(char) * (len + 1));
	if (!nb)
		return (NULL);
	nb[len] = '\0';
	while (len-- > 0)
	{
		nb[len] = ft_abs((n % 10)) + '0';
		n = n / 10;
	}
	if (nb[0] == '0' && nb[1])
		nb[0] = '-';
	return (nb);
}
/*
int	main(void)
{
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(12));
}*/
