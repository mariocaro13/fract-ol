/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:05:37 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/18 18:49:57 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_fractal_render(t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "mandelbrot", 10))
	{
		draw_mandelbrot(fractal);
	}
	else if (!ft_strncmp(fractal->name, "julia", 5))
	{
		//draw_julia(fractal);
	}
}
