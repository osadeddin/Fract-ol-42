/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osadeddi <osadeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:07:01 by osadeddi          #+#    #+#             */
/*   Updated: 2024/11/17 19:05:04 by osadeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_color	*color_palette2(t_fract *p, t_color *palette)
{
	if (p->palette == 3)
	{
		palette[0].hex = 0x330000;
		palette[1].hex = 0x661400;
		palette[2].hex = 0xCC3300;
		palette[3].hex = 0xFF6600;
		palette[4].hex = 0xFFCC00;
		palette[5].hex = 0xFFFF99;
	}
	else
	{
		palette[0].hex = 0x000000;
		palette[1].hex = 0x00FF00;
		palette[2].hex = 0x00FFFF;
		palette[3].hex = 0xFF00FF;
		palette[4].hex = 0xFF1493;
		palette[5].hex = 0xFF4500;
	}
	return (palette);
}

t_color	*color_palette(t_fract *p)
{
	static t_color	palette[6];

	if (p->palette > 4)
		p->palette %= 4;
	else if (p->palette == 1)
	{
		palette[0].hex = 0x0000FF;
		palette[1].hex = 0xFF0000;
		palette[2].hex = 0xFF00FF;
		palette[3].hex = 0x00FF00;
		palette[4].hex = 0x0000FF;
		palette[5].hex = 0xFFFF00;
	}
	else if (p->palette == 2)
	{
		palette[0].hex = 0x0000FF;
		palette[1].hex = 0x00FFFF;
		palette[2].hex = 0x00FF00;
		palette[3].hex = 0xFFFF00;
		palette[4].hex = 0xFFA500;
		palette[5].hex = 0xFF0000;
	}
	else
		return (color_palette2(p, palette));
	return (palette);
}

int	interpolate_color(int color1, int color2, double t)
{
	t_rgb	c1;
	t_rgb	c2;
	t_rgb	result;

	c1 = get_rgb(color1);
	c2 = get_rgb(color2);
	result.r = c1.r + t * (c2.r - c1.r);
	result.g = c1.g + t * (c2.g - c1.g);
	result.b = c1.b + t * (c2.b - c1.b);
	return (to_hex(result));
}

int	choose_color(int i, t_color *palette, t_fract *p)
{
	double	t;
	int		index;
	int		next_index;
	double	position;

	if (p->set == 3 && i == 0)
		return (0x0);
	position = (p->clr_shift + (double)i) / p->max_iter * PALETTE_SIZE;
	index = (int)position % PALETTE_SIZE;
	next_index = (index + 1) % PALETTE_SIZE;
	t = position - (int)position;
	return (interpolate_color(palette[index].hex, palette[next_index].hex, t));
}
