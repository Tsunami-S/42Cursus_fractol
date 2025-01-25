/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:35:38 by tssaito           #+#    #+#             */
/*   Updated: 2025/01/25 15:09:08 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	init_fractol(argc, argv, &fractol);
	init_mlx(&fractol);
	render_fractol(&fractol);
	mlx_loop(fractol.mlx_ptr);
}
