/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:42:15 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/12/13 18:30:24 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_julia(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	int			iter;
	int			color;

	iter = 0;
	z.r = (ft_map(x, COMPLEX_MIN, COMPLEX_MAX, WIDTH) * fractal->zoom)
		+ fractal->offset.r;
	z.i = (ft_map(y, COMPLEX_MAX, COMPLEX_MIN, HEIGHT) * fractal->zoom)
		+ fractal->offset.i;
	while (iter < fractal->num_of_iterations)
	{
		z = ft_sum_complex(ft_square_complex(z), fractal->init_point);
		if ((ft_hypotenuse(z.r, z.i)) > ESCAPE_VALUE)
		{
			color = ft_map(iter, BLACK, WHITE, fractal->num_of_iterations);
			ft_mlx_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		iter++;
	}
	ft_mlx_pixel_put(x, y, &fractal->img, BLACK);
}
