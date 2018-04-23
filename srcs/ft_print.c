/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 13:07:54 by tmanuel           #+#    #+#             */
/*   Updated: 2018/04/23 21:16:30 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
/*
définir x1 = -2.1
définir x2 = 0.6
définir y1 = -1.2
définir y2 = 1.2
définir f->zoom = 100 // pour une distance de 1 sur le plan, on a 100 pixel sur l'image
définir iteration_max = 50

définir image_x = (x2 - x1) * f->zoom
définir image_y = (y2 - y1) * f->zoom

Pour x = 0 tant que x < image_x par pas de 1 
 Pour y = 0 tant que y < image_y par pas de 1
  définir c_r = x / f->zoom + x1
  définir c_i = y / f->zoom + y1
  définir z_r = 0
  définir z_i = 0
  définir i = 0

  Faire
   définir tmp = z_r
   z_r = z_r*z_r - z_i*z_i + c_r
   z_i = 2*z_i*tmp + c_i
   i = i+1
  Tant que z_r*z_r + z_i*z_i < 4 et i < iteration_max

  si i = iteration_max
   dessiner en noir le pixel de coordonné (x; x)
  sinon
   dessiner avec couleur rgb(0, 0, i*255/iterations_max) le pixel de coordonné (x; x)
  finSi
 finPour
finPour
*/

void		ft_test(t_libx *f)
{
	f->x1 = -2.1;
	f->x2 = 0.6;
	f->y1 = -1.2;
	f->y2 = 1.2;
	f->zoom = 200;
	f->imax = 150;

	float 	ix;
	float 	iy;
	float	tmp;
	int		y;
	int		x;

	ix = (f->x2 - f->x1) * f->zoom;
	iy = (f->y2 - f->y1) * f->zoom;
	x = 0;
	while (x < ix)
	{
		y = 0;
		while (y < iy)
		{
			f->cr = x / f->zoom + f->x1;
			f->ci = y / f->zoom + f->y1;
			f->zr = 0;
			f->zi = 0;
			f->i = 0;
			while (f->zr * f->zr + f->zi * f->zi < 4 && f->i < f->imax)
			{
				tmp = f->zr;
				f->zr = f->zr * f->zr - f->zi * f->zi + f->cr;
				f->zi = 2 * tmp * f->zi + f->ci;
				f->i++;
			}
			if (f->i == f->imax)
				ft_putpixel(f, x, y, 0xffffff);
			printf("|%d|%d|\n", x, y);
			y++;
		}
		x++;
	}
}

void		ft_print(t_libx *f)
{
	f->image = mlx_new_image(f->mlx_ptr, SCX, SCY);
	f->pix = mlx_get_data_addr(f->image, &f->bbp, &f->s_l, &f->endian);
	ft_test(f);
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->image, 0, 0);
	mlx_destroy_image(f->mlx_ptr, f->image);
}
