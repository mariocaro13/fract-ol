/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 09:43:13 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/30 16:20:53 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mlx_init(t_fractal *mlx)
{
	mlx->mlx_connection = mlx_init();
	if (NULL == mlx->mlx_connection)
		return (MALLOC_ERROR);
	mlx->mlx_window = mlx_new_window(mlx->mlx_connection, WIDTH, HEIGHT,
			mlx->name);
	if (NULL == mlx->mlx_window)
	{
		ft_mlx_clean(mlx);
		return (MALLOC_ERROR);
	}
	return (EXIT_SUCCESS);
}

int	ft_mlx_img_init(t_fractal *mlx)
{
	mlx->img.ptr = mlx_new_image(mlx->mlx_connection, WIDTH, HEIGHT);
	if (NULL == mlx->img.ptr)
	{
		ft_mlx_clean(mlx);
		return (MALLOC_ERROR);
	}
	mlx->img.pixels_ptr = mlx_get_data_addr(mlx->img.ptr,
			&mlx->img.bits_per_pixel, &mlx->img.line_length, &mlx->img.endian);
	return (EXIT_SUCCESS);
}

void	ft_mlx_clean(t_fractal *fractal)
{
	if (NULL != fractal->mlx_window)
	{
		mlx_destroy_image(fractal->mlx_connection, fractal->img.ptr);
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	}
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
}

int	ft_offset(int x, int y, int line_length, int bits_per_pixel)
{
	return (y * line_length + (x * (bits_per_pixel / 8)));
}

void	ft_mlx_pixel_put(int x, int y, t_img_data *img, int color)
{
	int	offset;

	offset = ft_offset(x, y, img->line_length, img->bits_per_pixel);
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}
