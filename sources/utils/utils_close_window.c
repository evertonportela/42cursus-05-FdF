/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_close_window.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:08:00 by evportel          #+#    #+#             */
/*   Updated: 2023/08/11 10:21:39 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

int	utils_close_window(t_fractol *fract)
{
	mlx_destroy_image(fract->mlx_ptr, fract->image.mlx_img);
	mlx_destroy_window(fract->mlx_ptr, fract->win_ptr);
	mlx_destroy_display(fract->mlx_ptr);
	free(fract->mlx_ptr);
	exit(MLX_SUCCESS);
}
