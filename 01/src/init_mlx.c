/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:44:19 by tssaito           #+#    #+#             */
/*   Updated: 2025/01/29 14:48:05 by tssaito          ###   ########.fr       */
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
	fractol->mlx_ptr = mlx_init();
	if (!fractol->mlx_ptr)
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
	fractol->window = mlx_new_window(fractol->mlx_ptr, WIDTH, HEIGHT, type);
	if (!fractol->window)
	{
		mlx_destroy_display(fractol->mlx_ptr);
		free(fractol->mlx_ptr);
		exit_malloc_error();
	}
}

static void	init_mlx_image(t_fractol *fractol)
{
	fractol->image_ptr = mlx_new_image(fractol->mlx_ptr, WIDTH, HEIGHT);
	if (!fractol->image_ptr)
	{
		mlx_destroy_image(fractol->mlx_ptr, fractol->image_ptr);
		mlx_destroy_window(fractol->mlx_ptr, fractol->window);
		mlx_destroy_display(fractol->mlx_ptr);
		free(fractol->mlx_ptr);
		exit_malloc_error();
	}
	fractol->data_addr = mlx_get_data_addr(fractol->image_ptr,
			&fractol->bits_per_pixel, &fractol->line_size, &fractol->endian);
}

void	init_mlx(t_fractol *fractol)
{
	init_mlx_ptr(fractol);
	init_mlx_window(fractol);
	init_mlx_image(fractol);
}
