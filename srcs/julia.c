/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 14:23:15 by tmanuel           #+#    #+#             */
/*   Updated: 2018/04/26 19:23:08 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_init_julia(t_libx *f)
{
	f->zoomm = f->zoom + 0.1;
	f->cr = -1.0 / f->zoomm + f->ar1;
	f->ci = 1.0 / f->zoomm + f->ar1;
	f->cd = -1.0 / f->zoomm + f->ar2;
	f->ce = 1.0 / f->zoomm + f->ar2;
	f->imax = 20 + f->im;
	if (f->imax < 10)
		f->imax = 10;
}

static void	ft_loop_julia(t_libx *f)
{
	double or;

	or = 0;
	while ((f->zr * f->zr + f->zi * f->zi) < 4.0 && f->i < f->imax)
	{
		or = f->zr;
		f->zr = f->zr * f->zr - f->zi * f->zi + f->rar1;
		f->zi = 2 * or * f->zi + f->rar2;
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
			f->zr = f->cr + (((double)x + (f->ar1 * 100)) / SCX)
				* (f->ci - f->cr);
			f->zi = f->cd + (((double)y + (f->ar2 * 100)) / SCY)
				* (f->ce - f->cd);
			f->i = 0;
			ft_loop_julia(f);
			if (f->i == f->imax)
				ft_putpixel(f, x, y, f->colorb);
			else
				ft_putpixel(f, x, y, f->color[f->i % 5]);
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
