/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:17:13 by achantra          #+#    #+#             */
/*   Updated: 2024/11/07 13:25:30 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*res;

	res = (char *) s;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if ((unsigned char) s[i] == (unsigned char) c)
			return (res + i);
		i --;
	}
	return (0);
}
/*
int	main(void)
{
	printf("%s\n", strrchr("BONJOUR", 'O'));
	printf("%s\n\n", ft_strrchr("BONJOUR", 'O'));
	
	printf("%s\n", strrchr("BONJOUR", '\0'));
        printf("%s\n\n", ft_strrchr("BONJOUR", '\0'));
	
 	printf("%s\n", strrchr("", 'N'));
        printf("%s\n\n", ft_strrchr("", 'N'));

	printf("%s\n", strrchr("BONJOUR", 'W'));
        printf("%s\n\n", ft_strrchr("BONJOUR", 'W'));
	
	printf("%s\n", strrchr("", '\0'));
        printf("%s\n\n", ft_strrchr("", '\0'));

	return (0);
}*/
