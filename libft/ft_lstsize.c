/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osadeddi <osadeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:31:04 by osadeddi          #+#    #+#             */
/*   Updated: 2024/09/03 18:48:30 by osadeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
/*
void ft_lstadd_back(t_list **lst, t_list *new)
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
	while(last->next)
		last = last->next;
	last->next = new;
}

void *ft_lstnew(void *content)
{
	t_list *new;

	new = malloc(sizeof(t_list));
	if(!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

int 	main()
{
	t_list	*new1 = ft_lstnew("Hello");
	t_list	*new = ft_lstnew("World");
	ft_lstadd_back(&new1, new);
	printf("%s\n", (char *)new1->content);
	printf("%s\n", (char *)new1->next->content);
	printf("%d\n", ft_lstsize(new1));
	return 0;
}
*/
