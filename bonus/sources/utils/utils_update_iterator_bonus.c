/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_update_iterator_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:26:04 by evportel          #+#    #+#             */
/*   Updated: 2023/08/21 17:51:58 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol_bonus.h"

void	utils_update_iterator(int key, t_fractol *fract)
{
	if (key == 'e')
		fract->max_iterator += 10;
	if (key == 'q')
		fract->max_iterator -= 10;
}
