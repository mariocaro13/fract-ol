/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:05:16 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/12/13 19:21:48 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((2 == argc && (!ft_strcmp(argv[1], MANDELBROT) || !ft_strcmp(argv[1],
					BURNING_SHIP))) || (4 == argc && !ft_strcmp(argv[1],
				JULIA)))
	{
		fractal.name = argv[1];
		if (ft_init(&fractal))
			exit(EXIT_FAILURE);
		if (4 == argc)
		{
			if (ft_atoi_float(argv[2]) == 0.0 && ft_atoi_float(argv[2]) != 0)
				ft_exit_failure();
			if (ft_atoi_float(argv[3]) == 0.0 && ft_atoi_float(argv[3]) != 0)
				ft_exit_failure();
			fractal.init_point.r = ft_atoi_float(argv[2]);
			fractal.init_point.i = ft_atoi_float(argv[3]);
		}
		ft_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
		ft_exit_failure();
	ft_mlx_clean(&fractal);
	return (EXIT_SUCCESS);
}
