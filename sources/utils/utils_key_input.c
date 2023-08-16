/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_key_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:27:52 by evportel          #+#    #+#             */
/*   Updated: 2023/08/16 09:18:24 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

int	utils_key_input(int key, t_fractol *fract)
{
	if (key == XK_Escape)
		utils_close_window(fract);
	return (MLX_SUCCESS);
}
