/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractales_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 15:51:43 by llejeune          #+#    #+#             */
/*   Updated: 2019/03/13 14:04:46 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_julia(t_first *m)
{
	int		n;

	m->y = 0;
	while (m->y < m->height)
	{
		m->x = 0;
		while (m->x < m->width)
		{
			ft_init_move(m);
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

void	ft_sofiya(t_first *m)
{
	int		n;

	m->y = 0;
	while (m->y < m->height)
	{
		m->x = 0;
		while (m->x < m->width)
		{
			ft_init_move(m);
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

void	ft_jerome(t_first *m)
{
	int		n;

	m->y = 0;
	while (m->y < m->height)
	{
		m->x = 0;
		while (m->x < m->width)
		{
			ft_init_move(m);
			n = 0;
			while ((m->zr * m->zr + m->zi * m->zi) < 4 && n < m->nmax)
			{
				m->tmp = log((m->zr * m->zr - m->zi * m->zi + m->cr) * 1.5);
				m->zi = ((2 * m->zr * m->zi) + m->ci);
				m->zr = (m->tmp);
				n++;
			}
			ft_fill_pixel(m, m->x, m->y, n);
			m->x++;
		}
		m->y++;
	}
}

void	ft_lapinou(t_first *m)
{
	int		n;

	m->y = 0;
	while (m->y < m->height)
	{
		m->x = 0;
		while (m->x < m->width)
		{
			ft_init_move(m);
			n = 0;
			while ((m->zr * m->zr + m->zi * m->zi) < 4 && n < m->nmax)
			{
				m->tmp = (-sin(((m->zr * m->zr - m->zi * m->zi + m->cr) * 1.5)
							* 360 / 180)) * log(m->cr);
				m->zi = ((2 * m->zr * m->zi) + m->ci);
				m->zr = (m->tmp);
				n++;
			}
			ft_fill_pixel(m, m->x, m->y, n);
			m->x++;
		}
		m->y++;
	}
}

void	ft_illuminati(t_first *m)
{
	int		n;

	m->y = 0;
	while (m->y < m->height)
	{
		m->x = 0;
		while (m->x < m->width)
		{
			ft_init_move(m);
			m->zr = ((m->x / m->scalex + m->xmin) * (m->x / m->scalex +
						m->xmin));
			n = 0;
			while ((m->zr * m->zr + m->zi * m->zi) < 4 && n < m->nmax)
			{
				m->tmp = sin(sqrt(m->zr * m->zr - m->zi * m->zi + m->cr)
						* 360 / 180);
				m->zi = ((2 * m->zr * m->zi) + m->ci);
				m->zr = (m->tmp);
				n++;
			}
			ft_fill_pixel(m, m->x, m->y, n);
			m->x++;
		}
		m->y++;
	}
}
