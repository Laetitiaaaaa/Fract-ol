/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 15:45:50 by llejeune          #+#    #+#             */
/*   Updated: 2019/03/13 13:32:02 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	ft_fill_pixel(t_first *m, int x, int y, int n)
{
	int		pixel;

	ft_color(n, m);
	pixel = 4 * (x + (m->width) * y);
	if (x < m->width && x >= 0 && y < m->height && y >= 0
			&& pixel < (4 * m->width * m->height) && pixel >= 0)
	{
		((unsigned char *)m->str)[pixel] = m->blue;
		((unsigned char *)m->str)[pixel + 1] = m->green;
		((unsigned char *)m->str)[pixel + 2] = m->red;
		((unsigned char *)m->str)[pixel + 3] = 0;
	}
}

void	ft_nb_color(t_first *m, unsigned char blue,
		unsigned char green, unsigned char red)
{
	m->blue = blue;
	m->green = green;
	m->red = red;
}

void	ft_color(int n, t_first *m)
{
	m->trans = 0;
	m->val = (n * 360 / m->nmax) + m->val1;
	if (m->val < 0)
		m->val = -m->val;
	while (m->val > 360)
		m->val = m->val - 360;
	if (m->val >= 0 && m->val <= 120)
		ft_nb_color(m, 0, m->val * 255 / 120, 255 - (m->val * 255 / 120));
	else if (m->val > 120 && m->val <= 240)
		ft_nb_color(m, (m->val - 120) * 255 / 120,
				255 - ((m->val - 120) * 255 / 120), 0);
	else
		ft_nb_color(m, 255 - ((m->val - 240) * 255 / 120),
				0, (m->val - 240) * 255 / 120);
}

void	ft_translation(t_first *m)
{
	if (m->trans == 1)
	{
		m->xmin++;
		m->xmax++;
	}
	if (m->trans == 2)
	{
		m->xmin--;
		m->xmax--;
	}
	if (m->trans == 3)
	{
		m->ymin++;
		m->ymax++;
	}
	if (m->trans == 4)
	{
		m->ymin--;
		m->ymax--;
	}
}

void	ft_zoom(t_first *m, float x, float y)
{
	m->trans = 0;
	if (m->a == 1)
	{
		m->xmin += (x - m->xmin) / 10;
		m->ymin += (y - m->ymin) / 10;
		m->xmax -= (m->xmax - x) / 10;
		m->ymax -= (m->ymax - y) / 10;
	}
	else if (m->a == -1)
	{
		m->xmin -= (x - m->xmin) / 10;
		m->ymin -= (y - m->ymin) / 10;
		m->xmax += (m->xmax - x) / 10;
		m->ymax += (m->ymax - y) / 10;
	}
	else if (m->a == 0)
	{
		m->xmin = m->xa;
		m->ymin = m->ya;
		m->xmax = m->xb;
		m->ymax = m->yb;
	}
}
