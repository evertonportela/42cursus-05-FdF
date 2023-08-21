/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_draw_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:00:13 by evportel          #+#    #+#             */
/*   Updated: 2023/08/21 17:22:29 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol_bonus.h"

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

static void	fct_select_fractal_draw(t_fractol *fract)
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
			if (fract->fractol == 1)
				iterator = fct_mandelbrot(fct_map_real(x, fract),
						fct_map_imaginary(y, fract), fract);
			else if (fract->fractol == 2)
				iterator = fct_julia(fct_map_real(x, fract),
						fct_map_imaginary(y, fract), fract);
			else if (fract->fractol == 3)
				iterator = fct_tricorn(fct_map_real(x, fract),
						fct_map_imaginary(y, fract), fract);
			fct_color(x, y, iterator, fract);
		}
	}
}

int	fct_draw(t_fractol *fract)
{
	mlx_clear_window(fract->mlx_ptr, fract->win_ptr);
	fct_select_fractal_draw(fract);
	mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr,
		fract->image.mlx_img, 0, 0);
	return (MLX_SUCCESS);
}
