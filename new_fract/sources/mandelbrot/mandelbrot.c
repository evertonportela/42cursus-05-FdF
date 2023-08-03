/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:12:40 by evportel          #+#    #+#             */
/*   Updated: 2023/08/03 18:43:43 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	init_mandelbrot()
{
	
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
