/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:51:02 by achantra          #+#    #+#             */
/*   Updated: 2024/11/13 20:23:25 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == ' ' || (c >= '\t' && c <= '\r'))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	nb;
	int	s;

	s = 1;
	i = 0;
	nb = 0;
	while (ft_isspace((int)str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + ((str[i] - '0'));
		i++;
	}
	return (s * nb);
}

/*int	main(void)
{
	printf("%d\n", atoi("  \n-2147483648bcd45"));
	printf("%d\n\n", ft_atoi("  \n-2147483648bcd45"));
	printf("%d\n", atoi("  \n\t\v\f\r456"));
	printf("%d\n\n", ft_atoi("  \n\t\v\f\r456"));
	printf("%d\n", atoi(" u+56"));
	printf("%d\n\n", ft_atoi(" u+56"));
	printf("%d\n", atoi(" +2147483647"));
		printf("%d\n\n", ft_atoi(" +2147483647"));
}*/
