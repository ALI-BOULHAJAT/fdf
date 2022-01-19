/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:08:26 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/01/19 18:55:13 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

#define MAX_VAL(a, b) (a > b ? a : b)
#define POSIT(a) (a > 0 ? a : -a)

void    ft_bresenham(t_fdf *m_size, float i, float j, float i1, float j1)
{
    float di;
    float dj;
    int Val;
    int z;
    int z1;
    
    z = m_size->map[(int) j][(int) i].z;
    z1 = m_size->map[(int) j1][(int) i1].z;
    //zoom
    i *= m_size->zoom;
    j *= m_size->zoom;
    i1 *= m_size->zoom;
    j1 *= m_size->zoom;
    
    m_size->color = (z) ? 0xe80c0c : 0xffffff; 
    di = i1 - i;
    dj = j1 - j;

    Val = MAX_VAL(POSIT(di), POSIT(dj));
    
    di /= Val;
    dj /= Val;

    while ((int)(i - i1) || (int)(j - j1))
    {
        mlx_pixel_put(m_size->mlx_ptr, m_size->win_ptr, i, j, m_size->color);
        i += di;
        j += dj;
    }
}

void    draw(t_fdf  *m_size)
{
    //int i;
    //int j;
    
    m_size->i = 0;
    while (m_size->i < m_size->column_num)
    {
        m_size->j = 0;
        while (m_size->j < m_size->line_num - 1)
        {
            if (m_size->j < m_size->line_num)
                ft_bresenham(m_size, m_size->i, m_size->j, m_size->i + 1, m_size->j);
            if (m_size->i < m_size->column_num)
                 //ft_bresenham(m_size, m_size->i, m_size->j, m_size->i, m_size->j + 1);
            m_size->j++;
        }
        m_size->i++;
    }
}