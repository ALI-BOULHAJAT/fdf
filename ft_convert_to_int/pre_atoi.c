/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:35:19 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/01/16 19:21:04 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

char	*pre_atoi(char *s)
{
	char	*num;
	int		i;

	i = 0;
	while (s[i] != ',')
		i++;
	num = malloc(i + 1);
	i = 0;
	while (s[i] != ',')
	{
		num[i] = s[i];
		i++;
	}
	num[i] = '\0';
	return (num);
}