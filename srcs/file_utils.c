/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 15:53:20 by llejeune          #+#    #+#             */
/*   Updated: 2019/03/13 11:10:30 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		ft_key(int key, t_first *m)
{
	(key == ESC) ? ft_free_exit(m) : 0;
	(key == CL) ? m->val1-- : 0;
	(key == CR) ? m->val1++ : 0;
	(key == M) ? m->num = 1 : 0;
	(key == J) ? m->num = 2 : 0;
	(key == B) ? m->num = 3 : 0;
	(key == T) ? m->num = 4 : 0;
	(key == D) ? m->num = 5 : 0;
	(key == L) ? m->num = 6 : 0;
	(key == I) ? m->num = 7 : 0;
	(key == S) ? m->num = 8 : 0;
	(key == LEFT) ? m->trans = 1 : 0;
	(key == RIGHT) ? m->trans = 2 : 0;
	(key == UP) ? m->trans = 3 : 0;
	(key == DOWN) ? m->trans = 4 : 0;
	ft_display(m);
	return (0);
}

int		ft_mouse_clic(int button, int x, int y, t_first *m)
{
	if (button == 1 || button == 2)
	{
		if (m->num == 2 || m->num == 5 || m->num == 6 || m->num == 7
				|| m->num == 8)
		{
			m->clic = -m->clic;
			m->clicx = x / m->scalex + m->xmin;
			m->clicy = y / m->scaley + m->ymin;
		}
	}
	if (button == 3 || button == 4 || button == 5)
	{
		(button == 3) ? m->a = 0 : 0;
		(button == 5) ? m->a = 1 : 0;
		(button == 4) ? m->a = -1 : 0;
		m->b = 1;
	}
	m->movex = m->clicx;
	m->movey = m->clicy;
	ft_display(m);
	return (0);
}

int		ft_mouse_move(int x, int y, t_first *m)
{
	if ((m->num == 2 || m->num == 5 || m->num == 6 || m->num == 7
				|| m->num == 8) && m->clic == 1)
	{
		m->movex = x / m->scalex + m->xmin;
		m->movey = y / m->scaley + m->ymin;
		ft_display(m);
	}
	return (0);
}

void	ft_display(t_first *m)
{
	ft_translation(m);
	if (m->b == 1)
	{
		ft_zoom(m, m->clicx, m->clicy);
		m->b = 0;
	}
	(m->num == 1) ? ft_mandel(m) : 0;
	(m->num == 2) ? ft_julia(m) : 0;
	(m->num == 3) ? ft_burn(m) : 0;
	(m->num == 4) ? ft_tricorn(m) : 0;
	(m->num == 5) ? ft_jerome(m) : 0;
	(m->num == 6) ? ft_lapinou(m) : 0;
	(m->num == 7) ? ft_illuminati(m) : 0;
	(m->num == 8) ? ft_sofiya(m) : 0;
	if (m->num == 0)
	{
		ft_putstr("usage: ./fractol <command>\n");
		ft_free_exit(m);
	}
	mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->img_ptr, 0, 0);
}
