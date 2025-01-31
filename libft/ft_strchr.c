/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:58:26 by achantra          #+#    #+#             */
/*   Updated: 2024/12/05 21:21:12 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*res;

	res = (char *) s;
	i = 0;
	while (s[i])
	{
		if ((unsigned char) s[i] == (unsigned char) c)
			return (res + i);
		i += 1;
	}
	if ((unsigned char) s[i] == (unsigned char) c)
		return (res + i);
	return (0);
}
/*
int	main(void)
{
	printf("%s\n", strchr("BONJOUR", 'O'));
	printf("%s\n\n", ft_strchr("BONJOUR", 'O'));
	
	printf("%s\n", strchr("BONJOUR", '\0'));
        printf("%s\n\n", ft_strchr("BONJOUR", '\0'));
	
 	printf("%s\n", strchr("", 'N'));
        printf("%s\n\n", ft_strchr("", 'N'));

	printf("%s\n", strchr("BONJOUR", 'W'));
        printf("%s\n\n", ft_strchr("BONJOUR", 'W'));
	
	printf("%s\n", strchr("", '\0'));
        printf("%s\n\n", ft_strchr("", '\0'));

	return (0);
}*/