/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osadeddi <osadeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:23:11 by osadeddi          #+#    #+#             */
/*   Updated: 2024/08/29 17:21:37 by osadeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*p;
	t_list	*temp;

	if (!lst || !del)
		return ;
	p = *lst;
	while (p)
	{
		del(p->content);
		temp = p;
		p = p->next;
		free(temp);
	}
	*lst = NULL;
}
/*
void	del(void *content)
{
	free(content);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

int	ft_lstsize(t_list *lst)
{
	int	c;

	c = 0;
	while (lst != 0)
	{
		c++;
		lst = lst->next;
	}
	return (c);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
}

#include<stdio.h>

int main()
{
	t_list *lst = ft_lstnew(strdup("Hello"));
	t_list *lst1 = ft_lstnew(strdup("welcome"));
	t_list *lst2 = ft_lstnew(strdup("to"));
	t_list *lst3 = ft_lstnew(strdup("new"));
	t_list *lst4 = ft_lstnew(strdup("Home"));

	ft_lstadd_back(&lst,lst1);
	ft_lstadd_back(&lst,lst2);
	ft_lstadd_back(&lst,lst3);
	ft_lstadd_back(&lst,lst4);

	printf("nb = %d\n", ft_lstsize(lst));

	t_list *current = lst;
	while (current->next != lst2)
		current = current->next;
	current->next = lst2->next;
	lst2->next = NULL;

	ft_lstclear(&lst2, del);
	printf("na = %d\n", ft_lstsize(lst));
	return 0;
}
*/
