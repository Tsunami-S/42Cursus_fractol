/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:43:44 by tssaito           #+#    #+#             */
/*   Updated: 2025/01/29 14:53:51 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/* standard library */
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* for minilibx */
# include <X11/X.h>
# include <X11/keysym.h>
# include <X11/keysymdef.h>
# include <mlx.h>

/* my headers */
# include "fractol_macro.h"
# include "fractol_struct.h"

/* fractol */
void	init_fractol(int argc, char **argv, t_fractol *fractol);
void	init_julia_param(t_fractol *fractol);
void	init_mlx(t_fractol *fractol);
void	init_event(t_fractol *fractol);
void	render_fractol(t_fractol *fractol);

/* event utils */
void	color_shift(t_fractol *fractol, t_act act, int keycode);
void	zoom(t_fractol *fractol, t_act act, double ratio_i, double ratio_r);
void	move(t_fractol *fractol, t_act act);
void	manage_max_iter(t_fractol *fractol, t_act act);

/* exit */
void	param_error(t_error reason);

/* ft_utlis */
int		ft_isdigit(int c);
int		ft_isspace(char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
double	ft_abs_for_double(double n);

#endif
