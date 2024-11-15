/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 04:01:05 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/15 16:03:34 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_offset(int x, int y, int line_length, int bits_per_pixel)
{
	return (y * line_length + x * (bits_per_pixel / 8));
}

double	ft_convert_to_complex(int point, double size)
{
	double	window_center;

	window_center = size / 2.0;
	return ((point - window_center) * (COMPLEX_MAX - COMPLEX_MIN) / size);
}
