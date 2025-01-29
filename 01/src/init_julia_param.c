#include "fractol.h"

void	param_error(t_error reason)
{
		write(STDERR_FILENO, "julia needs 2 params between -2.0 and 2.0\n", 42);
	exit(EXIT_FAILURE);
}

static void	exit_read_error(void)
{
	write(STDERR_FILENO, "read error\n", 11);
	exit(EXIT_FAILURE);
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

void init_julia_param(t_fractol *fractol)
{
	char	input_for_x[30];

}
