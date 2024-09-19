/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:05:16 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/09/19 09:43:11 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	t_mlx	mlx;

	if (ft_mlx_init(&mlx))
		exit(EXIT_FAILURE);
	mlx_key_hook(mlx.window, ft_mlx_close_window, &mlx);
	mlx_loop(mlx.connection);
	ft_mlx_clean(mlx.connection, mlx.window);
	return (EXIT_SUCCESS);
}
