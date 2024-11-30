/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 04:01:05 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/30 02:19:58 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	ft_sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.r = z1.r + z2.r;
	result.i = z1.i + z2.i;
	return (result);
}

t_complex	ft_square_complex(t_complex z)
{
	t_complex	result;

	result.r = (z.r * z.r) - (z.i * z.i);
	result.i = (2 * z.r * z.i);
	return (result);
}

t_complex	ft_square_complex_i_abs(t_complex z)
{
	t_complex	result;

	result.r = (z.r * z.r) - (z.i * z.i);
	result.i = fabs(2 * z.r * z.i);
	return (result);
}

int	ft_hypotenuse(double x, double y)
{
	return ((x * x) + (y * y));
}

double	ft_map(int input, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * input / old_max + new_min);
}
