/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:03:49 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/15 16:39:08 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(double complex_r, double complex_i)
{
	int		iterations;
	double	z_real;
	double	z_imaginary;
	double	temp;

	iterations = 0;
	z_real = 0;
	z_imaginary = 0;
	while (z_real * z_real + z_imaginary * z_imaginary <= 4 && iterations < MAX_ITERATIONS)
	{
		temp = z_real * z_real - z_imaginary * z_imaginary + complex_r;
		z_imaginary = 2 * z_real * z_imaginary + complex_i;
		z_real = temp;
		iterations++;
	}
	return (iterations);
}

void	draw_mandelbrot(t_img_data *img)
{
	int		x;
	int		y;
	int		iterations;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			iterations = mandelbrot(ft_convert_to_complex(x, WIDTH),
					ft_convert_to_complex(y, HEIGHT));
			if (iterations == MAX_ITERATIONS)
				ft_mlx_pixel_put(img,
					ft_offset(x, y, img->line_length, img->bits_per_pixel),
					BLACK);
			else
				ft_mlx_pixel_put(img,
					ft_offset(x, y, img->line_length, img->bits_per_pixel),
					WHITE - iterations * (WHITE / MAX_ITERATIONS));
			y++;
		}
		x++;
	}
}
