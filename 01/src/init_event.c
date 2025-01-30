/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:31:29 by tssaito           #+#    #+#             */
/*   Updated: 2025/01/30 19:08:40 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	destroy_fractol(t_fractol *fractol)
{
	if (fractol->ptr.image)
		mlx_destroy_image(fractol->ptr.mlx, fractol->ptr.image);
	if (fractol->ptr.window)
		mlx_destroy_window(fractol->ptr.mlx, fractol->ptr.window);
	if (fractol->ptr.mlx)
	{
		mlx_destroy_display(fractol->ptr.mlx);
		free(fractol->ptr.mlx);
	}
	exit(EXIT_SUCCESS);
}

static int	key_hook(int keycode, t_fractol *fractol)
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
	else if (keycode == XK_i)
		zoom(fractol, UP, 0.5, 0.5);
	else if (keycode == XK_o)
		zoom(fractol, DOWN, 0.5, 0.5);
	else if (keycode == XK_r || keycode == XK_g || keycode == XK_b)
		color_shift(fractol, keycode);
	else if (keycode == XK_p)
		manage_max_iter(fractol, UP);
	else if (keycode == XK_r)
		manage_max_iter(fractol, DOWN);
	render_fractol(fractol);
	return (0);
}

static int	mouse_hook(int button, int x, int y, t_fractol *fractol)
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

void	init_mlx_hook(t_fractol *fractol)
{
	mlx_key_hook(fractol->ptr.window, key_hook, fractol);
	mlx_mouse_hook(fractol->ptr.window, mouse_hook, fractol);
	mlx_hook(fractol->ptr.window, DestroyNotify, 0, destroy_fractol, fractol);
}
