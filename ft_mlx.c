/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 09:43:13 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/08 13:19:43 by mcaro-ro         ###   ########.fr       */
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

int	ft_mlx_init(t_mlx_data *mlx)
{
	mlx->connection = mlx_init();
	if (NULL == mlx->connection)
		return (MALLOC_ERROR);
	mlx->window = mlx_new_window(mlx->connection, WIDTH, HEIGHT, "Fract'ol");
	if (NULL == mlx->window)
	{
		ft_mlx_clean(mlx->connection, NULL);
		return (MALLOC_ERROR);
	}
	return (EXIT_SUCCESS);
}

int	ft_mlx_close_window(int keysym, t_mlx_data *mlx)
{
	if (XK_Escape == keysym)
	{
		ft_mlx_clean(mlx->connection, mlx->window);
		exit(EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}

void	ft_mlx_pixel_put(t_img_data *img, int offset, int color)
{
	char	*dst;

	dst = img->addr + offset;
	*(unsigned int *)dst = color;
}
