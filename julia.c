/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankasamanyan <ankasamanyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:53:48 by ankasamanya       #+#    #+#             */
/*   Updated: 2022/09/02 03:16:25 by ankasamanya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_innit(t_mlx *mlx)
{
	mlx->max_x = 2.25;
	mlx->min_x = -2.25;
	mlx->max_y = 1.25;
	mlx->min_y = -1.25;
	mlx->max_iter = 50;
	mlx->draw_func = &draw_julia;
}

void	julia(t_mlx *mlx, int x, int y)
{
	t_copmlx	constant;
	t_copmlx	complex;
	t_copmlx	temp;

	mlx->iter = 0;
	constant = mlx->julia_const;
	complex = screen_to_complex(mlx, x, y);
	while ((complex.x * complex.x + complex.y * complex.y < 4)
		&& (mlx->iter < mlx->max_iter))
	{
		temp.x = complex.x;
		temp.y = complex.y;
		complex.x = temp.x * temp.x - temp.y * temp.y + constant.x;
		complex.y = 2 * temp.x * temp.y + constant.y;
		mlx->iter++;
	}
	if (mlx->iter == mlx->max_iter)
		my_mlx_pixel_put(&mlx->img, x, y, 0x00000000);
	else if (mlx->iter < mlx->max_iter)
		my_mlx_pixel_put(&mlx->img, x, y, mlx->colour_func(mlx, mlx->iter));
}

void	draw_julia( t_mlx *mlx)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			julia(mlx, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img_ptr, 0, 0);
}
