/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:23:29 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/19 18:20:22 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

double	ft_atoi_float(char *str)
{
	long	integer_part;
	double	decimal_part;
	double	power;
	int		sign;

	integer_part = 0;
	decimal_part = 0.0;
	sign = +1;
	power = 1.0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	while (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -sign;
	while (*str != '.' && *str != ',' && *str)
		integer_part = integer_part * 10 + (*str++ - '0');
	if (*str == '.' || *str == ',')
		str++;
	while (*str)
	{
		power /= 10;
		decimal_part = decimal_part + (*str++ - '0') * power;
	}
	return ((integer_part + decimal_part) * sign);
}
