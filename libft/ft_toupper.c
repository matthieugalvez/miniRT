/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:14:47 by achantra          #+#    #+#             */
/*   Updated: 2024/11/05 17:14:53 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
/*
int	main(void)
{
        for (int i = 0; i < 256; i++)
        {
                printf("%d\n", toupper(i));
                printf("%d\n\n", ft_toupper(i));
        }
	return (0);
}*/
