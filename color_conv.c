/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osadeddi <osadeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:35:46 by osadeddi          #+#    #+#             */
/*   Updated: 2024/11/18 15:36:34 by osadeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	srgb_to_rgb(double color)
{
	if (color <= 0.04045)
	{
		return (color / 12.92);
	}
	return (pow((color + 0.055) / 1.055, GAMMA));
}

static double	rgb_to_srgb(double color)
{
	if (color <= 0.0031308)
	{
		return (color * 12.92);
	}
	return (1.055 * pow(color, 1.0 / GAMMA) - 0.055);
}

t_rgb	get_rgb(int hex)
{
	t_rgb	color;

	color.r = srgb_to_rgb(((hex >> 16) & 0xFF) / 255.0);
	color.g = srgb_to_rgb(((hex >> 8) & 0xFF) / 255.0);
	color.b = srgb_to_rgb((hex & 0xFF) / 255.0);
	return (color);
}

int	to_hex(t_rgb color)
{
	int	r;
	int	g;
	int	b;

	r = (int)(rgb_to_srgb(color.r) * 255.0);
	g = (int)(rgb_to_srgb(color.g) * 255.0);
	b = (int)(rgb_to_srgb(color.b) * 255.0);
	return ((r << 16) | (g << 8) | b);
}
