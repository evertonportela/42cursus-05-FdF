/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_char_to_double.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:17:19 by evportel          #+#    #+#             */
/*   Updated: 2023/08/12 18:05:36 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

double	utils_char_to_double(char *str)
{
	int		signal;
	int		index;
	double	result;

	index = 0;
	signal = 1;
	while ((str[index] >= 9 && str[index] <= 13) || str[index] == ' ')
		index++;
	if (str[index] == '-' || str[index] == '+')
		if (str[index++] == '-')
			signal *= -1;
	while (str[index] >= '0' && str[index] <= '9')
		result = result * 10 + str[index++] - '0';
}
