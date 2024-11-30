/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osadeddi <osadeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:05:24 by osadeddi          #+#    #+#             */
/*   Updated: 2024/09/03 18:48:45 by osadeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
		str[i++] = c;
	return (s);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main()
{
	char str[50] = "Hello World!";
	printf("%s\n", str);
	ft_memset(str + 6, 'a', 5);
	printf("%s\n", str);
}
*/
