/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:37:15 by tssaito           #+#    #+#             */
/*   Updated: 2025/01/25 21:20:09 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
}

static void	is_valid_param(char *str)
{
	if (!*str)
		param_error(INVALID_PARAM_FOR_JULIA);
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
		str++;
	if (*str == '.')
		str++;
	while (ft_isdigit(*str))
		str++;
	while (ft_isspace(*str))
		str++;
	if (*str != '\0')
		param_error(INVALID_PARAM_FOR_JULIA);
}

static double	convert_params_to_double(char *str)
{
	int		sign;
	int		power;
	double	ans;

	is_valid_param(str);
	ans = 0;
	sign = 1;
	power = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
		ans = ans * 10 + *str++ - '0';
	if (*str == '.')
		str++;
	while (ft_isdigit(*str))
	{
		ans = ans * 10 + (*str++ - '0');
		power *= 10;
	}
	return (sign * ans / power);
}

static void	make_julia_coordinates(t_fractol *fractol)
{
	char	input_for_x[30];
	char	input_for_y[30];
	int		check_read;

	write(STDOUT_FILENO, "Enter x coordinate between 2.0 and -2.0\n", 40);
	check_read = read(STDIN_FILENO, input_for_x, 29);
	if (check_read == -1)
		param_error(READ_ERROR);
	fractol->julia.r = convert_params_to_double(input_for_x);
	if (fractol->julia.r > 2.0 || fractol->julia.r < -2.0)
		param_error(INVALID_PARAM_FOR_JULIA);
	write(STDOUT_FILENO, "Enter y coordinate between 2.0 and -2.0\n", 40);
	check_read = read(STDIN_FILENO, input_for_y, 29);
	if (check_read == -1)
		param_error(READ_ERROR);
	fractol->julia.i = convert_params_to_double(input_for_y);
	if (fractol->julia.i > 2.0 || fractol->julia.i < -2.0)
		param_error(INVALID_PARAM_FOR_JULIA);
}

void	init_fractol(int argc, char **argv, t_fractol *fractol)
{
	init_fractol_data(fractol);
	if (argc != 2)
		param_error(INVALID_PARAM);
	if (ft_strncmp("mandelbrot", argv[1], 11) == SAME)
		fractol->type = MANDELBROT;
	else if (ft_strncmp("julia", argv[1], 6) == SAME)
	{
		make_julia_coordinates(fractol);
		fractol->type = JULIA;
	}
	else if (ft_strncmp("burningship", argv[1], 12) == SAME)
		fractol->type = BURNINGSHIP;
	else
		param_error(INVALID_PARAM);
}
