/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osadeddi <osadeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:57:18 by osadeddi          #+#    #+#             */
/*   Updated: 2024/11/27 16:42:10 by osadeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	shift_func(int keysym, t_fract *p)
{
	if (keysym == XK_Up)
		p->shift_y += (SHIFTFAC * p->zoom);
	if (keysym == XK_Down)
		p->shift_y -= (SHIFTFAC * p->zoom);
	if (keysym == XK_Left)
		p->shift_x -= (SHIFTFAC * p->zoom);
	if (keysym == XK_Right)
		p->shift_x += (SHIFTFAC * p->zoom);
}

void	newton_hooks(int keysym, t_fract *p)
{
	if (keysym == NUM_KEY_1)
	{
		p->newton.n++;
		ft_printf("Newton n: %d\n", p->newton.n);
	}
	if (keysym == NUM_KEY_2)
	{
		p->newton.n--;
		ft_printf("Newton n: %d\n", p->newton.n);
	}
	if (keysym == NUM_KEY_4)
	{
		p->newton.a += 0.1;
		ft_printf("Newton a: %f\n", p->newton.a);
	}
	if (keysym == NUM_KEY_5)
	{
		p->newton.a -= 0.1;
		ft_printf("Newton a: %f\n", p->newton.a);
	}
}

int	key_hook(int keysym, t_fract *p)
{
	if (keysym == XK_Escape)
		exit_fract(p);
	shift_func(keysym, p);
	if (p->set == 3)
		newton_hooks(keysym, p);
	if (keysym == PLUS_KEY)
	{
		p->max_iter += 10;
		ft_printf("Max_iter: %f\n", p->max_iter);
	}
	if (keysym == MINUS_KEY)
	{
		p->max_iter -= 10;
		ft_printf("Max_iter: %f\n", p->max_iter);
	}
	if (keysym == XK_space)
	{
		p->palette++;
		ft_printf("Palette: %d\n", p->palette - 1);
	}
	return (0);
}
