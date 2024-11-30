/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osadeddi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:28:20 by osadeddi          #+#    #+#             */
/*   Updated: 2024/11/20 18:29:08 by osadeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	atof_helper(char *str, int i, double *res)
{
	double	factor;

	if (str[i] == '.')
	{
		i++;
		factor = 0.1;
		while (str[i] >= '0' && str[i] <= '9')
		{
			*res += (str[i] - '0') * factor;
			factor *= 0.1;
			i++;
		}
	}
}

double	ft_atof(char *str)
{
	double	res;
	int		i;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	atof_helper(str, i, &res);
	return (res * sign);
}
