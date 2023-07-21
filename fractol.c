/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:03:45 by evportel          #+#    #+#             */
/*   Updated: 2023/07/21 15:44:29 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include <X11/X.h>
#include <X11/keysym.h>

#define MLX_ERROR 1
#define MLX_SUCCESS 0

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 300

#define WHITE_PIXEL 0xFFFFFF
#define GREEN_PIXEL 0xFF00
#define RED_PIXEL 0xFF0000

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	int		cur_img;
}	t_data;

typedef struct s_rectangle
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_rectangle;

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		/* big endian, MSB is the leftmost bit */
		if (img->endian != 0)
			*pixel++ = (color >> 1) & 0xFF;
		/* litte endian, LSB is the lefmost bit */
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			img_pix_put(img, j++, i, color);
		}
		++i;
	}
}

int	render_rectangle(t_img *img, t_rectangle rectangle)
{
	int	i;
	int	j;

	i = rectangle.y;
	while (i < rectangle.y + rectangle.height)
	{
		j = rectangle.x;
		while (j < rectangle.x + rectangle.width)
			img_pix_put(img, j++, i, rectangle.color);
		++i;
	}
	return (MLX_SUCCESS);
}

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (MLX_ERROR);
	render_background(&data->img, WHITE_PIXEL);
	render_rectangle(&data->img, (t_rectangle){
		WINDOW_WIDTH - 100,
		WINDOW_HEIGHT - 100,
		100,
		100,
		GREEN_PIXEL
	});
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.mlx_img, 0, 0);
	return (MLX_SUCCESS);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	return (MLX_SUCCESS);
}

int	main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT, "fract'ol");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
