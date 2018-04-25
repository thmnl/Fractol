/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 13:13:14 by tmanuel           #+#    #+#             */
/*   Updated: 2018/04/25 16:27:54 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int			ft_key_hook(int key, t_libx *f)
{
	ft_putnbr(key);
	ft_putchar('\n');
	if (key == 53)
	{
		free(f);
		exit(0);
	}
	if (key == 16)
	{
		if (f->psy == 1)
			f->psy = 0;
		else
			f->psy = 1;
	}
	if (key == 49 && !f->djoo)
		f->djoo = 1;
	else if (key == 49)
		f->djoo = 0;
	return (0);
}

int			ft_mouse_hook2(int key, t_libx *f)
{
	static int i;

	if (key == 5)
	{
		f->zoom += 1;
		i++;
	}
	if (key == 4)
	{
		f->zoom -= 1;
		i--;
	}
	if (i < 0)
		i = 0;
	if (f->frct != 2)
	{
		if (i < 50)
			f->zoom = i * i * i;
		else if (i < 100)
			f->zoom = (i * i * i) * 2;
		else
			f->zoom = (i * i * i) * 4;
	}
	ft_print(f);
	return (0);
}

int			ft_mouse_hook(int key, int x, int y, t_libx *f)
{
	(void)x;
	(void)y;
	if (key == 4 || key == 5)
		ft_mouse_hook2(key, f);
	return (0);
}

int			ft_hook(int x, int y, t_libx *f)
{
	if (f->djoo == 0 && f->frct == 2)
	{
		f->rar1 = 2.0 * x / SCX - 1;
		f->rar2 = 2.0 * y / SCY - 1;
		ft_print(f);
	}
	return (0);
}
