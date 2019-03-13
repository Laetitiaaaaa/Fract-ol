/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 15:49:50 by llejeune          #+#    #+#             */
/*   Updated: 2019/03/13 14:05:10 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int ac, char **av)
{
	t_first m;

	if (ac != 2)
		ft_putstr("usage: ./fractol <command>\n");
	else
	{
		(ft_init_mlx(&m) == 0) ? ft_free_exit(&m) : 0;
		(ft_strcmp(av[1], "mandelbrot") == 0) ? m.num = 1 : 0;
		(ft_strcmp(av[1], "julia") == 0) ? m.num = 2 : 0;
		(ft_strcmp(av[1], "burningship") == 0) ? m.num = 3 : 0;
		(ft_strcmp(av[1], "tricorn") == 0) ? m.num = 4 : 0;
		(ft_strcmp(av[1], "jerome") == 0) ? m.num = 5 : 0;
		(ft_strcmp(av[1], "lapinou") == 0) ? m.num = 6 : 0;
		(ft_strcmp(av[1], "illuminati") == 0) ? m.num = 7 : 0;
		(ft_strcmp(av[1], "sofiya") == 0) ? m.num = 8 : 0;
		ft_display(&m);
		mlx_hook(m.win_ptr, 2, 0, ft_key, &m);
		mlx_hook(m.win_ptr, 4, 0, ft_mouse_clic, &m);
		mlx_hook(m.win_ptr, 6, 0, ft_mouse_move, &m);
		mlx_loop(m.mlx_ptr);
	}
	return (0);
}
