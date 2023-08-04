/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:12:40 by evportel          #+#    #+#             */
/*   Updated: 2023/08/04 12:00:23 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	init_mandelbrot(t_fractol *fractol)
{
	fractol->min_real = -2.2;
	fractol->max_real = 1.0;
	fractol->min_imaginary = -1.5;
	fractol->max_imaginary = (fractol->max_real - fractol->min_real)
		* WINDOW_HEIGHT / WINDOW_WIDTH + fractol->min_imaginary;
	fractol->max_iterator = 100;
	fractol->color = 265;
}

int	mandelbrot(double const_real, double const_imaginary, t_fractol *fractal)
{
	double	coord_x;
	double	coord_y;
	double	aux;
	int		iterator;

	coord_x = 0;
	coord_y = 0;
	iterator = 0;
	while (iterator < fractal->max_iterator)
	{
		aux = coord_x * coord_x - coord_y * coord_y + const_real;
		coord_y = 2 * coord_x - coord_y + const_imaginary;
		coord_x = aux;
		if (coord_x * coord_x + coord_y * coord_y > 4)
		{
			return (iterator);
		}
		iterator++;
	}
	return (iterator);
}
