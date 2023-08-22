/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_struct_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:55:35 by evportel          #+#    #+#             */
/*   Updated: 2023/08/22 15:33:03 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	utils_set_fractol_init(t_fractol *fract)
{
	if (fract->fractol == 1)
		fct_init_mandelbrot(fract);
	else if (fract->fractol == 2)
		fct_init_julia(fract);
}

int	utils_mlx_init(t_fractol *fract)
{
	fract->mlx_ptr = mlx_init();
	if (fract->mlx_ptr == NULL)
		return (MLX_ERROR);
	fract->win_ptr = mlx_new_window(fract->mlx_ptr, WIDTH, HEIGHT,
			"42SP - Fract-ol");
	if (fract->win_ptr == NULL)
	{
		free(fract->win_ptr);
		return (MLX_ERROR);
	}
	fract->image.mlx_img = mlx_new_image(fract->mlx_ptr, WIDTH,
			HEIGHT);
	fract->image.address = mlx_get_data_addr(
			fract->image.mlx_img, &fract->image.bits_pixel,
			&fract->image.line_length, &fract->image.endian);
	utils_set_fractol_init(fract);
	return (MLX_SUCCESS);
}
