/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osadeddi <osadeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 01:48:24 by osadeddi          #+#    #+#             */
/*   Updated: 2024/09/03 18:49:32 by osadeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	b;

	b = 0;
	while (s[b])
		b++;
	return (b);
}
/*
void main()
{
	char a[] = "omar";

	ft_strlen(a);
	printf(" a length is %d", ft_strlen(a));
}
#include<stdio.h>
*/
