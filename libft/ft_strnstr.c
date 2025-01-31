/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:11:36 by achantra          #+#    #+#             */
/*   Updated: 2024/11/05 17:11:50 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*res;

	res = (char *) haystack;
	i = 0;
	if (needle[0] == 0)
		return (res);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (i + j < len && needle[j] == haystack[i + j] && haystack[i + j])
			j += 1;
		if (!(needle[j]))
			return (res + i);
		i += 1;
	}
	return (0);
}
/*
int	main(void)
{
	printf("%s\n", strnstr("BONJOUR", "", 2));
	printf("%s\n\n", ft_strnstr("BONJOUR", "", 2));
	
	printf("%s\n", strnstr("BONJOUR", "NJ", 4));
        printf("%s\n\n", ft_strnstr("BONJOUR", "NJ", 4));
	
 	printf("%s\n", strnstr("BONJOUR", "NJ", 3));
        printf("%s\n\n", ft_strnstr("BONJOUR", "NJ", 3));

	printf("%s\n", strnstr("BONJOUR", "O", 2));
        printf("%s\n\n", ft_strnstr("BONJOUR", "O", 2));
	
	printf("%s\n", strnstr("", "O", 2));
        printf("%s\n\n", ft_strnstr("", "O", 2));

	printf("%s\n", strnstr("", "", 2));
        printf("%s\n\n", ft_strnstr("", "", 2));

	printf("%s\n", strnstr("BONJOUR", "", 0));
        printf("%s\n\n", ft_strnstr("BONJOUR", "", 0));

	return (0);
}*/
