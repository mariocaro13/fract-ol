/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 09:43:13 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/18 16:08:46 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_fractal_init(t_fractal *mlx)
{
	mlx->mlx_connection = mlx_init();
	if (NULL == mlx->mlx_connection)
		return (MALLOC_ERROR);
	mlx->mlx_window = mlx_new_window(mlx->mlx_connection, WIDTH, HEIGHT,
			mlx->name);
	if (NULL == mlx->mlx_window)
	{
		ft_mlx_clean(mlx->mlx_connection, NULL);
		return (MALLOC_ERROR);
	}
	mlx->img.ptr = mlx_new_image(mlx->mlx_connection, WIDTH, HEIGHT);
	if (NULL == mlx->img.ptr)
	{
		ft_mlx_clean(mlx->mlx_connection, mlx->mlx_window);
		return (MALLOC_ERROR);
	}
	mlx->img.pixels_ptr = mlx_get_data_addr(mlx->img.ptr,
			&mlx->img.bits_per_pixel, &mlx->img.line_length, &mlx->img.endian);
	// Init Events
	// Data init
	return (EXIT_SUCCESS);
}
