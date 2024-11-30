/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osadeddi <osadeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:43:09 by osadeddi          #+#    #+#             */
/*   Updated: 2024/09/03 18:48:14 by osadeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
void	*ft_lstnew(void *content)
{
	t_list *new;

	new = malloc(sizeof(t_list));
	if(!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

int main()
{
	t_list	*new1 = ft_lstnew("Hello");
	t_list	*new = ft_lstnew("World");
	ft_lstadd_front(&new1, new);
	printf("%s\n", (char *)new1->content);
	printf("%s\n", (char *)new1->next->content);
	return 0;
}
*/
