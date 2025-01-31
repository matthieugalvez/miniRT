/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:54:01 by achantra          #+#    #+#             */
/*   Updated: 2024/11/05 17:14:04 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c < 32 || c >= 127)
		return (0);
	return (1);
}
/*
int	main(void)
{
	for (int i = 0; i < 256; i++)
	{
		printf("%d\n", isprint(i));
		printf("%d\n\n", ft_isprint(i));
	}	
	return (0);
}*/
