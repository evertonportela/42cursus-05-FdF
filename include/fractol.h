/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:56:36 by evportel          #+#    #+#             */
/*   Updated: 2023/08/05 20:06:44 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>

# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000

# define MLX_ERROR 1
# define MLX_SUCCESS 0

/**
 * @brief MLX image structure T_IMG
 * 
 * @param mlx_img Refers to the address that mlx_new_image returns.
 * @param img_addr The address of the image.
 * @param bits_pixel The bits per pixel of the image.
 * @param line_length The size of an image line.
 * @param endian byte encoding system used. (endianness)
 */
typedef struct s_img
{
	void	*mlx_img;
	char	*address;
	int		bits_pixel;
	int		line_length;
	int		endian;
}			t_img;

/**
 * @brief Structure of the fractal that will be drawn on the screen T_FRACTOL
 * 
 * @param mlx_ptr A pointer to the MiniLibX graphical instance.
 * @param win_ptr A pointer to the window created by MiniLibx.
 * @param max_iterator Represents maximum iterations for calculating a fractal.
 * @param fractol Indicates which type of fractal will be drawn.
 * @param color Represents the color used in the fractal design.
 * @param x0 Initial value of the X coordinate in the plane.
 * @param y0 Initial value of the Y coordinate in the plane.
 * @param min_real Limit of the plane that will be mapped to the window.
 * @param max_real Limit of the plane that will be mapped to the window.
 * @param min_imaginary Limit of the plane that will be mapped to the window.
 * @param max_imaginary Limit of the plane that will be mapped to the window.
 * @param args Indicates the number of arguments passed to the program.
 * @param arg_real Represent arguments related to the fractal parameter.
 * @param arg_imaginary Represent arguments related to the fractal parameter.
 * @param image Store the fractal drawing before it is plotted in the window.
*/
typedef struct s_fractol
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		max_iterator;
	int		fractol;
	int		color;
	double	x0;
	double	y0;
	double	min_real;
	double	max_real;
	double	min_imaginary;
	double	max_imaginary;
	int		args;
	double	arg_real;
	double	arg_imaginary;
	t_img	image;
}			t_fractol;

int	mandelbrot(double const_real, double const_imaginary, t_fractol *fractal);

#endif