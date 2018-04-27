/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 13:13:14 by tmanuel           #+#    #+#             */
/*   Updated: 2018/04/26 19:25:06 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_key_hook2(int key, t_libx *f)
{
	if (key == 11)
	{
		ft_color4(f);
		ft_print(f);
	}
	return (0);
}

int			ft_key_hook(int key, t_libx *f)
{
	if (key == 8)
		ft_color1(f);
	if (key == 9)
		ft_color3(f);
	if (key == 0)
		ft_color2(f);
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
	if (key == 8 || key == 9 || key == 0)
		ft_print(f);
	return (ft_key_hook2(key, f));
}

int			ft_mouse_hook2(int key, t_libx *f)
{
	if (key == 5)
		f->zoom += 1 + f->zoom * 1.2;
	if (key == 4)
		f->zoom -= f->zoom * 0.2;
	if (f->zoom < 0)
		f->zoom = 0;
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
	if (f->djoo == 0 && f->frct != 3)
	{
		f->rar1 = 2.0 * x / SCX - 1;
		f->rar2 = 2.0 * y / SCY - 1;
		ft_print(f);
	}
	return (0);
}
