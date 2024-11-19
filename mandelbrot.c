/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:03:49 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/19 18:39:04 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mandelbrot(int x, int y, t_fractal *fractal)
{
	t_complex	c;
	t_complex	z;
	int			iter;
	int			color;

	iter = 0;
	z.r = 0.0;
	z.i = 0.0;
	c.r = (ft_map(x, COMPLEX_MIN, COMPLEX_MAX, WIDTH) * fractal->zoom)
		+ fractal->offset_x;
	c.i = (ft_map(y, COMPLEX_MAX, COMPLEX_MIN, HEIGHT) * fractal->zoom)
		+ fractal->offset_y;
	while (iter < fractal->num_of_iterations)
	{
		z = ft_sum_complex(ft_square_complex(z), c);
		if ((ft_hypotenuse(z.r, z.i)) > ESCAPE_VALUE)
		{
			color = ft_map(iter, BLACK, CYAN_BLUE,
					fractal->num_of_iterations);
			ft_mlx_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		iter++;
	}
	ft_mlx_pixel_put(x, y, &fractal->img, EGYPTIAN_BLUE);
}
