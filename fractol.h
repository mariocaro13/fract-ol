/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 06:58:17 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/09/19 09:49:37 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>

# define MALLOC_ERROR 1

# define WIDTH 800
# define HEIGHT 800

typedef struct s_mlx
{
	void	*connection;
	void	*window;
}			t_mlx;

void		ft_mlx_clean(void *mlx_connection, void *mlx_window);
int			ft_mlx_init(t_mlx *mlx);
int			ft_mlx_close_window(int keysym, t_mlx *mlx);

#endif