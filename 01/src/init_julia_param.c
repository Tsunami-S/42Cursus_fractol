#include "fractol.h"

static bool	is_valid_param(char *str)
{
	if(!str)
	{
		write(STDERR_FILENO, "read error\n", 11);
		exit(EXIT_FAILURE);
	}
	else if (!*str)
		return (false);
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
		return (false);
	return (true);
}

static double	convert_params_to_double(char *str)
{
	int		sign;
	int		power;
	double	ans;

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

static int	isvalid_julia_param(double n)
{
	if (n < -2.0 || n > 2.0)
	{
		write(STDERR_FILENO, "julia needs 2 params between -2.0 and 2.0\n", 42);
		return ERROR;
	}
	return SUCCESS;
}

void	init_julia_param(t_fractol *fractol)
{
	char *param_r;
	char *param_i;

	while (isvalid_julia_param(fractol->julia.r) == ERROR)
	{
		write(STDOUT_FILENO, "Enter real coordinate\n", 22);
		param_r = get_next_line(STDIN_FILENO);
		if(is_valid_param(param_r) == VALID)
			t_fractol->julia.r = ft_atof(param_r);
	}
	while (isvalid_julia_param(fractol->julia.i) == ERROR)
	{
		write(STDOUT_FILENO, "Enter imaginary coordinate\n", 27);
		param_i = get_next_line(STDIN_FILENO);
		if(is_valid_param(param_i) == VALID)
			t_fractol->julia.i = ft_atof(param_i);
	}
}
