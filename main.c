/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:05:16 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/18 18:05:07 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * PROYECT
 ** Name: Fractol
 * Julia and Mandelbrot
 * Infinite Zoom
 * Able to take command line args to display fractal render
 * Able to take command line args to shape Julia, i.e x y coordinates
 * ESC closes with no leaks
 * Click on the X button closes with no leaks
 **/

#include "fractol.h"

/**
 * 2 KINDA PROMPTS
 * 	.\fractol mandelbrot
 *  .\fractol julia <real> <i>
 **/
int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((2 == argc && !ft_strncmp(argv[1], "mandelbrot", 10)) || (4 == argc
			&& !ft_strncmp(argv[1], "julia", 5)))
	{
		fractal.name = argv[1];
		if (ft_fractal_init(&fractal))
			exit(EXIT_FAILURE);
		// Render
		ft_fractal_render(&fractal);
		mlx_key_hook(fractal.mlx_window, ft_mlx_handle_key, &fractal);
		// Loop
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		// Prompt wrong, exit app with error message
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	ft_mlx_clean(fractal.mlx_connection, fractal.mlx_window);
	return (EXIT_SUCCESS);
}
