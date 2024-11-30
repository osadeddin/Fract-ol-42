/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osadeddi <osadeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:58:14 by osadeddi          #+#    #+#             */
/*   Updated: 2024/09/03 18:48:04 by osadeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nlen(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	o;
	int		len;

	o = n;
	len = nlen(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	if (o < 0)
	{
		str[0] = '-';
		o *= -1;
	}
	else if (o == 0)
		str[0] = '0';
	str[len--] = '\0';
	while (o > 0)
	{
		str[len--] = o % 10 + '0';
		o /= 10;
	}
	return (str);
}
// #include <stdio.h>

// int	main(void)
// {
// 	printf("str = %s\n", ft_itoa(-123));
// 	printf("str = %s\n", ft_itoa(123));
// 	printf("str = %s\n", ft_itoa(0));
// 	return (0);
// }
