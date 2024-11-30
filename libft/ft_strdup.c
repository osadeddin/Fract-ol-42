/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osadeddi <osadeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:09:00 by osadeddi          #+#    #+#             */
/*   Updated: 2024/09/03 18:49:13 by osadeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*p;
	char	*str;
	int		i;

	i = 0;
	while (src[i])
		i++;
	str = malloc(i + 1);
	if (str == NULL)
		return (NULL);
	p = str;
	while (*src)
		*p++ = *src++;
	*p = '\0';
	return (str);
}
/*
#include<stdio.h>
int	main(void)
{
	char	a[] = "la la la laaaaa";
	char	*b;

	b = ft_strdup(a);
	printf("a = %s\nb = %s\n",a,b);
	free(b);
}
*/
