/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:39:18 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/30 16:16:22 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mlx_handle_key(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		ft_mlx_handle_close(fractal);
	else if (keysym == XK_Right)
		ft_move_right(fractal);
	else if (keysym == XK_Left)
		ft_move_left(fractal);
	else if (keysym == XK_Up)
		ft_move_up(fractal);
	else if (keysym == XK_Down)
		ft_move_down(fractal);
	else if (keysym == XK_equal || keysym == XK_plus)
	{
		fractal->num_of_iterations += 10;
		ft_render(fractal);
	}
	else if (keysym == XK_minus && fractal->num_of_iterations > MIN_ITERATIONS)
	{
		fractal->num_of_iterations -= 10;
		ft_render(fractal);
	}
	return (EXIT_SUCCESS);
}

int	ft_mlx_handle_mouse(int button, int x, int y, t_fractal *fractal)
{
	fractal->mouse.r = x;
	fractal->mouse.i = y;
	if (button == Button4)
		fractal->zoom *= 0.95;
	else if (button == Button5)
		fractal->zoom *= 1.05;
	else
		return (EXIT_FAILURE);
	ft_render(fractal);
	return (EXIT_SUCCESS);
}

int	ft_mlx_handle_close(t_fractal *mlx)
{
	ft_mlx_clean(mlx);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
