/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fractol_zoom.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 09:18:30 by evportel          #+#    #+#             */
/*   Updated: 2023/08/16 12:01:55 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

int	utils_mouse_zoom(int key_pressed, int x, int y, t_fractol *fract)
{
	x = 1;
	y = 1;
	if (key_pressed == 4 && x)
	{
		fract->min_real -= fract->min_real * 0.1;
		fract->max_real -= fract->max_real * 0.1;
		fract->min_imaginary -= fract->min_imaginary * 0.1;
		fract->max_imaginary -= fract->max_imaginary * 0.1;
	}
	if (key_pressed == 5 && y)
	{
		fract->min_real += fract->min_real * 0.1;
		fract->max_real += fract->max_real * 0.1;
		fract->min_imaginary += fract->min_imaginary * 0.1;
		fract->max_imaginary += fract->max_imaginary * 0.1;
	}
	return (MLX_SUCCESS);
}

void	utils_keyboard_zoom(int key_pressed, t_fractol *fract)
{
	if (key_pressed == '=')
	{
		fract->min_real -= fract->min_real * 0.1;
		fract->max_real -= fract->max_real * 0.1;
		fract->min_imaginary -= fract->min_imaginary * 0.1;
		fract->max_imaginary -= fract->max_imaginary * 0.1;
	}
	else if (key_pressed == '-')
	{
		fract->min_real += fract->min_real * 0.1;
		fract->max_real += fract->max_real * 0.1;
		fract->min_imaginary += fract->min_imaginary * 0.1;
		fract->max_imaginary += fract->max_imaginary * 0.1;
	}
}
