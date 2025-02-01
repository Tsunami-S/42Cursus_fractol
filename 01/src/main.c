/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:35:38 by tssaito           #+#    #+#             */
/*   Updated: 2025/02/01 16:24:57 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	indicate_key_map(void)
{
	write(STDOUT_FILENO, "----------------------------\n", 29);
	write(STDOUT_FILENO, "*** You can change image ***\n", 29);
	write(STDOUT_FILENO, "----------------------------\n", 29);
	write(STDOUT_FILENO, "u: ZOOM UP\n", 11);
	write(STDOUT_FILENO, "d: ZOOM DOWN\n\n", 14);
	write(STDOUT_FILENO, "k: MOVE UP\n", 11);
	write(STDOUT_FILENO, "j: MOVE DOWN\n", 13);
	write(STDOUT_FILENO, "h: MOVE LEFT\n", 13);
	write(STDOUT_FILENO, "l: MOVE RIGHT\n\n", 15);
	write(STDOUT_FILENO, "p: MORE PRECISELY\n", 18);
	write(STDOUT_FILENO, "s: MORE SPEADILY\n\n", 18);
	write(STDOUT_FILENO, "r: CHANGE RED INTENSE\n", 22);
	write(STDOUT_FILENO, "g: CHANGE GREEN INTENSE\n", 24);
	write(STDOUT_FILENO, "b: CHANGE BULE INTENSE\n\n", 24);
	write(STDOUT_FILENO, "q: QUIT PROGRAM\n", 16);
	write(STDOUT_FILENO, "----------------------------\n", 29);
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	init_fractol_data(argc, argv, &fractol);
	init_mlx(&fractol);
	init_mlx_hook(&fractol);
	indicate_key_map();
	render_fractol(&fractol);
	mlx_loop(fractol.ptr.mlx);
}
