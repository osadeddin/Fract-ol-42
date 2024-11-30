/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osadeddi <osadeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:22:17 by osadeddi          #+#    #+#             */
/*   Updated: 2024/08/29 17:46:11 by osadeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*p;

	if (!lst || !f)
		return ;
	p = lst;
	while (p)
	{
		f(p->content);
		p = p->next;
	}
}
/*
void	ft_putstr(void *content)
{
	char	*str;

	str = (char *)content;
	while(*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
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

int	main(void)
{
	t_list	*lst;
	t_list	*new;
	t_list	*new2;
	t_list	*new3;

	lst = ft_lstnew("Hello");
	new = ft_lstnew("World");
	new2 = ft_lstnew("42");
	new3 = ft_lstnew("Paris");
	lst->next = new;
	new->next = new2;
	new2->next = new3;
	ft_lstiter(lst, &ft_putstr);
	return (0);
}
*/
