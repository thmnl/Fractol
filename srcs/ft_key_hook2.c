/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 13:41:21 by tmanuel           #+#    #+#             */
/*   Updated: 2018/04/26 19:15:51 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_loop_hook(t_libx *f)
{
	if (f->psy == 1)
	{
		ft_color(f);
		ft_print(f);
	}
	return (0);
}

int			ft_keypress2(int key, t_libx *f)
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
	if (f->im < -10)
		f->im = -10;
	if ((key >= 123 && key <= 126) || key == 15 || key == 69 || key == 78)
		ft_print(f);
	return (0);
}

int			ft_keypress(int key, t_libx *f)
{
	char	**tmp;

	if (key == 53)
	{
		free(f);
		if (!(tmp = ft_strsplit("killall afplay", ' ')))
			exit(ft_printf("Malloc error\n"));
		execve("/usr/bin/killall", tmp, NULL);
		free(tmp[0]);
		free(tmp[1]);
		free(tmp);
		exit(0);
	}
	if (key == 91)
		f->zoom += 1500;
	if (key == 87)
		f->zoom -= 1500;
	if (key == 87 || key == 91)
		ft_print(f);
	return (ft_keypress2(key, f));
}
