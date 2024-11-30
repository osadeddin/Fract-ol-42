/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osadeddi <osadeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:00:23 by osadeddi          #+#    #+#             */
/*   Updated: 2024/11/24 19:25:12 by osadeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pf_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	pf_putstr(char *s)
{
	int	i;

	if (!s)
		return (pf_putstr("(null)"));
	i = 0;
	while (s[i])
		pf_putchar(s[i++]);
	return (i);
}

int	pf_putnbr(int n)
{
	int		i;
	long	nb;

	i = 0;
	nb = n;
	if (nb < 0)
	{
		pf_putchar('-');
		i++;
		nb = -nb;
	}
	if (nb > 9)
		i += pf_putnbr(nb / 10);
	pf_putchar(nb % 10 + '0');
	i++;
	return (i);
}

int	pf_putnbr_unsigned(unsigned int n)
{
	int		i;

	i = 0;
	if (n > 9)
	{
		i += pf_putnbr_unsigned(n / 10);
	}
	pf_putchar(n % 10 + '0');
	i++;
	return (i);
}

int	pf_putfloat(double n, int dec)
{
	int			i;
	long long	nb;
	double		frac;

	i = 0;
	if (n < 0)
	{
		pf_putchar('-');
		i++;
		n = -n;
	}
	nb = (long long)n;
	frac = n - nb;
	if (nb > 9)
		pf_putfloat(nb / 10, 0);
	i += pf_putchar(nb % 10 + '0');
	if (dec > 0)
		i += pf_putchar('.');
	while (dec--)
	{
		frac *= 10;
		i += pf_putchar((int)frac + '0');
		frac -= (int)frac;
	}
	return (i);
}
