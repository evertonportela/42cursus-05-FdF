/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:56:36 by evportel          #+#    #+#             */
/*   Updated: 2023/08/22 15:32:59 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <X11/keysym.h>

# define WIDTH 800.0
# define HEIGHT 800.0

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
 * @param min_real Limit of the plane that will be mapped to the window.
 * @param max_real Limit of the plane that will be mapped to the window.
 * @param min_imaginary Limit of the plane that will be mapped to the window.
 * @param max_imaginary Limit of the plane that will be mapped to the window.
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
	float	min_real;
	float	max_real;
	float	min_imaginary;
	float	max_imaginary;
	int		args;
	double	arg_real;
	double	arg_imaginary;
	t_img	image;
}			t_fractol;

/* Functions Fractol */
int		fct_mandelbrot(double const_real, double const_imaginary,
			t_fractol *fractal);
int		fct_julia(double const_real, double const_imaginary,
			t_fractol *fractal);

void	fct_init_mandelbrot(t_fractol *fract);
void	fct_init_julia(t_fractol *fract);

int		fct_check_args_julia(int argc, char *argv[], t_fractol *fract);
int		fct_draw(t_fractol *fract);
void	fct_pixel_print(t_img *image, int x, int y, int color);

/* Funtions Utils */
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		utils_check_args(int argc, char *argv[], t_fractol *fract);
int		utils_check_double(char *str);
int		utils_mlx_init(t_fractol *fract);
int		utils_error_message(void);
void	utils_set_fractol_init(t_fractol *fract);
int		utils_key_input(int key, t_fractol *fract);
void	utils_update_iterator(int key, t_fractol *fract);
int		utils_close_window(t_fractol *fract);
double	utils_char_to_double(char *str);
int		utils_mouse_zoom(int key_pressed, int x, int y, t_fractol *fract);
void	utils_keyboard_zoom(int key_pressed, t_fractol *fract);

#endif
