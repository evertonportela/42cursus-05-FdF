/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 14:24:22 by evportel          #+#    #+#             */
/*   Updated: 2023/08/05 20:30:44 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(void)
{
	t_fractol fract;
	
	/** Init MLX **/
	fract.mlx_ptr = mlx_init();
	if (fract.mlx_ptr == NULL)
		return (MLX_ERROR);
	
	/** Init New Window **/
	fract.win_ptr = mlx_new_window(fract.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Fract-ol");
	if (fract.win_ptr == NULL)
	{
		free(fract.win_ptr);
		return (MLX_ERROR);
	}
	
	/** Init MLX Image **/
	fract.image.mlx_img = mlx_new_image(fract.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	
	/** Init MLX Address **/
	fract.image.address = mlx_get_data_addr(fract.image.mlx_img, fract.image.bits_pixel,
		fract.image.line_length, fract.image.endian);
	
	/** Init Mandelbrot **/
	fract.max_real = 2.0;
	fract.min_real = -2.0;
	fract.max_imaginary = 2.0;
	fract.min_imaginary = -2.0;
	fract.max_iterator = 100;
	fract.color = 0;
	fract.args = 0;
	
	int	frct_draw(t_fractol *fractol)
	{
		
	}
	
	/** Init MLX Loop Hook **/
	mlx_loop_hook(fract.mlx_ptr, &frct_draw, &fract);
	mlx_hook();
	mlx_destroy_image();
	mlx_destroy_window();
	mlx_destroy_display();
	free()
	
	return (MLX_SUCCESS);
}
