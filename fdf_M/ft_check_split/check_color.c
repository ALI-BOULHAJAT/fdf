/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 20:34:16 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/02/22 11:18:39 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	check_color(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ',')
		{
			if (s[i + 1] == '0' && (s[i + 2] == 'x' || s[i + 2] == 'X'))
				return (1);
			else if (s[i + 1] >= '0' && s[i + 1] <= '9')
				return (2);
			else
				return (3);
		}
		i++;
	}
	return (0);
}
