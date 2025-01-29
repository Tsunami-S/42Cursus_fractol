/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:48:02 by tssaito           #+#    #+#             */
/*   Updated: 2025/01/25 16:48:03 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	manage_max_iter(t_fractol *fractol, t_act act)
{
	static int	out_count;

	if (act == UP)
	{
		if (fractol->max_iter < ITER_UPPER_LIMIT)
			fractol->max_iter *= 1.05;
		else
			out_count++;
	}
	else if (act == DOWN)
	{
		if (out_count)
			out_count--;
		else if (fractol->max_iter > ITER_LOWER_LIMIT)
			fractol->max_iter /= 1.03;
	}
}

static void	move(t_fractol *fractol, t_act act)
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

static void	zoom(t_fractol *fractol, t_act act, double ratio_i, double ratio_r)
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

int	key_hook(int keycode, t_fractol *fractol)
{
	if (keycode == XK_Escape || keycode == XK_q)
		destroy_fractol(fractol);
	else if (keycode == XK_Up || keycode == XK_k)
		move(fractol, UP);
	else if (keycode == XK_Down || keycode == XK_j)
		move(fractol, DOWN);
	else if (keycode == XK_Right || keycode == XK_l)
		move(fractol, RIGHT);
	else if (keycode == XK_Left || keycode == XK_h)
		move(fractol, LEFT);
	else if (keycode == XK_u || keycode == XK_U)
		zoom(fractol, UP, 0.5, 0.5);
	else if (keycode == XK_d || keycode == XK_D)
		zoom(fractol, DOWN, 0.5, 0.5);
	render_fractol(fractol);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_fractol *fractol)
{
	double	ratio_i;
	double	ratio_r;

	ratio_i = (y / (double)HEIGHT);
	ratio_r = (x / (double)WIDTH);
	if (button == Button4)
		zoom(fractol, UP, ratio_i, ratio_r);
	else if (button == Button5)
		zoom(fractol, DOWN, ratio_i, ratio_r);
	render_fractol(fractol);
	return (0);
}
