/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:53:18 by achantra          #+#    #+#             */
/*   Updated: 2024/11/05 17:13:20 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}
/*
int	main(void)
{
	for (int i = 0; i < 256; i++)
	{
		printf("%d\n", isalnum(i));
		printf("%d\n\n", ft_isalnum(i));
	}	
return (0);
}*/
