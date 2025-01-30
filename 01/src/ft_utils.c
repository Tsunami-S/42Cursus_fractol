/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tssaito <tssaito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:40:03 by tssaito           #+#    #+#             */
/*   Updated: 2025/01/30 19:06:57 by tssaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (n--)
	{
		if (!s1[i] || !s2[i] || s1[i] != s2[i] || !n)
			break ;
		i++;
	}
	if (s1[i] == s2[i])
		return (SAME);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int	ft_isspace(char c)
{
	if (c == ' ' || (9 <= c && c <= 13))
		return (1);
	return (0);
}

double	ft_abs_for_double(double n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*copy_dest;
	const unsigned char	*copy_src;

	if (!dest && !src)
		return (NULL);
	copy_dest = (unsigned char *)dest;
	copy_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		copy_dest[i] = copy_src[i];
		i++;
	}
	return (dest);
}
