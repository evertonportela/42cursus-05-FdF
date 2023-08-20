/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:30:18 by evportel          #+#    #+#             */
/*   Updated: 2023/08/20 12:08:24 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	fct_pixel_print(t_img *image, int x, int y, int color)
{
	char	*pixel;

	pixel = image->address
		+ (y * image->line_length + x * (image->bits_pixel / 8));
	*(unsigned int *)pixel = color;
}
