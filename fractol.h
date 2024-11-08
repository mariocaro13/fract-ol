/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 06:58:17 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/08 13:21:15 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <stdlib.h>

# define MALLOC_ERROR 1

# define WIDTH 800
# define HEIGHT 800

typedef struct s_mlx_data
{
	void	*connection;
	void	*window;
}			t_mlx_data;

typedef struct s_img_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img_data;

void		ft_mlx_clean(void *mlx_connection, void *mlx_window);
int			ft_mlx_init(t_mlx_data *mlx);
int			ft_mlx_close_window(int keysym, t_mlx_data *mlx);

void		ft_mlx_pixel_put(t_img_data *img, int offset, int color);

int			ft_get_offset(int x, int y, int line_length, int bits_per_pixel);

int			mandelbrot(double complex_real, double complex_imaginary);

void		draw_mandelbrot(t_img_data *img);

#endif