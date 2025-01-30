/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:44:19 by tssaito           #+#    #+#             */
/*   Updated: 2025/01/30 19:08:07 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	exit_malloc_error(void)
{
	write(STDERR_FILENO, "malloc error\n", 13);
	exit(EXIT_FAILURE);
}

static void	init_mlx_ptr(t_fractol *fractol)
{
	fractol->ptr.mlx = mlx_init();
	if (!fractol->ptr.mlx)
		exit_malloc_error();
}

static void	init_mlx_window(t_fractol *fractol)
{
	char	*type;

	if (fractol->type == MANDELBROT)
		type = "MANDELBROT";
	else if (fractol->type == JULIA)
		type = "JULIA";
	else
		type = "BURNINGSHIP";
	fractol->ptr.window = mlx_new_window(fractol->ptr.mlx, WIDTH, HEIGHT, type);
	if (!fractol->ptr.window)
	{
		mlx_destroy_display(fractol->ptr.mlx);
		free(fractol->ptr.mlx);
		exit_malloc_error();
	}
}

static void	init_mlx_image(t_fractol *fractol)
{
	fractol->ptr.image = mlx_new_image(fractol->ptr.mlx, WIDTH, HEIGHT);
	if (!fractol->ptr.image)
	{
		mlx_destroy_image(fractol->ptr.mlx, fractol->ptr.image);
		mlx_destroy_window(fractol->ptr.mlx, fractol->ptr.window);
		mlx_destroy_display(fractol->ptr.mlx);
		free(fractol->ptr.mlx);
		exit_malloc_error();
	}
	fractol->data_addr = mlx_get_data_addr(fractol->ptr.image,
			&fractol->bits_per_pixel, &fractol->line_size, &fractol->endian);
}

void	init_mlx(t_fractol *fractol)
{
	init_mlx_ptr(fractol);
	init_mlx_window(fractol);
	init_mlx_image(fractol);
}
