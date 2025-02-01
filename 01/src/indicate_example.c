/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indicate_key_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 19:48:58 by tssaito           #+#    #+#             */
/*   Updated: 2025/02/01 14:12:06 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	indicate_julia_example(void)
{
	write(STDOUT_FILENO, "-------------------------------\n", 32);
	write(STDOUT_FILENO, "Julia needs 2 params between -2.0 and 2.0\n", 42);
	write(STDOUT_FILENO, "For example\n", 12);
	write(STDOUT_FILENO, "(real, imaginary)\n", 18);
	write(STDOUT_FILENO, "(-0.8, 0.156)\n", 14);
	write(STDOUT_FILENO, "(0.285, 0.01)\n", 14);
	write(STDOUT_FILENO, "(-0.70176, -0.3842)\n", 20);
	write(STDOUT_FILENO, "(-0.4, 0.6)\n", 12);
	write(STDOUT_FILENO, "(0.355, 0.355)\n", 15);
	write(STDOUT_FILENO, "-------------------------------\n", 32);
}

void	indicate_key_map(void)
{
	write(STDOUT_FILENO, "-------------------------------\n", 32);
	write(STDOUT_FILENO, "You can change image\n", 21);
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
	write(STDOUT_FILENO, "-------------------------------\n", 32);
}
