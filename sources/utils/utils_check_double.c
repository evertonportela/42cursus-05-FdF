/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check_double.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:27:23 by evportel          #+#    #+#             */
/*   Updated: 2023/08/16 10:54:26 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

int	utils_check_double(char *str)
{
	int	index;

	index = 0;
	while (str[index] == ' ')
		index++;
	if (str[index] == '-' || str[index] == '+')
		index++;
	while (str[index] >= '0' && str[index] <= '9')
		index++;
	if (str[index] == '.')
		index++;
	while (str[index] >= '0' && str[index] <= '9')
		index++;
	while (str[index] == ' ')
		index++;
	if (str[index] == '\0')
		return (MLX_SUCCESS);
	return (MLX_ERROR);
}
