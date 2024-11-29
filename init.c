/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 09:43:13 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/29 16:32:55 by mcaro-ro         ###   ########.fr       */
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
	mlx_hook(fractal->mlx_window, ConfigureNotify, StructureNotifyMask,
		ft_mlx_handle_resize, fractal);
}

int	ft_init(t_fractal *mlx)
{
	ft_data_init(mlx);
	ft_mlx_init(mlx);
	ft_mlx_img_init(mlx);
	ft_events_init(mlx);
	return (EXIT_SUCCESS);
}
