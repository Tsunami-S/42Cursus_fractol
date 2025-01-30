/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:48:02 by tssaito           #+#    #+#             */
/*   Updated: 2025/01/30 18:52:37 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_shift(t_fractol *fractol, int keycode)
{
	if (keycode == XK_r && fractol->intens.r > COLOR_MIN)
		fractol->intens.r = (fractol->intens.r + 1) % (COLOR_MAX + 1);
	else if (keycode == XK_g && fractol->intens.g > COLOR_MIN)
		fractol->intens.g = (fractol->intens.g + 1) % (COLOR_MAX + 1);
	else if (keycode == XK_b && fractol->intens.b > COLOR_MIN)
		fractol->intens.b = (fractol->intens.b + 1) % (COLOR_MAX + 1);
}

void	manage_max_iter(t_fractol *fractol, t_act act)
{
	static int	out_count;

	if (act == UP)
	{
		if (fractol->max_iter < ITER_UPPER_LIMIT)
			fractol->max_iter += 2;
		else
			out_count++;
	}
	else if (act == DOWN)
	{
		if (out_count)
			out_count--;
		else if (fractol->max_iter > ITER_LOWER_LIMIT)
			fractol->max_iter -= 2;
	}
}

void	move(t_fractol *fractol, t_act act)
{
	double	height;
	double	width;

	height = fractol->max.i - fractol->min.i;
	width = fractol->max.r - fractol->min.r;
	if (act == UP)
	{
		fractol->max.i -= height / MOVEMENT_SIZE;
		fractol->min.i -= height / MOVEMENT_SIZE;
	}
	else if (act == DOWN)
	{
		fractol->max.i += height / MOVEMENT_SIZE;
		fractol->min.i += height / MOVEMENT_SIZE;
	}
	else if (act == RIGHT)
	{
		fractol->max.r += width / MOVEMENT_SIZE;
		fractol->min.r += width / MOVEMENT_SIZE;
	}
	else if (act == LEFT)
	{
		fractol->max.r -= width / MOVEMENT_SIZE;
		fractol->min.r -= width / MOVEMENT_SIZE;
	}
}

void	zoom(t_fractol *fractol, t_act act, double ratio_i, double ratio_r)
{
	double	height;
	double	width;

	height = fractol->max.i - fractol->min.i;
	width = fractol->max.r - fractol->min.r;
	if (act == UP)
	{
		fractol->max.i -= height * (1 - ratio_i) / ZOOM_RATIO;
		fractol->min.i += height * ratio_i / ZOOM_RATIO;
		fractol->max.r -= width * (1 - ratio_r) / ZOOM_RATIO;
		fractol->min.r += width * ratio_r / ZOOM_RATIO;
	}
	else if (act == DOWN)
	{
		fractol->max.i += act * height * (1 - ratio_i) / ZOOM_RATIO;
		fractol->min.i -= act * height * ratio_i / ZOOM_RATIO;
		fractol->max.r += act * width * (1 - ratio_r) / ZOOM_RATIO;
		fractol->min.r -= act * width * ratio_r / ZOOM_RATIO;
	}
	manage_max_iter(fractol, act);
}
