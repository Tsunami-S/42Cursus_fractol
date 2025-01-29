/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:31:29 by tssaito           #+#    #+#             */
/*   Updated: 2025/01/29 14:31:08 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	destroy_fractol(t_fractol *fractol)
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
	else if (keycode == XK_i || keycode == XK_I)
		zoom(fractol, UP, 0.5, 0.5);
	else if (keycode == XK_o || keycode == XK_O)
		zoom(fractol, DOWN, 0.5, 0.5);
	else if (keycode == XK_R || keycode == XK_G || keycode == XK_B)
		color_shift(fractol, UP, keycode);
	else if (keycode == XK_r || keycode == XK_g || keycode == XK_b)
		color_shift(fractol, DOWN, keycode);
	else if (keycode == XK_p || keycode == XK_P)
		manage_max_iter(fractol, UP);
	else if (keycode == XK_r || keycode == XK_R)
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

void	init_event(t_fractol *fractol)
{
	mlx_key_hook(fractol->window, key_hook, fractol);
	mlx_mouse_hook(fractol->window, mouse_hook, fractol);
	mlx_hook(fractol->window, DestroyNotify, 0, destroy_fractol, fractol);
}
