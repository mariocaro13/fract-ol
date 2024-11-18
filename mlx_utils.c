/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 09:43:13 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/18 19:39:52 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mlx_clean(void *connection, void *window)
{
	if (NULL != window)
		mlx_destroy_window(connection, window);
	mlx_destroy_display(connection);
	free(connection);
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
