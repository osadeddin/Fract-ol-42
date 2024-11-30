/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osadeddi <osadeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:22:30 by osadeddi          #+#    #+#             */
/*   Updated: 2024/09/03 18:47:17 by osadeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*
#include <stdio.h>
int main()
{
	int i = 0;
	char str[50] = "hello my name is osadeddi";
	char *s;
	ft_bzero(str, 5);
	s = str + 5;
	printf("After bzero str = %s\ns = %s\n", str,s);
	while (i < 50)
	{
		if (str[i] == 0)
			printf("0");
		else
			printf("%c", str[i]);
		i++;
	}
	return 0;
}
*/
