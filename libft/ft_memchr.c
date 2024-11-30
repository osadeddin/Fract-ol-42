/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osadeddi <osadeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:15:44 by osadeddi          #+#    #+#             */
/*   Updated: 2024/09/01 20:04:30 by osadeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	ch;

	str = (unsigned char *)s;
	ch = (unsigned char)c;
	while (n--)
	{
		if (*str == ch)
			return (str);
		str++;
	}
	return (0);
}

/*
int	main()
{
	char str[] = "Hello World!";
	char *ret;
	ret = ft_memchr(str, 'o', 12);
	printf("String after 'o' is %s\n", ret);
	return (0);
}
*/
