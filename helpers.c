/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osadeddi <osadeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:32:58 by osadeddi          #+#    #+#             */
/*   Updated: 2024/11/27 16:42:10 by osadeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	exit_fract(t_fract *fract)
{
	ft_printf("\n\n~~~Exiting Fract-ol~~~\n");
	mlx_destroy_image(fract->mlx, fract->img.img);
	mlx_destroy_window(fract->mlx, fract->win);
	mlx_destroy_display(fract->mlx);
	free(fract->mlx);
	free(fract->name);
	exit(EXIT_SUCCESS);
}

double	scale_fract(double value, double set_min, double set_max,
		double win_size)
{
	return (set_min + (value * (set_max - set_min) / win_size));
}

void	put_controls(t_fract *p)
{
	mlx_string_put(p->mlx, p->win, 10, 10, 0x0, "Controls:");
	mlx_string_put(p->mlx, p->win, 10, 22, 0x0, "\"ESC\" to exit");
	mlx_string_put(p->mlx, p->win, 10, 34, 0x0, "\"arrow keys\" to shift");
	mlx_string_put(p->mlx, p->win, 10, 46, 0x0,
		"\"+/-\" to change Max_iterations");
	mlx_string_put(p->mlx, p->win, 10, 58, 0x0,
		"\"SPACE\" to change color palette");
	mlx_string_put(p->mlx, p->win, 10, 70, 0x0,
		"\"mouse scroll\" to zoom in/out");
	mlx_string_put(p->mlx, p->win, 10, 82, 0x0,
		"\"mouse R_Click\" toggle color shift");
	if (p->set == 2)
		mlx_string_put(p->mlx, p->win, 10, 94, 0x0,
			"\"mouse L_Click\" to change Julia set");
	if (p->set == 3)
	{
		mlx_string_put(p->mlx, p->win, 10, 94, 0x0,
			"\"numkey 2, 3\" to change Newton set");
		mlx_string_put(p->mlx, p->win, 10, 106, 0x0,
			"\"numkey 4, 5\" to change Newton's a");
	}
}
