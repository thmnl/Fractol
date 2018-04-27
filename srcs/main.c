/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 19:14:10 by tmanuel           #+#    #+#             */
/*   Updated: 2018/04/26 19:16:27 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_color4(t_libx *f)
{
	f->color[0] = 0x751aff;
	f->color[1] = 0x6600ff;
	f->color[2] = 0x5c00e6;
	f->color[3] = 0x4700b3;
	f->color[4] = 0x330080;
	f->colorb = 0;
}

void		ft_exit(char *s)
{
	ft_printf("%s\n", s);
	exit(-1);
}

int			ft_check_fct(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= 65 && s[i] <= 90)
			s[i] += 32;
		i++;
	}
	if (!ft_strcmp(s, "mandelbrot") || !ft_strcmp(s, "m"))
		return (1);
	else if (!ft_strcmp(s, "julia") || !ft_strcmp(s, "j"))
		return (2);
	else if (!ft_strcmp(s, "autre") || !ft_strcmp(s, "a"))
		return (3);
	else
		ft_exit("[fract] = mandelbrot | julia | autre");
	return (0);
}

int			main(int ac, char **av)
{
	t_libx	*ptr;

	if (ac != 2)
		return (ft_printf("Usage: ./fractol [fract]\n"));
	if (!(ptr = (t_libx*)malloc(sizeof(t_libx))))
		ft_exit("Malloc error");
	ft_bzero(ptr, sizeof(t_libx));
	ptr->djoo = 1;
	ft_color1(ptr);
	ptr->frct = ft_check_fct(av[1]);
	ptr->mlx_ptr = mlx_init();
	ptr->win_ptr = mlx_new_window(ptr->mlx_ptr, SCX, SCY, "Fractol");
	mlx_key_hook(ptr->win_ptr, ft_key_hook, (t_libx*)ptr);
	mlx_mouse_hook(ptr->win_ptr, ft_mouse_hook, (t_libx*)ptr);
	mlx_hook(ptr->win_ptr, 6, (1L << 6), ft_hook, (t_libx*)ptr);
	mlx_hook(ptr->win_ptr, 2, (1L << 0), ft_keypress, (t_libx*)ptr);
	mlx_loop_hook(ptr->mlx_ptr, ft_loop_hook, (t_libx*)ptr);
	ft_print(ptr);
	ft_music();
	mlx_loop(ptr->mlx_ptr);
	return (0);
}
