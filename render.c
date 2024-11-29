/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:45:13 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/29 17:33:53 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_render_fractal(t_fractal *fractal, void (*ft_fractal)(int, int,
			t_fractal *))
{
	t_complex	z;

	z.i = 0;
	while (z.i < WIDTH)
	{
		z.r = 0;
		while (z.r < HEIGHT)
		{
			ft_fractal(z.r, z.i, fractal);
			z.r++;
		}
		z.i++;
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
		fractal->img.ptr, 0, 0);
}

void	ft_render(t_fractal *fractal)
{
	void		(*ft_fractal)(int, int, t_fractal *);

	if (!ft_strncmp(fractal->name, "mandelbrot", 10))
		ft_fractal = ft_mandelbrot;
	else if (!ft_strncmp(fractal->name, "julia", 5))
		ft_fractal = ft_julia;
	ft_render_fractal(fractal, ft_fractal);
}
