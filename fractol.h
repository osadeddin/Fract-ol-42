/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osadeddi <osadeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:44:43 by osadeddi          #+#    #+#             */
/*   Updated: 2024/11/27 17:05:37 by osadeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

//# include "minilibx-linux/mlx.h"
# include <minilibx-linux/mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <libft.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <float.h>

# define ERROR_MSG "Available Commands:\n1- ./fractol mandel\n2-\
 ./fractol julia\n2- ./fractol newton\n"
# define WIDTH 500
# define HEIGHT 500
# define GAMMA 2.2
# define PALETTE_SIZE 6
# define M_SCRL_UP 4
# define M_SCRL_DOWN 5
# define M_L_CLICK 1
# define M_R_CLICK 3
# define ZOOMFAC 1.1
# define SHIFTFAC 0.1
# define ITER_MULT 1.006
# define PLUS_KEY 65451
# define MINUS_KEY 65453
# define NUM_KEY_1 65433
# define NUM_KEY_2 65436
# define NUM_KEY_4 65430
# define NUM_KEY_5 65437

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}				t_img;

typedef struct s_complex
{
	double		x;
	double		y;
}				t_complex;

typedef struct s_newton
{
	double		a;
	int			n;
	double		tolerance;
	double		magnitude;
	double		z_mag;
	double		denominator;
	double		r_squared;
	double		theta;
	double		delta_x;
	double		delta_y;
	t_complex	z;
	t_complex	pz;
	t_complex	dpz;
	t_complex	next_z;
}				t_newton;

typedef struct s_julia
{
	double		x;
	double		y;
}				t_julia;

typedef struct s_fract
{
	void		*mlx;
	void		*win;
	char		*name;
	int			set;
	float		max_iter;
	double		shift_x;
	double		shift_y;
	int			palette;
	double		zoom;
	int			clr_shift;
	int			clr_delay;
	int			clr_set;
	t_newton	newton;
	t_julia		julia;
	t_img		img;
}				t_fract;

typedef struct s_color
{
	int			hex;
}				t_color;

typedef struct s_rgb
{
	double		r;
	double		g;
	double		b;
}				t_rgb;

int		key_hook(int keysym, t_fract *p);
int		mouse_hook(int button, int x, int y, t_fract *p);
void	fract_init(t_fract *fract);
void	init_name(t_fract *fract, char **argv);
int		put_fract(t_fract *fract);
int		choose_color(int i, t_color *palette, t_fract *p);
t_color	*color_palette(t_fract *p);
double	scale_fract(double value, double set_min, double set_max,
			double win_size);
int		exit_fract(t_fract *fract);
void	newton(int x, int y, t_fract *p);
void	my_mlx_pixel_put(t_fract *fract, int x, int y, int color);
void	shift_func(int keysym, t_fract *p);
void	put_controls(t_fract *p);
int		to_hex(t_rgb color);
t_rgb	get_rgb(int hex);

#endif
