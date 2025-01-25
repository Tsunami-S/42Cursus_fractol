/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:44:19 by tssaito           #+#    #+#             */
/*   Updated: 2025/01/25 21:20:23 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_mlx_ptr(t_fractol *fractol)
{
	fractol->mlx_ptr = mlx_init();
	if (!fractol->mlx_ptr)
		destroy_fractol(fractol);
}

static void	init_mlx_window(t_fractol *fractol)
{
	char	*type;

	if (fractol->type == MANDELBROT)
		type = "MANDELBROT";
	else if (fractol->type == JULIA)
		type = "JULIA";
	else if (fractol->type == BURNINGSHIP)
		type = "BURNINGSHIP";
	fractol->window = mlx_new_window(fractol->mlx_ptr, WIDTH, HEIGHT, type);
	if (!fractol->window)
		destroy_fractol(fractol);
}

static void	init_mlx_image(t_fractol *fractol)
{
	fractol->image_ptr = mlx_new_image(fractol->mlx_ptr, WIDTH, HEIGHT);
	if (!fractol->image_ptr)
		destroy_fractol(fractol);
	fractol->data_addr = mlx_get_data_addr(fractol->image_ptr,
			&fractol->bits_per_pixel, &fractol->line_size, &fractol->endian);
}

void	init_mlx(t_fractol *fractol)
{
	init_mlx_ptr(fractol);
	init_mlx_window(fractol);
	init_mlx_image(fractol);
	mlx_key_hook(fractol->window, key_hook, fractol);
	mlx_mouse_hook(fractol->window, mouse_hook, fractol);
	mlx_hook(fractol->window, DestroyNotify, 0, destroy_fractol, fractol);
}
