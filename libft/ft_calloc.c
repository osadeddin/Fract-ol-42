/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osadeddi <osadeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:38:06 by osadeddi          #+#    #+#             */
/*   Updated: 2024/09/03 18:47:04 by osadeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*ptr;

	ptr = malloc(num * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, num * size);
	return (ptr);
}

/*
int	main()
{
	int *ptr;
	int	*p;

	int n = 5;
	ptr = (int *)ft_calloc(n, sizeof(int));

	if (ptr == NULL)
	{
		printf("Memory not .allocated\n");
		exit(0);
	}
	else
	{
		printf("Memory successfully allocated using calloc\n");
			for (int i = 0; i < n; i++)
			printf("%d ", ptr[i]);
	}
	return (0);
}
*/
