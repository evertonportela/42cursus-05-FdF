/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 14:24:22 by evportel          #+#    #+#             */
/*   Updated: 2023/08/04 15:31:57 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

double	map_re(int x, t_fractol *fractol)
{
	double	range;

	range = fractol->max_real - fractol->min_real;
	return (fractol->min_real + (x * range) / WINDOW_WIDTH);
}

double	map_imaginary(int y, t_fractol *fractol)
{
	double	range;

	range = fractol->max_imaginary - fractol->min_imaginary;
	return (fractol->min_imaginary + (y * range) / WINDOW_HEIGHT);
}

int	render(t_fractol *fractol)
{
	mlx_clear_window(fractol->mlx_ptr, fractol->win_ptr);
	//set_fractol();
	/* depois colocar na funcao set_fractal */
	int iterator = 0;
	int x = -1, y = -1;
	while (++x < WINDOW_WIDTH)
	{
		y = -1;
		while (++y < WINDOW_HEIGHT)
		{
			iterator = mandelbrot(map_re(x, fractol), map_imaginary(y, fractol), fractol);
		}
		
	}
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->win_ptr,
		fractol->image.mlx_img, 0, 0);
	return (MLX_SUCCESS);
}

//int	main(int argc, char *argv[])
int	main(void)
{
	t_fractol	fractol;

	mlx_loop_hook(fractol.mlx_ptr, &render, &fractol);
	return (MLX_SUCCESS);
}
