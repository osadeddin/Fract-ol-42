/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osadeddi <osadeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 11:21:18 by osadeddi          #+#    #+#             */
/*   Updated: 2024/08/26 16:26:11 by osadeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/*
#include<stdio.h>

void	main(void)
{
	char	a;
	int		b;

	a = '1';
	b = ft_isdigit(&a);
	printf("%d", b);
}
*/
