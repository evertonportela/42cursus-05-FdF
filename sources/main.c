/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evertonsantos <evertonsantos@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 14:24:22 by evportel          #+#    #+#             */
/*   Updated: 2023/08/15 18:59:42 by evertonsant      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/** 
 * Checks - Valid Arguments
 * Checks - Initialize Atributes MLX
 * Initialize Loops and Hooks
 * */
int	main(int argc, char *argv[])
{
	t_fractol	fract;

	if (utils_check_args(argc, argv, &fract) == MLX_ERROR)
		return (MLX_ERROR);
	if (utils_mlx_init(&fract) == MLX_ERROR)
		return (MLX_ERROR);
	mlx_loop_hook(fract.mlx_ptr, &fct_draw, &fract);
	mlx_hook(fract.win_ptr, 2, 1L << 0, &utils_key_input, &fract);
	mlx_hook(fract.win_ptr, 17, 0L, &utils_close_window, &fract);
	mlx_hook(fract.win_ptr, 4, 1L << 2, &utils_mouse_zoom, &fract);
	mlx_loop(fract.mlx_ptr);
	return (MLX_SUCCESS);
}
