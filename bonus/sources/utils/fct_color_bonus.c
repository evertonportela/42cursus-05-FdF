/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_color_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:30:18 by evportel          #+#    #+#             */
/*   Updated: 2023/08/22 09:49:56 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol_bonus.h"

void	fct_pixel_print(t_img *image, int x, int y, int color)
{
	char	*pixel;

	pixel = image->address
		+ (y * image->line_length + x * (image->bits_pixel / 8));
	*(unsigned int *)pixel = color;
}

int	fct_color_pack_1(int number)
{
	if (number % 8 == 7)
		return (0xFF3D5C);
	else if (number % 8 == 6)
		return (0xE024BA);
	else if (number % 8 == 5)
		return (0xE024BA);
	else if (number % 8 == 4)
		return (0xBF08F5);
	else if (number % 8 == 3)
		return (0xBF08F5);
	else if (number % 8 == 2)
		return (0x7C34E0);
	else if (number % 8 == 1)
		return (0x685CFF);
	else if (number % 8 == 0)
		return (0x685CFF);
	return (0);
}

int	fct_color_pack_2(int number)
{
	if (number % 8 == 7)
		return (0x2390FC);
	else if (number % 8 == 6)
		return (0x1FB4E0);
	else if (number % 8 == 5)
		return (0x2FF7F1);
	else if (number % 8 == 4)
		return (0x2FF7F1);
	else if (number % 8 == 3)
		return (0x1FE0A3);
	else if (number % 8 == 2)
		return (0x1FE0A3);
	else if (number % 8 == 1)
		return (0x23FC7A);
	else if (number % 8 == 0)
		return (0x23FC7A);
	return (0);
}

int	fct_color_pack_3(int number)
{
	if (number % 8 == 7)
		return (0x23B8B3);
	else if (number % 8 == 6)
		return (0x177875);
	else if (number % 8 == 5)
		return (0x2FF7F1);
	else if (number % 8 == 4)
		return (0x2FF7F1);
	else if (number % 8 == 3)
		return (0x0B3837);
	else if (number % 8 == 2)
		return (0x0B3837);
	else if (number % 8 == 1)
		return (0x2ADED8);
	else if (number % 8 == 0)
		return (0x2ADED8);
	return (0);
}

void	fct_color(int x, int y, int iterator, t_fractol *fract)
{
	int	color;

	color = 0;
	if (iterator == fract->max_iterator)
		color = 0x000000;
	else if (fract->color == 0)
		color = fct_color_pack_1(iterator);
	else if (fract->color == 1)
		color = fct_color_pack_2(iterator);
	else if (fract->color == 2)
		color = fct_color_pack_3(iterator);
	fct_pixel_print(&fract->image, x, y, color);
}
