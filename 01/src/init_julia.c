/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:09:54 by tssaito           #+#    #+#             */
/*   Updated: 2025/02/01 16:23:37 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	indicate_julia_example(void)
{
	write(STDOUT_FILENO, "-----------------------------------------\n", 42);
	write(STDOUT_FILENO, "Julia needs 2 params between -2.0 and 2.0\n", 42);
	write(STDOUT_FILENO, "For example\n", 12);
	write(STDOUT_FILENO, "(real, imaginary)\n", 18);
	write(STDOUT_FILENO, "(-0.8, 0.156)\n", 14);
	write(STDOUT_FILENO, "(0.285, 0.01)\n", 14);
	write(STDOUT_FILENO, "(-0.70176, -0.3842)\n", 20);
	write(STDOUT_FILENO, "(-0.4, 0.6)\n", 12);
	write(STDOUT_FILENO, "(0.355, 0.355)\n", 15);
	write(STDOUT_FILENO, "-----------------------------------------\n", 42);
}

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

static void	make_julia_coordinate(double *num)
{
	char	*str;

	*num = -3;
	while (1)
	{
		str = get_next_line(STDIN_FILENO);
		if (is_valid_param(str) == SUCCESS)
			*num = convert_params_to_double(str);
		free(str);
		if (-2.0 <= *num && *num <= 2.0)
			break ;
		else
			write(STDERR_FILENO, "Error! Please retry again!\n", 27);
	}
}

void	init_julia(t_fractol *fractol)
{
	indicate_julia_example();
	write(STDOUT_FILENO, "Enter real coordinate\n", 22);
	make_julia_coordinate(&fractol->julia.r);
	write(STDOUT_FILENO, "Enter imaginary coordinate\n", 27);
	make_julia_coordinate(&fractol->julia.i);
}
