/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:18:23 by achantra          #+#    #+#             */
/*   Updated: 2024/11/05 17:18:30 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cp;
	size_t	len;

	len = ft_strlen(s1);
	cp = malloc(sizeof(char) * (len + 1));
	if (!cp)
		return (NULL);
	ft_strlcpy(cp, s1, len + 1);
	return (cp);
}
/*
int	main(void)
{
	printf("%s\n", strdup("Bonjour"));
	printf("%s\n\n", ft_strdup("Bonjour"));

	printf("%s\n", strdup(""));
	printf("%s\n\n", ft_strdup(""));

	printf("%s\n", strdup(" "));
	printf("%s\n\n", ft_strdup(" "));

	return (0);
}*/
