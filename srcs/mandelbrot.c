/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 12:55:17 by llejeune          #+#    #+#             */
/*   Updated: 2019/03/08 20:40:27 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_fill_pixel(t_first *m, int x, int y, int n)
{
	int		pixel;

	ft_color(n, m);
	pixel = 4 * (x + (m->width) * y);
	if (x < m->width && x >= 0 && y < m->height && y >= 0 && pixel < (4 * m->width * m->height) && pixel >= 0)
	{
		((unsigned char *)m->str)[pixel] = m->blue;
		((unsigned char *)m->str)[pixel + 1] = m->green;
		((unsigned char *)m->str)[pixel + 2] = m->red;
		((unsigned char *)m->str)[pixel + 3] = 0;
	}
}

void	ft_nb_color(t_first *m, int blue, int green, int red)
{
	m->blue = blue;
	m->green = green;
	m->red = red;
}

void	ft_color(int n, t_first *m)
{
	m->val = n * 360 / m->nmax;
	if (m->val >= 0 && m->val <= 120)
		ft_nb_color(m, 0, m->val * 255 / 100, 255 - m->green);
	if (m->val > 120 && m->val <= 240)
		ft_nb_color(m, (m->val - 120) * 255 / 120, 255 - m->blue, 0);
	if (m->val > 240 && m->val < 360)
		ft_nb_color(m, 255 - ((m->val - 240) * 255 / 120), 0, (m->val - 240) * 255 / 120);
	if (m->val == 360)
	{
		m->blue = 0;
		m->green = 0;
		m->red = 0;
	}
}

void	ft_mandel(t_first *m)
{
	int		n;

	m->nmax = 50;
	m->y = 0;
	m->xmin = -2.1;
	m->xmax = 0.6;
	m->ymin = -1.2;
	m->ymax = 1.2;
	m->scalex = m->width / (m->xmax - m->xmin);
	m->scaley = m->height / (m->ymax - m->ymin);
	while (m->y < m->height)
	{
		m->x = 0;
		while (m->x < m->width)
		{
			m->cr = m->x / m->scalex + m->xmin;
			m->ci = m->y / m->scaley + m->ymin;
			m->zr = 0;
			m->zi = 0;
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

void	ft_julia(t_first *m)
{
	int		n;

	m->y = 0;
	m->nmax = 200;
	m->xmin = -1.6;
	m->xmax = 1.6;
	m->ymin = -1.2;
	m->ymax = 1.2;
	m->scalex = m->width / (m->xmax - m->xmin);
	m->scaley = m->height / (m->ymax - m->ymin);
	while (m->y < m->height)
	{
		m->x = 0;
		while (m->x < m->width)
		{
			m->cr = m->movex;
			m->ci = m->movey;
			m->zr = m->x / m->scalex + m->xmin;
			m->zi = m->y / m->scaley + m->ymin;
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

void	ft_burn(t_first *m)
{
	int		n;

	m->y = 0;
	m->nmax = 100;
	m->xmin = -3;
	m->xmax = 2;
	m->ymin = -3;
	m->ymax = 2;
	m->scalex = m->width / (m->xmax - m->xmin);
	m->scaley = m->height / (m->ymax - m->ymin);
	while (m->y < m->height)
	{
		m->x = 0;
		while (m->x < m->width)
		{
			m->cr = m->x / m->scalex + m->xmin;
			m->ci = m->y / m->scaley + m->ymin;
			m->zr = 0;
			m->zi = 0;
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

int		ft_key(int key, t_first *m)
{
	(key == ESC) ? exit(0) : 0;
	printf("key = %d\n", key);
	(void)m;
	return (0);
}

int		ft_mouse_clic(int button, int x, int y, t_first *m)
{
	(void)button;
	(void)m;
	(void)x;
	(void)y;
	return (0);
}

int		ft_mouse_move(int x, int y, t_first *m)
{
	m->movex = x / m->scalex + m->xmin;
	m->movey = y / m->scaley + m->ymin;
	ft_julia(m);
	mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->img_ptr, 0, 0);
	return (0);
}

int		main(int ac, char **av)
{
	t_first m;

	ac = 2;
	m.width = 400;
	m.height = 300;
	m.movex = -0.4;
	m.movey = 0.6;
	m.mlx_ptr = mlx_init();
	m.win_ptr = mlx_new_window(m.mlx_ptr, m.width, m.height, "Fract'ol");
	m.img_ptr = mlx_new_image(m.mlx_ptr, m.width, m.height);
	m.str = mlx_get_data_addr(m.img_ptr, &m.bpp, &m.s_l, &m.endian);
	if (ft_strcmp(av[1], "-m") == 0)
		ft_mandel(&m);
	if (ft_strcmp(av[1], "-j") == 0)
		ft_julia(&m);
	if (ft_strcmp(av[1], "-b") == 0)
		ft_burn(&m);
	mlx_put_image_to_window(m.mlx_ptr, m.win_ptr, m.img_ptr, 0, 0);
	mlx_hook(m.win_ptr, 2, 0, ft_key, &m);
	mlx_hook(m.win_ptr, 4, 0, ft_mouse_clic, &m);
	mlx_hook(m.win_ptr, 6, 0, ft_mouse_move, &m);
	mlx_loop(m.mlx_ptr);
	return (0);
}
