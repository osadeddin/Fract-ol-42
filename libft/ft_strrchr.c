/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osadeddi <osadeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:35:47 by osadeddi          #+#    #+#             */
/*   Updated: 2024/09/03 19:04:17 by osadeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (0);
}

// #include <string.h>
// #include <stdio.h>
// int main()
// {
// 	char str[] = "Hello World!";
// 	char c = 'l';
// 	printf("%s\n", ft_strrchr(str, c));
// 	printf("%s\n", str);
// 	printf("%s\n", strrchr(str, c));
// 	printf("%s\n", str);
// 	return 0;
// }
