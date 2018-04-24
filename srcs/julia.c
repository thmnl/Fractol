/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 14:23:15 by tmanuel           #+#    #+#             */
/*   Updated: 2018/04/24 16:39:17 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_init_julia(t_libx *f)
{
	f->zoomm = 0.8 + f->zoom;
	f->imax = 20 + f->im;
	if (f->imax < 10)
		f->imax = 10;
	if (f->rar1 == 0 && f->rar2 == 0)
	{
		f->rar2 = -540;
		f->rar1 = 399;
	}
	f->cr = (4 * (float)f->rar1 / SCX - 2);
	f->ci = (4 * (float)f->rar2 / SCY + + 2);
}

static void	ft_loop_julia(t_libx *f)
{
	double or;

	or = 0;
	while ((f->zr * f->zr + f->zi * f->zi) < 4.0 && f->i < f->imax)
	{
		or = f->zr;
		f->zr = f->zr * f->zr - f->zi * f->zi + f->cr;
		f->zi = 2 * or * f->zi + f->ci;
		f->i++;
	}
}

static void	ft_init_loop(t_libx *f)
{
	int		y;
	int		x;

	x = 0;
	while (x < SCX)
	{
		y = 0;
		while (y < SCY)
		{
			f->zr = 4 * ((float)x - (f->ar1 * 2)) / SCX - 2;
			f->zi = -4 * ((float)y - (f->ar2 * 2)) / SCY + 2;
			f->i = 0;
			ft_loop_julia(f);
			if (f->i == f->imax)
				ft_putpixel(f, x, y, 0);
			else
				ft_putpixel(f, x, y, f->i * 255 / f->imax);
			y++;
		}
		x++;
	}
}

void		ft_julia(t_libx *f)
{
	ft_init_julia(f);
	ft_init_loop(f);
}
