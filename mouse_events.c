/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osadeddi <osadeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:53:32 by osadeddi          #+#    #+#             */
/*   Updated: 2024/11/27 16:45:50 by osadeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom_shift(t_fract *p, int x, int y)
{
	int	u;
	int	l;
	int	r;
	int	d;

	u = 0;
	l = 0;
	r = 0;
	d = 0;
	if (x < WIDTH / 3)
		l = 1;
	else if (x > WIDTH * 2 / 3)
		r = 1;
	if (y < HEIGHT / 3)
		u = 1;
	else if (y > HEIGHT * 2 / 3)
		d = 1;
	if (l == 1)
		p->shift_x -= (SHIFTFAC * p->zoom);
	else if (r == 1)
		p->shift_x += (SHIFTFAC * p->zoom);
	if (u == 1)
		p->shift_y += (SHIFTFAC * p->zoom);
	else if (d == 1)
		p->shift_y -= (SHIFTFAC * p->zoom);
}

void	check_click(int button, int x, int y, t_fract *p)
{
	if (button == M_L_CLICK && p->set == 2)
	{
		p->julia.x = scale_fract(x, -2 * p->zoom, 2 * p->zoom, WIDTH)
			+ p->shift_x;
		p->julia.y = scale_fract(y, 2 * p->zoom, -2 * p->zoom, HEIGHT)
			+ p->shift_y;
		ft_printf("New Julia set: %f + %fi\n", p->julia.x, p->julia.y);
	}
	else if (button == M_R_CLICK)
	{
		if (p->clr_set == 1)
		{
			p->clr_set = 0;
			ft_printf("Color shift off\n");
		}
		else
		{
			p->clr_set = 1;
			ft_printf("Color shift on\n");
		}
	}
}

int	mouse_hook(int button, int x, int y, t_fract *p)
{
	if (button == M_SCRL_UP)
	{
		p->zoom /= ZOOMFAC;
		if (p->set != 3)
			p->max_iter *= ITER_MULT;
		zoom_shift(p, x, y);
		ft_printf("zoom: %f%%\n", 100 / p->zoom);
		if (p->set != 3)
			ft_printf("Max_iter: %f\n", p->max_iter);
	}
	else if (button == M_SCRL_DOWN)
	{
		p->zoom *= ZOOMFAC;
		if (p->set != 3)
			p->max_iter /= ITER_MULT;
		zoom_shift(p, x, y);
		ft_printf("zoom: %f%%\n", 100 / p->zoom);
		if (p->set != 3)
			ft_printf("Max_iter: %f\n", p->max_iter);
	}
	check_click(button, x, y, p);
	return (0);
}
