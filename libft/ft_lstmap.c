/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osadeddi <osadeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:44:56 by osadeddi          #+#    #+#             */
/*   Updated: 2024/09/03 18:40:06 by osadeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*p;
	t_list	*new;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	if (!new)
		return (NULL);
	p = lst->next;
	while (p)
	{
		tmp = ft_lstnew(f(p->content));
		if (!tmp)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, tmp);
		p = p->next;
	}
	return (new);
}
/*
void	*ft_uppercase(void *content)
{
	char	*str;
	char	*new;
	int		i;

	str = (char *)content;
	new = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (str[i])
	{
		new[i] = ft_toupper(str[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}

void	ft_lstclear2(t_list **lst, void (*del)(void *))
{
	t_list	*p;
	t_list	*tmp;

	if (!lst || !del)
		return ;
	p = *lst;
	while (p)
	{
		tmp = p->next;
		del(p->content);
		free(p);
		p = tmp;
	}
	*lst = NULL;
}

int	main(void)
{
	t_list	*lst;
	t_list	*new;
	t_list	*tmp;

	lst = ft_lstnew("Hello");
	tmp = ft_lstnew("World");
	ft_lstadd_back(&lst, tmp);
	new = ft_lstmap(lst, &ft_uppercase, &ft_lstclear2);
	if (!new)
		return (1);
	ft_lstclear(&new, &ft_lstclear);
	return (0);
}
*/
