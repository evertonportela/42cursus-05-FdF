/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 14:24:22 by evportel          #+#    #+#             */
/*   Updated: 2023/08/05 21:22:38 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

double	frct_map_real(int x, t_fractol *fractol)
{
	double	range;
	range = fractol->max_real - fractol->min_real;
	return (fractol->min_real + (x * range) / WIN_WIDTH);
}

double	frct_map_imag(int y, t_fractol *fractol)
{
	double	range;
	range = fractol->max_imaginary - fractol->min_imaginary;
	return (fractol->min_imaginary + (y * range) / WIN_HEIGHT);
}

void	frct_pixel_print(t_img *image, int x, int y, int color)
{
	char	*pixel;
	pixel = image->address + (y * image->line_length + x * (image->bits_pixel / 8));
	*(int *)pixel = color;
}

void	frct_color(int x, int y, int iterator, t_fractol *fractol)
{
	int	color;
	color = 0;
	if (iterator == fractol->max_imaginary)
		color = 0x000000;
	else if (fractol->color > 5)
		color = FCTL_COLOR_CYAN;
	else if (fractol->color <= 5)
		color = FCTL_COLOR_YELLOW;
	frct_pixel_print(&fractol->image, x, y, color);
}

int	frct_draw(t_fractol *fractol)
{
	mlx_clear_window(fractol->mlx_ptr, fractol->win_ptr);
	
	/** function set_fractal **/
	double	x;
	double	y;
	int		iterator;

	x = -1;
	iterator = 0;
	while (++x < WIN_WIDTH)
	{
		y = -1;
		while (++y < WIN_HEIGHT)
		{
			iterator = mandelbrot(frct_map_real(x, fractol), frct_map_imag(y, fractol), fractol);
			frct_color(x, y, iterator, fractol);
		}
	}
	/** function set_fractal **/

	mlx_put_image_to_window(fractol->mlx_ptr, fractol->win_ptr, fractol->image.mlx_img, 0, 0);

	return (MLX_SUCCESS);
}

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
	fract.image.address = mlx_get_data_addr(fract.image.mlx_img, &fract.image.bits_pixel,
		&fract.image.line_length, &fract.image.endian);
	
	/** Init Mandelbrot **/
	fract.max_real = 2.0;
	fract.min_real = -2.0;
	fract.max_imaginary = 2.0;
	fract.min_imaginary = -2.0;
	fract.max_iterator = 100;
	fract.color = 0;
	fract.args = 0;
	
	/** Init MLX Loop Hook **/
	mlx_loop_hook(fract.mlx_ptr, &frct_draw, &fract);
	// mlx_hook();
	// mlx_destroy_image();
	// mlx_destroy_window();
	// mlx_destroy_display();
	// free();

	mlx_loop(fract.mlx_ptr);
	
	return (MLX_SUCCESS);
}
