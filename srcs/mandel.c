/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 18:06:30 by tmanuel           #+#    #+#             */
/*   Updated: 2018/04/26 19:23:17 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_init_mandel(t_libx *f)
{
	f->x1 = -0.5 + f->ar1;
	f->y1 = 0.0 + f->ar2;
	f->zoomm = 0.1 + f->zoom;
	f->imax = 20 + f->im;
	if (f->imax < 10)
		f->imax = 10;
}

static void	ft_loop_mandel(t_libx *f)
{
	double or;
	double oi;

	or = 0;
	oi = 0;
	while ((f->zr * f->zr + f->zi * f->zi) < 4.0 && f->i < f->imax)
	{
		or = f->zr;
		oi = f->zi;
		f->zr = f->zr * f->zr - f->zi * f->zi + f->cr;
		f->zi = 2 * or * oi + f->ci;
		f->i++;
	}
}

static void	ft_init_loop(t_libx *f)
{
	int		y;
	int		x;

	y = 0;
	while (y < SCY)
	{
		x = 0;
		f->ci = (y - SCY / 2.0) / (0.5 * f->zoomm * SCY) + f->y1;
		while (x < SCX)
		{
			f->cr = 1.5 * (x - SCX / 2.0) / (0.5 * f->zoomm * SCX) + f->x1;
			f->zr = 0;
			f->zi = 0;
			f->i = 0;
			ft_loop_mandel(f);
			if (f->i == f->imax)
				ft_putpixel(f, x, y, f->colorb);
			else
				ft_putpixel(f, x, y, f->color[f->i % 5]);
			x++;
		}
		y++;
	}
}

void		ft_mandel(t_libx *f)
{
	ft_init_mandel(f);
	ft_init_loop(f);
}
