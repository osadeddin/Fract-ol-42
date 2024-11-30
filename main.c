/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osadeddi <osadeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:49:55 by osadeddi          #+#    #+#             */
/*   Updated: 2024/11/17 20:09:53 by osadeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fract	fract;

	if (2 == argc && (!ft_strncmp(argv[1], "mandel", 10) || !ft_strncmp(argv[1],
				"julia", 5) || !ft_strncmp(argv[1], "newton", 6)))
	{
		if (!ft_strncmp(argv[1], "mandel", 10))
			fract.set = 1;
		else if (!ft_strncmp(argv[1], "julia", 5))
			fract.set = 2;
		else
			fract.set = 3;
		init_name(&fract, argv);
		fract_init(&fract);
		mlx_loop_hook(fract.mlx, put_fract, &fract);
		mlx_loop(fract.mlx);
	}
	else
	{
		ft_putstr_fd(ERROR_MSG, 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
