/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:15:10 by achantra          #+#    #+#             */
/*   Updated: 2024/11/29 17:04:14 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*int	main(void)
{
	printf("%lu\n", strlen(""));
	printf("%lu\n\n", ft_strlen(""));
        printf("%lu\n", strlen("Hello"));
        printf("%lu\n\n", ft_strlen("Hello"));
	printf("%lu\n", strlen("Hello world"));
        printf("%lu\n\n", ft_strlen("Hello world"));	
	return (0);
}*/
