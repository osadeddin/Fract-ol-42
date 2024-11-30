/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osadeddi <osadeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:29:50 by osadeddi          #+#    #+#             */
/*   Updated: 2024/11/24 19:14:04 by osadeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*sel_type(char i, va_list pa, int *res)
{
	if (i == 'c')
		(*res) += pf_putchar((unsigned char)va_arg(pa, int));
	else if (i == 's')
		(*res) += pf_putstr(va_arg(pa, char *));
	else if (i == 'd' || i == 'i')
		(*res) += pf_putnbr(va_arg(pa, int));
	else if (i == 'x')
		(*res) += ft_puthex(va_arg(pa, unsigned int), "0123456789abcdef");
	else if (i == 'X')
		(*res) += ft_puthex(va_arg(pa, unsigned int), "0123456789ABCDEF");
	else if (i == 'p')
		(*res) += ft_puthex_p(va_arg(pa, unsigned long), "0123456789abcdef");
	else if (i == 'u')
		(*res) += pf_putnbr_unsigned(va_arg(pa, unsigned int));
	else if (i == 'f')
		(*res) += pf_putfloat(va_arg(pa, double), 4);
	else if (i == '%')
		(*res) += pf_putchar('%');
	else
		return (NULL);
	return (pa);
}

static int	read_args(char *l, va_list pa)
{
	int	j;
	int	res;

	j = 0;
	res = 0;
	while (l[j])
	{
		if (l[j] == '%' && l[j + 1])
		{
			if (sel_type(l[j + 1], pa, &res) == NULL)
				return (-1);
			j += 2;
		}
		else
		{
			pf_putchar(l[j++]);
			res++;
		}
	}
	return (res);
}

int	ft_printf(const char *l, ...)
{
	va_list	pa;
	int		i;

	va_start(pa, l);
	i = read_args((char *)l, pa);
	va_end(pa);
	return (i);
}

/*
int	main(void)
{
	int	num;

	num = 42;
	printf(", s = %d\n",ft_printf("ft_Character %%c: %c", 'A') - 3);
	printf(", s = %d\n",ft_printf("ft_String %%s: %s", "Hello, World!") - 3);
	printf(", s = %d\n",ft_printf("ft_Decimal %%d: %d", 12345) - 3);
	printf(", s = %d\n",ft_printf("ft_int %%i: %i", 12345) - 3);
	printf(", s = %d\n",ft_printf("ft_Hexadecimal %%x: %x", 255) - 3);
	printf(", s = %d\n",ft_printf("ft_Hexadecimal %%X: %X", 255) - 3);
	printf(", s = %d\n",ft_printf("ft_Pointer %%p: %p", (void *)&num) - 3);
	printf(", s = %d\n",ft_printf("ft_Unsigned %%u: %u", 4294967295u) - 3);
	printf(", s = %d\n\n",ft_printf("ft_Percent Sign %%: %%") - 3);
	printf(", s = %d\n",printf("Character %%c: %c", 'A'));
	printf(", s = %d\n",printf("String %%s: %s", "Hello, World!"));
	printf(", s = %d\n",printf("Decimal %%d: %d", 12345));
	printf(", s = %d\n",printf("int %%i: %i", 12345));
	printf(", s = %d\n",printf("Hexadecimal %%x: %x", 255));
	printf(", s = %d\n",printf("Hexadecimal %%X: %X", 255));
	printf(", s = %d\n",printf("Pointer %%p: %p", (void *)&num));
	printf(", s = %d\n",printf("Unsigned %%u: %u", 4294967295u));
	printf(", s = %d\n\n",printf("Percent Sign %%: %%"));
	return (0);
}
*/
