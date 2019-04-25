/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 17:19:57 by llejeune          #+#    #+#             */
/*   Updated: 2019/03/28 21:01:03 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	m->val1 = 283;
	m->clic = 1;
	m->a = 0;
	m->b = 0;
	m->trans = 0;
	m->num = 0;
}

int		ft_init_mlx(t_first *m)
{
	ft_init(m);
	m->mlx_ptr = NULL;
	m->win_ptr = NULL;
	m->img_ptr = NULL;
	m->str = NULL;
	if (!(m->mlx_ptr = mlx_init()))
		return (0);
	if (!(m->win_ptr = mlx_new_window(m->mlx_ptr, m->width, m->height,
					"Fract'ol")))
		return (0);
	if (!(m->img_ptr = mlx_new_image(m->mlx_ptr, m->width, m->height)))
		return (0);
	if (!(m->str = mlx_get_data_addr(m->img_ptr, &m->bpp, &m->s_l, &m->endian)))
		return (0);
	return (1);
}

void	ft_init_move(t_first *m)
{
	m->scalex = m->width / (m->xmax - m->xmin);
	m->scaley = m->height / (m->ymax - m->ymin);
	m->cr = m->movex;
	m->ci = m->movey;
	m->zi = m->y / m->scaley + m->ymin;
	if (m->num != 7)
		m->zr = m->x / m->scalex + m->xmin;
}

void	ft_init_fixe(t_first *m)
{
	m->scalex = m->width / (m->xmax - m->xmin);
	m->scaley = m->height / (m->ymax - m->ymin);
	m->cr = m->x / m->scalex + m->xmin;
	m->ci = m->y / m->scaley + m->ymin;
	m->zr = 0;
	m->zi = 0;
}

void	ft_free_exit(t_first *m)
{
	mlx_destroy_image(m->mlx_ptr, m->img_ptr);
	mlx_destroy_window(m->mlx_ptr, m->win_ptr);
	exit(0);
}
