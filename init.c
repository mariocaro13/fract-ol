/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 09:43:13 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/19 18:09:21 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_data_init(t_fractal *fractal)
{
	fractal->num_of_iterations = NUM_OF_ITERATIONS;
	fractal->offset_x = 0.0;
	fractal->offset_y = 0.0;
	fractal->zoom = 1.0;
	fractal->init_point.r = 0.0;
	fractal->init_point.i = 0.0;
}

void	ft_events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, KeyPress, KeyPressMask, ft_mlx_handle_key,
		fractal);
	mlx_hook(fractal->mlx_window, ButtonPress, ButtonPressMask,
		ft_mlx_handle_mouse, fractal);
	mlx_hook(fractal->mlx_window, DestroyNotify, StructureNotifyMask,
		ft_mlx_handle_close, fractal);
}

int	ft_fractal_init(t_fractal *fractal)
{
	ft_data_init(fractal);
	fractal->mlx_connection = mlx_init();
	if (NULL == fractal->mlx_connection)
		return (MALLOC_ERROR);
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT,
			fractal->name);
	if (NULL == fractal->mlx_window)
	{
		ft_mlx_clean(fractal->mlx_connection, NULL);
		return (MALLOC_ERROR);
	}
	fractal->img.ptr = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
	if (NULL == fractal->img.ptr)
	{
		ft_mlx_clean(fractal->mlx_connection, fractal->mlx_window);
		return (MALLOC_ERROR);
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.ptr,
			&fractal->img.bits_per_pixel, &fractal->img.line_length,
			&fractal->img.endian);
	ft_events_init(fractal);
	return (EXIT_SUCCESS);
}
