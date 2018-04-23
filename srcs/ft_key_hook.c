/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 13:13:14 by tmanuel           #+#    #+#             */
/*   Updated: 2018/04/23 14:24:45 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_key_hook(int key, void *f)
{
	(void)f;
	ft_putnbr(key);
	ft_putchar('\n');
	if (key == 53)
		exit(0);
	return (0);
}

int			ft_mouse_hook(int key, int x, int y, void *f)
{
	(void)f;
	ft_putnbr(key);
	ft_putchar('\n');
	ft_putnbr(x);
	ft_putchar('\n');
	ft_putnbr(y);
	ft_putchar('\n');
	return (0);
}
