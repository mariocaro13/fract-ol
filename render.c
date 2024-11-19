/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:45:13 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/19 18:45:18 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_render_fractal(t_fractal *fractal, void (*ft_fractal)(int, int,
			t_fractal *))
{
	t_complex	z;

	z.i = -1;
	while (++z.i < HEIGHT)
	{
		z.r = -1;
		while (++z.r < WIDTH)
		{
			ft_fractal(z.r, z.i, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
		fractal->img.ptr, 0, 0);
}

void	ft_render(t_fractal *fractal)
{
	void	(*ft_fractal)(int, int, t_fractal *);

	if (!ft_strncmp(fractal->name, "mandelbrot", 10))
		ft_fractal = ft_mandelbrot;
	else if (!ft_strncmp(fractal->name, "julia", 5))
		ft_fractal = ft_julia;
	ft_render_fractal(fractal, ft_fractal);
}
