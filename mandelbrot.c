/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:03:49 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/08 13:34:27 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(double complex_real, double complex_imaginary)
{
	int		iterations;
	double	z_real;
	double	z_imaginary;
	double	temp;

	iterations = 0;
	z_real = 0;
	z_imaginary = 0;
	while (z_real * z_real + z_imaginary * z_imaginary <= 4 && iterations < 100)
	{
		temp = z_real * z_real - z_imaginary * z_imaginary + complex_real;
		z_imaginary = 2 * z_real * z_imaginary + complex_imaginary;
		z_real = temp;
		iterations++;
	}
	return (iterations);
}

void	draw_mandelbrot(t_img_data *img)
{
	int		x;
	int		y;
	double	complex_r;
	double	complex_i;
	int	iterations;
	int	color;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			complex_r = (x - WIDTH / 2.0) * 4.0 / WIDTH;
			complex_i = (y - HEIGHT / 2.0) * 4.0 / HEIGHT;
			iterations = mandelbrot(complex_r, complex_i);
			if (iterations == 100)
			{
				color = 0;
			} else {
				color = 0xFFFFFF - iterations * (0xFFFFFF/ 100);
			}
			ft_mlx_pixel_put(img, ft_get_offset(x, y, img->line_length, img->bits_per_pixel), color);
			y++;
		}
		x++;
	}
}
