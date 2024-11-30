/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osadeddi <osadeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:33:00 by osadeddi          #+#    #+#             */
/*   Updated: 2024/09/03 18:49:11 by osadeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}

// #include <string.h>
// #include <stdio.h>

// int	main()
// {
// 	char str[] = "teste";
// 	char c = '\0';
// 	printf("%s\n", ft_strchr(str, c));
// 	printf("%s\n", str);
// 	printf("%s\n", strchr(str, c));
// 	printf("%s\n", str);
// 	return 0;
// }
