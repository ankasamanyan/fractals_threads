/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasaman <akasaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:34:55 by ankasamanya       #+#    #+#             */
/*   Updated: 2022/09/06 17:46:58 by akasaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_init(t_mlx *mlx)
{
	mlx->max_x = 1.2;
	mlx->min_x = -2.4;
	mlx->max_y = 1;
	mlx->min_y = -1;
	mlx->max_iter = 200;
	mlx->draw_func = &draw_mandelbrot;
}

void	mandelbrot(t_mlx *mlx, int x, int y)
{
	t_copmlx	constant;
	t_copmlx	complex;
	t_copmlx	temp;
	int			iter;

	iter = 0;
	constant = screen_to_complex(mlx, x, y);
	complex.x = 0.0;
	complex.y = 0.0;
	while ((complex.x * complex.x + complex.y * complex.y < 4)
		&& (iter < mlx->max_iter))
	{
		temp.x = complex.x;
		temp.y = complex.y;
		complex.x = temp.x * temp.x - temp.y * temp.y + constant.x;
		complex.y = 2 * temp.x * temp.y + constant.y;
		iter++;
	}	
	if (iter == mlx->max_iter)
	{
		// pthread_mutex_lock(&mlx->da);
		
		my_mlx_pixel_put(&mlx->img, x, y, 0x00000000);
		// pthread_mutex_unlock(&mlx->da);
	}
	else if (iter < mlx->max_iter)
	{
		// pthread_mutex_lock(&mlx->da);

		my_mlx_pixel_put(&mlx->img, x, y, mlx->colour_func(mlx, iter));
		// pthread_mutex_unlock(&mlx->da);
	}
}

void	*draw_mandelbrot_thread(void *thread_struct_prot)
{
	int	x;
	int	y;
	t_thread_struct *thread_struct = thread_struct_prot;
	t_mlx *mlx = thread_struct->mlx;

	x = thread_struct->thread_id * (WIDTH / 10);
	while (x < (thread_struct->thread_id + 1) * ((WIDTH / 10)))
	{
		y = 0;
		while (y < HEIGHT)
		{
			mandelbrot(mlx, x, y);
			y++;
		}
		x++;
	}
	return NULL;
}

void	draw_mandelbrot( t_mlx *mlx)
{
	int		i;
	t_thread_struct		*thread_struct[10];
	
	pthread_mutex_init(&mlx->da, NULL);
	i = 0;
	while (i < 10)
	{
		thread_struct[i] = calloc(sizeof(t_thread_struct), 1);
		thread_struct[i]->thread_id = i;
		thread_struct[i]->mlx = mlx;
		// printf("hi i got here with number %i    %p\n", i, thread_struct[i]->mlx);
		// printf("hi i got here with number %i\n", mlx->max_iter);
		
		pthread_create(&mlx->id_struct[i], NULL, draw_mandelbrot_thread, thread_struct[i]);
		i++;
	}
	while (i > 0)
	{
		pthread_join(mlx->id_struct[i], NULL);
		// free(thread_struct[i]);
		i--;
	}
	// printf("did i even get here?\n");
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img_ptr, 0, 0);
}
