/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:37:15 by tssaito           #+#    #+#             */
/*   Updated: 2025/01/29 14:48:37 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	exit_param_error(void)
{
	write(STDERR_FILENO, "Enter mandelbrot or julia or burningship\n", 41);
	exit(EXIT_FAILURE);
}

static void	init_fractol_data(t_fractol *fractol)
{
	fractol->mlx_ptr = NULL;
	fractol->window = NULL;
	fractol->image_ptr = NULL;
	fractol->data_addr = NULL;
	fractol->max_iter = MAX_ITER;
	fractol->max.r = INIT_COMPLEX_RANGE;
	fractol->min.r = -1 * INIT_COMPLEX_RANGE;
	fractol->max.i = INIT_COMPLEX_RANGE;
	fractol->min.i = -1 * INIT_COMPLEX_RANGE;
	fractol->bits_per_pixel = 0;
	fractol->line_size = 0;
	fractol->endian = 0;
	if (fractol->type == BURNINGSHIP)
	{
		fractol->intens.r = 9;
		fractol->intens.g = 1;
		fractol->intens.b = 1;
	}
	else
	{
		fractol->intens.r = 1;
		fractol->intens.g = 3;
		fractol->intens.b = 5;
	}
}
void	init_fractol(int argc, char **argv, t_fractol *fractol)
{
	if (argc != 2)
		exit_param_error();
	if (ft_strncmp("mandelbrot", argv[1], 11) == SAME)
		fractol->type = MANDELBROT;
	else if (ft_strncmp("julia", argv[1], 6) == SAME)
		fractol->type = JULIA;
	else if (ft_strncmp("burningship", argv[1], 12) == SAME)
		fractol->type = BURNINGSHIP;
	else
		exit_param_error();
	init_fractol_data(fractol);
}
