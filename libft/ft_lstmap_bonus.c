/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achantra <achantra@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:33:45 by achantra          #+#    #+#             */
/*   Updated: 2024/12/01 15:34:42 by achantra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	*ft_idem(void *i)
{
	char	*res = (char *) i;
	return ((void *) res);
}*/

t_list	*ft_lstmap(t_list *lst, char *(*f)(char *), void (*del)(void *))
{
	t_list	*beginlist;
	t_list	*new;

	if (!lst)
		return (NULL);
	beginlist = ft_lstnew(f(lst->content));
	if (!beginlist)
		return (NULL);
	new = beginlist;
	while (lst->next)
	{
		lst = lst->next;
		new->next = ft_lstnew(f(lst->content));
		if (!(new->next))
		{
			ft_lstclear(&beginlist, del);
			return (NULL);
		}
		new = new->next;
	}
	return (beginlist);
}
/*
int	main(void)
{
        t_list  *elem1 = ft_lstnew("elem1");
        t_list  *elem2 = ft_lstnew("elem2");
        t_list  *elem3 = ft_lstnew("elem3");
        t_list  *begin = NULL;
	t_list	*beginf;
	t_list  *begin2;
	t_list  *beginf2;
        ft_lstadd_back(&begin, elem1);
        ft_lstadd_back(&begin, elem2);
        ft_lstadd_back(&begin, elem3);
	begin2 = begin;
        beginf = ft_lstmap(begin, &ft_idem, &free);
	beginf2 = beginf;
	while (begin)
        {
                printf("%s\n", (char *) begin->content);
                begin = begin->next;
        }
	while (beginf)
        {
                printf("%s\n", (char *) beginf->content);
                beginf = beginf->next;
        }
	ft_lstclear(&begin2, &free);
	ft_lstclear(&beginf2, &free);
}*/
