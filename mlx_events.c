/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:39:18 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/19 17:36:56 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mlx_handle_key(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		ft_mlx_handle_close(fractal);
	else if (keysym == XK_Right)
		fractal->offset_x += (0.5 * fractal->zoom);
	else if (keysym == XK_Left)
		fractal->offset_x -= (0.5 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->offset_y += (0.5 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->offset_y -= (0.5 * fractal->zoom);
	else if (keysym == XK_equal || keysym == XK_plus)
		fractal->num_of_iterations += 10;
	else if (keysym == XK_minus)
		fractal->num_of_iterations -= 10;
	ft_fractal_render(fractal);
	return (EXIT_SUCCESS);
}

int	ft_mlx_handle_mouse(int button, int x, int y, t_fractal *fractal)
{
	int	x_f;
	int	y_f;

	x_f = x;
	y_f = x_f + y;
	x_f = y_f + x;
	if (button == Button4)
		fractal->zoom *= 0.95;
	else if (button == Button5)
		fractal->zoom *= 1.05;
	ft_fractal_render(fractal);
	return (EXIT_SUCCESS);
}

int	ft_mlx_handle_close(t_fractal *mlx)
{
	ft_mlx_clean(mlx->mlx_connection, mlx->mlx_window);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
