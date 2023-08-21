/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_color_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:30:18 by evportel          #+#    #+#             */
/*   Updated: 2023/08/21 18:23:13 by evportel         ###   ########.fr       */
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
		return (0xff5232);
	else if (number % 8 == 6)
		return (0xFF0000);
	else if (number % 8 == 5)
		return (0xd11507);
	else if (number % 8 == 4)
		return (0xa51b0b);
	else if (number % 8 == 3)
		return (0x7a1b0c);
	else if (number % 8 == 2)
		return (0x52170b);
	else if (number % 8 == 1)
		return (0x2d1106);
	else if (number % 8 == 0)
		return (0x000000);
	return (0);
}
/**
 * 0xFF3D5C < 1
 * 0xE024BA < 3
 * 0xBF08F5 < 5
 * 0x7C34E0 < 7
 * 0x685CFF < 8
*/

void	fct_color(int x, int y, int iterator, t_fractol *fract)
{
	int	color;

	color = 0;
	if (iterator == fract->max_iterator)
		color = 0x000000;
	else if (fract->color == 0)
		fct_color_pack_1(iterator);
	fct_pixel_print(&fract->image, x, y, color);
}
