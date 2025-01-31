/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:14:28 by achantra          #+#    #+#             */
/*   Updated: 2024/10/02 17:23:35 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str);
int	check_base(char *base);
int	ft_position_in_base(char c, char *base);

char	*convert_to_char(int nbr, char *base, int len_nbr_base, char *nbr_base)
{
	int	q;
	int	s;
	int	len_base;

	len_base = ft_strlen(base);
	s = 1;
	if (nbr < 0)
	{
		nbr_base[0] = '-';
		s = -1;
	}
	nbr_base[len_nbr_base] = '\0';
	q = nbr;
	while (len_nbr_base > 1)
	{
		nbr_base[len_nbr_base - 1] = base[s * (q % len_base)];
		len_nbr_base --;
		q = q / len_base;
	}
	if (nbr >= 0)
		nbr_base[0] = base[(q % len_base)];
	return (nbr_base);
}

int	convert_to_int(char *nbr, char *base)
{
	int	len_base;
	int	i;
	int	nbr_int;

	len_base = ft_strlen(base);
	nbr_int = 0;
	i = 0;
	while (ft_position_in_base(nbr[i], base) > -1)
	{
		nbr_int = nbr_int * len_base + ft_position_in_base(nbr[i], base);
		i++;
	}
	return (nbr_int);
}

int	ft_atoi_base(char *nbr, char *base)
{
	int	i;
	int	s;
	int	nbr_int;

	s = 1;
	i = 0;
	nbr_int = 0;
	while (nbr[i] == ' ' || (nbr[i] >= '\t' && nbr[i] <= '\r'))
		i ++;
	while (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			s *= -1;
		i++;
	}
	return (s * convert_to_int(&nbr[i], base));
}

char	*ft_itoa(int nbr, char *base)
{
	int		len_base;
	char	*nbr_base;
	int		len_nbr_base;
	int		q;

	len_base = ft_strlen(base);
	len_nbr_base = 0;
	q = nbr;
	while (q != 0)
	{
		q = q / len_base;
		len_nbr_base ++;
	}
	if (nbr < 0)
		len_nbr_base += 1;
	nbr_base = malloc((sizeof(char) * (len_nbr_base + 1)));
	if (!nbr_base)
		return (NULL);
	return (convert_to_char(nbr, base, len_nbr_base, nbr_base));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	nbr_int;

	if (!check_base(base_from) || !check_base(base_to))
		return (NULL);
	nbr_int = ft_atoi_base(nbr, base_from);
	return (ft_itoa(nbr_int, base_to));
}
/*
int	main(void)
{
	char	*n;

	n = ft_convert_base("  \t -+-0a", "0123456789abcdef", "0123456789");
	printf("%s\n", n);
	free(n);
	return (0);
}*/
