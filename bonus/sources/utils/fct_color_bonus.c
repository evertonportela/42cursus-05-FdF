/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_color_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:30:18 by evportel          #+#    #+#             */
/*   Updated: 2023/08/21 17:39:19 by evportel         ###   ########.fr       */
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
	if (number % 8 == 0)
	{
		return (0xff5232);
	}
	return (0);
}

void	fct_color(int x, int y, int iterator, t_fractol *fract)
{
	int	color;

	color = 0;
	if (iterator == fract->max_iterator)
		color = 0x000000;
	else
		color = 0xFFFFFF;
	fct_pixel_print(&fract->image, x, y, color);
}
