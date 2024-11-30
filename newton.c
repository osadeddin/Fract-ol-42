/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osadeddi <osadeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:28:01 by osadeddi          #+#    #+#             */
/*   Updated: 2024/11/20 17:31:15 by osadeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	polynomial(t_fract *p, double r_squared, double theta)
{
	double	n_theta;

	p->newton.z_mag = pow(r_squared, (p->newton.n - 1) / 2.0);
	n_theta = p->newton.n * theta;
	p->newton.pz.x = p->newton.z_mag * cos(n_theta) - 1;
	p->newton.pz.y = p->newton.z_mag * sin(n_theta);
}

static void	poly_derivative(t_fract *p, double r_squared, double theta)
{
	double	n_minus_1_theta;

	p->newton.z_mag = pow(r_squared, (p->newton.n - 2) / 2.0);
	n_minus_1_theta = (p->newton.n - 1) * theta;
	p->newton.dpz.x = p->newton.n * p->newton.z_mag * cos(n_minus_1_theta);
	p->newton.dpz.y = p->newton.n * p->newton.z_mag * sin(n_minus_1_theta);
}

static void	denomenator(t_fract *p)
{
	p->newton.denominator = p->newton.dpz.x * p->newton.dpz.x + p->newton.dpz.y
		* p->newton.dpz.y;
	p->newton.next_z.x = p->newton.z.x - p->newton.a * ((p->newton.pz.x
				* p->newton.dpz.x + p->newton.pz.y * p->newton.dpz.y)
			/ p->newton.denominator);
	p->newton.next_z.y = p->newton.z.y - p->newton.a * ((p->newton.pz.y
				* p->newton.dpz.x - p->newton.pz.x * p->newton.dpz.y)
			/ p->newton.denominator);
	p->newton.delta_x = p->newton.next_z.x - p->newton.z.x;
	p->newton.delta_y = p->newton.next_z.y - p->newton.z.y;
	p->newton.magnitude = p->newton.delta_x * p->newton.delta_x
		+ p->newton.delta_y * p->newton.delta_y;
}

void	newton(int x, int y, t_fract *p)
{
	int	i;

	p->newton.z.x = scale_fract(x, -2 * p->zoom, 2 * p->zoom, WIDTH)
		+ p->shift_x;
	p->newton.z.y = scale_fract(y, 2 * p->zoom, -2 * p->zoom, HEIGHT)
		+ p->shift_y;
	i = 0;
	while (i < p->max_iter)
	{
		p->newton.r_squared = p->newton.z.x * p->newton.z.x
			+ p->newton.z.y * p->newton.z.y;
		p->newton.theta = atan2(p->newton.z.y, p->newton.z.x);
		polynomial(p, p->newton.r_squared, p->newton.theta);
		poly_derivative(p, p->newton.r_squared, p->newton.theta);
		denomenator(p);
		if (p->newton.magnitude < p->newton.tolerance * p->newton.tolerance)
			break ;
		p->newton.z = p->newton.next_z;
		i++;
	}
	if (i == p->max_iter)
		my_mlx_pixel_put(p, x, y, 0x0);
	else
		my_mlx_pixel_put(p, x, y, choose_color(i, color_palette(p), p));
}

// f(z) = z^n - 1
// f'(z) = n*z^(n-1)
// r^2 = x^2 + y^2
// theta = atan2(y, x)
// z = r*cos(theta) + i*r*sin(theta)
// z+1 = z - a*f(z)/f'(z)
