/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:56:36 by evportel          #+#    #+#             */
/*   Updated: 2023/08/03 19:10:11 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 1000

# define MLX_ERROR 1
# define MLX_SUCCESS 0

/**
 * @brief MLX image structure T_IMG
 * 
 * @param mlx_img se refere ao endereço que mlx_new_image retorna;
 * @param img_addr o endereço da imagem;
 * @param bits_pixel os bits por pixel da imagem;
 * @param line_length o tamanho de uma linha da imagem;
 * @param endian a parte mais importante da imagem;
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
 * @brief Estrutura do fractal que será desenhado na tela T_FRACTOL
 * 
 * @param mlx_ptr Um ponteiro para a instância gráfica da MiniLibX
	* @param win_ptr Um ponteiro para a janela criada pela biblioteca MiniLibx, 
 * para interagir com a janela e atualizar seu conteúdo.
	* @param max_iterator Um valor inteiro que representa o número máximo de 
 * iterações para o calculo de um fractal
	* @param fractol Uma variável inteira para indicar qual tipo de fractal será 
 * desenhado.
 * @param color Representa a cor utilizada no desenho do fractal
	* @param x0 Valor que representa a coordenada X inicial do plano onde o fractal 
 * será desenhado.
	* @param y0 Valor que representa a coordenada Y inicial do plano onde o fractal 
 * será desenhado.
	* @param min_real Definem o intervalo do plano que será mapeado para a janela. 
 * Determinam o tamanho e a área de visualização do fractal.
	* @param max_real Definem o intervalo do plano que será mapeado para a janela. 
 * Determinam o tamanho e a área de visualização do fractal.
	* @param min_imaginary Definem o intervalo do plano que será mapeado para a 
 * janela. Determinam o tamanho e a área de visualização do fractal.
	* @param max_imaginary Definem o intervalo do plano que será mapeado para a 
 * janela. Determinam o tamanho e a área de visualização do fractal.
 * @param args Indica a quantidade de argumentos passados ao programa
	* @param arg_real Valores que representam argumentos relacionados ao parametro 
 * do fractal
	* @param arg_imaginary Valores que representam argumentos relacionados ao 
 * parametro do fractal
	* @param image Estrutura usada para armazenar o desenho do fractal antes de ser 
 * exibido na janela gráfica.
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

#endif