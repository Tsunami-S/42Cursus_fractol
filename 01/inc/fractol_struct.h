/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:47:42 by tssaito           #+#    #+#             */
/*   Updated: 2025/01/30 19:07:53 by tssaito          ###   ########.fr       */
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

typedef struct s_ptr
{
	void			*mlx;
	void			*window;
	void			*image;
}					t_ptr;

typedef struct s_fractol
{
	t_fractol_type	type;
	t_ptr			ptr;
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

/* get_next_line */
typedef struct s_buf
{
	char			buf[BUFFER_SIZE];
	char			*save;
	int				len;
}					t_buf;

typedef struct s_line
{
	char			*line;
	size_t			len;
	size_t			m_size;
}					t_line;

#endif
