/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:28:42 by tssaito           #+#    #+#             */
/*   Updated: 2025/01/25 16:56:38 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	put_color(t_fractol *fractol, double iter_ratio, int x, int y)
{
	int	index;
	int	color;
	int	green;
	int	blue;
	int	red;

	color = BLACK;
	if (iter_ratio >= 1)
		color = WHITE;
	else if (fractol->type == BURNINGSHIP)
	{
		red = (int)(COLOR_MAX * iter_ratio * RED_INTENS) % (COLOR_MAX + 1);
		green = (int)(COLOR_MAX * iter_ratio) % (COLOR_MAX + 1);
		blue = (int)(COLOR_MAX * iter_ratio) % (COLOR_MAX + 1);
		color = (red * RED_SHIFT) + (green * GREEN_SHIFT) + blue;
	}
	else if (iter_ratio > 0)
	{
		red = (int)(COLOR_MAX * iter_ratio) % (COLOR_MAX + 1);
		green = (int)(COLOR_MAX * iter_ratio * GREEN_INTENS) % (COLOR_MAX + 1);
		blue = (int)(COLOR_MAX * iter_ratio * BLUE_INTENS) % (COLOR_MAX + 1);
		color = (red * RED_SHIFT) + (green * GREEN_SHIFT) + blue;
	}
	index = (y * fractol->bits_line) + (x * fractol->bits_pixel / 8);
	*(int *)(fractol->data_addr + index) = color;
}

static void	calculate_for_mandelbrot(t_fractol *fractol, int x, int y)
{
	int			iter;
	t_complex	z;
	t_complex	c;
	t_complex	z_prev;

	iter = 0;
	z_prev.r = 0.0;
	z_prev.i = 0.0;
	c.r = fractol->min.r + x * (fractol->max.r - fractol->min.r) / WIDTH;
	c.i = fractol->min.i + y * (fractol->max.i - fractol->min.i) / HEIGHT;
	while (iter < fractol->max_iter)
	{
		z.i = 2 * z_prev.r * z_prev.i + c.i;
		z.r = z_prev.r * z_prev.r - z_prev.i * z_prev.i + c.r;
		if ((z.r * z.r + z.i * z.i) > 4)
			break ;
		z_prev.r = z.r;
		z_prev.i = z.i;
		iter++;
	}
	put_color(fractol, iter / fractol->max_iter, x, y);
}

static void	calculate_for_julia(t_fractol *fractol, int x, int y)
{
	int			iter;
	t_complex	z;
	t_complex	z_prev;

	iter = 0;
	z_prev.r = fractol->min.r + x * (fractol->max.r - fractol->min.r) / WIDTH;
	z_prev.i = fractol->min.i + y * (fractol->max.i - fractol->min.i) / HEIGHT;
	while (iter < fractol->max_iter)
	{
		z.i = 2 * z_prev.r * z_prev.i + fractol->julia.i;
		z.r = z_prev.r * z_prev.r - z_prev.i * z_prev.i + fractol->julia.r;
		if ((z.r * z.r + z.i * z.i) > 4)
			break ;
		z_prev.r = z.r;
		z_prev.i = z.i;
		iter++;
	}
	put_color(fractol, iter / fractol->max_iter, x, y);
}

static void	calculate_for_burningship(t_fractol *fractol, int x, int y)
{
	int			iter;
	t_complex	c;
	t_complex	z;
	t_complex	z_prev;

	iter = 0;
	z_prev.r = 0.0;
	z_prev.i = 0.0;
	c.r = fractol->min.r + x * (fractol->max.r - fractol->min.r) / WIDTH;
	c.i = fractol->min.i + y * (fractol->max.i - fractol->min.i) / HEIGHT;
	while (iter < fractol->max_iter)
	{
		z.r = z_prev.r * z_prev.r - z_prev.i * z_prev.i + c.r;
		z.i = 2 * z_prev.r * z_prev.i + c.i;
		if ((z.r * z.r + z.i * z.i) > 4)
			break ;
		z_prev.r = ft_abs_for_double(z.r);
		z_prev.i = ft_abs_for_double(z.i);
		iter++;
	}
	put_color(fractol, iter / fractol->max_iter, x, y);
}

void	render_fractol(t_fractol *fractol)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (fractol->type == MANDELBROT)
				calculate_for_mandelbrot(fractol, x, y);
			else if (fractol->type == JULIA)
				calculate_for_julia(fractol, x, y);
			else if (fractol->type == BURNINGSHIP)
				calculate_for_burningship(fractol, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->window,
		fractol->image_ptr, 0, 0);
}
