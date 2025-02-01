/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:35:38 by tssaito           #+#    #+#             */
/*   Updated: 2025/02/01 14:11:46 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	init_fractol(argc, argv, &fractol);
	init_mlx(&fractol);
	init_mlx_hook(&fractol);
	indicate_key_map();
	render_fractol(&fractol);
	mlx_loop(fractol.ptr.mlx);
}
