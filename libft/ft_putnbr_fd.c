/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:54:25 by achantra          #+#    #+#             */
/*   Updated: 2024/11/07 13:35:31 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		q;
	int		s;
	char	r;

	s = 1;
	r = 0;
	if (n < 0)
	{
		write(fd, "-", 1);
		s = -1;
	}
	q = s * (n / 10);
	if (q > 0)
		ft_putnbr_fd(q, fd);
	r = s * (n % 10) + '0';
	write(fd, &r, 1);
}
/*
int	main(void)
{
	ft_putnbr_fd(0, 1);
	write(1, "\n", 1);
	
	ft_putnbr_fd(-2147483648, 1);
	write(1, "\n", 1);

	ft_putnbr_fd(2147483647, 1);
	return (0);
}*/
