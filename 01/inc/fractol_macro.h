/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_macro.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:47:36 by tssaito           #+#    #+#             */
/*   Updated: 2025/01/29 23:18:10 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_MACRO_H
# define FRACTOL_MACRO_H

/* window */
# define WIDTH 800
# define HEIGHT 800
# define INIT_COMPLEX_RANGE 2.0

/* event */
# define MOVEMENT_SIZE 42
# define ZOOM_RATIO 4
# define ITER_UPPER_LIMIT 700
# define ITER_LOWER_LIMIT 42

/* color */
# define BLACK 0x000000
# define WHITE 0xFFFFFF

/* calculate color */
# define COLOR_MAX 255
# define RED_SHIFT 65536
# define GREEN_SHIFT 256
# define RED_INTENS 9
# define GREEN_INTENS 3
# define BLUE_INTENS 5
# define MAX_ITER 42

/* strcmp */
# define SAME 0

/* get_next_line */
# define BUFFER_SIZE 42


typedef enum e_fractol_type
{
	MANDELBROT,
	JULIA,
	BURNINGSHIP
}	t_fractol_type;

typedef enum e_error
{
	SUCCESS,
	INVALID_PARAM,
	INVALID_PARAM_FOR_JULIA,
	READ_ERROR
}	t_error;

typedef enum e_act
{
	UP,
	DOWN,
	RIGHT,
	LEFT
}	t_act;

#endif
