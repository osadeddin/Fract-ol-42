/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_fract.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osadeddi <osadeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 20:04:59 by osadeddi          #+#    #+#             */
/*   Updated: 2024/11/27 16:53:36 by osadeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_fract *fract, int x, int y, int color)
{
	char	*dst;

	dst = fract->img.addr + (y * fract->img.line_len + x * (fract->img.bpp
				/ 8));
	*(unsigned int *)dst = color;
}

void	mandel(int x, int y, t_fract *p)
{
	t_complex	z;
	t_complex	c;
	double		tmp;
	int			i;

	i = 0;
	z.x = 0;
	z.y = 0;
	c.x = scale_fract(x, -2 * p->zoom, 2 * p->zoom, WIDTH) + p->shift_x;
	c.y = scale_fract(y, 2 * p->zoom, -2 * p->zoom, HEIGHT) + p->shift_y;
	while (i < (int)p->max_iter)
	{
		tmp = z.x * z.x - z.y * z.y + c.x;
		z.y = 2 * z.x * z.y + c.y;
		z.x = tmp;
		i++;
		if (z.x * z.x + z.y * z.y > 4)
			break ;
	}
	if (i == (int)p->max_iter)
		my_mlx_pixel_put(p, x, y, 0x0);
	else
		my_mlx_pixel_put(p, x, y, choose_color(i, color_palette(p), p));
}

void	julia(int x, int y, t_fract *fract)
{
	t_complex	z;
	double		tmp;
	int			i;

	i = 0;
	z.x = scale_fract(x, -2 * fract->zoom, 2 * fract->zoom, WIDTH)
		+ fract->shift_x;
	z.y = scale_fract(y, 2 * fract->zoom, -2 * fract->zoom, HEIGHT)
		+ fract->shift_y;
	while (i < (int)fract->max_iter)
	{
		tmp = z.x * z.x - z.y * z.y + fract->julia.x;
		z.y = 2 * z.x * z.y + fract->julia.y;
		z.x = tmp;
		i++;
		if (z.x * z.x + z.y * z.y > 4)
			break ;
	}
	if (i == (int)fract->max_iter)
		my_mlx_pixel_put(fract, x, y, 0x0);
	else
		my_mlx_pixel_put(fract, x, y, choose_color(i, color_palette(fract),
				fract));
}

static void	color_shift(t_fract *p)
{
	if (p->clr_set == 1)
	{
		p->clr_delay++;
		if (p->clr_delay == 1)
		{
			p->clr_shift++;
			p->clr_delay = 0;
		}
	}
}

int	put_fract(t_fract *p)
{
	int	x;
	int	y;

	y = -1;
	while (++y < WIDTH)
	{
		x = -1;
		while (++x < HEIGHT)
		{
			if (p->set == 1)
				mandel(x, y, p);
			else if (p->set == 2)
				julia(x, y, p);
			else
				newton(x, y, p);
		}
	}
	mlx_put_image_to_window(p->mlx, p->win, p->img.img, 0, 0);
	put_controls(p);
	color_shift(p);
	return (0);
}
