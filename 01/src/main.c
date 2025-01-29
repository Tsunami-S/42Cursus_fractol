/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:35:38 by tssaito           #+#    #+#             */
/*   Updated: 2025/01/29 14:54:15 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	init_fractol(argc, argv, &fractol);
	init_julia_param(&fractol);
	init_mlx(&fractol);
	init_event(&fractol);
	render_fractol(&fractol);
	mlx_loop(fractol.mlx_ptr);
}
