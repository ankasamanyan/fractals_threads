/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankasamanyan <ankasamanyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:34:38 by akasaman          #+#    #+#             */
/*   Updated: 2022/07/12 22:49:37 by ankasamanya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_copmlx	screen_to_complex(t_mlx *mlx, int x, int y)
{
	t_copmlx	complex;

	complex.x = (x / (double)WIDTH) * (mlx->max_x - mlx->min_x) + mlx->min_x;
	complex.y = (y / (double)HEIGHT) * (mlx->max_y - mlx->min_y) + mlx->min_y;
	return (complex);
}

double	ft_abs(double i)
{
	if (i >= 0)
		return (i);
	else
		return (-1 * i);
}

// t_copmlx	vector_add(t_copmlx first, t_copmlx second)
// {
// 	t_copmlx	complex;

// 	complex.x = first.x + second.x;
// 	complex.y = first.y + second.y;
// 	return (complex);
// }

// t_copmlx	vector_multpl(t_copmlx first, t_copmlx second)
// {
// 	t_copmlx	complex;

// 	complex.x = (first.x * second.x) - (first.y * second.y);
// 	complex.y = 2 * (first.x * second.y);
// 	return (complex);
// }

// t_copmlx	the_math(t_copmlx z, t_copmlx constant)
// {
// 	z = vector_add(vector_multpl(z, z), constant);
// 	return (z);
// }