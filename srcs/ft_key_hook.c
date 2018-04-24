/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 13:13:14 by tmanuel           #+#    #+#             */
/*   Updated: 2018/04/24 16:34:14 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int			ft_key_hook2(int key, t_libx *f)
{
	if (key == 69)
		f->im += 10;
	if (key == 78)
		f->im -= 10;
	if (key == 126)
		f->ar2 -= 0.1 / (f->zoom + 0.1);
	if (key == 125)
		f->ar2 += 0.1 / (f->zoom + 0.1);
	if (key == 124)
		f->ar1 += 0.1 / (f->zoom + 0.1);
	if (key == 123)
		f->ar1 -= 0.1 / (f->zoom + 0.1);
	if (key == 15)
	{
		f->ar1 = 0;
		f->ar2 = 0;
		f->zoom = 0;
		f->im = 0;
	}
	if ((key >= 123 && key <= 126) || key == 15 || key == 69 || key == 78)
		ft_print(f);
	return (0);
}

int			ft_key_hook(int key, t_libx *f)
{
	ft_putnbr(key);
	ft_putchar('\n');
	if (key == 53)
		exit(0);
	if (key == 49 && !f->djoo)
		f->djoo = 1;
	else if (key == 49)
		f->djoo = 0;
	return (ft_key_hook2(key, f));
}

int			ft_mouse_hook2(int key, int x, int y, t_libx *f)
{
	static int i;

	(void)x;
	(void)y;
	if (key == 5)
		i++;
	if (key == 4)
		i--;
	if (i < 0)
		i = 0;
	if (key == 4 || key == 5)
	{
		if (i < 50)
			f->zoom = i * i * i;
		else if (i < 100)
			f->zoom = (i * i * i) * 2;
		else
			f->zoom = (i * i * i) * 4;
		ft_print(f);
	}
	return (0);
}

int			ft_mouse_hook(int key, int x, int y, t_libx *f)
{
	ft_mouse_hook2(key, x, y, f);
	return (0);
}

int			ft_hook(int x, int y, t_libx *f)
{
	if (f->djoo == 0 && f->frct == 2)
	{
		f->rar1 = x * 6;
		f->rar2 = y * 6;
		ft_print(f);
	}
	return (0);
}
