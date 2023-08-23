/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fractol_zoom_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 09:18:30 by evportel          #+#    #+#             */
/*   Updated: 2023/08/23 10:55:08 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol_bonus.h"

static void	utils_zoom_updown(double zoom, char *direction, t_fractol *fract)
{
	if (ft_strncmp(direction, "down", 5) == 0)
	{
		fract->min_real += (fract->max_imaginary - fract->min_imaginary) * zoom;
		fract->max_real -= (fract->max_imaginary - fract->min_imaginary) * zoom;
		fract->min_imaginary += (fract->max_real - fract->min_real) * zoom;
		fract->max_imaginary = (fract->max_real - fract->min_real)
			* HEIGHT / WIDTH + fract->min_imaginary;
	}
	else if (ft_strncmp(direction, "up", 3) == 0)
	{
		fract->min_real -= (fract->max_imaginary - fract->min_imaginary) * zoom;
		fract->max_real += (fract->max_imaginary - fract->min_imaginary) * zoom;
		fract->min_imaginary -= (fract->max_real - fract->min_real) * zoom;
		fract->max_imaginary = (fract->max_real - fract->min_real)
			* HEIGHT / WIDTH + fract->min_imaginary;
	}
}

static void	utils_zoom_leftright(double zoom, char *direction, t_fractol *fract)
{
	double	refresh_x;
	double	refresh_y;

	refresh_x = fract->max_real - fract-> min_real;
	refresh_y = fract->max_imaginary - fract-> min_imaginary;
	if (ft_strncmp(direction, "right", 6) == 0)
	{
		fract->min_real += refresh_x * zoom;
		fract->max_real += refresh_x * zoom;
	}
	else if (ft_strncmp(direction, "left", 5) == 0)
	{
		fract->min_real -= refresh_x * zoom;
		fract->max_real -= refresh_x * zoom;
	}
	if (ft_strncmp(direction, "up", 3) == 0)
	{
		fract->min_imaginary -= refresh_y * zoom;
		fract->max_imaginary -= refresh_y * zoom;
	}
	else if (ft_strncmp(direction, "down", 5) == 0)
	{
		fract->min_imaginary += refresh_y * zoom;
		fract->max_imaginary += refresh_y * zoom;
	}
}

int	utils_mouse_zoom(int key_pressed, int x, int y, t_fractol *fract)
{
	if (key_pressed == 4)
	{
		utils_zoom_updown(0.1, "down", fract);
		x -= WIDTH / 2;
		y -= HEIGHT / 2;
		if (x < 0)
			utils_zoom_leftright(ft_abs(x) / WIDTH, "left", fract);
		else if (x > 0)
			utils_zoom_leftright(x / WIDTH, "right", fract);
		else if (y < 0)
			utils_zoom_leftright(ft_abs(y) / HEIGHT, "up", fract);
		else if (y > 0)
			utils_zoom_leftright(y / HEIGHT, "down", fract);
	}
	if (key_pressed == 5)
		utils_zoom_updown(0.1, "up", fract);
	return (MLX_SUCCESS);
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
