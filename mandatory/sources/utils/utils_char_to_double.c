/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_char_to_double.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:17:19 by evportel          #+#    #+#             */
/*   Updated: 2023/08/16 09:17:56 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

double	utils_char_to_double(char *str)
{
	int		signal;
	int		index;
	double	result;
	double	power;

	signal = 1;
	index = 0;
	result = 0;
	power = 1;
	while ((str[index] >= 9 && str[index] <= 13) || str[index] == ' ')
		index++;
	if (str[index] == '-' || str[index] == '+')
		if (str[index++] == '-')
			signal *= -1;
	while (str[index] >= '0' && str[index] <= '9')
		result = result * 10 + str[index++] - '0';
	if (str[index] == '.')
		index++;
	while (str[index] >= '0' && str[index] <= '9')
	{
		result = result * 10 + str[index++] - '0';
		power *= 10;
	}
	result = signal * result / power;
	return (result);
}
