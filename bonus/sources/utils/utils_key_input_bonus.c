/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_key_input_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:27:52 by evportel          #+#    #+#             */
/*   Updated: 2023/08/22 11:23:54 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol_bonus.h"

static void	utils_arrows_input(int key, t_fractol *fract)
{
	if (key == XK_Left)
	{
		fract->min_real -= (fract->max_real - fract->min_real) * 0.1;
		fract->max_real -= (fract->max_real - fract->min_real) * 0.1;
	}
	if (key == XK_Right)
	{
		fract->min_real += (fract->max_real - fract->min_real) * 0.1;
		fract->max_real += (fract->max_real - fract->min_real) * 0.1;
	}
	if (key == XK_Up)
	{
		fract->min_imaginary -= (fract->max_imaginary - fract->min_imaginary)
			* 0.1;
		fract->max_imaginary -= (fract->max_imaginary - fract->min_imaginary)
			* 0.1;
	}
	if (key == XK_Down)
	{
		fract->min_imaginary += (fract->max_imaginary - fract->min_imaginary)
			* 0.1;
		fract->max_imaginary += (fract->max_imaginary - fract->min_imaginary)
			* 0.1;
	}
}

static void	utils_letters_input(int key, t_fractol *fract)
{
	if (key == XK_Escape)
		utils_close_window(fract);
	else if (key == 'r')
		utils_set_fractol_init(fract);
	else if (key == 'q' || key == 'e')
		utils_update_iterator(key, fract);
	else if (key == '-' || key == '=')
		utils_keyboard_zoom(key, fract);
	else if (key == 'c')
	{
		if (fract->color < 2)
			fract->color++;
		else
			fract->color = 0;
	}
}

int	utils_key_input(int key, t_fractol *fract)
{
	utils_arrows_input(key, fract);
	utils_letters_input(key, fract);
	return (MLX_SUCCESS);
}
