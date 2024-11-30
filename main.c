/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:05:16 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/30 02:38:23 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((2 == argc && (!ft_strcmp(argv[1], MANDELBROT)
				|| !ft_strcmp(argv[1], BURNING_SHIP)))
		|| (4 == argc && !ft_strcmp(argv[1], JULIA)))
	{
		fractal.name = argv[1];
		if (ft_init(&fractal))
			exit(EXIT_FAILURE);
		if (4 == argc)
		{
			fractal.init_point.r = ft_atoi_float(argv[2]);
			fractal.init_point.i = ft_atoi_float(argv[3]);
		}
		ft_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		ft_putstr_fd(USAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	ft_mlx_clean(fractal.mlx_connection, fractal.mlx_window);
	return (EXIT_SUCCESS);
}
