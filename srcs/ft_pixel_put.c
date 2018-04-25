/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 02:28:19 by tmanuel           #+#    #+#             */
/*   Updated: 2018/04/25 13:29:02 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_putpixel(t_libx *f, int x, int y, int color)
{
	int		pos;
	int8_t	mask;

	if ((x >= 0 && x <= SCX - 1) && (y >= 0 && y <= SCY - 1))
	{
		pos = (y * f->s_l + x * 4);
		mask = color;
		f->pix[pos] = mask;
		color = color >> 8;
		mask = color;
		f->pix[pos + 1] = mask;
		color = color >> 8;
		mask = color;
		f->pix[pos + 2] = mask;
		f->pix[pos + 3] = 0x00;
	}
}
