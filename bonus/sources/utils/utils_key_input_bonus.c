/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_key_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:27:52 by evportel          #+#    #+#             */
/*   Updated: 2023/08/21 17:48:20 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol_bonus.h"

int	utils_key_input(int key, t_fractol *fract)
{
	if (key == XK_Escape)
		utils_close_window(fract);
	else if (key == 'q' || key == 'e')
		utils_update_iterator(key, fract);
	else if (key == '-' || key == '=')
		utils_keyboard_zoom(key, fract);
	return (MLX_SUCCESS);
}
