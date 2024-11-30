/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osadeddi <osadeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:57:43 by osadeddi          #+#    #+#             */
/*   Updated: 2024/09/07 17:35:14 by osadeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex(long s, char *hex)
{
	char	h[17];
	int		i;
	int		count;

	if (s == 0)
		return (pf_putchar('0'));
	i = 0;
	count = 0;
	while (s > 0)
	{
		h[i] = hex[s % 16];
		s /= 16;
		i++;
	}
	h[i] = '\0';
	while (--i >= 0)
	{
		write(1, &h[i], 1);
		count++;
	}
	return (count);
}

int	ft_puthex_p(unsigned long s, char *hex)
{
	char	h[17];
	int		i;
	int		count;

	if (s == 0)
		return (pf_putstr("(nil)"));
	i = 0;
	count = 0;
	count += pf_putstr("0x");
	while (s > 0)
	{
		h[i] = hex[s % 16];
		s /= 16;
		i++;
	}
	h[i] = '\0';
	while (--i >= 0)
	{
		write(1, &h[i], 1);
		count++;
	}
	return (count);
}
// int	main(void)
// {
// 	char	a[] = "Coucou\ntu vas b\tien ?";
// 	ft_puthex(a, "0123456789abcdef");
// 	return (0);
// }
