/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:45:13 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/30 02:38:07 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_render_fractal(t_fractal *fractal, void (*ft_fractal)(int, int,
			t_fractal *))
{
	t_complex	z;

	if (fractal->img.ptr != NULL)
	{
		mlx_destroy_image(fractal->mlx_connection, fractal->img.ptr);
		ft_mlx_img_init(fractal);
	}
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

	if (!ft_strcmp(fractal->name, MANDELBROT))
		ft_fractal = ft_mandelbrot;
	else if (!ft_strcmp(fractal->name, JULIA))
		ft_fractal = ft_julia;
	else if (!ft_strcmp(fractal->name, BURNING_SHIP))
		ft_fractal = ft_burning_ship;
	else
		exit (EXIT_FAILURE);
	ft_render_fractal(fractal, ft_fractal);
}
