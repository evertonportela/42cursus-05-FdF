/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check_args_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:46:14 by evportel          #+#    #+#             */
/*   Updated: 2023/08/22 10:28:08 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol_bonus.h"

int	utils_error_message(void)
{
	write(1, "Use ./fractol [Fractal Name]\n", 30);
	write(1, "(1) Mandelbrot\n\n", 17);
	write(1, "(2) Julia [real param] [imaginary param]\n", 42);
	write(1, "Suggestions:\n", 14);
	write(1, "-0.4  0.6 |  0.285 0   |  0.45 0.1428\n", 39);
	write(1, "-0.6 -0.2 | -0.54  0.5 | -0.08 0.72\n\n", 38);
	write(1, "(3) Tricorn\n\n", 14);
	write(1, "Keyboard Shotcuts:\n", 20);
	write(1, "Q - Iterations Out\t'-' Zoom Out\n", 33);
	write(1, "E - Iteration In\t'+' Zoom In\n", 30);
	return (MLX_ERROR);
}

int	utils_check_args(int argc, char *argv[], t_fractol *fract)
{
	fract->fractol = 0;
	if (argc < 2 || argc > 4)
		return (utils_error_message());
	else if (ft_strncmp(argv[1], "Mandelbrot", 11) == 0)
	{
		fract->fractol = 1;
		return (MLX_SUCCESS);
	}
	else if (ft_strncmp(argv[1], "Julia", 6) == 0)
	{	
		fract->fractol = 2;
		if (fct_check_args_julia(argc, argv, fract) == 0)
			return (MLX_SUCCESS);
		return (utils_error_message());
	}
	else if (ft_strncmp(argv[1], "Tricorn", 8) == 0)
	{
		fract->fractol = 3;
		return (MLX_SUCCESS);
	}
	else
		return (utils_error_message());
}
