/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:03:49 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/18 18:50:44 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			iterations;
	int			color;

	iterations = 0;
	z.r = 0.0;
	z.i = 0.0;
	c.r = ft_map(x, COMPLEX_MIN, COMPLEX_MAX, WIDTH);
	c.i = ft_map(y, COMPLEX_MAX, COMPLEX_MIN, HEIGHT);
	while (iterations < NUM_OF_ITERATIONS)
	{
		z = ft_sum_complex(ft_square_complex(z), c);
		if ((ft_hypotenuse(z.r, z.i)) > ESCAPE_VALUE)
		{
			color = ft_map(iterations, BLACK, WHITE, NUM_OF_ITERATIONS);
			ft_mlx_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		iterations++;
	}
	ft_mlx_pixel_put(x, y, &fractal->img, WHITE);
}

void	draw_mandelbrot(t_fractal *fractal)
{
	t_complex	z;

	z.i = -1;
	while (++z.i < HEIGHT)
	{
		z.r = -1;
		while (++z.r < WIDTH)
		{
			mandelbrot(z.r, z.i, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
		fractal->img.ptr, 0, 0);
}
