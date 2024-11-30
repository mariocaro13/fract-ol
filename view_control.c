/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 02:45:45 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/30 04:50:33 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_move_up(t_fractal *fractal)
{
	if (!ft_strcmp(fractal->name, BURNING_SHIP))
		fractal->offset.i -= (0.5 * fractal->zoom);
	else
		fractal->offset.i += (0.5 * fractal->zoom);
	ft_render(fractal);
}

void	ft_move_down(t_fractal *fractal)
{
	if (!ft_strcmp(fractal->name, BURNING_SHIP))
		fractal->offset.i += (0.5 * fractal->zoom);
	else
		fractal->offset.i -= (0.5 * fractal->zoom);
	ft_render(fractal);
}

void	ft_move_right(t_fractal *fractal)
{
	fractal->offset.r += (0.5 * fractal->zoom);
	ft_render(fractal);
}

void	ft_move_left(t_fractal *fractal)
{
	fractal->offset.r -= (0.5 * fractal->zoom);
	ft_render(fractal);
}
