/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_julia.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:44:38 by evportel          #+#    #+#             */
/*   Updated: 2023/08/11 11:47:05 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	fct_init_julia(t_fractol *fract)
{
	fract->max_real = 1.0;
	fract->min_real = -2.2;
	fract->max_imaginary = (fract->max_real - fract->min_real) * WIN_HEIGHT / WIN_WIDTH + fract->min_imaginary;
	fract->min_imaginary = -1.5;
	fract->max_iterator = 100;
	fract->color = 265;
}
