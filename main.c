/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:05:16 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/18 22:20:02 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Julia and Mandelbrot
 * Able to take command line args to shape Julia, i.e x y coordinates
 **/

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((2 == argc && !ft_strncmp(argv[1], "mandelbrot", 10)) || (4 == argc
			&& !ft_strncmp(argv[1], "julia", 5)))
	{
		fractal.name = argv[1];
		if (ft_fractal_init(&fractal))
			exit(EXIT_FAILURE);
		ft_fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	ft_mlx_clean(fractal.mlx_connection, fractal.mlx_window);
	return (EXIT_SUCCESS);
}
