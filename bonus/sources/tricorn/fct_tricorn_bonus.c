/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_tricorn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:12:40 by evportel          #+#    #+#             */
/*   Updated: 2023/08/21 17:05:30 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol_bonus.h"

void	fct_init_tricorn(t_fractol *fract)
{
	fract->min_real = -2.1;
	fract->max_real = 2.0;
	fract->min_imaginary = -2.0;
	fract->max_imaginary = (fract->max_real - fract->min_real)
		* (WIN_HEIGHT / WIN_WIDTH) + fract->min_imaginary;
	fract->max_iterator = 100;
	fract->color = 2;
	fract->args = 0;
}

int	fct_tricorn(double const_real, double const_imaginary,
		t_fractol *fractal)
{
	double	coord_x;
	double	coord_y;
	double	aux;
	int		iterator;

	coord_x = const_real;
	coord_y = const_imaginary;
	iterator = 0;
	while (iterator < fractal->max_iterator)
	{
		aux = coord_x * coord_x - coord_y * coord_y + const_real;
		coord_y = 2 * coord_x * coord_y + const_imaginary;
		coord_x = aux;
		if (coord_x * coord_x + coord_y * coord_y > 4)
			return (iterator);
		iterator++;
	}
	return (iterator);
}
