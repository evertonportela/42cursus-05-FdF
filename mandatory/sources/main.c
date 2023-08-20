/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 09:17:06 by evportel          #+#    #+#             */
/*   Updated: 2023/08/20 12:05:50 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int argc, char *argv[])
{
	t_fractol	fract;

	if (utils_check_args(argc, argv, &fract) == MLX_ERROR)
		return (MLX_ERROR);
	if (utils_mlx_init(&fract) == MLX_ERROR)
		return (MLX_ERROR);
	mlx_loop_hook(fract.mlx_ptr, &fct_draw, &fract);
	mlx_hook(fract.win_ptr, 2, 1L << 0, &utils_key_input, &fract);
	mlx_hook(fract.win_ptr, 4, 1L << 2, &utils_mouse_zoom, &fract);
	mlx_hook(fract.win_ptr, 17, 0L, &utils_close_window, &fract);
	mlx_loop(fract.mlx_ptr);
	return (MLX_SUCCESS);
}
