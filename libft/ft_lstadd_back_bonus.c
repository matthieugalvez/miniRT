/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:38:56 by achantra          #+#    #+#             */
/*   Updated: 2024/11/07 15:13:46 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !*lst)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}
/*
int	main(void)
{
	t_list	*elem1 = ft_lstnew("elem1");
	t_list	*elem2 = ft_lstnew("elem2");
	t_list	*elem3 = ft_lstnew("elem3");
	t_list	*begin = NULL;
	ft_lstadd_back(&begin, elem1);
	ft_lstadd_back(&begin, elem2);
	ft_lstadd_back(&begin, elem3);
	while (begin)
	{
		printf("%s\n", (char *) begin->content);
		begin = begin->next;
	}
}*/
