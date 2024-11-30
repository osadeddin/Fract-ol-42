/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osadeddi <osadeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 22:19:52 by osadeddi          #+#    #+#             */
/*   Updated: 2024/09/03 18:49:27 by osadeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	a;
	size_t	dst_s;
	size_t	src_s;

	i = 0;
	j = 0;
	dst_s = ft_strlen(dest);
	src_s = ft_strlen(src);
	a = size - dst_s - 1;
	if (size <= dst_s)
		return (src_s + size);
	while (dest[i])
		i++;
	while (src[j] && j < a)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dst_s + src_s);
}

/*
#include <stdio.h>

int	main(void)
{
	char			a[10] = "hello";
	char			b[] = " world";
	unsigned int	c;
	unsigned int	d;

	c = 10;
	d = ft_strlcat(a,b,c);
	printf("a = %s, len = %d",a,d);
	return (0);
}
*/
