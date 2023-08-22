/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fractol_zoom_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 09:18:30 by evportel          #+#    #+#             */
/*   Updated: 2023/08/22 15:13:23 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol_bonus.h"

static void	utils_mouse_zoom_move(int x, int y, t_fractol *fract)
{
	x -= WIN_WIDTH / 2;
	y -= WIN_HEIGHT / 2;
	fract->mid_win_x = fract->max_imaginary - fract->min_imaginary;
	fract->mid_win_y = fract->max_real - fract->min_real;
	if (y < 0)
	{
		fract->max_imaginary = ;
		fract->min_imaginary = ;
	}
}

int	utils_mouse_zoom(int key_pressed, int x, int y, t_fractol *fract)
{
	x = fract->max_real - fract->min_real;
	y = fract->max_imaginary - fract->min_imaginary;
	if (key_pressed == 4)
	{
		fract->min_real += x * 0.115;
		fract->max_real -= x * 0.115;
		fract->min_imaginary += y * 0.115;
		fract->max_imaginary -= y * 0.115;
		utils_mouse_zoom_move(x, y, WIN_WIDTH / 2, WIN_HEIGHT / 2, fract);
	}
}

void	utils_keyboard_zoom(int key_pressed, t_fractol *fract)
{
	double	refresh_real;
	double	refresh_imaginary;

	refresh_real = fract->max_real - fract->min_real;
	refresh_imaginary = fract->max_imaginary - fract->min_imaginary;
	if (key_pressed == '=')
	{
		fract->min_real += refresh_real * 0.125;
		fract->max_real -= refresh_real * 0.125;
		fract->min_imaginary += refresh_imaginary * 0.125;
		fract->max_imaginary -= refresh_imaginary * 0.125;
	}
	else if (key_pressed == '-')
	{
		fract->min_real -= refresh_real * 0.125;
		fract->max_real += refresh_real * 0.125;
		fract->min_imaginary -= refresh_imaginary * 0.125;
		fract->max_imaginary += refresh_imaginary * 0.125;
	}
}


/**
int	utils_mouse_zoom(int key_pressed, int x, int y, t_fractol *fract)
{
	x = 1;
	y = 1;
	if (key_pressed == 4 && x)
	{
		fract->min_real -= fract->min_real * 0.125;
		fract->max_real -= fract->max_real * 0.125;
		fract->min_imaginary -= fract->min_imaginary * 0.125;
		fract->max_imaginary -= fract->max_imaginary * 0.125;
	}
	if (key_pressed == 5 && y)
	{
		fract->min_real += fract->min_real * 0.125;
		fract->max_real += fract->max_real * 0.125;
		fract->min_imaginary += fract->min_imaginary * 0.125;
		fract->max_imaginary += fract->max_imaginary * 0.125;
	}
	return (MLX_SUCCESS);
}
*/