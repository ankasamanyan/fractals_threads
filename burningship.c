/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasaman <akasaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:50:03 by ankasamanya       #+#    #+#             */
/*   Updated: 2022/09/04 16:40:35 by akasaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	burningship_init(t_mlx *mlx)
{
	mlx->max_x = 2.75;
	mlx->min_x = -3.25;
	mlx->max_y = 1.4;
	mlx->min_y = -2.1;
	mlx->max_iter = 30;
	mlx->draw_func = &draw_burninghsip;
}

void	burningship(t_mlx *mlx, int x, int y)
{
	t_copmlx	constant;
	t_copmlx	complex;
	double		tmp;
	int			iter;

	iter = 0;
	constant = screen_to_complex(mlx, x, y);
	complex.x = 0.0;
	complex.y = 0.0;
	while ((complex.x * complex.x + complex.y * complex.y < 4)
		&& (iter < mlx->max_iter))
	{
		tmp = complex.x * complex.x - complex.y * complex.y + constant.x;
		complex.y = ft_abs(2 * complex.x * complex.y) + constant.y;
		complex.x = tmp;
		iter++;
	}
	if (iter == mlx->max_iter)
		my_mlx_pixel_put(&mlx->img, x, y, 0x00000000);
	else if (iter < mlx->max_iter)
		my_mlx_pixel_put(&mlx->img, x, y, mlx->colour_func(mlx, iter));
}

void	*draw_burninghsip_thread(void *thread_struct_prot)
{
	int	x;
	int	y;
	t_thread_struct *thread_struct = thread_struct_prot;
	t_mlx *mlx = thread_struct->mlx;

	x = thread_struct->thread_id;
		printf("this is the id %p\n", thread_struct->mlx);

	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			burningship(mlx, x, y);
			y++;
		}
		x += 10;
	}
	return NULL;
}

void	draw_burninghsip( t_mlx *mlx )
{
	int		i;
	t_thread_struct		*thread_struct[10];

	i = 0;
	while (i < 10)
	{
		thread_struct[i] = calloc(sizeof(t_thread_struct), 1);
		thread_struct[i]->thread_id = i;
		thread_struct[i]->mlx = mlx;
		printf("hi i got here with number %i    %p\n", i, thread_struct[i]->mlx);
		
		pthread_create(&mlx->id_struct[i], NULL, draw_burninghsip_thread, thread_struct[i]);
		i++;
	}
	while (i > 0)
	{
		pthread_join(mlx->id_struct[i], NULL);
		// free(thread_struct[i]);
		i--;
	}
	printf("did i even get here?\n");
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img_ptr, 0, 0);
}
