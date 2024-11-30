/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osadeddi <osadeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:31:27 by osadeddi          #+#    #+#             */
/*   Updated: 2024/11/27 16:42:10 by osadeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_name(t_fract *fract, char **argv)
{
	char	*tmp;

	tmp = ft_strjoin("fract-ol (", argv[1]);
	if (!tmp)
		exit(EXIT_FAILURE);
	fract->name = ft_strjoin(tmp, ")");
	free(tmp);
	if (!fract->name)
		exit(EXIT_FAILURE);
}

static void	init_error(t_fract *fract)
{
	ft_putstr_fd("MLX Error\n", 2);
	if (fract->img.img)
		mlx_destroy_image(fract->mlx, fract->img.img);
	if (fract->win)
		mlx_destroy_window(fract->mlx, fract->win);
	if (fract->mlx)
	{
		mlx_destroy_display(fract->mlx);
		free(fract->mlx);
	}
	free(fract->name);
	exit(EXIT_FAILURE);
}

static void	init_message(void)
{
	ft_printf("\n~~~Welcome to Fract-ol~~~\n\n");
	ft_printf("Controls:\n-----------------\n");
	ft_printf("Press \"ESC\" to exit\n");
	ft_printf("Use \"arrow keys\" to shift\n");
	ft_printf("Use \"+/-\" to change Max_iterations\n");
	ft_printf("Use \"SPACE\" to change color palette\n");
	ft_printf("Use \"mouse scroll\" to zoom in/out\n");
	ft_printf("Use \"mouse left click\" to change Julia set\n");
	ft_printf("Use \"mouse right click\" to turn ON/OFF color shift\n");
	ft_printf("Use \"1/2\" to change Newton's n\n");
	ft_printf("Use \"4/5\" to change Newton's a\n");
	ft_printf("-----------------\n\n");
}

static void	init_values(t_fract *fract)
{
	if (fract->set == 1)
		fract->max_iter = 80;
	else if (fract->set == 2)
		fract->max_iter = 200;
	else
		fract->max_iter = 30;
	fract->julia.x = 0.0;
	fract->julia.y = 0.0;
	fract->shift_x = 0.0;
	fract->shift_y = 0.0;
	fract->palette = 1;
	fract->zoom = 1.0;
	fract->clr_shift = 0;
	fract->clr_delay = 0;
	fract->clr_set = 0;
	fract->newton.a = 1.2;
	fract->newton.n = 3;
	fract->newton.tolerance = 0.000001;
}

void	fract_init(t_fract *fract)
{
	fract->mlx = mlx_init();
	if (!fract->mlx)
		init_error(fract);
	fract->win = mlx_new_window(fract->mlx, WIDTH, HEIGHT, fract->name);
	if (!fract->win)
		init_error(fract);
	fract->img.img = mlx_new_image(fract->mlx, WIDTH, HEIGHT);
	if (!fract->img.img)
		init_error(fract);
	fract->img.addr = mlx_get_data_addr(fract->img.img, &fract->img.bpp,
			&fract->img.line_len, &fract->img.endian);
	if (!fract->img.addr)
		init_error(fract);
	init_values(fract);
	init_message();
	mlx_hook(fract->win, KeyPress, KeyPressMask, key_hook, fract);
	mlx_hook(fract->win, ButtonPress, ButtonPressMask, mouse_hook, fract);
	mlx_hook(fract->win, DestroyNotify, 0, exit_fract, fract);
}
