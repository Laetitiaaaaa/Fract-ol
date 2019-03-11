/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 12:55:17 by llejeune          #+#    #+#             */
/*   Updated: 2019/03/11 10:53:54 by llejeune         ###   ########.fr       */
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
	m->val = n * 360 / m->nmax + m->val1;
	if (m->val < 0)
		m->val = -m->val;
	while (m->val > 360)
		m->val = m->val - 360;
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

void	ft_zoom(t_first *m, int x, int y)
{
	if (m->a == 1)
	{
		m->xmin += (x - m->xmin) / 10;
		m->ymin += (y - m->ymin) / 10;
		m->xmax -= (m->xmax - x) / 10;
		m->ymax -= (m->ymax - y) / 10;
		m->nmax += 10;
	}
	else if (m->a == -1)
	{
		m->xmin -= (x - m->xmin) / 10;
		m->ymin -= (y - m->ymin) / 10;
		m->xmax += (m->xmax - x) / 10;
		m->ymax += (m->ymax - y) / 10;
		m->nmax -= 10;
	}
	else if (m->a == 0)
	{
		m->xmin = m->xa;
		m->ymin = m->ya;
		m->xmax = m->xb;
		m->ymax = m->yb;
		m->nmax = m->na;
	}
}

void	ft_mandel(t_first *m)
{
	int		n;

	m->y = 0;
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

void	ft_tricorn(t_first *m)
{
	int		n;

	m->y = 0;
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

void	ft_sofia(t_first *m)
{
	int		n;

	m->y = 0;
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
	(key == CL) ? m->val1-- : 0;
	(key == CR) ? m->val1++ : 0;
	(key == M) ? m->num = 1 : 0;
	(key == J) ? m->num = 2 : 0;
	(key == B) ? m->num = 3 : 0;
 	(key == T) ? m->num = 4 : 0;
 	(key == S) ? m->num = 5 : 0;
	ft_display(m);
	return (0);
}

int		ft_mouse_clic(int button, int x, int y, t_first *m)
{
	if (button == 1 || button == 2)
	{
		if (m->num == 2 || m->num == 5)
		{
			m->movex = x / m->scalex + m->xmin;
			m->movey = y / m->scaley + m->ymin;
			m->clic = -m->clic;
		}
	}
	if (button == 3 || button == 4 || button == 5)
	{
		(button == 3) ? m->a = 0 : 0;
		(button == 5) ? m->a = 1 : 0;
		(button == 4) ? m->a = -1 : 0;
		m->b = 1;
	}
	m->clicx = x / m->scalex + m->xmin;
	m->clicy = y / m->scaley + m->ymin;
	ft_display(m);
	return (0);
}

int		ft_mouse_move(int x, int y, t_first *m)
{
	if ((m->num == 2 || m->num == 5) && m->clic == 1)
	{
		m->movex = x / m->scalex + m->xmin;
		m->movey = y / m->scaley + m->ymin;
		ft_display(m);
	}
	return (0);
}

void	ft_display(t_first *m)
{
	if (m->b == 1)
	{
		ft_zoom(m, m->clicx, m->clicy);
		m->b = 0;
	}
	(m->num == 1) ? ft_mandel(m) : 0;
	(m->num == 2) ? ft_julia(m) : 0;
	(m->num == 3) ? ft_burn(m) : 0;
	(m->num == 4) ? ft_tricorn(m) : 0;
	(m->num == 5) ? ft_sofia(m) : 0;
	mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->img_ptr, 0, 0);
}

void	ft_init(t_first *m)
{
	m->xa = -3;
	m->xb = 2;
	m->ya = -3;
	m->yb = 2;
	m->xmin = m->xa;
	m->xmax = m->xb;
	m->ymin = m->ya;
	m->ymax = m->yb;
	m->na = 100;
	m->nmax = m->na;
	m->width = 600;
	m->height = 450;
	m->movex = -0.4;
	m->movey = 0.6;
	m->val1 = 0;
	m->clic = 1;
	m->a = 0;
	m->b = 0;
}

int		main(int ac, char **av)
{
	t_first m;

	ac = 2;
	ft_init(&m);
	m.mlx_ptr = mlx_init();
	m.win_ptr = mlx_new_window(m.mlx_ptr, m.width, m.height, "Fract'ol");
	m.img_ptr = mlx_new_image(m.mlx_ptr, m.width, m.height);
	m.str = mlx_get_data_addr(m.img_ptr, &m.bpp, &m.s_l, &m.endian);
	(ft_strcmp(av[1], "-m") == 0) ? m.num = 1 : 0;
	(ft_strcmp(av[1], "-j") == 0) ? m.num = 2 : 0;
	(ft_strcmp(av[1], "-b") == 0) ? m.num = 3 : 0;
	(ft_strcmp(av[1], "-t") == 0) ? m.num = 4 : 0;
	(ft_strcmp(av[1], "-s") == 0) ? m.num = 5 : 0;
	ft_display(&m);
	mlx_hook(m.win_ptr, 2, 0, ft_key, &m);
	mlx_hook(m.win_ptr, 4, 0, ft_mouse_clic, &m);
	mlx_hook(m.win_ptr, 6, 0, ft_mouse_move, &m);
	mlx_loop(m.mlx_ptr);
	return (0);
}
