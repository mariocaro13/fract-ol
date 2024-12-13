/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:56:34 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/12/13 19:59:29 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_skip_whitespace(const char **str)
{
	while ((**str >= 9 && **str <= 13) || **str == ' ')
		(*str)++;
}

int	ft_get_sign(const char **str)
{
	int	sign;

	sign = 1;
	while (**str == '+' || **str == '-')
		if (*(*str)++ == '-')
			sign = -sign;
	return (sign);
}

long	ft_get_integer_part(const char **str)
{
	long	integer_part;

	integer_part = 0;
	while (ft_isdigit(**str))
		integer_part = integer_part * 10 + (*(*str)++ - '0');
	return (integer_part);
}

double	ft_get_decimal_part(const char **str)
{
	double	decimal_part;
	double	power;

	decimal_part = 0.0;
	power = 1.0;
	if (**str == '.' || **str == ',')
	{
		(*str)++;
		while (ft_isdigit(**str))
		{
			power /= 10;
			decimal_part += (*(*str)++ - '0') * power;
		}
	}
	return (decimal_part);
}

double	ft_atoi_float(const char *str)
{
	long	integer_part;
	double	decimal_part;
	int		sign;

	ft_skip_whitespace(&str);
	sign = ft_get_sign(&str);
	integer_part = ft_get_integer_part(&str);
	decimal_part = ft_get_decimal_part(&str);
	if (*str != '\0')
		ft_exit_failure();
	return ((integer_part + decimal_part) * sign);
}
