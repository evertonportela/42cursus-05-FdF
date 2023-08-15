/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mouse_zoom.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evertonsantos <evertonsantos@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:02:55 by evertonsant       #+#    #+#             */
/*   Updated: 2023/08/15 18:58:22 by evertonsant      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

int	utils_mouse_zoom(int key_pressed, t_fractol *fract)
{

	if (key == 4)
	{
		fract->min_real -= fract->min_real * 0.1;
		fract->max_real -= fract->max_real * 0.1;
		fract->min_imaginary -= fract->min_imaginary * 0.1;
		fract->max_imaginary -= fract->max_imaginary * 0.1;
	}
	if (key == 5)
	{
		fract->min_real += fract->min_real * 0.1;
		fract->max_real += fract->max_real * 0.1;
		fract->min_imaginary += fract->min_imaginary * 0.1;
		fract->max_imaginary += fract->max_imaginary * 0.1;
	}
	return (MLX_SUCCESS);
}
