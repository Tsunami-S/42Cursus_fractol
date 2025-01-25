/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:41:50 by tssaito           #+#    #+#             */
/*   Updated: 2025/01/25 15:08:20 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	param_error(t_error reason)
{
	if (reason == INVALID_PARAM)
		write(STDERR_FILENO, "Enter mandelbrot or julia or burningship\n", 41);
	if (reason == INVALID_PARAM || reason == INVALID_PARAM_FOR_JULIA)
		write(STDERR_FILENO, "julia needs 2 params between -2.0 and 2.0\n", 42);
	if (reason == READ_ERROR)
		write(STDERR_FILENO, "read error\n", 11);
	exit(EXIT_FAILURE);
}

int	destroy_fractol(t_fractol *fractol)
{
	if (fractol->image_ptr)
		mlx_destroy_image(fractol->mlx_ptr, fractol->image_ptr);
	if (fractol->window)
		mlx_destroy_window(fractol->mlx_ptr, fractol->window);
	if (fractol->mlx_ptr)
	{
		mlx_destroy_display(fractol->mlx_ptr);
		free(fractol->mlx_ptr);
	}
	exit(EXIT_SUCCESS);
}
