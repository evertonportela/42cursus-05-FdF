/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:00:13 by evportel          #+#    #+#             */
/*   Updated: 2023/08/08 17:36:26 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

static double	fct_map_real(int x, t_fractol *fract)
{
	double	range;

	range = fract->max_real - fract->min_real;
	return (fract->min_real + (x * range) / WIN_WIDTH);
}

static double	fct_map_imaginary(int y, t_fractol *fract)
{
	double	range;

	range = fract->max_imaginary - fract->min_imaginary;
	return (fract->min_imaginary + (y * range) / WIN_HEIGHT);
}

int	fct_draw(t_fractol *fract)
{
	double	x;
	double	y;
	int		iterator;

	x = 0;
	iterator = 0;
	while (x++ < WIN_WIDTH)
	{
		y = 0;
		while (y++ < WIN_HEIGHT)
		{
			iterator = fct_mandelbrot(fct_map_real(x, fract),
					fct_map_imaginary(y, fract), fract);
			fct_color(x, y, iterator, fract);
		}
	}
	mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr,
		fract->image.mlx_img, 0, 0);
	return (MLX_SUCCESS);
}
