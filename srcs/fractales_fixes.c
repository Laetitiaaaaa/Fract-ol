/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractales_fixes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 15:40:34 by llejeune          #+#    #+#             */
/*   Updated: 2019/03/13 14:04:35 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mandel(t_first *m)
{
	int		n;

	m->y = 0;
	while (m->y < m->height)
	{
		m->x = 0;
		while (m->x < m->width)
		{
			ft_init_fixe(m);
			n = 0;
			while ((m->zr * m->zr + m->zi * m->zi) < 4 && n < m->nmax)
			{
				m->tmp = m->zr;
				m->zr = m->zr * m->zr - m->zi * m->zi + m->cr;
				m->zi = 2 * m->zi * m->tmp + m->ci;
				n++;
			}
			ft_fill_pixel(m, m->x, m->y, n);
			m->x++;
		}
		m->y++;
	}
}

void	ft_tricorn(t_first *m)
{
	int		n;

	m->y = 0;
	while (m->y < m->height)
	{
		m->x = 0;
		while (m->x < m->width)
		{
			ft_init_fixe(m);
			n = 0;
			while ((m->zr * m->zr + m->zi * m->zi) < 4 && n < m->nmax)
			{
				m->tmp = m->zr;
				m->zr = m->zr * m->zr - m->zi * m->zi + m->cr;
				m->zi = -2 * m->zi * m->tmp + m->ci;
				n++;
			}
			ft_fill_pixel(m, m->x, m->y, n);
			m->x++;
		}
		m->y++;
	}
}

void	ft_burn(t_first *m)
{
	int		n;

	m->y = 0;
	while (m->y < m->height)
	{
		m->x = 0;
		while (m->x < m->width)
		{
			ft_init_fixe(m);
			n = 0;
			while ((m->zr * m->zr + m->zi * m->zi) < 4 && n < m->nmax)
			{
				m->tmp = m->zr * m->zr - m->zi * m->zi + m->cr;
				m->zi = fabsf(2 * m->zr * m->zi) + m->ci;
				m->zr = fabsf(m->tmp);
				n++;
			}
			ft_fill_pixel(m, m->x, m->y, n);
			m->x++;
		}
		m->y++;
	}
}
