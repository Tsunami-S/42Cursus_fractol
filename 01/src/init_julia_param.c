/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_julia_param.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:09:54 by tssaito           #+#    #+#             */
/*   Updated: 2025/02/01 14:36:25 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	is_valid_param(char *str)
{
	if (!str)
	{
		write(STDERR_FILENO, "read error\n", 11);
		exit(EXIT_FAILURE);
	}
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	if (*str != '0' && *str != '1' && *str != '2')
		return (ERROR);
	str++;
	if (*str != '.' && !ft_isspace(*str))
		return (ERROR);
	if (*str == '.')
	{
		str++;
		while (ft_isdigit(*str))
			str++;
	}
	while (ft_isspace(*str))
		str++;
	if (*str != '\0')
		return (ERROR);
	return (SUCCESS);
}

static double	convert_params_to_double(char *str)
{
	int		sign;
	int		power;
	int		count;
	double	ans;

	sign = 1;
	power = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	ans = *str++ - '0';
	if (*str == '.')
		str++;
	count = 0;
	while (ft_isdigit(*str) && count++ < 7)
	{
		ans = ans * 10 + (*str++ - '0');
		power *= 10;
	}
	if (*str && *str - '0' >= 5)
		ans++;
	return (sign * ans / power);
}

static t_error	isvalid_julia_param(double n)
{
	if (n < -2.0 || n > 2.0)
	{
		write(STDERR_FILENO, "julia needs 2 params between -2.0 and 2.0\n", 42);
		return (ERROR);
	}
	return (SUCCESS);
}

void	init_julia_param(t_fractol *fractol)
{
	char	*param_r;
	char	*param_i;

	fractol->julia.r = -3;
	fractol->julia.i = -3;
	indicate_julia_example();
	while (isvalid_julia_param(fractol->julia.r) == ERROR)
	{
		write(STDOUT_FILENO, "Enter real coordinate\n", 22);
		param_r = get_next_line(STDIN_FILENO);
		if (is_valid_param(param_r) == SUCCESS)
			fractol->julia.r = convert_params_to_double(param_r);
		free(param_r);
	}
	while (isvalid_julia_param(fractol->julia.i) == ERROR)
	{
		write(STDOUT_FILENO, "Enter imaginary coordinate\n", 27);
		param_i = get_next_line(STDIN_FILENO);
		if (is_valid_param(param_i) == SUCCESS)
			fractol->julia.i = convert_params_to_double(param_i);
		free(param_i);
	}
}

