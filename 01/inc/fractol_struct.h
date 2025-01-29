/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:47:42 by tssaito           #+#    #+#             */
/*   Updated: 2025/01/29 13:11:32 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_STRUCT_H
# define FRACTOL_STRUCT_H

typedef struct s_complex
{
	double			r;
	double			i;
}					t_complex;

typedef struct s_intens
{
	int				r;
	int				g;
	int				b;
}					t_intens;

typedef struct s_fractol
{
	t_fractol_type	type;
	void			*mlx_ptr;
	void			*window;
	void			*image_ptr;
	char			*data_addr;
	int				bits_per_pixel;
	int				line_size;
	int				endian;
	double			max_iter;
	t_complex		julia;
	t_complex		min;
	t_complex		max;
	t_intens		intens;
}					t_fractol;

#endif
