/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:05:16 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/08 13:21:20 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mlx_put_image(void)
{
}

int	main(void)
{
	t_mlx_data	mlx;
	t_img_data	img;

	if (ft_mlx_init(&mlx))
		exit(EXIT_FAILURE);
	mlx_key_hook(mlx.window, ft_mlx_close_window, &mlx);
	img.img = mlx_new_image(mlx.connection, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	ft_mlx_pixel_put(&img, ft_get_offset(5, 10, img.line_length,
			img.bits_per_pixel), 0x00FF0000);
	draw_mandelbrot(&img);
	mlx_put_image_to_window(mlx.connection, mlx.window, img.img, 0, 0);
	mlx_loop(mlx.connection);
	ft_mlx_clean(mlx.connection, mlx.window);
	return (EXIT_SUCCESS);
}
