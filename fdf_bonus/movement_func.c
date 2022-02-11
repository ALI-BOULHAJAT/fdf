/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:57:34 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/02/11 08:34:50 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_mouvment(int key, t_fdf *m_size)
{
	if (key == 126)
		m_size->key_j -= 10;
	if (key == 125)
		m_size->key_j += 10;
	if (key == 124)
		m_size->key_i += 10;
	if (key == 123)
		m_size->key_i -= 10;
	// if (m_size->key_mo == 1 && m_size->key_lac != 1)
	// 	m_size->key_i += m_size->how_much;
	// printf("%f\n", m_size->key_i);
}

void	ft_retation_x_y(int key, t_fdf *m_size)
{
	if (key == 88)
	{
		m_size->key = 88;
		m_size->alpha += 0.1;
	}
	if (key == 86)
	{
		m_size->key = 86;
		m_size->alpha -= 0.1;
	}
	if (key == 91)
	{
		m_size->key = 91;
		m_size->alpha += 0.1;
	}
	if (key == 84)
	{
		m_size->key = 84;
		m_size->alpha -= 0.1;
	}
}

void	ft_retation_z(int key, t_fdf *m_size)
{
	if (key == 6)
	{
		m_size->key = 6;
		m_size->alpha += 0.1;
	}
	if (key == 7)
	{
		m_size->key = 7;
		m_size->alpha -= 0.1;
	}
}

void	ft_ckeck_key(int key, t_fdf *m_size)
{
	// if (key >= 123 && key <= 126)
	// 	ft_mouvment(key, m_size);
	if (m_size->key_mo == 1 && m_size->key_lac != 1)
		ft_mouvment(key, m_size);
	if (key == 53)
	{
		mlx_destroy_window(m_size->mlx_ptr, m_size->win_ptr);
		exit(0);
	}
	if (key >= 84 && key <= 91)
		ft_retation_x_y(key, m_size);
	if (key == 6 || key == 7)
		ft_retation_z(key, m_size);
	if (key == 69)
		m_size->z_zoom += 2;
	if (key == 78)
		m_size->z_zoom -= 2;
}

int	ft_movekey(int key, t_fdf *m)
{
	ft_ckeck_key(key, m);
	mlx_clear_window(m->mlx_ptr, m->win_ptr);
	mlx_destroy_image(m->mlx_ptr, m->image);
	m->image = mlx_new_image(m->mlx_ptr, m->lenght, m->hieght);
	m->addr = mlx_get_data_addr(m->image, &m->bit_img, &m->d_size, &m->endian);
	draw(m);
	mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->image, 0, 0);
	return (0);
}

