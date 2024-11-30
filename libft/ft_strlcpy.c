/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osadeddi <osadeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:22:57 by osadeddi          #+#    #+#             */
/*   Updated: 2024/09/03 18:49:29 by osadeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i);
}
/*
#include<stdio.h>

int	main(void)
{
	char a[] = "hello world";
	char b[5];
	unsigned int c = 5;
	unsigned int d;

	d = ft_strlcpy(b,a,c);
	printf("a = %s, len = %d\nb = %s, len = %d" , a , d+1 , b , c);
	return (0);
}
*/
