/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_julia_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:44:38 by evportel          #+#    #+#             */
/*   Updated: 2023/08/22 15:32:45 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol_bonus.h"

void	fct_init_julia(t_fractol *fract)
{
	fract->min_real = -2.0;
	fract->max_real = 2.0;
	fract->min_imaginary = -2.0;
	fract->max_imaginary = (fract->max_real - fract->min_real)
		* (HEIGHT / WIDTH) + fract->min_imaginary;
	fract->max_iterator = 250;
	fract->color = 0;
}

int	fct_check_args_julia(int argc, char *argv[], t_fractol *fract)
{
	if (argc != 4)
		return (MLX_ERROR);
	if (utils_check_double(argv[2]) == MLX_ERROR
		|| utils_check_double(argv[3]) == MLX_ERROR)
		return (MLX_ERROR);
	fract->arg_real = utils_char_to_double(argv[2]);
	if (fract->arg_real < -2.0 || fract->arg_real > 2.0)
		return (MLX_ERROR);
	fract->arg_imaginary = utils_char_to_double(argv[3]);
	if (fract->arg_imaginary < -2.0 || fract->arg_imaginary > 2.0)
		return (MLX_ERROR);
	if (fract->arg_imaginary == 0 && fract->arg_real == 0)
		fract->args = 0;
	else
		fract->args = 1;
	return (MLX_SUCCESS);
}

int	fct_julia(double var_real, double var_imaginary, t_fractol *fractal)
{
	double	coord_x;
	double	coord_y;
	double	aux;
	int		iterator;

	coord_x = var_real;
	coord_y = var_imaginary;
	iterator = 0;
	while (iterator < fractal->max_iterator)
	{
		aux = coord_x * coord_x - coord_y * coord_y + fractal->arg_real;
		coord_y = 2 * coord_x * coord_y - fractal->arg_imaginary;
		coord_x = aux;
		if (coord_x * coord_x + coord_y * coord_y > 4)
			return (iterator);
		iterator++;
	}
	return (iterator);
}
