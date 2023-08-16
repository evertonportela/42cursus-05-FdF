/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mouse_zoom.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 09:18:30 by evportel          #+#    #+#             */
/*   Updated: 2023/08/16 09:18:36 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

int	utils_mouse_zoom(int key_pressed, t_fractol *fract)
{
	if (key_pressed == 4)
	{
		fract->min_real -= fract->min_real * 0.1;
		fract->max_real -= fract->max_real * 0.1;
		fract->min_imaginary -= fract->min_imaginary * 0.1;
		fract->max_imaginary -= fract->max_imaginary * 0.1;
	}
	if (key_pressed == 5)
	{
		fract->min_real += fract->min_real * 0.1;
		fract->max_real += fract->max_real * 0.1;
		fract->min_imaginary += fract->min_imaginary * 0.1;
		fract->max_imaginary += fract->max_imaginary * 0.1;
	}
	return (MLX_SUCCESS);
}
