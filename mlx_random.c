/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_random.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankasamanyan <ankasamanyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 19:06:18 by ankasamanya       #+#    #+#             */
/*   Updated: 2022/07/14 19:29:37 by ankasamanya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->data + (y * data->size_l + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	get_colour(t_colour colour)
{
	int	trgb;

	trgb = colour.t << 24 | colour.r << 16 | colour.g << 8 | colour.b;
	return (trgb);
}

void	print_message(void)
{
	ft_printf("\033[0;31m\n\n\t\t\t\t\t================================");
	ft_printf("=======================");
	ft_printf("\n\n\t\t\t\t\t   <<<>>>  Error: Wrong number of arguments! ");
	ft_printf("<<<>>>\n\n");
	ft_printf("\t\t\t\t\t===================================");
	ft_printf("====================\n\n\033[0m");
	ft_printf("\033[0;33mHow to use fractal: './fractol <flag> <colour> ");
	ft_printf("(<julia_set_number)>'\033[0m\n\n");
	ft_printf("==================================================");
	ft_printf("\t=========================\t=========================\n");
	ft_printf("|\tNAME OF THE SET\t\t|\tFLAG\t |\t|\t  COLOUR \t|\t|");
	ft_printf("    JULIA SET NUMBER   |\n");
	ft_printf("==================================================");
	ft_printf("\t=========================\t=========================\n");
	ft_printf("|\t          \t\t|\t   \t |\t|\t  blue\t\t|\t|\t    1\t\t|\n");
	ft_printf("|\tMandelbrot\t\t|\t -m\t |\t|\t  hippy\t\t|\t|\t    2\t\t|\n");
	ft_printf("|\tBurning ship\t\t|\t -b\t |\t|\t  acid\t\t|\t|\t    3\t\t|\n");
	ft_printf("|\tJulia\t\t\t|\t -j\t |\t|\t  mono\t\t|\t|\t    4\t\t|\n");
	ft_printf("|\t          \t\t|\t   \t |\t|\t  pastel\t|\t|\t     \t\t|\n");
	ft_printf("==================================================");
	ft_printf("\t=========================\t=========================\n");
	ft_printf("\033[0;33m Examples: \"./fractol -m blue\" ,");
	ft_printf(" \"./fractol -j hippy 3\" \033[0m\n\n");
}
