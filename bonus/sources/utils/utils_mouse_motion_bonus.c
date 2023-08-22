/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mouse_motion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:09:45 by evportel          #+#    #+#             */
/*   Updated: 2023/08/22 12:18:03 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol_bonus.h"

int	utils_mouse_motion(int x, int y, t_fractol *fract)
{
	if (fract->fractol == 2 && fract->args == 0)
	{
		fract->arg_real = fct_map_real(x, fract);
		fract->arg_imaginary = fct_map_imaginary(y, fract);
	}
	return (MLX_SUCCESS);
}
