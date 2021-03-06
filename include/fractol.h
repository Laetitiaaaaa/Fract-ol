/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 10:08:51 by llejeune          #+#    #+#             */
/*   Updated: 2019/03/13 12:49:18 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define ESC 53
# define PLUS 69
# define MINUS 78
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define M 46
# define J 38
# define B 11
# define T 17
# define S 1
# define D 2
# define L 37
# define I 34
# define CL 33
# define CR 30

# include <mlx.h>
# include <math.h>
# include "../libft/libft.h"

typedef struct		s_first
{
	int				width;
	int				height;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				bpp;
	int				s_l;
	int				endian;
	char			*str;
	unsigned char	blue;
	unsigned char	green;
	unsigned char	red;
	int				val;
	float			x;
	float			y;
	float			xmin;
	float			xmax;
	float			ymin;
	float			ymax;
	float			nmax;
	float			zr;
	float			zi;
	float			cr;
	float			ci;
	float			tmp;
	float			scalex;
	float			scaley;
	float			movex;
	float			movey;
	int				val1;
	float			clicx;
	float			clicy;
	int				num;
	float			xa;
	float			ya;
	float			xb;
	float			yb;
	int				na;
	int				clic;
	int				a;
	int				b;
	int				trans;
}					t_first;

void				ft_fill_pixel(t_first *m, int x, int y, int n);
void				ft_nb_color(t_first *m, unsigned char blue,
		unsigned char green, unsigned char red);
void				ft_color(int n, t_first *m);
void				ft_mandel(t_first *m);
void				ft_julia(t_first *m);
void				ft_burn(t_first *m);
int					ft_key(int key, t_first *m);
int					ft_mouse_clic(int button, int x, int y, t_first *m);
int					ft_mouse_move(int x, int y, t_first *m);
void				ft_display(t_first *m);
void				ft_tricorn(t_first *m);
void				ft_jerome(t_first *m);
void				ft_zoom(t_first *m, float x, float y);
void				ft_lapinou(t_first *m);
void				ft_illuminati(t_first *m);
void				ft_sofiya(t_first *m);
void				ft_translation(t_first *m);
int					ft_init_mlx(t_first *m);
void				ft_init_move(t_first *m);
void				ft_init_fixe(t_first *m);
void				ft_free_exit(t_first *m);

#endif
